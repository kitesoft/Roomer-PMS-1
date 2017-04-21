inherited FrmEditResourceProperties: TFrmEditResourceProperties
  Caption = 'Edit Resource Properties'
  ClientHeight = 160
  ClientWidth = 606
  ExplicitWidth = 612
  ExplicitHeight = 189
  PixelsPerInch = 96
  TextHeight = 13
  object lbResourceName: TsLabel [0]
    Left = 64
    Top = 41
    Width = 78
    Height = 13
    Alignment = taRightJustify
    Caption = 'Resource name:'
  end
  object lbSubject: TsLabel [1]
    Left = 102
    Top = 68
    Width = 40
    Height = 13
    Alignment = taRightJustify
    Caption = 'Subject:'
  end
  object lbResourceType: TsLabel [2]
    Left = 68
    Top = 14
    Width = 74
    Height = 13
    Alignment = taRightJustify
    Caption = 'Resource type:'
  end
  inherited sbStatusBar: TsStatusBar
    Top = 140
    Width = 606
    ExplicitTop = 122
    ExplicitWidth = 597
  end
  inherited pnlButtons: TsPanel
    Top = 97
    Width = 606
    TabOrder = 4
    ExplicitTop = 79
    ExplicitWidth = 597
    inherited btnOK: TsButton
      Left = 396
      ExplicitLeft = 387
      ExplicitTop = 4
    end
    inherited btnCancel: TsButton
      Left = 502
      ExplicitLeft = 493
      ExplicitTop = 4
    end
  end
  object edtName: TsEdit [5]
    Left = 148
    Top = 38
    Width = 425
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnChange = edtNameChange
    SkinData.SkinSection = 'EDIT'
  end
  object edtSubject: TsEdit [6]
    Left = 148
    Top = 65
    Width = 425
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
  end
  object cbxResourceType: TsComboBox [7]
    Left = 148
    Top = 11
    Width = 425
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Style = csDropDownList
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = -1
    ParentFont = False
    TabOrder = 2
    OnChange = cbxResourceTypeChange
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
