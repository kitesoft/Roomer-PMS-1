inherited frmChangeRRdates: TfrmChangeRRdates
  Left = 1072
  Top = 281
  Caption = 'Change room reservation dates'
  ClientHeight = 382
  ClientWidth = 623
  OnCreate = FormCreate
  OnShow = FormShow
  ExplicitWidth = 629
  ExplicitHeight = 411
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 362
    Width = 623
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ExplicitTop = 362
    ExplicitWidth = 623
  end
  inherited pnlButtons: TsPanel
    Top = 319
    Width = 623
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 3
    ExplicitTop = 319
    ExplicitWidth = 623
    inherited btnOK: TsButton
      Left = 412
      Top = 5
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Visible = False
      ExplicitLeft = 412
      ExplicitTop = 3
      ExplicitHeight = 33
    end
    inherited btnCancel: TsButton
      Left = 519
      Caption = 'Close'
      ExplicitLeft = 519
    end
  end
  object sPanel1: TsPanel [2]
    Left = 0
    Top = 165
    Width = 623
    Height = 154
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object gbrNextRR: TsGroupBox
      AlignWithMargins = True
      Left = 308
      Top = 5
      Width = 310
      Height = 144
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alClient
      Caption = 'Next Reservation'
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      object labNextName: TsLabel
        Left = 8
        Top = 20
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labNextGuest: TsLabel
        Left = 8
        Top = 39
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LMDSimpleLabel3: TsLabel
        Left = 75
        Top = 60
        Width = 38
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Arrival :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LMDSimpleLabel4: TsLabel
        Left = 57
        Top = 82
        Width = 56
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Departure :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LMDSimpleLabel5: TsLabel
        Left = 75
        Top = 100
        Width = 38
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Status :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labNextArrival: TsLabel
        Left = 122
        Top = 60
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labNextDeparture: TsLabel
        Left = 122
        Top = 82
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labNextStatus: TsLabel
        Left = 122
        Top = 100
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labNextDays: TsLabel
        Left = 187
        Top = 60
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
    end
    object gbrLastRR: TsGroupBox
      AlignWithMargins = True
      Left = 5
      Top = 5
      Width = 295
      Height = 144
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alLeft
      Caption = 'Previous reservation'
      TabOrder = 1
      SkinData.SkinSection = 'GROUPBOX'
      object labLastName: TsLabel
        Left = 8
        Top = 20
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labLastGuest: TsLabel
        Left = 8
        Top = 35
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LMDSimpleLabel6: TsLabel
        Left = 75
        Top = 60
        Width = 38
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Arrival :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LMDSimpleLabel7: TsLabel
        Left = 57
        Top = 82
        Width = 56
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Departure :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LMDSimpleLabel8: TsLabel
        Left = 75
        Top = 100
        Width = 38
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Status :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LabLastArrival: TsLabel
        Left = 122
        Top = 60
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labLastDeparture: TsLabel
        Left = 122
        Top = 82
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labLastStatus: TsLabel
        Left = 122
        Top = 100
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labLastDays: TsLabel
        Left = 187
        Top = 60
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
      end
    end
  end
  object LMDSimplePanel1: TsPanel [3]
    Left = 0
    Top = 0
    Width = 623
    Height = 165
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object gbxReservationsDates: TsGroupBox
      AlignWithMargins = True
      Left = 5
      Top = 5
      Width = 295
      Height = 155
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alLeft
      Caption = 'Change dates'
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      DesignSize = (
        295
        155)
      object labArrival: TsLabel
        Left = 64
        Top = 25
        Width = 38
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Arrival :'
      end
      object labDeparture: TsLabel
        Left = 46
        Top = 51
        Width = 56
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Departure :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labNights: TsLabel
        Left = 65
        Top = 78
        Width = 37
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Nights :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labWeekDayFrom: TsLabel
        Left = 208
        Top = 25
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labWeekDayTo: TsLabel
        Left = 208
        Top = 51
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labErr: TsLabel
        Left = 110
        Top = 101
        Width = 3
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Color = clYellow
        ParentColor = False
        ParentFont = False
        Transparent = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object dtArrival: TsDateEdit
        Left = 108
        Top = 21
        Width = 94
        Height = 22
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
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
        OnChange = dtUpdateControls
        OnExit = dtUpdateControls
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
      object dtDeparture: TsDateEdit
        Left = 108
        Top = 48
        Width = 94
        Height = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
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
        TabOrder = 2
        Text = '  -  -    '
        OnChange = dtUpdateControls
        OnDblClick = dtDepartureDblClick
        OnExit = dtUpdateControls
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
      object edNightCount: TsSpinEdit
        Left = 108
        Top = 74
        Width = 94
        Height = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = '1'
        OnChange = dtUpdateControls
        OnExit = dtUpdateControls
        SkinData.SkinSection = 'EDIT'
        MaxValue = 1000
        MinValue = 1
        Value = 1
      end
      object btnChangeDates: TsButton
        Left = 215
        Top = 126
        Width = 76
        Height = 25
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Anchors = [akTop, akRight]
        Caption = 'Change'
        ImageIndex = 82
        Images = DImages.PngImageList1
        ModalResult = 1
        TabOrder = 3
        OnClick = btnChangeDatesClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object sGroupBox1: TsGroupBox
      AlignWithMargins = True
      Left = 308
      Top = 5
      Width = 310
      Height = 155
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alClient
      Caption = '.. or split reservation in two'
      TabOrder = 1
      SkinData.SkinSection = 'GROUPBOX'
      DesignSize = (
        310
        155)
      object Label1: TsLabel
        Left = 62
        Top = 24
        Width = 40
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'Split at :'
      end
      object sLabel1: TsLabel
        Left = 200
        Top = 24
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel2: TsLabel
        Left = 108
        Top = 45
        Width = 152
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'First date in second reservation'
      end
      object labPart1: TsLabel
        Left = 27
        Top = 71
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
      end
      object labPart2: TsLabel
        Left = 27
        Top = 92
        Width = 4
        Height = 13
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = '-'
      end
      object btnSplit: TsButton
        Left = 231
        Top = 126
        Width = 75
        Height = 25
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Anchors = [akTop, akRight]
        Caption = 'Split'
        ImageIndex = 82
        Images = DImages.PngImageList1
        ModalResult = 1
        TabOrder = 0
        OnClick = btnSplitClick
        SkinData.SkinSection = 'BUTTON'
      end
      object dtSplitAt: TsDateEdit
        Left = 108
        Top = 18
        Width = 86
        Height = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
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
        OnChange = dtUpdateControls
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 288
    Top = 24
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 336
    Top = 64
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
