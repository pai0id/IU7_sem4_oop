using ElevatorSimulation.Elev;

namespace ElevatorSimulation.Ctrl;

public enum Direction
{
    NONE,
    UP,
    DOWN,
    ANY
}

public class UpdateGoalEventArgs(int floor) : EventArgs
{
    public int Floor { get; } = floor;
}

public struct Request
{
    public int floor;
    public Direction dir;
}

public class ElevatorController
{
    private readonly Elevator _elevator;
    private readonly Direction[] _currRequests;
    private ElevatorControllerState _currState;
    private int _latestReq;
    public event EventHandler<UpdateGoalEventArgs>? UpdateGoal;
    protected virtual void OnUpdateGoal(UpdateGoalEventArgs e) => UpdateGoal?.Invoke(this, e);
    private event EventHandler? GoalFound;
    protected virtual void OnGoalFound(EventArgs e) => GoalFound?.Invoke(this, e);
    private event EventHandler? GoalListNotEmpty;
    protected virtual void OnGoalListNotEmpty(EventArgs e) => GoalListNotEmpty?.Invoke(this, e);
    private event EventHandler? GoalNotFound;
    protected virtual void OnGoalNotFound(EventArgs e) => GoalNotFound?.Invoke(this, e);
    private event EventHandler? ReturnToBusy;
    protected virtual void OnReturnToBusy(EventArgs e) => ReturnToBusy?.Invoke(this, e);

    public ElevatorController(int nFloors, ref EventHandler<NewRequestEventArgs>? newRequestHandler)
    {
        _elevator = new Elevator(ref UpdateGoal);
        _elevator.GoalReached += GoalReached;

        newRequestHandler += NewRequestGiven;

        GoalFound += ProcessGoal;
        GoalListNotEmpty += StartSearch;
        GoalNotFound += EndSearch;
        ReturnToBusy += NewGoalNotFound;

        _currRequests = new Direction[nFloors];
        _currState = new IdleElevatorControllerState(this);
    }

    private void TransitionTo(ElevatorControllerState state)
    {
        _currState = state;
        _currState.SetContext(this);
    }

    private void NewRequestGiven(object? sender, NewRequestEventArgs e)
    {
        _currRequests[e.Floor] = e.Direction;
        if (_currState is IdleElevatorControllerState)
            TransitionTo(new SearchElevatorControllerState(this));
        else
            TransitionTo(new SearchWhileBusyElevatorControllerState(this));
        _currState.ParseState();
        _latestReq = e.Floor;
    }

    private void GoalReached(object? sender, GoalReachedEventArgs e)
    {
        _currRequests[e.Floor] = Direction.NONE;
        TransitionTo(new SearchElevatorControllerState(this));
        _currState.ParseState();
    }

    private void ProcessGoal(object? sender, EventArgs e)
    {
        TransitionTo(new BusyElevatorControllerState(this));
    }

    private void StartSearch(object? sender, EventArgs e)
    {
        TransitionTo(new SearchElevatorControllerState(this));
        _currState.ParseState();
    }

    private void EndSearch(object? sender, EventArgs e)
    {
        TransitionTo(new IdleElevatorControllerState(this));
    }

    private void NewGoalNotFound(object? sender, EventArgs e)
    {
        TransitionTo(new BusyElevatorControllerState(this));
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
                if (_context._currRequests[i] != Direction.NONE)
                {
                    _context.OnGoalListNotEmpty(EventArgs.Empty);
                    return;
                }
            }
        }
    }

    private class SearchElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            int currPos = _context._elevator.GetCurrFloor();
            int right = currPos;
            int left = currPos;

            while (left >= 0 || right < _context._currRequests.Length)
            {
                if (left >= 0 && _context._currRequests[left] != Direction.NONE)
                {
                     _context.OnUpdateGoal(new UpdateGoalEventArgs(left));
                    _context.OnGoalFound(EventArgs.Empty);
                    return;
                }
                if (right < _context._currRequests.Length && _context._currRequests[right] != Direction.NONE)
                {
                    _context.OnUpdateGoal(new UpdateGoalEventArgs(right));
                    _context.OnGoalFound(EventArgs.Empty);
                    return;
                }

                left--;
                right++;
            }

            _context.OnGoalNotFound(EventArgs.Empty);
        }
    }

    private class BusyElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            return;
        }
    }

    private class SearchWhileBusyElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            int currPos = _context._elevator.GetCurrFloor();
            if (_context._latestReq > currPos)
            {
                while (currPos < _context._currRequests.Length)
                {
                    if (_context._currRequests[currPos] == Direction.ANY || _context._currRequests[currPos] == Direction.UP)
                    {
                        _context.OnUpdateGoal(new UpdateGoalEventArgs(currPos));
                        _context.OnGoalFound(EventArgs.Empty);
                        return;
                    }
                    currPos++;
                }
            }
            else
            {
                while (currPos >= 0)
                {
                    if (_context._currRequests[currPos] == Direction.ANY || _context._currRequests[currPos] == Direction.DOWN)
                    {
                        _context.OnUpdateGoal(new UpdateGoalEventArgs(currPos));
                        _context.OnGoalFound(EventArgs.Empty);
                        return;
                    }
                    currPos--;
                }
            }

            _context.OnReturnToBusy(EventArgs.Empty);
        }
    }
}
