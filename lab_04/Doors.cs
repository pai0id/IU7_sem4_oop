namespace ElevatorSimulation.Elev;

public class Doors
{
    public event EventHandler? DoneDoors;
    protected virtual void OnDoneDoors(EventArgs e) => DoneDoors?.Invoke(this, e);

    DoorsState _currState;

    public Doors( ref EventHandler? e)
    {
        e += ActivateDoors;
        _currState = new ClosedDoorsState(this);
    }

    void ActivateDoors(object? sender, EventArgs e)
    {
        if (_currState is ClosedDoorsState)
            TransitionTo(new OpeningDoorsState(this));
        else
        {
            _currState = new ClosedDoorsState(this);
            _currState.SetContext(this);
        }
    }

    void TransitionTo(DoorsState state)
    {
        _currState = state;
        _currState.SetContext(this);
        _currState.ParseState();
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
            Console.WriteLine("Doors opening");
            await Task.Delay(1000);
            context.TransitionToNext();
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
            Console.WriteLine("Doors opened");
            await Task.Delay(1000);
            context.TransitionToNext();
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
            Console.WriteLine("Doors closing");
            await Task.Delay(1000);
            context.TransitionToNext();
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
            Console.WriteLine("Doors closed");
            _context.OnDoneDoors(EventArgs.Empty);
        }
        public override DoorsState GetNextState()
        {
            return new OpeningDoorsState(_context);
        }
    }
}
