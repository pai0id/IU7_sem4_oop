using ElevatorSimulation.Ctrl;

namespace ElevatorSimulation.Elev;

public class GoalReachedEventArgs(int floor) : EventArgs
{
    public int Floor = floor;
}

public class Elevator
{
    public event EventHandler<GoalReachedEventArgs>? GoalReached;
    protected virtual void OnGoalReached(GoalReachedEventArgs e) => GoalReached?.Invoke(this, e);
    public event EventHandler? ActivateDoors;
    protected virtual void OnActivateDoors(EventArgs e) =>ActivateDoors?.Invoke(this, e);

    private volatile int _currGoal;
    private int _currFloor;
    public int GetCurrFloor()
    {
        return _currFloor;
    }
    ElevatorState _currState;
    Doors _doors;

    public Elevator(ref EventHandler<UpdateGoalEventArgs>? e)
    {
        _currGoal = 0;
        _currFloor = 0;
        _currState = new StopElevatorState(this);

        e += UpdateGoal;

        _doors = new Doors(ref ActivateDoors);
        _doors.DoneDoors += DoneDoors;
    }

    void UpdateGoal(object? sender, UpdateGoalEventArgs e)
    {
        _currGoal = e.Floor;
        _currState.ParseState();
    }

    void DoneDoors(object? sender, EventArgs e)
    {
        TransitionTo(new StopElevatorState(this));
        OnGoalReached(new GoalReachedEventArgs(_currGoal));
    }

    public async Task Move()
    {
        Console.WriteLine($"Elevator starting to move from floor {_currFloor} to floor {_currGoal}.");

        while (_currFloor != _currGoal)
        {
            if (_currFloor < _currGoal)
            {
                _currFloor++;
            }
            else if (_currFloor > _currGoal)
            {
                _currFloor--;
            }

            await Task.Delay(1000);
            Console.WriteLine($"Elevator at {_currFloor}");
        }

        Console.WriteLine($"Elevator reached floor {_currFloor}");
        await _currState.ParseState();
    }

    void TransitionTo(ElevatorState state)
    {
        _currState = state;
        _currState.SetContext(this);
        _currState.ParseState();
    }

    abstract class ElevatorState(Elevator context)
    {
        protected Elevator _context = context;

        public void SetContext(Elevator context)
        {
            _context = context;
        }

        public abstract Task ParseState();
    }

    class MovingElevatorState(Elevator context) : ElevatorState(context)
    {
        public async override Task ParseState()
        {
            if (context._currFloor == context._currGoal)
            {
                _context.TransitionTo(new WaitElevatorState(_context));
            }
        }
    }

    class WaitElevatorState(Elevator context) : ElevatorState(context)
    {
        public async override Task ParseState()
        {
            context.OnActivateDoors(EventArgs.Empty);
        }
    }

    class StopElevatorState(Elevator context) : ElevatorState(context)
    {
        public async override Task ParseState()
        {
            if (context._currFloor != context._currGoal)
            {
                _context.TransitionTo(new MovingElevatorState(_context));
                await context.Move();
            }
        }
    }
}
