using ElevatorSimulation.Ctrl;

namespace ElevatorSimulation.Elev;

public class GoalReachedEventArgs(int floor, LiftIds liftId) : EventArgs
{
    public int Floor { get; } = floor;
    public LiftIds LiftId { get; } = liftId;
}

public class Elevator
{
    public event EventHandler<GoalReachedEventArgs>? GoalReached;
    protected virtual void OnGoalReached(GoalReachedEventArgs e) => GoalReached?.Invoke(this, e);
    public event EventHandler? ActivateDoors;
    protected virtual void OnActivateDoors(EventArgs e) => ActivateDoors?.Invoke(this, e);
    private event EventHandler? Need2Move;
    protected virtual void OnNeed2Move(EventArgs e) => Need2Move?.Invoke(this, e);
    private event EventHandler? Need2Wait;
    protected virtual void OnNeed2Wait(EventArgs e) => Need2Wait?.Invoke(this, e);
    private readonly LiftIds _id;
    private volatile int _currGoal;
    private volatile int _currFloor;
    private ElevatorState _currState;
    private readonly Doors _doors;

    public Elevator(LiftIds id, ref EventHandler<UpdateGoalEventArgs>? updateGoalHandler)
    {
        _id = id;
        _currGoal = 0;
        _currFloor = 0;
        _currState = new StopElevatorState(this);

        updateGoalHandler += UpdateGoal;

        Need2Move += BegMove;
        Need2Wait += BegWait;

        _doors = new Doors(id, ref ActivateDoors);
        _doors.DoneDoors += DoneDoors;
    }

    public int GetCurrFloor() => _currFloor;
    public int GetCurrGoal() => _currGoal;

    private void UpdateGoal(object? sender, UpdateGoalEventArgs e)
    {
        if (_currState is WaitElevatorState && e.Floor == _currGoal)
        {
            return;
        }
        else if ((_currState is WaitElevatorState || _currState is StopElevatorState) && e.Floor == _currFloor)
        {
            OnActivateDoors(EventArgs.Empty);
        }
        else
        {
            _currGoal = e.Floor;
            if (_currState is StopElevatorState)
                _currState.ParseState();
        }
    }

    private void DoneDoors(object? sender, EventArgs e)
    {
        TransitionTo(new StopElevatorState(this));
        _currState.ParseState();
        OnGoalReached(new GoalReachedEventArgs(_currFloor, _id));
    }

    private void BegMove(object? sender, EventArgs e)
    {
        TransitionTo(new MovingElevatorState(this));
        Move();
    }

    private void BegWait(object? sender, EventArgs e)
    {
        TransitionTo(new WaitElevatorState(this));
        OnActivateDoors(EventArgs.Empty);
    }

    public async void Move()
    {
        Console.WriteLine($"Elevator {_id} starting to move from floor {_currFloor} to floor {_currGoal}.");

        while (_currFloor != _currGoal)
        {
            _currFloor += _currFloor < _currGoal ? 1 : -1;

            await Task.Delay(1000);
            Console.WriteLine($"Elevator {_id} at {_currFloor}");
        }

        Console.WriteLine($"Elevator {_id} reached floor {_currFloor}");
        _currState.ParseState();
    }

    private void TransitionTo(ElevatorState state)
    {
        _currState = state;
        _currState.SetContext(this);
    }

    private abstract class ElevatorState(Elevator context)
    {
        protected Elevator _context = context;

        public void SetContext(Elevator context)
        {
            _context = context;
        }

        public abstract void ParseState();
    }

    private class MovingElevatorState(Elevator context) : ElevatorState(context)
    {
        public override void ParseState()
        {
            if (_context._currFloor == _context._currGoal)
            {
                _context.OnNeed2Wait(EventArgs.Empty);
            }
        }
    }

    private class WaitElevatorState(Elevator context) : ElevatorState(context)
    {
        public override void ParseState()
        {
           return;
        }
    }

    private class StopElevatorState(Elevator context) : ElevatorState(context)
    {
        public override void ParseState()
        {
            if (_context._currFloor != _context._currGoal)
            {
                _context.OnNeed2Move(EventArgs.Empty);
            }
        }
    }
}
