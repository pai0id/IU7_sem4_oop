using ElevatorSimulation.Elev;

namespace ElevatorSimulation.Ctrl;

public enum Direction
{
    NONE,
    UP,
    DOWN,
    ANY
}

public enum LiftIds
{
    ANY,
    FIRST,
    SECOND
}

public class UpdateGoalEventArgs(int floor) : EventArgs
{
    public int Floor { get; } = floor;
}

public struct Request
{
    public int floor;
    public Direction dir;
    public LiftIds liftId;
}

public class ElevatorController
{
    public readonly Elevator _elevator1;
    private int _currFinGoal1;
    public readonly Elevator _elevator2;
    private int _currFinGoal2;
    private readonly Request[] _currRequests;
    private ElevatorControllerState _currState;
    public event EventHandler<UpdateGoalEventArgs>? UpdateGoal1;
    protected virtual void OnUpdateGoal1(UpdateGoalEventArgs e) => UpdateGoal1?.Invoke(this, e);
    public event EventHandler<UpdateGoalEventArgs>? UpdateGoal2;
    protected virtual void OnUpdateGoal2(UpdateGoalEventArgs e) => UpdateGoal2?.Invoke(this, e);
    private event EventHandler? StartBothSearch;
    protected virtual void OnStartBothSearch(EventArgs e) => StartBothSearch?.Invoke(this, e);
    private event EventHandler? BothGoalFound;
    protected virtual void OnBothGoalFound(EventArgs e) => BothGoalFound?.Invoke(this, e);
    private event EventHandler? Goal1Found;
    protected virtual void OnGoal1Found(EventArgs e) => Goal1Found?.Invoke(this, e);
    private event EventHandler? RetrunTo1B2IBusy;
    protected virtual void OnRetrunTo1B2IBusy(EventArgs e) => RetrunTo1B2IBusy?.Invoke(this, e);
    private event EventHandler? Goal2Found;
    protected virtual void OnGoal2Found(EventArgs e) => Goal2Found?.Invoke(this, e);
    private event EventHandler? RetrunTo2B1IBusy;
    protected virtual void OnRetrunTo2B1IBusy(EventArgs e) => RetrunTo2B1IBusy?.Invoke(this, e);
    private event EventHandler? BothGoalNotFound;
    protected virtual void OnBothGoalNotFound(EventArgs e) => BothGoalNotFound?.Invoke(this, e);

    public ElevatorController(int nFloors, ref EventHandler<NewRequestEventArgs>? newRequestHandler)
    {
        _elevator1 = new Elevator(LiftIds.FIRST, ref UpdateGoal1);
        _elevator1.GoalReached += GoalReached;

        _elevator2 = new Elevator(LiftIds.SECOND, ref UpdateGoal2);
        _elevator2.GoalReached += GoalReached;

        newRequestHandler += NewRequestGiven;

        StartBothSearch += SearchBoth;
        BothGoalFound += ProcessBothGoals;
        Goal1Found += ProcessGoal1;
        RetrunTo1B2IBusy += ProcessGoal1;
        Goal2Found += ProcessGoal2;
        RetrunTo2B1IBusy += ProcessGoal2;
        BothGoalNotFound += EndAllSearch;

        _currRequests = new Request[nFloors];
        _currState = new BothIdleElevatorControllerState(this);
    }

    private void TransitionTo(ElevatorControllerState state)
    {
        _currState = state;
        _currState.SetContext(this);
    }

    private void NewRequestGiven(object? sender, NewRequestEventArgs e)
    {
        _currRequests[e.Req.floor] = e.Req;
        if (_currState is BothIdleElevatorControllerState)
        {
            TransitionTo(new BothSearchElevatorControllerState(this));
        }
        else if (_currState is _1Busy2IdleElevatorControllerState)
        {
            TransitionTo(new _1B2ISearchElevatorControllerState(this));
        }
        else if (_currState is _2Busy1IdleElevatorControllerState)
        {
            TransitionTo(new _2B1ISearchElevatorControllerState(this));
        }
        _currState.ParseState();
    }

