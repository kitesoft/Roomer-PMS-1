object dxfmDefinePrintStyles: TdxfmDefinePrintStyles
  Left = 414
  Top = 232
  BorderStyle = bsDialog
  Caption = 'Define Print Styles'
  ClientHeight = 204
  ClientWidth = 314
  Color = clBtnFace
  Constraints.MinHeight = 220
  Constraints.MinWidth = 290
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000004
    4444000000004444474F444440004477774FFFF440004477774FFFF440004477
    774FFFF440004477774FFFF440004477774FFFF444444477774FFFF44F444477
    7474FFF44F44044447774444FF440004477774FFFF440004477774FFFF440004
    477774FFFF4400044777404FFF4400004444000444400000000000000000E0FF
    0000000700000007000000070000000700000007000000000000000000000000
    000080000000E0000000E0000000E0000000E0400000F0E10000FFFF0000}
  KeyPreview = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object lblPrintStyles: TLabel
    Left = 12
    Top = 12
    Width = 58
    Height = 13
    Caption = 'Print &Styles:'
    FocusControl = lbxPrintStyles
    Transparent = True
  end
  object btnEdit: TcxButton
    Left = 218
    Top = 28
    Width = 85
    Height = 23
    Anchors = [akTop, akRight]
    Caption = '&Edit...'
    TabOrder = 1
    OnClick = EditClick
  end
  object btnCopy: TcxButton
    Left = 218
    Top = 57
    Width = 85
    Height = 23
    Anchors = [akTop, akRight]
    Caption = '&Copy...'
    TabOrder = 2
    OnClick = CopyClick
  end
  object btnReset: TcxButton
    Left = 218
    Top = 86
    Width = 85
    Height = 23
    Anchors = [akTop, akRight]
    Caption = '&Reset...'
    TabOrder = 3
    OnClick = ResetClick
  end
  object btnClose: TcxButton
    Left = 218
    Top = 141
    Width = 85
    Height = 23
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = 'Close'
    Default = True
    ModalResult = 1
    TabOrder = 4
  end
  object btnHelp: TcxButton
    Left = 218
    Top = 170
    Width = 85
    Height = 23
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = '&Help'
    ModalResult = 1
    TabOrder = 5
  end
  object lbxPrintStyles: TcxListBox
    Left = 12
    Top = 28
    Width = 200
    Height = 165
    Anchors = [akLeft, akTop, akRight, akBottom]
    ItemHeight = 34
    ListStyle = lbOwnerDrawFixed
    PopupMenu = pmPrintStyles
    Style.TransparentBorder = False
    TabOrder = 0
    OnClick = lbxPrintStylesClick
    OnDblClick = EditClick
    OnDrawItem = lbxPrintStylesDrawItem
  end
  object pmPrintStyles: TPopupMenu
    Images = ilPrintStyles
    OnPopup = pmPrintStylesPopup
    Left = 26
    Top = 120
    object miEdit: TMenuItem
      Caption = '&Edit ...'
      Default = True
      ImageIndex = 15
      ShortCut = 16397
      OnClick = EditClick
    end
    object miLine1: TMenuItem
      Caption = '-'
    end
    object miCopy: TMenuItem
      Caption = '&Copy ...'
      ImageIndex = 2
      ShortCut = 45
      OnClick = CopyClick
    end
    object miReset: TMenuItem
      Caption = '&Reset ...'
      OnClick = ResetClick
    end
    object miClear: TMenuItem
      Caption = 'C&lear ...'
      OnClick = ClearClick
    end
  end
  object ilPrintStyles: TcxImageList
    FormatVersion = 1
    DesignInfo = 7864376
  end
end
