inherited frmBusyMessage: TfrmBusyMessage
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = 'Busy ...'
  ClientHeight = 150
  ClientWidth = 325
  Font.Height = -11
  FormStyle = fsStayOnTop
  ExplicitWidth = 331
  ExplicitHeight = 179
  PixelsPerInch = 96
  TextHeight = 13
  object __lblMessage: TsLabel [0]
    AlignWithMargins = True
    Left = 3
    Top = 47
    Width = 319
    Height = 80
    Align = alClient
    Alignment = taCenter
    AutoSize = False
    ParentFont = False
    WordWrap = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ExplicitLeft = -2
    ExplicitHeight = 122
  end
  object __lblHeadline: TsLabel [1]
    AlignWithMargins = True
    Left = 3
    Top = 10
    Width = 319
    Height = 24
    Margins.Top = 10
    Margins.Bottom = 10
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ExplicitLeft = 8
  end
  inherited sbStatusBar: TsStatusBar
    Top = 130
    Width = 325
    Panels = <
      item
        Style = psOwnerDraw
        Width = 27
      end
      item
        Width = 100
      end
      item
        Style = psOwnerDraw
        Width = 50
      end>
    ExplicitTop = 132
    ExplicitWidth = 325
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 232
    Top = 8
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 8
    Top = 8
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
