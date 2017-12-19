inherited frmAddAccommodation: TfrmAddAccommodation
  Left = 931
  Top = 376
  BorderIcons = []
  Caption = 'Add accommodation'
  ClientHeight = 194
  ClientWidth = 273
  ParentFont = False
  Position = poDefault
  OnShow = FormShow
  ExplicitWidth = 279
  ExplicitHeight = 223
  PixelsPerInch = 96
  TextHeight = 13
  object cxLabel1: TsLabel [0]
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
  object cxLabel2: TsLabel [1]
    Left = 4
    Top = 42
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
  object cxLabel3: TsLabel [2]
    Left = 4
    Top = 68
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
  object cxLabel4: TsLabel [3]
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
  inherited sbStatusBar: TsStatusBar
    Top = 174
    Width = 273
    ExplicitTop = 174
    ExplicitWidth = 273
  end
  inherited pnlButtons: TsPanel
    Top = 131
    Width = 273
    TabOrder = 6
    ExplicitTop = 131
    ExplicitWidth = 273
    inherited btnOK: TsButton
      Left = -43
      ExplicitLeft = -43
    end
    inherited btnCancel: TsButton
      Left = 63
      ExplicitLeft = 63
    end
    inherited btnClose: TsButton
      Left = 169
      ExplicitLeft = 169
    end
  end
  object edPersons: TsSpinEdit [6]
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
    Text = '1'
    OnChange = HandleChanged
    SkinData.SkinSection = 'EDIT'
    BoundLabel.Font.Charset = DEFAULT_CHARSET
    BoundLabel.Font.Color = clWindowText
    BoundLabel.Font.Height = -13
    BoundLabel.Font.Name = 'Tahoma'
    BoundLabel.Font.Style = []
    MaxValue = 0
    MinValue = 0
    Value = 1
  end
  object edNights: TsSpinEdit [7]
    Left = 124
    Top = 39
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
    Text = '1'
    OnChange = HandleChanged
    SkinData.SkinSection = 'EDIT'
    BoundLabel.Font.Charset = DEFAULT_CHARSET
    BoundLabel.Font.Color = clWindowText
    BoundLabel.Font.Height = -13
    BoundLabel.Font.Name = 'Tahoma'
    BoundLabel.Font.Style = []
    MaxValue = 0
    MinValue = 0
    Value = 1
  end
  object edRooms: TsSpinEdit [8]
    Left = 124
    Top = 65
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
    Text = '1'
    OnChange = HandleChanged
    SkinData.SkinSection = 'EDIT'
    BoundLabel.Font.Charset = DEFAULT_CHARSET
    BoundLabel.Font.Color = clWindowText
    BoundLabel.Font.Height = -13
    BoundLabel.Font.Name = 'Tahoma'
    BoundLabel.Font.Style = []
    MaxValue = 0
    MinValue = 0
    Value = 1
  end
  object edRoomPrice: TsCurrencyEdit [9]
    Left = 124
    Top = 93
    Width = 80
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
    ShowButton = True
  end
  inline fraCurrencyPanel: TfraCurrencyPanel [10]
    Left = 209
    Top = 93
    Width = 135
    Height = 20
    AutoSize = True
    TabOrder = 4
    ExplicitLeft = 209
    ExplicitTop = 93
    ExplicitWidth = 135
    inherited pnlCurrency: TsPanel
      Width = 135
      ExplicitWidth = 135
      inherited lblCurrencyName: TsLabel
        Width = 65
        ExplicitWidth = 73
        ExplicitHeight = 14
      end
      inherited btnGetCurrency: TsButton
        ExplicitLeft = 40
      end
    end
  end
  inherited psRoomerBase: TcxPropertiesStore [11]
    Left = 8
    Top = 40
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 8
    Top = 88
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
