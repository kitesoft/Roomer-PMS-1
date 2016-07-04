unit uEmbDateSelection;

interface

uses
  System.Classes,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uBaseEmbeddableForm, Vcl.ExtCtrls, sPanel, Vcl.StdCtrls, sRadioButton, Vcl.Mask,
  sMaskEdit, sCustomComboEdit, sToolEdit, sComboBox, sGroupBox;

type
  TDateSelPreset = (Today, Tomorrow, Yesterday, ThisWeek, ThisMonth, ThisYear);
  TDateSelPresetHelper = record helper for TDateSelPreset
  public
    procedure SetStrings(aStrings: TStrings);
  end;

  TfrmDateSelection = class(TembeddableForm)
    pnlDateSelection: TsPanel;
    gbxSelectMonths: TsGroupBox;
    cbxMonth: TsComboBox;
    cbxYear: TsComboBox;
    gbxSelectDates: TsGroupBox;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    gbxPresets: TsGroupBox;
    cbxPresets: TsComboBox;
    procedure cbxMonthChange(Sender: TObject);
  private
    function GetFromDate: TDateTime;
    function GetToDate: TDateTime;
    procedure SetFromDate(const Value: TDateTime);
    procedure SetToDate(const Value: TDateTime);
    { Private declarations }
  protected
    function GetEmbeddableControl: TControl; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    procedure UpdateControls; override;
    property FromDate: TDateTime read GetFromDate write SetFromDate;
    property ToDate: TDateTime read GetToDate write SetToDate;
  end;

implementation

{$R *.dfm}



{ TfrmDateSelection }

procedure TfrmDateSelection.cbxMonthChange(Sender: TObject);
begin
  inherited;
  SignalChanges(Sender);
  UpdateControls;
end;

constructor TfrmDateSelection.Create(aOwner: TComponent);
begin
  inherited;
  TDateSelPreset.SetStrings(cbxPresets.Items);
end;

function TfrmDateSelection.GetEmbeddableControl: TControl;
begin
  Result := pnlDateSelection;
end;

function TfrmDateSelection.GetFromDate: TDateTime;
begin

end;

function TfrmDateSelection.GetToDate: TDateTime;
begin

end;

procedure TfrmDateSelection.SetFromDate(const Value: TDateTime);
begin

end;

procedure TfrmDateSelection.SetToDate(const Value: TDateTime);
begin

end;

procedure TfrmDateSelection.UpdateControls;
begin
  inherited;

end;

end.
