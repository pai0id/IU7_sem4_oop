using ElevatorSimulation.Elev;

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
    private int _latestReq;
    private event EventHandler? StartMoving;
    protected virtual void OnStartMoving(EventArgs e) => StartMoving?.Invoke(this, e);
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

        StartMoving += CheckPath;
        GoalFound += ProcessGoal;
        GoalListNotEmpty += StartSearch;
        GoalNotFound += EndSearch;
        ReturnToBusy += NewGoalNotFound;

        _currRequests = new bool[nFloors];
        _currState = new IdleElevatorControllerState(this);
    }

    private void TransitionTo(ElevatorControllerState state)
    {
        _currState = state;
        _currState.SetContext(this);
    }

    private void NewRequestGiven(object? sender, NewRequestEventArgs e)
    {
        _currRequests[e.Floor] = true;
        if (_currState is not IdleElevatorControllerState)
        {
            TransitionTo(new SearchWhileBusyElevatorControllerState(this));
        }
        else
        {
            TransitionTo(new SearchElevatorControllerState(this));
        }
        _currState.ParseState();
    }

    private void CheckPath(object? sender, EventArgs e)
    {
        TransitionTo(new SearchWhileBusyElevatorControllerState(this));
        _currState.ParseState();
    }

    private void GoalReached(object? sender, GoalReachedEventArgs e)
    {
        _currRequests[e.Floor] = false;
        if (e.Floor == _latestReq)
        {
            TransitionTo(new SearchElevatorControllerState(this));
        }
        else
        {
            TransitionTo(new SearchWhileBusyElevatorControllerState(this));
        }
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
                if (_context._currRequests[i])
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

            bool flag = false;
            while (left >= 0 || right < _context._currRequests.Length)
            {
                if (left >= 0 && _context._currRequests[left])
                {
                    _context._latestReq = left;
                    flag = true;
                }
                if (right < _context._currRequests.Length && _context._currRequests[right])
                {
                    _context._latestReq = right;
                    flag = true;
                }

                left--;
                right++;
            }

            if (flag)
            {
                _context.OnStartMoving(EventArgs.Empty);
            }
            else
            {
                _context.OnGoalNotFound(EventArgs.Empty);
            }
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
                    if (_context._currRequests[currPos])
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
                    if (_context._currRequests[currPos])
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
