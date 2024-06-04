using System.Text.RegularExpressions;
using Gtk;

namespace ElevatorSimulation;

public class NewRequestEventArgs(Ctrl.Request r) : EventArgs
{
    public Ctrl.Request Req { get; } = r;
}

public partial class MainForm : Window
{
    private const string UpButtonTxt = "^";
    private const string DownButtonTxt = "v";
    private const int nFloors = 10;
    public event EventHandler<NewRequestEventArgs>? NewRequest;
    protected virtual void OnNewRequest(NewRequestEventArgs e) => NewRequest?.Invoke(this, e);

    private readonly Ctrl.ElevatorController _elevatorCtrl;

    private Label? lblFloors;
    private Label? lblLift1;
    private Label? lblLift2;
    private readonly Button?[] floorButtons = new Button?[nFloors*2];
    private readonly Button?[] lift1Buttons = new Button?[nFloors];
    private readonly Button?[] lift2Buttons = new Button?[nFloors];

    public MainForm() : base("ElSim")
    {
        SetPosition(WindowPosition.Center);
        DeleteEvent += delegate { Application.Quit(); };

        Box vboxAll = new(Orientation.Vertical, 1);

        Box hboxButtons = new(Orientation.Horizontal, 1);

        Box vboxFloors = CreateFloorButtons();
        hboxButtons.PackStart(vboxFloors, false, false, 5);

        Box hboxLift1 = CreateliftButtons(1, lift1Buttons);
        hboxButtons.PackStart(hboxLift1, false, false, 5);

        Box hboxLift2 = CreateliftButtons(2, lift2Buttons);
        hboxButtons.PackStart(hboxLift2, false, false, 5);

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
            vboxFloors.PackStart(CreateFloorButtonBox(i.ToString(), out floorButtons[i], out floorButtons[i+nFloors]), false, false, 5);
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
            vboxLift1.PackStart(CreateLiftButton(id, i.ToString(), out liftButtons[i]), false, false, 5);
        }

        Box hboxLifts = new(Orientation.Horizontal, 1);
        hboxLifts.PackStart(vboxLift1, false, false, 5);

        return hboxLifts;
    }

    private Box CreateFloorButtonBox(string floor, out Button upButton, out Button downButton)
    {
        Box hbox = new(Orientation.Horizontal, 1);
        Label lblFloor = new($"{floor}:");
        hbox.PackStart(lblFloor, false, false, 5);

        upButton = new Button(UpButtonTxt)
        {
            Name = floor
        };
        downButton = new Button(DownButtonTxt)
        {
            Name = floor
        };
        upButton.Clicked += OnButtonClicked;
        downButton.Clicked += OnButtonClicked;
        hbox.PackStart(upButton, false, false, 5);
        hbox.PackStart(downButton, false, false, 5);

        return hbox;
    }

    private Box CreateLiftButton(int liftId, string floor, out Button button)
    {
        button = new Button(floor)
        {
            Name = $"{liftId}"
        };
        button.Clicked += OnButtonClicked;
        Box vbox = new(Orientation.Vertical, 1);
        vbox.PackStart(button, false, false, 1);
        return vbox;
    }

    private void OnButtonClicked(object? sender, EventArgs e)
    {
        if (sender is Button button)
        {
            int floor;
            Ctrl.Direction dir = Ctrl.Direction.ANY;
            Ctrl.LiftIds liftId = Ctrl.LiftIds.ANY;
            if (button.Label == UpButtonTxt)
            {
                floor = int.Parse(MyRegex().Match(button.Name).Value);
                dir = Ctrl.Direction.UP;
            }
            else if (button.Label == DownButtonTxt)
            {
                floor = int.Parse(MyRegex().Match(button.Name).Value);
                dir = Ctrl.Direction.DOWN;
            }
            else
            {
                floor = int.Parse(button.Label);
                liftId = (Ctrl.LiftIds)int.Parse(button.Name);
            }
            Ctrl.Request NewRequest = new() { floor=floor, dir=dir, liftId=liftId };
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
