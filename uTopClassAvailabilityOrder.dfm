inherited FrmTopClassAvailabilityOrder: TFrmTopClassAvailabilityOrder
  Caption = 'Top-Class Availability Order'
  ClientHeight = 451
  ClientWidth = 662
  Font.Height = -11
  OnCreate = FormCreate
  OnShow = FormShow
  ExplicitWidth = 678
  ExplicitHeight = 490
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 431
    Width = 662
    ExplicitTop = 433
    ExplicitWidth = 644
  end
  object panBtn: TsPanel [1]
    Left = 0
    Top = 398
    Width = 662
    Height = 33
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    ExplicitTop = 392
    object BtnOk: TsButton
      AlignWithMargins = True
      Left = 481
      Top = 3
      Width = 86
      Height = 27
      Hint = 'Apply and close'
      Align = alRight
      Caption = 'OK'
      Default = True
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 0
      OnClick = BtnOkClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 462
      ExplicitTop = 4
      ExplicitHeight = 25
    end
    object btnCancel: TsButton
      AlignWithMargins = True
      Left = 573
      Top = 3
      Width = 86
      Height = 27
      Hint = 'Cancel'
      Align = alRight
      Cancel = True
      Caption = 'Cancel'
      Default = True
      ImageIndex = 4
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 554
      ExplicitTop = 4
      ExplicitHeight = 25
    end
  end
  object sPanel1: TsPanel [2]
    Left = 0
    Top = 0
    Width = 662
    Height = 398
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitWidth = 644
    ExplicitHeight = 433
    object pnlOrder: TsPanel
      Left = 0
      Top = 0
      Width = 45
      Height = 398
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      ExplicitHeight = 433
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
      Width = 617
      Height = 398
      Align = alClient
      Color = clWhite
      Columns = <
        item
          Caption = 'Top Class'
          Width = 100
        end
        item
          AutoSize = True
          Caption = 'Description'
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
      ExplicitWidth = 599
      ExplicitHeight = 433
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = frmBaseRoomerForm.Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Top'
          'Width'
          'Position')
      end>
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 464
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
