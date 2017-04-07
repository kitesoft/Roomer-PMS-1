inherited FrmStaffNote: TFrmStaffNote
  Caption = 'Note for the day'
  ClientHeight = 537
  ClientWidth = 657
  Font.Height = -11
  ExplicitWidth = 673
  ExplicitHeight = 576
  PixelsPerInch = 96
  TextHeight = 13
  object sLabel3: TsLabel [0]
    Left = 67
    Top = 139
    Width = 86
    Height = 19
    Alignment = taRightJustify
    Caption = 'Action type:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object sLabel4: TsLabel [1]
    Left = 114
    Top = 171
    Width = 39
    Height = 19
    Alignment = taRightJustify
    Caption = 'Note:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  inherited sbStatusBar: TsStatusBar
    Top = 517
    Width = 657
    ExplicitTop = 517
    ExplicitWidth = 657
  end
  object panBtn: TsPanel [3]
    Left = 0
    Top = 485
    Width = 657
    Height = 32
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    DesignSize = (
      657
      32)
    object btnCancel: TsButton
      Left = 578
      Top = 4
      Width = 75
      Height = 25
      Hint = 'Cancel and close'
      Anchors = [akTop, akRight]
      Cancel = True
      Caption = 'Cancel'
      ImageIndex = 4
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 0
      SkinData.SkinSection = 'BUTTON'
    end
    object BtnOk: TsButton
      Left = 500
      Top = 4
      Width = 75
      Height = 25
      Hint = 'Apply and close'
      Anchors = [akTop, akRight]
      Caption = 'OK'
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
    end
  end
  object sPanel1: TsPanel [4]
    Left = 0
    Top = 0
    Width = 657
    Height = 113
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object sLabel1: TsLabel
      Left = 106
      Top = 16
      Width = 99
      Height = 19
      Alignment = taRightJustify
      Caption = 'Note for date:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object sLabel2: TsLabel
      Left = 123
      Top = 41
      Width = 82
      Height = 19
      Alignment = taRightJustify
      Caption = 'Created by:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object lblAuthor: TsLabel
      Left = 220
      Top = 41
      Width = 6
      Height = 19
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object lblWhen: TsLabel
      Left = 220
      Top = 66
      Width = 6
      Height = 19
      Caption = '-'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object sLabel6: TsLabel
      Left = 127
      Top = 66
      Width = 78
      Height = 19
      Alignment = taRightJustify
      Caption = 'Created at:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object lblUntil: TsLabel
      Left = 368
      Top = 16
      Width = 37
      Height = 19
      Alignment = taRightJustify
      Caption = 'until:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object dtDateFrom: TsDateEdit
      Left = 220
      Top = 13
      Width = 125
      Height = 23
      AutoSize = False
      EditMask = '!99/99/9999;1; '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
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
      Left = 412
      Top = 13
      Width = 117
      Height = 23
      AutoSize = False
      EditMask = '!99/99/9999;1; '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
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
  object __cbxAction: TsComboBox [5]
    Left = 167
    Top = 139
    Width = 427
    Height = 27
    Alignment = taLeftJustify
    SkinData.SkinSection = 'COMBOBOX'
    VerticalAlignment = taAlignTop
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = -1
    ParentFont = False
    TabOrder = 2
  end
  object mmoText: TsMemo [6]
    Left = 166
    Top = 171
    Width = 427
    Height = 286
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    SkinData.SkinSection = 'EDIT'
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
    Left = 608
    Top = 64
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 608
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
