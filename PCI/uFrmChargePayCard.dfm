inherited FrmChargePayCard: TFrmChargePayCard
  Caption = 'Charge Paycard'
  ClientHeight = 615
  ClientWidth = 768
  OnShow = FormShow
  ExplicitWidth = 774
  ExplicitHeight = 644
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 595
    Width = 768
    ExplicitTop = 595
    ExplicitWidth = 768
  end
  object pnlTop: TsPanel [1]
    Left = 0
    Top = 0
    Width = 768
    Height = 179
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object sLabel3: TsLabel
      Left = 119
      Top = 21
      Width = 62
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Reservation:'
      ParentBiDiMode = False
    end
    object sLabel4: TsLabel
      Left = 89
      Top = 40
      Width = 92
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Room Reservation:'
      ParentBiDiMode = False
    end
    object lbRoomReservation: TsLabel
      Left = 192
      Top = 40
      Width = 31
      Height = 13
      BiDiMode = bdLeftToRight
      Caption = '[N/A]'
      ParentBiDiMode = False
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object lbReservation: TsLabel
      Left = 192
      Top = 21
      Width = 31
      Height = 13
      BiDiMode = bdLeftToRight
      Caption = '[N/A]'
      ParentBiDiMode = False
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel1: TsLabel
      Left = 138
      Top = 69
      Width = 43
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Paycard:'
      ParentBiDiMode = False
    end
    object sLabel2: TsLabel
      Left = 140
      Top = 96
      Width = 41
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Amount:'
      ParentBiDiMode = False
    end
    object sLabel5: TsLabel
      Left = 133
      Top = 123
      Width = 48
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Currency:'
      ParentBiDiMode = False
    end
    object cbxPaycards: TsComboBox
      Left = 192
      Top = 66
      Width = 472
      Height = 21
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 4473924
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = -1
      ParentFont = False
      TabOrder = 0
      OnCloseUp = cbxPaycardsCloseUp
      OnChange = cbxPaycardsChange
    end
    object btnProceed: TsButton
      Left = 191
      Top = 148
      Width = 91
      Height = 25
      Caption = 'Charge'
      TabOrder = 3
      OnClick = btnProceedClick
    end
    inline fraCurrency: TfraCurrencyPanel
      Left = 192
      Top = 120
      Width = 208
      Height = 20
      AutoSize = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      ExplicitLeft = 192
      ExplicitTop = 120
      ExplicitWidth = 208
      ExplicitHeight = 20
      inherited pnlLookup: TsPanel
        Width = 208
        ExplicitWidth = 208
      end
    end
    object edAmount: TsCurrencyEdit
      Left = 192
      Top = 93
      Width = 87
      Height = 21
      AutoSize = False
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnChange = edAmountChange
      CheckOnExit = True
      GlyphMode.Blend = 0
      GlyphMode.Grayed = False
      ShowButton = True
    end
  end
  inherited pnlButtons: TsPanel
    Top = 552
    Width = 768
    TabOrder = 0
    ExplicitTop = 552
    ExplicitWidth = 768
    inherited btnOK: TsButton
      Left = 452
      ExplicitLeft = 452
    end
    inherited btnCancel: TsButton
      Left = 558
      ExplicitLeft = 558
    end
    inherited btnClose: TsButton
      Left = 664
      ExplicitLeft = 664
    end
  end
  object pnlBottom: TsPanel [3]
    Left = 0
    Top = 179
    Width = 768
    Height = 373
    Align = alClient
    TabOrder = 3
    object pnlResult: TsPanel
      AlignWithMargins = True
      Left = 6
      Top = 6
      Width = 756
      Height = 361
      Margins.Left = 5
      Margins.Top = 5
      Margins.Right = 5
      Margins.Bottom = 5
      Align = alClient
      TabOrder = 0
      object sLabel6: TsLabel
        Left = 97
        Top = 59
        Width = 77
        Height = 13
        Alignment = taRightJustify
        BiDiMode = bdLeftToRight
        Caption = 'Operation type:'
        ParentBiDiMode = False
      end
      object sLabel7: TsLabel
        Left = 133
        Top = 32
        Width = 41
        Height = 13
        Alignment = taRightJustify
        BiDiMode = bdLeftToRight
        Caption = 'Amount:'
        ParentBiDiMode = False
      end
      object lblResRate: TsLabel
        Left = 413
        Top = 32
        Width = 72
        Height = 13
        Caption = '(Rate: 1.0000)'
      end
      object sLabel9: TsLabel
        Left = 92
        Top = 113
        Width = 82
        Height = 13
        Alignment = taRightJustify
        BiDiMode = bdLeftToRight
        Caption = 'Operation result:'
        ParentBiDiMode = False
      end
      object sLabel10: TsLabel
        Left = 37
        Top = 140
        Width = 137
        Height = 13
        Alignment = taRightJustify
        BiDiMode = bdLeftToRight
        Caption = 'Operation result description:'
        ParentBiDiMode = False
      end
      object sLabel11: TsLabel
        Left = 78
        Top = 167
        Width = 96
        Height = 13
        Alignment = taRightJustify
        BiDiMode = bdLeftToRight
        Caption = 'Payment reference:'
        ParentBiDiMode = False
      end
      object sLabel12: TsLabel
        Left = 42
        Top = 279
        Width = 132
        Height = 13
        Alignment = taRightJustify
        BiDiMode = bdLeftToRight
        Caption = 'Gateway result description:'
        ParentBiDiMode = False
      end
      object sLabel13: TsLabel
        Left = 7
        Top = 7
        Width = 64
        Height = 16
        Caption = 'Operation'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold, fsUnderline]
      end
      object sLabel14: TsLabel
        Left = 71
        Top = 252
        Width = 103
        Height = 13
        Alignment = taRightJustify
        BiDiMode = bdLeftToRight
        Caption = 'Gateway result code:'
        ParentBiDiMode = False
      end
      object sLabel8: TsLabel
        Left = 7
        Top = 84
        Width = 106
        Height = 16
        Caption = 'Operation result'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold, fsUnderline]
      end
      object sLabel15: TsLabel
        Left = 7
        Top = 194
        Width = 160
        Height = 16
        Caption = 'Payment gateway result'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold, fsUnderline]
      end
      object sLabel16: TsLabel
        Left = 98
        Top = 225
        Width = 76
        Height = 13
        Alignment = taRightJustify
        BiDiMode = bdLeftToRight
        Caption = 'Gateway name:'
        ParentBiDiMode = False
      end
      object edResAmount: TsEdit
        Left = 185
        Top = 29
        Width = 121
        Height = 21
        Alignment = taRightJustify
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
        Text = '0.00'
      end
      object edResCurrency: TsEdit
        Left = 312
        Top = 29
        Width = 91
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
      object edResOperationType: TsEdit
        Left = 185
        Top = 56
        Width = 218
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
      object edResOperationResult: TsEdit
        Left = 185
        Top = 110
        Width = 218
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ReadOnly = True
        TabOrder = 3
      end
      object edResOperationResultDescription: TsEdit
        Left = 185
        Top = 137
        Width = 464
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
      end
      object edResPaymentReference: TsEdit
        Left = 185
        Top = 164
        Width = 464
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
      object edResGatewayDescription: TsMemo
        Left = 185
        Top = 276
        Width = 464
        Height = 57
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
      object edResGatewayResult: TsEdit
        Left = 185
        Top = 249
        Width = 218
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
      object edResGatewayName: TsEdit
        Left = 185
        Top = 222
        Width = 218
        Height = 21
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
    end
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
