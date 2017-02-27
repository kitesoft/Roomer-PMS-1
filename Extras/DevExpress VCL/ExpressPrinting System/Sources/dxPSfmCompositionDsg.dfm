object dxfmCompositionDesignWindow: TdxfmCompositionDesignWindow
  Left = 380
  Top = 267
  BorderStyle = bsDialog
  Caption = 'Composition Designer'
  ClientHeight = 330
  ClientWidth = 462
  Color = clBtnFace
  Constraints.MinHeight = 334
  Constraints.MinWidth = 462
  KeyPreview = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object pcItems: TcxPageControl
    Left = 12
    Top = 12
    Width = 438
    Height = 271
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    Properties.ActivePage = tbsItems
    Properties.CustomButtons.Buttons = <>
    Properties.ShowFrame = True
    ClientRectBottom = 270
    ClientRectLeft = 1
    ClientRectRight = 437
    ClientRectTop = 24
    object tbsItems: TcxTabSheet
      BorderWidth = 10
      Caption = 'Items'
      ImageIndex = 0
      object bvlSpacer: TBevel
        Left = 0
        Top = 203
        Width = 416
        Height = 6
        Align = alBottom
        Shape = bsSpacer
      end
      object lvItems: TcxListView
        Left = 0
        Top = 0
        Width = 310
        Height = 203
        Align = alClient
        ColumnClick = False
        Columns = <>
        DragMode = dmAutomatic
        MultiSelect = True
        PopupMenu = pmItems
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnChange = lvItemsChange
        OnDblClick = DesignerClick
        OnDragDrop = lvItemsDragDrop
        OnDragOver = lvItemsDragOver
        OnEdited = lvItemsEdited
        OnEditing = lvItemsEditing
        OnStartDrag = lvItemsStartDrag
      end
      object gpButtons: TcxGroupBox
        Left = 310
        Top = 0
        Align = alRight
        PanelStyle.Active = True
        Style.BorderStyle = ebsNone
        Style.LookAndFeel.SkinName = ''
        StyleDisabled.LookAndFeel.SkinName = ''
        StyleFocused.LookAndFeel.SkinName = ''
        StyleHot.LookAndFeel.SkinName = ''
        TabOrder = 1
        Transparent = True
        Height = 203
        Width = 106
        object btnAdd: TcxButton
          Left = 10
          Top = 1
          Width = 96
          Height = 23
          Caption = '&Add...'
          TabOrder = 0
          OnClick = AddClick
        end
        object btnDelete: TcxButton
          Left = 10
          Top = 30
          Width = 96
          Height = 23
          Caption = '&Delete...'
          TabOrder = 1
          OnClick = DeleteClick
        end
        object btnDesign: TcxButton
          Left = 10
          Top = 65
          Width = 96
          Height = 23
          Caption = 'Desi&gn...'
          TabOrder = 2
          Font.Style = [fsBold]
          ParentFont = False
          OnClick = DesignerClick
        end
        object btnMoveDown: TcxButton
          Left = 10
          Top = 129
          Width = 96
          Height = 23
          Caption = 'Move Down'
          TabOrder = 3
          OnClick = MoveDownClick
        end
        object btnMoveUp: TcxButton
          Left = 10
          Top = 100
          Width = 96
          Height = 23
          Caption = 'Move Up'
          TabOrder = 4
          OnClick = MoveUpClick
        end
      end
      object cbStartEachItemFromNewPage: TcxCheckBox
        Left = 0
        Top = 209
        Align = alBottom
        Caption = '&Start each item from new page'
        ParentBackground = False
        Style.TransparentBorder = False
        TabOrder = 2
        Transparent = True
        OnClick = cbStartEachItemFromNewPageClick
        Width = 416
      end
    end
  end
  object btnClose: TcxButton
    Left = 274
    Top = 295
    Width = 85
    Height = 23
    Anchors = [akRight, akBottom]
    Caption = 'Close'
    ModalResult = 1
    TabOrder = 1
  end
  object btnHelp: TcxButton
    Left = 365
    Top = 295
    Width = 85
    Height = 23
    Anchors = [akRight, akBottom]
    Caption = '&Help'
    TabOrder = 3
  end
  object pnlNoItems: TcxLabel
    Left = 44
    Top = 130
    TabStop = False
    Anchors = [akLeft, akTop, akRight, akBottom]
    AutoSize = False
    Caption = 'There are no Items to dispay'
    ParentColor = False
    ParentFont = False
    Style.TextColor = clGray
    Style.TextStyle = [fsBold]
    Properties.Alignment.Horz = taCenter
    Properties.Alignment.Vert = taVCenter
    Transparent = True
    Height = 54
    Width = 269
    AnchorX = 179
    AnchorY = 157
  end
  object pmItems: TPopupMenu
    Images = ilItems
    OnPopup = pmItemsPopup
    Left = 36
    Top = 72
    object miAdd: TMenuItem
      Caption = '&Add...'
      ImageIndex = 14
      ShortCut = 45
      OnClick = AddClick
    end
    object miDelete: TMenuItem
      Caption = '&Delete'
      ImageIndex = 5
      ShortCut = 46
      OnClick = DeleteClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object miRename: TMenuItem
      Caption = 'Rena&me'
      ShortCut = 113
      OnClick = RenameClick
    end
    object miSelectAll: TMenuItem
      Caption = 'Select All'
      ShortCut = 16449
      OnClick = SelectAllClick
    end
    object miLine2: TMenuItem
      Caption = '-'
    end
    object miDesign: TMenuItem
      Caption = 'Desi&gn...'
      Default = True
      ImageIndex = 6
      ShortCut = 16397
      OnClick = DesignerClick
    end
    object miLine1: TMenuItem
      Caption = '-'
    end
    object miMoveUp: TMenuItem
      Caption = 'Move &Up'
      ImageIndex = 10
      ShortCut = 16422
      OnClick = MoveUpClick
    end
    object miMoveDown: TMenuItem
      Caption = 'Move &Down'
      ImageIndex = 11
      ShortCut = 16424
      OnClick = MoveDownClick
    end
  end
  object ilItems: TcxImageList
    FormatVersion = 1
    DesignInfo = 4718664
  end
end
