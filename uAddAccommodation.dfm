object frmAddAccommodation: TfrmAddAccommodation
  Left = 931
  Top = 376
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Add accommodation'
  ClientHeight = 163
  ClientWidth = 278
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object cxLabel1: TsLabel
    Left = 4
    Top = 16
    Width = 114
    Height = 17
    Alignment = taRightJustify
    AutoSize = False
    Caption = 'Number of persons :'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object cxLabel2: TsLabel
    Left = 4
    Top = 39
    Width = 114
    Height = 17
    Alignment = taRightJustify
    AutoSize = False
    Caption = 'Nights :'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object cxLabel3: TsLabel
    Left = 4
    Top = 72
    Width = 114
    Height = 17
    Alignment = taRightJustify
    AutoSize = False
    Caption = 'Rooms :'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object cxLabel4: TsLabel
    Left = 4
    Top = 96
    Width = 114
    Height = 17
    Alignment = taRightJustify
    AutoSize = False
    Caption = 'Room price :'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object edPersons: TsSpinEdit
    Left = 124
    Top = 13
    Width = 81
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    SkinData.SkinSection = 'EDIT'
    BoundLabel.Font.Charset = DEFAULT_CHARSET
    BoundLabel.Font.Color = clWindowText
    BoundLabel.Font.Height = -13
    BoundLabel.Font.Name = 'Tahoma'
    BoundLabel.Font.Style = []
    MaxValue = 0
    MinValue = 0
    Value = 0
  end
  object edNights: TsSpinEdit
    Left = 124
    Top = 36
    Width = 81
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    SkinData.SkinSection = 'EDIT'
    BoundLabel.Font.Charset = DEFAULT_CHARSET
    BoundLabel.Font.Color = clWindowText
    BoundLabel.Font.Height = -13
    BoundLabel.Font.Name = 'Tahoma'
    BoundLabel.Font.Style = []
    MaxValue = 0
    MinValue = 0
    Value = 0
  end
  object edRooms: TsSpinEdit
    Left = 124
    Top = 69
    Width = 81
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    SkinData.SkinSection = 'EDIT'
    BoundLabel.Font.Charset = DEFAULT_CHARSET
    BoundLabel.Font.Color = clWindowText
    BoundLabel.Font.Height = -13
    BoundLabel.Font.Name = 'Tahoma'
    BoundLabel.Font.Style = []
    MaxValue = 0
    MinValue = 0
    Value = 0
  end
  object sPanel1: TsPanel
    Left = 0
    Top = 122
    Width = 278
    Height = 41
    Align = alBottom
    TabOrder = 5
    SkinData.SkinSection = 'PANEL'
    ExplicitTop = 131
    ExplicitWidth = 286
    object BtnOk: TsButton
      AlignWithMargins = True
      Left = 100
      Top = 4
      Width = 83
      Height = 33
      Hint = 'Apply and close'
      Align = alRight
      Caption = 'OK'
      Default = True
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 0
      OnClick = BtnOkClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 108
    end
    object btnCancel: TsButton
      AlignWithMargins = True
      Left = 189
      Top = 4
      Width = 85
      Height = 33
      Hint = 'Cancel and close'
      Align = alRight
      Caption = 'Cancel'
      ImageIndex = 4
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 197
    end
  end
  object edRoomPrice: TsCalcEdit
    Left = 124
    Top = 93
    Width = 81
    Height = 21
    AutoSize = False
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnChange = edRoomPriceChange
    SkinData.SkinSection = 'EDIT'
    GlyphMode.Blend = 0
    GlyphMode.Grayed = False
  end
  inline fraCurrencyPanel: TfraCurrencyPanel
    Left = 209
    Top = 93
    Width = 135
    Height = 21
    TabOrder = 4
    ExplicitLeft = 209
    ExplicitTop = 93
    ExplicitWidth = 135
    ExplicitHeight = 21
    inherited pnlCurrency: TsPanel
      Width = 135
      inherited lblCurrencyName: TsLabel
        Width = 73
        ExplicitLeft = 65
        ExplicitTop = 0
        ExplicitWidth = 70
        ExplicitHeight = 14
      end
    end
  end
  object FormStore: TcxPropertiesStore
    Components = <
      item
        Component = Owner
        Properties.Strings = (
          'Left'
          'Position'
          'Top')
      end>
    StorageName = 'Software\Roomer\FormStatus\frmAddAccommodation'
    StorageType = stRegistry
    Left = 18
    Top = 126
  end
end
