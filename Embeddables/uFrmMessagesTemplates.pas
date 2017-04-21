unit uFrmMessagesTemplates;

interface

uses
  Winapi.Windows
  , Winapi.Messages
  , System.SysUtils
  , System.Variants
  , System.Classes
  , Vcl.Graphics
  , Vcl.Controls
  , Vcl.Forms
  , Vcl.Dialogs
  , uDImages
  , Vcl.StdCtrls
  , sButton
  , Vcl.ExtCtrls
  , sPanel
  , sScrollBox
  , sLabel
  , Vcl.ImgList
  , HTMLabel
  , acAlphaImageList
  , acImage
  , System.Generics.Collections
  , cxGraphics
  , cxControls
  , cxLookAndFeels
  , cxLookAndFeelPainters
  , cxContainer
  , cxEdit
  , cxLabel
  , uTransparentPanel

  ;

type

  TRoomerMessageType = (rmtUnknown,rmtNewBooking,rmtCancellation,rmtReview);

  TMessagePanel = class(TsPanel)
  private
    FButtonPanel : TsPanel;
    FImagePanel : TsPanel;
    FReadButton : TsButton;
    FImage : TsLabel;
    FText : TsLabel;
    FMessageText: String;
    FMessageLink: String;
    FMessageId: String;

    FMessageType : TRoomerMessageType;

    procedure CreateButtonPanel;
    procedure CreateButtonPanelImage;
    procedure CreateButtonPanelReadButton;
    procedure CreateButtonPanelText;
    procedure SetMessageText(const Value: String);
    procedure SetMessageType(const Value: TRoomerMessageType);
    procedure CreateImagePanel;
    function GetMessageTypeText: String;
  public
    constructor Create(AOwner: TComponent); override;

    procedure Prepare;

    procedure PrepareMessagePanel(_messageType : TRoomerMessageType;
                                  _messageText : String;
                                  _messageLink : String;
                                  _messageId : String;
                                  _imageList : TsAlphaImageList;
                                  _TextClickEvent,
                                  _ButtonClickEvent,
                                  _MessageMouseEnterEvent,
                                  _MessageMouseLeaveEvent : TNotifyEvent
                                  );

    property messageText : String read FMessageText write SetMessageText;
    property messageLink : String read FMessageLink;
    property messageType : TRoomerMessageType read FMessageType write SetMessageType;
    property ButtonPanel : TsPanel read FButtonPanel;
    property ReadButton : TsButton read FReadButton;
    property Image : TsLabel read FImage;
    property Text : TsLabel read FText;
  end;

  TMessagePanelList = TObjectList<TMessagePanel>;

  TFrmMessagesTemplates = class(TForm)
    sbMessageContainer: TsScrollBox;
    pnlDesignTime: TsPanel;
    sPanel1: TsPanel;
    sButton1: TsButton;
    sAlphaImageList1: TsAlphaImageList;
    HTMLabel2: THTMLabel;
    pnlContainer: TsPanel;
    sPanel2: TsPanel;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    procedure FormCreate(Sender: TObject);
    procedure MessageAreaMouseEnter(Sender: TObject);
    procedure MessageAreaMouseLeave(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure HTMLabel2Click(Sender: TObject);
  private
    procedure PanelButtonClick(Sender: TObject);
    function MessageIndex(msgType: TRoomerMessageType; msgId: String): Integer;
    { Private declarations }
  public
    { Public declarations }
    MessageList : TMessagePanelList;
    procedure AddMessage(MessageType : TRoomerMessageType;
                         MessageText,
                         MessageLink,
                         MessageId : String);
    procedure RemoveThoseNotInList(MessageType: TRoomerMessageType; List: TStrings);
    procedure Clear;
    function HeightNeeded : Integer;

  end;


implementation

{$R *.dfm}

uses uMain,
     uD,
     uReservationProfile
     ;

{ TMessagePanel }

const IMAGE_INDEX_BOOKINGS = 'R';
      IMAGE_INDEX_CANCELLATIONS = 'S';
      IMAGE_INDEX_REVIEWS = ',';

      IMAGE_INDEX_BOOKINGS_COLOR = $00FF8000;
      IMAGE_INDEX_CANCELLATIONS_COLOR = $007280FE;
      IMAGE_INDEX_REVIEWS_COLOR = $00858585;

constructor TMessagePanel.Create(AOwner: TComponent);
begin
  inherited;

  BevelKind := bkFlat;
  BevelOuter:= bvNone;
  Align := alTop;
  BorderStyle := bsNone;
  BevelOuter := bvNone;
  Height := 41;
  ParentColor := True;
  Top := 10000;
  SkinData.SkinManager := frmMain.sSkinManager1;
end;

procedure TMessagePanel.Prepare;
begin
  CreateButtonPanel;
  CreateImagePanel;
  CreateButtonPanelReadButton;
  CreateButtonPanelImage;
  CreateButtonPanelText;
end;

procedure TFrmMessagesTemplates.RemoveThoseNotInList(MessageType: TRoomerMessageType; List : TStrings);
var i, idx : Integer;
    MessagePanel : TMessagePanel;
begin
  for i := MessageList.Count - 1 downto 0 do
  begin
    idx := List.IndexOf(MessageList[i].FMessageId);
    if (MessageList[i].FMessageType=MessageType) AND (idx >= 0) then
      List.Delete(List.IndexOf(MessageList[i].FMessageId));
  end;
  for i := 0 to List.Count - 1 do
  begin
    idx := MessageIndex(MessageType, List[i]);
    if idx >= 0 then
      MessageList.Delete(idx);
  end;
end;

procedure TMessagePanel.CreateButtonPanel;
begin
  FButtonPanel := TsPanel.Create(nil);
  FButtonPanel.Parent := self;
  FButtonPanel.Align := alRight;
  FButtonPanel.BevelOuter := bvNone;
  FButtonPanel.Width := 28;
  FButtonPanel.SkinData.SkinManager := frmMain.sSkinManager1;
  FButtonPanel.SkinData.SkinSection := 'PANEL';
end;

procedure TMessagePanel.CreateImagePanel;
begin
  FImagePanel := TsPanel.Create(nil);
  FImagePanel.Parent := self;
  FImagePanel.ParentColor := True;
  FImagePanel.Align := alLeft;
  FImagePanel.BevelOuter := bvNone;
  FImagePanel.Width := 30;
  FImagePanel.SkinData.SkinManager := frmMain.sSkinManager1;
  FImagePanel.SkinData.SkinSection := 'PANEL';
end;

procedure TMessagePanel.CreateButtonPanelImage;
begin
  FImage := TsLabel.Create(nil);
  FImage.Align := alClient;
  FImage.AlignWithMargins := True;
  FImage.Parent := FImagePanel;
  FImage.Caption := ' ';
  FImage.SkinSection := '';
  FImage.ParentFont := False;
  FImage.UseSkinColor := False;
  FImage.Font.Name := 'Wingdings 2';
  FImage.Font.Color := $00FF8000;
  FImage.Font.Size := 16;
  FImage.Layout := tlCenter;
  FImage.SkinManager := frmMain.sSkinManager1;
  FImage.SkinSection := 'LABEL';
end;

procedure TMessagePanel.CreateButtonPanelText;
begin
  FText := TsLabel.Create(nil);
  FText.Align := alClient;
  FText.Parent := self;
  FText.WordWrap := True;
  FText.Cursor := crHandPoint;
  FText.AutoSize := False;
//  FText.Transparent := True;
  FText.Caption := '';
  FText.Font.Size := 8;
  FText.Font.Name := 'Tahoma';
  FText.Font.Style := [];
  FText.SkinManager := frmMain.sSkinManager1;
  FText.SkinSection := 'PANEL';
end;

procedure TMessagePanel.CreateButtonPanelReadButton;
begin
  FReadButton := TsButton.Create(nil);
  FReadButton.Align := alClient;
  FReadButton.Parent := FButtonPanel;
  FReadButton.Images := DImages.cxSmallImagesFlat;
  FReadButton.ImageIndex := 4;
  FReadButton.Left := 0;
  FReadButton.Top := -1;
  FReadButton.SkinData.SkinManager := frmMain.sSkinManager1;
  FReadButton.SkinData.SkinSection := 'BUTTON';
end;

procedure TMessagePanel.PrepareMessagePanel(_messageType: TRoomerMessageType;
        _messageText: String;
        _messageLink : String;
        _messageId : String;
        _imageList : TsAlphaImageList;
        _TextClickEvent,
        _ButtonClickEvent,
        _MessageMouseEnterEvent,
        _MessageMouseLeaveEvent: TNotifyEvent);
begin
  MessageType := _messageType;
  MessageText := _messageText;
  FMessageLink := _messageLink;

  FMessageId := _messageId;

  case _messageType of
    rmtNewBooking: begin
                     FImage.Caption := IMAGE_INDEX_BOOKINGS;
                     FImage.Font.Color := IMAGE_INDEX_BOOKINGS_COLOR;
                   end;
    rmtCancellation: begin
                     FImage.Caption := IMAGE_INDEX_CANCELLATIONS;
                     FImage.Font.Color := IMAGE_INDEX_CANCELLATIONS_COLOR;
                   end;
    rmtReview:     begin
                     FImage.Caption := IMAGE_INDEX_REVIEWS;
                     FImage.Font.Color := IMAGE_INDEX_REVIEWS_COLOR;
                   end;
  end;

//  FText.Style.BorderColor := clRed;
  FText.Caption := _messageText;
  FText.ShowHint := True;
  FText.Hint := GetMessageTypeText + #13 + _messageText;
  FText.OnClick := _TextClickEvent;

  FText.OnMouseEnter := _MessageMouseEnterEvent;
  FText.OnMouseLeave := _MessageMouseLeaveEvent;
  FReadButton.OnClick := _ButtonClickEvent;
end;

function TMessagePanel.GetMessageTypeText : String;
begin
  result := '';
  case MessageType of
    rmtUnknown: result := '';
    rmtNewBooking:    result := 'NEW BOOKING' + #13 +
                                '---------------------';
    rmtCancellation:  result := 'CANCELLATION' + #13 +
                                '----------------------';
    rmtReview:        result := 'NEW GUEST REVIEW' + #13 +
                                '--------------------------';
  end;
end;

procedure TMessagePanel.SetMessageText(const Value: String);
begin
  FMessageText := Value;
  FText.Caption := Value;
end;

procedure TMessagePanel.SetMessageType(const Value: TRoomerMessageType);
begin
  FMessageType := Value;
  case FMessageType of
    rmtNewBooking: begin
                     FImage.Caption := IMAGE_INDEX_BOOKINGS;
                     FImage.Font.Color := IMAGE_INDEX_BOOKINGS_COLOR;
                   end;
    rmtCancellation: begin
                     FImage.Caption := IMAGE_INDEX_CANCELLATIONS;
                     FImage.Font.Color := IMAGE_INDEX_CANCELLATIONS_COLOR;
                   end;
    rmtReview:     begin
                     FImage.Caption := IMAGE_INDEX_REVIEWS;
                     FImage.Font.Color := IMAGE_INDEX_REVIEWS_COLOR;
                   end;
  end;
end;

procedure TFrmMessagesTemplates.AddMessage(MessageType: TRoomerMessageType; MessageText, MessageLink, MessageId: String);
var msg : TMessagePanel;
begin
  if MessageIndex(MessageType, MessageId) = -1 then
  begin
    msg := TMessagePanel.Create(nil); // Panel will be owned by MessageList and freed when removed there
    msg.Parent := sbMessageContainer;
    msg.Prepare;
    msg.PrepareMessagePanel(MessageType,
              MessageText,
              MessageLink,
              MessageId,
              sAlphaImageList1,
              HTMLabel2Click,
              PanelButtonClick,
              MessageAreaMouseEnter,
              MessageAreaMouseLeave);
    MessageList.Add(msg);
  end;
end;

function TFrmMessagesTemplates.MessageIndex(msgType : TRoomerMessageType; msgId : String) : Integer;
var i : Integer;
begin
  result := -1;
  for i := 0 to MessageList.Count - 1 do
  begin
    if (MessageList[i].FMessageType=msgType) AND (MessageList[i].FMessageId=msgId) then
    begin
      result := i;
      Break;
    end;
  end;
end;


procedure TFrmMessagesTemplates.FormCreate(Sender: TObject);
begin
  //sbMessageContainer.
  FreeAndNil(pnlDesignTime);
  MessageList := TMessagePanelList.Create(True);
end;

procedure TFrmMessagesTemplates.FormDestroy(Sender: TObject);
begin
  MessageList.Free;
end;

function TFrmMessagesTemplates.HeightNeeded: Integer;
begin
  result := MessageList.Count * 50 + sLabel2.Height;
end;

procedure TFrmMessagesTemplates.HTMLabel2Click(Sender: TObject);
var MessagePanel : TMessagePanel;
begin
  MessagePanel := TMessagePanel(TsLabel(Sender).Parent);
  case MessagePanel.FMessageType of

    rmtNewBooking,
    rmtCancellation: EditReservation(StrToInt(MessagePanel.FMessageId), 0);

    rmtReview: ;
  end;
end;

procedure TFrmMessagesTemplates.MessageAreaMouseEnter(Sender: TObject);
var APoint : TPoint;
begin
  APoint.X := TsLabel(Sender).Height;
  APoint.Y := 0;
  APoint := TsLabel(Sender).ClientToScreen(APoint);
  Application.ActivateHint(APoint);
end;

procedure TFrmMessagesTemplates.MessageAreaMouseLeave(Sender: TObject);
begin
  Application.CancelHint;
end;

procedure TFrmMessagesTemplates.PanelButtonClick(Sender: TObject);
var MessagePanel : TMessagePanel;
    idx : Integer;
begin
  MessagePanel := TMessagePanel(TsPanel(TsButton(Sender).Parent).Parent);
  case MessagePanel.FMessageType of

    rmtNewBooking,
    rmtCancellation: d.roomerMainDataSet.SystemMarkReservationAsNotified(StrToInt(MessagePanel.FMessageId));

    rmtReview: ; // FImage.ImageIndex := IMAGE_INDEX_REVIEWS;
  end;
  idx := MessageIndex(MessagePanel.FMessageType, MessagePanel.FMessageId);
  if idx >= 0 then
    MessageList.Delete(idx);

end;

procedure TFrmMessagesTemplates.Clear;
begin
  MessageList.Clear;
end;

end.
