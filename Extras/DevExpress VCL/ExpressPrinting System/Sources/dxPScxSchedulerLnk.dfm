object cxfmSchedulerReportLinkDesignWindow: TcxfmSchedulerReportLinkDesignWindow
  Left = 364
  Top = 183
  BorderStyle = bsDialog
  Caption = 'cxfmSchedulerReportLinkDesignWindow'
  ClientHeight = 502
  ClientWidth = 632
  Color = clBtnFace
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 608
    Height = 444
    ActivePage = tshPrintRange
    Anchors = [akLeft, akTop, akRight, akBottom]
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 443
    ClientRectLeft = 1
    ClientRectRight = 607
    ClientRectTop = 24
    object tshPrintRange: TcxTabSheet
      Caption = 'Print Range'
      ImageIndex = 3
      object lblPrintRangeStart: TLabel
        Left = 17
        Top = 20
        Width = 28
        Height = 13
        Caption = '&Start:'
        Transparent = True
      end
      object lblPrintRangeEnd: TLabel
        Left = 18
        Top = 52
        Width = 22
        Height = 13
        Caption = '&End:'
        Transparent = True
      end
      object dePrintRangeStart: TcxDateEdit
        Left = 70
        Top = 18
        EditValue = 38187d
        Properties.OnEditValueChanged = dePrintRangeStartEditValueChanged
        TabOrder = 0
        Width = 239
      end
      object dePrintRangeEnd: TcxDateEdit
        Left = 70
        Top = 48
        EditValue = 38187d
        Properties.OnEditValueChanged = dePrintRangeEndEditValueChanged
        TabOrder = 1
        Width = 239
      end
      object chbxHideDetailsOfPrivateAppointments: TcxCheckBox
        Left = 66
        Top = 105
        Caption = 'Hide Details of Private Appointments'
        TabOrder = 2
        Transparent = True
        Visible = False
        Width = 236
      end
      object lblPrintRangesMiscellaneous: TcxLabel
        Left = 10
        Top = 81
        AutoSize = False
        Caption = 'Miscellaneous'
        Properties.LineOptions.Visible = True
        Transparent = True
        Visible = False
        Height = 18
        Width = 301
      end
    end
    object tshPrintStyles: TcxTabSheet
      Caption = 'Print Styles'
      object cbxPrintStyles: TcxImageComboBox
        Left = 10
        Top = 18
        AutoSize = False
        Properties.Alignment.Vert = taVCenter
        Properties.Items = <>
        Style.TransparentBorder = False
        TabOrder = 0
        OnClick = cbxPrintStylesClick
        Height = 40
        Width = 300
      end
      object pcPrintStyleOptions: TcxPageControl
        Left = 10
        Top = 64
        Width = 300
        Height = 340
        ActivePage = tshYearly
        HideTabs = True
        ShowFrame = True
        TabOrder = 1
        ClientRectBottom = 339
        ClientRectLeft = 1
        ClientRectRight = 299
        ClientRectTop = 1
        object tshDaily: TcxTabSheet
          Caption = 'Daily'
          TabVisible = False
          object lblPrintStyleDailyLayout: TLabel
            Left = 20
            Top = 34
            Width = 37
            Height = 13
            Caption = 'La&yout:'
            FocusControl = cbxPrintStyleDailyLayout
            Transparent = True
          end
          object lblPrintStyleDailyInclude: TLabel
            Left = 20
            Top = 86
            Width = 39
            Height = 13
            Caption = 'Include:'
            Transparent = True
          end
          object lblPrintStyleDailyPrintFrom: TLabel
            Left = 20
            Top = 155
            Width = 53
            Height = 13
            Caption = 'Print &From:'
            FocusControl = tePrintStyleDailyPrintFrom
            Transparent = True
          end
          object lblPrintStyleDailyPrintTo: TLabel
            Left = 20
            Top = 183
            Width = 41
            Height = 13
            Caption = 'Print &To:'
            FocusControl = tePrintStyleDailyPrintTo
            Transparent = True
          end
          object lblPrintStyleDailyResourceCountPerPage: TLabel
            Left = 20
            Top = 59
            Width = 82
            Height = 13
            Caption = 'Resources/Page:'
            FocusControl = sePrintStyleDailyResourceCountPerPage
            Transparent = True
          end
          object cbxPrintStyleDailyLayout: TcxComboBox
            Left = 114
            Top = 29
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            Properties.Items.Strings = (
              '1 page/day'
              '2 pages/day')
            TabOrder = 0
            OnClick = cbxPrintStyleDailyLayoutClick
            Width = 173
          end
          object chbxPrintStyleDailyTaskPad: TcxCheckBox
            Left = 113
            Top = 83
            Caption = 'Task&Pad'
            TabOrder = 2
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 178
          end
          object chbxPrintStyleDailyNotesAreaBlank: TcxCheckBox
            Tag = 1
            Left = 113
            Top = 104
            Caption = 'Notes Area (&Blank)'
            TabOrder = 3
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 178
          end
          object chbxPrintStyleDailyNotesAreaLined: TcxCheckBox
            Tag = 2
            Left = 113
            Top = 125
            Caption = 'Notes Area (&Lined)'
            TabOrder = 4
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 178
          end
          object tePrintStyleDailyPrintFrom: TcxTimeEdit
            Left = 114
            Top = 152
            EditValue = 0.000000000000000000
            Properties.TimeFormat = tfHourMin
            Properties.OnChange = tePrintStylePrintRangePropertiesChange
            Properties.OnEditValueChanged = tePrintStylePrintRangePropertiesEditValueChanged
            TabOrder = 5
            Width = 100
          end
          object tePrintStyleDailyPrintTo: TcxTimeEdit
            Tag = 1
            Left = 114
            Top = 179
            EditValue = 0.000000000000000000
            Properties.ImmediatePost = True
            Properties.TimeFormat = tfHourMin
            Properties.OnChange = tePrintStylePrintRangePropertiesChange
            Properties.OnEditValueChanged = tePrintStylePrintRangePropertiesEditValueChanged
            TabOrder = 6
            Width = 100
          end
          object sePrintStyleDailyResourceCountPerPage: TcxSpinEdit
            Left = 114
            Top = 56
            Properties.AssignedValues.MinValue = True
            Properties.OnChange = sePrintStyleResourceCountPerPagePropertiesChanged
            Properties.OnEditValueChanged = sePrintStyleResourceCountPerPagePropertiesEditValueChanged
            TabOrder = 1
            Width = 100
          end
          object chbxPrintStyleDailyShowResourceImages: TcxCheckBox
            Left = 14
            Top = 224
            Caption = 'Show resource images'
            TabOrder = 7
            Transparent = True
            OnClick = chbxPrintStyleShowResourceImagesClick
            Width = 306
          end
          object chbxPrintStyleDailyShowEventImages: TcxCheckBox
            Left = 14
            Top = 269
            Caption = 'Show event images'
            TabOrder = 8
            Transparent = True
            OnClick = chbxPrintStyleShowEventImagesClick
            Width = 306
          end
          object lbViewDaily: TcxLabel
            Left = 9
            Top = 204
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'View'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object lbImagesDaily: TcxLabel
            Left = 9
            Top = 249
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Images '
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object lbOptionsDaily: TcxLabel
            Left = 9
            Top = 8
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Options'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
        end
        object tshWeekly: TcxTabSheet
          Caption = 'Weekly'
          ImageIndex = 1
          TabVisible = False
          object lblPrintStyleWeeklyPrintTo: TLabel
            Left = 20
            Top = 220
            Width = 41
            Height = 13
            Caption = 'Print &To:'
            FocusControl = tePrintStyleWeeklyPrintTo
            Transparent = True
          end
          object lblPrintStyleWeeklyPrintFrom: TLabel
            Left = 20
            Top = 193
            Width = 53
            Height = 13
            Caption = 'Print &From:'
            FocusControl = tePrintStyleWeeklyPrintFrom
            Transparent = True
          end
          object lblPrintStyleWeeklyInclude: TLabel
            Left = 20
            Top = 131
            Width = 39
            Height = 13
            Caption = 'Include:'
            Transparent = True
          end
          object lblPrintStyleWeeklyLayout: TLabel
            Left = 20
            Top = 58
            Width = 37
            Height = 13
            Caption = 'La&yout:'
            FocusControl = cbxPrintStyleWeeklyLayout
            Transparent = True
          end
          object lblPrintStyleWeeklyArrange: TLabel
            Left = 20
            Top = 33
            Width = 43
            Height = 13
            Caption = '&Arrange:'
            FocusControl = cbxPrintStyleWeeklyArrange
            Transparent = True
          end
          object lblPrintStyleWeeklyResourceCountPerPage: TLabel
            Left = 20
            Top = 107
            Width = 82
            Height = 13
            Caption = 'Resources/Page:'
            FocusControl = sePrintStyleWeeklyResourceCountPerPage
            Transparent = True
          end
          object lblPrintStyleWeeklyDaysLayout: TLabel
            Left = 20
            Top = 83
            Width = 61
            Height = 13
            Caption = '&Days layout:'
            FocusControl = cbxPrintStyleWeeklyDaysLayout
            Transparent = True
          end
          object tePrintStyleWeeklyPrintTo: TcxTimeEdit
            Tag = 1
            Left = 114
            Top = 217
            EditValue = 0.000000000000000000
            Properties.TimeFormat = tfHourMin
            Properties.OnChange = tePrintStylePrintRangePropertiesChange
            Properties.OnEditValueChanged = tePrintStylePrintRangePropertiesEditValueChanged
            TabOrder = 8
            Width = 100
          end
          object tePrintStyleWeeklyPrintFrom: TcxTimeEdit
            Left = 114
            Top = 190
            EditValue = 0.000000000000000000
            Properties.TimeFormat = tfHourMin
            Properties.OnChange = tePrintStylePrintRangePropertiesChange
            Properties.OnEditValueChanged = tePrintStylePrintRangePropertiesEditValueChanged
            TabOrder = 7
            Width = 100
          end
          object chbxPrintStyleWeeklyNotesAreaLined: TcxCheckBox
            Tag = 2
            Left = 113
            Top = 167
            Caption = 'Notes Area (&Lined)'
            TabOrder = 6
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 177
          end
          object chbxPrintStyleWeeklyNotesAreaBlank: TcxCheckBox
            Tag = 1
            Left = 113
            Top = 147
            Caption = 'Notes Area (&Blank)'
            TabOrder = 5
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 177
          end
          object cbxPrintStyleWeeklyArrange: TcxComboBox
            Left = 114
            Top = 29
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            Properties.Items.Strings = (
              'Top to Bottom'
              'Left to Right')
            TabOrder = 0
            OnClick = cbxPrintStyleWeeklyArrangeClick
            Width = 173
          end
          object cbxPrintStyleWeeklyLayout: TcxComboBox
            Left = 114
            Top = 54
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            Properties.Items.Strings = (
              '1 page/day'
              '2 pages/day')
            TabOrder = 1
            OnClick = cbxPrintStyleWeeklyLayoutClick
            Width = 173
          end
          object chbxPrintStyleWeeklyTaskPad: TcxCheckBox
            Left = 113
            Top = 127
            Caption = 'TaskPad'
            TabOrder = 4
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 177
          end
          object chbxPrintStyleWeeklyDontPrintWeekends: TcxCheckBox
            Left = 18
            Top = 254
            Caption = 'Don'#39't Print &Weekends'
            TabOrder = 9
            Transparent = True
            OnClick = chbxPrintStyleWeeklyDontPrintWeekendsClick
            Width = 266
          end
          object sePrintStyleWeeklyResourceCountPerPage: TcxSpinEdit
            Tag = 1
            Left = 114
            Top = 104
            Properties.AssignedValues.MinValue = True
            Properties.OnChange = sePrintStyleResourceCountPerPagePropertiesChanged
            Properties.OnEditValueChanged = sePrintStyleResourceCountPerPagePropertiesEditValueChanged
            TabOrder = 3
            Width = 100
          end
          object cbxPrintStyleWeeklyDaysLayout: TcxComboBox
            Left = 114
            Top = 79
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            Properties.Items.Strings = (
              'Two columns'
              'One column')
            TabOrder = 2
            OnClick = cbxPrintStyleWeeklyDaysLayoutClick
            Width = 173
          end
          object chbxPrintStyleWeeklyShowEventImages: TcxCheckBox
            Left = 18
            Top = 313
            Caption = 'Show Event Images'
            TabOrder = 11
            Transparent = True
            OnClick = chbxPrintStyleShowEventImagesClick
            Width = 264
          end
          object chbxPrintStyleWeeklyShowResourceImages: TcxCheckBox
            Left = 18
            Top = 293
            Caption = 'Show Resource Images'
            TabOrder = 10
            Transparent = True
            OnClick = chbxPrintStyleShowResourceImagesClick
            Width = 265
          end
          object Label5: TcxLabel
            Left = 9
            Top = 238
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'View'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object Label6: TcxLabel
            Left = 9
            Top = 275
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Images '
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object lbOptionsWeekly: TcxLabel
            Left = 9
            Top = 8
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Options'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
        end
        object tshMonthly: TcxTabSheet
          Caption = 'Monthly'
          ImageIndex = 2
          TabVisible = False
          object lblPrintStyleMonthlyLayout: TLabel
            Left = 20
            Top = 34
            Width = 37
            Height = 13
            Caption = 'La&yout:'
            FocusControl = cbxPrintStyleMonthlyLayout
            Transparent = True
          end
          object lblPrintStyleMonthlyInclude: TLabel
            Left = 20
            Top = 86
            Width = 39
            Height = 13
            Caption = 'Include:'
            Transparent = True
          end
          object lblPrintStyleMonthlyResourceCountPerPage: TLabel
            Left = 20
            Top = 59
            Width = 82
            Height = 13
            Caption = 'Resources/Page:'
            FocusControl = sePrintStyleMonthlyResourceCountPerPage
            Transparent = True
          end
          object cbxPrintStyleMonthlyLayout: TcxComboBox
            Left = 114
            Top = 29
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            Properties.Items.Strings = (
              '1 page/month'
              '2 pages/month')
            TabOrder = 0
            OnClick = cbxPrintStyleMonthlyLayoutClick
            Width = 173
          end
          object chbxPrintStyleMonthlyTaskPad: TcxCheckBox
            Left = 113
            Top = 83
            Caption = 'Task&Pad'
            TabOrder = 2
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 174
          end
          object chbxPrintStyleMonthlyNotesAreaBlank: TcxCheckBox
            Tag = 1
            Left = 113
            Top = 104
            Caption = 'Notes Area (&Blank)'
            TabOrder = 3
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 174
          end
          object chbxPrintStyleMonthlyNotesAreaLined: TcxCheckBox
            Tag = 2
            Left = 113
            Top = 125
            Caption = 'Notes Area (&Lined)'
            TabOrder = 4
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 174
          end
          object chbxPrintStyleMonthlyDontPrintWeekends: TcxCheckBox
            Left = 18
            Top = 166
            Caption = 'Don'#39't Print &Weekends'
            TabOrder = 5
            Transparent = True
            OnClick = chbxPrintStyleDontPrintWeekEndsClick
            Width = 267
          end
          object chbxPrintStyleMonthlyPrintExactlyOneMonthPerPage: TcxCheckBox
            Left = 18
            Top = 187
            Caption = 'Print Exactly One Month Per Page'
            TabOrder = 6
            Transparent = True
            OnClick = chbxPrintStyleMonthlyPrintExactlyOneMonthPerPageClick
            Width = 267
          end
          object sePrintStyleMonthlyResourceCountPerPage: TcxSpinEdit
            Tag = 2
            Left = 114
            Top = 56
            Properties.AssignedValues.MinValue = True
            Properties.OnChange = sePrintStyleResourceCountPerPagePropertiesChanged
            Properties.OnEditValueChanged = sePrintStyleResourceCountPerPagePropertiesEditValueChanged
            TabOrder = 1
            Width = 100
          end
          object chbxPrintStyleMonthlyShowEventImages: TcxCheckBox
            Left = 18
            Top = 250
            Caption = 'Show Event Images'
            TabOrder = 7
            Transparent = True
            OnClick = chbxPrintStyleShowEventImagesClick
            Width = 250
          end
          object chbxPrintStyleMonthlyShowResourceImages: TcxCheckBox
            Left = 18
            Top = 229
            Caption = 'Show Resource Images'
            TabOrder = 8
            Transparent = True
            OnClick = chbxPrintStyleShowResourceImagesClick
            Width = 250
          end
          object Label7: TcxLabel
            Left = 9
            Top = 147
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'View'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object Label8: TcxLabel
            Left = 9
            Top = 210
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Images '
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object lbOptionsMonthly: TcxLabel
            Left = 9
            Top = 8
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Options'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
        end
        object tshTrifold: TcxTabSheet
          Caption = 'Tri-fold'
          ImageIndex = 3
          TabVisible = False
          object lblPrintStyleTrifoldSectionLeft: TLabel
            Left = 20
            Top = 33
            Width = 61
            Height = 13
            Caption = '&Left Section:'
            FocusControl = cbxPrintStyleTrifoldSectionLeft
            Transparent = True
          end
          object lblPrintStyleTrifoldSectionMiddle: TLabel
            Left = 20
            Top = 60
            Width = 72
            Height = 13
            Caption = '&Middle Section:'
            FocusControl = cbxPrintStyleTrifoldSectionMiddle
            Transparent = True
          end
          object lblPrintStyleTrifoldSectionRight: TLabel
            Left = 20
            Top = 87
            Width = 67
            Height = 13
            Caption = '&Right Section:'
            FocusControl = cbxPrintStyleTrifoldSectionRight
            Transparent = True
          end
          object cbxPrintStyleTrifoldSectionLeft: TcxComboBox
            Left = 103
            Top = 29
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            TabOrder = 0
            OnClick = cbxPrintStyleTrifoldSectionModeClick
            Width = 184
          end
          object cbxPrintStyleTrifoldSectionMiddle: TcxComboBox
            Tag = 1
            Left = 103
            Top = 56
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            TabOrder = 1
            OnClick = cbxPrintStyleTrifoldSectionModeClick
            Width = 184
          end
          object cbxPrintStyleTrifoldSectionRight: TcxComboBox
            Tag = 2
            Left = 103
            Top = 83
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            TabOrder = 2
            OnClick = cbxPrintStyleTrifoldSectionModeClick
            Width = 184
          end
          object lbOptionsTrifold: TcxLabel
            Left = 9
            Top = 8
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Options'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
        end
        object tshDetails: TcxTabSheet
          Caption = 'Details'
          ImageIndex = 4
          TabVisible = False
          object chbxPrintStyleDetailsUsePagination: TcxCheckBox
            Left = 18
            Top = 29
            Caption = 'Start a New Page Each:'
            TabOrder = 0
            Transparent = True
            OnClick = chbxPrintStyleDetailsUsePaginationClick
            Width = 151
          end
          object cbxPrintStyleDetailsPagination: TcxComboBox
            Left = 167
            Top = 29
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            Properties.Items.Strings = (
              'Day'
              'Week'
              'Month')
            TabOrder = 1
            OnClick = cbxPrintStyleDetailsPaginationClick
            Width = 120
          end
          object lbOptionsDetails: TcxLabel
            Left = 9
            Top = 8
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Options'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
        end
        object tshMemo: TcxTabSheet
          Caption = 'Memo'
          ImageIndex = 5
          TabVisible = False
          object chbxPrintStyleMemoStartEachItemOnNewPage: TcxCheckBox
            Left = 18
            Top = 29
            Caption = 'Start Each Item On New Page'
            TabOrder = 0
            Transparent = True
            OnClick = chbxPrintStyleMemoStartEachItemOnNewPageClick
            Width = 187
          end
          object chbxPrintStyleMemoPrintOnlySelectedEvents: TcxCheckBox
            Left = 18
            Top = 51
            Caption = 'Print Only Selected Events'
            State = cbsChecked
            TabOrder = 1
            Transparent = True
            OnClick = chbxPrintStyleMemoPrintOnlySelectedEventsClick
            Width = 187
          end
          object lbOptionsMemo: TcxLabel
            Left = 9
            Top = 8
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Options'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
        end
        object tshYearly: TcxTabSheet
          Caption = 'Yearly'
          ImageIndex = 6
          TabVisible = False
          object lblPrintStyleYearlyMonthPerPage: TLabel
            Left = 20
            Top = 60
            Width = 67
            Height = 13
            Caption = '&Months/Page:'
            FocusControl = cbxPrintStyleYearlyMonthPerPage
            Transparent = True
          end
          object lblPrintStyleYearlyResourceCountPerPage: TLabel
            Left = 20
            Top = 86
            Width = 82
            Height = 13
            Caption = 'Resources/Page:'
            FocusControl = sePrintStyleYearlyResourceCountPerPage
            Transparent = True
            Visible = False
          end
          object lblPrintStyleYearlyInclude: TLabel
            Left = 20
            Top = 109
            Width = 39
            Height = 13
            Caption = 'Include:'
            Transparent = True
          end
          object lblPrintStyleYearlyLayout: TLabel
            Left = 20
            Top = 33
            Width = 37
            Height = 13
            Caption = 'La&yout:'
            FocusControl = cbxPrintStyleYearlyLayout
            Transparent = True
          end
          object cbxPrintStyleYearlyMonthPerPage: TcxComboBox
            Left = 119
            Top = 56
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            Properties.Items.Strings = (
              '1 page/year'
              '2 pages/year'
              '3 pages/year'
              '4 pages/year'
              '6 pages/year'
              '12 pages/year')
            TabOrder = 1
            Text = '12 pages/year'
            OnClick = cbxPrintStyleYearlyMonthPagesPerYearClick
            Width = 168
          end
          object sePrintStyleYearlyResourceCountPerPage: TcxSpinEdit
            Tag = 3
            Left = 119
            Top = 83
            Properties.AssignedValues.MinValue = True
            Properties.OnChange = sePrintStyleResourceCountPerPagePropertiesChanged
            Properties.OnEditValueChanged = sePrintStyleResourceCountPerPagePropertiesEditValueChanged
            TabOrder = 2
            Visible = False
            Width = 100
          end
          object chbxPrintStyleYearlyTaskPad: TcxCheckBox
            Left = 118
            Top = 109
            Caption = 'Task&Pad'
            TabOrder = 3
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 173
          end
          object chbxPrintStyleYearlyNotesAreaBlank: TcxCheckBox
            Tag = 1
            Left = 118
            Top = 130
            Caption = 'Notes Area (&Blank)'
            TabOrder = 4
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 173
          end
          object chbxPrintStyleYearlyNotesAreaLined: TcxCheckBox
            Tag = 2
            Left = 118
            Top = 151
            Caption = 'Notes Area (&Lined)'
            TabOrder = 5
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 173
          end
          object cbxPrintStyleYearlyLayout: TcxComboBox
            Left = 119
            Top = 29
            Anchors = [akLeft, akTop, akRight]
            Properties.DropDownListStyle = lsFixedList
            Properties.ItemHeight = 15
            Properties.Items.Strings = (
              '1 page/month'
              '2 pages/month')
            TabOrder = 0
            Text = '1 page/month'
            OnClick = cbxPrintStyleYearlyLayoutClick
            Width = 168
          end
          object chbxPrimaryPageHeadersOnly: TcxCheckBox
            Left = 18
            Top = 192
            Caption = 'Primary Page Headers Only'
            TabOrder = 6
            Transparent = True
            OnClick = chbxPrimaryPageHeadersOnlyClick
            Width = 280
          end
          object chbxPrintStyleYearlyShowEventImages: TcxCheckBox
            Left = 18
            Top = 233
            Caption = 'Show Event Images'
            TabOrder = 7
            Transparent = True
            OnClick = chbxPrintStyleShowEventImagesClick
            Width = 280
          end
          object Label9: TcxLabel
            Left = 9
            Top = 173
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'View'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object Label10: TcxLabel
            Left = 9
            Top = 214
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Images '
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object lbOptionsYear: TcxLabel
            Left = 9
            Top = 8
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Options'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
        end
        object tshTimeLine: TcxTabSheet
          Caption = 'TimeLine'
          ImageIndex = 7
          TabVisible = False
          object lblPrintStyleTimeLineResourceCountPerPage: TLabel
            Left = 20
            Top = 34
            Width = 82
            Height = 13
            Caption = 'Resources/Page:'
            FocusControl = sePrintStyleTimeLineResourceCountPerPage
            Transparent = True
          end
          object lblPrintStyleTimeLineInclude: TLabel
            Left = 20
            Top = 54
            Width = 39
            Height = 13
            Caption = 'Include:'
            Transparent = True
          end
          object lblPrintStyleTimeLinePrintFrom: TLabel
            Left = 20
            Top = 120
            Width = 53
            Height = 13
            Caption = 'Print &From:'
            FocusControl = tePrintStyleTimeLinePrintFrom
            Transparent = True
          end
          object lblPrintStyleTimeLinePrintTo: TLabel
            Left = 20
            Top = 147
            Width = 41
            Height = 13
            Caption = 'Print &To:'
            FocusControl = tePrintStyleTimeLinePrintTo
            Transparent = True
          end
          object sePrintStyleTimeLineResourceCountPerPage: TcxSpinEdit
            Tag = 4
            Left = 122
            Top = 29
            Properties.AssignedValues.MinValue = True
            Properties.OnChange = sePrintStyleResourceCountPerPagePropertiesChanged
            Properties.OnEditValueChanged = sePrintStyleResourceCountPerPagePropertiesEditValueChanged
            TabOrder = 0
            Width = 100
          end
          object chbxPrintStyleTimeLineTaskPad: TcxCheckBox
            Left = 121
            Top = 51
            Caption = 'Task&Pad'
            TabOrder = 1
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 165
          end
          object chbxPrintStyleTimeLineNotesAreaBlank: TcxCheckBox
            Tag = 1
            Left = 121
            Top = 72
            Caption = 'Notes Area (&Blank)'
            TabOrder = 2
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 165
          end
          object chbxPrintStyleTimeLineNotesAreaLined: TcxCheckBox
            Tag = 2
            Left = 121
            Top = 93
            Caption = 'Notes Area (&Lined)'
            TabOrder = 3
            Transparent = True
            OnClick = chbxPrintStyleOptionsViewClick
            Width = 165
          end
          object tePrintStyleTimeLinePrintFrom: TcxTimeEdit
            Left = 122
            Top = 117
            EditValue = 0.000000000000000000
            Properties.TimeFormat = tfHourMin
            Properties.OnChange = tePrintStylePrintRangePropertiesChange
            Properties.OnEditValueChanged = tePrintStylePrintRangePropertiesEditValueChanged
            TabOrder = 4
            Width = 100
          end
          object tePrintStyleTimeLinePrintTo: TcxTimeEdit
            Tag = 1
            Left = 122
            Top = 144
            EditValue = 0.000000000000000000
            Properties.ImmediatePost = True
            Properties.TimeFormat = tfHourMin
            Properties.OnChange = tePrintStylePrintRangePropertiesChange
            Properties.OnEditValueChanged = tePrintStylePrintRangePropertiesEditValueChanged
            TabOrder = 5
            Width = 100
          end
          object chbxPrintStyleTimeLineShowResourceImages: TcxCheckBox
            Left = 18
            Top = 290
            Caption = 'Show Resource Images'
            TabOrder = 10
            Transparent = True
            OnClick = chbxPrintStyleShowResourceImagesClick
            Width = 250
          end
          object chbxPrintStyleTimeLineShowEventImages: TcxCheckBox
            Left = 18
            Top = 311
            Caption = 'Show Event Images'
            TabOrder = 11
            Transparent = True
            OnClick = chbxPrintStyleShowEventImagesClick
            Width = 250
          end
          object chbxPrintStyleTimeLinePrimaryPageHeadersOnly: TcxCheckBox
            Left = 18
            Top = 208
            Caption = 'Primary Page Headers Only'
            TabOrder = 7
            Transparent = True
            OnClick = chbxPrimaryPageHeadersOnlyClick
            Width = 194
          end
          object chbxPrintStyleTimeLinePrimaryPageScalesOnly: TcxCheckBox
            Left = 18
            Top = 187
            Caption = 'Primary Page Scales Only'
            TabOrder = 6
            Transparent = True
            OnClick = chbxPrimaryPageScalesOnlyClick
            Width = 194
          end
          object chbxPrintStyleTimeLineDontPrintWeekends: TcxCheckBox
            Left = 18
            Top = 229
            Caption = 'Don'#39't Print &Weekends'
            TabOrder = 8
            Transparent = True
            OnClick = chbxPrintStyleDontPrintWeekEndsClick
            Width = 194
          end
          object chbxPrintStyleTimeLineWorkTimeOnly: TcxCheckBox
            Left = 18
            Top = 250
            Caption = 'W&ork Time Only'
            TabOrder = 9
            Transparent = True
            OnClick = chbxPrintStyleWorkTimeOnlyClick
            Width = 194
          end
          object Label2: TcxLabel
            Left = 9
            Top = 169
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'View'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object lbTimeLineImages: TcxLabel
            Left = 9
            Top = 271
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Images '
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
          object lbOptionsTimeLine: TcxLabel
            Left = 9
            Top = 8
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            Caption = 'Options'
            Properties.LineOptions.Visible = True
            Transparent = True
            Height = 18
            Width = 279
          end
        end
      end
      object lblPreviewWindow: TcxLabel
        Left = 320
        Top = 2
        TabStop = False
        Caption = 'Preview'
        Transparent = True
      end
      object pnlPrintStylesPreview: TcxGroupBox
        Left = 321
        Top = 19
        PanelStyle.Active = True
        ParentBackground = False
        ParentColor = False
        Style.Color = clWindow
        TabOrder = 2
        Height = 385
        Width = 271
        object pnlPrintStylesPreviewContainer: TPanel
          Left = 2
          Top = 2
          Width = 267
          Height = 381
          Align = alClient
          BevelOuter = bvNone
          Color = clWindow
          ParentBackground = False
          TabOrder = 0
          object pbxPrintStylesPreview: TPaintBox
            Left = 0
            Top = 0
            Width = 267
            Height = 381
            Align = alClient
            OnPaint = pbxPrintStylesPreviewPaint
          end
        end
      end
    end
    object tshFormatting: TcxTabSheet
      Caption = 'Formatting'
      ImageIndex = 2
      object imgLookAndFeel: TImage
        Left = 10
        Top = 31
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgRefinements: TImage
        Left = 10
        Top = 104
        Width = 48
        Height = 48
        Transparent = True
      end
      object cbxLookAndFeel: TcxComboBox
        Left = 75
        Top = 32
        AutoSize = False
        Properties.DropDownListStyle = lsFixedList
        Properties.ItemHeight = 15
        Properties.OnChange = cbxLookAndFeelPropertiesChange
        TabOrder = 0
        OnClick = LookAndFeelChange
        Height = 23
        Width = 235
      end
      object chbxSuppressBackgroundBitmaps: TcxCheckBox
        Tag = 1
        Left = 73
        Top = 101
        Caption = 'Suppress Background Textures'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsFormattingClick
        Width = 200
      end
      object chbxSuppressContentColoration: TcxCheckBox
        Tag = 2
        Left = 73
        Top = 123
        Caption = 'Suppress Content Coloration'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsFormattingClick
        Width = 200
      end
      object lblLookAndFeel: TcxLabel
        Left = 10
        Top = 11
        AutoSize = False
        Caption = 'Look and Feel'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 301
      end
      object lblRefinements: TcxLabel
        Left = 10
        Top = 84
        AutoSize = False
        Caption = 'Refinements'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 301
      end
    end
    object tshStyles: TcxTabSheet
      Caption = 'Styles'
      ImageIndex = 1
      object bvlStylesHost: TBevel
        Left = 9
        Top = 32
        Width = 223
        Height = 224
      end
      object cbxStyleSheets: TcxComboBox
        Left = 10
        Top = 318
        Properties.DropDownListStyle = lsFixedList
        Properties.ItemHeight = 20
        Properties.OnDrawItem = cbxStyleSheetsPropertiesDrawItem
        Style.TransparentBorder = False
        TabOrder = 7
        OnClick = cbxStyleSheetsClick
        OnKeyDown = cbxStyleSheetsKeyDown
        Width = 299
      end
      object chbxUseNativeStyles: TcxCheckBox
        Left = 7
        Top = 10
        AutoSize = False
        Style.TransparentBorder = False
        TabOrder = 0
        Transparent = True
        OnClick = OptionsFormattingClick
        Height = 21
        Width = 19
      end
      object lblUseNativeStyles: TcxLabel
        Left = 24
        Top = 11
        AutoSize = False
        Caption = '&Use Native Styles'
        FocusControl = chbxUseNativeStyles
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = lblUseNativeStylesClick
        Height = 18
        Width = 287
      end
      object Label1: TcxLabel
        Left = 85
        Top = 140
        Caption = '[ Styles Site ]'
        Visible = False
      end
      object lblStyleSheets: TcxLabel
        Left = 10
        Top = 294
        AutoSize = False
        Caption = 'Style Sheets'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 301
      end
      object btnStyleColor: TcxButton
        Left = 237
        Top = 62
        Width = 72
        Height = 23
        Caption = 'Co&lor...'
        TabOrder = 2
        OnClick = btnStyleColorClick
      end
      object btnStyleFont: TcxButton
        Left = 237
        Top = 33
        Width = 72
        Height = 23
        Caption = '&Font...'
        TabOrder = 1
        OnClick = btnStyleFontClick
      end
      object btnStyleBackgroundBitmap: TcxButton
        Left = 237
        Top = 91
        Width = 72
        Height = 23
        Caption = '&Bitmap...'
        TabOrder = 3
        OnClick = btnStyleBackgroundBitmapClick
      end
      object btnStyleSheetNew: TcxButton
        Left = 10
        Top = 343
        Width = 70
        Height = 23
        Caption = '&New...'
        TabOrder = 8
        OnClick = btnStyleSheetNewClick
      end
      object btnStyleSheetCopy: TcxButton
        Left = 86
        Top = 343
        Width = 70
        Height = 23
        Caption = '&Copy...'
        TabOrder = 9
        OnClick = btnStyleSheetCopyClick
      end
      object btnStyleSheetDelete: TcxButton
        Left = 162
        Top = 343
        Width = 70
        Height = 23
        Caption = '&Delete...'
        TabOrder = 10
        OnClick = btnStyleSheetDeleteClick
      end
      object btnStylesSaveAs: TcxButton
        Left = 124
        Top = 261
        Width = 107
        Height = 23
        Caption = 'Save &As...'
        TabOrder = 6
        OnClick = btnStylesSaveAsClick
      end
      object btnStyleSheetRename: TcxButton
        Left = 239
        Top = 343
        Width = 70
        Height = 23
        Caption = '&Rename...'
        TabOrder = 11
        OnClick = btnStyleSheetRenameClick
      end
      object btnStyleBackgroundBitmapClear: TcxButton
        Left = 237
        Top = 120
        Width = 72
        Height = 23
        Caption = 'Cle&ar'
        TabOrder = 4
        OnClick = btnStyleBackgroundBitmapClearClick
      end
      object btnStyleRestoreDefaults: TcxButton
        Left = 10
        Top = 261
        Width = 108
        Height = 23
        Caption = 'Rest&ore Defaults'
        TabOrder = 5
        OnClick = btnStyleRestoreDefaultsClick
      end
    end
  end
  object pnlPreview: TPanel
    Left = 334
    Top = 55
    Width = 271
    Height = 385
    BevelOuter = bvNone
    TabOrder = 1
    object gbPreview: TcxGroupBox
      Left = 0
      Top = 0
      Align = alClient
      PanelStyle.Active = True
      ParentBackground = False
      ParentColor = False
      Style.Color = clWindow
      TabOrder = 0
      Height = 385
      Width = 271
      object pbPreview: TPaintBox
        Left = 2
        Top = 2
        Width = 267
        Height = 381
        Align = alClient
        OnPaint = pbPreviewPaint
      end
    end
  end
  object pmStyles: TPopupMenu
    Images = ilStylesPopup
    OnPopup = pmStylesPopup
    Left = 46
    Top = 473
    object miStyleFont: TMenuItem
      Caption = '&Font...'
      ImageIndex = 0
      OnClick = btnStyleFontClick
    end
    object miStyleColor: TMenuItem
      Caption = '&Color...'
      OnClick = btnStyleColorClick
    end
    object miLine3: TMenuItem
      Caption = '-'
    end
    object miStyleBackgroundBitmap: TMenuItem
      Caption = '&Bitmap...'
      ImageIndex = 1
      ShortCut = 16463
      OnClick = btnStyleBackgroundBitmapClick
    end
    object miStyleBackgroundBitmapClear: TMenuItem
      Caption = 'Clear'
      ImageIndex = 3
      ShortCut = 16430
      OnClick = btnStyleBackgroundBitmapClearClick
    end
    object miLine2: TMenuItem
      Caption = '-'
    end
    object miStyleRestoreDefaults: TMenuItem
      Caption = 'Restore Defaults'
      OnClick = btnStyleRestoreDefaultsClick
    end
    object milLine: TMenuItem
      Caption = '-'
    end
    object miStylesSelectAll: TMenuItem
      Caption = 'Select A&ll'
      ShortCut = 16449
      OnClick = miStylesSelectAllClick
    end
    object miLine4: TMenuItem
      Caption = '-'
    end
    object miStylesSaveAs: TMenuItem
      Caption = 'Save &As...'
      ImageIndex = 2
      ShortCut = 16467
      OnClick = btnStylesSaveAsClick
    end
  end
  object cxEditStyleController1: TcxEditStyleController
    OnStyleChanged = StyleController1StyleChanged
    Left = 80
    Top = 464
  end
  object ilStylesPopup: TcxImageList
    FormatVersion = 1
    DesignInfo = 30408712
  end
end
