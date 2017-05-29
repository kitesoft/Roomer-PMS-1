object FrmPayCardView: TFrmPayCardView
  Left = 0
  Top = 0
  Caption = 'View pay-card information'
  ClientHeight = 591
  ClientWidth = 976
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object sPanel1: TsPanel
    Left = 0
    Top = 0
    Width = 976
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
  end
  object sPanel2: TsPanel
    Left = 0
    Top = 41
    Width = 976
    Height = 550
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object browser: TsWebBrowser
      Left = 0
      Top = 0
      Width = 976
      Height = 550
      Align = alClient
      TabOrder = 0
      ExplicitTop = 6
      ExplicitWidth = 871
      ExplicitHeight = 475
      ControlData = {
        4C000000DF640000D83800000000000000000000000000000000000000000000
        000000004C000000000000000000000001000000E0D057007335CF11AE690800
        2B2E126208000000000000004C0000000114020000000000C000000000000046
        8000000000000000000000000000000000000000000000000000000000000000
        00000000000000000100000000000000000000000000000000000000}
    end
  end
end
