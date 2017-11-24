inherited frmEmbDateStatistics: TfrmEmbDateStatistics
  Caption = 'Statistics'
  ClientHeight = 677
  ClientWidth = 488
  Font.Height = -11
  ExplicitWidth = 504
  ExplicitHeight = 716
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 657
    Width = 488
    ExplicitTop = 657
    ExplicitWidth = 534
  end
  object pnlStatistics: TsPanel [1]
    Left = 0
    Top = 0
    Width = 488
    Height = 657
    Align = alClient
    BevelOuter = bvNone
    Color = 14540253
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 4013373
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    ExplicitWidth = 534
    object lblPropertyStatus: TsLabel
      Left = 0
      Top = 0
      Width = 488
      Height = 21
      Margins.Left = 10
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alTop
      Alignment = taCenter
      Caption = 'Hotel Property Status'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ExplicitWidth = 158
    end
    object lblDateStatistics: TsLabel
      Left = 0
      Top = 21
      Width = 488
      Height = 18
      Margins.Left = 10
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alTop
      Alignment = taCenter
      Caption = '2013-10-10 friday'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ExplicitWidth = 115
    end
    object pgrStatisticsPanelGroup: TCategoryPanelGroup
      Left = 0
      Top = 39
      Width = 488
      Height = 618
      VertScrollBar.Tracking = True
      Align = alClient
      HeaderFont.Charset = DEFAULT_CHARSET
      HeaderFont.Color = clWindowText
      HeaderFont.Height = -11
      HeaderFont.Name = 'Tahoma'
      HeaderFont.Style = []
      TabOrder = 0
      ExplicitWidth = 534
      object cpnlRoomtypes: TCategoryPanel
        Top = 438
        Height = 221
        Caption = 'Room types'
        ParentBackground = True
        ParentColor = True
        TabOrder = 0
        ExplicitTop = 473
        object grdRoomStates: TAdvStringGrid
          Left = 0
          Top = 0
          Width = 467
          Height = 195
          Cursor = crDefault
          Margins.Left = 10
          Margins.Top = 0
          Margins.Right = 0
          Margins.Bottom = 0
          Align = alTop
          BevelEdges = []
          BevelInner = bvNone
          BevelOuter = bvNone
          BorderStyle = bsNone
          ColCount = 3
          Ctl3D = False
          DefaultColWidth = 70
          DefaultRowHeight = 19
          DrawingStyle = gdsClassic
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentCtl3D = False
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          ActiveRowColor = 15790320
          HoverRowCells = [hcNormal, hcSelected]
          OnGetAlignment = grdGetAlignment
          OnResize = grdResize
          ActiveCellFont.Charset = DEFAULT_CHARSET
          ActiveCellFont.Color = clWindowText
          ActiveCellFont.Height = -13
          ActiveCellFont.Name = 'Tahoma'
          ActiveCellFont.Style = [fsBold]
          AutoSize = True
          ControlLook.FixedGradientFrom = clInactiveCaptionText
          ControlLook.FixedGradientTo = clWhite
          ControlLook.FixedGradientHoverFrom = clGray
          ControlLook.FixedGradientHoverTo = clWhite
          ControlLook.FixedGradientDownFrom = clGray
          ControlLook.FixedGradientDownTo = clSilver
          ControlLook.ControlStyle = csWinXP
          ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
          ControlLook.DropDownHeader.Font.Color = clWindowText
          ControlLook.DropDownHeader.Font.Height = -13
          ControlLook.DropDownHeader.Font.Name = 'Tahoma'
          ControlLook.DropDownHeader.Font.Style = []
          ControlLook.DropDownHeader.Visible = True
          ControlLook.DropDownHeader.Buttons = <>
          ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
          ControlLook.DropDownFooter.Font.Color = clWindowText
          ControlLook.DropDownFooter.Font.Height = -13
          ControlLook.DropDownFooter.Font.Name = 'Tahoma'
          ControlLook.DropDownFooter.Font.Style = []
          ControlLook.DropDownFooter.Visible = True
          ControlLook.DropDownFooter.Buttons = <>
          Filter = <>
          FilterDropDown.Font.Charset = DEFAULT_CHARSET
          FilterDropDown.Font.Color = clWindowText
          FilterDropDown.Font.Height = -13
          FilterDropDown.Font.Name = 'Tahoma'
          FilterDropDown.Font.Style = []
          FilterDropDown.TextChecked = 'Checked'
          FilterDropDown.TextUnChecked = 'Unchecked'
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
          FixedColWidth = 70
          FixedRowHeight = 19
          FixedFont.Charset = DEFAULT_CHARSET
          FixedFont.Color = clWindowText
          FixedFont.Height = -11
          FixedFont.Name = 'Tahoma'
          FixedFont.Style = [fsBold]
          Flat = True
          FloatFormat = '%.2f'
          Grouping.HeaderColor = clInactiveCaptionText
          Grouping.HeaderColorTo = clWhite
          Grouping.SummaryColor = 15790320
          Grouping.SummaryColorTo = clWhite
          HoverButtons.Buttons = <>
          HoverButtons.Position = hbLeftFromColumnLeft
          HTMLSettings.ImageFolder = 'images'
          HTMLSettings.ImageBaseName = 'img'
          PrintSettings.DateFormat = 'dd/mm/yyyy'
          PrintSettings.Font.Charset = DEFAULT_CHARSET
          PrintSettings.Font.Color = clWindowText
          PrintSettings.Font.Height = -13
          PrintSettings.Font.Name = 'Tahoma'
          PrintSettings.Font.Style = []
          PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
          PrintSettings.FixedFont.Color = clWindowText
          PrintSettings.FixedFont.Height = -13
          PrintSettings.FixedFont.Name = 'Tahoma'
          PrintSettings.FixedFont.Style = []
          PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
          PrintSettings.HeaderFont.Color = clWindowText
          PrintSettings.HeaderFont.Height = -13
          PrintSettings.HeaderFont.Name = 'Tahoma'
          PrintSettings.HeaderFont.Style = []
          PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
          PrintSettings.FooterFont.Color = clWindowText
          PrintSettings.FooterFont.Height = -13
          PrintSettings.FooterFont.Name = 'Tahoma'
          PrintSettings.FooterFont.Style = []
          PrintSettings.PageNumSep = '/'
          ScrollWidth = 21
          SearchFooter.Color = clInactiveCaptionText
          SearchFooter.ColorTo = clWhite
          SearchFooter.FindNextCaption = 'Find &next'
          SearchFooter.FindPrevCaption = 'Find &previous'
          SearchFooter.Font.Charset = DEFAULT_CHARSET
          SearchFooter.Font.Color = clWindowText
          SearchFooter.Font.Height = -13
          SearchFooter.Font.Name = 'Tahoma'
          SearchFooter.Font.Style = []
          SearchFooter.HighLightCaption = 'Highlight'
          SearchFooter.HintClose = 'Close'
          SearchFooter.HintFindNext = 'Find next occurrence'
          SearchFooter.HintFindPrev = 'Find previous occurrence'
          SearchFooter.HintHighlight = 'Highlight occurrences'
          SearchFooter.MatchCaseCaption = 'Match case'
          SearchFooter.ResultFormat = '(%d of %d)'
          SelectionColor = 15790320
          SelectionColorTo = 15387318
          ShowDesignHelper = False
          SortSettings.DefaultFormat = ssAutomatic
          Version = '8.2.4.1'
          ColWidths = (
            70
            12
            12)
          RowHeights = (
            19
            19
            19
            19
            19
            19
            19
            19
            19
            19)
        end
      end
      object cpnlChart: TCategoryPanel
        Top = 198
        Height = 240
        Caption = 'Chart'
        ParentColor = True
        TabOrder = 1
        ExplicitTop = 233
        object chrtRoomStats: TChart
          Left = 0
          Top = 0
          Width = 467
          Height = 214
          Margins.Left = 10
          Margins.Top = 0
          Margins.Right = 0
          Margins.Bottom = 0
          Foot.Font.Name = 'Segoe UI'
          LeftWall.Color = clSilver
          Legend.Font.Height = -8
          Legend.Font.Name = 'Segoe UI'
          Legend.Visible = False
          SubTitle.Font.Color = clBlack
          Title.Font.Height = -8
          Title.Text.Strings = (
            'Rooms')
          Title.Visible = False
          BottomAxis.LabelsAlternate = True
          BottomAxis.LabelsSeparation = 4
          LeftAxis.Automatic = False
          LeftAxis.AutomaticMaximum = False
          LeftAxis.Maximum = 29.000000000000000000
          SeriesGroups = <
            item
              Name = 'Group1'
            end>
          Align = alClient
          BevelOuter = bvNone
          Color = clWhite
          TabOrder = 0
          PrintMargins = (
            15
            6
            15
            6)
          ColorPaletteIndex = 13
          object Series1: TBarSeries
            ColorEachPoint = True
            Marks.Arrow.Visible = True
            Marks.Callout.Brush.Color = clBlack
            Marks.Callout.Arrow.Visible = True
            Marks.Callout.Distance = -19
            Marks.Callout.Length = 0
            Marks.Margins.Left = 5
            Marks.Margins.Top = 1
            Marks.Margins.Right = 8
            Marks.Margins.Bottom = 0
            Marks.Style = smsValue
            Marks.Visible = True
            Title = 'Rooms'
            Emboss.Color = 8487297
            Shadow.Color = 8487297
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Bar'
            YValues.Order = loNone
            Data = {
              06050000000000000000001440FFFF0000FF0500000054616B656E0000000000
              001C4080804000FF040000004E6F526D0000000000002840FF000000FF040000
              0046726565000000000000224000800000FF050000004E6574746F0000000000
              00004080404000FF0900000043616E63656C6C6564}
          end
        end
      end
      object cpnlRoomClasses: TCategoryPanel
        Top = 0
        Height = 198
        Caption = 'Room Classes'
        FullRepaint = False
        ParentBackground = True
        ParentColor = True
        TabOrder = 2
        object grdRoomClasses: TAdvStringGrid
          Left = 0
          Top = 0
          Width = 467
          Height = 172
          Cursor = crDefault
          Margins.Left = 10
          Margins.Top = 0
          Margins.Right = 0
          Margins.Bottom = 0
          Align = alTop
          BevelEdges = []
          BevelInner = bvNone
          BevelOuter = bvNone
          BorderStyle = bsNone
          ColCount = 4
          Ctl3D = False
          DefaultColWidth = 60
          DefaultRowHeight = 19
          DrawingStyle = gdsClassic
          RowCount = 5
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentCtl3D = False
          ParentFont = False
          PopupMenu = pmnuChannelSettings
          ScrollBars = ssNone
          TabOrder = 0
          OnDrawCell = grdRoomClassesDrawCell
          OnMouseDown = grdRoomClassesMouseDown
          OnMouseMove = grdRoomClassesMouseMove
          ActiveRowColor = 15790320
          HoverRowCells = [hcNormal, hcSelected]
          OnGetCellBorder = grdRoomClassesGetCellBorder
          OnGetAlignment = grdGetAlignment
          OnCanEditCell = grdRoomClassesCanEditCell
          OnCellValidate = grdRoomClassesCellValidate
          OnResize = grdResize
          HintShowSizing = True
          ActiveCellFont.Charset = DEFAULT_CHARSET
          ActiveCellFont.Color = clWindowText
          ActiveCellFont.Height = -13
          ActiveCellFont.Name = 'Tahoma'
          ActiveCellFont.Style = [fsBold]
          ControlLook.FixedGradientFrom = clInactiveCaptionText
          ControlLook.FixedGradientTo = clWhite
          ControlLook.FixedGradientHoverFrom = clGray
          ControlLook.FixedGradientHoverTo = clWhite
          ControlLook.FixedGradientDownFrom = clGray
          ControlLook.FixedGradientDownTo = clSilver
          ControlLook.ControlStyle = csWinXP
          ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
          ControlLook.DropDownHeader.Font.Color = clWindowText
          ControlLook.DropDownHeader.Font.Height = -13
          ControlLook.DropDownHeader.Font.Name = 'Tahoma'
          ControlLook.DropDownHeader.Font.Style = []
          ControlLook.DropDownHeader.Visible = True
          ControlLook.DropDownHeader.Buttons = <>
          ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
          ControlLook.DropDownFooter.Font.Color = clWindowText
          ControlLook.DropDownFooter.Font.Height = -13
          ControlLook.DropDownFooter.Font.Name = 'Tahoma'
          ControlLook.DropDownFooter.Font.Style = []
          ControlLook.DropDownFooter.Visible = True
          ControlLook.DropDownFooter.Buttons = <>
          Filter = <>
          FilterDropDown.Font.Charset = DEFAULT_CHARSET
          FilterDropDown.Font.Color = clWindowText
          FilterDropDown.Font.Height = -13
          FilterDropDown.Font.Name = 'Tahoma'
          FilterDropDown.Font.Style = []
          FilterDropDown.TextChecked = 'Checked'
          FilterDropDown.TextUnChecked = 'Unchecked'
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
          FixedColWidth = 60
          FixedRowHeight = 19
          FixedFont.Charset = DEFAULT_CHARSET
          FixedFont.Color = clWindowText
          FixedFont.Height = -11
          FixedFont.Name = 'Tahoma'
          FixedFont.Style = [fsBold]
          Flat = True
          FloatFormat = '%.2f'
          Grouping.HeaderColor = clInactiveCaptionText
          Grouping.HeaderColorTo = clWhite
          Grouping.SummaryColor = 15790320
          Grouping.SummaryColorTo = clWhite
          HoverButtons.Buttons = <>
          HoverButtons.Position = hbLeftFromColumnLeft
          HTMLSettings.ImageFolder = 'images'
          HTMLSettings.ImageBaseName = 'img'
          PrintSettings.DateFormat = 'dd/mm/yyyy'
          PrintSettings.Font.Charset = DEFAULT_CHARSET
          PrintSettings.Font.Color = clWindowText
          PrintSettings.Font.Height = -13
          PrintSettings.Font.Name = 'Tahoma'
          PrintSettings.Font.Style = []
          PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
          PrintSettings.FixedFont.Color = clWindowText
          PrintSettings.FixedFont.Height = -13
          PrintSettings.FixedFont.Name = 'Tahoma'
          PrintSettings.FixedFont.Style = []
          PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
          PrintSettings.HeaderFont.Color = clWindowText
          PrintSettings.HeaderFont.Height = -13
          PrintSettings.HeaderFont.Name = 'Tahoma'
          PrintSettings.HeaderFont.Style = []
          PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
          PrintSettings.FooterFont.Color = clWindowText
          PrintSettings.FooterFont.Height = -13
          PrintSettings.FooterFont.Name = 'Tahoma'
          PrintSettings.FooterFont.Style = []
          PrintSettings.PageNumSep = '/'
          ScrollWidth = 21
          SearchFooter.Color = clInactiveCaptionText
          SearchFooter.ColorTo = clWhite
          SearchFooter.FindNextCaption = 'Find &next'
          SearchFooter.FindPrevCaption = 'Find &previous'
          SearchFooter.Font.Charset = DEFAULT_CHARSET
          SearchFooter.Font.Color = clWindowText
          SearchFooter.Font.Height = -13
          SearchFooter.Font.Name = 'Tahoma'
          SearchFooter.Font.Style = []
          SearchFooter.HighLightCaption = 'Highlight'
          SearchFooter.HintClose = 'Close'
          SearchFooter.HintFindNext = 'Find next occurrence'
          SearchFooter.HintFindPrev = 'Find previous occurrence'
          SearchFooter.HintHighlight = 'Highlight occurrences'
          SearchFooter.MatchCaseCaption = 'Match case'
          SearchFooter.ResultFormat = '(%d of %d)'
          SelectionColor = 15790320
          SelectionColorTo = 15387318
          ShowDesignHelper = False
          SortSettings.DefaultFormat = ssAutomatic
          Version = '8.2.4.1'
          RowHeights = (
            19
            19
            19
            19
            19)
        end
      end
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 112
    Top = 8
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 24
    Top = 8
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
  object pmnuChannelSettings: TPopupMenu
    Left = 252
    Top = 508
    object N01: TMenuItem
      Caption = '0'
    end
  end
  object sSkinProvider1: TsSkinProvider
    SkinData.SkinSection = 'FORM'
    TitleButtons = <>
    Left = 248
    Top = 168
  end
end
