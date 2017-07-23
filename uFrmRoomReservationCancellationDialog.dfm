inherited FrmRoomReservationCancellationDialog: TFrmRoomReservationCancellationDialog
  AlignWithMargins = True
  Caption = 'Room Cancellation'
  ClientHeight = 310
  ClientWidth = 513
  ParentFont = False
  ExplicitWidth = 519
  ExplicitHeight = 339
  PixelsPerInch = 96
  TextHeight = 13
  object sLabel2: TsLabel [0]
    Left = 13
    Top = 185
    Width = 40
    Height = 13
    Caption = 'Reason:'
  end
  inherited sbStatusBar: TsStatusBar
    Top = 290
    Width = 513
    ExplicitTop = 326
    ExplicitWidth = 583
  end
  inherited pnlButtons: TsPanel
    Top = 247
    Width = 513
    ExplicitTop = 242
    ExplicitWidth = 583
    inherited btnOK: TsButton
      Left = 303
      Default = False
      ExplicitLeft = 373
      ExplicitTop = 4
    end
    inherited btnCancel: TsButton
      Left = 409
      ExplicitLeft = 479
      ExplicitTop = 4
    end
  end
  object sGroupBox1: TsGroupBox [3]
    AlignWithMargins = True
    Left = 0
    Top = 3
    Width = 513
    Height = 126
    Margins.Left = 0
    Margins.Right = 0
    Align = alTop
    Caption = 'Roomreservation information'
    TabOrder = 2
    object sLabel1: TsLabel
      Left = 40
      Top = 81
      Width = 91
      Height = 13
      Alignment = taRightJustify
      Caption = 'Reservation name:'
    end
    object lblResName: TsLabel
      Left = 142
      Top = 81
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel3: TsLabel
      Left = 89
      Top = 100
      Width = 42
      Height = 13
      Alignment = taRightJustify
      Caption = 'Contact:'
    end
    object lblContact: TsLabel
      Left = 142
      Top = 100
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel5: TsLabel
      Left = 328
      Top = 43
      Width = 35
      Height = 13
      Alignment = taRightJustify
      Caption = 'Arrival:'
    end
    object lblArrival: TsLabel
      Left = 382
      Top = 43
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel7: TsLabel
      Left = 310
      Top = 62
      Width = 53
      Height = 13
      Alignment = taRightJustify
      Caption = 'Departure:'
    end
    object lblDeparture: TsLabel
      Left = 382
      Top = 62
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel9: TsLabel
      Left = 277
      Top = 81
      Width = 86
      Height = 13
      Alignment = taRightJustify
      Caption = 'Number of rooms:'
    end
    object lblRooms: TsLabel
      Left = 382
      Top = 81
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel11: TsLabel
      Left = 274
      Top = 100
      Width = 89
      Height = 13
      Alignment = taRightJustify
      Caption = 'Number of guests:'
    end
    object lblGuests: TsLabel
      Left = 382
      Top = 100
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel4: TsLabel
      Left = 70
      Top = 62
      Width = 61
      Height = 13
      Alignment = taRightJustify
      Caption = 'Guest name:'
    end
    object lblGuest: TsLabel
      Left = 142
      Top = 62
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel8: TsLabel
      Left = 100
      Top = 43
      Width = 31
      Height = 13
      Alignment = taRightJustify
      Caption = 'Room:'
    end
    object lblRoom: TsLabel
      Left = 142
      Top = 43
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object lbReservationNr: TsLabel
      Left = 59
      Top = 24
      Width = 72
      Height = 13
      Alignment = taRightJustify
      Caption = 'Reservationnr:'
    end
    object lblReservationNr: TsLabel
      Left = 142
      Top = 24
      Width = 5
      Height = 13
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
  end
  object sPanel1: TsPanel [4]
    AlignWithMargins = True
    Left = 0
    Top = 132
    Width = 513
    Height = 112
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Align = alClient
    TabOrder = 3
    ExplicitLeft = -5
    ExplicitTop = 252
    ExplicitWidth = 970
    ExplicitHeight = 297
    object mmoReason: TsMemo
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 505
      Height = 104
      Align = alClient
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'EDIT'
      ExplicitLeft = 13
      ExplicitTop = 3
      ExplicitWidth = 491
      ExplicitHeight = 155
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 232
    Top = 160
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 112
    Top = 160
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
