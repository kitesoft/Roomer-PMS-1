object IDEEditorForm: TIDEEditorForm
  Left = 415
  Top = 131
  Width = 856
  Height = 545
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object FLeftSplitter: TSplitter
    Left = 185
    Top = 71
    Height = 420
    Beveled = True
  end
  object FRightSplitter: TSplitter
    Left = 671
    Top = 71
    Height = 420
    Align = alRight
    Beveled = True
  end
  object FLeftPanel: TPanel
    Left = 0
    Top = 71
    Width = 185
    Height = 420
    Align = alLeft
    BevelOuter = bvNone
    DockSite = True
    TabOrder = 0
    OnDockDrop = PanelDockDrop
    OnUnDock = PanelUnDock
  end
  object IDEPaletteToolbar2: TIDEPaletteToolbar
    Left = 0
    Top = 30
    Width = 848
    Height = 41
    Align = alTop
    FlatButtons = True
    ButtonSize = 29
  end
  object ControlBar1: TControlBar
    Left = 0
    Top = 0
    Width = 848
    Height = 30
    Align = alTop
    AutoSize = True
    BevelEdges = []
    BevelInner = bvNone
    BevelOuter = bvNone
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    object ToolBar2: TToolBar
      Left = 11
      Top = 2
      Width = 70
      Height = 26
      AutoSize = True
      Caption = 'ToolBar1'
      Images = dmIDEActions.ImageList1
      TabOrder = 1
      object ToolButton15: TToolButton
        Left = 0
        Top = 2
        Action = dmIDEActions.acNewProject
      end
      object ToolButton3: TToolButton
        Left = 23
        Top = 2
        Action = dmIDEActions.acOpenProject
      end
      object ToolButton4: TToolButton
        Left = 46
        Top = 2
        Action = dmIDEActions.acSaveAll
      end
    end
    object ToolBar4: TToolBar
      Left = 94
      Top = 2
      Width = 94
      Height = 26
      AutoSize = True
      Caption = 'ToolBar1'
      Images = dmIDEActions.ImageList1
      TabOrder = 3
      object ToolButton16: TToolButton
        Left = 0
        Top = 2
        Action = dmIDEActions.acNewUnit
      end
      object ToolButton17: TToolButton
        Left = 23
        Top = 2
        Action = dmIDEActions.acNewForm
      end
      object ToolButton18: TToolButton
        Left = 46
        Top = 2
        Action = dmIDEActions.acOpenFile
      end
      object ToolButton19: TToolButton
        Left = 69
        Top = 2
        Action = dmIDEActions.acSaveFile
      end
    end
    object ToolBar3: TToolBar
      Left = 201
      Top = 2
      Width = 73
      Height = 26
      AutoSize = True
      Caption = 'ToolBar1'
      Images = dmIDEActions.ImageList1
      TabOrder = 2
      object ToolButton6: TToolButton
        Left = 0
        Top = 2
        Action = dmIDEActions.acCutClipboard
      end
      object ToolButton7: TToolButton
        Left = 23
        Top = 2
        Action = dmIDEActions.acCopyClipboard
      end
      object ToolButton8: TToolButton
        Left = 46
        Top = 2
        Action = dmIDEActions.acPasteClipboard
      end
    end
    object ToolBar1: TToolBar
      Left = 287
      Top = 2
      Width = 179
      Height = 26
      AutoSize = True
      Caption = 'ToolBar1'
      Images = dmIDEActions.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 2
        Action = dmIDEActions.acRun
      end
      object ToolButton2: TToolButton
        Left = 23
        Top = 2
        Action = dmIDEActions.acPause
      end
      object ToolButton11: TToolButton
        Left = 46
        Top = 2
        Action = dmIDEActions.acReset
      end
      object ToolButton9: TToolButton
        Left = 69
        Top = 2
        Width = 8
        Caption = 'ToolButton9'
        ImageIndex = 23
        Style = tbsSeparator
      end
      object ToolButton5: TToolButton
        Left = 77
        Top = 2
        Action = dmIDEActions.acTraceInto
      end
      object ToolButton10: TToolButton
        Left = 100
        Top = 2
        Action = dmIDEActions.acStepOver
      end
      object ToolButton12: TToolButton
        Left = 123
        Top = 2
        Width = 8
        Caption = 'ToolButton12'
        ImageIndex = 12
        Style = tbsSeparator
      end
      object ToolButton13: TToolButton
        Left = 131
        Top = 2
        Action = dmIDEActions.acToggleBreak
      end
      object ToolButton14: TToolButton
        Left = 154
        Top = 2
        Action = dmIDEActions.acAddWatch
      end
    end
  end
  object FRightPanel: TPanel
    Left = 674
    Top = 71
    Width = 174
    Height = 420
    Align = alRight
    BevelOuter = bvNone
    DockSite = True
    TabOrder = 3
    OnDockDrop = PanelDockDrop
    OnUnDock = PanelUnDock
  end
  object Panel1: TPanel
    Left = 188
    Top = 71
    Width = 483
    Height = 420
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object FBottomSplitter: TSplitter
      Left = 0
      Top = 337
      Width = 483
      Height = 3
      Cursor = crVSplit
      Align = alBottom
    end
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 483
      Height = 337
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 0
      object TabControl1: TTabControl
        Left = 0
        Top = 0
        Width = 483
        Height = 316
        Align = alClient
        TabOrder = 0
        Visible = False
        object IDEFormDesignControl1: TIDEFormDesignControl
          Left = 4
          Top = 6
          Width = 475
          Height = 306
          Align = alClient
          Color = clWindow
          ParentColor = False
          PopupMenu = PopupMenu1
        end
        object IDEMemo1: TIDEMemo
          Left = 4
          Top = 6
          Width = 475
          Height = 306
          Cursor = crIBeam
          ActiveLineSettings.ShowActiveLine = True
          ActiveLineSettings.ShowActiveLineIndicator = False
          ActiveLineSettings.ActiveLineColor = 10066380
          ActiveLineSettings.ActiveLineTextColor = clBlack
          Align = alClient
          AutoCompletion.Font.Charset = DEFAULT_CHARSET
          AutoCompletion.Font.Color = clWindowText
          AutoCompletion.Font.Height = -11
          AutoCompletion.Font.Name = 'MS Sans Serif'
          AutoCompletion.Font.Style = []
          AutoCompletion.StartToken = '(.'
          AutoCorrect.Active = True
          AutoHintParameterPosition = hpBelowCode
          BookmarkGlyph.Data = {
            36050000424D3605000000000000360400002800000010000000100000000100
            0800000000000001000000000000000000000001000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
            A6000020400000206000002080000020A0000020C0000020E000004000000040
            20000040400000406000004080000040A0000040C0000040E000006000000060
            20000060400000606000006080000060A0000060C0000060E000008000000080
            20000080400000806000008080000080A0000080C0000080E00000A0000000A0
            200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
            200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
            200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
            20004000400040006000400080004000A0004000C0004000E000402000004020
            20004020400040206000402080004020A0004020C0004020E000404000004040
            20004040400040406000404080004040A0004040C0004040E000406000004060
            20004060400040606000406080004060A0004060C0004060E000408000004080
            20004080400040806000408080004080A0004080C0004080E00040A0000040A0
            200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
            200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
            200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
            20008000400080006000800080008000A0008000C0008000E000802000008020
            20008020400080206000802080008020A0008020C0008020E000804000008040
            20008040400080406000804080008040A0008040C0008040E000806000008060
            20008060400080606000806080008060A0008060C0008060E000808000008080
            20008080400080806000808080008080A0008080C0008080E00080A0000080A0
            200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
            200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
            200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
            2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
            2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
            2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
            2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
            2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
            2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
            2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FDFD25252525
            2525252525252525FDFDFD2E25FFFFFFFFFFFFFFFFFFFF25FDFDFD2525252525
            2525252525252525FDFD9A9AB7B7B7B7B7B7B7B7B7B72525FDFDFD25B7B7B7B7
            B7B7B7B7B7B72525FDFD9A9AB7B7B7B7B7B7B7B7B7B72525FDFDFD25BFB7BFBF
            B7B7B7B7B7B72525FDFD9A9ABFBFBFB7BFBFB7B7B7B72525FDFDFD25BFBFBFBF
            BFB7BFBFB7B72525FDFD9A9ABFBFBFB7BFBFBFB7BFB72525FDFDFD25BFBFBFBF
            BFBFBFBFBFB72525FDFD9A9ABFBFBFBFBFB7BFBFB7B72525FDFDFD25BFBFBFBF
            BFBFBFBFBFB72525FDFD9A9ABFBFBFBFBFBFBFBFBFB725FDFDFDFD2525252525
            25252525252525FDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFD}
          BorderStyle = bsSingle
          BreakpointColor = 16762823
          BreakpointTextColor = clBlack
          ClipboardFormats = [cfText]
          CodeFolding.Enabled = False
          CodeFolding.LineColor = clGray
          Ctl3D = False
          DelErase = True
          EnhancedHomeKey = False
          Gutter.Font.Charset = DEFAULT_CHARSET
          Gutter.Font.Color = clWindowText
          Gutter.Font.Height = -13
          Gutter.Font.Name = 'Courier New'
          Gutter.Font.Style = []
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'COURIER NEW'
          Font.Style = []
          HiddenCaret = False
          Lines.Strings = (
            '')
          MarkerList.UseDefaultMarkerImageIndex = False
          MarkerList.DefaultMarkerImageIndex = -1
          MarkerList.ImageTransparentColor = 33554432
          OleDropTarget = []
          PrintOptions.MarginLeft = 0
          PrintOptions.MarginRight = 0
          PrintOptions.MarginTop = 0
          PrintOptions.MarginBottom = 0
          PrintOptions.PageNr = False
          PrintOptions.PrintLineNumbers = False
          RightMarginColor = 14869218
          ScrollHint = False
          SelColor = clWhite
          SelBkColor = clNavy
          ShowRightMargin = True
          SmartTabs = False
          TabOrder = 1
          TabStop = True
          TrimTrailingSpaces = False
          UILanguage.ScrollHint = 'Row'
          UILanguage.Undo = 'Undo'
          UILanguage.Redo = 'Redo'
          UILanguage.Copy = 'Copy'
          UILanguage.Cut = 'Cut'
          UILanguage.Paste = 'Paste'
          UILanguage.Delete = 'Delete'
          UILanguage.SelectAll = 'Select All'
          UrlStyle.TextColor = clBlue
          UrlStyle.BkColor = clWhite
          UrlStyle.Style = [fsUnderline]
          UseStyler = True
          Version = '3.1.5.0'
          WordWrap = wwNone
        end
      end
      object TabSet1: TTabSet
        Left = 0
        Top = 316
        Width = 483
        Height = 21
        Align = alBottom
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        OnChange = TabSet1Change
      end
    end
    object FBottomPanel: TPanel
      Left = 0
      Top = 340
      Width = 483
      Height = 80
      Align = alBottom
      BevelOuter = bvNone
      DockSite = True
      TabOrder = 1
      OnDockDrop = PanelDockDrop
      OnUnDock = PanelUnDock
    end
  end
  object MainMenu1: TMainMenu
    Images = dmIDEActions.ImageList1
    Left = 368
    Top = 40
    object File1: TMenuItem
      Caption = '&File'
      object NewUnit1: TMenuItem
        Action = dmIDEActions.acNewUnit
      end
      object NewForm1: TMenuItem
        Action = dmIDEActions.acNewForm
      end
      object N7: TMenuItem
        Caption = '-'
      end
      object Newproject1: TMenuItem
        Action = dmIDEActions.acNewProject
      end
      object Openproject1: TMenuItem
        Action = dmIDEActions.acOpenProject
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object Open1: TMenuItem
        Action = dmIDEActions.acOpenFile
      end
      object Removefromproject1: TMenuItem
        Action = dmIDEActions.acRemoveFromProject
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Save1: TMenuItem
        Action = dmIDEActions.acSaveFile
      end
      object Saveas1: TMenuItem
        Action = dmIDEActions.acSaveAsFile
      end
      object Saveprojectas1: TMenuItem
        Action = dmIDEActions.acSaveProjectAs
      end
      object Saveall1: TMenuItem
        Action = dmIDEActions.acSaveAll
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Closefile1: TMenuItem
        Action = dmIDEActions.acCloseFile
      end
      object Closeall1: TMenuItem
        Action = dmIDEActions.acCloseAll
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Action = dmIDEActions.acExit
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
      object Undo1: TMenuItem
        Action = dmIDEActions.acUndo
      end
      object Redo1: TMenuItem
        Action = dmIDEActions.acRedo
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object Cut1: TMenuItem
        Action = dmIDEActions.acCutClipboard
      end
      object Copy1: TMenuItem
        Action = dmIDEActions.acCopyClipboard
      end
      object Paste1: TMenuItem
        Action = dmIDEActions.acPasteClipboard
      end
      object Delete1: TMenuItem
        Action = dmIDEActions.acDeleteControl
      end
      object SelectAll1: TMenuItem
        Action = dmIDEActions.acSelectAll
      end
      object N11: TMenuItem
        Caption = '-'
      end
      object Find1: TMenuItem
        Action = dmIDEActions.acFind
      end
      object Replace1: TMenuItem
        Action = dmIDEActions.acReplace
      end
      object Searchagain1: TMenuItem
        Action = dmIDEActions.acSearchAgain
      end
      object N8: TMenuItem
        Caption = '-'
      end
      object AligntoGrid1: TMenuItem
        Action = dmIDEActions.acAlignToGrid
      end
      object BringtoFront1: TMenuItem
        Action = dmIDEActions.acBringToFront
      end
      object SendtoBack1: TMenuItem
        Action = dmIDEActions.acSendToBack
      end
      object Align1: TMenuItem
        Action = dmIDEActions.acAlignDialog
      end
      object Size1: TMenuItem
        Action = dmIDEActions.acSizeDialog
      end
      object TabOrder1: TMenuItem
        Action = dmIDEActions.acTabOrderDialog
      end
      object acLock1: TMenuItem
        Action = dmIDEActions.acLock
      end
    end
    object View1: TMenuItem
      Caption = 'View'
      object ObjectInspector1: TMenuItem
        Action = acViewInspector
      end
      object ToolPalette1: TMenuItem
        Action = acViewPalette
      end
      object Watches1: TMenuItem
        Action = acViewWatches
      end
      object LibraryBrowser1: TMenuItem
        Action = acViewLibraryBrowser
      end
      object N9: TMenuItem
        Caption = '-'
      end
      object ToggleFormUnit1: TMenuItem
        Action = dmIDEActions.acToggleFormUnit
      end
    end
    object Run1: TMenuItem
      Caption = '&Run'
      object Run2: TMenuItem
        Action = dmIDEActions.acRun
      end
      object Compile1: TMenuItem
        Action = dmIDEActions.acCompile
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object Stepover1: TMenuItem
        Action = dmIDEActions.acStepOver
      end
      object Traceinto1: TMenuItem
        Action = dmIDEActions.acTraceInto
      end
      object Runtocursor1: TMenuItem
        Action = dmIDEActions.acRunTo
      end
      object Rununtilreturn1: TMenuItem
        Action = dmIDEActions.acReturn
      end
      object Pause1: TMenuItem
        Action = dmIDEActions.acPause
      end
      object Scriptreset1: TMenuItem
        Action = dmIDEActions.acReset
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object Addwatch1: TMenuItem
        Action = dmIDEActions.acAddWatch
      end
      object Togglebreakpoint1: TMenuItem
        Action = dmIDEActions.acToggleBreak
      end
    end
    object Project1: TMenuItem
      Caption = 'Project'
      object SelectMainUnit1: TMenuItem
        Action = dmIDEActions.acSetMainUnit
      end
    end
    object Tools1: TMenuItem
      Caption = 'Tools'
      object DesignerOptions1: TMenuItem
        Action = dmIDEActions.acDesignerOptionsDlg
      end
    end
  end
  object ActionList1: TActionList
    Left = 440
    Top = 42
    object acViewWatches: TAction
      Caption = 'Watches'
      Hint = 'View watches'
      ImageIndex = 27
      ShortCut = 49239
      OnExecute = acViewWatchesExecute
    end
    object acViewPalette: TAction
      Caption = 'Tool Palette'
      Hint = 'View Tool Palette'
      ImageIndex = 26
      ShortCut = 49232
      OnExecute = acViewPaletteExecute
    end
    object acViewLibraryBrowser: TAction
      Caption = 'Library Browser'
      Hint = 'View Library Browser'
      OnExecute = acViewLibraryBrowserExecute
    end
    object acViewInspector: TAction
      Caption = 'Object Inspector'
      Hint = 'View Object Inspector'
      ImageIndex = 25
      ShortCut = 122
      OnExecute = acViewInspectorExecute
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 474
    Top = 42
  end
end
