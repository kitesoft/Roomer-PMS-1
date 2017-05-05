inherited frmInvoiceObjects: TfrmInvoiceObjects
  Left = 686
  Top = 154
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biMinimize, biMaximize]
  Caption = 'Invoice'
  ClientHeight = 681
  ClientWidth = 1096
  Constraints.MinWidth = 910
  DoubleBuffered = True
  Font.Height = -11
  Menu = MainMenu1
  Position = poDesigned
  Scaled = False
  OnShow = FormShow
  ExplicitWidth = 1112
  ExplicitHeight = 740
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 661
    Width = 1096
    ExplicitTop = 661
    ExplicitWidth = 1096
  end
  object pnlMain: TsPanel [1]
    Left = 0
    Top = 0
    Width = 1096
    Height = 661
    Align = alClient
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object pnlHeader: TsPanel
      Left = 0
      Top = 0
      Width = 1096
      Height = 166
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      DesignSize = (
        1096
        166)
      object clabCurrency: TsLabel
        Left = 661
        Top = 31
        Width = 57
        Height = 13
        Alignment = taRightJustify
        Caption = 'Currency :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabRate: TsLabel
        Left = 685
        Top = 52
        Width = 33
        Height = 13
        Alignment = taRightJustify
        Caption = 'Rate :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabRefrence: TsLabel
        Left = 661
        Top = 101
        Width = 57
        Height = 13
        Alignment = taRightJustify
        Caption = 'Refrence :'
        Color = 15400938
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabInvoice: TsLabel
        Left = 657
        Top = 7
        Width = 56
        Height = 18
        Alignment = taRightJustify
        Caption = 'Invoice'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabRoomGuest: TsLabel
        Left = 644
        Top = 78
        Width = 74
        Height = 13
        Alignment = taRightJustify
        Caption = 'Guest name :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabCustomer: TsLabel
        Left = 2
        Top = 8
        Width = 103
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Customer :'
        Color = 15400938
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabPId: TsLabel
        Left = 2
        Top = 31
        Width = 103
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'ID :'
        Color = 15400938
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabCountry: TsLabel
        Left = 2
        Top = 131
        Width = 103
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Country :'
        Color = 15400938
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabAddress: TsLabel
        Left = 2
        Top = 69
        Width = 103
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Address :'
        Color = 15400938
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object cLabName: TsLabel
        Left = 2
        Top = 48
        Width = 103
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Name :'
        Color = 15400938
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object labTmpStatus: TsLabel
        Left = 719
        Top = 11
        Width = 4
        Height = 13
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object clabForeignCurrency: TsLabel
        Left = 616
        Top = 124
        Width = 102
        Height = 13
        Alignment = taRightJustify
        Caption = 'Foreign Currency :'
        ParentFont = False
        Visible = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object edtCurrency: TsEdit
        Left = 724
        Top = 28
        Width = 70
        Height = 20
        AutoSize = False
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 10
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object rgrInvoiceType: TsRadioGroup
        Left = 368
        Top = 4
        Width = 189
        Height = 151
        Caption = 'Invoice header method'
        ParentBackground = False
        TabOrder = 9
        SkinData.SkinSection = 'GROUPBOX'
        ItemIndex = 1
        Items.Strings = (
          'Customer'
          'Reservation Customer'
          'RoomGuest'
          'Last Saved '
          'Free Text'
          'Cash')
      end
      object edtRate: TsEdit
        Left = 724
        Top = 49
        Width = 70
        Height = 20
        AutoSize = False
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 12
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object edtInvRefrence: TsEdit
        Left = 724
        Top = 101
        Width = 160
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 30
        ParentFont = False
        TabOrder = 15
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object btnGetCurrency: TsButton
        Left = 795
        Top = 28
        Width = 90
        Height = 20
        Caption = 'Get..'
        TabOrder = 11
        SkinData.SkinSection = 'BUTTON'
      end
      object btnGetRate: TsButton
        Left = 795
        Top = 49
        Width = 90
        Height = 20
        Caption = 'Get..'
        TabOrder = 13
        SkinData.SkinSection = 'BUTTON'
      end
      object edtRoomGuest: TsEdit
        Left = 724
        Top = 78
        Width = 160
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 14
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object edtCustomer: TsEdit
        Left = 111
        Top = 8
        Width = 93
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 15
        ParentFont = False
        TabOrder = 0
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object edtPersonalId: TsEdit
        Left = 111
        Top = 30
        Width = 253
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 15
        ParentFont = False
        TabOrder = 3
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object edtName: TsEdit
        Left = 111
        Top = 48
        Width = 253
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object edtAddress1: TsEdit
        Left = 111
        Top = 68
        Width = 253
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object edtAddress2: TsEdit
        Left = 111
        Top = 88
        Width = 253
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object edtAddress3: TsEdit
        Left = 111
        Top = 108
        Width = 253
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object edtAddress4: TsEdit
        Left = 111
        Top = 131
        Width = 253
        Height = 17
        AutoSize = False
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object btnClearAddresses: TsButton
        Left = 237
        Top = 6
        Width = 126
        Height = 17
        Caption = 'Clear addresses'
        TabOrder = 2
        SkinData.SkinSection = 'BUTTON'
      end
      object btnExit: TcxButton
        Left = 929
        Top = 2
        Width = 161
        Height = 44
        Hint = 'Close form'
        Anchors = [akTop, akRight]
        Caption = 'Close'
        LookAndFeel.NativeStyle = False
        ModalResult = 1
        OptionsImage.ImageIndex = 4
        OptionsImage.Images = DImages.cxLargeImagesFlat
        ParentShowHint = False
        ShowHint = True
        SpeedButtonOptions.Flat = True
        TabOrder = 17
        WordWrap = True
      end
      object btnInvoice: TcxButton
        Left = 929
        Top = 96
        Width = 161
        Height = 41
        Action = actPrintInvoice
        Anchors = [akTop, akRight]
        Caption = 'Pay and Print'
        LookAndFeel.NativeStyle = False
        OptionsImage.ImageIndex = 59
        OptionsImage.Images = DImages.cxLargeImagesFlat
        ParentShowHint = False
        ShowHint = True
        SpeedButtonOptions.Flat = True
        TabOrder = 19
        WordWrap = True
      end
      object btnProforma: TcxButton
        Left = 929
        Top = 49
        Width = 161
        Height = 41
        Action = actPrintProforma
        Anchors = [akTop, akRight]
        LookAndFeel.NativeStyle = False
        OptionsImage.ImageIndex = 3
        OptionsImage.Images = DImages.cxLargeImagesFlat
        ParentShowHint = False
        ShowHint = True
        SpeedButtonOptions.Flat = True
        TabOrder = 18
        WordWrap = True
      end
      object edtForeignCurrency: TsEdit
        Left = 724
        Top = 124
        Width = 105
        Height = 17
        Alignment = taRightJustify
        AutoSize = False
        BorderStyle = bsNone
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 16
        Text = '0'
        Visible = False
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object chkShowPackage: TsCheckBox
        Left = 724
        Top = 143
        Width = 119
        Height = 17
        Caption = 'Package on invoice'
        Checked = True
        State = cbChecked
        TabOrder = 20
        SkinData.SkinSection = 'CHECKBOX'
        ImgChecked = 0
        ImgUnchecked = 0
      end
      object btnGetCustomer: TsButton
        Left = 204
        Top = 6
        Width = 27
        Height = 17
        Caption = '...'
        TabOrder = 1
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object pnlDetails: TsPanel
      Left = 0
      Top = 166
      Width = 1096
      Height = 495
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object pnlBottom: TsPanel
        Left = 0
        Top = 343
        Width = 1096
        Height = 152
        Align = alBottom
        BevelOuter = bvLowered
        ParentColor = True
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object memExtraText: TMemo
          Left = 1
          Top = 1
          Width = 336
          Height = 150
          Align = alLeft
          BevelInner = bvNone
          BevelOuter = bvNone
          BorderStyle = bsNone
          Color = clWhite
          Font.Charset = ANSI_CHARSET
          Font.Color = 16384
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
        end
        object pnlTotals: TsPanel
          Left = 337
          Top = 1
          Width = 256
          Height = 150
          Align = alLeft
          ParentBackground = False
          ParentColor = True
          TabOrder = 1
          SkinData.SkinSection = 'PANEL'
          object clabTotalwoVAT: TsLabel
            Left = 7
            Top = 9
            Width = 124
            Height = 13
            Alignment = taRightJustify
            AutoSize = False
            Caption = 'Total w/o VAT :'
            ParentFont = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
          end
          object clavVAT: TsLabel
            Left = 7
            Top = 29
            Width = 124
            Height = 13
            Alignment = taRightJustify
            AutoSize = False
            Caption = 'VAT :'
            ParentFont = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
          end
          object clabInvoiceTotal: TsLabel
            Left = 7
            Top = 49
            Width = 124
            Height = 13
            Alignment = taRightJustify
            AutoSize = False
            Caption = 'Invoice total :'
            ParentFont = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
          end
          object clabDownpayments: TsLabel
            Left = 7
            Top = 69
            Width = 124
            Height = 13
            Alignment = taRightJustify
            AutoSize = False
            Caption = 'Down payments :'
            ParentFont = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
          end
          object clabBalance: TsLabel
            Left = 7
            Top = 89
            Width = 124
            Height = 13
            Alignment = taRightJustify
            AutoSize = False
            Caption = 'Balance :'
            ParentFont = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
          end
          object edtTotal: TsEdit
            Left = 139
            Top = 6
            Width = 105
            Height = 17
            Alignment = taRightJustify
            AutoSize = False
            BorderStyle = bsNone
            Color = clWhite
            Font.Charset = ANSI_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            TabOrder = 0
            SkinData.SkinSection = 'EDIT'
            BoundLabel.Font.Charset = DEFAULT_CHARSET
            BoundLabel.Font.Color = clWindowText
            BoundLabel.Font.Height = -13
            BoundLabel.Font.Name = 'Tahoma'
            BoundLabel.Font.Style = []
          end
          object edtVat: TsEdit
            Left = 139
            Top = 26
            Width = 105
            Height = 17
            Alignment = taRightJustify
            AutoSize = False
            BorderStyle = bsNone
            Color = clWhite
            Font.Charset = ANSI_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            TabOrder = 1
            SkinData.SkinSection = 'EDIT'
            BoundLabel.Font.Charset = DEFAULT_CHARSET
            BoundLabel.Font.Color = clWindowText
            BoundLabel.Font.Height = -13
            BoundLabel.Font.Name = 'Tahoma'
            BoundLabel.Font.Style = []
          end
          object edtInvoiceTotal: TsEdit
            Left = 139
            Top = 46
            Width = 105
            Height = 17
            Alignment = taRightJustify
            AutoSize = False
            BorderStyle = bsNone
            Color = clWhite
            Font.Charset = ANSI_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            TabOrder = 2
            SkinData.SkinSection = 'EDIT'
            BoundLabel.Font.Charset = DEFAULT_CHARSET
            BoundLabel.Font.Color = clWindowText
            BoundLabel.Font.Height = -13
            BoundLabel.Font.Name = 'Tahoma'
            BoundLabel.Font.Style = []
          end
          object edtDownPayments: TsEdit
            Left = 139
            Top = 66
            Width = 105
            Height = 17
            Alignment = taRightJustify
            AutoSize = False
            BorderStyle = bsNone
            Color = clWhite
            Font.Charset = ANSI_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            TabOrder = 3
            SkinData.SkinSection = 'EDIT'
            BoundLabel.Font.Charset = DEFAULT_CHARSET
            BoundLabel.Font.Color = clWindowText
            BoundLabel.Font.Height = -13
            BoundLabel.Font.Name = 'Tahoma'
            BoundLabel.Font.Style = []
          end
          object edtBalance: TsEdit
            Left = 139
            Top = 86
            Width = 105
            Height = 17
            Alignment = taRightJustify
            AutoSize = False
            BorderStyle = bsNone
            Color = clWhite
            Font.Charset = ANSI_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            TabOrder = 4
            SkinData.SkinSection = 'EDIT'
            BoundLabel.Font.Charset = DEFAULT_CHARSET
            BoundLabel.Font.Color = clWindowText
            BoundLabel.Font.Height = -13
            BoundLabel.Font.Name = 'Tahoma'
            BoundLabel.Font.Style = []
          end
          object grbInclutedTaxes: TsGroupBox
            Left = 16
            Top = 110
            Width = 228
            Height = 36
            Caption = 'Included taxes'
            TabOrder = 5
            SkinData.SkinSection = 'GROUPBOX'
            object labLodgingTaxISK: TsLabel
              Left = 12
              Top = 16
              Width = 22
              Height = 13
              Caption = '0,00'
            end
            object labLodgingTaxNights: TsLabel
              Left = 192
              Top = 16
              Width = 22
              Height = 13
              Caption = '0,00'
            end
            object labTaxNights: TsLabel
              Left = 95
              Top = 16
              Width = 53
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'units :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
            end
            object ClabLodgingTaxCurrency: TsLabel
              Left = 77
              Top = 16
              Width = 19
              Height = 13
              Alignment = taRightJustify
              Caption = 'ISK'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
            end
          end
        end
        object pnlPayments: TsPanel
          Left = 593
          Top = 1
          Width = 502
          Height = 150
          Align = alClient
          Caption = 'pnlPayments'
          TabOrder = 2
          SkinData.SkinSection = 'PANEL'
          object sPanel3: TsPanel
            Left = 1
            Top = 1
            Width = 500
            Height = 20
            Align = alTop
            TabOrder = 0
            SkinData.SkinSection = 'PANEL'
            object labPayments: TsLabel
              Left = 9
              Top = 2
              Width = 84
              Height = 13
              Caption = 'Down payments :'
            end
          end
          object grPayments: TcxGrid
            Left = 1
            Top = 21
            Width = 500
            Height = 128
            Align = alClient
            DragMode = dmAutomatic
            TabOrder = 1
            LookAndFeel.NativeStyle = False
            object tvPayments: TcxGridDBTableView
              Navigator.Buttons.CustomButtons = <>
              DataController.DataSource = dsPaymentObjects
              DataController.Summary.DefaultGroupSummaryItems = <>
              DataController.Summary.FooterSummaryItems = <>
              DataController.Summary.SummaryGroups = <>
              OptionsData.CancelOnExit = False
              OptionsData.Deleting = False
              OptionsData.DeletingConfirmation = False
              OptionsData.Editing = False
              OptionsData.Inserting = False
              OptionsView.GroupByBox = False
              object tvPaymentsPayDate: TcxGridDBColumn
                Caption = 'Date'
                DataBinding.FieldName = 'PayDate'
                Width = 75
              end
              object tvPaymentsPayType: TcxGridDBColumn
                Caption = 'Type'
                DataBinding.FieldName = 'PayTypeCode'
                Width = 78
              end
              object tvPaymentsAmount: TcxGridDBColumn
                Caption = 'Native Amount'
                DataBinding.FieldName = 'Amount'
                Width = 84
              end
              object tvPaymentsDescription: TcxGridDBColumn
                DataBinding.FieldName = 'Description'
                Width = 164
              end
              object tvPaymentsPayGroup: TcxGridDBColumn
                Caption = 'Paygroup'
                OnGetDisplayText = tvPaymentsPayGroupGetDisplayText
                Width = 70
              end
              object tvPaymentsMemo: TcxGridDBColumn
                DataBinding.FieldName = 'Memo'
                PropertiesClassName = 'TcxMemoProperties'
                Options.Editing = False
                Width = 128
              end
              object tvPaymentsconfirmDate: TcxGridDBColumn
                DataBinding.FieldName = 'confirmDate'
              end
            end
            object lvPayments: TcxGridLevel
              GridView = tvPayments
            end
          end
        end
      end
      object pnlButtons: TsPanel
        Left = 0
        Top = 0
        Width = 1096
        Height = 91
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 2
        SkinData.SkinSection = 'PANEL'
        DesignSize = (
          1096
          91)
        object btnRoomToTemp: TsButton
          Left = 10
          Top = 4
          Width = 130
          Height = 40
          Action = actRRtoTemp
          TabOrder = 0
          SkinData.SkinSection = 'BUTTON'
        end
        object btnAddItem: TsButton
          Left = 10
          Top = 47
          Width = 130
          Height = 40
          Action = actAddLine
          TabOrder = 1
          SkinData.SkinSection = 'BUTTON'
        end
        object btnItemToTmp: TsButton
          Left = 141
          Top = 4
          Width = 130
          Height = 40
          Action = actItemToTemp
          TabOrder = 2
          SkinData.SkinSection = 'BUTTON'
        end
        object btnRemoveItem: TsButton
          Left = 141
          Top = 47
          Width = 130
          Height = 40
          Action = actDelLine
          TabOrder = 3
          SkinData.SkinSection = 'BUTTON'
        end
        object btnMoveItem: TsButton
          Left = 272
          Top = 4
          Width = 130
          Height = 40
          Action = actItemToGroupInvoice
          Caption = 'Move sales item'
          DropDownMenu = mnuMoveItem
          Style = bsSplitButton
          TabOrder = 4
          SkinData.SkinSection = 'BUTTON'
        end
        object btnMoveRoom: TsButton
          Left = 403
          Top = 4
          Width = 130
          Height = 40
          Caption = 'Move room item'
          DropDownMenu = mnuMoveRoom
          Enabled = False
          Style = bsSplitButton
          TabOrder = 6
          SkinData.SkinSection = 'BUTTON'
        end
        object btnRemoveLodgingTax2: TsButton
          Left = 403
          Top = 47
          Width = 130
          Height = 40
          Caption = 'Toggle lodging tax'
          TabOrder = 7
          SkinData.SkinSection = 'BUTTON'
        end
        object btnReservationNotes: TsButton
          Left = 272
          Top = 47
          Width = 130
          Height = 40
          Caption = 'Reservation notes'
          TabOrder = 5
          SkinData.SkinSection = 'BUTTON'
        end
        object btnSaveChanges: TsButton
          Left = 892
          Top = 4
          Width = 134
          Height = 40
          Anchors = [akTop, akRight]
          Caption = 'Save changes'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ImageIndex = 2
          Images = DImages.cxSmallImagesFlat
          ParentFont = False
          TabOrder = 8
          Visible = False
          SkinData.CustomFont = True
          SkinData.ColorTone = clRed
        end
        object pnlPaymentButtons: TsPanel
          Left = 629
          Top = 47
          Width = 396
          Height = 40
          Alignment = taLeftJustify
          Anchors = [akTop, akRight]
          AutoSize = True
          BevelOuter = bvNone
          TabOrder = 9
          SkinData.SkinSection = 'PANEL'
          object btnAddDownPayment: TsButton
            Left = 0
            Top = 0
            Width = 131
            Height = 40
            Action = actDownPayment
            Align = alRight
            TabOrder = 0
            SkinData.SkinSection = 'BUTTON'
          end
          object btnEditDownPayment: TsButton
            Left = 131
            Top = 0
            Width = 131
            Height = 40
            Align = alRight
            Caption = 'Edit Down Payment'
            TabOrder = 1
            SkinData.SkinSection = 'BUTTON'
          end
          object btnDeleteDownpayment: TsButton
            Left = 262
            Top = 0
            Width = 134
            Height = 40
            Align = alRight
            Caption = 'Delete Down Payment'
            TabOrder = 2
            SkinData.SkinSection = 'BUTTON'
          end
        end
      end
      object pnlLines: TsPanel
        Left = 0
        Top = 91
        Width = 1096
        Height = 252
        Align = alClient
        BevelOuter = bvNone
        Caption = 'pnlLines'
        Padding.Left = 10
        Padding.Top = 5
        Padding.Right = 10
        Padding.Bottom = 5
        TabOrder = 1
        SkinData.SkinSection = 'PANEL'
        object tsInvocieIndex: TsTabControl
          Left = 10
          Top = 5
          Width = 1076
          Height = 242
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          MultiLine = True
          ParentFont = False
          RaggedRight = True
          TabOrder = 0
          TabPosition = tpRight
          Tabs.Strings = (
            '1'
            '2'
            '3'
            '4'
            '5'
            '6'
            '7'
            '8'
            '9')
          TabIndex = 0
          TabWidth = 25
          OnChange = tsInvocieIndexChange
          OnDockOver = tsInvocieIndexDockOver
          OnDragDrop = tsInvocieIndexDragDrop
          object tlInvoiceLines: TcxDBTreeList
            Left = 4
            Top = 4
            Width = 1048
            Height = 234
            Hint = ''
            Align = alClient
            Bands = <
              item
                Caption.Text = 'Band1'
              end>
            DataController.DataSource = dsInvoicelinesObjects
            DataController.KeyField = 'ID'
            DragCursor = crDrag
            DragMode = dmAutomatic
            Font.Charset = ANSI_CHARSET
            Font.Color = clBlack
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            Navigator.Buttons.CustomButtons = <>
            OptionsSelection.CellSelect = False
            OptionsView.Footer = True
            ParentFont = False
            RootValue = 0
            TabOrder = 0
            OnDataChanged = tlInvoiceLinesDataChanged
            ExplicitLeft = 3
            ExplicitTop = 5
            object cxDBTreeList1cxDBTreeListColumn7: TcxDBTreeListColumn
              PropertiesClassName = 'TcxCheckBoxProperties'
              Caption.AlignHorz = taCenter
              Caption.Text = 'Selected'
              MinWidth = 25
              Width = 25
              Position.ColIndex = 0
              Position.RowIndex = 0
              Position.BandIndex = 0
              Summary.FooterSummaryItems = <>
              Summary.GroupFooterSummaryItems = <>
            end
            object cxDBTreeList1cxDBTreeListColumn1: TcxDBTreeListColumn
              DataBinding.FieldName = 'Description'
              Options.Editing = False
              Width = 407
              Position.ColIndex = 2
              Position.RowIndex = 0
              Position.BandIndex = 0
              Summary.FooterSummaryItems = <>
              Summary.GroupFooterSummaryItems = <>
            end
            object cxDBTreeList1cxDBTreeListColumn2: TcxDBTreeListColumn
              DataBinding.FieldName = 'Itemtype'
              Options.Editing = False
              Width = 100
              Position.ColIndex = 1
              Position.RowIndex = 0
              Position.BandIndex = 0
              Summary.FooterSummaryItems = <>
              Summary.GroupFooterSummaryItems = <>
            end
            object cxDBTreeList1cxDBTreeListColumn3: TcxDBTreeListColumn
              DataBinding.FieldName = 'PurchaseDate'
              Options.Editing = False
              Width = 100
              Position.ColIndex = 3
              Position.RowIndex = 0
              Position.BandIndex = 0
              Summary.FooterSummaryItems = <>
              Summary.GroupFooterSummaryItems = <>
            end
            object cxDBTreeList1cxDBTreeListColumn4: TcxDBTreeListColumn
              PropertiesClassName = 'TcxCalcEditProperties'
              DataBinding.FieldName = 'Quantity'
              Options.Editing = False
              Width = 100
              Position.ColIndex = 4
              Position.RowIndex = 0
              Position.BandIndex = 0
              Summary.FooterSummaryItems = <>
              Summary.GroupFooterSummaryItems = <>
            end
            object cxDBTreeList1cxDBTreeListColumn5: TcxDBTreeListColumn
              PropertiesClassName = 'TcxCurrencyEditProperties'
              DataBinding.FieldName = 'Nettoprice'
              Options.Editing = False
              Width = 100
              Position.ColIndex = 5
              Position.RowIndex = 0
              Position.BandIndex = 0
              Summary.FooterSummaryItems = <>
              Summary.GroupFooterSummaryItems = <>
            end
            object cxDBTreeList1cxDBTreeListColumn6: TcxDBTreeListColumn
              PropertiesClassName = 'TcxCurrencyEditProperties'
              DataBinding.FieldName = 'TotalnetAmount'
              Options.Editing = False
              Width = 100
              Position.ColIndex = 6
              Position.RowIndex = 0
              Position.BandIndex = 0
              Summary.FooterSummaryItems = <
                item
                  AlignHorz = taLeftJustify
                  Kind = skSum
                end>
              Summary.GroupFooterSummaryItems = <>
            end
          end
          object DBGrid1: TDBGrid
            Left = 138
            Top = 96
            Width = 320
            Height = 120
            DataSource = dsInvoicelinesObjects
            TabOrder = 1
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clWindowText
            TitleFont.Height = -11
            TitleFont.Name = 'Tahoma'
            TitleFont.Style = []
            Columns = <
              item
                Expanded = False
                FieldName = 'ID'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'Index_'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'Description'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'Itemtype'
                Visible = True
              end>
          end
        end
      end
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
  object MainMenu1: TMainMenu
    Left = 372
    Top = 304
    object File1: TMenuItem
      Caption = '&File'
      object ExitandSave1: TMenuItem
        Action = actSaveAndExit
        ShortCut = 16465
      end
      object S1: TMenuItem
        Caption = 'Sa&ve'
        ShortCut = 16467
      end
      object Exit1: TMenuItem
        Caption = 'Close'
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object GuestName1: TMenuItem
        Caption = 'Copy Guest name to clipboard'
        ShortCut = 16455
      end
      object Refrence1: TMenuItem
        Caption = 'Copy Refrence to clipboard'
        ShortCut = 16466
      end
    end
    object Invoice2: TMenuItem
      Caption = '&Invoice'
      object Print2: TMenuItem
        Action = actPrintInvoice
        Caption = 'Pay '#39'n Print'
      end
      object PrintProforma1: TMenuItem
        Action = actPrintProforma
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Downpayment1: TMenuItem
        Action = actDownPayment
      end
    end
    object Items1: TMenuItem
      Caption = 'Items'
      object Add1: TMenuItem
        Action = actAddLine
      end
      object Delete1: TMenuItem
        Action = actDelLine
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Removetemporarily1: TMenuItem
        Action = actItemToTemp
      end
      object RemoveRoomRenttemporarity1: TMenuItem
        Action = actRRtoTemp
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object SendItemToGroupInvoice: TMenuItem
        Action = actItemToGroupInvoice
      end
    end
  end
  object GridImages: TImageList
    Left = 933
    Top = 328
    Bitmap = {
      494C010101000500040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      0000000000007B7B7B0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF00000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      00007B7B7B0000FFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF000000
      000000000000000000000000000000FFFF000000000000000000000000007B7B
      7B0000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF000000000000000000000000000000000000000000000000000000000000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000FFFF0000FFFF0000FFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000FFFF0000FFFF000000
      000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000
      000000FFFF0000FFFF0000FFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007B7B
      7B00000000000000000000FFFF0000FFFF0000FFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007B7B7B0000FF
      FF000000000000000000000000000000000000000000000000000000000000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B7B7B0000FFFF000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      000000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF00000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      00000000000000FFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FF7F000000000000DE79000000000000
      AE73000000000000D6E7000000000000EE2F000000000000FC1F000000000000
      F80F00000000000080080000000000001001000000000000F01F000000000000
      F83F000000000000E477000000000000CF6B0000000000009E75000000000000
      BE7B000000000000FEFF00000000000000000000000000000000000000000000
      000000000000}
  end
  object alInvoices: TActionList
    Left = 136
    Top = 300
    object actSaveAndExit: TAction
      Category = 'File'
      Caption = 'Save and close'
    end
    object actPrintInvoice: TAction
      Category = 'Invoice'
      Caption = 'To invoice'
    end
    object actPrintProforma: TAction
      Category = 'Invoice'
      Caption = 'Print proforma'
      ImageIndex = 30
    end
    object actInvoiceProperties: TAction
      Caption = 'Properties'
    end
    object actDownPayment: TAction
      Category = 'Invoice'
      Caption = 'Add Down payment'
    end
    object actInfo: TAction
      Category = 'Invoice'
      Caption = 'Reservation notes'
    end
    object actAddLine: TAction
      Category = 'Lines'
      Caption = 'Add item'
      ShortCut = 113
      OnExecute = actAddLineExecute
    end
    object actDelLine: TAction
      Category = 'Lines'
      Caption = 'Remove item'
      ShortCut = 16430
      OnExecute = actDelLineExecute
      OnUpdate = actDelLineUpdate
    end
    object actRRtoTemp: TAction
      Category = 'Lines'
      Caption = 'Room to temp'
      ShortCut = 115
    end
    object actItemToTemp: TAction
      Category = 'Lines'
      Caption = 'Item to temp'
      ShortCut = 114
    end
    object actItemToGroupInvoice: TAction
      Category = 'Lines'
      Caption = 'Item to groupinvoice'
      ShortCut = 116
    end
    object actCompressLines: TAction
      Category = 'Lines'
      Caption = 'Compress items'
    end
    object actAddPackage: TAction
      Caption = 'Add Package'
    end
    object Action2: TAction
      Category = 'Lines'
      Caption = 'Action2'
    end
  end
  object StoreMain: TcxPropertiesStore
    Components = <
      item
        Component = actInvoiceProperties
        Properties.Strings = (
          'AutoCheck'
          'Caption'
          'Category'
          'Checked'
          'Enabled'
          'GroupIndex'
          'HelpContext'
          'HelpKeyword'
          'HelpType'
          'Hint'
          'ImageIndex'
          'Name'
          'SecondaryShortCuts'
          'ShortCut'
          'Tag'
          'Visible')
      end
      item
        Component = chkShowPackage
        Properties.Strings = (
          'Checked')
      end
      item
        Component = Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Position'
          'Top'
          'Width')
      end>
    StorageName = 'Software\Roomer\FormStatus\Invoice'
    StorageType = stRegistry
    Left = 448
    Top = 312
  end
  object rptDsLines: TfrxDBDataset
    UserName = 'rptDsLines'
    CloseDataSource = False
    BCDToCurrency = False
    Left = 1048
    Top = 144
  end
  object mnuMoveItem: TPopupMenu
    Left = 312
    Top = 176
    object T1: TMenuItem
      Caption = 'To group invoice'
    end
    object mnuMoveItemToSpecifiedRoomAndInvoiceIndex: TMenuItem
      Caption = 'To room invoice'
    end
    object N6: TMenuItem
      Caption = '-'
    end
    object mnuMoveItemToAnyOtherRoomAndInvoiceIndex: TMenuItem
      Caption = 'Transfer'
      object TMenuItem
      end
    end
  end
  object mnuMoveRoom: TPopupMenu
    Left = 464
    Top = 176
    object mnuMoveRoomRentFromRoomInvoiceToGroup: TMenuItem
      Caption = 'To group invoice'
    end
    object mnuMoveRoomRentFromGroupToNormalRoomInvoice: TMenuItem
      Caption = 'To room invoice'
    end
    object N7: TMenuItem
      Caption = '-'
    end
    object mnuTransferRoomRentToDifferentRoom: TMenuItem
      Caption = 'Transfer'
      object TMenuItem
      end
    end
  end
  object mnuInvoiceIndex: TPopupMenu
    Left = 936
    Top = 400
    object I1: TMenuItem
      Tag = -1
      Caption = 'Invoice index'
      Enabled = False
    end
    object N5: TMenuItem
      Tag = -1
      Caption = '-'
      Enabled = False
    end
    object N01: TMenuItem
      Caption = '1'
    end
    object N11: TMenuItem
      Tag = 1
      Caption = '2'
    end
    object N31: TMenuItem
      Tag = 2
      Caption = '3'
    end
    object N41: TMenuItem
      Tag = 3
      Caption = '4'
    end
    object N51: TMenuItem
      Tag = 4
      Caption = '5'
    end
    object N61: TMenuItem
      Tag = 5
      Caption = '6'
    end
    object N71: TMenuItem
      Tag = 6
      Caption = '7'
    end
    object N81: TMenuItem
      Tag = 7
      Caption = '8'
    end
    object N91: TMenuItem
      Tag = 8
      Caption = '9'
    end
    object N12: TMenuItem
      Tag = 9
      Caption = '10'
    end
  end
  object odsPayments: TObjectDataSet
    Left = 672
    Top = 584
  end
  object dsPaymentObjects: TDataSource
    DataSet = odsPayments
    Left = 736
    Top = 584
  end
  object odsInvoicelines: TObjectDataSet
    BeforeDelete = odsInvoicelinesBeforeDelete
    OnNewRecord = odsInvoicelinesNewRecord
    Left = 784
    Top = 320
    object odsInvoicelinesID: TIntegerField
      FieldName = 'ID'
    end
    object odsInvoicelinesDescription: TStringField
      FieldName = 'Description'
    end
    object odsInvoicelinesItemtype: TStringField
      FieldName = 'Itemtype'
    end
    object odsInvoicelinesIndex_: TIntegerField
      FieldName = 'Index_'
    end
  end
  object dsInvoicelinesObjects: TDataSource
    DataSet = odsInvoicelines
    Left = 784
    Top = 368
  end
end
