object dxBreadcrumbEditEditorForm: TdxBreadcrumbEditEditorForm
  Left = 224
  Top = 210
  BorderIcons = [biSystemMenu]
  ClientHeight = 262
  ClientWidth = 438
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 400
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object bvlLine: TdxBevel
    Left = 8
    Top = 217
    Width = 422
    Height = 6
    Anchors = [akLeft, akRight, akBottom]
    Shape = dxbsLineCenteredVert
  end
  object cxBtnOK: TcxButton
    Left = 274
    Top = 229
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 0
  end
  object cxBtnCancel: TcxButton
    Left = 355
    Top = 229
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object tvStruct: TcxTreeView
    Left = 8
    Top = 8
    Width = 260
    Height = 203
    Anchors = [akLeft, akTop, akRight, akBottom]
    Style.TransparentBorder = False
    TabOrder = 2
    HideSelection = False
    ReadOnly = True
    OnChange = tvStructChange
  end
  object btnNewItem: TcxButton
    Left = 274
    Top = 8
    Width = 156
    Height = 25
    Anchors = [akTop, akRight]
    Caption = '&New Item'
    TabOrder = 3
    OnClick = btnNewItemClick
  end
  object btnNewSubItem: TcxButton
    Left = 274
    Top = 39
    Width = 156
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'New &SubItem'
    TabOrder = 4
    OnClick = btnNewSubItemClick
  end
  object btnDeleteItem: TcxButton
    Left = 274
    Top = 70
    Width = 156
    Height = 25
    Anchors = [akTop, akRight]
    Caption = '&Delete'
    TabOrder = 5
    OnClick = btnDeleteItemClick
  end
  object gbItemOptions: TcxGroupBox
    Left = 274
    Top = 103
    Anchors = [akTop, akRight]
    Caption = ' Item Options '
    TabOrder = 6
    Height = 108
    Width = 156
    object lbItemText: TcxLabel
      Left = 10
      Top = 17
      Caption = '&Text:'
      FocusControl = teItemText
      Transparent = True
    end
    object teItemText: TcxTextEdit
      Left = 10
      Top = 35
      Properties.OnChange = teItemOptionsChange
      TabOrder = 1
      Width = 136
    end
    object lbItemImageIndex: TcxLabel
      Left = 10
      Top = 59
      Caption = 'I&mage Index:'
      Transparent = True
    end
    object seItemImageIndex: TcxSpinEdit
      Left = 10
      Top = 77
      Properties.MinValue = -1.000000000000000000
      Properties.OnChange = teItemOptionsChange
      TabOrder = 3
      Value = -1
      Width = 136
    end
  end
  object cbSaveSelection: TcxCheckBox
    Left = 8
    Top = 233
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'S&ave selection'
    State = cbsChecked
    TabOrder = 7
    Transparent = True
    Width = 260
  end
end
