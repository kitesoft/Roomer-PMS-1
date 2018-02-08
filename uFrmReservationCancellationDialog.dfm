inherited FrmReservationCancellationDialog: TFrmReservationCancellationDialog
  AlignWithMargins = True
  Caption = 'Reservation Cancellation'
  ClientHeight = 346
  ClientWidth = 583
  ParentFont = False
  ExplicitWidth = 589
  ExplicitHeight = 375
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 326
    Width = 583
    ExplicitTop = 326
    ExplicitWidth = 583
  end
  inherited pnlButtons: TsPanel
    Top = 283
    Width = 583
    ExplicitTop = 242
    ExplicitWidth = 583
    inherited btnOK: TsButton
      Left = 373
      Default = False
      ExplicitLeft = 373
    end
    inherited btnCancel: TsButton
      Left = 479
      ExplicitLeft = 479
    end
  end
  object gbxResInfo: TsGroupBox [2]
    AlignWithMargins = True
    Left = 0
    Top = 3
    Width = 583
    Height = 145
    Margins.Left = 0
    Margins.Right = 0
    Align = alTop
    Caption = 'Reservation information:'
    TabOrder = 2
    ExplicitLeft = -2
    ExplicitTop = 4
    ExplicitWidth = 577
    object sLabel1: TsLabel
      Left = 40
      Top = 24
      Width = 91
      Height = 13
      Alignment = taRightJustify
      Caption = 'Reservation name:'
    end
    object lblResName: TsLabel
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
    object sLabel3: TsLabel
      Left = 89
      Top = 42
      Width = 42
      Height = 13
      Alignment = taRightJustify
      Caption = 'Contact:'
    end
    object lblContact: TsLabel
      Left = 142
      Top = 42
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
      Left = 96
      Top = 60
      Width = 35
      Height = 13
      Alignment = taRightJustify
      Caption = 'Arrival:'
    end
    object lblArrival: TsLabel
      Left = 142
      Top = 60
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
      Left = 78
      Top = 79
      Width = 53
      Height = 13
      Alignment = taRightJustify
      Caption = 'Departure:'
    end
    object lblDeparture: TsLabel
      Left = 142
      Top = 79
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
      Left = 293
      Top = 42
      Width = 86
      Height = 13
      Alignment = taRightJustify
      Caption = 'Number of rooms:'
    end
    object lblRooms: TsLabel
      Left = 390
      Top = 42
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
      Left = 290
      Top = 60
      Width = 89
      Height = 13
      Alignment = taRightJustify
      Caption = 'Number of guests:'
    end
    object lblGuests: TsLabel
      Left = 390
      Top = 60
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
      Left = 304
      Top = 24
      Width = 75
      Height = 13
      Alignment = taRightJustify
      Caption = 'Reservation nr:'
    end
    object lblReservationNr: TsLabel
      Left = 390
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
  object sPanel1: TsPanel [3]
    Left = 0
    Top = 151
    Width = 583
    Height = 132
    Margins.Left = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alClient
    TabOrder = 3
    ExplicitLeft = -2
    ExplicitTop = 154
    ExplicitWidth = 577
    ExplicitHeight = 126
    object sLabel2: TsLabel
      Left = 91
      Top = 31
      Width = 40
      Height = 13
      Alignment = taRightJustify
      Caption = 'Reason:'
    end
    object chkSendConfirmation: TsCheckBox
      AlignWithMargins = True
      Left = 143
      Top = 4
      Width = 436
      Height = 21
      Margins.Left = 142
      Caption = 'Send Cancellation confirmation'
      Align = alTop
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'CHECKBOX'
      ImgChecked = 0
      ImgUnchecked = 0
      ExplicitWidth = 430
    end
    object mmoReason: TsMemo
      AlignWithMargins = True
      Left = 143
      Top = 28
      Width = 436
      Height = 100
      Margins.Left = 142
      Margins.Top = 0
      Align = alClient
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      SkinData.SkinSection = 'EDIT'
      ExplicitLeft = 153
      ExplicitTop = 40
      ExplicitWidth = 420
      ExplicitHeight = 82
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 480
    Top = 72
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
