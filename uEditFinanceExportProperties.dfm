object frmEditFinanceExportProperties: TfrmEditFinanceExportProperties
  Left = 0
  Top = 0
  Caption = 'Edit Finance Export Properties'
  ClientHeight = 165
  ClientWidth = 432
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object sLabel1: TsLabel
    Left = 54
    Top = 19
    Width = 199
    Height = 19
    Alignment = taRightJustify
    Caption = 'Roomer invoice number:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
  end
  object lblExternalSystemsInvoiceNumber: TsLabel
    Left = 12
    Top = 56
    Width = 241
    Height = 19
    Alignment = taRightJustify
    Caption = 'External system'#39's invoice number:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object __lblRoomerNumber: TsLabel
    Left = 264
    Top = 19
    Width = 10
    Height = 19
    Caption = '0'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
  end
  object lblExportableToFinance: TsLabel
    Left = 98
    Top = 84
    Width = 155
    Height = 19
    Alignment = taRightJustify
    Caption = 'Exportable to finance:'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object edtExternalSystemsInvoiceNumber: TsEdit
    Left = 264
    Top = 53
    Width = 145
    Height = 27
    Alignment = taRightJustify
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    NumbersOnly = True
    ParentFont = False
    TabOrder = 0
  end
  object cbxExportableToFinance: TsCheckBox
    Left = 264
    Top = 86
    Width = 20
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    ImgChecked = 0
    ImgUnchecked = 0
  end
  object pnlButtons: TsPanel
    Left = 0
    Top = 128
    Width = 432
    Height = 37
    Align = alBottom
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    object btnCancel: TsButton
      AlignWithMargins = True
      Left = 343
      Top = 4
      Width = 85
      Height = 29
      Hint = 'Cancel and close'
      Align = alRight
      Cancel = True
      Caption = 'Cancel'
      ImageIndex = 4
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 0
      SkinData.SkinSection = 'BUTTON'
    end
    object BtnOk: TsButton
      AlignWithMargins = True
      Left = 252
      Top = 4
      Width = 85
      Height = 29
      Hint = 'Apply and close'
      Align = alRight
      Caption = 'OK'
      Default = True
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
    end
  end
end
