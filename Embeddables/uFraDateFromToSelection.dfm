object fraDateFromToSelection: TfraDateFromToSelection
  Left = 0
  Top = 0
  Width = 326
  Height = 83
  TabOrder = 0
  object gbxSelectDates: TsGroupBox
    Left = 0
    Top = 0
    Width = 169
    Height = 83
    Align = alLeft
    Caption = 'Select dates'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    SkinData.SkinSection = 'GROUPBOX'
    ExplicitHeight = 154
    object dtDateFrom: TsDateEdit
      AlignWithMargins = True
      Left = 52
      Top = 18
      Width = 112
      Height = 21
      Margins.Left = 50
      Align = alTop
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
      OnChange = dtDateChange
      BoundLabel.Active = True
      BoundLabel.Caption = 'From :'
      SkinData.SkinSection = 'EDIT'
      GlyphMode.Blend = 0
      GlyphMode.Grayed = False
    end
    object dtDateTo: TsDateEdit
      AlignWithMargins = True
      Left = 52
      Top = 45
      Width = 112
      Height = 20
      Margins.Left = 50
      Align = alTop
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
      OnChange = dtDateChange
      BoundLabel.Active = True
      BoundLabel.Caption = 'To : '
      SkinData.SkinSection = 'EDIT'
      GlyphMode.Blend = 0
      GlyphMode.Grayed = False
    end
  end
  object gbxSelectMonth: TsGroupBox
    AlignWithMargins = True
    Left = 172
    Top = 0
    Width = 151
    Height = 83
    Margins.Top = 0
    Margins.Bottom = 0
    Align = alLeft
    Caption = '.. or select month'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    SkinData.SkinSection = 'GROUPBOX'
    ExplicitHeight = 154
    object cbxMonth: TsComboBox
      Left = 15
      Top = 20
      Width = 121
      Height = 21
      Alignment = taLeftJustify
      BoundLabel.Font.Charset = DEFAULT_CHARSET
      BoundLabel.Font.Color = clWindowText
      BoundLabel.Font.Height = -13
      BoundLabel.Font.Name = 'Tahoma'
      BoundLabel.Font.Style = []
      SkinData.SkinSection = 'COMBOBOX'
      VerticalAlignment = taAlignTop
      TextHint = 'Choose a month ...'
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
      OnChange = cbxMonthChange
      Items.Strings = (
        '')
    end
    object cbxYear: TsComboBox
      Left = 15
      Top = 47
      Width = 121
      Height = 21
      Alignment = taLeftJustify
      BoundLabel.Font.Charset = DEFAULT_CHARSET
      BoundLabel.Font.Color = clWindowText
      BoundLabel.Font.Height = -13
      BoundLabel.Font.Name = 'Tahoma'
      BoundLabel.Font.Style = []
      SkinData.SkinSection = 'COMBOBOX'
      VerticalAlignment = taAlignTop
      TextHint = 'Choose a year ...'
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = -1
      ParentFont = False
      TabOrder = 1
      OnChange = cbxMonthChange
    end
  end
end
