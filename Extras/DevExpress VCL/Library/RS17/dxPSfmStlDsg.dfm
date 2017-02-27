object dxfmPrintStylesDesignWindow: TdxfmPrintStylesDesignWindow
  Left = 395
  Top = 187
  BorderStyle = bsDialog
  BorderWidth = 12
  Caption = 'Print Styles'
  ClientHeight = 191
  ClientWidth = 346
  Color = clBtnFace
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    00000000000000000000000000000FFFFFFFFFF000000F00F00000F000000FFF
    FFFFFFF000000F00F00000F000000FFFFFFFFFF000000FFFFFFF0FF000000F00
    FFF080F000000F080F08080000440FF080808088804400000808088888440000
    008088888844000000088888804400000000000000440000000000000000FFFF
    0000000F0000000F0000000F0000000F0000000F0000000F0000000F0000000F
    0000000400000000000000000000F8000000FC000000FE040000FFFF0000}
  KeyPreview = True
  OldCreateOrder = True
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object pnlButtons: TcxGroupBox
    Left = 228
    Top = 0
    Align = alRight
    PanelStyle.Active = True
    Style.BorderStyle = ebsNone
    Style.TransparentBorder = False
    TabOrder = 0
    Height = 191
    Width = 118
    object btnAdd: TcxButton
      Left = 8
      Top = 0
      Width = 110
      Height = 22
      Caption = '&Add...'
      TabOrder = 0
      OnClick = AddClick
    end
    object btnDelete: TcxButton
      Tag = 4
      Left = 8
      Top = 28
      Width = 110
      Height = 22
      Caption = '&Delete'
      TabOrder = 1
      OnClick = EditClick
    end
    object btnSelectAll: TcxButton
      Tag = 6
      Left = 8
      Top = 56
      Width = 110
      Height = 22
      Caption = 'Se&lect All'
      TabOrder = 2
      OnClick = EditClick
    end
    object btnPageSetup: TcxButton
      Tag = 1
      Left = 8
      Top = 140
      Width = 110
      Height = 22
      Caption = 'Pa&ge Setup...'
      TabOrder = 5
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = PageSetupClick
    end
    object btnMoveUp: TcxButton
      Left = 8
      Top = 84
      Width = 110
      Height = 22
      Caption = 'Move &Up'
      TabOrder = 3
      OnClick = MoveUpClick
    end
    object btnMoveDown: TcxButton
      Tag = 1
      Left = 8
      Top = 112
      Width = 110
      Height = 22
      Caption = 'Move Dow&n'
      TabOrder = 4
      OnClick = MoveDownClick
    end
    object btnRestoreDefaults: TcxButton
      Left = 8
      Top = 168
      Width = 110
      Height = 22
      Caption = 'Rest&ore Defaults'
      TabOrder = 6
      OnClick = RestoreDefaultsClick
    end
  end
  object lbxStyles: TcxListBox
    Left = 0
    Top = 0
    Width = 228
    Height = 191
    Align = alClient
    DragMode = dmAutomatic
    ItemHeight = 36
    ListStyle = lbOwnerDrawFixed
    MultiSelect = True
    ParentFont = False
    PopupMenu = pmStyles
    Style.TransparentBorder = False
    TabOrder = 1
    OnClick = lbxStylesClick
    OnDblClick = PageSetupClick
    OnDragDrop = lbxStylesDragDrop
    OnDragOver = lbxStylesDragOver
    OnDrawItem = lbxStylesDrawItem
    OnEndDrag = lbxStylesEndDrag
    OnKeyPress = lbxStylesKeyPress
    OnStartDrag = lbxStylesStartDrag
  end
  object pmStyles: TPopupMenu
    Images = ilMenu
    OnPopup = pmStylesPopup
    Left = 13
    Top = 9
    object miAdd: TMenuItem
      Caption = '&Add...'
      ImageIndex = 0
      ShortCut = 45
      OnClick = AddClick
    end
    object miAddStandard: TMenuItem
      Caption = 'Add'
      ShortCut = 32813
      OnClick = AddStandardClick
    end
    object miLine5: TMenuItem
      Caption = '-'
    end
    object miEdit: TMenuItem
      Caption = '&Edit'
      object miCut: TMenuItem
        Tag = 2
        Caption = 'Cu&t'
        ImageIndex = 3
        ShortCut = 16472
        OnClick = EditClick
      end
      object miCopy: TMenuItem
        Tag = 1
        Caption = '&Copy'
        ImageIndex = 2
        ShortCut = 16451
        OnClick = EditClick
      end
      object miPaste: TMenuItem
        Tag = 3
        Caption = '&Paste'
        ImageIndex = 4
        ShortCut = 16470
        OnClick = EditClick
      end
      object miDelete: TMenuItem
        Tag = 4
        Caption = '&Delete'
        ImageIndex = 5
        ShortCut = 46
        OnClick = EditClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object miSelectAll: TMenuItem
        Tag = 6
        Caption = 'Se&lect All'
        ShortCut = 16449
        OnClick = EditClick
      end
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object miMoveUp: TMenuItem
      Caption = 'Move &Up'
      ImageIndex = 10
      ShortCut = 16422
      OnClick = MoveUpClick
    end
    object miMoveDown: TMenuItem
      Caption = 'Move Dow&n'
      ImageIndex = 11
      ShortCut = 16424
      OnClick = MoveDownClick
    end
    object miLine1: TMenuItem
      Caption = '-'
    end
    object miPageSetup: TMenuItem
      Tag = 1
      Caption = 'Pa&ge Setup...'
      Default = True
      ImageIndex = 7
      ShortCut = 16397
      OnClick = PageSetupClick
    end
    object miSetAsCurrent: TMenuItem
      Caption = '&Make Current'
      ShortCut = 16416
      OnClick = miSetAsCurrentClick
    end
    object miLine: TMenuItem
      Caption = '-'
    end
    object miRestoreDefaults: TMenuItem
      Caption = 'Rest&ore Defaults'
      ShortCut = 16463
      OnClick = RestoreDefaultsClick
    end
    object miLine2: TMenuItem
      Caption = '-'
    end
    object miBackground: TMenuItem
      Caption = 'Bac&kground'
      object miBackgroundEffects: TMenuItem
        Tag = 4
        Caption = 'E&ffects...'
        ImageIndex = 12
        OnClick = BackgroundClick
      end
      object miBackgroundClear: TMenuItem
        Tag = 5
        Caption = 'Clear'
        OnClick = ClearBackgroundClick
      end
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object miShowButtons: TMenuItem
      Caption = 'Show &Button Bar'
      Checked = True
      OnClick = miShowButtonsClick
    end
  end
  object ilMenu: TcxImageList
    FormatVersion = 1
    DesignInfo = 589865
  end
end
