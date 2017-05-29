object frmInvoicePayment: TfrmInvoicePayment
  Left = 878
  Top = 10
  BorderStyle = bsDialog
  Caption = 'Invoice payment'
  ClientHeight = 471
  ClientWidth = 314
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  Scaled = False
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TsPanel
    Left = 0
    Top = 426
    Width = 314
    Height = 45
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    ExplicitTop = 416
    DesignSize = (
      314
      45)
    object BtnOk: TsButton
      Left = 116
      Top = 4
      Width = 83
      Height = 37
      Hint = 'Apply and close'
      Anchors = [akTop, akRight]
      Caption = 'OK'
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 0
      OnClick = BtnOkClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnCancel: TsButton
      Left = 205
      Top = 4
      Width = 102
      Height = 37
      Hint = 'Cancel and close'
      Anchors = [akTop, akRight]
      Caption = 'Cancel'
      ImageIndex = 4
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
    end
  end
  object Panel2: TsPanel
    Left = 0
    Top = 0
    Width = 314
    Height = 29
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object lblCustomername: TsLabel
      Left = 202
      Top = 8
      Width = 74
      Height = 13
      AutoSize = False
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object lblAmount: TsLabel
      Left = 30
      Top = 8
      Width = 37
      Height = 13
      Alignment = taRightJustify
      Caption = 'Amount'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object edtCustomer: TsEdit
      Left = 322
      Top = 37
      Width = 103
      Height = 21
      BorderStyle = bsNone
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      SkinData.SkinSection = 'EDIT'
    end
    object edtAmount: TsEdit
      Left = 73
      Top = 5
      Width = 123
      Height = 21
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnExit = edtAmountExit
      SkinData.SkinSection = 'EDIT'
    end
  end
  object Panel3: TsPanel
    Left = 0
    Top = 108
    Width = 314
    Height = 19
    Align = alTop
    Alignment = taLeftJustify
    BevelWidth = 2
    Caption = 'Payment type:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    SkinData.SkinSection = 'PANEL'
    ExplicitTop = 77
  end
  object agrPayTypes: TAdvStringGrid
    Left = 0
    Top = 127
    Width = 314
    Height = 180
    Cursor = crDefault
    Align = alClient
    BorderStyle = bsNone
    ColCount = 2
    DefaultRowHeight = 19
    DrawingStyle = gdsClassic
    RowCount = 2
    ScrollBars = ssBoth
    TabOrder = 1
    OnEnter = agrPayTypesEnter
    OnKeyDown = agrPayTypesKeyDown
    OnSelectCell = agrPayTypesSelectCell
    HoverRowCells = [hcNormal, hcSelected]
    OnGetAlignment = agrPayTypesGetAlignment
    OnClickCell = agrPayTypesClickCell
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ControlLook.FixedGradientHoverFrom = clGray
    ControlLook.FixedGradientHoverTo = clWhite
    ControlLook.FixedGradientDownFrom = clGray
    ControlLook.FixedGradientDownTo = clSilver
    ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
    ControlLook.DropDownHeader.Font.Color = clWindowText
    ControlLook.DropDownHeader.Font.Height = -11
    ControlLook.DropDownHeader.Font.Name = 'Tahoma'
    ControlLook.DropDownHeader.Font.Style = []
    ControlLook.DropDownHeader.Visible = True
    ControlLook.DropDownHeader.Buttons = <>
    ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
    ControlLook.DropDownFooter.Font.Color = clWindowText
    ControlLook.DropDownFooter.Font.Height = -11
    ControlLook.DropDownFooter.Font.Name = 'Tahoma'
    ControlLook.DropDownFooter.Font.Style = []
    ControlLook.DropDownFooter.Visible = True
    ControlLook.DropDownFooter.Buttons = <>
    Filter = <>
    FilterDropDown.Font.Charset = DEFAULT_CHARSET
    FilterDropDown.Font.Color = clWindowText
    FilterDropDown.Font.Height = -11
    FilterDropDown.Font.Name = 'Tahoma'
    FilterDropDown.Font.Style = []
    FilterDropDownClear = '(All)'
    FilterEdit.TypeNames.Strings = (
      'Starts with'
      'Ends with'
      'Contains'
      'Not contains'
      'Equal'
      'Not equal'
      'Larger than'
      'Smaller than'
      'Clear')
    FixedColWidth = 169
    FixedRowHeight = 19
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = [fsBold]
    FloatFormat = '%.2f'
    HoverButtons.Buttons = <>
    HoverButtons.Position = hbLeftFromColumnLeft
    HTMLSettings.ImageFolder = 'images'
    HTMLSettings.ImageBaseName = 'img'
    PrintSettings.DateFormat = 'dd/mm/yyyy'
    PrintSettings.Font.Charset = DEFAULT_CHARSET
    PrintSettings.Font.Color = clWindowText
    PrintSettings.Font.Height = -11
    PrintSettings.Font.Name = 'Tahoma'
    PrintSettings.Font.Style = []
    PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
    PrintSettings.FixedFont.Color = clWindowText
    PrintSettings.FixedFont.Height = -11
    PrintSettings.FixedFont.Name = 'Tahoma'
    PrintSettings.FixedFont.Style = []
    PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
    PrintSettings.HeaderFont.Color = clWindowText
    PrintSettings.HeaderFont.Height = -11
    PrintSettings.HeaderFont.Name = 'Tahoma'
    PrintSettings.HeaderFont.Style = []
    PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
    PrintSettings.FooterFont.Color = clWindowText
    PrintSettings.FooterFont.Height = -11
    PrintSettings.FooterFont.Name = 'Tahoma'
    PrintSettings.FooterFont.Style = []
    PrintSettings.PageNumSep = '/'
    SearchFooter.Font.Charset = DEFAULT_CHARSET
    SearchFooter.Font.Color = clWindowText
    SearchFooter.Font.Height = -11
    SearchFooter.Font.Name = 'Tahoma'
    SearchFooter.Font.Style = []
    SearchFooter.ResultFormat = '(%d of %d)'
    SortSettings.DefaultFormat = ssAutomatic
    Version = '8.2.5.2'
    ExplicitTop = 96
    ExplicitHeight = 201
    ColWidths = (
      169
      116)
    RowHeights = (
      19
      19)
  end
  object Panel5: TsPanel
    Left = 0
    Top = 307
    Width = 314
    Height = 22
    Align = alBottom
    BevelOuter = bvLowered
    Color = clGray
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clCaptionText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    SkinData.SkinSection = 'PANEL'
    ExplicitTop = 297
    object Label2: TsLabel
      Left = 26
      Top = 5
      Width = 45
      Height = 13
      Alignment = taRightJustify
      Caption = 'Selected:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object Label3: TsLabel
      Left = 141
      Top = 5
      Width = 23
      Height = 13
      Caption = 'Left:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object lblSelected: TsLabel
      Left = 77
      Top = 5
      Width = 6
      Height = 13
      Caption = '0'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object lblLeft: TsLabel
      Left = 172
      Top = 5
      Width = 94
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = '0.00'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
  end
  object sPanel1: TsPanel
    Left = 0
    Top = 329
    Width = 314
    Height = 97
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 5
    SkinData.SkinSection = 'PANEL'
    ExplicitTop = 319
    object sLabel1: TsLabel
      Left = 10
      Top = 11
      Width = 127
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Invoice Date :'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object sLabel2: TsLabel
      Left = 7
      Top = 38
      Width = 127
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Due Date :'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object sLabel3: TsLabel
      Left = 7
      Top = 67
      Width = 127
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Location :'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object dtInvDate: TsDateEdit
      Left = 140
      Top = 8
      Width = 111
      Height = 21
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
      SkinData.SkinSection = 'EDIT'
      GlyphMode.Blend = 0
      GlyphMode.Grayed = False
    end
    object dtPayDate: TsDateEdit
      Left = 140
      Top = 35
      Width = 111
      Height = 21
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
      SkinData.SkinSection = 'EDIT'
      GlyphMode.Blend = 0
      GlyphMode.Grayed = False
    end
    object cbxLocation: TsComboBox
      Left = 140
      Top = 62
      Width = 138
      Height = 21
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
      ItemIndex = 0
      ParentFont = False
      TabOrder = 2
      Text = 'Select Location'
      Items.Strings = (
        'Select Location')
    end
  end
  object __pnlCurrencies: TsPanel
    Left = 0
    Top = 29
    Width = 314
    Height = 79
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 6
    object LblForeignCurrencyAmount: TsLabel
      Left = 31
      Top = 8
      Width = 124
      Height = 13
      Alignment = taRightJustify
      Caption = 'Foreign currency amount:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object LblLocalCurrencyAmount: TsLabel
      Left = 43
      Top = 27
      Width = 112
      Height = 13
      Alignment = taRightJustify
      Caption = 'Local currency amount:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object __LblForeignCurrency: TsLabel
      Left = 224
      Top = 4
      Width = 29
      Height = 18
      Alignment = taRightJustify
      Caption = '0.00'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object __LblLocalCurrency: TsLabel
      Left = 224
      Top = 23
      Width = 29
      Height = 18
      Alignment = taRightJustify
      Caption = '0.00'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object LblForeignCurrency: TsLabel
      Left = 264
      Top = 8
      Width = 12
      Height = 13
      Caption = '...'
    end
    object LblLocalCurrency: TsLabel
      Left = 264
      Top = 27
      Width = 12
      Height = 13
      Caption = '...'
    end
    object btnViewPayCard: TsButton
      Left = 141
      Top = 46
      Width = 112
      Height = 32
      Caption = 'Pay-card info'
      ImageIndex = 92
      Images = DImages.PngImageList1
      TabOrder = 0
      OnClick = btnViewPayCardClick
    end
  end
  object sSkinProvider1: TsSkinProvider
    SkinData.SkinSection = 'FORM'
    TitleButtons = <>
    Left = 136
    Top = 208
  end
end
