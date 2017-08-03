object FrmOptInMessage: TFrmOptInMessage
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Not opted in'
  ClientHeight = 245
  ClientWidth = 603
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  DesignSize = (
    603
    245)
  PixelsPerInch = 96
  TextHeight = 15
  object lblPleaseRead: THTMLabel
    AlignWithMargins = True
    Left = 15
    Top = 15
    Width = 573
    Height = 180
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
    Version = '1.9.2.8'
    ExplicitLeft = 10
    ExplicitTop = 10
  end
  object btnOk: TsButton
    Left = 513
    Top = 212
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
    ExplicitTop = 276
  end
  object lblLink: TLinkLabel
    Left = 8
    Top = 218
    Width = 112
    Height = 19
    Anchors = [akLeft, akBottom]
    Caption = 
      '<a href="mailto:sales@roomerpms.com?subject={emailSubject}&body=' +
      '{emailBody}">Email Roomer Sales</a>'
    TabOrder = 1
    OnLinkClick = lblLinkLinkClick
  end
  object lblDownload: TLinkLabel
    Left = 182
    Top = 218
    Width = 177
    Height = 19
    Anchors = [akLeft, akBottom]
    Caption = 
      '<a href="http://roomerstore.com/documents/roomer-paycard-agreeme' +
      'nt.pdf">Download Contract Amendment</a>'
    TabOrder = 2
    OnLinkClick = lblLinkLinkClick
  end
end
