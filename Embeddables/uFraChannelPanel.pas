unit ufraChannelPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uFraLookupPanel, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel;

type
  TfraChannelPanel = class(TfraCustomLookupPanel)
  private
    function GetChannelId: integer;
    procedure SetChannelId(const Value: integer);
  protected
    { Private declarations }
    procedure DoInternalSelect; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    property ChannelId: integer read GetChannelId write SetChannelId;
  end;


implementation

{$R *.dfm}

uses
  hData
  , uAppGlobal
  , uG
  , uChannels
  ;

{ TfraChannelPanel }

constructor TfraChannelPanel.Create(aOwner: TComponent);
begin
  inherited;
  Dataset := glb.ChannelsSet;
  CodeField := 'channelmanagerid';
  DescriptionField := 'name';
end;

procedure TfraChannelPanel.DoInternalSelect;
var
  theData : recChannelHolder;
begin
  theData.channelManagerId := code;
  if openChannels(actLookup, theData) then
    Code := theData.channelManagerId;
end;

function TfraChannelPanel.GetChannelId: integer;
begin
  Result := -1;
  Dataset.First;
  if IsValid and Dataset.Locate(CodeField, Code, []) then
    Result := Dataset.FieldByName('id').AsInteger;
end;

procedure TfraChannelPanel.SetChannelId(const Value: integer);
begin
  if glb.LocateChannelById(value) then
    Code := Dataset.FieldByName(CodeField).asString;
end;

end.
