inherited cxEditRepositoryEditor: TcxEditRepositoryEditor
  Left = 363
  Top = 194
  Caption = 'EditRepository editor'
  ClientHeight = 378
  ClientWidth = 337
  Constraints.MinHeight = 200
  Constraints.MinWidth = 350
  PopupMenu = PopupMenu1
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object bvTopSpacer: TBevel
    Left = 0
    Top = 0
    Width = 337
    Height = 8
    Align = alTop
    Shape = bsSpacer
  end
  object bvBottomSpacer: TBevel
    Left = 0
    Top = 370
    Width = 337
    Height = 8
    Align = alBottom
    Shape = bsSpacer
  end
  object bvLeftSpacer: TBevel
    Left = 0
    Top = 8
    Width = 8
    Height = 362
    Align = alLeft
    Shape = bsSpacer
  end
  object bvRightSpacer: TBevel
    Left = 329
    Top = 8
    Width = 8
    Height = 362
    Align = alRight
    Shape = bsSpacer
  end
  object LBItems: TListBox
    Left = 8
    Top = 8
    Width = 231
    Height = 362
    Align = alClient
    ItemHeight = 13
    MultiSelect = True
    Sorted = True
    TabOrder = 0
    OnClick = LBItemsClick
  end
  object Panel1: TPanel
    Left = 239
    Top = 8
    Width = 90
    Height = 362
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 1
    object btAdd: TButton
      Left = 6
      Top = 0
      Width = 85
      Height = 25
      Caption = '&Add...'
      TabOrder = 0
      OnClick = btAddClick
    end
    object btDelete: TButton
      Left = 6
      Top = 31
      Width = 85
      Height = 25
      Caption = '&Delete'
      TabOrder = 1
      OnClick = btDeleteClick
    end
    object btClose: TButton
      Left = 6
      Top = 337
      Width = 85
      Height = 25
      Anchors = [akLeft, akBottom]
      Caption = '&Close'
      TabOrder = 2
      OnClick = btCloseClick
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 32
    Top = 16
    object miAdd: TMenuItem
      Caption = 'Add'
      ShortCut = 45
      OnClick = miAddClick
    end
    object miDelete: TMenuItem
      Caption = 'Delete'
      Enabled = False
      ShortCut = 46
      OnClick = miDeleteClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object miSelectAll: TMenuItem
      Caption = 'Select all'
      Enabled = False
      ShortCut = 16449
      OnClick = miSelectAllClick
    end
  end
end
