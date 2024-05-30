using Cairo;
using ElevatorSimulation.Elev;
using System;

namespace ElevatorSimulation.Ctrl;

public class UpdateGoalEventArgs(int floor) : EventArgs
{
    public int Floor { get; } = floor;
}

public struct Request
{
    public int floor;
}

public class ElevatorController
{
    private readonly Elevator _elevator;
    private readonly bool[] _currRequests;
    private ElevatorControllerState _currState;
    public event EventHandler<UpdateGoalEventArgs>? UpdateGoal;
    protected virtual void OnUpdateGoal(UpdateGoalEventArgs e) => UpdateGoal?.DynamicInvoke(this, e);

    public ElevatorController(int nFloors, out EventHandler<NewRequestEventArgs>? newRequestHandler)
    {
        _elevator = new Elevator(ref UpdateGoal);
        _elevator.GoalReached += GoalReached;

        newRequestHandler = NewRequestGiven;

        _currRequests = new bool[nFloors];
        _currState = new IdleElevatorControllerState(this);
    }

    private void TransitionTo(ElevatorControllerState state)
    {
        _currState = state;
        _currState.SetContext(this);
        _currState.ParseState();
    }

    private void NewRequestGiven(object? sender, NewRequestEventArgs e)
    {
        _currRequests[e.Floor] = true;
        _currState.ParseState();
    }

    private void GoalReached(object? sender, GoalReachedEventArgs e)
    {
        _currRequests[e.Floor] = false;
        _currState.ParseState();
    }

    private abstract class ElevatorControllerState(ElevatorController context)
    {
        protected ElevatorController _context = context;

        public void SetContext(ElevatorController context)
        {
            _context = context;
        }

        public abstract void ParseState();
    }

    private class IdleElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            for (int i = 0; i < _context._currRequests.Length; i++)
            {
                if (_context._currRequests[i])
                {
                    _context.TransitionTo(new BusyElevatorControllerState(_context));
                    break;
                }
            }
        }
    }

    private class BusyElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            int currPos = _context._elevator.GetCurrFloor();
            int right = currPos;
            int left = currPos;

            while (left >= 0 || right < _context._currRequests.Length)
            {
                if (left >= 0 && _context._currRequests[left])
                {
                    _context.OnUpdateGoal(new UpdateGoalEventArgs(left));
                    return;
                }
                if (right < _context._currRequests.Length && _context._currRequests[right])
                {
                    _context.OnUpdateGoal(new UpdateGoalEventArgs(right));
                    return;
                }

                left--;
                right++;
            }

            _context.TransitionTo(new IdleElevatorControllerState(_context));
        }
    }
}
