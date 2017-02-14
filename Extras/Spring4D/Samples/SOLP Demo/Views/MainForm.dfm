object CustomersView: TCustomersView
  Left = 0
  Top = 0
  Caption = 'CustomersView'
  ClientHeight = 289
  ClientWidth = 554
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 554
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Button1: TButton
      Left = 8
      Top = 10
      Width = 113
      Height = 25
      Caption = 'Load Customers'
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 136
      Top = 14
      Width = 185
      Height = 21
      TabOrder = 1
      TextHint = 'Search by customer id...'
    end
  end
end