    private void GoalReached(object? sender, GoalReachedEventArgs e)
    {
        _currRequests[e.Floor] = new Request();
        if (_currState is _1Busy2IdleElevatorControllerState)
        {
            if (e.Floor == _currFinGoal1)
                TransitionTo(new BothSearchElevatorControllerState(this));
            else
                TransitionTo(new _1B2ISearchElevatorControllerState(this));
        }
        else if (_currState is _2Busy1IdleElevatorControllerState)
        {
            if (e.Floor == _currFinGoal2)
                TransitionTo(new BothSearchElevatorControllerState(this));
            else
                TransitionTo(new _2B1ISearchElevatorControllerState(this));
        }
        else if (_currState is BothBusyElevatorControllerState)
        {
            if (e.Floor == _currFinGoal1)
                TransitionTo(new _2B1ISearchElevatorControllerState(this));
            else if (e.Floor == _currFinGoal2)
                TransitionTo(new _1B2ISearchElevatorControllerState(this));
            else
                TransitionTo(new BothSearchElevatorControllerState(this));
        }
        _currState.ParseState();
    }

    private void SearchBoth(object? sender, EventArgs e)
    {
        TransitionTo(new BothSearchElevatorControllerState(this));
        _currState.ParseState();
    }

    private void ProcessBothGoals(object? sender, EventArgs e)
    {
        TransitionTo(new BothBusyElevatorControllerState(this));
    }

    private void ProcessGoal1(object? sender, EventArgs e)
    {
        TransitionTo(new _1Busy2IdleElevatorControllerState(this));
    }

    private void ProcessGoal2(object? sender, EventArgs e)
    {
        TransitionTo(new _2Busy1IdleElevatorControllerState(this));
    }

