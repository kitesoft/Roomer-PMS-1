inherited FrmOptInMessage: TFrmOptInMessage
  Caption = 'Not opted in'
  ClientHeight = 245
  ClientWidth = 603
  ParentFont = False
  Font.Height = -13
  Font.Name = 'Calibri'
  OnShow = FormShow
  ExplicitWidth = 609
  ExplicitHeight = 274
  DesignSize = (
    603
    245)
  PixelsPerInch = 96
  TextHeight = 15
  object lblPleaseRead: THTMLabel [0]
    AlignWithMargins = True
    Left = 15
    Top = 15
    Width = 573
    Height = 117
    Margins.Left = 15
    Margins.Top = 15
    Margins.Right = 15
    Margins.Bottom = 50
    Align = alClient
    HTMLText.Strings = (
      
        '<B><FONT size="12">{PLEASE_NOTE}</FONT></B><BR><BR>&nbsp;&nbsp;&' +
        'nbsp;{MESSAGE_1}<br>&nbsp;&nbsp;&nbsp;{MESSAGE_2}<BR><BR>{FROM_R' +
        'OOMER}')
    Transparent = True
    Version = '1.9.2.7'
    ExplicitLeft = 10
    ExplicitTop = 10
    ExplicitHeight = 180
  end
  inherited sbStatusBar: TsStatusBar
    Top = 225
    Width = 603
    ExplicitTop = 225
    ExplicitWidth = 603
  end
  inherited pnlButtons: TsPanel
    Top = 182
    Width = 603
    TabOrder = 3
    ExplicitTop = 182
    ExplicitWidth = 603
    inherited btnOK: TsButton
      Left = 287
      ExplicitLeft = 287
    end
    inherited btnCancel: TsButton
      Left = 393
      ExplicitLeft = 393
    end
    inherited btnClose: TsButton
      Left = 499
      ExplicitLeft = 499
    end
  end
  object lblLink: TLinkLabel [3]
    Left = 8
    Top = 157
    Width = 112
    Height = 19
    Anchors = [akLeft, akBottom]
    Caption = 
      '<a href="mailto:sales@roomerpms.com?subject={emailSubject}&body=' +
      '{emailBody}">Email Roomer Sales</a>'
    TabOrder = 1
    OnLinkClick = lblLinkLinkClick
  end
  object lblDownload: TLinkLabel [4]
    Left = 166
    Top = 157
    Width = 177
    Height = 19
    Anchors = [akLeft, akBottom]
    Caption = 
      '<a href="http://roomerstore.com/documents/roomer-paycard-agreeme' +
      'nt.pdf">Download Contract Amendment</a>'
    TabOrder = 2
    OnLinkClick = lblLinkLinkClick
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
