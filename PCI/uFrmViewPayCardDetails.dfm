inherited FrmViewPayCardDetails: TFrmViewPayCardDetails
  Caption = 'View card Details'
  ClientHeight = 357
  ClientWidth = 594
  Font.Height = -11
  OnShow = FormShow
  ExplicitWidth = 610
  ExplicitHeight = 396
  PixelsPerInch = 96
  TextHeight = 13
  object sLabel1: TsLabel [0]
    Left = 170
    Top = 75
    Width = 66
    Height = 13
    Alignment = taRightJustify
    Caption = 'Card number:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel2: TsLabel [1]
    Left = 166
    Top = 102
    Width = 70
    Height = 13
    Alignment = taRightJustify
    Caption = 'Name on card:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel3: TsLabel [2]
    Left = 159
    Top = 129
    Width = 77
    Height = 13
    Alignment = taRightJustify
    Caption = 'Expiration date:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel4: TsLabel [3]
    Left = 210
    Top = 179
    Width = 26
    Height = 13
    Alignment = taRightJustify
    Caption = 'User:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel5: TsLabel [4]
    Left = 179
    Top = 206
    Width = 57
    Height = 13
    Alignment = taRightJustify
    Caption = 'Description:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel10: TsLabel [5]
    Left = 193
    Top = 26
    Width = 43
    Height = 13
    Alignment = taRightJustify
    Caption = 'Created:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  inherited sbStatusBar: TsStatusBar
    Top = 337
    Width = 594
    ExplicitTop = 524
    ExplicitWidth = 594
  end
  object sPanel1: TsPanel [7]
    Left = 0
    Top = 296
    Width = 594
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitTop = 483
    object sButton1: TsButton
      AlignWithMargins = True
      Left = 514
      Top = 5
      Width = 75
      Height = 31
      Margins.Top = 5
      Margins.Right = 5
      Margins.Bottom = 5
      Align = alRight
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
    end
  end
  object edCardNumber: TsEdit [8]
    Left = 254
    Top = 72
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
  object edNameOnCard: TsEdit [9]
    Left = 254
    Top = 99
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
    TabOrder = 3
  end
  object edExpirationDate: TsEdit [10]
    Left = 254
    Top = 126
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
    TabOrder = 4
  end
  object edUser: TsEdit [11]
    Left = 254
    Top = 176
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
  object edDescription: TsMemo [12]
    Left = 254
    Top = 203
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
  object edWhen: TsEdit [13]
    Left = 254
    Top = 23
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
