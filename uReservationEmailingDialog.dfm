object FrmReservationEmailingDialog: TFrmReservationEmailingDialog
  Left = 0
  Top = 0
  Caption = 'Reservation emailing dialog'
  ClientHeight = 558
  ClientWidth = 637
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pnlTop: TsPanel
    Left = 0
    Top = 0
    Width = 637
    Height = 129
    Align = alTop
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    DesignSize = (
      637
      129)
    object sLabel1: TsLabel
      Left = 46
      Top = 15
      Width = 88
      Height = 13
      Alignment = taRightJustify
      Caption = 'Email template:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel2: TsLabel
      Left = 78
      Top = 43
      Width = 56
      Height = 13
      Alignment = taRightJustify
      Caption = 'Recipient:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel3: TsLabel
      Left = 61
      Top = 70
      Width = 73
      Height = 13
      Alignment = taRightJustify
      Caption = 'Carbon copy:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object sLabel4: TsLabel
      Left = 88
      Top = 98
      Width = 46
      Height = 13
      Alignment = taRightJustify
      Caption = 'Subject:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object shpTemplate: TShape
      Left = 476
      Top = 14
      Width = 16
      Height = 17
      Anchors = [akTop, akRight]
      Brush.Color = clRed
      Pen.Color = clRed
      Shape = stCircle
      Visible = False
      ExplicitLeft = 504
    end
    object shpTo: TShape
      Left = 476
      Top = 42
      Width = 16
      Height = 17
      Anchors = [akTop, akRight]
      Brush.Color = clRed
      Pen.Color = clRed
      Shape = stCircle
      Visible = False
      ExplicitLeft = 504
    end
    object shpSubject: TShape
      Left = 476
      Top = 97
      Width = 16
      Height = 17
      Anchors = [akTop, akRight]
      Brush.Color = clRed
      Pen.Color = clRed
      Shape = stCircle
      Visible = False
    end
    object edTemplate: TsComboBox
      Left = 144
      Top = 12
      Width = 320
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      Alignment = taLeftJustify
      SkinData.SkinSection = 'COMBOBOX'
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
      TabOrder = 0
      OnCloseUp = edTemplateCloseUp
      ExplicitWidth = 348
    end
    object btnResources: TsButton
      Left = 499
      Top = 10
      Width = 125
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Templates'
      TabOrder = 1
      OnClick = btnResourcesClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 527
    end
    object edTo: TsComboBox
      Left = 144
      Top = 40
      Width = 320
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      Alignment = taLeftJustify
      SkinData.SkinSection = 'COMBOBOX'
      VerticalAlignment = taAlignTop
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = -1
      ParentFont = False
      TabOrder = 2
      OnCloseUp = edToCloseUp
      OnChange = edToChange
      ExplicitWidth = 348
    end
    object edCC: TsComboBox
      Left = 144
      Top = 67
      Width = 320
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      Alignment = taLeftJustify
      SkinData.SkinSection = 'COMBOBOX'
      VerticalAlignment = taAlignTop
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = -1
      ParentFont = False
      TabOrder = 3
      OnCloseUp = edToCloseUp
      OnChange = edToChange
      ExplicitWidth = 348
    end
    object edSubject: TsEdit
      Left = 144
      Top = 95
      Width = 320
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnChange = edSubjectChange
      SkinData.SkinSection = 'EDIT'
    end
  end
  object sPanel2: TsPanel
    Left = 0
    Top = 520
    Width = 637
    Height = 38
    Align = alBottom
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    ExplicitWidth = 750
    object btnOk: TsButton
      AlignWithMargins = True
      Left = 405
      Top = 4
      Width = 111
      Height = 30
      Align = alRight
      Caption = 'Send'
      Default = True
      Enabled = False
      ModalResult = 1
      TabOrder = 0
      OnClick = btnOkClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 518
    end
    object btnEdit: TsButton
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 111
      Height = 30
      Align = alLeft
      Caption = 'Edit text'
      Enabled = False
      TabOrder = 1
      OnClick = btnEditClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnCancel: TsButton
      AlignWithMargins = True
      Left = 522
      Top = 4
      Width = 111
      Height = 30
      Align = alRight
      Caption = 'Cancel'
      Enabled = False
      ModalResult = 2
      TabOrder = 2
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 635
    end
  end
  object WebBrowser: TWebBrowser
    Left = 0
    Top = 129
    Width = 637
    Height = 391
    Align = alClient
    TabOrder = 2
    ExplicitLeft = 95
    ExplicitTop = 256
    ExplicitWidth = 300
    ExplicitHeight = 150
    ControlData = {
      4C000000D6410000692800000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object FormStore: TcxPropertiesStore
    Components = <
      item
        Component = Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Position'
          'Top'
          'Width')
      end>
    StorageName = 'Software\Roomer\FormStatus\ReservationEmailingDialog'
    StorageType = stRegistry
    Left = 423
    Top = 328
  end
end
