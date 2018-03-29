unit uMultiSelection;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sListBox, sCheckListBox, Vcl.ExtCtrls, sPanel,
  sLabel, sButton, cmpRoomerDataSet, Data.DB, uappglobal;

type
  TfrmMultiSelection = class(TForm)
    sPanel1: TsPanel;
    pnlHeader: TsPanel;
    sButton1: TsButton;
    sButton2: TsButton;
    lblHeader: TsLabel;
    sPanel2: TsPanel;
    lstItems: TsCheckListBox;
    pnlUpDown: TsPanel;
    btnUp: TsButton;
    btnDown: TsButton;
    procedure FormCreate(Sender: TObject);
    procedure lstItemsClick(Sender: TObject);
    procedure lstItemsClickCheck(Sender: TObject);
    procedure btnUpClick(Sender: TObject);
    procedure btnDownClick(Sender: TObject);
  private
    { Private declarations }
    ListCodes : TStrings;
    IntegerCodes : Boolean;
    MultiSelect : Boolean;
    function MoveListItem(ListView: TsCheckListBox; ItemFrom, ItemTo: Word): Boolean;
    procedure EnableOrDisableButtons;
  public
    { Public declarations }
    procedure PrepareItems(OriginalSelection: String; _MultiSelect : Boolean; _IntegerCodes : Boolean; ListCodeItems, ListNameItems: TStrings);
    function GetResult : String;
  end;

var
  frmMultiSelection: TfrmMultiSelection;

function SelectItems(Caption: String;
                     OriginalSelection : String;
                     ListCodeItems : TStrings;
                     ListNameItems : TStrings;
                     IntegerCodes : Boolean;
                     MultiSelect : Boolean) : String;

function LookupForDataItem(Caption : String;
                            LookupDataSet : TRoomerDataSet;
                            CodeFieldName,
                            DescriptionFieldName,
                            OriginalValue : String;
                            MultiSelect : Boolean;
                            IsInteger : Boolean = False;
                            ActiveInActiveField : String = '';
                            destinationDataSet : TDataSet = nil;
                            destinationFieldName : String = '') : String;

implementation

{$R *.dfm}

uses uRoomerLanguage, uUtils, uDImages, uVCLUtils;


function SelectItems(Caption: String;
                     OriginalSelection : String;
                     ListCodeItems : TStrings;
                     ListNameItems : TStrings;
                     IntegerCodes : Boolean;
                     MultiSelect : Boolean) : String;
begin
  frmMultiSelection := TfrmMultiSelection.Create(Application);
  try
    frmMultiSelection.lblHeader.Caption := Caption;
    frmMultiSelection.PrepareItems(OriginalSelection, MultiSelect, IntegerCodes, ListCodeItems, ListNameItems);
    result := OriginalSelection;
    if frmMultiSelection.ShowModal = mrOk then
      result := frmMultiSelection.GetResult;
  finally
    FreeAndNil(frmMultiSelection);
  end;
end;

function LookupForDataItem(Caption : String;
                            LookupDataSet : TRoomerDataSet;
                            CodeFieldName,
                            DescriptionFieldName,
                            OriginalValue : String;
                            MultiSelect : Boolean;
                            IsInteger : Boolean = False;
                            ActiveInActiveField : String = '';
                            destinationDataSet : TDataSet = nil;
                            destinationFieldName : String = '') : String;
var
    codes : TStrings;
    names : TStrings;
    newValue : String;
begin
  codes := TStringList.Create;
  Names := TStringList.Create;
  LookupDataSet.First;
  while NOT LookupDataSet.EOF do
  begin
    if (ActiveInActiveField = '') OR LookupDataSet[ActiveInActiveField] then
    begin
      if IsInteger then
        Codes.Add(IntToStr(LookupDataSet[CodeFieldName]))
      else
        Codes.Add(LookupDataSet[CodeFieldName]);
      Names.Add(LookupDataSet[DescriptionFieldName]);
    end;
    LookupDataSet.Next;
  end;
//  CopyToClipboard(OriginalValue);
//  DebugMessage(OriginalValue);
  newValue := SelectItems(Caption,
                          OriginalValue,
                          Codes,
                          Names,
                          isInteger,
                          MultiSelect);
  if (newValue <> OriginalValue) AND
      Assigned(destinationDataSet) AND
      (destinationFieldName > '') then
  begin
    destinationDataSet.Edit;
    destinationDataSet[destinationFieldName] := newValue;
  end;

  result := newValue;
