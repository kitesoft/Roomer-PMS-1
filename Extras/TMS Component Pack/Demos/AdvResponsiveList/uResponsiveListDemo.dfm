object Form1: TForm1
  Left = 0
  Top = 0
  Anchors = [akLeft, akTop, akRight, akBottom]
  Caption = 'TAdvResponsiveList Demo'
  ClientHeight = 345
  ClientWidth = 256
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    256
    345)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 20
    Width = 33
    Height = 13
    Caption = 'Car list'
  end
  object Label2: TLabel
    Left = 34
    Top = 311
    Width = 158
    Height = 26
    Anchors = [akLeft, akBottom]
    Caption = 'Resize the form to see effect on the responsive list'
    WordWrap = True
  end
  object AdvResponsiveList1: TAdvResponsiveList
    Left = 32
    Top = 39
    Width = 193
    Height = 266
    Cursor = crDefault
    HorzScrollBar.Range = 171
    HorzScrollBar.Tracking = True
    VertScrollBar.Range = 447
    VertScrollBar.Tracking = True
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    BorderColor = clNone
    Conditions = <
      item
        Columns = 1
        HeightFrom = -1
        ItemHeight = 150
        WidthTo = 250
      end
      item
        Columns = 2
        HeightFrom = -1
        ItemHeight = 150
        WidthFrom = 250
        WidthTo = 500
      end
      item
        Columns = 3
        HeightFrom = -1
        ItemHeight = 150
        WidthFrom = 500
        WidthTo = 750
      end
      item
        Columns = 4
        HeightFrom = -1
        ItemHeight = 150
        WidthFrom = 750
      end>
    Items = <
      item
        Content = 'item 1'
        Visible = True
        ControlName = ''
      end
      item
        Content = 'item 2'
        Visible = True
        ControlName = ''
      end
      item
        Content = 'item 3'
        Visible = True
        ControlName = ''
      end>
    Version = '1.0.0.0'
  end
end
