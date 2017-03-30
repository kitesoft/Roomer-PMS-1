object frmInvoice: TfrmInvoice
  Left = 686
  Top = 154
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biMinimize, biMaximize]
  ClientHeight = 681
  ClientWidth = 1096
  Color = clBtnFace
  Constraints.MinWidth = 910
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  Scaled = False
  ShowHint = True
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PANmAIN: TsPanel
    Left = 0
    Top = 0
    Width = 1096
    Height = 662
    Align = alClient
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object lblChangedInvoiceActive: TsLabel
      Left = 0
      Top = 166
      Width = 1096
      Height = 3
      Hint = 'Search Filter Active'
      Align = alTop
      AutoSize = False
      Color = clRed
      ParentColor = False
      ParentFont = False
      Visible = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 15789037
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      UseSkinColor = False
      ExplicitTop = 27
      ExplicitWidth = 1153
    end
    object Panel1: TsPanel
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
        Top = 128
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
        OnDblClick = edtCurrencyDblClick
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
        OnClick = rgrInvoiceTypeClick
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
        OnDblClick = edtRateDblClick
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
        OnClick = edtCurrencyDblClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnGetRate: TsButton
        Left = 795
        Top = 49
        Width = 90
        Height = 20
        Caption = 'Get..'
        TabOrder = 13
        OnClick = edtRateDblClick
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
        OnChange = edtCustomerChange
        OnDblClick = edtCustomerDblClick
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
        OnDblClick = edtCustomerDblClick
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
        Top = 128
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
        OnClick = btnClearAddressesClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnExit: TsButton
        Left = 929
        Top = 5
        Width = 161
        Height = 44
        Hint = 'Close form'
        Anchors = [akTop, akRight]
        Caption = 'Close'
        ImageIndex = 4
        Images = DImages.cxLargeImagesFlat
        ModalResult = 1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 17
        OnClick = btnExitClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnInvoice: TsButton
        Left = 929
        Top = 99
        Width = 161
        Height = 41
        Action = actPrintInvoice
        Anchors = [akTop, akRight]
        Caption = 'Pay and Print'
        ImageIndex = 59
        Images = DImages.cxLargeImagesFlat
        ParentShowHint = False
        ShowHint = True
        TabOrder = 19
        SkinData.SkinSection = 'BUTTON'
      end
      object btnProforma: TsButton
        Left = 929
        Top = 53
        Width = 161
        Height = 41
        Action = actPrintProforma
        Anchors = [akTop, akRight]
        ImageIndex = 3
        Images = DImages.cxLargeImagesFlat
        ParentShowHint = False
        ShowHint = True
        TabOrder = 18
        SkinData.SkinSection = 'BUTTON'
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
        OnChange = edtTotalChange
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
        OnClick = edtCustomerDblClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object sPanel5: TsPanel
      Left = 0
      Top = 169
      Width = 1096
      Height = 493
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object Panel2: TsPanel
        Left = 0
        Top = 341
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
        object sPanel2: TsPanel
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
            OnChange = edtTotalChange
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
            OnChange = edtTotalChange
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
            OnChange = edtTotalChange
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
            OnChange = edtTotalChange
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
            OnChange = edtTotalChange
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
        object TsPanel
          Left = 593
          Top = 1
          Width = 502
          Height = 150
          Align = alClient
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
              OnMouseDown = tvPaymentsMouseDown
              Navigator.Buttons.CustomButtons = <>
              OnCellDblClick = tvPaymentsCellDblClick
              DataController.DataSource = PaymentsDS
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
                DataBinding.FieldName = 'PayType'
                Width = 78
              end
              object tvPaymentsAmount: TcxGridDBColumn
                DataBinding.FieldName = 'Amount'
                Width = 84
              end
              object tvPaymentsDescription: TcxGridDBColumn
                DataBinding.FieldName = 'Description'
                Width = 128
              end
              object tvPaymentsPayGroup: TcxGridDBColumn
                DataBinding.FieldName = 'PayGroup'
                Width = 70
              end
              object tvPaymentsMemo: TcxGridDBColumn
                DataBinding.FieldName = 'Memo'
                PropertiesClassName = 'TcxMemoProperties'
                Options.Editing = False
              end
              object tvPaymentsconfirmDate: TcxGridDBColumn
                DataBinding.FieldName = 'confirmDate'
              end
              object tvPaymentsid: TcxGridDBColumn
                DataBinding.FieldName = 'id'
              end
            end
            object lvPayments: TcxGridLevel
              GridView = tvPayments
            end
          end
        end
      end
      object Panel4: TsPanel
        Left = 0
        Top = 0
        Width = 1096
        Height = 91
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 3
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
          OnClick = btnRemoveLodgingTax2Click
          SkinData.SkinSection = 'BUTTON'
        end
        object btnReservationNotes: TsButton
          Left = 272
          Top = 47
          Width = 130
          Height = 40
          Caption = 'Reservation notes'
          TabOrder = 5
          OnClick = btnReservationNotesClick
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
          OnClick = btnSaveChangesClick
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
          OnResize = pnlPaymentButtonsResize
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
            OnClick = btnEditDownPaymentClick
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
            OnClick = btnDeleteDownpaymentClick
            SkinData.SkinSection = 'BUTTON'
          end
        end
      end
      object sPanel1: TsPanel
        Left = 0
        Top = 91
        Width = 1040
        Height = 250
        Align = alClient
        BevelOuter = bvNone
        Caption = 'sPanel1'
        Padding.Left = 10
        Padding.Top = 5
        Padding.Right = 10
        Padding.Bottom = 5
        TabOrder = 2
        SkinData.SkinSection = 'PANEL'
        object agrLines: TAdvStringGrid
          Left = 10
          Top = 5
          Width = 1020
          Height = 240
          Cursor = crDefault
          Align = alClient
          BevelInner = bvNone
          BevelOuter = bvNone
          BorderStyle = bsNone
          ColCount = 7
          DefaultRowHeight = 19
          DrawingStyle = gdsClassic
          FixedCols = 0
          RowCount = 2
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing, goThumbTracking]
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          OnDrawCell = agrLinesDrawCell
          OnGetEditText = agrLinesGetEditText
          OnKeyDown = agrLinesKeyDown
          OnMouseDown = agrLinesMouseDown
          HoverRowCells = [hcNormal, hcSelected]
          OnGetCellColor = agrLinesGetCellColor
          OnGetAlignment = agrLinesGetAlignment
          OnRowChanging = agrLinesRowChanging
          OnDblClickCell = agrLinesDblClickCell
          OnCanEditCell = agrLinesCanEditCell
          OnCellValidate = agrLinesCellValidate
          OnCheckBoxClick = agrLinesCheckBoxClick
          OnColumnSize = agrLinesColumnSize
          ActiveCellFont.Charset = DEFAULT_CHARSET
          ActiveCellFont.Color = clWindowText
          ActiveCellFont.Height = -13
          ActiveCellFont.Name = 'Tahoma'
          ActiveCellFont.Style = [fsBold]
          ControlLook.FixedGradientHoverFrom = clGray
          ControlLook.FixedGradientHoverTo = clWhite
          ControlLook.FixedGradientDownFrom = clGray
          ControlLook.FixedGradientDownTo = clSilver
          ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
          ControlLook.DropDownHeader.Font.Color = clWindowText
          ControlLook.DropDownHeader.Font.Height = -13
          ControlLook.DropDownHeader.Font.Name = 'Tahoma'
          ControlLook.DropDownHeader.Font.Style = []
          ControlLook.DropDownHeader.Visible = True
          ControlLook.DropDownHeader.Buttons = <>
          ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
          ControlLook.DropDownFooter.Font.Color = clWindowText
          ControlLook.DropDownFooter.Font.Height = -13
          ControlLook.DropDownFooter.Font.Name = 'Tahoma'
          ControlLook.DropDownFooter.Font.Style = []
          ControlLook.DropDownFooter.Visible = True
          ControlLook.DropDownFooter.Buttons = <>
          Filter = <>
          FilterDropDown.Font.Charset = DEFAULT_CHARSET
          FilterDropDown.Font.Color = clWindowText
          FilterDropDown.Font.Height = -13
          FilterDropDown.Font.Name = 'Tahoma'
          FilterDropDown.Font.Style = []
          FilterDropDownClear = '(All)'
          FilterEdit.TypeNames.Strings = (
            'Starts with'
            'Ends with'
            'Contains'
            'Not contains'
            'Equal'
            'Not equal'
            'Larger than'
            'Smaller than'
            'Clear')
          FixedColWidth = 24
          FixedRowHeight = 19
          FixedFont.Charset = DEFAULT_CHARSET
          FixedFont.Color = clWindowText
          FixedFont.Height = -13
          FixedFont.Name = 'Tahoma'
          FixedFont.Style = [fsBold]
          FloatFormat = '%.2f'
          HoverButtons.Buttons = <>
          HoverButtons.Position = hbLeftFromColumnLeft
          HTMLSettings.ImageFolder = 'images'
          HTMLSettings.ImageBaseName = 'img'
          PrintSettings.DateFormat = 'dd/mm/yyyy'
          PrintSettings.Font.Charset = DEFAULT_CHARSET
          PrintSettings.Font.Color = clWindowText
          PrintSettings.Font.Height = -13
          PrintSettings.Font.Name = 'Tahoma'
          PrintSettings.Font.Style = []
          PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
          PrintSettings.FixedFont.Color = clWindowText
          PrintSettings.FixedFont.Height = -13
          PrintSettings.FixedFont.Name = 'Tahoma'
          PrintSettings.FixedFont.Style = []
          PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
          PrintSettings.HeaderFont.Color = clWindowText
          PrintSettings.HeaderFont.Height = -13
          PrintSettings.HeaderFont.Name = 'Tahoma'
          PrintSettings.HeaderFont.Style = []
          PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
          PrintSettings.FooterFont.Color = clWindowText
          PrintSettings.FooterFont.Height = -13
          PrintSettings.FooterFont.Name = 'Tahoma'
          PrintSettings.FooterFont.Style = []
          PrintSettings.PageNumSep = '/'
          ScrollWidth = 21
          SearchFooter.FindNextCaption = 'Find &next'
          SearchFooter.FindPrevCaption = 'Find &previous'
          SearchFooter.Font.Charset = DEFAULT_CHARSET
          SearchFooter.Font.Color = clWindowText
          SearchFooter.Font.Height = -13
          SearchFooter.Font.Name = 'Tahoma'
          SearchFooter.Font.Style = []
          SearchFooter.HighLightCaption = 'Highlight'
          SearchFooter.HintClose = 'Close'
          SearchFooter.HintFindNext = 'Find next occurrence'
          SearchFooter.HintFindPrev = 'Find previous occurrence'
          SearchFooter.HintHighlight = 'Highlight occurrences'
          SearchFooter.MatchCaseCaption = 'Match case'
          SearchFooter.ResultFormat = '(%d of %d)'
          SortSettings.DefaultFormat = ssAutomatic
          Version = '8.2.5.2'
          ColWidths = (
            24
            91
            348
            88
            83
            91
            31)
        end
      end
      object sPanel4: TsPanel
        AlignWithMargins = True
        Left = 1043
        Top = 94
        Width = 50
        Height = 244
        Align = alRight
        TabOrder = 1
        object pnlInvoiceIndex0: TsPanel
          Left = 3
          Top = 4
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '1 '
          Color = 16764840
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex0: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Brush.Color = clRed
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 1
            ExplicitTop = 1
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR0: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Brush.Color = clBlue
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 24
            ExplicitTop = 1
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex1: TsPanel
          Tag = 1
          Left = 3
          Top = 41
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '2 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex1: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 17
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR1: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 27
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex2: TsPanel
          Tag = 2
          Left = 3
          Top = 78
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '3 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex2: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 17
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR2: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 27
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex3: TsPanel
          Tag = 3
          Left = 3
          Top = 115
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '4 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex3: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 17
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR3: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 27
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex4: TsPanel
          Tag = 4
          Left = 3
          Top = 151
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '5 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex4: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 17
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR4: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 27
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex5: TsPanel
          Tag = 5
          Left = 3
          Top = 189
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '6 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex5: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 17
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR5: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 27
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex6: TsPanel
          Tag = 6
          Left = 3
          Top = 226
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '7 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 6
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex6: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 17
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR6: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 27
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex7: TsPanel
          Tag = 7
          Left = 3
          Top = 263
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '8 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex7: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 17
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR7: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 27
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex8: TsPanel
          Tag = 8
          Left = 3
          Top = 300
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '9 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 8
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex8: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 0
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR8: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 27
            ExplicitHeight = 29
          end
        end
        object pnlInvoiceIndex9: TsPanel
          Tag = 9
          Left = 3
          Top = 337
          Width = 42
          Height = 31
          Alignment = taRightJustify
          BevelInner = bvLowered
          Caption = '10 '
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
          OnClick = pnlInvoiceIndex0Click
          OnDragDrop = pnlInvoiceIndex0DragDrop
          OnDragOver = pnlInvoiceIndex0DragOver
          SkinData.CustomColor = True
          SkinData.CustomFont = True
          object shpInvoiceIndex9: TShape
            Left = 2
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 1
            ExplicitTop = 1
            ExplicitHeight = 29
          end
          object shpInvoiceIndexRR9: TShape
            Left = 10
            Top = 2
            Width = 8
            Height = 27
            Align = alLeft
            Pen.Style = psClear
            OnDragDrop = shpInvoiceIndex0DragDrop
            OnDragOver = shpInvoiceIndex0DragOver
            OnMouseUp = shpInvoiceIndex0MouseUp
            ExplicitLeft = 25
            ExplicitTop = 1
            ExplicitHeight = 29
          end
        end
      end
    end
  end
  object FriendlyStatusBar1: TsStatusBar
    Left = 0
    Top = 662
    Width = 1096
    Height = 19
    Panels = <>
    SkinData.SkinSection = 'STATUSBAR'
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
        OnClick = S1Click
      end
      object Exit1: TMenuItem
        Caption = 'Close'
        OnClick = Exit1Click
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
  object act: TActionList
    Left = 136
    Top = 300
    object actSaveAndExit: TAction
      Category = 'File'
      Caption = 'Save and close'
      OnExecute = actSaveAndExitExecute
    end
    object actPrintInvoice: TAction
      Category = 'Invoice'
      Caption = 'To invoice'
      OnExecute = actPrintInvoiceExecute
    end
    object actPrintProforma: TAction
      Category = 'Invoice'
      Caption = 'Print proforma'
      ImageIndex = 30
      OnExecute = actPrintProformaExecute
    end
    object actInvoiceProperties: TAction
      Caption = 'Properties'
    end
    object actDownPayment: TAction
      Category = 'Invoice'
      Caption = 'Add Down payment'
      OnExecute = actDownPaymentExecute
    end
    object actInfo: TAction
      Category = 'Invoice'
      Caption = 'Reservation notes'
      OnExecute = actInfoExecute
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
    end
    object actRRtoTemp: TAction
      Category = 'Lines'
      Caption = 'Room to temp'
      ShortCut = 115
      OnExecute = actRRtoTempExecute
    end
    object actItemToTemp: TAction
      Category = 'Lines'
      Caption = 'Item to temp'
      ShortCut = 114
      OnExecute = actItemToTempExecute
    end
    object actItemToGroupInvoice: TAction
      Category = 'Lines'
      Caption = 'Item to groupinvoice'
      ShortCut = 116
      OnExecute = actItemToGroupInvoiceExecute
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
  object timCloseInvoice: TTimer
    Enabled = False
    Interval = 100
    OnTimer = timCloseInvoiceTimer
    Left = 57
    Top = 405
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
  object PaymentsDS: TDataSource
    DataSet = mPayments
    Left = 320
    Top = 568
  end
  object rptDsLines: TfrxDBDataset
    UserName = 'rptDsLines'
    CloseDataSource = False
    BCDToCurrency = False
    Left = 296
    Top = 304
  end
  object mPayments: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 320
    Top = 512
    object mPaymentsPayDate: TDateField
      FieldName = 'PayDate'
    end
    object mPaymentsPayType: TWideStringField
      FieldName = 'PayType'
    end
    object mPaymentsAmount: TFloatField
      FieldName = 'Amount'
    end
    object mPaymentsDescription: TWideStringField
      FieldName = 'Description'
      Size = 60
    end
    object mPaymentsPayGroup: TWideStringField
      FieldName = 'PayGroup'
    end
    object mPaymentsMemo: TMemoField
      FieldName = 'Memo'
      BlobType = ftMemo
    end
    object mPaymentsconfirmDate: TDateTimeField
      FieldName = 'confirmDate'
    end
    object mPaymentsid: TIntegerField
      FieldName = 'id'
    end
    object mPaymentsInvoiceIndex: TIntegerField
      FieldName = 'InvoiceIndex'
    end
  end
  object mnuMoveItem: TPopupMenu
    OnPopup = mnuMoveItemPopup
    Left = 544
    Top = 336
    object T1: TMenuItem
      Caption = 'To group invoice'
      OnClick = T1Click
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
    OnPopup = mnuMoveRoomPopup
    Left = 448
    Top = 376
    object mnuMoveRoomRentFromRoomInvoiceToGroup: TMenuItem
      Caption = 'To group invoice'
      OnClick = mnuMoveRoomRentFromRoomInvoiceToGroupClick
    end
    object mnuMoveRoomRentFromGroupToNormalRoomInvoice: TMenuItem
      Caption = 'To room invoice'
      OnClick = mnuMoveRoomRentFromGroupToNormalRoomInvoiceClick
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
    Left = 632
    Top = 352
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
      OnClick = N91Click
    end
    object N11: TMenuItem
      Tag = 1
      Caption = '2'
      OnClick = N91Click
    end
    object N31: TMenuItem
      Tag = 2
      Caption = '3'
      OnClick = N91Click
    end
    object N41: TMenuItem
      Tag = 3
      Caption = '4'
      OnClick = N91Click
    end
    object N51: TMenuItem
      Tag = 4
      Caption = '5'
      OnClick = N91Click
    end
    object N61: TMenuItem
      Tag = 5
      Caption = '6'
      OnClick = N91Click
    end
    object N71: TMenuItem
      Tag = 6
      Caption = '7'
      OnClick = N91Click
    end
    object N81: TMenuItem
      Tag = 7
      Caption = '8'
      OnClick = N91Click
    end
    object N91: TMenuItem
      Tag = 8
      Caption = '9'
      OnClick = N91Click
    end
    object N12: TMenuItem
      Tag = 9
      Caption = '10'
    end
  end
  object mRoomRes: TdxMemData
    Indexes = <
      item
        FieldName = 'Room'
        SortOptions = []
      end>
    SortOptions = []
    Left = 152
    Top = 408
    object mRoomResReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mRoomResroomreservation: TIntegerField
      FieldName = 'roomreservation'
    end
    object mRoomResRoom: TStringField
      FieldName = 'Room'
      Size = 10
    end
    object mRoomResRoomType: TStringField
      FieldName = 'RoomType'
      Size = 10
    end
    object mRoomResGuests: TIntegerField
      FieldName = 'Guests'
    end
    object mRoomResAvragePrice: TFloatField
      FieldName = 'AvragePrice'
    end
    object mRoomResRateCount: TIntegerField
      FieldName = 'RateCount'
    end
    object mRoomResRoomDescription: TStringField
      FieldName = 'RoomDescription'
      Size = 30
    end
    object mRoomResRoomTypeDescription: TStringField
      FieldName = 'RoomTypeDescription'
      Size = 30
    end
    object mRoomResArrival: TDateTimeField
      FieldName = 'Arrival'
    end
    object mRoomResDeparture: TDateTimeField
      FieldName = 'Departure'
    end
    object mRoomResChildrenCount: TIntegerField
      FieldName = 'ChildrenCount'
    end
    object mRoomResinfantCount: TIntegerField
      FieldName = 'infantCount'
    end
    object mRoomResPriceCode: TStringField
      FieldName = 'PriceCode'
      Size = 10
    end
    object mRoomResAvrageDiscount: TFloatField
      FieldName = 'AvrageDiscount'
    end
    object mRoomResPackage: TWideStringField
      FieldName = 'Package'
    end
    object mRoomResInvoiceIndex: TIntegerField
      FieldName = 'InvoiceIndex'
    end
    object mRoomResGroupAccount: TBooleanField
      FieldName = 'GroupAccount'
    end
    object mRoomResGuestName: TWideStringField
      FieldName = 'GuestName'
      Size = 60
    end
  end
  object mRoomRates: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 224
    Top = 408
    object mRoomRatesReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mRoomRatesroomreservation: TIntegerField
      FieldName = 'roomreservation'
    end
    object mRoomRatesRoomNumber: TStringField
      FieldName = 'RoomNumber'
      Size = 10
    end
    object mRoomRatesRateDate: TDateTimeField
      FieldName = 'RateDate'
    end
    object mRoomRatesPriceCode: TStringField
      FieldName = 'PriceCode'
      Size = 10
    end
    object mRoomRatesRate: TFloatField
      FieldName = 'Rate'
    end
    object mRoomRatesDiscount: TFloatField
      FieldName = 'Discount'
    end
    object mRoomRatesisPercentage: TBooleanField
      FieldName = 'isPercentage'
    end
    object mRoomRatesShowDiscount: TBooleanField
      FieldName = 'ShowDiscount'
    end
    object mRoomRatesisPaid: TBooleanField
      FieldName = 'isPaid'
    end
    object mRoomRatesDiscountAmount: TFloatField
      FieldName = 'DiscountAmount'
    end
    object mRoomRatesRentAmount: TFloatField
      FieldName = 'RentAmount'
    end
    object mRoomRatesNativeAmount: TFloatField
      FieldName = 'NativeAmount'
    end
    object mRoomRatesGuestName: TWideStringField
      FieldName = 'GuestName'
      Size = 60
    end
  end
end
