object cxSchedulerEventEditorForm: TcxSchedulerEventEditorForm
  Left = 313
  Top = 267
  AutoScroll = False
  ClientHeight = 415
  ClientWidth = 450
  Color = clBtnFace
  Constraints.MinHeight = 410
  Constraints.MinWidth = 458
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnCloseQuery = FormCloseQuery
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object pnlButtons: TPanel
    Left = 0
    Top = 377
    Width = 450
    Height = 38
    Align = alBottom
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 0
    object pnlThreeButtons: TPanel
      Left = 0
      Top = 0
      Width = 340
      Height = 38
      Align = alClient
      BevelOuter = bvNone
      FullRepaint = False
      ParentColor = True
      TabOrder = 0
      object btnOk: TcxButton
        Left = 15
        Top = 7
        Width = 95
        Height = 23
        Anchors = [akTop, akRight]
        Caption = 'OK'
        Default = True
        ModalResult = 1
        TabOrder = 0
      end
      object btnCancel: TcxButton
        Left = 125
        Top = 7
        Width = 95
        Height = 23
        Anchors = [akTop, akRight]
        Caption = 'Cancel'
        ModalResult = 2
        TabOrder = 1
      end
      object btnDelete: TcxButton
        Left = 235
        Top = 7
        Width = 95
        Height = 23
        Anchors = [akTop, akRight]
        Caption = '&Delete'
        TabOrder = 2
        OnClick = btnDeleteClick
      end
    end
    object pnlRecurrence: TPanel
      Left = 340
      Top = 0
      Width = 110
      Height = 38
      Align = alRight
      BevelOuter = bvNone
      FullRepaint = False
      ParentColor = True
      TabOrder = 1
      object btnRecurrence: TcxButton
        Left = 5
        Top = 7
        Width = 95
        Height = 23
        Caption = '&Recurrence'
        TabOrder = 0
        OnClick = btnRecurrenceClick
      end
    end
  end
  object pnlInformation: TPanel
    Left = 0
    Top = 0
    Width = 450
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 8
    object Bevel6: TdxBevel
      Left = 11
      Top = 33
      Width = 429
      Height = 7
      Anchors = [akLeft, akTop, akRight]
      Shape = dxbsLineCenteredVert
    end
    object btnFindTime: TcxButton
      Left = 320
      Top = 8
      Width = 120
      Height = 23
      Anchors = [akTop, akRight]
      Caption = 'Find available time'
      TabOrder = 0
      OnClick = btnFindTimeClick
    end
    object cxGroupBox1: TcxGroupBox
      Left = 13
      Top = 8
      Alignment = alCenterCenter
      Anchors = [akLeft, akTop, akRight]
      ParentBackground = False
      ParentColor = False
      Style.Color = clInfoBk
      Style.TransparentBorder = False
      TabOrder = 1
      Height = 23
      Width = 298
      object lbInformation: TcxLabel
        Left = 4
        Top = 4
        AutoSize = False
        Caption = 'Conflicts with another event in your schedule.'
        Style.TransparentBorder = False
        Transparent = True
        Height = 15
        Width = 290
      end
    end
  end
  object pnlCaption: TPanel
    Left = 0
    Top = 41
    Width = 450
    Height = 58
    Align = alTop
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 1
    object lbSubject: TcxLabel
      Left = 16
      Top = 10
      Caption = 'Subject:'
      FocusControl = teSubject
      Style.TransparentBorder = False
      Transparent = True
    end
    object lbLocation: TcxLabel
      Left = 16
      Top = 35
      Caption = 'Location:'
      FocusControl = teLocation
      Style.TransparentBorder = False
      Transparent = True
    end
    object lbLabel: TcxLabel
      Left = 239
      Top = 35
      Anchors = [akTop, akRight]
      Caption = 'La&bel:'
      FocusControl = icbLabel
      Style.TransparentBorder = False
      Transparent = True
    end
    object teSubject: TcxTextEdit
      Left = 72
      Top = 6
      Anchors = [akLeft, akTop, akRight]
      Properties.OnChange = OnChanged
      TabOrder = 0
      Width = 369
    end
    object teLocation: TcxTextEdit
      Left = 72
      Top = 31
      Anchors = [akLeft, akTop, akRight]
      Properties.OnChange = OnChanged
      TabOrder = 1
      Width = 145
    end
    object icbLabel: TcxImageComboBox
      Left = 272
      Top = 31
      Anchors = [akTop, akRight]
      Properties.Items = <>
      Properties.OnChange = OnChanged
      TabOrder = 2
      Width = 169
    end
  end
  object pnlTime: TPanel
    Left = 0
    Top = 99
    Width = 450
    Height = 62
    Align = alTop
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 2
    object Bevel4: TdxBevel
      Left = 10
      Top = 0
      Width = 429
      Height = 8
      Anchors = [akLeft, akTop, akRight]
      Shape = dxbsLineCenteredVert
    end
    object lbStartTime: TcxLabel
      Left = 16
      Top = 15
      Caption = 'Start time:'
      FocusControl = deStart
      Style.TransparentBorder = False
      Transparent = True
    end
    object lbEndTime: TcxLabel
      Left = 16
      Top = 40
      Caption = 'End time:'
      FocusControl = deEnd
      Style.TransparentBorder = False
      Transparent = True
    end
    object deStart: TcxDateEdit
      Left = 96
      Top = 11
      Properties.DateButtons = [btnToday]
      Properties.InputKind = ikStandard
      Properties.OnChange = OnChanged
      Properties.OnEditValueChanged = StartDateChanged
      TabOrder = 0
      Width = 121
    end
    object teStart: TcxTimeEdit
      Left = 224
      Top = 11
      EditValue = 0.000000000000000000
      Properties.TimeFormat = tfHourMin
      Properties.OnChange = OnEventTimeChanged
      TabOrder = 1
      Width = 78
    end
    object deEnd: TcxDateEdit
      Left = 96
      Top = 36
      Properties.DateButtons = [btnToday]
      Properties.InputKind = ikStandard
      Properties.OnChange = OnChanged
      TabOrder = 2
      Width = 121
    end
    object teEnd: TcxTimeEdit
      Left = 224
      Top = 36
      EditValue = 0.000000000000000000
      Properties.TimeFormat = tfHourMin
      Properties.OnChange = OnEventTimeChanged
      TabOrder = 3
      Width = 78
    end
    object cbAllDayEvent: TcxCheckBox
      Left = 320
      Top = 12
      Caption = 'All day event'
      Properties.OnChange = cbAllDayEventPropertiesChange
      TabOrder = 4
      Transparent = True
      Width = 121
    end
  end
  object pnlRecurrenceInfo: TPanel
    Left = 0
    Top = 201
    Width = 450
    Height = 40
    Align = alTop
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 4
    object Bevel7: TdxBevel
      Left = 11
      Top = 0
      Width = 429
      Height = 8
      Anchors = [akLeft, akTop, akRight]
      Shape = dxbsLineCenteredVert
    end
    object lbRecurrence: TcxLabel
      Left = 16
      Top = 15
      Caption = 'Recurrence:'
      Style.TransparentBorder = False
      Transparent = True
    end
    object lbRecurrencePattern: TcxLabel
      Left = 88
      Top = 16
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'PatternInfo'
      Style.TransparentBorder = False
      Properties.WordWrap = True
      Transparent = True
      Height = 13
      Width = 353
    end
  end
  object pnlPlaceHolder: TPanel
    Left = 0
    Top = 284
    Width = 450
    Height = 43
    Align = alTop
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 6
    object pnlReminder: TPanel
      Left = 0
      Top = 4
      Width = 224
      Height = 39
      Align = alLeft
      BevelOuter = bvNone
      FullRepaint = False
      ParentColor = True
      TabOrder = 0
      object cbReminder: TcxCheckBox
        Left = 11
        Top = 9
        Caption = 'Reminder:'
        Properties.OnChange = OnChanged
        State = cbsChecked
        TabOrder = 0
        Transparent = True
        OnClick = cbReminderClick
        Width = 81
      end
      object cbReminderMinutesBeforeStart: TcxComboBox
        Left = 96
        Top = 8
        Properties.ImmediateDropDown = False
        Properties.ImmediatePost = True
        Properties.IncrementalSearch = False
        Properties.OnChange = OnChanged
        Properties.OnPopup = cbReminderMinutesBeforeStartPropertiesPopup
        Properties.OnValidate = cbReminderMinutesBeforeStartPropertiesValidate
        TabOrder = 1
        Width = 121
      end
    end
    object Panel1: TPanel
      Left = 0
      Top = 0
      Width = 450
      Height = 4
      Align = alTop
      BevelOuter = bvNone
      FullRepaint = False
      ParentColor = True
      TabOrder = 1
      object Bevel3: TdxBevel
        Left = 11
        Top = 0
        Width = 439
        Height = 4
        Anchors = [akLeft, akTop, akRight]
        Shape = dxbsLineCenteredVert
      end
    end
    object pnlShowTimeAs: TPanel
      Left = 224
      Top = 4
      Width = 281
      Height = 39
      Align = alLeft
      BevelOuter = bvNone
      FullRepaint = False
      ParentColor = True
      TabOrder = 2
      object lbShowTimeAs: TcxLabel
        Left = 16
        Top = 12
        Caption = 'Show time as:'
        FocusControl = icbShowTimeAs
        Style.TransparentBorder = False
        Transparent = True
      end
      object icbShowTimeAs: TcxImageComboBox
        Left = 96
        Top = 8
        Properties.Items = <>
        Properties.OnChange = OnEventTimeChanged
        TabOrder = 0
        Width = 121
      end
    end
  end
  object pnlMessage: TPanel
    Left = 0
    Top = 327
    Width = 450
    Height = 50
    Align = alClient
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 7
    object Bevel2: TdxBevel
      Left = 11
      Top = 0
      Width = 429
      Height = 9
      Anchors = [akLeft, akTop, akRight]
      Shape = dxbsLineCenteredVert
    end
    object Bevel1: TdxBevel
      Left = 11
      Top = 42
      Width = 429
      Height = 7
      Anchors = [akLeft, akRight, akBottom]
      Shape = dxbsLineCenteredVert
    end
    object meMessage: TcxMemo
      Left = 10
      Top = 12
      Anchors = [akLeft, akTop, akRight, akBottom]
      Properties.OnChange = OnChanged
      TabOrder = 0
      Height = 12
      Width = 431
    end
  end
  object pnlResource: TPanel
    Left = 0
    Top = 241
    Width = 450
    Height = 43
    Align = alTop
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 5
    object Bevel5: TdxBevel
      Left = 11
      Top = -4
      Width = 429
      Height = 7
      Anchors = [akLeft, akTop, akRight]
      Shape = dxbsLineCenteredVert
    end
    object lbResource: TcxLabel
      Left = 16
      Top = 17
      Caption = 'Resource(s):'
      Style.TransparentBorder = False
      Transparent = True
    end
    object cbResources: TcxCheckComboBox
      Left = 96
      Top = 13
      Anchors = [akLeft, akTop, akRight]
      Properties.DropDownAutoWidth = False
      Properties.EditValueFormat = cvfIndices
      Properties.Items = <>
      Properties.OnChange = OnResourceIDChanged
      Properties.OnClickCheck = cbResourcesPropertiesClickCheck
      TabOrder = 0
      Width = 346
    end
  end
  object pnlTaskComplete: TPanel
    Left = 0
    Top = 161
    Width = 450
    Height = 40
    Align = alTop
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 3
    object Bevel8: TdxBevel
      Left = 11
      Top = 0
      Width = 429
      Height = 8
      Anchors = [akLeft, akTop, akRight]
      Shape = dxbsLineCenteredVert
    end
    object lbTaskComplete: TcxLabel
      Left = 16
      Top = 18
      Caption = 'Task complete:'
      FocusControl = seTaskComplete
      Style.TransparentBorder = False
      Transparent = True
    end
    object lbTaskStatus: TcxLabel
      Left = 240
      Top = 18
      Caption = 'Task status:'
      FocusControl = cbxTaskStatus
      Style.TransparentBorder = False
      Transparent = True
    end
    object seTaskComplete: TcxSpinEdit
      Left = 96
      Top = 14
      Properties.AssignedValues.EditFormat = True
      Properties.AssignedValues.MinValue = True
      Properties.Increment = 25.000000000000000000
      Properties.LargeIncrement = 25.000000000000000000
      Properties.MaxValue = 100.000000000000000000
      Properties.OnChange = seTaskCompleteChange
      Properties.OnEditValueChanged = seTaskCompleteChange
      TabOrder = 0
      Width = 121
    end
    object cbxTaskStatus: TcxComboBox
      Left = 320
      Top = 14
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = cbxTaskStatusChange
      Properties.OnEditValueChanged = cbxTaskStatusChange
      TabOrder = 1
      Width = 121
    end
  end
end
