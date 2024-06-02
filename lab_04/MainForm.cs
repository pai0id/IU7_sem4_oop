using System.Text.RegularExpressions;
using Gtk;

namespace ElevatorSimulation;

public class NewRequestEventArgs(Ctrl.Request r) : EventArgs
{
    public int Floor { get; } = r.floor;
}

public partial class MainForm : Window
{
    private const string buttonTxt = "#";
    private const int nFloors = 10;
    public event EventHandler<NewRequestEventArgs>? NewRequest;
    protected virtual void OnNewRequest(NewRequestEventArgs e) => NewRequest?.Invoke(this, e);

    private readonly Ctrl.ElevatorController _elevatorCtrl;

    private Label? lblFloors;
    private Label? lblLift1;
    private readonly Button?[] floorButtons = new Button?[nFloors];
    private readonly Button?[] liftButtons = new Button?[nFloors];

    public MainForm() : base("ElSim")
    {
        SetPosition(WindowPosition.Center);
        DeleteEvent += delegate { Application.Quit(); };

        Box vboxAll = new(Orientation.Vertical, 1);

        Box hboxButtons = new(Orientation.Horizontal, 1);

        Box vboxFloors = CreateFloorButtons();
        hboxButtons.PackStart(vboxFloors, false, false, 5);

        Box hboxLift = CreateliftButtons(1, liftButtons);
        hboxButtons.PackStart(hboxLift, false, false, 5);

        vboxAll.PackStart(hboxButtons, false, false, 5);

        Add(vboxAll);

        _elevatorCtrl = new Ctrl.ElevatorController(nFloors, ref NewRequest);

        ShowAll();
    }

    private Box CreateFloorButtons()
    {
        Box vboxFloors = new(Orientation.Vertical, 1);
        lblFloors = new Label("Floors");
        vboxFloors.PackStart(lblFloors, false, false, 5);

        for (int i = nFloors - 1; i >= 0; --i)
        {
            vboxFloors.PackStart(CreateFloorButtonBox(i.ToString(), out floorButtons[i]), false, false, 5);
        }

        return vboxFloors;
    }

    private Box CreateliftButtons(int id, Button?[] liftButtons)
    {
        Box vboxLift1 = new(Orientation.Vertical, 1);
        lblLift1 = new Label($"Elevator {id}");
        vboxLift1.PackStart(lblLift1, false, false, 1);

        for (int i = nFloors - 1; i >= 0; --i)
        {
            vboxLift1.PackStart(CreateLiftButton(i.ToString(), out liftButtons[i]), false, false, 5);
        }

        Box hboxLifts = new(Orientation.Horizontal, 1);
        hboxLifts.PackStart(vboxLift1, false, false, 5);

        return hboxLifts;
    }

    private Box CreateFloorButtonBox(string floor, out Button button)
    {
        Box hbox = new(Orientation.Horizontal, 1);
        Label lblFloor = new($"{floor}:");
        hbox.PackStart(lblFloor, false, false, 5);

        button = new Button(buttonTxt)
        {
            Name = floor
        };
        button.Clicked += OnButtonClicked;
        hbox.PackStart(button, false, false, 5);

        return hbox;
    }

    private Box CreateLiftButton(string floor, out Button button)
    {
        button = new Button(floor);
        button.Clicked += OnButtonClicked;
        Box vbox = new(Orientation.Vertical, 1);
        vbox.PackStart(button, false, false, 1);
        return vbox;
    }

    private void OnButtonClicked(object? sender, EventArgs e)
    {
        if (sender is Button button)
        {
            int floor = button.Label == buttonTxt ? int.Parse(MyRegex().Match(button.Name).Value) : int.Parse(button.Label);
            var NewRequest = new Ctrl.Request { floor = floor };
            OnNewRequest(new NewRequestEventArgs(NewRequest));
        }
    }

    public static void Main()
    {
        Application.Init();
        _ = new MainForm();
        Application.Run();
    }

    [GeneratedRegex(@"\d+")]
    private static partial Regex MyRegex();
}