    private void EndAllSearch(object? sender, EventArgs e)
    {
        TransitionTo(new BothIdleElevatorControllerState(this));
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

    private class BothIdleElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            for (int i = 0; i < _context._currRequests.Length; i++)
            {
                if (_context._currRequests[i].dir != Direction.NONE)
                {
                    _context.OnStartBothSearch(EventArgs.Empty);
                    return;
                }
            }
        }
    }

    private class BothSearchElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            bool lift1Flag = false;
            bool lift2Flag = false;
            
            // For L1
            int currPos = _context._elevator1.GetCurrFloor();
            int goal1 = currPos;
            int right = currPos;
            int left = currPos;

            bool lFlag = false;
            bool rFlag = false;
            while (left >= 0 || right < _context._currRequests.Length)
            {
                if (left >= 0
                 && _context._currRequests[left].dir != Direction.NONE
                 && _context._currRequests[left].liftId != LiftIds.SECOND)
                {
                    goal1 = left;
                    lFlag = true;
                    lift1Flag = true;
                    break;
                }
                if (right < _context._currRequests.Length
                 && _context._currRequests[right].dir != Direction.NONE
                 && _context._currRequests[right].liftId != LiftIds.SECOND)
                {
                    goal1 = right;
                    rFlag = true;
                    lift1Flag = true;
                    break;
                }

                left--;
                right++;
            }

            if (rFlag)
            {
                while (right < _context._currRequests.Length)
                {
                    if (_context._currRequests[right].dir != Direction.NONE
                     && _context._currRequests[right].liftId != LiftIds.SECOND)
                    {
                        _context._currFinGoal1 = right;
                    }
                    right++;
                }
            }
            else if (lFlag)
            {
                while (left >= 0)
                {
                    if (_context._currRequests[left].dir != Direction.NONE
                     && _context._currRequests[left].liftId != LiftIds.SECOND)
                    {
                        _context._currFinGoal1 = left;
                    }
                    left--;
                }
            }

            // For L2
            currPos = _context._elevator2.GetCurrFloor();
            int goal2 = currPos;
            right = currPos;
            left = currPos;

            lFlag = false;
            rFlag = false;
            while (left >= 0 || right < _context._currRequests.Length)
            {
                if (left >= 0
                 && _context._currRequests[left].dir != Direction.NONE
                 && _context._currRequests[left].liftId == LiftIds.SECOND)
                {
                    goal2 = left;
                    lFlag = true;
                    lift2Flag = true;
                    break;
                }
                if (right < _context._currRequests.Length
                 && _context._currRequests[right].dir != Direction.NONE
                 && _context._currRequests[right].liftId == LiftIds.SECOND)
                {
                    goal2 = right;
                    rFlag = true;
                    lift2Flag = true;
                    break;
                }

                left--;
                right++;
            }

            if (rFlag)
            {
                while (right < _context._currRequests.Length)
                {
                    if (_context._currRequests[right].dir != Direction.NONE
                     && _context._currRequests[right].liftId == LiftIds.SECOND)
                    {
                        _context._currFinGoal2 = right;
                    }
                    right++;
                }
            }
            else if (lFlag)
            {
                while (left >= 0)
                {
                    if (_context._currRequests[left].dir != Direction.NONE
                     && _context._currRequests[left].liftId == LiftIds.SECOND)
                    {
                        _context._currFinGoal2 = left;
                    }
                    left--;
                }
            }

            if (lift1Flag && lift2Flag)
            {
                _context.OnUpdateGoal1(new UpdateGoalEventArgs(goal1));
                _context.OnUpdateGoal2(new UpdateGoalEventArgs(goal2));
                _context.OnBothGoalFound(EventArgs.Empty);
            }
            else if (lift1Flag)
            {
                _context.OnUpdateGoal1(new UpdateGoalEventArgs(goal1));
                _context.OnGoal1Found(EventArgs.Empty);
            }
            else if (lift2Flag)
            {
                _context.OnUpdateGoal2(new UpdateGoalEventArgs(goal2));
                _context.OnGoal2Found(EventArgs.Empty);
            }
            else
            {
                _context.OnBothGoalNotFound(EventArgs.Empty);
            }
        }
    }

    private class _1Busy2IdleElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            return;
        }
    }

    private class _1B2ISearchElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            // L1 BusySearch
            int currPos = _context._elevator1.GetCurrFloor();
            if (_context._currFinGoal1 > currPos)
            {
                while (currPos < _context._currRequests.Length)
                {
                    if ((_context._currRequests[currPos].dir == Direction.ANY || _context._currRequests[currPos].dir == Direction.UP)
                     &&  _context._currRequests[currPos].liftId != LiftIds.SECOND)
                    {
                        _context.OnUpdateGoal1(new UpdateGoalEventArgs(currPos));
                        break;
                    }
                    currPos++;
                }
            }
            else
            {
                while (currPos >= 0)
                {
                    if ((_context._currRequests[currPos].dir == Direction.ANY || _context._currRequests[currPos].dir == Direction.DOWN)
                     &&  _context._currRequests[currPos].liftId != LiftIds.SECOND)
                    {
                        _context.OnUpdateGoal1(new UpdateGoalEventArgs(currPos));
                        break;
                    }

                    currPos--;
                }
            }

            // L2 AnySearch
            bool lift2Flag = false;
            currPos = _context._elevator2.GetCurrFloor();
            int goal2 = currPos;
            int right = currPos;
            int left = currPos;

            bool lFlag = false;
            bool rFlag = false;
            while (left >= 0 || right < _context._currRequests.Length)
            {
                if (left >= 0
                 && _context._currRequests[left].dir != Direction.NONE
                 && _context._currRequests[left].liftId == LiftIds.SECOND)
                {
                    goal2 = left;
                    lFlag = true;
                    lift2Flag = true;
                    break;
                }
                if (right < _context._currRequests.Length
                 && _context._currRequests[right].dir != Direction.NONE
                 && _context._currRequests[right].liftId == LiftIds.SECOND)
                {
                    goal2 = right;
                    rFlag = true;
                    lift2Flag = true;
                    break;
                }

                left--;
                right++;
            }

            if (rFlag)
            {
                while (right < _context._currRequests.Length)
                {
                    if (_context._currRequests[right].dir != Direction.NONE
                     && _context._currRequests[right].liftId == LiftIds.SECOND)
                    {
                        _context._currFinGoal2 = right;
                    }
                    right++;
                }
            }
            else if (lFlag)
            {
                while (left >= 0)
                {
                    if (_context._currRequests[left].dir != Direction.NONE
                     && _context._currRequests[left].liftId == LiftIds.SECOND)
                    {
                        _context._currFinGoal2 = left;
                    }
                    left--;
                }
            }

            if (lift2Flag)
            {
                _context.OnUpdateGoal2(new UpdateGoalEventArgs(goal2));
                _context.OnBothGoalFound(EventArgs.Empty);
            }
            else
            {
                _context.OnRetrunTo1B2IBusy(EventArgs.Empty);
            }
        }
    }

    private class _2Busy1IdleElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            return;
        }
    }

    private class _2B1ISearchElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            // L2 BusySearch
            int currPos = _context._elevator2.GetCurrFloor();
            if (_context._currFinGoal2 > currPos)
            {
                while (currPos < _context._currRequests.Length)
                {
                    if ((_context._currRequests[currPos].dir == Direction.ANY || _context._currRequests[currPos].dir == Direction.UP)
                     &&  _context._currRequests[currPos].liftId != LiftIds.FIRST)
                    {
                        _context.OnUpdateGoal2(new UpdateGoalEventArgs(currPos));
                        break;
                    }
                    currPos++;
                }
            }
            else
            {
                while (currPos >= 0)
                {
                    if ((_context._currRequests[currPos].dir == Direction.ANY || _context._currRequests[currPos].dir == Direction.DOWN)
                     &&  _context._currRequests[currPos].liftId != LiftIds.FIRST)
                    {
                        _context.OnUpdateGoal2(new UpdateGoalEventArgs(currPos));
                        break;
                    }

                    currPos--;
                }
            }

            // L1 AnySearch
            bool lift1Flag = false;
            currPos = _context._elevator1.GetCurrFloor();
            int goal1 = currPos;
            int right = currPos;
            int left = currPos;

            bool lFlag = false;
            bool rFlag = false;
            while (left >= 0 || right < _context._currRequests.Length)
            {
                if (left >= 0
                 && _context._currRequests[left].dir != Direction.NONE
                 && _context._currRequests[left].liftId == LiftIds.FIRST)
                {
                    goal1 = left;
                    lFlag = true;
                    lift1Flag = true;
                    break;
                }
                if (right < _context._currRequests.Length
                 && _context._currRequests[right].dir != Direction.NONE
                 && _context._currRequests[right].liftId == LiftIds.FIRST)
                {
                    goal1 = right;
                    rFlag = true;
                    lift1Flag = true;
                    break;
                }

                left--;
                right++;
            }

            if (rFlag)
            {
                while (right < _context._currRequests.Length)
                {
                    if (_context._currRequests[right].dir != Direction.NONE
                     && _context._currRequests[right].liftId == LiftIds.FIRST)
                    {
                        _context._currFinGoal1 = right;
                    }
                    right++;
                }
            }
            else if (lFlag)
            {
                while (left >= 0)
                {
                    if (_context._currRequests[left].dir != Direction.NONE
                     && _context._currRequests[left].liftId == LiftIds.FIRST)
                    {
                        _context._currFinGoal1 = left;
                    }
                    left--;
                }
            }

            if (lift1Flag)
            {
                _context.OnUpdateGoal1(new UpdateGoalEventArgs(goal1));
                _context.OnBothGoalFound(EventArgs.Empty);
            }
            else
            {
                _context.OnRetrunTo2B1IBusy(EventArgs.Empty);
            }
        }
    }

    private class BothBusyElevatorControllerState(ElevatorController context) : ElevatorControllerState(context)
    {
        public override void ParseState()
        {
            return;
        }
    }
}
