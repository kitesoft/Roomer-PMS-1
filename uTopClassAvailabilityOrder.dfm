object FrmTopClassAvailabilityOrder: TFrmTopClassAvailabilityOrder
  Left = 0
  Top = 0
  Caption = 'Top-Class Availability Order'
  ClientHeight = 486
  ClientWidth = 644
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object panBtn: TsPanel
    Left = 0
    Top = 453
    Width = 644
    Height = 33
    Align = alBottom
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    ExplicitLeft = -309
    ExplicitTop = 443
    ExplicitWidth = 953
    DesignSize = (
      644
      33)
    object BtnOk: TsButton
      Left = 550
      Top = 4
      Width = 86
      Height = 25
      Hint = 'Apply and close'
      Anchors = [akTop, akRight]
      Caption = 'OK'
      Default = True
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 0
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 859
    end
  end
  object sPanel1: TsPanel
    Left = 0
    Top = 0
    Width = 644
    Height = 453
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitLeft = 240
    ExplicitTop = 240
    ExplicitWidth = 185
    ExplicitHeight = 41
    object sPanel2: TsPanel
      Left = 0
      Top = 0
      Width = 45
      Height = 453
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      ExplicitLeft = -6
      ExplicitTop = -6
      object btnUp: TsButton
        Left = 5
        Top = 29
        Width = 34
        Height = 33
        Hint = 'Move up / Higher priority'
        Enabled = False
        ImageAlignment = iaCenter
        ImageIndex = 0
        ImageMargins.Top = 5
        Images = DImages.PngImageList32
        TabOrder = 0
        OnClick = btnUpClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnDown: TsButton
        Left = 5
        Top = 68
        Width = 34
        Height = 34
        Hint = 'Move down / Lower priority'
        Enabled = False
        ImageAlignment = iaCenter
        ImageIndex = 1
        ImageMargins.Bottom = 5
        Images = DImages.PngImageList32
        TabOrder = 1
        OnClick = btnDownClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object lvRates: TsListView
      Left = 45
      Top = 0
      Width = 599
      Height = 453
      Align = alClient
      Color = clWhite
      Columns = <
        item
          Caption = 'Top Class'
          Width = 100
        end
        item
          Caption = 'Description'
          Width = 470
        end>
      DragMode = dmAutomatic
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      HideSelection = False
      RowSelect = True
      ParentFont = False
      TabOrder = 1
      ViewStyle = vsReport
      OnChange = lvRatesChange
      OnDragDrop = lvRatesDragDrop
      OnDragOver = lvRatesDragOver
      ExplicitTop = -2
    end
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
    StorageName = 'Software\Roomer\FormStatus\TopClassAvailabilityOrder'
    StorageType = stRegistry
    Left = 512
    Top = 88
  end
end
