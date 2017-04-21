inherited frmBaseRoomerDialogForm: TfrmBaseRoomerDialogForm
  BorderStyle = bsDialog
  Caption = 'Base Roomer dialog form'
  ClientHeight = 360
  ClientWidth = 655
  ParentFont = True
  ExplicitWidth = 661
  ExplicitHeight = 389
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 340
    Width = 655
    ExplicitTop = 340
    ExplicitWidth = 655
  end
  object pnlButtons: TsPanel [1]
    Left = 0
    Top = 297
    Width = 655
    Height = 43
    Align = alBottom
    Color = 14540253
    ParentBackground = False
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object btnOK: TsButton
      AlignWithMargins = True
      Left = 445
      Top = 4
      Width = 100
      Height = 35
      Align = alRight
      Caption = 'OK'
      Default = True
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 0
      SkinData.SkinSection = 'BUTTON'
      ExplicitTop = 2
    end
    object btnCancel: TsButton
      AlignWithMargins = True
      Left = 551
      Top = 4
      Width = 100
      Height = 35
      Align = alRight
      Cancel = True
      Caption = 'Cancel'
      ImageIndex = 27
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
      ExplicitTop = 2
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
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
