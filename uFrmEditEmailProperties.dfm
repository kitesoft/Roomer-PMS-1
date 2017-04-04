object FrmEditEmailProperties: TFrmEditEmailProperties
  Left = 0
  Top = 0
  Caption = 'Edit Email Properties'
  ClientHeight = 142
  ClientWidth = 597
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object sLabel1: TsLabel
    Left = 64
    Top = 41
    Width = 78
    Height = 13
    Alignment = taRightJustify
    Caption = 'Resource name:'
  end
  object sLabel2: TsLabel
    Left = 102
    Top = 68
    Width = 40
    Height = 13
    Alignment = taRightJustify
    Caption = 'Subject:'
  end
  object sLabel3: TsLabel
    Left = 68
    Top = 14
    Width = 74
    Height = 13
    Alignment = taRightJustify
    Caption = 'Resource type:'
  end
  object sPanel2: TsPanel
    Left = 0
    Top = 100
    Width = 597
    Height = 42
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    ExplicitTop = 119
    DesignSize = (
      597
      42)
    object sButton1: TsButton
      Left = 462
      Top = 5
      Width = 112
      Height = 31
      Anchors = [akRight, akBottom]
      Cancel = True
      Caption = 'Cancel'
      ImageIndex = 27
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 0
      SkinData.SkinSection = 'BUTTON'
    end
    object sButton2: TsButton
      Left = 346
      Top = 5
      Width = 110
      Height = 31
      Anchors = [akRight, akBottom]
      Caption = 'OK'
      Default = True
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
    end
  end
  object edtName: TsEdit
    Left = 148
    Top = 38
    Width = 425
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    SkinData.SkinSection = 'EDIT'
  end
  object edtSubject: TsEdit
    Left = 148
    Top = 65
    Width = 425
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    SkinData.SkinSection = 'EDIT'
  end
  object cbxResourceType: TsComboBox
    Left = 148
    Top = 11
    Width = 425
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Style = csDropDownList
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = -1
    ParentFont = False
    TabOrder = 3
    OnChange = cbxResourceTypeChange
  end
end
