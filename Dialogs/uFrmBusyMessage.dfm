object frmBusyMessage: TfrmBusyMessage
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsToolWindow
  ClientHeight = 148
  ClientWidth = 307
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object __lblMessage: TsLabel
    Left = 35
    Top = 40
    Width = 264
    Height = 72
    AutoSize = False
    WordWrap = True
  end
  object __lblHeadline: TsLabel
    Left = 17
    Top = 8
    Width = 282
    Height = 13
    AutoSize = False
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
  end
  object Marquee: TAdvSmoothWin8Marquee
    Left = 0
    Top = 128
    Width = 307
    Height = 20
    AnimationStretchFactor = 1.700000047683716000
    Transparent = True
    Animate = False
    AnimationFactor = 3.000000000000000000
    AnimationStep = 10.000000000000000000
    Fill.Color = clWhite
    Fill.ColorMirror = clNone
    Fill.ColorMirrorTo = clNone
    Fill.GradientType = gtSolid
    Fill.GradientMirrorType = gtSolid
    Fill.BorderColor = 9470064
    Fill.Rounding = 0
    Fill.ShadowOffset = 0
    Fill.Glow = gmNone
    Bullets.Color = 16764840
    Align = alBottom
    TMSStyle = 0
  end
  object StoreMain: TcxPropertiesStore
    Active = False
    Components = <
      item
        Properties.Strings = (
          'Down')
      end
      item
        Properties.Strings = (
          'Down')
      end
      item
        Properties.Strings = (
          'Down')
      end
      item
        Properties.Strings = (
          'ItemIndex')
      end
      item
        Properties.Strings = (
          'ItemIndex')
      end
      item
        Properties.Strings = (
          'ItemIndex')
      end
      item
        Component = Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Top'
          'Width')
      end
      item
        Properties.Strings = (
          'Height')
      end
      item
        Properties.Strings = (
          'Left')
      end
      item
        Properties.Strings = (
          'SkinName')
      end>
    StorageName = 'Software\Roomer\FormStatus\BusyMessage'
    StorageType = stRegistry
    Left = 15
    Top = 32
  end
end
