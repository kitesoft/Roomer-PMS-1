inherited frmDailyTotalsReport: TfrmDailyTotalsReport
  Left = 961
  Top = 264
  Caption = 'Finance mutations'
  ClientHeight = 641
  ClientWidth = 1116
  Font.Height = -11
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  ExplicitWidth = 1132
  ExplicitHeight = 680
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 621
    Width = 1116
    ExplicitTop = 621
    ExplicitWidth = 1116
  end
  object pageMain: TsPageControl [1]
    Left = 0
    Top = 81
    Width = 1116
    Height = 540
    ActivePage = sheetMain
    Align = alClient
    TabOrder = 0
    SkinData.SkinSection = 'PAGECONTROL'
    object sheetMain: TsTabSheet
      Caption = 'Main'
      TabVisible = False
      object Panel1: TsPanel
        Left = 0
        Top = 0
        Width = 1108
        Height = 43
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object btnExcelS1: TsButton
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 128
          Height = 37
          Align = alLeft
          Caption = 'Excel'
          ImageIndex = 115
          Images = DImages.PngImageList1
          TabOrder = 0
          OnClick = btnExcelS1Click
          SkinData.SkinSection = 'BUTTON'
        end
      end
      object gTrxList: TcxGrid
        Left = 0
        Top = 43
        Width = 1108
        Height = 487
        Align = alClient
        BevelOuter = bvNone
        BorderStyle = cxcbsNone
        TabOrder = 1
        LookAndFeel.NativeStyle = False
        ExplicitTop = 41
        object tvTrxList: TcxGridDBTableView
          Navigator.Buttons.CustomButtons = <>
          Navigator.Buttons.First.Visible = True
          Navigator.Buttons.PriorPage.Visible = True
          Navigator.Buttons.Prior.Visible = True
          Navigator.Buttons.Next.Visible = True
          Navigator.Buttons.NextPage.Visible = True
          Navigator.Buttons.Last.Visible = True
          Navigator.Buttons.Insert.Enabled = False
          Navigator.Buttons.Insert.Visible = False
          Navigator.Buttons.Append.Enabled = False
          Navigator.Buttons.Append.Visible = False
          Navigator.Buttons.Delete.Enabled = False
          Navigator.Buttons.Delete.Visible = False
          Navigator.Buttons.Edit.Enabled = False
          Navigator.Buttons.Edit.Visible = False
          Navigator.Buttons.Post.Enabled = False
          Navigator.Buttons.Post.Visible = False
          Navigator.Buttons.Cancel.Enabled = False
          Navigator.Buttons.Cancel.Visible = True
          Navigator.Buttons.Refresh.Visible = True
          Navigator.Buttons.SaveBookmark.Visible = True
          Navigator.Buttons.GotoBookmark.Visible = True
          Navigator.Buttons.Filter.Visible = True
          DataController.DataSource = mTrxListDS
          DataController.Summary.DefaultGroupSummaryItems = <
            item
              Format = ',0;-,0'
              Kind = skSum
              Position = spFooter
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0.00;-,0.00'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Position = spFooter
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Position = spFooter
            end>
          DataController.Summary.FooterSummaryItems = <
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'Total'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalWOVAT'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalVAT'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalStayTax'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalStayTaxNights'
            end
            item
              Kind = skCount
              FieldName = 'InvoiceNumber'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'totalStayTaxExcluted'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalTax'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotalACC
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotalACCWOVat
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotalFB
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotalFBWOVat
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotalAUX
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotalAUXWOVat
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotal
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotalWOVat
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.IncSearch = True
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsView.Footer = True
          OptionsView.HeaderAutoHeight = True
          OptionsView.Indicator = True
          Styles.StyleSheet = cxssRoomerGridTableView
          object tvTrxListRecId: TcxGridDBColumn
            DataBinding.FieldName = 'RecId'
            Visible = False
          end
          object tvTrxListdate: TcxGridDBColumn
            Caption = 'Date'
            DataBinding.FieldName = 'date'
            HeaderAlignmentHorz = taCenter
            Width = 82
          end
          object tvTrxListDEF: TcxGridDBColumn
            Caption = 'Confirmed'
            DataBinding.FieldName = 'DEF'
            HeaderAlignmentHorz = taRightJustify
            Width = 80
          end
          object tvTrxListTNT: TcxGridDBColumn
            Caption = 'Tentative'
            DataBinding.FieldName = 'TNT'
            HeaderAlignmentHorz = taRightJustify
          end
          object tvTrxListOPT: TcxGridDBColumn
            Caption = 'Optional'
            DataBinding.FieldName = 'OPT'
            HeaderAlignmentHorz = taRightJustify
          end
          object tvTrxListCXL: TcxGridDBColumn
            Caption = 'Cancelled'
            DataBinding.FieldName = 'CXL'
            HeaderAlignmentHorz = taRightJustify
          end
          object tvTrxListTotalACC: TcxGridDBColumn
            Caption = 'Gross Accomodation'
            DataBinding.FieldName = 'TotalACC'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
            Width = 128
          end
          object tvTrxListTotalACCWOVat: TcxGridDBColumn
            Caption = 'Net Accomodation'
            DataBinding.FieldName = 'TotalACCWOVat'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
            Width = 138
          end
          object tvTrxListTotalFB: TcxGridDBColumn
            Caption = 'Gross F&B'
            DataBinding.FieldName = 'TotalFB'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
            Width = 97
          end
          object tvTrxListTotalFBWOVat: TcxGridDBColumn
            Caption = 'Net F&B'
            DataBinding.FieldName = 'TotalFBWOVat'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
            Width = 88
          end
          object tvTrxListTotalAUX: TcxGridDBColumn
            Caption = 'Gross Various'
            DataBinding.FieldName = 'TotalAUX'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
            Width = 120
          end
          object tvTrxListTotalAUXWOVat: TcxGridDBColumn
            Caption = 'Net Various'
            DataBinding.FieldName = 'TotalAUXWOVat'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
            Width = 128
          end
          object tvTrxListTotal: TcxGridDBColumn
            Caption = 'Gross Total'
            DataBinding.FieldName = 'Total'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
            Width = 127
          end
          object tvTrxListTotalWOVat: TcxGridDBColumn
            Caption = 'Net Total'
            DataBinding.FieldName = 'TotalWOVat'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
            Width = 131
          end
        end
        object lvTrxList: TcxGridLevel
          GridView = tvTrxList
        end
      end
    end
  end
  object Panel3: TsPanel [2]
    Left = 0
    Top = 0
    Width = 1116
    Height = 81
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    object gbxPeriodSelection: TsGroupBox
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 189
      Height = 75
      Align = alLeft
      Caption = 'Select report period'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      object sLabel1: TsLabel
        Left = 34
        Top = 23
        Width = 28
        Height = 13
        Alignment = taRightJustify
        Caption = 'From:'
      end
      object sLabel2: TsLabel
        Left = 46
        Top = 50
        Width = 16
        Height = 13
        Alignment = taRightJustify
        Caption = 'To:'
      end
      object dtDateFrom: TsDateEdit
        Left = 68
        Top = 20
        Width = 105
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
      object dtDateTo: TsDateEdit
        Left = 68
        Top = 47
        Width = 105
        Height = 20
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
    end
    object btnRefresh: TsButton
      Left = 198
      Top = 17
      Width = 100
      Height = 37
      Caption = 'Refresh ALL'
      Enabled = False
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 1
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
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
  object mTrxList: TdxMemData
    Active = True
    Indexes = <>
    SortOptions = []
    AfterScroll = mTrxListAfterScroll
    Left = 256
    Top = 321
    object mTrxListdate: TDateField
      FieldName = 'date'
    end
    object mTrxListDEF: TIntegerField
      FieldName = 'DEF'
    end
    object mTrxListTNT: TIntegerField
      FieldName = 'TNT'
    end
    object mTrxListCXL: TIntegerField
      FieldName = 'CXL'
    end
    object mTrxListOPT: TIntegerField
      FieldName = 'OPT'
    end
    object mTrxListTotalACC: TFloatField
      FieldName = 'TotalACC'
    end
    object mTrxListTotalACCWOVat: TFloatField
      FieldName = 'TotalACCWOVat'
    end
    object mTrxListTotalAUX: TFloatField
      FieldName = 'TotalAUX'
    end
    object mTrxListTotalAUXWOVat: TFloatField
      FieldName = 'TotalAUXWOVat'
    end
    object mTrxListTotal: TFloatField
      FieldName = 'Total'
    end
    object mTrxListTotalWOVat: TFloatField
      FieldName = 'TotalWOVat'
    end
    object mTrxListTotalFB: TFloatField
      FieldName = 'TotalFB'
    end
    object mTrxListTotalFBWOVat: TFloatField
      FieldName = 'TotalFBWOVat'
    end
  end
  object mTrxListDS: TDataSource
    DataSet = mTrxList
    Left = 344
    Top = 321
  end
  object StoreMain: TcxPropertiesStore
    Components = <
      item
        Component = Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Position'
          'Top'
          'Width')
      end
      item
        Component = tvTrxListCXL
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListdate
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListDEF
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListOPT
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListRecId
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListTNT
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListTotal
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListTotalACC
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListTotalACCWOVat
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListTotalAUX
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListTotalAUXWOVat
        Properties.Strings = (
          'Width')
      end
      item
        Component = tvTrxListTotalWOVat
        Properties.Strings = (
          'Width')
      end>
    StorageName = 'Software\Roomer\FormStatus\DailyTotalsReport2'
    StorageType = stRegistry
    Left = 496
    Top = 344
  end
end
