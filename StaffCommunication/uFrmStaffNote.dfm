inherited FrmStaffNote: TFrmStaffNote
  BorderStyle = bsSizeable
  Caption = 'Note for the staff'
  ClientHeight = 334
  ClientWidth = 426
  Constraints.MinHeight = 373
  Constraints.MinWidth = 442
  ExplicitWidth = 442
  ExplicitHeight = 373
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 314
    Width = 426
    ExplicitTop = 517
    ExplicitWidth = 657
  end
  object sPanel1: TsPanel [1]
    Left = 0
    Top = 0
    Width = 426
    Height = 91
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    ExplicitWidth = 443
    object sLabel1: TsLabel
      Left = 23
      Top = 16
      Width = 69
      Height = 13
      Alignment = taRightJustify
      Caption = 'Note for date:'
    end
    object sLabel2: TsLabel
      Left = 34
      Top = 39
      Width = 58
      Height = 13
      Alignment = taRightJustify
      Caption = 'Created by:'
    end
    object lblAuthor: TsLabel
      Left = 100
      Top = 39
      Width = 4
      Height = 13
      Caption = '-'
    end
    object lblWhen: TsLabel
      Left = 100
      Top = 56
      Width = 4
      Height = 13
      Caption = '-'
    end
    object sLabel6: TsLabel
      Left = 36
      Top = 56
      Width = 56
      Height = 13
      Alignment = taRightJustify
      Caption = 'Created at:'
    end
    object lblUntil: TsLabel
      Left = 237
      Top = 16
      Width = 62
      Height = 13
      Alignment = taRightJustify
      Caption = 'Repeat until:'
    end
    object dtDateFrom: TsDateEdit
      Left = 100
      Top = 13
      Width = 125
      Height = 23
      AutoSize = False
      Color = clWhite
      EditMask = '!99/99/9999;1; '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 0
      Text = '  -  -    '
      OnChange = dtDateFromChange
      GlyphMode.Blend = 0
      GlyphMode.Grayed = False
    end
    object dtDateUntil: TsDateEdit
      Left = 305
      Top = 13
      Width = 117
      Height = 23
      AutoSize = False
      Color = clWhite
      EditMask = '!99/99/9999;1; '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 1
      Text = '  -  -    '
      OnChange = dtDateFromChange
      GlyphMode.Blend = 0
      GlyphMode.Grayed = False
    end
  end
  inherited pnlButtons: TsPanel
    Top = 271
    Width = 426
    TabOrder = 0
    ExplicitTop = 474
    ExplicitWidth = 657
    inherited btnOK: TsButton
      Left = 216
      ExplicitLeft = 447
      ExplicitTop = 4
    end
    inherited btnCancel: TsButton
      Left = 322
      ExplicitLeft = 553
      ExplicitTop = 4
    end
  end
  object sPanel2: TsPanel [3]
    Left = 0
    Top = 91
    Width = 426
    Height = 180
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 3
    ExplicitTop = 111
    ExplicitWidth = 561
    ExplicitHeight = 216
    object sLabel3: TsLabel
      Left = 33
      Top = 6
      Width = 59
      Height = 13
      Alignment = taRightJustify
      Caption = 'Action type:'
    end
    object sLabel4: TsLabel
      Left = 65
      Top = 30
      Width = 27
      Height = 13
      Alignment = taRightJustify
      Caption = 'Note:'
    end
    object __cbxAction: TsComboBox
      AlignWithMargins = True
      Left = 100
      Top = 3
      Width = 323
      Height = 21
      Margins.Left = 100
      Align = alTop
      Alignment = taLeftJustify
      SkinData.SkinSection = 'COMBOBOX'
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
      TabOrder = 0
      ExplicitLeft = 110
      ExplicitTop = 28
      ExplicitWidth = 427
    end
    object mmoText: TsMemo
      AlignWithMargins = True
      Left = 100
      Top = 27
      Width = 323
      Height = 150
      Margins.Left = 100
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
      ExplicitLeft = 117
      ExplicitTop = 30
      ExplicitWidth = 428
      ExplicitHeight = 166
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 32
    Top = 232
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 32
    Top = 184
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
