object frmHomedate: TfrmHomedate
  Left = 1288
  Top = 335
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Jump to date'
  ClientHeight = 80
  ClientWidth = 212
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  GlassFrame.Enabled = True
  KeyPreview = True
  OldCreateOrder = False
  Position = poDefault
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TsPanel
    Left = 0
    Top = 0
    Width = 212
    Height = 80
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object dtHome: TcxDateEdit
      Left = 0
      Top = 0
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Align = alTop
      AutoSize = False
      ParentFont = False
      Properties.Alignment.Horz = taCenter
      Properties.AutoSelect = False
      Properties.DateButtons = []
      Properties.ImmediatePost = True
      Properties.SaveTime = False
      Properties.ShowOnlyValidDates = True
      Properties.ShowTime = False
      Properties.ValidationOptions = []
      Properties.OnValidate = dtHomePropertiesValidate
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -30
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      TabOrder = 0
      OnKeyDown = dtHomeKeyDown
      ExplicitTop = -1
      Height = 47
      Width = 212
    end
    object sPanel1: TsPanel
      Left = 0
      Top = 47
      Width = 212
      Height = 33
      Align = alBottom
      TabOrder = 1
      SkinData.SkinSection = 'PANEL'
      DesignSize = (
        212
        33)
      object Button2: TsButton
        Left = 52
        Top = 4
        Width = 74
        Height = 25
        Anchors = [akTop, akRight]
        Caption = 'OK'
        ImageIndex = 82
        Images = DImages.PngImageList1
        TabOrder = 0
        OnClick = Button2Click
        SkinData.SkinSection = 'BUTTON'
      end
      object Button1: TsButton
        Left = 132
        Top = 4
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        Cancel = True
        Caption = 'Cancel'
        ImageIndex = 10
        Images = DImages.PngImageList1
        ModalResult = 8
        TabOrder = 1
        OnClick = Button1Click
        SkinData.SkinSection = 'BUTTON'
      end
    end
  end
end