end;


procedure TfrmMultiSelection.btnDownClick(Sender: TObject);
begin
//Move Down
 if lstItems.ItemIndex < lstItems.Items.Count - 1 then
   MoveListItem(lstItems, lstItems.ItemIndex, lstItems.ItemIndex + 1);
end;

procedure TfrmMultiSelection.btnUpClick(Sender: TObject);
begin
//Move Up
 if lstItems.ItemIndex > 0 then
   MoveListItem(lstItems, lstItems.ItemIndex, lstItems.ItemIndex - 1);
end;

procedure TfrmMultiSelection.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
     glb.PerformAuthenticationAssertion(self); PlaceFormOnVisibleMonitor(self);
end;

function TfrmMultiSelection.GetResult: String;
var i : Integer;
begin
  result := '';
  for i := 0 to lstItems.Items.Count - 1 do
    if lstItems.Checked[i] then
    begin
      if result = '' then
        result := ListCodes[i]
      else
        result := result + ',' + ListCodes[i]
    end;
end;

procedure TfrmMultiSelection.lstItemsClick(Sender: TObject);
begin
  EnableOrDisableButtons;
end;

procedure TfrmMultiSelection.EnableOrDisableButtons;
begin
  btnUp.Enabled := (lstItems.ItemIndex > 0);
  btnDown.Enabled := (lstItems.ItemIndex >= 0) AND (lstItems.ItemIndex < lstItems.Items.Count - 1);
end;

procedure TfrmMultiSelection.lstItemsClickCheck(Sender: TObject);
var i, iCurr : integer;
begin
  if NOT lstItems.MultiSelect then
  begin
    iCurr := lstItems.ItemIndex;
    if lstItems.Checked[iCurr] then
      for i := 0 to lstItems.Items.Count - 1 do
        if (i<>iCurr) AND (lstItems.Checked[i]) then
          lstItems.Checked[i] := False;
  end;
end;

procedure TfrmMultiSelection.PrepareItems(OriginalSelection : String;
                     _MultiSelect : Boolean;
                     _IntegerCodes : Boolean;
                     ListCodeItems : TStrings;
                     ListNameItems : TStrings);
var i, iCurr : Integer;
    s : String;
    OriginalList : TStringList;
begin
  ListCodes := ListCodeItems;
  IntegerCodes := _IntegerCodes;
  MultiSelect := _MultiSelect;
  pnlUpDown.Visible := _MultiSelect;
  lstItems.MultiSelect := MultiSelect;

  lstItems.Clear;
  OriginalList := TStringList.Create;
  try
    OriginalList.CommaText := OriginalSelection;

  //  CopyToClipboard(OriginalList.CommaText);
  //  DebugMessage(OriginalList.CommaText);

    for i := 0 to ListCodes.Count - 1 do
    begin
      s := ListCodes[i];
      if Assigned(ListNameItems) then
        if ListNameItems.Count > i then
        begin
          s := s + ^i + ListNameItems[i];
          if lstItems.TabWidth < Length(s) * (lstItems.Font.Size + 2) then
             lstItems.TabWidth := Length(s) * (lstItems.Font.Size + 2);
        end;

      iCurr := lstItems.Items.Add(s);
      lstItems.Checked[iCurr] := (OriginalList.IndexOf(ListCodes[i]) >= 0);
    end;

    for i := 0 to OriginalList.Count - 1 do
      MoveListItem(lstItems, ListCodes.IndexOf(OriginalList[i]), i);

  finally
    OriginalList.Free;
  end;
end;

function TfrmMultiSelection.MoveListItem(ListView: TsCheckListBox; ItemFrom, ItemTo: Word): Boolean;
begin
  listview.Items.BeginUpdate;
  try
    ListView.Items.Move(ItemFrom, ItemTo);
    ListCodes.Move(ItemFrom, ItemTo);
    ListView.ItemIndex := ItemTo;
    Result := True;
  finally
    ListView.Items.EndUpdate;
  end;
  EnableOrDisableButtons;
end;


end.
