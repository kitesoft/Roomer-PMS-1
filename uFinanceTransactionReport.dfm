inherited frmFinanceTransactionReport: TfrmFinanceTransactionReport
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
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
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
        ExplicitLeft = -1
        ExplicitTop = 46
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
              Column = tvTrxListTransactionAmountNet
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Position = spFooter
              Column = tvTrxListTransactionAmountGross
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
              Column = tvTrxListTransactionAmountNet
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTransactionAmountGross
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
          object tvTrxListTransactionCode: TcxGridDBColumn
            Caption = 'Item Code'
            DataBinding.FieldName = 'TransactionCode'
            Width = 75
          end
          object tvTrxListCodeDescription: TcxGridDBColumn
            Caption = 'Item name'
            DataBinding.FieldName = 'CodeDescription'
            Width = 196
          end
          object tvTrxListBusinessDate: TcxGridDBColumn
            Caption = 'Business Date'
            DataBinding.FieldName = 'BusinessDate'
            Width = 96
          end
          object tvTrxListUpdateTimestamp: TcxGridDBColumn
            Caption = 'Timestamp'
            DataBinding.FieldName = 'UpdateTimestamp'
            Visible = False
          end
          object tvTrxListTransactionAmountNet: TcxGridDBColumn
            Caption = 'Net Amount'
            DataBinding.FieldName = 'TransactionAmountNet'
            Width = 91
          end
          object tvTrxListTransactionAmountGross: TcxGridDBColumn
            Caption = 'Gross Amount'
            DataBinding.FieldName = 'TransactionAmountGross'
            Width = 92
          end
          object tvTrxListTransactionCodeGroup: TcxGridDBColumn
            Caption = 'Item Type'
            DataBinding.FieldName = 'TransactionCodeGroup'
            Width = 77
          end
          object tvTrxListCodeGroupDescription: TcxGridDBColumn
            Caption = 'Item Type Name'
            DataBinding.FieldName = 'CodeGroupDescription'
            Width = 179
          end
          object tvTrxListTransactionCodeSubgroup: TcxGridDBColumn
            Caption = 'Sub-Group'
            DataBinding.FieldName = 'TransactionCodeSubgroup'
            Width = 82
          end
          object tvTrxListReservationID: TcxGridDBColumn
            Caption = 'Reservation Id'
            DataBinding.FieldName = 'ReservationID'
          end
          object tvTrxListRoomReservationID: TcxGridDBColumn
            Caption = 'Room Reservation Id'
            DataBinding.FieldName = 'RoomReservationID'
            Visible = False
          end
          object tvTrxListreportStart: TcxGridDBColumn
            DataBinding.FieldName = 'reportStart'
            Visible = False
          end
          object tvTrxListreportEnd: TcxGridDBColumn
            DataBinding.FieldName = 'reportEnd'
            Visible = False
          end
          object tvTrxListisChanged: TcxGridDBColumn
            DataBinding.FieldName = 'isChanged'
            Visible = False
          end
          object tvTrxListtransactionId: TcxGridDBColumn
            Caption = 'Transaction Id'
            DataBinding.FieldName = 'transactionId'
            Width = 390
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
    Indexes = <>
    SortOptions = []
    AfterScroll = mTrxListAfterScroll
    Left = 256
    Top = 321
    object mTrxListtransactionId: TWideStringField
      FieldName = 'transactionId'
      Size = 64
    end
    object mTrxListTransactionAmountNet: TFloatField
      FieldName = 'TransactionAmountNet'
    end
    object mTrxListTransactionAmountGross: TFloatField
      FieldName = 'TransactionAmountGross'
    end
    object mTrxListBusinessDate: TDateField
      FieldName = 'BusinessDate'
    end
    object mTrxListTransactionCode: TWideStringField
      FieldName = 'TransactionCode'
    end
    object mTrxListTransactionCodeGroup: TWideStringField
      FieldName = 'TransactionCodeGroup'
    end
    object mTrxListTransactionCodeSubgroup: TWideStringField
      FieldName = 'TransactionCodeSubgroup'
    end
    object mTrxListUpdateTimestamp: TDateTimeField
      FieldName = 'UpdateTimestamp'
    end
    object mTrxListReservationID: TWideStringField
      FieldName = 'ReservationID'
    end
    object mTrxListRoomReservationID: TIntegerField
      FieldName = 'RoomReservationID'
    end
    object mTrxListreportStart: TDateTimeField
      FieldName = 'reportStart'
    end
    object mTrxListreportEnd: TDateTimeField
      FieldName = 'reportEnd'
    end
    object mTrxListisChanged: TBooleanField
      FieldName = 'isChanged'
    end
    object mTrxListCodeDescription: TWideStringField
      FieldName = 'CodeDescription'
      Size = 50
    end
    object mTrxListCodeGroupDescription: TWideStringField
      FieldName = 'CodeGroupDescription'
      Size = 50
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
      end>
    StorageName = 'Software\Roomer\FormStatus\FinanceTransactionReport'
    StorageType = stRegistry
    Left = 496
    Top = 344
  end
end
