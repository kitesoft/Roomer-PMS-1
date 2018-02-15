object FrmFrontDeskPageButton: TFrmFrontDeskPageButton
  Left = 0
  Top = 0
  Caption = 'FrmFrontDeskPageButton'
  ClientHeight = 681
  ClientWidth = 1102
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnKeyPress = FormKeyPress
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object pnlContainer: TsPanel
    Left = 56
    Top = 32
    Width = 833
    Height = 593
    BevelOuter = bvNone
    Color = 16760636
    ParentBackground = False
    TabOrder = 0
    object sPanel1: TsPanel
      Tag = 1
      Left = 24
      Top = 24
      Width = 190
      Height = 130
      Cursor = crHandPoint
      BevelInner = bvLowered
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      OnMouseEnter = sPanel1MouseEnter
      OnMouseLeave = sPanel1MouseLeave
      OnMouseUp = sPanel1MouseUp
      SkinData.CustomColor = True
      SkinData.CustomFont = True
      object lblTxtArrivals: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 92
        Width = 180
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Align = alBottom
        Alignment = taCenter
        Caption = 'Remaining Arrivals'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = sPanel1MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
        ExplicitWidth = 122
      end
      object Shape1: TShape
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 180
        Height = 12
        Align = alTop
        Brush.Style = bsClear
        Pen.Style = psClear
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = sPanel1MouseUp
        ExplicitLeft = 8
        ExplicitTop = 3
        ExplicitWidth = 174
      end
      object sPanel2: TsPanel
        AlignWithMargins = True
        Left = 5
        Top = 31
        Width = 180
        Height = 55
        Cursor = crHandPoint
        Margins.Top = 11
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = sPanel1MouseUp
        OnPaint = panelOnPaint
        object sImage1: TsImage
          Left = 90
          Top = 10
          Width = 57
          Height = 49
          Cursor = crHandPoint
          Picture.Data = {07544269746D617000000000}
          Transparent = True
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = sPanel1MouseUp
          ImageIndex = 1
          Images = PngImageList1
          SkinData.SkinSection = 'CHECKBOX'
        end
        object lblArrivals: TsLabel
          Left = 42
          Top = 6
          Width = 18
          Height = 47
          Cursor = crHandPoint
          Caption = '0'
          ParentFont = False
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = sPanel1MouseUp
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = 'Segoe UI Light'
          Font.Style = []
          Font.Quality = fqAntialiased
          UseSkinColor = False
        end
      end
    end
    object sPanel3: TsPanel
      Tag = 2
      Left = 228
      Top = 24
      Width = 190
      Height = 130
      Cursor = crHandPoint
      BevelInner = bvLowered
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      OnMouseEnter = sPanel1MouseEnter
      OnMouseLeave = sPanel1MouseLeave
      SkinData.CustomColor = True
      SkinData.CustomFont = True
      object lbTxtlDepartures: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 92
        Width = 180
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Align = alBottom
        Alignment = taCenter
        Caption = 'Remaining departures'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape2MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
        ExplicitWidth = 148
      end
      object Shape2: TShape
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 180
        Height = 12
        Align = alTop
        Brush.Style = bsClear
        Pen.Style = psClear
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape2MouseUp
        ExplicitLeft = 8
        ExplicitTop = 8
        ExplicitWidth = 174
      end
      object sPanel4: TsPanel
        AlignWithMargins = True
        Left = 5
        Top = 31
        Width = 180
        Height = 55
        Cursor = crHandPoint
        Margins.Top = 11
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape2MouseUp
        OnPaint = panelOnPaint
        object sImage2: TsImage
          Left = 85
          Top = 6
          Width = 57
          Height = 49
          Cursor = crHandPoint
          Picture.Data = {07544269746D617000000000}
          Transparent = True
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape2MouseUp
          ImageIndex = 2
          Images = PngImageList1
          SkinData.SkinSection = 'CHECKBOX'
        end
        object lblDepartures: TsLabel
          Left = 42
          Top = 6
          Width = 18
          Height = 47
          Cursor = crHandPoint
          Caption = '0'
          ParentFont = False
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape2MouseUp
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = 'Segoe UI Light'
          Font.Style = []
          Font.Quality = fqAntialiased
          UseSkinColor = False
        end
      end
    end
    object sPanel5: TsPanel
      Tag = 3
      Left = 432
      Top = 24
      Width = 190
      Height = 130
      Cursor = crHandPoint
      BevelInner = bvLowered
      Color = clWhite
      ParentBackground = False
      TabOrder = 2
      OnMouseEnter = sPanel1MouseEnter
      OnMouseLeave = sPanel1MouseLeave
      OnMouseUp = Shape3MouseUp
      SkinData.CustomColor = True
      SkinData.CustomFont = True
      object lblTxtTomArrivals: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 92
        Width = 180
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Align = alBottom
        Alignment = taCenter
        Caption = 'Tomorrow'#39's arrivals'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape3MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
        ExplicitWidth = 123
      end
      object Shape3: TShape
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 180
        Height = 12
        Align = alTop
        Brush.Style = bsClear
        Pen.Style = psClear
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape3MouseUp
        ExplicitLeft = 10
        ExplicitTop = 13
      end
      object sLabel1: TsLabel
        AlignWithMargins = True
        Left = 131
        Top = 12
        Width = 16
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Alignment = taCenter
        Caption = '+1'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape3MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
      end
      object sPanel6: TsPanel
        AlignWithMargins = True
        Left = 5
        Top = 31
        Width = 180
        Height = 55
        Cursor = crHandPoint
        Margins.Top = 11
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape3MouseUp
        OnPaint = panelOnPaint
        object sImage3: TsImage
          Left = 85
          Top = 10
          Width = 57
          Height = 49
          Cursor = crHandPoint
          Picture.Data = {07544269746D617000000000}
          Transparent = True
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape3MouseUp
          ImageIndex = 1
          Images = PngImageList1
          SkinData.SkinSection = 'CHECKBOX'
        end
        object lblTomArrivals: TsLabel
          Left = 42
          Top = 6
          Width = 18
          Height = 47
          Cursor = crHandPoint
          Caption = '0'
          ParentFont = False
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape3MouseUp
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = 'Segoe UI Light'
          Font.Style = []
          Font.Quality = fqAntialiased
          UseSkinColor = False
        end
      end
    end
    object sPanel7: TsPanel
      Tag = 4
      Left = 636
      Top = 24
      Width = 190
      Height = 130
      Cursor = crHandPoint
      BevelInner = bvLowered
      Color = clWhite
      ParentBackground = False
      TabOrder = 3
      OnMouseEnter = sPanel1MouseEnter
      OnMouseLeave = sPanel1MouseLeave
      OnMouseUp = Shape4MouseUp
      SkinData.CustomColor = True
      SkinData.CustomFont = True
      object lblTxlTomDepartures: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 92
        Width = 180
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Align = alBottom
        Alignment = taCenter
        Caption = 'Tomorrow'#39's departures'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape4MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
        ExplicitWidth = 151
      end
      object Shape4: TShape
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 180
        Height = 12
        Align = alTop
        Brush.Style = bsClear
        Pen.Style = psClear
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape4MouseUp
        ExplicitLeft = 10
        ExplicitTop = 13
      end
      object sLabel2: TsLabel
        AlignWithMargins = True
        Left = 140
        Top = 12
        Width = 16
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Alignment = taCenter
        Caption = '+1'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape3MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
      end
      object sPanel8: TsPanel
        AlignWithMargins = True
        Left = 5
        Top = 31
        Width = 180
        Height = 55
        Cursor = crHandPoint
        Margins.Top = 11
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape4MouseUp
        OnPaint = panelOnPaint
        object sImage4: TsImage
          Left = 90
          Top = 10
          Width = 57
          Height = 49
          Cursor = crHandPoint
          Picture.Data = {07544269746D617000000000}
          Transparent = True
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape4MouseUp
          ImageIndex = 2
          Images = PngImageList1
          SkinData.SkinSection = 'CHECKBOX'
        end
        object lblTomDepartures: TsLabel
          Left = 42
          Top = 6
          Width = 18
          Height = 47
          Cursor = crHandPoint
          Caption = '0'
          ParentFont = False
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape4MouseUp
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = 'Segoe UI Light'
          Font.Style = []
          Font.Quality = fqAntialiased
          UseSkinColor = False
        end
      end
    end
    object sPanel9: TsPanel
      Tag = 5
      Left = 24
      Top = 168
      Width = 190
      Height = 130
      Cursor = crHandPoint
      BevelInner = bvLowered
      Color = clWhite
      ParentBackground = False
      TabOrder = 4
      OnMouseEnter = sPanel1MouseEnter
      OnMouseLeave = sPanel1MouseLeave
      OnMouseUp = Shape5MouseUp
      SkinData.CustomColor = True
      SkinData.CustomFont = True
      object lblTxtNewReservation: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 92
        Width = 180
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Align = alBottom
        Alignment = taCenter
        Caption = 'New reservation'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape5MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
        ExplicitWidth = 108
      end
      object Shape5: TShape
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 180
        Height = 12
        Align = alTop
        Brush.Style = bsClear
        Pen.Style = psClear
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape5MouseUp
        ExplicitLeft = 10
        ExplicitTop = 13
      end
      object sPanel10: TsPanel
        AlignWithMargins = True
        Left = 5
        Top = 31
        Width = 180
        Height = 55
        Cursor = crHandPoint
        Margins.Top = 11
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape5MouseUp
        OnPaint = panelOnPaint
        object sImage5: TsImage
          Left = 63
          Top = 8
          Width = 57
          Height = 49
          Cursor = crHandPoint
          Picture.Data = {07544269746D617000000000}
          Transparent = True
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape5MouseUp
          ImageIndex = 5
          Images = PngImageList1
          SkinData.SkinSection = 'CHECKBOX'
        end
      end
    end
    object sPanel11: TsPanel
      Tag = 6
      Left = 228
      Top = 168
      Width = 190
      Height = 130
      Cursor = crHandPoint
      BevelInner = bvLowered
      Color = clWhite
      ParentBackground = False
      TabOrder = 5
      OnMouseEnter = sPanel1MouseEnter
      OnMouseLeave = sPanel1MouseLeave
      OnMouseUp = Shape6MouseUp
      SkinData.CustomColor = True
      SkinData.CustomFont = True
      object lblTxtInHouse: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 92
        Width = 180
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Align = alBottom
        Alignment = taCenter
        Caption = 'In-house'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape6MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
        ExplicitWidth = 60
      end
      object Shape6: TShape
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 180
        Height = 12
        Align = alTop
        Brush.Style = bsClear
        Pen.Style = psClear
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape6MouseUp
        ExplicitLeft = 10
        ExplicitTop = 13
      end
      object sPanel12: TsPanel
        AlignWithMargins = True
        Left = 5
        Top = 31
        Width = 180
        Height = 55
        Cursor = crHandPoint
        Margins.Top = 11
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape6MouseUp
        OnPaint = panelOnPaint
        object sImage6: TsImage
          Left = 85
          Top = 8
          Width = 57
          Height = 49
          Cursor = crHandPoint
          Picture.Data = {07544269746D617000000000}
          Transparent = True
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape6MouseUp
          ImageIndex = 4
          Images = PngImageList1
          SkinData.SkinSection = 'CHECKBOX'
        end
        object lblInHouse: TsLabel
          Left = 42
          Top = 6
          Width = 18
          Height = 47
          Cursor = crHandPoint
          Caption = '0'
          ParentFont = False
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape6MouseUp
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = 'Segoe UI Light'
          Font.Style = []
          Font.Quality = fqAntialiased
          UseSkinColor = False
        end
      end
    end
    object sPanel13: TsPanel
      Tag = 7
      Left = 432
      Top = 168
      Width = 190
      Height = 130
      Cursor = crHandPoint
      BevelInner = bvLowered
      Color = clWhite
      ParentBackground = False
      TabOrder = 6
      OnMouseEnter = sPanel1MouseEnter
      OnMouseLeave = sPanel1MouseLeave
      OnMouseUp = Shape7MouseUp
      SkinData.CustomColor = True
      SkinData.CustomFont = True
      object lblTxtCalendar: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 92
        Width = 180
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Align = alBottom
        Alignment = taCenter
        Caption = 'Calendar'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape7MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
        ExplicitWidth = 60
      end
      object Shape7: TShape
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 180
        Height = 12
        Align = alTop
        Brush.Style = bsClear
        Pen.Style = psClear
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape7MouseUp
        ExplicitLeft = 10
        ExplicitTop = 13
      end
      object sPanel14: TsPanel
        AlignWithMargins = True
        Left = 5
        Top = 31
        Width = 180
        Height = 55
        Cursor = crHandPoint
        Margins.Top = 11
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = Shape7MouseUp
        OnPaint = panelOnPaint
        object sImage7: TsImage
          Left = 63
          Top = 8
          Width = 57
          Height = 49
          Cursor = crHandPoint
          Picture.Data = {07544269746D617000000000}
          Transparent = True
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = Shape7MouseUp
          ImageIndex = 0
          Images = PngImageList1
          SkinData.SkinSection = 'CHECKBOX'
        end
      end
    end
    object sPanel15: TsPanel
      Tag = 8
      Left = 636
      Top = 168
      Width = 190
      Height = 130
      Cursor = crHandPoint
      BevelInner = bvLowered
      Color = clWhite
      ParentBackground = False
      TabOrder = 7
      OnMouseEnter = sPanel1MouseEnter
      OnMouseLeave = sPanel1MouseLeave
      OnMouseUp = sPanel15MouseUp
      SkinData.CustomColor = True
      SkinData.CustomFont = True
      object lblTxtHousekeepingStatus: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 92
        Width = 180
        Height = 21
        Cursor = crHandPoint
        Margins.Bottom = 15
        Align = alBottom
        Alignment = taCenter
        Caption = 'Housekeeping status'
        ParentFont = False
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = sPanel15MouseUp
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI Light'
        Font.Style = []
        Font.Quality = fqAntialiased
        UseSkinColor = False
        ExplicitWidth = 139
      end
      object Shape8: TShape
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 180
        Height = 12
        Align = alTop
        Brush.Style = bsClear
        Pen.Style = psClear
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = sPanel15MouseUp
        ExplicitLeft = 10
        ExplicitTop = 13
      end
      object sPanel16: TsPanel
        AlignWithMargins = True
        Left = 5
        Top = 31
        Width = 180
        Height = 55
        Cursor = crHandPoint
        Margins.Top = 11
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        OnMouseEnter = sPanel1MouseEnter
        OnMouseLeave = sPanel1MouseLeave
        OnMouseUp = sPanel15MouseUp
        OnPaint = panelOnPaint
        object sImage8: TsImage
          Left = 60
          Top = 8
          Width = 57
          Height = 49
          Cursor = crHandPoint
          Picture.Data = {07544269746D617000000000}
          Transparent = True
          OnMouseEnter = sPanel1MouseEnter
          OnMouseLeave = sPanel1MouseLeave
          OnMouseUp = sPanel15MouseUp
          ImageIndex = 3
          Images = PngImageList1
          SkinData.SkinSection = 'CHECKBOX'
        end
      end
    end
    object StatGrid: TAdvStringGrid
      Left = 24
      Top = 326
      Width = 802
      Height = 257
      Cursor = crDefault
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      ColCount = 8
      Ctl3D = False
      DefaultColWidth = 100
      DefaultRowHeight = 30
      DoubleBuffered = True
      DrawingStyle = gdsClassic
      FixedCols = 0
      RowCount = 7
      FixedRows = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentCtl3D = False
      ParentDoubleBuffered = False
      ParentFont = False
      ScrollBars = ssNone
      TabOrder = 8
      GridLineColor = 15527152
      GridFixedLineColor = 13947601
      HoverRowCells = [hcNormal, hcSelected]
      OnGetCellColor = StatGridGetCellColor
      OnGetAlignment = StatGridGetAlignment
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      ActiveCellColor = 16575452
      ActiveCellColorTo = 16571329
      ControlLook.FixedGradientMirrorFrom = 16049884
      ControlLook.FixedGradientMirrorTo = 16247261
      ControlLook.FixedGradientHoverFrom = 16710648
      ControlLook.FixedGradientHoverTo = 16446189
      ControlLook.FixedGradientHoverMirrorFrom = 16049367
      ControlLook.FixedGradientHoverMirrorTo = 15258305
      ControlLook.FixedGradientDownFrom = 15853789
      ControlLook.FixedGradientDownTo = 15852760
      ControlLook.FixedGradientDownMirrorFrom = 15522767
      ControlLook.FixedGradientDownMirrorTo = 15588559
      ControlLook.FixedGradientDownBorder = 14007466
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
      DefaultEditor = edNone
      Filter = <>
      FilterDropDown.Font.Charset = DEFAULT_CHARSET
      FilterDropDown.Font.Color = clWindowText
      FilterDropDown.Font.Height = -11
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
      FixedColWidth = 100
      FixedRowHeight = 30
      FixedFont.Charset = DEFAULT_CHARSET
      FixedFont.Color = clBlack
      FixedFont.Height = -11
      FixedFont.Name = 'Tahoma'
      FixedFont.Style = [fsBold]
      Flat = True
      FloatFormat = '%.2f'
      HoverButtons.Buttons = <>
      HoverButtons.Position = hbLeftFromColumnLeft
      HTMLSettings.ImageFolder = 'images'
      HTMLSettings.ImageBaseName = 'img'
      Look = glWin7
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
      SearchFooter.Color = 16645370
      SearchFooter.ColorTo = 16247261
      SearchFooter.FindNextCaption = 'Find &next'
      SearchFooter.FindPrevCaption = 'Find &previous'
      SearchFooter.Font.Charset = DEFAULT_CHARSET
      SearchFooter.Font.Color = clWindowText
      SearchFooter.Font.Height = -11
      SearchFooter.Font.Name = 'Tahoma'
      SearchFooter.Font.Style = []
      SearchFooter.HighLightCaption = 'Highlight'
      SearchFooter.HintClose = 'Close'
      SearchFooter.HintFindNext = 'Find next occurrence'
      SearchFooter.HintFindPrev = 'Find previous occurrence'
      SearchFooter.HintHighlight = 'Highlight occurrences'
      SearchFooter.MatchCaseCaption = 'Match case'
      SearchFooter.ResultFormat = '(%d of %d)'
      ShowSelection = False
      SortSettings.DefaultFormat = ssAutomatic
      SortSettings.HeaderColor = 16579058
      SortSettings.HeaderColorTo = 16579058
      SortSettings.HeaderMirrorColor = 16380385
      SortSettings.HeaderMirrorColorTo = 16182488
      Version = '8.2.4.1'
    end
  end
  object PngImageList1: TPngImageList
    Height = 42
    Width = 51
    PngImages = <
      item
        Background = clWindow
        Name = 'calendar'
        PngImage.Data = {
          89504E470D0A1A0A0000000D49484452000000330000002A08060000001E7863
          79000000097048597300000EC400000EC401952B0E1B0000000774494D4507E1
          051D112D328E46A09D0000000774455874417574686F7200A9AECC480000000C
          744558744465736372697074696F6E00130921230000000A74455874436F7079
          726967687400AC0FCC3A0000000E744558744372656174696F6E2074696D6500
          35F70F090000000974455874536F667477617265005D70FF3A0000000B744558
          74446973636C61696D657200B7C0B48F00000008744558745761726E696E6700
          C01BE6870000000774455874536F7572636500F5FF83EB000000087445587443
          6F6D6D656E7400F6CC96BF00000006744558745469746C6500A8EED227000000
          6E4944415478DAEDD2C109C0300840D1B889EE3F94A3A4047ACEA1B644EDFF03
          884F14559DE3CEDD65144EC0240DCC2E339BD1194F5ABB830103060C98FE9893
          FD13F3F6FB7C71383060C080015317532130BBA2EF18D9010C183060C0F4C79C
          0C4CD6C0640D4CD6FA62AAD70A7301199B0280A4722AD20000000049454E44AE
          426082}
      end
      item
        Background = clWindow
        Name = 'check-ins'
        PngImage.Data = {
          89504E470D0A1A0A0000000D49484452000000330000002A08060000001E7863
          79000000097048597300000EC400000EC401952B0E1B0000000774494D4507E1
          051D112D37FE2C54120000000774455874417574686F7200A9AECC480000000C
          744558744465736372697074696F6E00130921230000000A74455874436F7079
          726967687400AC0FCC3A0000000E744558744372656174696F6E2074696D6500
          35F70F090000000974455874536F667477617265005D70FF3A0000000B744558
          74446973636C61696D657200B7C0B48F00000008744558745761726E696E6700
          C01BE6870000000774455874536F7572636500F5FF83EB000000087445587443
          6F6D6D656E7400F6CC96BF00000006744558745469746C6500A8EED227000001
          A14944415478DA63FCFFFF3FC370018CA39E19A460D43383158C7A66B08251CF
          10033E7FDEFEBFC52E8B61D5075C2AD818784455182C63B21966E579310EB867
          2ECC08FB1FD97999412AAC9D61668D33830A2F2FDC519F3FAFF85FA257C9B08B
          0873D8E482186E1EECA5D84314796645BAE2FF4AB06BD918E4823A19E636203C
          443866D03CA491C170737B39451EA29267201E12F56E6458D6EE8D1243B8C0E7
          CFCFFFDFDFBF88A1A57E06C3E90F10FDB60DBB1916C5CB91ED212A7A86740F81
          C09BA36DFF23626633DC0571AC6B18EE2F491E2C9E810001B77686D53DC4C6D0
          A3FFAB32ED195A8E0239CA190CF7F7909FD468E21988875A1896B6FA31688910
          F610DC9CC1EA19523C4453CFACC831FB5FBFF535C32FB2BD89E421DB1A86B97D
          610C46783C4453CFA42B2AFE27A67EA09687869467C01E322D6198322D8EC11A
          8B87869C67F07968487A06ECA1A0490CBB1B1C1844908AED51CF0CB467864D32
          1B3605C08016CDC3AAD224160C89E60C353C336C1A9AC3A40B306C3A67C3A6DB
          3C0C063486D550133E30E40601071B18F5CC6005A39E19AC60D43383150C2BCF
          00004403CDBC14D4E4970000000049454E44AE426082}
      end
      item
        Background = clWindow
        Name = 'check-outs'
        PngImage.Data = {
          89504E470D0A1A0A0000000D49484452000000330000002A08060000001E7863
          79000000097048597300000EC400000EC401952B0E1B0000000774494D4507E1
          051D112D34672505A80000000774455874417574686F7200A9AECC480000000C
          744558744465736372697074696F6E00130921230000000A74455874436F7079
          726967687400AC0FCC3A0000000E744558744372656174696F6E2074696D6500
          35F70F090000000974455874536F667477617265005D70FF3A0000000B744558
          74446973636C61696D657200B7C0B48F00000008744558745761726E696E6700
          C01BE6870000000774455874536F7572636500F5FF83EB000000087445587443
          6F6D6D656E7400F6CC96BF00000006744558745469746C6500A8EED227000001
          BE4944415478DA63FCFFFF3FC370018CA39E19A460D43383158C7A66B002829E
          F9FCFCF4FFF5133A1816ECBAC670FFC30F9CEAD84CCB19D6CD8D66D0E6E5651C
          949E797374EAFFAC9C1E86D31F883049398361D9FA2C064B24CF7CFE7CE7FFD6
          CA2886FADD0C0CAE8DCB18A644A8D0D4A3383DF3F9D19AFF95FEA50C5B89F108
          03F698F9FC79C5FF12BD4A865D609E00835BFB6A869934F4104ECF1C68B4FE9F
          B8E019C4A172DE0CD5CD450CAE86A20C9224242354CF403DD4B294A1D54F9641
          8406C911AB673E7F3EFA7FB27F0CC3ECFB400EAF1343CBBA090CD12AA45B8EE9
          19DA7A088767108E60F3EE66B83925842C4BB17B06E221DB9AB90C7D61AA54F5
          1041CF28672C63D8536E4965CFD0C64303E81988874C4BA6304C8BD3A38A87C8
          F20CA8A4AB0DA966D8F8FA1715C2937A1E22CF332BD2FFEB55EE22D60E220007
          834ECE1C86F9699479689078863A1E1A449E010136068D8C790C8BB3C8F3D020
          F30CC443B60DBB1916C5CB8D7A66107986B27C33883C336C0A80812C9A8753A5
          492C1812CD19EA7866001A9AC3A00B308C3A6720306CBACD60870CA7010D1018
          36434D70070D9741C0A106463D3358C1A867062B18F5CC6005A39E19AC000057
          D919CBC876B7B50000000049454E44AE426082}
      end
      item
        Background = clWindow
        Name = 'duster'
        PngImage.Data = {
          89504E470D0A1A0A0000000D49484452000000330000002A08060000001E7863
          79000000097048597300000EC400000EC401952B0E1B0000000774494D4507E1
          051D112D31174FF1270000000774455874417574686F7200A9AECC480000000C
          744558744465736372697074696F6E00130921230000000A74455874436F7079
          726967687400AC0FCC3A0000000E744558744372656174696F6E2074696D6500
          35F70F090000000974455874536F667477617265005D70FF3A0000000B744558
          74446973636C61696D657200B7C0B48F00000008744558745761726E696E6700
          C01BE6870000000774455874536F7572636500F5FF83EB000000087445587443
          6F6D6D656E7400F6CC96BF00000006744558745469746C6500A8EED227000005
          F14944415478DAD5594B2C645B14DD450C0CFC9F1E11E23312BF16660FA11989
          F64B0C24C4A71313492346FE9F8954C7C34CE293301049377A6084204C10BFB9
          4FA37BD4D19A444F7CCE3BEBBC77EE3BF7BA4A95BAF5E89D88BA55F7D6D9EBEC
          B3D7DE6B978D31462FD1767777594E4E0E9D9F9F93979717C1CFA3A3230A0B0B
          B33DF48CED2582F9FCF933ABAEAEA68B8B8BFF1CB5D9E8F0F0F0F702333E3E2E
          8018EDFDFBF764B7DB6D8E9E7D51608C40E01B22525E5E4E232323B6C79E7F31
          60BABABA587777B7767D7B7B4B3E3E3E54565646A3A3A38F027931607834188F
          8ADE311E91F8F878DADADA720AC88B002381C079E98B04B2B4B444FEFEFEBF07
          98929212C6994B8090F40B4B4A4AA2C5C54597803C2B98D4D454C66BC93F4EF0
          48DCDDDD0940010101747070E0329067038364E77F028411C8FCFC3C22E33210
          8F8241059F9898A0BDBD3DEDBDBCBC3C1C2DE1F4CCCC0CA9341C1818E816108F
          81696C6C64838383DAB531273E7CF840555555343D3D4D353535E23DCE5A9490
          90F064209683B9BCBC646FDEBCA1EDED6DCD7959F88CD6DADA4AF5F5F5D4D1D1
          41898989288C6E01B1140C8ED5BB77EF686767E79EF32AEDAAEFADAFAF537272
          B2DB202C03C32994CDCDCDD1E4E4245D5D5D698E4B408EBE3F3B3B9BDADADA2C
          03E41698959515D6D9D949ABABABF78E937A2D194BBDC6E748FAEFDFBF3F5F64
          9017B3B3B3680A0146731C39121E1E2EDA76B575379A910CAEAFAFFF5F308800
          72616D6D0D5AC374B7EBEAEA4432437380047EFEFCA9D511B98659F46E6E6EAC
          05D3D4D4249C3501A1CB01D5796968CF71D4503BA4A18243250290EAB8F159B4
          2D9B9B9BD682E1ADB62E3CC6A360B48888080102458FB71DA6F71801197308D7
          2D2D2DD4DEDE6E2D98D0D050A62E0A20320AF8CBC8C810F990999949595959BA
          28383200CACDCD153ADEC8704141414FEEC11C82E13BC8C0F9582C2D2D8DF2F3
          F3C9D7D7974A4B4BDD5E606A6A4A14C85FBF7E6980F0BFAFAF0FD5DF32201A18
          55AE4646468A0A6E66781F51898E8E766911E877557C71096C49C53705037BF5
          472803A5E21A8B151415D2CED6361D1F1FD3F2D23267B255FA333D9DFE1AE877
          69017C07D88DDDF1A878D9A88D47A9A5BDCD72203A309C91584F4FCF833722E1
          FBFB5D03022B2A2A128A117998CE37636161C123407460500CA3A2A274054F9E
          71D9E59A19EE41112D2C2CBCF7198E25A222EDB1219E656060AA688281C500E4
          A11CC1B300393A3A6ADA19232ACBCBCBE2B5B3E322CBC0C062626218F204C6F5
          85E68C1910ECBADD6EA7D7AF5FDFFB1C51484949D1A2EBE9A8988219181860E8
          64A5C35087434343BA7B40B7BDBDBD14171747509366565B5B2B5A1F6F6F6F41
          F75C457A14882918981CC8C99A0076933901B9CB95A4788DA26776BC60BCADA7
          939313517C3F7EFC48050505E2C68686066DB4F4F6ED5B1A1E1EF67CA3C98F10
          935D310CB983565F369A6845B863A6CF82444026B28B909DB11C2D19416F6C6C
          7856CF80DD209ED0801AFB34B422FBFBFB0F4645D5F62011D0F1D7AF5F190AB2
          F1BBF01A33327E9F676533DF61C60941D7FD02407373F3BDA880D1247DF3BC13
          72008EE35E34939C48C4EF2DF23BD40E9C833505830DC0A6F19ED09A59B3FCD1
          476D442B2A2A74055452F4D8D898B8467EC923FAE9D327F47A36443A2424C474
          0D7ECCEE496768A8E2E2629C1031F07066C2E99438FBF6ED1BE3094C720209C3
          F101310407078BDE0B740E7250C1188F1098926B279D58C3C698D51FE3AF0298
          A93D1621A765B39A43F27840C343616251B5414591FDF1E387B80FFFFDFCFC34
          27B0E3B2E9C4863CD47072CA67959595DAA413EB3E56A75C9E0160C0879C3013
          6F701C8668892FE760CECECE74608C86638C9E10CF422FF11AA7DD8B6EFECB97
          2F02B43304F1A4E90C761739823AA2DABF3BAD1BBB1A23A31A121CD4AC120CB4
          8F0AC8157BF2A809C70EDA5F1DC3C28C5ADF11184E222287548324E70CF63C83
          73EC2EA75E4D7C1969D711181C23D423D50777861C968D67399B89A93FE8F9F4
          F4543888C44583F91018441764214521CC1D15EA915F0164B18B8D8D15D31B47
          04707E7ECE50B330F440178E9AF4D475FF0660770DE9543FA36F000000004945
          4E44AE426082}
      end
      item
        Background = clWindow
        Name = 'guest'
        PngImage.Data = {
          89504E470D0A1A0A0000000D49484452000000330000002A08060000001E7863
          79000000097048597300000EC400000EC401952B0E1B0000000774494D4507E1
          051D112D33F941900B0000000774455874417574686F7200A9AECC480000000C
          744558744465736372697074696F6E00130921230000000A74455874436F7079
          726967687400AC0FCC3A0000000E744558744372656174696F6E2074696D6500
          35F70F090000000974455874536F667477617265005D70FF3A0000000B744558
          74446973636C61696D657200B7C0B48F00000008744558745761726E696E6700
          C01BE6870000000774455874536F7572636500F5FF83EB000000087445587443
          6F6D6D656E7400F6CC96BF00000006744558745469746C6500A8EED227000002
          754944415478DAEDD76F4853511806F0670803C1C1A0999435181A1BB53E1458
          0D1141CC4145A161947F2A16C2C524097423281821D92AB02F8E1BD2C4340B34
          2269423A028918E407C1E6D8A808564BCA45832B0882BC352123D6EC68DD79A6
          F7F974E11E0EFCB8EFB9EF7B544484F5129582E1340A86D728185EA36062C1E7
          F468E00146C602F834978DADE652549CAAC6F1A2EDD06934AA8CC048D2344D74
          37A3B9631CF13FBCD71609B87EAD11D6C2B501316324294693EE7AD8C410E697
          59A73609F0F436A258977E103BC6EFA2CA1A11EF18D61608FDF0392CFC627C57
          F65343DF17B65D37D7A1CB6747799ACF0F134692A6E8DE9923B835C1BAED1EB4
          3CEDC1F95D5C62FCE4AEAC81C852638B2980D0FF180E0B879844069B8CD4EA9D
          675A0B94A16DFC366AD3FC1360C6447A4ED341E70BB070D4254E8C765641CFE3
          9949448ABD2477BD0D62E82F1CB50982A7178E621DBF7FB345D0DB87D4527D09
          23F1542BB4A8681FC09D93857C37CD5FA067D47DA3035D6361CC2E7D2435728C
          A568B868C705EBDA4056855942C52214FD2C61E1C77396260F267DFACBEABF61
          78CCC6C42406CD6FD1F708BF0E23147C85375FE7100DFCBC0298919FBD093BF6
          ED84C9B81B46433EF43C0E9AD393A334745F44DF70001F67199BA63A07DBCC87
          5027D4E2E80103B6A4A9DFA4C4C482C374B7CD098F7F86A951A674E55A60735E
          C6B912F92F6E499844397D1872E2EC552F66FE45F13B09B9657688AE13D82B63
          F9256122834D74ACD58BF82A375C2EDAC337F1A4DD2ADB989384E9AC3210FBA8
          BFD2C87B3548C2B8CA0DC43EEAAF34F25E0D144CC66022A1299216E4C2644193
          275F43DD98E34C2644C1F01A05C36B140CAF595798EFF04F55BCD6A7871E0000
          000049454E44AE426082}
      end
      item
        Background = clWindow
        Name = 'new-reservation'
        PngImage.Data = {
          89504E470D0A1A0A0000000D49484452000000330000002A08060000001E7863
          79000000097048597300000EC400000EC401952B0E1B0000000774494D4507E1
          051D112D351022353E0000000774455874417574686F7200A9AECC480000000C
          744558744465736372697074696F6E00130921230000000A74455874436F7079
          726967687400AC0FCC3A0000000E744558744372656174696F6E2074696D6500
          35F70F090000000974455874536F667477617265005D70FF3A0000000B744558
          74446973636C61696D657200B7C0B48F00000008744558745761726E696E6700
          C01BE6870000000774455874536F7572636500F5FF83EB000000087445587443
          6F6D6D656E7400F6CC96BF00000006744558745469746C6500A8EED227000002
          6B4944415478DAEDD94D6813411806E03797A0874091F4600FA14B7AA8750D28
          F4B0486AEB4F104AA8590BA6057F68A1F5A701A5A112118C1E1A821161B11841
          4855D4981E0A5628494E06420505A5A4E2C112BCD8437BDB8392CB7422AD8536
          76374BD64ECABCA72C64F69B676777BE25B11042B05B62A9178CAA2649D01542
          061E44E663F0DB6C168E61211CC36A38868508826068521CB313A9DBDBCC30E6
          5E204096D78F0EF8A05CE9B254578621CC89E666B2B87EE489A0F8C4CF311CF3
          BF31EACA57F2717606E9740E39FA4567BB8843EE5E5C38DD8AFD9B4EF8C82F91
          973F8C4E772F9A44112ED729787A24480E7BD517755BCC524E21A3C109CC2D97
          B60CB43A648C3F0EE16CDB46D1E84981C417356B6AC7DA0869208CDB836EB4D9
          6DBA51FFC4ACE4A3E4FC401CDF4ADB8C6E90A164C3F0AE15AC19662D7BC4113C
          4D0CE1A84E50458CAA7E21CF2F9E43EC7349F3044D9712C8DFE93405F3E77AD1
          394DC5BAD162D30655C6CC4589AF3F0E5DF3B2D1D5C9D3D5A1C5CCC0500E6425
          8B075EED67A83226394C5CA18CCE62AD1849A530DA6E16863E42EE30B213321C
          1AAB53171858BB71FF5304BD86304CDD66E51C46F0DD335C3B680443378044BF
          0F0F0BDA651A6405D97027ECA6629CB8FC6A1A37250398F2477D5B33EDC653B4
          1BB798B335D70C53CEF7F45D72E3FA240ABFB70EB4361EC7583C8AC12326344D
          3330E5A84BF3E4C3DB69A432EF51F8F90BFB9C1DE8E83983BE2E118E4DCD8C79
          4C35610B732C84E2E49021CCC2C22C7913B88A17455630CC8663580DC7B01A23
          18B10FC59971267E03B8E515C8EBBFAF533BD0676A99E4B040365EDC39866338
          C6144CBDFC0BA027BB0AB30A1240048FAF64D07F0000000049454E44AE426082}
      end>
    Left = 904
    Top = 48
    Bitmap = {}
  end
end
