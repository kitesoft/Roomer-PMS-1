object fmWatchPropertiesLegacy: TfmWatchPropertiesLegacy
  Left = 236
  Top = 155
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'ScripterStudio Watch Properties'
  ClientHeight = 78
  ClientWidth = 328
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnShow = FormShow
  DesignSize = (
    328
    78)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 7
    Top = 8
    Width = 54
    Height = 13
    Caption = '&Expression:'
  end
  object edExpression: TEdit
    Left = 66
    Top = 6
    Width = 257
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
  end
  object chEnabled: TCheckBox
    Left = 8
    Top = 37
    Width = 97
    Height = 17
    Caption = 'Enabled'
    TabOrder = 1
  end
  object btOk: TBitBtn
    Left = 167
    Top = 47
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'OK'
    Default = True
    ModalResult = 1
    NumGlyphs = 2
    TabOrder = 2
    OnClick = btOkClick
  end
  object btCancel: TBitBtn
    Left = 247
    Top = 47
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    NumGlyphs = 2
    TabOrder = 3
  end
end
