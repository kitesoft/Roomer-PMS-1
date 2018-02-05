inherited frmGroupGuests: TfrmGroupGuests
  Caption = 'Group Guests'
  ClientHeight = 654
  ClientWidth = 1121
  ParentFont = False
  ExplicitWidth = 1137
  ExplicitHeight = 693
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 634
    Width = 1121
    ExplicitTop = 634
    ExplicitWidth = 1121
  end
  inherited pnlButtons: TsPanel
    Top = 591
    Width = 1121
    ExplicitTop = 591
    ExplicitWidth = 1121
    inherited btnOK: TsButton
      Left = 805
      OnClick = btnOKClick
      ExplicitLeft = 805
    end
    inherited btnCancel: TsButton
      Left = 911
      ExplicitLeft = 911
    end
    inherited btnClose: TsButton
      Left = 1017
      ExplicitLeft = 1017
    end
  end
  inherited pnlTop: TsPanel
    Width = 1121
    Height = 154
    TabOrder = 3
    ExplicitWidth = 1121
    ExplicitHeight = 154
    object pnlSelection: TsPanel
      Left = 0
      Top = 0
      Width = 1121
      Height = 113
      Align = alTop
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      object rgrShow: TsRadioGroup
        Left = 14
        Top = 10
        Width = 147
        Height = 64
        Caption = 'Select'
        TabOrder = 0
        OnClick = rgrShowClick
        SkinData.SkinSection = 'GROUPBOX'
        ItemIndex = 0
        Items.Strings = (
          'All Guests'
          'Just Main Guests')
      end
      object chkCompactView: TsCheckBox
        Left = 14
        Top = 80
        Width = 87
        Height = 20
        Caption = 'Compact view'
        Checked = True
        State = cbChecked
        TabOrder = 1
        OnClick = chkCompactViewClick
        SkinData.SkinSection = 'CHECKBOX'
        ImgChecked = 0
        ImgUnchecked = 0
      end
    end
    object pnlGridButtons: TsPanel
      Left = 0
      Top = 113
      Width = 1121
      Height = 41
      Align = alTop
      TabOrder = 1
      SkinData.SkinSection = 'PANEL'
      object btnExcel: TsButton
        AlignWithMargins = True
        Left = 4
        Top = 4
        Width = 120
        Height = 33
        Align = alLeft
        Caption = 'Excel'
        ImageIndex = 132
        Images = DImages.PngImageList1
        TabOrder = 0
        OnClick = btnExcelClick
        SkinData.SkinSection = 'BUTTON'
      end
      object sButton1: TsButton
        AlignWithMargins = True
        Left = 130
        Top = 4
        Width = 120
        Height = 33
        Align = alLeft
        Caption = 'Notes'
        ImageIndex = 94
        Images = DImages.PngImageList1
        TabOrder = 1
        OnClick = sButton1Click
        SkinData.SkinSection = 'BUTTON'
      end
      object btnExpand: TsButton
        AlignWithMargins = True
        Left = 634
        Top = 4
        Width = 120
        Height = 33
        Align = alLeft
        Caption = 'Expand'
        ImageIndex = 94
        TabOrder = 2
        OnClick = btnExpandClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnCollapse: TsButton
        AlignWithMargins = True
        Left = 508
        Top = 4
        Width = 120
        Height = 33
        Align = alLeft
        Caption = 'Collapse'
        ImageIndex = 94
        TabOrder = 3
        OnClick = btnCollapseClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnEdit: TsButton
        AlignWithMargins = True
        Left = 256
        Top = 4
        Width = 120
        Height = 33
        Hint = 'Edit current record'
        Align = alLeft
        Caption = 'Edit'
        ImageIndex = 25
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = btnEditClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnOther: TsButton
        AlignWithMargins = True
        Left = 760
        Top = 4
        Width = 120
        Height = 33
        Hint = 'Other actions - Select from menu'
        Align = alLeft
        Caption = 'Other actions'
        DropDownMenu = pmnuOther
        ImageIndex = 76
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        Style = bsSplitButton
        TabOrder = 5
        SkinData.SkinSection = 'BUTTON'
      end
      object btnClearAddress: TsButton
        AlignWithMargins = True
        Left = 382
        Top = 4
        Width = 120
        Height = 33
        Align = alLeft
        Caption = 'Clear Address'
        ImageIndex = 11
        Images = DImages.PngImageList1
        TabOrder = 6
        Visible = False
        OnClick = btnClearAddressClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
  end
  inherited pnlClient: TsPanel
    Top = 154
    Width = 1121
    Height = 437
    TabOrder = 2
    ExplicitTop = 154
    ExplicitWidth = 1121
    ExplicitHeight = 437
    object splClient: TsSplitter [0]
      Left = 1
      Top = 330
      Width = 1119
      Height = 6
      Cursor = crVSplit
      Align = alBottom
      Color = clActiveCaption
      ParentColor = False
      ExplicitTop = 1
      ExplicitWidth = 335
    end
    inherited grData: TcxGrid
      Width = 1119
      Height = 329
      ExplicitWidth = 1119
      ExplicitHeight = 329
      inherited tvData: TcxGridDBBandedTableView
        DataController.KeyFieldNames = 'RoomReservation'
        DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
        OptionsData.Editing = True
        OptionsView.BandHeaders = False
        Styles.Content = nil
        Styles.ContentEven = nil
        Styles.ContentOdd = nil
        Styles.Selection = nil
        Styles.Footer = nil
        Styles.Group = nil
        Styles.GroupSummary = nil
        Styles.Header = nil
        Styles.Preview = nil
        Bands = <
          item
          end>
        object tvRoomsRecId: TcxGridDBBandedColumn
          DataBinding.FieldName = 'RecId'
          Visible = False
          Position.BandIndex = 0
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object tvRoomsRoomReservation: TcxGridDBBandedColumn
          DataBinding.FieldName = 'RoomReservation'
          Visible = False
          Width = 85
          Position.BandIndex = 0
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object tvRoomsRoom: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Room'
          Options.Editing = False
          Width = 62
          Position.BandIndex = 0
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object tvRoomsBreakfast: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Breakfast'
          Options.Editing = False
          Width = 88
          Position.BandIndex = 0
          Position.ColIndex = 8
          Position.RowIndex = 0
        end
        object tvRoomsrrArrival: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Arrival'
          Options.Editing = False
          Width = 72
          Position.BandIndex = 0
          Position.ColIndex = 3
          Position.RowIndex = 0
        end
        object tvRoomsrrDeparture: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Departure'
          Options.Editing = False
          Width = 72
          Position.BandIndex = 0
          Position.ColIndex = 4
          Position.RowIndex = 0
        end
        object tvRoomsnumGuests: TcxGridDBBandedColumn
          Caption = 'Nr of Guests'
          DataBinding.FieldName = 'numGuests'
          Width = 95
          Position.BandIndex = 0
          Position.ColIndex = 5
          Position.RowIndex = 0
        end
        object tvRoomsRoomDescription: TcxGridDBBandedColumn
          DataBinding.FieldName = 'RoomDescription'
          Options.Editing = False
          Width = 109
          Position.BandIndex = 0
          Position.ColIndex = 6
          Position.RowIndex = 0
        end
        object tvRoomsStatusText: TcxGridDBBandedColumn
          Caption = 'Status'
          DataBinding.FieldName = 'status'
          OnGetDisplayText = tvRoomsStatusTextGetDisplayText
          Options.Editing = False
          Width = 121
          Position.BandIndex = 0
          Position.ColIndex = 7
          Position.RowIndex = 0
        end
        object tvRoomsroomDetails: TcxGridDBBandedColumn
          Caption = 'Room Details'
          DataBinding.FieldName = 'roomDetails'
          Options.Editing = False
          Width = 203
          Position.BandIndex = 0
          Position.ColIndex = 9
          Position.RowIndex = 0
        end
        object tvRoomsRoomType: TcxGridDBBandedColumn
          DataBinding.FieldName = 'RoomType'
          Options.Editing = False
          Width = 105
          Position.BandIndex = 0
          Position.ColIndex = 10
          Position.RowIndex = 0
        end
      end
      object tvGuests: TcxGridDBBandedTableView [1]
        OnDblClick = tvGuestsDblClick
        Navigator.Buttons.CustomButtons = <>
        Navigator.InfoPanel.Visible = True
        FilterBox.Visible = fvNever
        DataController.DataSource = dsGuests
        DataController.DetailKeyFieldNames = 'RoomReservation'
        DataController.KeyFieldNames = 'Id'
        DataController.MasterKeyFieldNames = 'RoomReservation'
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.FocusCellOnTab = True
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Inserting = False
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        OptionsView.BandHeaderEndEllipsis = True
        Styles.StyleSheet = cxssRoomerGridBandedTableView
        Bands = <
          item
            Caption = 'Main'
            Width = 381
          end
          item
            Caption = 'Address'
            Width = 706
          end
          item
            Caption = 'Contact'
          end
          item
            Caption = 'Other'
            Width = 541
          end>
        object tvguestsRoomreservation: TcxGridDBBandedColumn
          DataBinding.FieldName = 'RoomReservation'
          Visible = False
          Options.Editing = False
          Width = 540
          Position.BandIndex = 0
          Position.ColIndex = 3
          Position.RowIndex = 0
        end
        object tvGueststitle: TcxGridDBBandedColumn
          Caption = 'Title'
          DataBinding.FieldName = 'title'
          Width = 45
          Position.BandIndex = 0
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object tvGuestsname: TcxGridDBBandedColumn
          DataBinding.FieldName = 'name'
          MinWidth = 226
          Options.HorzSizing = False
          Width = 226
          Position.BandIndex = 0
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object tvGuestsMainName: TcxGridDBBandedColumn
          Caption = 'Mainguest'
          DataBinding.FieldName = 'MainName'
          MinWidth = 40
          Options.Editing = False
          SortIndex = 0
          SortOrder = soDescending
          Width = 93
          Position.BandIndex = 0
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object tvGuestsTel1: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Tel1'
          Width = 100
          Position.BandIndex = 2
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object tvGuestsTel2: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Tel2'
          Width = 100
          Position.BandIndex = 2
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object tvGuestsFax: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Fax'
          Width = 100
          Position.BandIndex = 2
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object tvGuestsEmail: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Email'
          Width = 142
          Position.BandIndex = 2
          Position.ColIndex = 3
          Position.RowIndex = 0
        end
        object tvGuestsAddress1: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Address1'
          Width = 147
          Position.BandIndex = 1
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object tvGuestsAddress2: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Address2'
          Width = 147
          Position.BandIndex = 1
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object tvGuestsAddress3: TcxGridDBBandedColumn
          Caption = 'Zip code'
          DataBinding.FieldName = 'Address3'
          Width = 93
          Position.BandIndex = 1
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object tvGuestsAddress4: TcxGridDBBandedColumn
          Caption = 'City'
          DataBinding.FieldName = 'Address4'
          Width = 94
          Position.BandIndex = 1
          Position.ColIndex = 3
          Position.RowIndex = 0
        end
        object tvGuestsState: TcxGridDBBandedColumn
          DataBinding.FieldName = 'State'
          Width = 84
          Position.BandIndex = 1
          Position.ColIndex = 4
          Position.RowIndex = 0
        end
        object tvGuestsCountry: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Country'
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.CharCase = ecUpperCase
          Properties.OnButtonClick = tvGuestsCountryPropertiesButtonClick
          Properties.OnValidate = tvGuestsCountryPropertiesValidate
          Width = 74
          Position.BandIndex = 1
          Position.ColIndex = 5
          Position.RowIndex = 0
        end
        object tvGuestsNationality: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Nationality'
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.CharCase = ecUpperCase
          Properties.OnButtonClick = tvGuestsNationalityPropertiesButtonClick
          Properties.OnValidate = tvGuestsNationalityPropertiesValidate
          Width = 67
          Position.BandIndex = 1
          Position.ColIndex = 6
          Position.RowIndex = 0
        end
        object tvGuestsCustomer: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Customer'
          Options.Editing = False
          Width = 80
          Position.BandIndex = 3
          Position.ColIndex = 7
          Position.RowIndex = 0
        end
        object tvGuestsPID: TcxGridDBBandedColumn
          DataBinding.FieldName = 'PID'
          Options.Editing = False
          Width = 65
          Position.BandIndex = 3
          Position.ColIndex = 6
          Position.RowIndex = 0
        end
        object tvGuestsDateOfBirth: TcxGridDBBandedColumn
          Caption = 'Date of Birth'
          DataBinding.FieldName = 'DateOfBirth'
          Width = 65
          Position.BandIndex = 3
          Position.ColIndex = 4
          Position.RowIndex = 0
        end
        object tvGuestsPersonalIdentificationId: TcxGridDBBandedColumn
          Caption = 'Personal ID number'
          DataBinding.FieldName = 'PersonalIdentificationId'
          Width = 65
          Position.BandIndex = 3
          Position.ColIndex = 5
          Position.RowIndex = 0
        end
        object tvGuestsSocialSecurityNumber: TcxGridDBBandedColumn
          Caption = 'Social Security Number'
          DataBinding.FieldName = 'SocialSecurityNumber'
          Width = 65
          Position.BandIndex = 3
          Position.ColIndex = 3
          Position.RowIndex = 0
        end
        object tvGuestsId: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Id'
          Visible = False
          Options.Editing = False
          Position.BandIndex = 3
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object tvGuestsPerson: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Person'
          Visible = False
          Options.Editing = False
          Position.BandIndex = 3
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object tvGuestsPersonsProfilesId: TcxGridDBBandedColumn
          DataBinding.FieldName = 'PersonsProfilesId'
          Visible = False
          Options.Editing = False
          Position.BandIndex = 3
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object tvGuestsRecId: TcxGridDBBandedColumn
          DataBinding.FieldName = 'RecId'
          Visible = False
          Position.BandIndex = 0
          Position.ColIndex = 4
          Position.RowIndex = 0
        end
      end
      inherited lvData: TcxGridLevel
        object lvGuests: TcxGridLevel
          GridView = tvGuests
          Options.DetailFrameColor = clCream
        end
      end
    end
    object pnlNotes: TsPanel
      Left = 1
      Top = 336
      Width = 1119
      Height = 100
      Align = alBottom
      TabOrder = 1
      object lblReservationNotes: TsLabel
        Left = 5
        Top = 4
        Width = 93
        Height = 13
        Caption = 'Reservation Notes:'
      end
      object lblRoomNotes: TsLabel
        Left = 507
        Top = 4
        Width = 62
        Height = 13
        Caption = 'Room Notes:'
      end
      object memReservationPMInfo: TsMemo
        AlignWithMargins = True
        Left = 255
        Top = 21
        Width = 245
        Height = 75
        Margins.Top = 20
        Align = alLeft
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
      end
      object memRoomNotes: TDBMemo
        AlignWithMargins = True
        Left = 506
        Top = 21
        Width = 609
        Height = 75
        Margins.Top = 20
        Align = alClient
        Color = clWhite
        DataField = 'RoomNotes'
        DataSource = dsData
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object memReservationInformation: TsMemo
        AlignWithMargins = True
        Left = 4
        Top = 21
        Width = 245
        Height = 75
        Margins.Top = 20
        Align = alLeft
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
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = chkCompactView
        Properties.Strings = (
          'Checked')
      end>
    Left = 248
    Top = 56
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 248
    Top = 8
    PixelsPerInch = 96
    inherited cxstContent: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clInfoBk
    end
    object cxMasterBackground: TcxStyle [26]
      AssignedValues = [svColor]
      Color = clSkyBlue
    end
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet
      BuiltIn = True
    end
  end
  inherited dsData: TDataSource
    DataSet = mRooms
    Left = 80
    Top = 328
  end
  inherited alGridActions: TActionList
    Left = 184
    Top = 208
  end
  inherited grPrinter: TdxComponentPrinter
    Left = 264
    Top = 208
    inherited prLink_grData: TdxGridReportLink
      ReportDocument.CreationDate = 43112.424664120370000000
      AssignedFormatValues = []
      BuiltInReportLink = True
    end
  end
  object dsGuests: TDataSource
    DataSet = mGuests
    Left = 192
    Top = 328
  end
  object pmnuOther: TPopupMenu
    Images = DImages.PngImageList1
    Left = 760
    Top = 200
    object mnuiPrint: TMenuItem
      Action = acPrint
    end
    object N2: TMenuItem
      Caption = '-'
    end
  end
  object mGuests: TdxMemData
    Indexes = <>
    SortOptions = []
    SortedField = 'RoomReservation'
    AfterPost = mGuestsAfterPost
    Left = 192
    Top = 376
    object mGuestsId: TIntegerField
      FieldName = 'Id'
    end
    object mGuestsPerson: TIntegerField
      FieldName = 'Person'
    end
    object mGuestsReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mGuestsRoomReservation: TIntegerField
      FieldName = 'RoomReservation'
    end
    object mGuestsPersonsProfilesId: TIntegerField
      FieldName = 'PersonsProfilesId'
    end
    object mGueststitle: TWideStringField
      FieldName = 'title'
      Size = 10
    end
    object mGuestsName: TWideStringField
      FieldName = 'Name'
      Size = 100
    end
    object mGuestsAddress1: TWideStringField
      FieldName = 'Address1'
      Size = 100
    end
    object mGuestsAddress2: TWideStringField
      FieldName = 'Address2'
    end
    object mGuestsAddress3: TWideStringField
      FieldName = 'Address3'
      Size = 100
    end
    object mGuestsAddress4: TWideStringField
      FieldName = 'Address4'
      Size = 100
    end
    object mGuestsCountry: TWideStringField
      FieldName = 'Country'
      Size = 2
    end
    object mGueststel1: TWideStringField
      FieldName = 'tel1'
      Size = 40
    end
    object mGueststel2: TWideStringField
      FieldName = 'tel2'
      Size = 40
    end
    object mGuestsFax: TWideStringField
      DisplayWidth = 40
      FieldName = 'Fax'
      Size = 31
    end
    object mGuestsEmail: TWideStringField
      FieldName = 'Email'
      Size = 100
    end
    object mGuestsNationality: TWideStringField
      FieldName = 'Nationality'
      Size = 2
    end
    object mGuestsPID: TWideStringField
      FieldName = 'PID'
      Size = 30
    end
    object mGuestsMainName: TBooleanField
      FieldName = 'MainName'
    end
    object mGuestsCustomer: TWideStringField
      FieldName = 'Customer'
      Size = 15
    end
    object mGuestsState: TWideStringField
      FieldName = 'State'
      Size = 10
    end
    object mGuestsPersonalIdentificationId: TWideStringField
      FieldName = 'PersonalIdentificationId'
      Size = 50
    end
    object mGuestsDateOfBirth: TDateTimeField
      FieldName = 'DateOfBirth'
    end
    object mGuestsSocialSecurityNumber: TWideStringField
      FieldName = 'SocialSecurityNumber'
      Size = 45
    end
    object mGuestsCompanyName: TStringField
      FieldName = 'CompanyName'
      Size = 100
    end
    object mGuestsCompVATNumber: TWideStringField
      FieldName = 'CompVATNumber'
      Size = 45
    end
    object mGuestsCompAddress1: TStringField
      FieldName = 'CompAddress1'
      Size = 100
    end
    object mGuestsCompAddress2: TWideStringField
      FieldName = 'CompAddress2'
      Size = 100
    end
    object mGuestsCompZip: TWideStringField
      FieldName = 'CompZip'
      Size = 100
    end
    object mGuestsCompCity: TWideStringField
      FieldName = 'CompCity'
      Size = 100
    end
    object mGuestsCompCountry: TWideStringField
      FieldName = 'CompCountry'
      Size = 2
    end
    object mGuestsCompTel: TWideStringField
      FieldName = 'CompTel'
      Size = 40
    end
    object mGuestsCompFax: TWideStringField
      FieldName = 'CompFax'
      Size = 40
    end
    object mGuestsCompEmail: TWideStringField
      FieldName = 'CompEmail'
      Size = 255
    end
  end
  object mCompare: TdxMemData
    Indexes = <>
    SortOptions = []
    SortedField = 'RoomReservation'
    Left = 192
    Top = 424
    object mCompareId: TIntegerField
      FieldName = 'Id'
    end
    object mComparePerson: TIntegerField
      FieldName = 'Person'
    end
    object mCompareReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mCompareRoomReservation: TIntegerField
      FieldName = 'RoomReservation'
    end
    object mComparePersonsProfilesId: TIntegerField
      FieldName = 'PersonsProfilesId'
    end
    object mComparetitle: TWideStringField
      FieldName = 'title'
      Size = 10
    end
    object mCompareName: TWideStringField
      FieldName = 'Name'
      Size = 100
    end
    object mCompareAddress1: TWideStringField
      FieldName = 'Address1'
      Size = 100
    end
    object mCompareAddress2: TWideStringField
      FieldName = 'Address2'
    end
    object mCompareAddress3: TWideStringField
      FieldName = 'Address3'
      Size = 100
    end
    object mCompareAddress4: TWideStringField
      FieldName = 'Address4'
      Size = 100
    end
    object mCompareCountry: TWideStringField
      FieldName = 'Country'
      Size = 2
    end
    object mComparetel1: TWideStringField
      FieldName = 'tel1'
      Size = 40
    end
    object mComparetel2: TWideStringField
      FieldName = 'tel2'
      Size = 40
    end
    object mCompareFax: TWideStringField
      DisplayWidth = 40
      FieldName = 'Fax'
      Size = 31
    end
    object mCompareEmail: TWideStringField
      FieldName = 'Email'
      Size = 100
    end
    object mCompareNationality: TWideStringField
      FieldName = 'Nationality'
      Size = 2
    end
    object mComparePID: TWideStringField
      FieldName = 'PID'
      Size = 30
    end
    object mCompareMainName: TBooleanField
      FieldName = 'MainName'
    end
    object mCompareCustomer: TWideStringField
      FieldName = 'Customer'
      Size = 15
    end
    object mCompareState: TWideStringField
      FieldName = 'State'
      Size = 10
    end
    object mComparePersonalIdentificationId: TWideStringField
      FieldName = 'PersonalIdentificationId'
      Size = 50
    end
    object mCompareDateOfBirth: TDateTimeField
      FieldName = 'DateOfBirth'
    end
    object mCompareSocialSecurityNumber: TWideStringField
      FieldName = 'SocialSecurityNumber'
      Size = 45
    end
    object mCompareCompanyName: TStringField
      FieldName = 'CompanyName'
      Size = 100
    end
    object mCompareCompVATNumber: TWideStringField
      FieldName = 'CompVATNumber'
      Size = 45
    end
    object mCompareCompAddress1: TStringField
      FieldName = 'CompAddress1'
      Size = 100
    end
    object mCompareCompAddress2: TWideStringField
      FieldName = 'CompAddress2'
      Size = 100
    end
    object mCompareCompZip: TWideStringField
      FieldName = 'CompZip'
      Size = 100
    end
    object mCompareCompCity: TWideStringField
      FieldName = 'CompCity'
      Size = 100
    end
    object mCompareCompCountry: TWideStringField
      FieldName = 'CompCountry'
      Size = 2
    end
    object mCompareCompTel: TWideStringField
      FieldName = 'CompTel'
      Size = 40
    end
    object mCompareCompFax: TWideStringField
      FieldName = 'CompFax'
      Size = 40
    end
    object mCompareCompEmail: TWideStringField
      FieldName = 'CompEmail'
      Size = 255
    end
  end
  object mRooms: TdxMemData
    Indexes = <>
    SortOptions = []
    SortedField = 'Room'
    BeforePost = mRoomsBeforePost
    Left = 80
    Top = 376
    object mRoomsReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mRoomsRoomReservation: TIntegerField
      FieldName = 'RoomReservation'
    end
    object mRoomsRoom: TWideStringField
      FieldName = 'Room'
      Size = 8
    end
    object mRoomsRoomtype: TWideStringField
      FieldName = 'RoomType'
      Size = 10
    end
    object mRomsBreakfast: TBooleanField
      FieldName = 'Breakfast'
    end
    object mRoomsArrival: TDateTimeField
      FieldName = 'Arrival'
    end
    object mRoomsDeparture: TDateTimeField
      FieldName = 'Departure'
    end
    object mRoomsNumGuests: TIntegerField
      FieldName = 'numGuests'
    end
    object mRoomsStatus: TWideStringField
      FieldName = 'status'
      Size = 45
    end
    object mRoomsRoomDescription: TWideStringField
      FieldName = 'RoomDescription'
    end
    object mRoomsRoomDetails: TWideStringField
      FieldName = 'roomDetails'
      Size = 200
    end
    object mRoomsRoomNotes: TWideMemoField
      FieldName = 'RoomNotes'
      BlobType = ftWideMemo
    end
  end
  object mRoomsCompare: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 80
    Top = 424
    object mRoomsCompareReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object IntegerField7: TIntegerField
      FieldName = 'RoomReservation'
    end
    object WideStringField31: TWideStringField
      FieldName = 'Room'
      Size = 8
    end
    object WideStringField32: TWideStringField
      FieldName = 'RoomType'
      Size = 10
    end
    object BooleanField3: TBooleanField
      FieldName = 'Breakfast'
    end
    object DateTimeField4: TDateTimeField
      FieldName = 'Arrival'
    end
    object DateTimeField5: TDateTimeField
      FieldName = 'Departure'
    end
    object IntegerField8: TIntegerField
      FieldName = 'numGuests'
    end
    object WideStringField33: TWideStringField
      FieldName = 'status'
      Size = 45
    end
    object WideStringField34: TWideStringField
      FieldName = 'RoomDescription'
    end
    object WideStringField35: TWideStringField
      FieldName = 'roomDetails'
      Size = 200
    end
    object mRoomsCompareRoomNotes: TWideMemoField
      FieldName = 'RoomNotes'
      BlobType = ftWideMemo
    end
  end
end
