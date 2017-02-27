object fmRecurrenceSelectionForm: TfmRecurrenceSelectionForm
  Left = 217
  Top = 476
  BorderStyle = bsDialog
  Caption = 'fmRecurrenceSelectionForm'
  ClientHeight = 143
  ClientWidth = 261
  Color = clBtnFace
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object Image: TImage
    Left = 8
    Top = 4
    Width = 49
    Height = 49
    Center = True
  end
  object lbMessage: TcxLabel
    Left = 67
    Top = 6
    AutoSize = False
    Caption = 'lbMessage'
    Properties.WordWrap = True
    Transparent = True
    Height = 44
    Width = 186
  end
  object pnlControls: TPanel
    Left = 0
    Top = 59
    Width = 261
    Height = 84
    Align = alBottom
    BevelOuter = bvNone
    FullRepaint = False
    ParentColor = True
    TabOrder = 0
    object btnCancel: TcxButton
      Left = 136
      Top = 53
      Width = 90
      Height = 23
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 0
    end
    object rbSeries: TcxRadioButton
      Left = 56
      Top = 25
      Width = 193
      Height = 17
      Caption = 'rbSeries'
      TabOrder = 1
      Transparent = True
    end
    object rbOccurrence: TcxRadioButton
      Left = 56
      Top = 2
      Width = 201
      Height = 17
      Caption = 'rbOccurrence'
      Checked = True
      TabOrder = 2
      TabStop = True
      Transparent = True
    end
    object btnOk: TcxButton
      Left = 36
      Top = 53
      Width = 90
      Height = 23
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 3
    end
  end
end
