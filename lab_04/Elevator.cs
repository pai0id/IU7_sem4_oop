using ElevatorSimulation.Ctrl;

namespace ElevatorSimulation.Elev;

public class GoalReachedEventArgs(int floor) : EventArgs
{
    public int Floor { get; } = floor;
}

public class Elevator
{
    public event EventHandler<GoalReachedEventArgs>? GoalReached;
    protected virtual void OnGoalReached(GoalReachedEventArgs e) => GoalReached?.Invoke(this, e);
    public event EventHandler? ActivateDoors;
    protected virtual void OnActivateDoors(EventArgs e) => ActivateDoors?.Invoke(this, e);
    private volatile int _currGoal;
    private int _currFloor;
    private ElevatorState _currState;
    private readonly Doors _doors;

    public Elevator(ref EventHandler<UpdateGoalEventArgs>? updateGoalHandler)
    {
        _currGoal = 0;
        _currFloor = 0;
        _currState = new StopElevatorState(this);

        updateGoalHandler += UpdateGoal;

        _doors = new Doors(ref ActivateDoors);
        _doors.DoneDoors += DoneDoors;
    }

    public int GetCurrFloor() => _currFloor;

    private void UpdateGoal(object? sender, UpdateGoalEventArgs e)
    {
        _currGoal = e.Floor;
        if (_currState is not MovingElevatorState)
            _currState.ParseState();
    }

    private void DoneDoors(object? sender, EventArgs e)
    {
        TransitionTo(new StopElevatorState(this));
        OnGoalReached(new GoalReachedEventArgs(_currGoal));
    }

    public async Task Move()
    {
        Console.WriteLine($"Elevator starting to move from floor {_currFloor} to floor {_currGoal}.");

        while (_currFloor != _currGoal)
        {
            _currFloor += _currFloor < _currGoal ? 1 : -1;

            await Task.Delay(1000);
            Console.WriteLine($"Elevator at {_currFloor}");
        }

        Console.WriteLine($"Elevator reached floor {_currFloor}");
        await _currState.ParseState();
    }

    private void TransitionTo(ElevatorState state)
    {
        _currState = state;
        _currState.SetContext(this);
        _currState.ParseState();
    }

    private abstract class ElevatorState(Elevator context)
    {
        protected Elevator _context = context;

        public void SetContext(Elevator context)
        {
            _context = context;
        }

        public abstract Task ParseState();
    }

    private class MovingElevatorState(Elevator context) : ElevatorState(context)
    {
        public override async Task ParseState()
        {
            if (_context._currFloor == _context._currGoal)
            {
                _context.TransitionTo(new WaitElevatorState(_context));
            }
        }
    }

    private class WaitElevatorState(Elevator context) : ElevatorState(context)
    {
        public override async Task ParseState()
        {
           _context.OnActivateDoors(EventArgs.Empty);
        }
    }

    private class StopElevatorState(Elevator context) : ElevatorState(context)
    {
        public override async Task ParseState()
        {
            if (_context._currFloor != _context._currGoal)
            {
                _context.TransitionTo(new MovingElevatorState(_context));
                await _context.Move();
            }
        }
    }
}
