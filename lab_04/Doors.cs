using ElevatorSimulation.Ctrl;

namespace ElevatorSimulation.Elev;

public class Doors
{
    private event EventHandler? DoorsOpened;
    protected virtual void OnDoorsOpened(EventArgs e) => DoorsOpened?.Invoke(this, e);
    private event EventHandler? DoorsNeed2Close;
    protected virtual void OnDoorsNeed2Close(EventArgs e) => DoorsNeed2Close?.Invoke(this, e);
    private event EventHandler? DoorsClosed;
    protected virtual void OnDoorsClosed(EventArgs e) => DoorsClosed?.Invoke(this, e);
    public event EventHandler? DoneDoors;
    protected virtual void OnDoneDoors(EventArgs e) => DoneDoors?.Invoke(this, e);
    private readonly LiftIds _id;
    private volatile DoorsState _currState;

    public Doors(LiftIds id, ref EventHandler? e)
    {
        _id = id;
        e += ActivateDoors;
        _currState = new ClosedDoorsState(this);

        DoorsOpened += AfterDoorsOpened;
        DoorsNeed2Close += CloseDoors;
        DoorsClosed += AfterDoorsClosed;
    }

    void ActivateDoors(object? sender, EventArgs e)
    {
        if (_currState is not ClosedDoorsState)
        {
            TransitionTo(new ClosedDoorsState(this));
        }
        else
        {
            TransitionTo(new OpeningDoorsState(this));
            _currState.ParseState();
        }
    }

    void AfterDoorsOpened(object? sender, EventArgs e)
    {
        TransitionToNext();
        _currState.ParseState();
    }

    void CloseDoors(object? sender, EventArgs e)
    {
        TransitionToNext();
        _currState.ParseState();
    }

    void AfterDoorsClosed(object? sender, EventArgs e)
    {
        TransitionToNext();
        _currState.ParseState();
    }

    void TransitionTo(DoorsState state)
    {
        _currState = state;
        _currState.SetContext(this);
    }

    public void TransitionToNext()
    {
        if (_currState != null)
        {
            TransitionTo(_currState.GetNextState());
        }
    }

    abstract class DoorsState(Doors context)
    {
        protected Doors _context = context;

        public void SetContext(Doors context)
        {
            _context = context;
        }

        public abstract Task ParseState();
        public abstract DoorsState GetNextState();
    }

    class OpeningDoorsState(Doors context) : DoorsState(context)
    {
        public async override Task ParseState()
        {
            Console.WriteLine($"Doors {_context._id} opening");
            await Task.Delay(1000);
            _context.OnDoorsOpened(EventArgs.Empty);
        }
        public override DoorsState GetNextState()
        {
            return new OpenDoorsState(_context);
        }
    }

    class OpenDoorsState(Doors context) : DoorsState(context)
    {
        public async override Task ParseState()
        {
            Console.WriteLine($"Doors {_context._id} opened");
            await Task.Delay(1000);
            _context.OnDoorsNeed2Close(EventArgs.Empty);
        }
        public override DoorsState GetNextState()
        {
            return new ClosingDoorsState(_context);
        }
    }

    class ClosingDoorsState(Doors context) : DoorsState(context)
    {
        public async override Task ParseState()
        {
            Console.WriteLine($"Doors {_context._id} closing");
            await Task.Delay(1000);
            _context.OnDoorsClosed(EventArgs.Empty);
        }
        public override DoorsState GetNextState()
        {
            return new ClosedDoorsState(_context);
        }
    }

    class ClosedDoorsState(Doors context) : DoorsState(context)
    {
        public async override Task ParseState()
        {
            Console.WriteLine($"Doors {_context._id} closed");
            _context.OnDoneDoors(EventArgs.Empty);
        }
        public override DoorsState GetNextState()
        {
            return new OpeningDoorsState(_context);
        }
    }
}
