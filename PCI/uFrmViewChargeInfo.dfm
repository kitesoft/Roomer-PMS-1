inherited FrmViewChargeInfo: TFrmViewChargeInfo
  Caption = 'View Charge Details'
  ClientHeight = 544
  ClientWidth = 594
  OnShow = FormShow
  ExplicitWidth = 600
  ExplicitHeight = 573
  PixelsPerInch = 96
  TextHeight = 13
  object sLabel1: TsLabel [0]
    Left = 184
    Top = 95
    Width = 52
    Height = 13
    Alignment = taRightJustify
    Caption = 'Operation:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel2: TsLabel [1]
    Left = 142
    Top = 122
    Width = 94
    Height = 13
    Alignment = taRightJustify
    Caption = 'Authorization code:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel3: TsLabel [2]
    Left = 195
    Top = 149
    Width = 41
    Height = 13
    Alignment = taRightJustify
    Caption = 'Amount:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel4: TsLabel [3]
    Left = 128
    Top = 199
    Width = 108
    Height = 13
    Alignment = taRightJustify
    Caption = 'Operation result code:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel5: TsLabel [4]
    Left = 99
    Top = 226
    Width = 137
    Height = 13
    Alignment = taRightJustify
    Caption = 'Operation result description:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel6: TsLabel [5]
    Left = 160
    Top = 323
    Width = 76
    Height = 13
    Alignment = taRightJustify
    Caption = 'Gateway name:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel7: TsLabel [6]
    Left = 139
    Top = 350
    Width = 97
    Height = 13
    Alignment = taRightJustify
    Caption = 'Gateway reference:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel8: TsLabel [7]
    Left = 133
    Top = 377
    Width = 103
    Height = 13
    Alignment = taRightJustify
    Caption = 'Gateway result code:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel9: TsLabel [8]
    Left = 104
    Top = 404
    Width = 132
    Height = 13
    Alignment = taRightJustify
    Caption = 'Gateway result description:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel10: TsLabel [9]
    Left = 204
    Top = 46
    Width = 32
    Height = 13
    Alignment = taRightJustify
    Caption = 'When:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel11: TsLabel [10]
    Left = 388
    Top = 46
    Width = 28
    Height = 13
    Alignment = taRightJustify
    Caption = '(UTC)'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel12: TsLabel [11]
    Left = 137
    Top = 19
    Width = 99
    Height = 13
    Alignment = taRightJustify
    Caption = 'Reservation / Room:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  inherited sbStatusBar: TsStatusBar
    Top = 524
    Width = 594
    ExplicitTop = 524
    ExplicitWidth = 594
  end
  object edOperation: TsEdit [13]
    Left = 254
    Top = 92
    Width = 122
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
  end
  object edAutCode: TsEdit [14]
    Left = 254
    Top = 119
    Width = 293
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
  object edAmount: TsCurrencyEdit [15]
    Left = 254
    Top = 146
    Width = 122
    Height = 21
    AutoSize = False
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 3
    GlyphMode.Blend = 0
    GlyphMode.Grayed = False
  end
  object edCurrency: TsEdit [16]
    Left = 382
    Top = 146
    Width = 81
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
    Text = 'EUR'
  end
  object edOperationResult: TsEdit [17]
    Left = 254
    Top = 196
    Width = 122
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 5
  end
  object edOperationResultDescription: TsMemo [18]
    Left = 254
    Top = 223
    Width = 293
    Height = 63
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 6
  end
  object edGatewayName: TsEdit [19]
    Left = 254
    Top = 320
    Width = 293
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 7
  end
  object edGatewayReference: TsEdit [20]
    Left = 254
    Top = 347
    Width = 293
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 8
  end
  object edGatewayResultCode: TsEdit [21]
    Left = 254
    Top = 374
    Width = 293
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 9
  end
  object edGatewayResultDescription: TsMemo [22]
    Left = 254
    Top = 401
    Width = 293
    Height = 63
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 10
  end
  object edWhen: TsEdit [23]
    Left = 254
    Top = 43
    Width = 122
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 12
  end
  inherited pnlButtons: TsPanel
    Top = 481
    Width = 594
    TabOrder = 0
    ExplicitTop = 481
    ExplicitWidth = 594
    inherited btnOK: TsButton
      Left = 278
      ExplicitLeft = 278
    end
    inherited btnCancel: TsButton
      Left = 384
      ExplicitLeft = 384
    end
    inherited btnClose: TsButton
      Left = 490
      ExplicitLeft = 490
    end
    object btnRefundOrCapture: TsButton
      AlignWithMargins = True
      Left = 4
      Top = 6
      Width = 150
      Height = 31
      Margins.Top = 5
      Margins.Right = 10
      Margins.Bottom = 5
      Align = alLeft
      Caption = 'Charge action'
      DropDownMenu = pupCharge
      ImageIndex = 130
      Images = DImages.PngImageList1
      Style = bsSplitButton
      TabOrder = 3
      Visible = False
    end
  end
  object edReservation: TsEdit [25]
    Left = 254
    Top = 16
    Width = 293
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 13
  end
  inherited psRoomerBase: TcxPropertiesStore
    Top = 36
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Top = 36
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
  object pupCharge: TPopupMenu
    OnPopup = pupChargePopup
    Left = 70
    Top = 468
    object mnuCapture: TMenuItem
      Caption = 'Capture'
      OnClick = mnuCaptureClick
    end
    object mnuVoid: TMenuItem
      Caption = 'Void'
      OnClick = mnuVoidClick
    end
    object mnyRefund: TMenuItem
      Caption = 'Refund'
      OnClick = mnyRefundClick
    end
  end
end
