inherited FrmChargePayCard: TFrmChargePayCard
  Caption = 'Charge pay-card'
  ClientHeight = 620
  ClientWidth = 746
  Font.Height = -11
  OnShow = FormShow
  ExplicitWidth = 762
  ExplicitHeight = 659
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 600
    Width = 746
    ExplicitTop = 600
    ExplicitWidth = 746
  end
  object sPanel1: TsPanel [1]
    Left = 0
    Top = 0
    Width = 746
    Height = 91
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitWidth = 739
    object sLabel3: TsLabel
      Left = 128
      Top = 21
      Width = 62
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Reservation:'
      ParentBiDiMode = False
    end
    object sLabel4: TsLabel
      Left = 98
      Top = 40
      Width = 92
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Room Reservation:'
      ParentBiDiMode = False
    end
    object lbRoomReservation: TsLabel
      Left = 201
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
      Left = 201
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
  end
  object sPanel2: TsPanel [2]
    Left = 0
    Top = 91
    Width = 746
    Height = 509
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitWidth = 739
    ExplicitHeight = 409
    object sLabel1: TsLabel
      Left = 143
      Top = 29
      Width = 47
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Pay-card:'
      ParentBiDiMode = False
    end
    object sLabel2: TsLabel
      Left = 149
      Top = 56
      Width = 41
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Amount:'
      ParentBiDiMode = False
    end
    object sLabel5: TsLabel
      Left = 142
      Top = 83
      Width = 48
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Currency:'
      ParentBiDiMode = False
    end
    object lblRate: TsLabel
      Left = 336
      Top = 83
      Width = 72
      Height = 13
      Caption = '(Rate: 1.0000)'
    end
    object cbxPaycards: TsComboBox
      Left = 201
      Top = 26
      Width = 472
      Height = 21
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Color = clWhite
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = -1
      ParentFont = False
      TabOrder = 0
      OnCloseUp = cbxPaycardsCloseUp
    end
    object edAmount: TsEdit
      Left = 201
      Top = 53
      Width = 121
      Height = 21
      Alignment = taRightJustify
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = '0.00'
    end
    object edCurrency: TsEdit
      Left = 201
      Top = 80
      Width = 91
      Height = 21
      Alignment = taRightJustify
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object btnProceed: TsButton
      Left = 201
      Top = 108
      Width = 90
      Height = 25
      Caption = 'Proceed'
      TabOrder = 3
      OnClick = btnProceedClick
    end
    object btnGetCurrency: TsButton
      Left = 293
      Top = 80
      Width = 29
      Height = 20
      Caption = '...'
      TabOrder = 4
      OnClick = btnGetCurrencyClick
      SkinData.SkinSection = 'BUTTON'
    end
    object pnlResult: TsPanel
      Left = 24
      Top = 160
      Width = 697
      Height = 344
      TabOrder = 5
      Visible = False
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
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = frmBaseRoomerForm.Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Top'
          'Width'
          'Position')
      end>
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
