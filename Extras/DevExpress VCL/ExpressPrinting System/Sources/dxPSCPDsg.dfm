object dxfmCPDesigner: TdxfmCPDesigner
  Left = 435
  Top = 281
  BorderStyle = bsDialog
  Caption = 'Component Printer Designer'
  ClientHeight = 312
  ClientWidth = 466
  Color = clBtnFace
  Constraints.MinHeight = 340
  Constraints.MinWidth = 460
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object btnClose: TcxButton
    Left = 278
    Top = 277
    Width = 85
    Height = 23
    Caption = 'Close'
    ModalResult = 1
    TabOrder = 1
  end
  object btnHelp: TcxButton
    Left = 369
    Top = 277
    Width = 85
    Height = 23
    Caption = '&Help'
    TabOrder = 2
  end
  object pcItems: TcxPageControl
    Left = 12
    Top = 12
    Width = 442
    Height = 254
    ActivePage = tbsItems
    Anchors = [akLeft, akTop, akRight, akBottom]
    ShowFrame = True
    TabOrder = 0
    ClientRectBottom = 253
    ClientRectLeft = 1
    ClientRectRight = 441
    ClientRectTop = 24
    object tbsItems: TcxTabSheet
      BorderWidth = 10
      Caption = 'Items'
      ImageIndex = 0
      object lvItems: TcxListView
        Left = 0
        Top = 0
        Width = 314
        Height = 209
        Align = alClient
        ColumnClick = False
        Columns = <>
        MultiSelect = True
        PopupMenu = pmItems
        RowSelect = True
        Style.TransparentBorder = False
        TabOrder = 0
        ViewStyle = vsReport
        OnChange = lvItemsChange
        OnDblClick = lvItemsDblClick
        OnEdited = lvItemsEdited
        OnEditing = lvItemsEditing
      end
      object pnlButtons: TcxGroupBox
        Left = 314
        Top = 0
        Align = alRight
        PanelStyle.Active = True
        Style.BorderStyle = ebsNone
        TabOrder = 1
        Height = 209
        Width = 106
        object btnDesign: TcxButton
          Left = 10
          Top = 99
          Width = 96
          Height = 23
          Anchors = [akLeft, akBottom]
          Caption = 'Desi&gn...'
          TabOrder = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          OnClick = DesignClick
        end
        object btnAdd: TcxButton
          Left = 10
          Top = 0
          Width = 96
          Height = 23
          Caption = '&Add...'
          TabOrder = 0
          OnClick = AddClick
        end
        object btnDelete: TcxButton
          Left = 10
          Top = 58
          Width = 96
          Height = 23
          Caption = '&Delete...'
          TabOrder = 2
          OnClick = DeleteClick
        end
        object btnPageSetup: TcxButton
          Left = 10
          Top = 128
          Width = 96
          Height = 23
          Anchors = [akLeft, akBottom]
          Caption = 'Pa&ge Setup...'
          TabOrder = 4
          OnClick = PageSetupClick
        end
        object btnPrintPreview: TcxButton
          Left = 10
          Top = 157
          Width = 96
          Height = 23
          Anchors = [akLeft, akBottom]
          Caption = 'Pre&view...'
          TabOrder = 5
          OnClick = PrintPreviewClick
        end
        object btnPrint: TcxButton
          Left = 10
          Top = 186
          Width = 96
          Height = 23
          Anchors = [akLeft, akBottom]
          Caption = '&Print...'
          TabOrder = 6
          OnClick = PrintClick
        end
        object btnAddComposition: TcxButton
          Left = 10
          Top = 29
          Width = 96
          Height = 23
          Caption = 'Add Composition'
          TabOrder = 1
          OnClick = AddCompositionClick
        end
      end
      object pnlNoItems: TcxLabel
        Left = 12
        Top = 83
        TabStop = False
        AutoSize = False
        Caption = 'There are no Items to display'
        ParentColor = False
        ParentFont = False
        Style.TextColor = clGray
        Properties.Alignment.Horz = taCenter
        Properties.Alignment.Vert = taVCenter
        Transparent = True
        Height = 38
        Width = 301
        AnchorX = 163
        AnchorY = 102
      end
    end
  end
  object pmItems: TPopupMenu
    Images = ilItems
    OnPopup = pmItemsPopup
    Left = 20
    Top = 198
    object miAdd: TMenuItem
      Caption = '&Add...'
      ImageIndex = 14
      ShortCut = 45
      OnClick = AddClick
    end
    object miAddComposition: TMenuItem
      Caption = 'Add Composition'
      OnClick = AddCompositionClick
    end
    object miDelete: TMenuItem
      Caption = '&Delete'
      ImageIndex = 5
      ShortCut = 46
      OnClick = DeleteClick
    end
    object miRename: TMenuItem
      Caption = '&Rename'
      ShortCut = 113
      OnClick = RenameClick
    end
    object miLine2: TMenuItem
      Caption = '-'
    end
    object miDesign: TMenuItem
      Caption = 'Desi&gn...'
      Default = True
      ImageIndex = 6
      ShortCut = 16397
      OnClick = DesignClick
    end
    object miLine1: TMenuItem
      Caption = '-'
    end
    object miPageSetup: TMenuItem
      Caption = 'Pa&ge Setup...'
      ImageIndex = 15
      OnClick = PageSetupClick
    end
    object miPrintPreview: TMenuItem
      Caption = 'Pre&view...'
      ImageIndex = 8
      OnClick = PrintPreviewClick
    end
    object miPrint: TMenuItem
      Caption = '&Print...'
      ImageIndex = 16
      ShortCut = 16464
      OnClick = PrintClick
    end
  end
  object ilItems: TcxImageList
    FormatVersion = 1
    DesignInfo = 13107248
  end
end
