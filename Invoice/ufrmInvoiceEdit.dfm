inherited frmInvoiceEdit: TfrmInvoiceEdit
  Left = 686
  Top = 154
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biMinimize, biMaximize]
  Caption = 'Invoice'
  ClientHeight = 697
  ClientWidth = 1158
  Constraints.MinWidth = 1112
  DoubleBuffered = True
  Font.Height = -11
  Menu = MainMenu1
  Position = poDesigned
  Scaled = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  ExplicitWidth = 1174
  ExplicitHeight = 756
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 677
    Width = 1158
    ExplicitTop = 677
    ExplicitWidth = 1158
  end
  object pnlMain: TsPanel [1]
    Left = 0
    Top = 0
    Width = 1158
    Height = 677
    Align = alClient
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object pnlHead: TsPanel
      Left = 0
      Top = 0
      Width = 1158
      Height = 189
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      DesignSize = (
        1158
        189)
      object clabCurrency: TsLabel
        Left = 616
        Top = 120
        Width = 102
        Height = 13
        Alignment = taRightJustify
        Caption = 'Invoice Currency :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object clabRefrence: TsLabel
        Left = 654
        Top = 53
        Width = 64
        Height = 13
        Alignment = taRightJustify
        Caption = 'Reference :'
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
        Top = 31
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
      object lblResNr: TsLabel
        Left = 673
        Top = 77
        Width = 45
        Height = 13
        Alignment = taRightJustify
        Caption = 'Res. nr :'
        Color = 15400938
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object edtInvRefrence: TsLabel
        Left = 725
        Top = 53
        Width = 160
        Height = 17
        AutoSize = False
        Caption = '-'
        Color = clWhite
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object edtRoomGuest: TsLabel
        Left = 725
        Top = 31
        Width = 160
        Height = 17
        AutoSize = False
        Caption = '-'
        Color = clWhite
        ParentColor = False
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object edResNr: TsLabel
        Left = 725
        Top = 77
        Width = 160
        Height = 17
        AutoSize = False
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object btnExit: TsButton
        Left = 991
        Top = 4
        Width = 161
        Height = 41
        Hint = 'Close form'
        Anchors = [akTop, akRight]
        Caption = 'Close'
        ImageIndex = 4
        Images = DImages.cxLargeImagesFlat
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = btnExitClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnInvoice: TsButton
        Left = 991
        Top = 93
        Width = 161
        Height = 41
        Action = actPrintInvoice
        Anchors = [akTop, akRight]
        Caption = 'Pay and Print'
        ImageIndex = 59
        Images = DImages.cxLargeImagesFlat
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        SkinData.SkinSection = 'BUTTON'
      end
      object btnProforma: TsButton
        Left = 991
        Top = 48
        Width = 161
        Height = 41
        Action = actPrintProforma
        Anchors = [akTop, akRight]
        ImageIndex = 3
        Images = DImages.cxLargeImagesFlat
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        SkinData.SkinSection = 'BUTTON'
      end
      object btnSaveChanges: TsButton
        Left = 991
        Top = 137
        Width = 161
        Height = 41
        Action = actSave
        Anchors = [akTop, akRight]
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Images = DImages.cxSmallImagesFlat
        ParentFont = False
        TabOrder = 4
        SkinData.CustomFont = True
        SkinData.ColorTone = clRed
      end
      object gbxHeader: TsGroupBox
        Left = 3
        Top = 3
        Width = 567
        Height = 178
        Caption = 'Invoice Header'
        TabOrder = 0
        object clabCustomer: TsLabel
          Left = 2
          Top = 17
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
          Top = 40
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
          Top = 155
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
          Top = 86
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
          Top = 63
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
        object rgrInvoiceAddressType: TsRadioGroup
          Left = 368
          Top = 10
          Width = 189
          Height = 165
          Caption = 'Invoice header method'
          ParentBackground = False
          TabOrder = 0
          OnClick = rgrInvoiceAddressTypeClick
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
        object edtCustomer: TsEdit
          Left = 111
          Top = 14
          Width = 93
          Height = 21
          AutoSize = False
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          MaxLength = 15
          ParentFont = False
          TabOrder = 1
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
          Top = 37
          Width = 253
          Height = 21
          AutoSize = False
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          MaxLength = 15
          ParentFont = False
          ReadOnly = True
          TabOrder = 2
          OnChange = edtPersonalIdChange
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
          Top = 60
          Width = 253
          Height = 21
          AutoSize = False
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnChange = edtPersonalIdChange
          SkinData.SkinSection = 'EDIT'
          BoundLabel.Font.Charset = DEFAULT_CHARSET
          BoundLabel.Font.Color = clWindowText
          BoundLabel.Font.Height = -13
          BoundLabel.Font.Name = 'Tahoma'
          BoundLabel.Font.Style = []
        end
        object edtAddress1: TsEdit
          Left = 111
          Top = 83
          Width = 253
          Height = 21
          AutoSize = False
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnChange = edtPersonalIdChange
          SkinData.SkinSection = 'EDIT'
          BoundLabel.Font.Charset = DEFAULT_CHARSET
          BoundLabel.Font.Color = clWindowText
          BoundLabel.Font.Height = -13
          BoundLabel.Font.Name = 'Tahoma'
          BoundLabel.Font.Style = []
        end
        object edtAddress2: TsEdit
          Left = 111
          Top = 106
          Width = 253
          Height = 21
          AutoSize = False
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          OnChange = edtPersonalIdChange
          SkinData.SkinSection = 'EDIT'
          BoundLabel.Font.Charset = DEFAULT_CHARSET
          BoundLabel.Font.Color = clWindowText
          BoundLabel.Font.Height = -13
          BoundLabel.Font.Name = 'Tahoma'
          BoundLabel.Font.Style = []
        end
        object edtAddress3: TsEdit
          Left = 111
          Top = 129
          Width = 253
          Height = 21
          AutoSize = False
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          OnChange = edtPersonalIdChange
          SkinData.SkinSection = 'EDIT'
          BoundLabel.Font.Charset = DEFAULT_CHARSET
          BoundLabel.Font.Color = clWindowText
          BoundLabel.Font.Height = -13
          BoundLabel.Font.Name = 'Tahoma'
          BoundLabel.Font.Style = []
        end
        object edtAddress4: TsEdit
          Left = 111
          Top = 152
          Width = 253
          Height = 21
          AutoSize = False
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 7
          OnChange = edtPersonalIdChange
          SkinData.SkinSection = 'EDIT'
          BoundLabel.Font.Charset = DEFAULT_CHARSET
          BoundLabel.Font.Color = clWindowText
          BoundLabel.Font.Height = -13
          BoundLabel.Font.Name = 'Tahoma'
          BoundLabel.Font.Style = []
        end
        object btnClearAddresses: TsButton
          Left = 237
          Top = 14
          Width = 126
          Height = 21
          Caption = 'Clear addresses'
          TabOrder = 8
          OnClick = btnClearAddressesClick
          SkinData.SkinSection = 'BUTTON'
        end
        object btnGetCustomer: TsButton
          Left = 206
          Top = 14
          Width = 27
          Height = 21
          Caption = '...'
          TabOrder = 9
          OnClick = edtCustomerDblClick
          SkinData.SkinSection = 'BUTTON'
        end
      end
      inline fraInvoiceCurrency: TfraCurrencyPanel
        Left = 725
        Top = 116
        Width = 206
        Height = 21
        TabOrder = 5
        ExplicitLeft = 725
        ExplicitTop = 116
        ExplicitHeight = 21
        inherited pnlCurrency: TsPanel
          Height = 21
          Align = alClient
          ExplicitHeight = 21
          inherited lblCurrencyName: TsLabel
            Width = 140
            Height = 15
          end
          inherited edCurrencyCode: TsEdit
            Height = 20
          end
          inherited btnGetCurrency: TsButton
            Height = 21
            ExplicitHeight = 21
          end
        end
      end
    end
    object pnlLnes: TsPanel
      Left = 0
      Top = 189
      Width = 1158
      Height = 488
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object pnlTotalsAndPayments: TsPanel
        Left = 0
        Top = 279
        Width = 1158
        Height = 209
        Align = alBottom
        BevelOuter = bvLowered
        ParentColor = True
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object splExtraInfo: TsSplitter
          Left = 526
          Top = 1
          Height = 207
          Color = clHighlightText
          ParentColor = False
          SkinData.SkinSection = 'SPLITTER'
          SkinData.OuterEffects.Visibility = ovAlways
          ExplicitLeft = 400
          ExplicitHeight = 193
        end
        object pnlExtraInfo: TsPanel
          Left = 1
          Top = 1
          Width = 525
          Height = 207
          Align = alLeft
          TabOrder = 0
          object memExtraText: TMemo
            Left = 1
            Top = 1
            Width = 267
            Height = 205
            Align = alClient
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
            OnChange = memExtraTextChange
          end
          object pnlTotals: TsPanel
            Left = 268
            Top = 1
            Width = 256
            Height = 205
            Align = alRight
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
            object edtTotalWOVat: TsEdit
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
              AlignWithMargins = True
              Left = 4
              Top = 165
              Width = 248
              Height = 36
              Align = alBottom
              Caption = 'Included taxes'
              TabOrder = 5
              SkinData.SkinSection = 'GROUPBOX'
              object labLodgingTax: TsLabel
                Left = 40
                Top = 16
                Width = 85
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = '0,00'
              end
              object labLodgingTaxNights: TsLabel
                Left = 199
                Top = 16
                Width = 41
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = '0'
              end
              object labTaxNights: TsLabel
                Left = 140
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
            end
            object pnlTotalsInCurrency: TsPanel
              AlignWithMargins = True
              Left = 4
              Top = 112
              Width = 248
              Height = 50
              Margins.Top = 0
              Margins.Bottom = 0
              Align = alBottom
              TabOrder = 6
              object lbTotalInCurrency: TsLabel
                Left = 22
                Top = 8
                Width = 105
                Height = 13
                Alignment = taRightJustify
                Caption = 'Total  in Currency :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
              end
              object lbBalanceInCurrency: TsLabel
                Left = 10
                Top = 29
                Width = 117
                Height = 13
                Alignment = taRightJustify
                Caption = 'Balance in Currency :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
              end
              object edtTotalInCurrency: TsEdit
                Left = 135
                Top = 4
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
              object edtBalanceInCurrency: TsEdit
                Left = 135
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
            end
          end
        end
        object pnlPayments: TsPanel
          Left = 532
          Top = 1
          Width = 625
          Height = 207
          Align = alClient
          Caption = 'pnlPayments'
          TabOrder = 1
          SkinData.SkinSection = 'PANEL'
          object sPanel3: TsPanel
            Left = 1
            Top = 1
            Width = 623
            Height = 20
            Align = alTop
            TabOrder = 0
            SkinData.SkinSection = 'PANEL'
            object labPayments: TsLabel
              Left = 5
              Top = 1
              Width = 97
              Height = 13
              Caption = 'Down payments :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
            end
          end
          object grPayments: TcxGrid
            Left = 1
            Top = 21
            Width = 623
            Height = 146
            Align = alClient
            DragMode = dmAutomatic
            TabOrder = 1
            LookAndFeel.NativeStyle = False
            object tvPayments: TcxGridDBTableView
              OnMouseDown = tvPaymentsMouseDown
              Navigator.Buttons.CustomButtons = <>
              DataController.DataSource = PaymentsDS
              DataController.Summary.DefaultGroupSummaryItems = <>
              DataController.Summary.FooterSummaryItems = <>
              DataController.Summary.SummaryGroups = <>
              OptionsData.CancelOnExit = False
              OptionsData.Deleting = False
              OptionsData.DeletingConfirmation = False
              OptionsData.Editing = False
              OptionsData.Inserting = False
              OptionsView.ColumnAutoWidth = True
              OptionsView.GroupByBox = False
              object tvPaymentsPayDate: TcxGridDBColumn
                Caption = 'Date'
                DataBinding.FieldName = 'PayDate'
                Width = 75
              end
              object tvPaymentsCCCharged: TcxGridDBColumn
                Caption = 'Charged on CC'
                DataBinding.FieldName = 'ChargedOnCC'
                PropertiesClassName = 'TcxCheckBoxProperties'
                HeaderAlignmentHorz = taCenter
                Options.Editing = False
                Width = 83
              end
              object tvPaymentsPayType: TcxGridDBColumn
                Caption = 'Type'
                DataBinding.FieldName = 'PayType'
                Width = 78
              end
              object tvPaymentsCurrency: TcxGridDBColumn
                DataBinding.FieldName = 'Currency'
                Width = 50
              end
              object tvPaymentsCurrencyAmount: TcxGridDBColumn
                DataBinding.FieldName = 'CurrencyAmount'
                PropertiesClassName = 'TcxCurrencyEditProperties'
                OnGetProperties = tvPaymentsCurrencyAmountGetProperties
              end
              object tvPaymentNativeAmount: TcxGridDBColumn
                DataBinding.FieldName = 'NativeAmount'
                PropertiesClassName = 'TcxCurrencyEditProperties'
                OnGetProperties = tvPaymentNativeAmountGetProperties
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
                Visible = False
              end
              object tvPaymentsid: TcxGridDBColumn
                DataBinding.FieldName = 'id'
                Visible = False
              end
              object tvPaymentsRecId: TcxGridDBColumn
                DataBinding.FieldName = 'RecId'
                Visible = False
              end
              object tvPaymentsInvoiceIndex: TcxGridDBColumn
                DataBinding.FieldName = 'InvoiceIndex'
                Visible = False
              end
              object tvPaymentsPaycardTraceIndex: TcxGridDBColumn
                DataBinding.FieldName = 'PaycardTraceIndex'
                Visible = False
              end
            end
            object lvPayments: TcxGridLevel
              GridView = tvPayments
            end
          end
          object pnlPaymentButtons: TsPanel
            Left = 1
            Top = 167
            Width = 623
            Height = 39
            Align = alBottom
            TabOrder = 2
            object btnAddDownPayment: TsButton
              AlignWithMargins = True
              Left = 125
              Top = 3
              Width = 119
              Height = 33
              Margins.Top = 2
              Margins.Bottom = 2
              Action = actAddDownPayment
              Align = alRight
              TabOrder = 0
              SkinData.SkinSection = 'BUTTON'
            end
            object btnRevertDownpayment: TsButton
              AlignWithMargins = True
              Left = 500
              Top = 3
              Width = 119
              Height = 33
              Margins.Top = 2
              Margins.Bottom = 2
              Action = actRevertDownpayment
              Align = alRight
              TabOrder = 3
              SkinData.SkinSection = 'BUTTON'
            end
            object btnEditDownpayment: TsButton
              AlignWithMargins = True
              Left = 250
              Top = 3
              Width = 119
              Height = 33
              Margins.Top = 2
              Margins.Bottom = 2
              Action = actEditDownPayment
              Align = alRight
              TabOrder = 1
              SkinData.SkinSection = 'BUTTON'
            end
            object btnDeleteDownpayment: TsButton
              AlignWithMargins = True
              Left = 375
              Top = 3
              Width = 119
              Height = 33
              Margins.Top = 2
              Margins.Bottom = 2
              Action = actDeleteDownPayment
              Align = alRight
              TabOrder = 2
              SkinData.SkinSection = 'BUTTON'
            end
          end
        end
      end
      object pnlLineButtons: TsPanel
        Left = 0
        Top = 0
        Width = 1158
        Height = 49
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 3
        SkinData.SkinSection = 'PANEL'
        object btnAddRoom: TsButton
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 130
          Height = 43
          Action = actAddRoom
          Align = alLeft
          TabOrder = 0
          SkinData.SkinSection = 'BUTTON'
        end
        object btnMoveRoom: TsButton
          AlignWithMargins = True
          Left = 139
          Top = 3
          Width = 130
          Height = 43
          Align = alLeft
          Caption = 'Move Room'
          DropDownMenu = mnuMoveRoom
          Enabled = False
          Style = bsSplitButton
          TabOrder = 1
          OnClick = btnClickDropDown
          SkinData.SkinSection = 'BUTTON'
        end
        object btnAddItem: TsButton
          AlignWithMargins = True
          Left = 275
          Top = 3
          Width = 130
          Height = 43
          Action = actAddLine
          Align = alLeft
          TabOrder = 2
          SkinData.SkinSection = 'BUTTON'
        end
        object btnMoveItem: TsButton
          AlignWithMargins = True
          Left = 411
          Top = 3
          Width = 130
          Height = 43
          Align = alLeft
          Caption = 'Move Item'
          DropDownMenu = mnuMoveItem
          Style = bsSplitButton
          TabOrder = 3
          OnClick = btnClickDropDown
          SkinData.SkinSection = 'BUTTON'
        end
        object btnRemoveSelected: TsButton
          AlignWithMargins = True
          Left = 547
          Top = 3
          Width = 130
          Height = 43
          Action = actRemoveSelected
          Align = alLeft
          TabOrder = 4
          SkinData.SkinSection = 'BUTTON'
        end
        object btnToggleLodgingTax: TsButton
          AlignWithMargins = True
          Left = 683
          Top = 3
          Width = 130
          Height = 43
          Action = actToggleLodgingTax
          Align = alLeft
          TabOrder = 5
          SkinData.SkinSection = 'BUTTON'
        end
        object btnReservationNotes: TsButton
          AlignWithMargins = True
          Left = 955
          Top = 3
          Width = 130
          Height = 43
          Align = alLeft
          Caption = 'Reservation notes'
          TabOrder = 6
          OnClick = btnReservationNotesClick
          SkinData.SkinSection = 'BUTTON'
        end
        object btnShowOnInvoice: TsButton
          AlignWithMargins = True
          Left = 819
          Top = 3
          Width = 130
          Height = 43
          Align = alLeft
          Caption = 'Show or Hide on Invoice'
          DropDownMenu = mnuShowOnInvoice
          Style = bsSplitButton
          TabOrder = 7
          OnClick = btnClickDropDown
          SkinData.SkinSection = 'BUTTON'
        end
      end
      object pnlLinesGrid: TsPanel
        Left = 0
        Top = 49
        Width = 1083
        Height = 230
        Align = alClient
        BevelOuter = bvNone
        Caption = 'pnlLinesGrid'
        Padding.Left = 10
        Padding.Top = 5
        Padding.Right = 10
        Padding.Bottom = 5
        TabOrder = 2
        SkinData.SkinSection = 'PANEL'
        object agrLines: TAdvStringGrid
          Left = 10
          Top = 5
          Width = 1063
          Height = 220
          Cursor = crDefault
          Align = alClient
          BevelInner = bvNone
          BevelOuter = bvNone
          BorderStyle = bsNone
          ColCount = 16
          DefaultRowHeight = 19
          DrawingStyle = gdsClassic
          FixedCols = 0
          RowCount = 2
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goThumbTracking]
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          OnDrawCell = agrLinesDrawCell
          OnGetEditText = agrLinesGetEditText
          OnKeyDown = agrLinesKeyDown
          OnMouseDown = agrLinesMouseDown
          OnMouseUp = agrLinesMouseUp
          HoverRowCells = [hcNormal, hcSelected]
          OnGetDisplText = agrLinesGetDisplText
          OnGetCellColor = agrLinesGetCellColor
          OnGetAlignment = agrLinesGetAlignment
          OnRowChanging = agrLinesRowChanging
          OnDblClickCell = agrLinesDblClickCell
          OnCanEditCell = agrLinesCanEditCell
          OnCellValidate = agrLinesCellValidate
          OnCheckBoxClick = CheckBoxClick
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
          Look = glStandard
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
          SearchFooter.Color = clBtnFace
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
          SelectionColor = clHighlight
          SelectionTextColor = clHighlightText
          SortSettings.DefaultFormat = ssAutomatic
          Version = '8.2.4.1'
          ColWidths = (
            24
            28
            84
            486
            83
            91
            31
            64
            64
            64
            64
            64
            64
            64
            64
            64)
        end
      end
      object pnlInvoiceIndices: TsScrollBox
        AlignWithMargins = True
        Left = 1086
        Top = 52
        Width = 69
        Height = 224
        HorzScrollBar.Visible = False
        VertScrollBar.Tracking = True
        Align = alRight
        TabOrder = 1
        OnDragOver = pnlInvoiceIndicesDragOver
        object pnlInvoiceIndex0: TsPanel
          Left = 0
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
          Left = 0
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
            Left = 10
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
            ExplicitTop = 6
          end
        end
        object pnlInvoiceIndex2: TsPanel
          Tag = 2
          Left = 0
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
          Left = 0
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
          Left = 0
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
          Left = 0
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
          Left = 0
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
          Left = 0
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
          Left = 0
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
          Left = 0
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
        Action = actSave
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
        Action = actAddDownPayment
      end
    end
    object Items1: TMenuItem
      Caption = 'Items'
      object Add1: TMenuItem
        Action = actAddLine
      end
      object Delete1: TMenuItem
        Action = actRemoveSelected
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Removetemporarily1: TMenuItem
        Action = actMoveItemToTemp
      end
      object RemoveRoomRenttemporarity1: TMenuItem
        Action = actMoveRoomToTemp
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object SendItemToGroupInvoice: TMenuItem
        Action = actMoveItemToGroupInvoice
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
  object actInvoiceActions: TActionList
    OnUpdate = actInvoiceActionsUpdate
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
    object actAddDownPayment: TAction
      Category = 'Downpayment'
      Caption = 'Add Downpayment'
      OnExecute = actAddDownPaymentExecute
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
    object actRemoveSelected: TAction
      Category = 'Lines'
      Caption = 'Remove Selected'
      ShortCut = 16430
      OnExecute = actRemoveSelectedExecute
    end
    object actMoveRoomToTemp: TAction
      Category = 'MoveRoom'
      Caption = 'Room to temp'
      ShortCut = 115
      OnExecute = actMoveRoomToTempExecute
    end
    object actMoveItemToTemp: TAction
      Category = 'MoveItem'
      Caption = 'Item to temp'
      ShortCut = 114
      OnExecute = actMoveItemToTempExecute
    end
    object actMoveItemToGroupInvoice: TAction
      Category = 'MoveItem'
      Caption = 'Item to groupinvoice'
      ShortCut = 116
      OnExecute = actMoveItemToGroupInvoiceExecute
    end
    object actAddPackage: TAction
      Caption = 'Add Package'
    end
    object actAddRoom: TAction
      Category = 'Lines'
      Caption = 'Add Room'
      OnExecute = actAddRoomExecute
    end
    object actToggleLodgingTax: TAction
      Category = 'Invoice'
      Caption = 'Toggle Lodging Tax'
      OnExecute = actToggleLodgingTaxClick
    end
    object actMoveRoomToGroupInvoice: TAction
      Category = 'MoveRoom'
      Caption = 'Room to group invoice'
      OnExecute = actMoveRoomToGroupInvoiceExecute
    end
    object actMoveRoomToRoomInvoice: TAction
      Category = 'MoveRoom'
      Caption = 'Room to room invoice'
      OnExecute = actMoveRoomToRoomInvoiceExecute
    end
    object acShowAllCTax: TAction
      Category = 'ShowHide'
      Caption = 'Show all Citytax'
      OnExecute = acShowAllCTaxExecute
    end
    object acShowAlllBreakfasts: TAction
      Category = 'ShowHide'
      Caption = 'Show all included breakfasts'
      OnExecute = acShowAlllBreakfastsExecute
    end
    object acShowAllDiscounts: TAction
      Category = 'ShowHide'
      Caption = 'Show all discounts'
      OnExecute = acShowAllDiscountsExecute
    end
    object acHideAllCTax: TAction
      Category = 'ShowHide'
      Caption = 'Hide all Citytax'
      OnExecute = acHideAllCTaxExecute
    end
    object acHideAllBreakfasts: TAction
      Category = 'ShowHide'
      Caption = 'Hide all included breakfasts'
      OnExecute = acHideAllBreakfastsExecute
    end
    object acHideAllDiscounts: TAction
      Category = 'ShowHide'
      Caption = 'Hide all discounts'
      OnExecute = acHideAllDiscountsExecute
    end
    object acShowpackageItems: TAction
      Category = 'ShowHide'
      Caption = 'Show packageitems'
      OnExecute = acShowpackageItemsExecute
    end
    object acHidePackageItems: TAction
      Category = 'ShowHide'
      Caption = 'Hide packageitems'
      OnExecute = acHidePackageItemsExecute
    end
    object actRevertDownpayment: TAction
      Category = 'Downpayment'
      Caption = 'Revert Downpayment'
      OnExecute = actRevertDownpaymentExecute
    end
    object actEditDownPayment: TAction
      Category = 'Downpayment'
      Caption = 'Edit Dowpayment'
      OnExecute = actEditDownPaymentExecute
    end
    object actDeleteDownPayment: TAction
      Category = 'Downpayment'
      Caption = 'Delete downpayment'
      OnExecute = actDeleteDownPaymentExecute
    end
    object actSave: TAction
      Category = 'File'
      Caption = 'Save changes'
      OnExecute = btnSaveChangesClick
    end
  end
  object timCloseInvoice: TTimer
    Enabled = False
    Interval = 100
    OnTimer = timCloseInvoiceTimer
    Left = 57
    Top = 405
  end
  object PaymentsDS: TDataSource
    DataSet = mPayments
    Left = 680
    Top = 520
  end
  object mPayments: TdxMemData
    Indexes = <>
    SortOptions = []
    OnCalcFields = mPaymentsCalcFields
    Left = 616
    Top = 520
    object mPaymentsPayDate: TDateField
      FieldName = 'PayDate'
    end
    object mPaymentsPayType: TWideStringField
      FieldName = 'PayType'
    end
    object mPaymentsCurrency: TWideStringField
      FieldName = 'Currency'
      Size = 5
    end
    object mPaymentsCurrencyAmount: TFloatField
      FieldKind = fkCalculated
      FieldName = 'CurrencyAmount'
      Calculated = True
    end
    object mPaymentsNativeAmount: TFloatField
      FieldName = 'NativeAmount'
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
    object mPaymentsPaycardTraceIndex: TIntegerField
      FieldName = 'PaycardTraceIndex'
    end
    object mPaymentsChargedOnCC: TBooleanField
      FieldKind = fkCalculated
      FieldName = 'ChargedOnCC'
      Calculated = True
    end
  end
  object mnuMoveItem: TPopupMenu
    OnPopup = mnuMoveItemPopup
    Left = 208
    Top = 328
    object mnuItemToGroupInvoice: TMenuItem
      Action = actMoveItemToGroupInvoice
    end
    object mnuItemToRoomInvoice: TMenuItem
      Caption = 'Item to room invoice'
    end
    object mnuItemToTemp: TMenuItem
      Action = actMoveItemToTemp
      Visible = False
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
    Left = 40
    Top = 328
    object mnuMoveRoomRentFromRoomInvoiceToGroup: TMenuItem
      Action = actMoveRoomToGroupInvoice
    end
    object mnuMoveRoomRentFromGroupToNormalRoomInvoice: TMenuItem
      Action = actMoveRoomToRoomInvoice
    end
    object mnuMoveRoomToInvoiceIndex: TMenuItem
      Caption = 'Room to invoiceindex'
      object TMenuItem
      end
    end
    object mnuRoomToTemp: TMenuItem
      Action = actMoveRoomToTemp
      Visible = False
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
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
    end
    object N11: TMenuItem
      Tag = 1
      Caption = '2'
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
    end
    object N31: TMenuItem
      Tag = 2
      Caption = '3'
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
    end
    object N41: TMenuItem
      Tag = 3
      Caption = '4'
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
    end
    object N51: TMenuItem
      Tag = 4
      Caption = '5'
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
    end
    object N61: TMenuItem
      Tag = 5
      Caption = '6'
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
    end
    object N71: TMenuItem
      Tag = 6
      Caption = '7'
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
    end
    object N81: TMenuItem
      Tag = 7
      Caption = '8'
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
    end
    object N91: TMenuItem
      Tag = 8
      Caption = '9'
      OnClick = MoveSelectedLinesToRoomInvoiceIndex
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
  object mnuShowOnInvoice: TPopupMenu
    Left = 352
    Top = 384
    object mnuCityTax: TMenuItem
      Caption = 'Citytax'
      object mnuShowAllCTax: TMenuItem
        Action = acShowAllCTax
      end
      object mnuHideallCitytax: TMenuItem
        Action = acHideAllCTax
      end
    end
    object mnuBreakfast: TMenuItem
      Caption = 'Breakfasts'
      object mnuShowallincludedbreakfasts: TMenuItem
        Action = acShowAlllBreakfasts
      end
      object mnuHideallincludedbreakfasts: TMenuItem
        Action = acHideAllBreakfasts
      end
    end
    object mnuDiscounts: TMenuItem
      Caption = 'Discounts'
      object mnuShowalldiscounts: TMenuItem
        Action = acShowAllDiscounts
      end
      object mnuHidealldiscounts: TMenuItem
        Action = acHideAllDiscounts
      end
    end
    object mnuPackages: TMenuItem
      Caption = 'Packages'
      object mnuShowPackageItems: TMenuItem
        Action = acShowpackageItems
      end
      object mnuHidePackageItems: TMenuItem
        Action = acHidePackageItems
      end
    end
  end
end
