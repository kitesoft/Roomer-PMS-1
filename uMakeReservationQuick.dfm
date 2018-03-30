object frmMakeReservationQuick: TfrmMakeReservationQuick
  Left = 549
  Top = 309
  Caption = 'New reservation'
  ClientHeight = 682
  ClientWidth = 1317
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object panBottom: TsPanel
    Left = 0
    Top = 649
    Width = 1317
    Height = 33
    Align = alBottom
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    DesignSize = (
      1317
      33)
    object btnCancel: TsButton
      Left = 1082
      Top = 4
      Width = 111
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      Caption = 'Cancel'
      ImageIndex = 11
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 2
      SkinData.SkinSection = 'BUTTON'
    end
    object btnNext: TsButton
      Left = 121
      Top = 4
      Width = 111
      Height = 25
      Caption = 'Next'
      Enabled = False
      ImageAlignment = iaRight
      ImageIndex = 107
      Images = DImages.PngImageList1
      TabOrder = 0
      OnClick = btnNextClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnPrevius: TsButton
      Left = 4
      Top = 4
      Width = 111
      Height = 25
      Caption = 'Previous'
      Enabled = False
      ImageIndex = 106
      Images = DImages.PngImageList1
      TabOrder = 3
      OnClick = btnPreviusClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnFinish: TsButton
      Left = 1199
      Top = 4
      Width = 107
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Finish'
      DropDownMenu = mnuFinish
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      Style = bsSplitButton
      TabOrder = 1
      OnClick = btnFinishClick
      SkinData.SkinSection = 'BUTTON'
    end
  end
  object pnlNotes: TsPanel
    Left = 0
    Top = 577
    Width = 1317
    Height = 72
    Align = alBottom
    Constraints.MinHeight = 50
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object panNotesPayment: TsPanel
      Left = 407
      Top = 1
      Width = 284
      Height = 70
      Align = alLeft
      TabOrder = 1
      SkinData.SkinSection = 'PANEL'
      object Panel7: TsPanel
        Left = 1
        Top = 1
        Width = 282
        Height = 17
        Align = alTop
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object clabPaymentNotes: TsLabel
          Left = 1
          Top = 1
          Width = 86
          Height = 13
          Align = alClient
          Alignment = taCenter
          Caption = 'Payment Notes'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
        end
      end
      object memReservationPaymentInfo: TsMemo
        Left = 1
        Top = 18
        Width = 282
        Height = 51
        Align = alClient
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 1
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
        SkinData.SkinSection = 'EDIT'
      end
    end
    object panNotesGeneral: TsPanel
      Left = 1
      Top = 1
      Width = 406
      Height = 70
      Align = alLeft
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      object Panel11: TsPanel
        Left = 1
        Top = 1
        Width = 404
        Height = 17
        Align = alTop
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object clabGeneralNotes: TsLabel
          Left = 1
          Top = 1
          Width = 79
          Height = 13
          Align = alClient
          Alignment = taCenter
          Caption = 'General Notes'
          Color = clBtnFace
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
        end
      end
      object memReservationGeneralInfo: TsMemo
        Left = 1
        Top = 18
        Width = 404
        Height = 51
        Align = alClient
        BorderStyle = bsNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 1
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
        SkinData.SkinSection = 'EDIT'
      end
    end
    object panRoomNotes: TsPanel
      Left = 691
      Top = 1
      Width = 625
      Height = 70
      Align = alClient
      TabOrder = 2
      SkinData.SkinSection = 'PANEL'
      object sPanel6: TsPanel
        Left = 1
        Top = 1
        Width = 623
        Height = 17
        Align = alTop
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object clabRoomNotes: TsLabel
          Left = 1
          Top = 1
          Width = 68
          Height = 13
          Align = alClient
          Alignment = taCenter
          Caption = 'Room Notes'
          Color = clBtnFace
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
        end
      end
      object btnClearLog: TsButton
        Left = 13
        Top = 136
        Width = 52
        Height = 25
        Caption = 'Clear'
        TabOrder = 1
        Visible = False
        OnClick = btnClearLogClick
        SkinData.SkinSection = 'BUTTON'
      end
      object sButton2: TsButton
        Left = 71
        Top = 136
        Width = 43
        Height = 25
        Caption = 'Format'
        TabOrder = 2
        Visible = False
        OnClick = sButton2Click
        SkinData.SkinSection = 'BUTTON'
      end
      object sButton5: TsButton
        Left = 122
        Top = 136
        Width = 43
        Height = 25
        Caption = 'Home'
        TabOrder = 3
        Visible = False
        OnClick = sButton5Click
        SkinData.SkinSection = 'BUTTON'
      end
      object sButton6: TsButton
        Left = 171
        Top = 135
        Width = 43
        Height = 25
        Caption = 'up'
        TabOrder = 4
        Visible = False
        OnClick = sButton6Click
        SkinData.SkinSection = 'BUTTON'
      end
      object sButton7: TsButton
        Left = 220
        Top = 135
        Width = 43
        Height = 25
        Caption = 'Down'
        TabOrder = 5
        Visible = False
        OnClick = sButton7Click
        SkinData.SkinSection = 'BUTTON'
      end
      object memRoomNotes: TDBMemo
        Left = 1
        Top = 18
        Width = 623
        Height = 51
        Align = alClient
        DataField = 'roomNotes'
        DataSource = mRoomResDS
        TabOrder = 6
      end
    end
  end
  object pgcMain: TsPageControl
    Left = 0
    Top = 0
    Width = 1317
    Height = 577
    ActivePage = taReservation
    Align = alClient
    TabOrder = 2
    OnChange = pgcMainChange
    SkinData.SkinSection = 'PAGECONTROL'
    object taReservation: TsTabSheet
      Caption = 'Reservation'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object panTop: TsPanel
        Left = 0
        Top = 0
        Width = 1309
        Height = 549
        Align = alClient
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object Panel2: TsPanel
          Left = 1
          Top = 1
          Width = 503
          Height = 547
          Align = alLeft
          TabOrder = 0
          SkinData.SkinSection = 'PANEL'
          object gbxGetCustomer: TsGroupBox
            AlignWithMargins = True
            Left = 6
            Top = 109
            Width = 491
            Height = 76
            Margins.Left = 5
            Margins.Top = 2
            Margins.Right = 5
            Margins.Bottom = 2
            Align = alTop
            Caption = 'Customer'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object clabCustomer: TsLabel
              Left = 106
              Top = 18
              Width = 52
              Height = 13
              Alignment = taRightJustify
              Caption = 'Company :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblPortfolio: TsLabel
              Left = 123
              Top = 45
              Width = 35
              Height = 13
              Alignment = taRightJustify
              Caption = 'Guest :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object pnlGuest: TsPanel
              AlignWithMargins = True
              Left = 166
              Top = 44
              Width = 309
              Height = 21
              Margins.Left = 164
              Margins.Right = 14
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 1
              object btnPortfolioLookup: TsSpeedButton
                AlignWithMargins = True
                Left = 257
                Top = 0
                Width = 23
                Height = 21
                Margins.Top = 0
                Margins.Right = 0
                Margins.Bottom = 0
                Align = alRight
                Caption = '...'
                OnClick = btnPortfolioLookupClick
                SkinData.SkinSection = 'SPEEDBUTTON'
                ExplicitLeft = 275
                ExplicitTop = -3
              end
              object btnPortfolio: TsSpeedButton
                AlignWithMargins = True
                Left = 283
                Top = 0
                Width = 23
                Height = 21
                Margins.Top = 0
                Margins.Bottom = 0
                Align = alRight
                Caption = 'X'
                OnClick = btnPortfolioClick
                SkinData.SkinSection = 'SPEEDBUTTON'
                ExplicitLeft = 325
              end
              object edtPortfolio: TsEdit
                Left = 0
                Top = 0
                Width = 254
                Height = 21
                Align = alClient
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnDblClick = btnPortfolioLookupClick
                SkinData.SkinSection = 'EDIT'
              end
            end
            inline fraCustomerPanel: TfraCustomerPanel
              AlignWithMargins = True
              Left = 166
              Top = 18
              Width = 309
              Height = 20
              Margins.Left = 164
              Margins.Right = 14
              Align = alTop
              TabOrder = 0
              ExplicitLeft = 166
              ExplicitTop = 18
              ExplicitWidth = 309
              inherited pnlLookup: TsPanel
                Width = 309
                ExplicitWidth = 309
                inherited lblDescription: TsLabel
                  Left = 181
                  ExplicitLeft = 181
                end
                inherited edCode: TsEdit
                  Width = 115
                  ExplicitWidth = 115
                end
                inherited btnSelect: TsButton
                  Left = 151
                  ExplicitLeft = 151
                end
                inherited btnLast: TsButton
                  Left = 115
                  ExplicitLeft = 115
                end
              end
            end
          end
          object gbxGetReservation: TsGroupBox
            AlignWithMargins = True
            Left = 6
            Top = 189
            Width = 491
            Height = 180
            Margins.Left = 5
            Margins.Top = 2
            Margins.Right = 5
            Margins.Bottom = 2
            Align = alTop
            Caption = 'Reservation'
            TabOrder = 2
            SkinData.SkinSection = 'GROUPBOX'
            object pnlReservationBaseData: TsPanel
              Left = 2
              Top = 15
              Width = 487
              Height = 52
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 0
              object clabReservationType: TsLabel
                Left = 118
                Top = 4
                Width = 38
                Height = 13
                Alignment = taRightJustify
                Caption = 'Status :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object clabReservationName: TsLabel
                Left = 122
                Top = 30
                Width = 34
                Height = 13
                Alignment = taRightJustify
                Caption = 'Name :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object edReservationName: TsEdit
                AlignWithMargins = True
                Left = 164
                Top = 27
                Width = 309
                Height = 21
                Margins.Left = 164
                Margins.Right = 14
                Align = alTop
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 0
                SkinData.SkinSection = 'EDIT'
              end
              object pnlReservationStatus: TsPanel
                AlignWithMargins = True
                Left = 164
                Top = 0
                Width = 309
                Height = 21
                Margins.Left = 164
                Margins.Top = 0
                Margins.Right = 14
                Align = alTop
                BevelOuter = bvNone
                TabOrder = 1
                object cbxRoomStatus: TsComboBox
                  Left = 0
                  Top = 0
                  Width = 178
                  Height = 21
                  Align = alLeft
                  Alignment = taLeftJustify
                  SkinData.SkinSection = 'COMBOBOX'
                  VerticalAlignment = taAlignTop
                  Style = csDropDownList
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ItemIndex = -1
                  ParentFont = False
                  TabOrder = 0
                  OnChange = cbxRoomStatusChange
                  Items.Strings = (
                    'Not Arrived'
                    'Checked in'
                    'Alotment'
                    'Optional booking'
                    'No-show'
                    'Departed'
                    'Blocked'
                    'Out-Of-Order Blocking'
                    'Waiting list')
                end
                object chkGroupInvoice: TsCheckBox
                  AlignWithMargins = True
                  Left = 208
                  Top = 0
                  Width = 101
                  Height = 21
                  Margins.Top = 0
                  Margins.Right = 0
                  Margins.Bottom = 0
                  Caption = 'Group &Invoice :'
                  Align = alRight
                  Alignment = taLeftJustify
                  TabOrder = 1
                  SkinData.SkinSection = 'CHECKBOX'
                  ImgChecked = 0
                  ImgUnchecked = 0
                end
              end
            end
            object pnlReservationDetaildata: TsPanel
              Left = 2
              Top = 67
              Width = 487
              Height = 106
              Align = alTop
              AutoSize = True
              BevelOuter = bvNone
              TabOrder = 1
              object clabMarketSegmentCode: TsLabel
                Left = 72
                Top = 86
                Width = 84
                Height = 13
                Alignment = taRightJustify
                Caption = 'Market segment :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object lblCountry: TsLabel
                Left = 46
                Top = 60
                Width = 110
                Height = 13
                Alignment = taRightJustify
                Caption = 'Country  / Nationality :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object lblMarket: TsLabel
                Left = 116
                Top = 7
                Width = 40
                Height = 13
                Alignment = taRightJustify
                Caption = 'Market :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object sLabel9: TsLabel
                Left = 99
                Top = 33
                Width = 57
                Height = 13
                Alignment = taRightJustify
                Caption = 'Reference :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object cbxMarket: TsComboBox
                AlignWithMargins = True
                Left = 164
                Top = 3
                Width = 309
                Height = 21
                Margins.Left = 164
                Margins.Right = 14
                Align = alTop
                Alignment = taLeftJustify
                SkinData.SkinSection = 'COMBOBOX'
                VerticalAlignment = taAlignTop
                Style = csDropDownList
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ItemIndex = -1
                ParentFont = False
                TabOrder = 0
              end
              object edInvRefrence: TsEdit
                AlignWithMargins = True
                Left = 164
                Top = 30
                Width = 309
                Height = 21
                Margins.Left = 164
                Margins.Right = 14
                Align = alTop
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 1
                SkinData.SkinSection = 'EDIT'
              end
              inline fraLookupCountry: TfraCountryPanel
                AlignWithMargins = True
                Left = 164
                Top = 57
                Width = 309
                Height = 20
                Margins.Left = 164
                Margins.Right = 14
                Align = alTop
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                ExplicitLeft = 164
                ExplicitTop = 57
                ExplicitWidth = 309
                inherited pnlLookup: TsPanel
                  Width = 309
                  ExplicitWidth = 309
                end
              end
              inline fraLookupMarketSegment: TfraLookupMarketSegment
                AlignWithMargins = True
                Left = 164
                Top = 83
                Width = 309
                Height = 20
                Margins.Left = 164
                Margins.Right = 14
                Align = alTop
                TabOrder = 3
                ExplicitLeft = 164
                ExplicitTop = 83
                ExplicitWidth = 309
                inherited pnlLookup: TsPanel
                  Width = 309
                  ExplicitWidth = 309
                end
              end
            end
          end
          object gbxDates: TsGroupBox
            AlignWithMargins = True
            Left = 6
            Top = 3
            Width = 491
            Height = 102
            Margins.Left = 5
            Margins.Top = 2
            Margins.Right = 5
            Margins.Bottom = 2
            Align = alTop
            Caption = 'Dates'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object clabArrival: TsLabel
              Left = 120
              Top = 18
              Width = 38
              Height = 13
              Alignment = taRightJustify
              Caption = 'Arrival :'
              Color = clBtnFace
              ParentColor = False
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabdeparture: TsLabel
              Left = 102
              Top = 45
              Width = 56
              Height = 13
              Alignment = taRightJustify
              Caption = 'Departure :'
              Color = clBtnFace
              ParentColor = False
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabNights: TsLabel
              Left = 121
              Top = 72
              Width = 37
              Height = 13
              Alignment = taRightJustify
              Caption = 'Nights :'
              Color = clBtnFace
              ParentColor = False
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edNights: TsSpinEdit
              AlignWithMargins = True
              Left = 166
              Top = 69
              Width = 150
              Height = 21
              Margins.Left = 164
              Margins.Right = 173
              Align = alTop
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              OnChange = edNightsChange
              SkinData.SkinSection = 'EDIT'
              BoundLabel.Font.Charset = DEFAULT_CHARSET
              BoundLabel.Font.Color = clWindowText
              BoundLabel.Font.Height = -13
              BoundLabel.Font.Name = 'Tahoma'
              BoundLabel.Font.Style = []
              MaxValue = 365
              MinValue = 1
              Value = 0
            end
            object pnlArrival: TsPanel
              AlignWithMargins = True
              Left = 166
              Top = 15
              Width = 309
              Height = 21
              Margins.Left = 164
              Margins.Top = 0
              Margins.Right = 14
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 0
              object __lblArrivalWeekday: TsLabel
                AlignWithMargins = True
                Left = 156
                Top = 0
                Width = 4
                Height = 13
                Margins.Left = 6
                Margins.Top = 0
                Margins.Right = 0
                Margins.Bottom = 0
                Align = alLeft
                Caption = '-'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object dtArrival: TsDateEdit
                Left = 0
                Top = 0
                Width = 150
                Height = 21
                Align = alLeft
                AutoSize = False
                Color = clWhite
                EditMask = '!99/99/9999;1; '
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                MaxLength = 10
                ParentFont = False
                TabOrder = 0
                Text = '  -  -    '
                OnChange = dtArrivalChange
                OnExit = dtArrivalExit
                SkinData.SkinSection = 'EDIT'
                GlyphMode.Blend = 0
                GlyphMode.Grayed = False
                OnCloseUp = dtArrivalCloseUp
              end
            end
            object pnlDeparture: TsPanel
              AlignWithMargins = True
              Left = 166
              Top = 42
              Width = 309
              Height = 21
              Margins.Left = 164
              Margins.Right = 14
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 1
              object __lblDepartureWeekday: TsLabel
                AlignWithMargins = True
                Left = 156
                Top = 0
                Width = 4
                Height = 13
                Margins.Left = 6
                Margins.Top = 0
                Margins.Right = 0
                Margins.Bottom = 0
                Align = alLeft
                Caption = '-'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object dtDeparture: TsDateEdit
                Left = 0
                Top = 0
                Width = 150
                Height = 21
                Align = alLeft
                AutoSize = False
                Color = clWhite
                EditMask = '!99/99/9999;1; '
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                MaxLength = 10
                ParentFont = False
                TabOrder = 0
                Text = '  -  -    '
                OnChange = dtDepartureChange
                OnExit = dtDepartureExit
                SkinData.SkinSection = 'EDIT'
                GlyphMode.Blend = 0
                GlyphMode.Grayed = False
                OnCloseUp = dtDepartureCloseUp
              end
            end
          end
          object gbxRate: TsGroupBox
            AlignWithMargins = True
            Left = 6
            Top = 373
            Width = 491
            Height = 171
            Margins.Left = 5
            Margins.Top = 2
            Margins.Right = 5
            Margins.Bottom = 2
            Align = alClient
            Caption = 'Room Rate'
            TabOrder = 3
            SkinData.SkinSection = 'GROUPBOX'
            object clabCurrency: TsLabel
              Left = 107
              Top = 18
              Width = 51
              Height = 13
              Alignment = taRightJustify
              Caption = 'Currency :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              UseSkinColor = False
            end
            object clabPcCode: TsLabel
              Left = 97
              Top = 44
              Width = 61
              Height = 13
              Alignment = taRightJustify
              Caption = 'Price group :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabDiscountPerc: TsLabel
              Left = 110
              Top = 70
              Width = 48
              Height = 13
              Alignment = taRightJustify
              Caption = 'Discount :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            inline fraCurrencyPanel: TfraCurrencyPanel
              AlignWithMargins = True
              Left = 166
              Top = 15
              Width = 309
              Height = 20
              Margins.Left = 164
              Margins.Top = 0
              Margins.Right = 14
              Align = alTop
              AutoSize = True
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              ExplicitLeft = 166
              ExplicitTop = 15
              ExplicitWidth = 309
              inherited pnlLookup: TsPanel
                Width = 309
                ExplicitWidth = 309
              end
            end
            object pnlDiscount: TPanel
              AlignWithMargins = True
              Left = 166
              Top = 67
              Width = 309
              Height = 21
              Margins.Left = 164
              Margins.Right = 14
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 1
              object edRoomResDiscount: TsCurrencyEdit
                AlignWithMargins = True
                Left = 0
                Top = 0
                Width = 84
                Height = 20
                Margins.Left = 0
                Margins.Top = 0
                Margins.Right = 0
                Margins.Bottom = 1
                Align = alLeft
                AutoSize = False
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = edRoomResDiscountChange
                SkinData.SkinSection = 'EDIT'
                GlyphMode.Blend = 0
                GlyphMode.Grayed = False
                ShowButton = True
                MaxValue = 100.000000000000000000
              end
              object cbxIsRoomResDiscountPrec: TsComboBox
                AlignWithMargins = True
                Left = 87
                Top = 0
                Width = 56
                Height = 21
                Margins.Top = 0
                Margins.Bottom = 1
                Align = alLeft
                Alignment = taLeftJustify
                SkinData.SkinSection = 'COMBOBOX'
                VerticalAlignment = taAlignTop
                Style = csDropDownList
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ItemIndex = 0
                ParentFont = False
                TabOrder = 1
                Text = '%'
                OnChange = edRoomResDiscountChange
                Items.Strings = (
                  '%'
                  'ISK')
              end
            end
            inline fraPriceCodePanel: TfraPriceCodePanel
              AlignWithMargins = True
              Left = 166
              Top = 41
              Width = 309
              Height = 20
              Margins.Left = 164
              Margins.Right = 14
              Align = alTop
              TabOrder = 2
              ExplicitLeft = 166
              ExplicitTop = 41
              ExplicitWidth = 309
              inherited pnlLookup: TsPanel
                Width = 309
                ExplicitWidth = 309
              end
            end
          end
        end
        object pgcMoreInfo: TsPageControl
          Left = 504
          Top = 1
          Width = 804
          Height = 547
          ActivePage = tabContactDetails
          Align = alClient
          TabOrder = 1
          SkinData.SkinSection = 'PAGECONTROL'
          object tabContactDetails: TsTabSheet
            Caption = 'Contact Details'
            ImageIndex = 2
            TabVisible = False
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object sPanel3: TsPanel
              Left = 0
              Top = 0
              Width = 796
              Height = 537
              Align = alClient
              TabOrder = 0
              SkinData.SkinSection = 'PANEL'
              object AdvSplitter1: TAdvSplitter
                Left = 257
                Top = 292
                Height = 244
                Appearance.BorderColor = clNone
                Appearance.BorderColorHot = clNone
                Appearance.Color = clWhite
                Appearance.ColorTo = clSilver
                Appearance.ColorHot = clWhite
                Appearance.ColorHotTo = clGray
                GripStyle = sgDots
                ExplicitLeft = 304
                ExplicitTop = 320
                ExplicitHeight = 100
              end
              object gbxContact: TsGroupBox
                AlignWithMargins = True
                Left = 6
                Top = 3
                Width = 784
                Height = 287
                Margins.Left = 5
                Margins.Top = 2
                Margins.Right = 5
                Margins.Bottom = 2
                Align = alTop
                Caption = 'Contact'
                Color = clBtnFace
                ParentColor = False
                TabOrder = 0
                SkinData.SkinSection = 'GROUPBOX'
                object clabContactPerson: TsLabel
                  Left = 68
                  Top = 44
                  Width = 75
                  Height = 13
                  Alignment = taRightJustify
                  Caption = 'Contact Name :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabContactAddress: TsLabel
                  Left = 56
                  Top = 88
                  Width = 87
                  Height = 13
                  Alignment = taRightJustify
                  Caption = 'Contact Address :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabContactFax: TsLabel
                  Left = 108
                  Top = 223
                  Width = 35
                  Height = 17
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Fax :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabContactEmail: TsLabel
                  Left = 112
                  Top = 250
                  Width = 31
                  Height = 13
                  Alignment = taRightJustify
                  Caption = 'Email :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object lblContactZip: TsLabel
                  Left = 96
                  Top = 142
                  Width = 47
                  Height = 13
                  Alignment = taRightJustify
                  Caption = 'Zip code :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object lblContactCity: TsLabel
                  Left = 117
                  Top = 169
                  Width = 26
                  Height = 13
                  Alignment = taRightJustify
                  Caption = 'City :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object lblNew: TsLabel
                  Left = 510
                  Top = 42
                  Width = 60
                  Height = 37
                  AutoSize = False
                  Caption = 'F2=New'
                  WordWrap = True
                end
                object clabContactPhone: TsLabel
                  Left = 122
                  Top = 196
                  Width = 21
                  Height = 13
                  Alignment = taRightJustify
                  Caption = 'Tel :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edContactAddress1: TsEdit
                  AlignWithMargins = True
                  Left = 152
                  Top = 91
                  Width = 550
                  Height = 21
                  Margins.Left = 150
                  Margins.Right = 80
                  Align = alTop
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edContactAddress2: TsEdit
                  AlignWithMargins = True
                  Left = 152
                  Top = 118
                  Width = 550
                  Height = 21
                  Margins.Left = 150
                  Margins.Right = 80
                  Align = alTop
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edContactAddress3: TsEdit
                  AlignWithMargins = True
                  Left = 152
                  Top = 145
                  Width = 550
                  Height = 21
                  Margins.Left = 150
                  Margins.Right = 80
                  Align = alTop
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
                object edContactAddress4: TsEdit
                  AlignWithMargins = True
                  Left = 152
                  Top = 172
                  Width = 550
                  Height = 21
                  Margins.Left = 150
                  Margins.Right = 80
                  Align = alTop
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = False
                  TabOrder = 3
                  SkinData.SkinSection = 'EDIT'
                end
                object chkContactIsGuest: TsCheckBox
                  AlignWithMargins = True
                  Left = 12
                  Top = 18
                  Width = 767
                  Height = 20
                  Margins.Left = 10
                  Margins.Bottom = 0
                  Caption = 'Contact is guest'
                  Align = alTop
                  Checked = True
                  State = cbChecked
                  TabOrder = 5
                  SkinData.SkinSection = 'CHECKBOX'
                  ImgChecked = 0
                  ImgUnchecked = 0
                end
                object edContactFax: TsEdit
                  AlignWithMargins = True
                  Left = 152
                  Top = 226
                  Width = 351
                  Height = 21
                  Margins.Left = 150
                  Margins.Right = 279
                  Align = alTop
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = False
                  TabOrder = 4
                  SkinData.SkinSection = 'EDIT'
                end
                object cbxAddToGuestProfiles: TsCheckBox
                  AlignWithMargins = True
                  Left = 152
                  Top = 68
                  Width = 627
                  Height = 20
                  Margins.Left = 150
                  Margins.Bottom = 0
                  Caption = 'Add to guest profiles'
                  Align = alTop
                  TabOrder = 6
                  SkinData.SkinSection = 'CHECKBOX'
                  ImgChecked = 0
                  ImgUnchecked = 0
                end
                object edContactPerson1: TcxComboBox
                  AlignWithMargins = True
                  Left = 152
                  Top = 41
                  Margins.Left = 150
                  Margins.Right = 80
                  Align = alTop
                  Properties.DropDownRows = 16
                  Properties.OnCloseUp = edContactPerson1PropertiesCloseUp
                  TabOrder = 7
                  OnEnter = edContactPersonEnter
                  OnExit = edContactPersonExit
                  OnKeyDown = edContactPersonKeyDown
                  Width = 550
                end
                object pnlPhones: TsPanel
                  AlignWithMargins = True
                  Left = 152
                  Top = 199
                  Width = 550
                  Height = 21
                  Margins.Left = 150
                  Margins.Right = 80
                  Align = alTop
                  BevelOuter = bvNone
                  TabOrder = 8
                  object lblContactMobile: TsLabel
                    AlignWithMargins = True
                    Left = 363
                    Top = 3
                    Width = 34
                    Height = 13
                    Align = alRight
                    Alignment = taRightJustify
                    Caption = 'Mobile:'
                    ParentFont = False
                    Layout = tlCenter
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object edContactPhone: TsEdit
                    Left = 0
                    Top = 0
                    Width = 150
                    Height = 21
                    Align = alLeft
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    ParentShowHint = False
                    ShowHint = False
                    TabOrder = 0
                    SkinData.SkinSection = 'EDIT'
                  end
                  object edContactMobile: TsEdit
                    Left = 400
                    Top = 0
                    Width = 150
                    Height = 21
                    Align = alRight
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    ParentShowHint = False
                    ShowHint = False
                    TabOrder = 1
                    SkinData.SkinSection = 'EDIT'
                  end
                end
                object pnlEmail: TsPanel
                  AlignWithMargins = True
                  Left = 152
                  Top = 253
                  Width = 580
                  Height = 21
                  Margins.Left = 150
                  Margins.Right = 50
                  Align = alTop
                  BevelOuter = bvNone
                  TabOrder = 9
                  object edContactEmail: TsEdit
                    Left = 0
                    Top = 0
                    Width = 200
                    Height = 21
                    Align = alLeft
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    ParentShowHint = False
                    ShowHint = False
                    TabOrder = 0
                    OnChange = edContactEmailChange
                    SkinData.SkinSection = 'EDIT'
                  end
                  object chkSendConfirmation: TsCheckBox
                    AlignWithMargins = True
                    Left = 206
                    Top = 3
                    Width = 148
                    Height = 15
                    Margins.Left = 6
                    Caption = 'Send confirmation by email'
                    Align = alLeft
                    Enabled = False
                    TabOrder = 1
                    SkinData.SkinSection = 'CHECKBOX'
                    ImgChecked = 0
                    ImgUnchecked = 0
                  end
                end
              end
              object gbxProfileAlert: TsGroupBox
                AlignWithMargins = True
                Left = 265
                Top = 294
                Width = 525
                Height = 240
                Margins.Left = 5
                Margins.Top = 2
                Margins.Right = 5
                Margins.Bottom = 2
                Align = alClient
                Caption = 'Guest profile notes and preferences'
                TabOrder = 1
                SkinData.SkinSection = 'GROUPBOX'
                object lblSpecialRequests: TsLabel
                  AlignWithMargins = True
                  Left = 7
                  Top = 18
                  Width = 81
                  Height = 13
                  Margins.Left = 5
                  Margins.Bottom = 0
                  Align = alTop
                  Caption = 'Special Requests'
                end
                object lblNotes: TsLabel
                  AlignWithMargins = True
                  Left = 7
                  Top = 92
                  Width = 28
                  Height = 13
                  Margins.Left = 5
                  Margins.Bottom = 0
                  Align = alTop
                  Caption = 'Notes'
                end
                object edtSpecialRequests: TMemo
                  AlignWithMargins = True
                  Left = 7
                  Top = 36
                  Width = 511
                  Height = 48
                  Margins.Left = 5
                  Margins.Top = 5
                  Margins.Right = 5
                  Margins.Bottom = 5
                  Align = alTop
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clRed
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  ReadOnly = True
                  ScrollBars = ssVertical
                  TabOrder = 0
                end
                object edtNotes: TMemo
                  AlignWithMargins = True
                  Left = 7
                  Top = 110
                  Width = 511
                  Height = 49
                  Margins.Left = 5
                  Margins.Top = 5
                  Margins.Right = 5
                  Margins.Bottom = 0
                  Align = alTop
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clRed
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  ReadOnly = True
                  ScrollBars = ssVertical
                  TabOrder = 1
                end
                object gbxRoomAlert: TsGroupBox
                  Left = 2
                  Top = 159
                  Width = 521
                  Height = 105
                  Align = alTop
                  TabOrder = 2
                  object lblRoomType: TsLabel
                    Left = 13
                    Top = 45
                    Width = 59
                    Height = 13
                    Alignment = taRightJustify
                    Caption = 'Room type :'
                  end
                  object lblRoom: TsLabel
                    Left = 38
                    Top = 18
                    Width = 34
                    Height = 13
                    Alignment = taRightJustify
                    Caption = 'Room :'
                  end
                  object edtRoom: TsEdit
                    AlignWithMargins = True
                    Left = 82
                    Top = 15
                    Width = 423
                    Height = 21
                    Margins.Left = 80
                    Margins.Top = 0
                    Margins.Right = 14
                    Align = alTop
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clRed
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    ReadOnly = True
                    TabOrder = 0
                    SkinData.CustomFont = True
                  end
                  object edtRoomType: TsEdit
                    AlignWithMargins = True
                    Left = 82
                    Top = 42
                    Width = 423
                    Height = 21
                    Margins.Left = 80
                    Margins.Right = 14
                    Align = alTop
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clRed
                    Font.Height = -11
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    ReadOnly = True
                    TabOrder = 1
                    SkinData.CustomFont = True
                  end
                end
              end
              object gbxCustomerAlert: TsGroupBox
                AlignWithMargins = True
                Left = 6
                Top = 294
                Width = 246
                Height = 240
                Margins.Left = 5
                Margins.Top = 2
                Margins.Right = 5
                Margins.Bottom = 2
                Align = alLeft
                Caption = 'Customer Alert'
                TabOrder = 2
                SkinData.SkinSection = 'GROUPBOX'
                object memCustomerAlert: TMemo
                  AlignWithMargins = True
                  Left = 2
                  Top = 20
                  Width = 242
                  Height = 218
                  Margins.Left = 0
                  Margins.Top = 5
                  Margins.Right = 0
                  Margins.Bottom = 0
                  Align = alClient
                  Color = clWhite
                  ReadOnly = True
                  ScrollBars = ssVertical
                  TabOrder = 0
                end
              end
            end
          end
          object tabCustomerDetails: TsTabSheet
            Caption = 'Customer Details'
            ImageIndex = 1
            TabVisible = False
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object clabTel2: TsLabel
              Left = 204
              Top = 125
              Width = 47
              Height = 17
              AutoSize = False
              Caption = 'Tel :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sPanel1: TsPanel
              Left = 0
              Top = 0
              Width = 796
              Height = 537
              Align = alClient
              TabOrder = 0
              SkinData.SkinSection = 'PANEL'
              object clabPID: TsLabel
                Left = 50
                Top = 13
                Width = 62
                Height = 13
                Alignment = taRightJustify
                Caption = 'Personal ID :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object clabCustomerName: TsLabel
                Left = 78
                Top = 34
                Width = 34
                Height = 13
                Alignment = taRightJustify
                Caption = 'Name :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object clabAddress1: TsLabel
                Left = 66
                Top = 56
                Width = 46
                Height = 13
                Alignment = taRightJustify
                Caption = 'Address :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object clabWebSite: TsLabel
                Left = 66
                Top = 185
                Width = 46
                Height = 13
                Alignment = taRightJustify
                Caption = 'Website :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object clabEmail: TsLabel
                Left = 81
                Top = 163
                Width = 31
                Height = 13
                Alignment = taRightJustify
                Caption = 'Email :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object clabFax: TsLabel
                Left = 87
                Top = 141
                Width = 25
                Height = 13
                Alignment = taRightJustify
                Caption = 'Fax :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object clabTel1: TsLabel
                Left = 91
                Top = 120
                Width = 21
                Height = 13
                Alignment = taRightJustify
                Caption = 'Tel :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object edPID: TsEdit
                Left = 118
                Top = 12
                Width = 229
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 0
                SkinData.SkinSection = 'EDIT'
              end
              object edCustomerName: TsEdit
                Left = 118
                Top = 34
                Width = 229
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 1
                SkinData.SkinSection = 'EDIT'
              end
              object edAddress1: TsEdit
                Left = 118
                Top = 55
                Width = 229
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 2
                SkinData.SkinSection = 'EDIT'
              end
              object edAddress2: TsEdit
                Left = 118
                Top = 76
                Width = 229
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 3
                SkinData.SkinSection = 'EDIT'
              end
              object edAddress3: TsEdit
                Left = 118
                Top = 98
                Width = 229
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 4
                SkinData.SkinSection = 'EDIT'
              end
              object edTel1: TsEdit
                Left = 118
                Top = 119
                Width = 89
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 5
                SkinData.SkinSection = 'EDIT'
              end
              object edTel2: TsEdit
                Left = 257
                Top = 119
                Width = 90
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 6
                SkinData.SkinSection = 'EDIT'
              end
              object edFax: TsEdit
                Left = 118
                Top = 141
                Width = 89
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 7
                SkinData.SkinSection = 'EDIT'
              end
              object edEmailAddress: TsEdit
                Left = 118
                Top = 162
                Width = 229
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 8
                SkinData.SkinSection = 'EDIT'
              end
              object edHomePage: TsEdit
                Left = 118
                Top = 184
                Width = 229
                Height = 21
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                ParentShowHint = False
                ShowHint = False
                TabOrder = 9
                SkinData.SkinSection = 'EDIT'
              end
            end
          end
        end
      end
    end
    object tabSelectType: TsTabSheet
      Caption = 'Select Types'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object panSelectTypesTop: TsPanel
        Left = 0
        Top = 0
        Width = 1309
        Height = 72
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object gbxSelStatus: TsGroupBox
          AlignWithMargins = True
          Left = 145
          Top = 3
          Width = 542
          Height = 66
          Margins.Left = 20
          Align = alLeft
          Caption = 'Exclude No-Room with status of : '
          TabOrder = 0
          SkinData.SkinSection = 'GROUPBOX'
          object chkExcluteWaitingList: TsCheckBox
            Left = 14
            Top = 19
            Width = 69
            Height = 20
            Caption = 'Waitinglist'
            TabOrder = 0
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
          object chkExcluteAllotment: TsCheckBox
            Left = 14
            Top = 41
            Width = 65
            Height = 20
            Caption = 'Allotment'
            TabOrder = 1
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
          object chkExcluteOrder: TsCheckBox
            Left = 327
            Top = 19
            Width = 48
            Height = 20
            Caption = 'Order'
            TabOrder = 2
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
          object chkExcluteNoShow: TsCheckBox
            Left = 224
            Top = 41
            Width = 61
            Height = 20
            Caption = 'No show'
            TabOrder = 3
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
          object chkExcluteDeparted: TsCheckBox
            Left = 122
            Top = 19
            Width = 65
            Height = 20
            Caption = 'Departed'
            TabOrder = 4
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
          object chkExcluteBlocked: TsCheckBox
            Left = 224
            Top = 19
            Width = 56
            Height = 20
            Caption = 'Blocked'
            TabOrder = 5
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
          object chkExcluteGuest: TsCheckBox
            Left = 122
            Top = 41
            Width = 48
            Height = 20
            Caption = 'Guest'
            TabOrder = 6
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
          object chkExcludeWaitingListNonOptional: TsCheckBox
            Left = 327
            Top = 41
            Width = 72
            Height = 20
            Caption = 'Waiting list'
            TabOrder = 7
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
        end
        object sPanel7: TsPanel
          AlignWithMargins = True
          Left = 2
          Top = 2
          Width = 121
          Height = 68
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Align = alLeft
          BevelOuter = bvNone
          TabOrder = 1
          SkinData.SkinSection = 'PANEL'
          object sLabel1: TsLabel
            Left = 16
            Top = 40
            Width = 36
            Height = 13
            Caption = 'sLabel1'
          end
          object cxButton1: TsButton
            Left = 9
            Top = 7
            Width = 100
            Height = 25
            Caption = 'Refresh'
            ImageIndex = 28
            Images = DImages.PngImageList1
            TabOrder = 0
            SkinData.SkinSection = 'BUTTON'
          end
        end
      end
      object grSelectType: TcxGrid
        Left = 0
        Top = 72
        Width = 609
        Height = 477
        Align = alLeft
        TabOrder = 1
        LookAndFeel.NativeStyle = False
        object tvSelectType: TcxGridDBTableView
          Navigator.Buttons.CustomButtons = <>
          DataController.DataSource = mSelectTypesDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              FieldName = 'Selected'
              Column = tvSelectTypeSelected
            end
            item
              Kind = skSum
              FieldName = 'NoRooms'
              Column = tvSelectTypeNoRooms
            end
            item
              Kind = skSum
              FieldName = 'TotalFree'
              Column = tvSelectTypeTotalFree
            end
            item
              Kind = skSum
              FieldName = 'Available'
              Column = tvSelectTypeAvailable
            end
            item
              Kind = skSum
              FieldName = 'RoomsSelected'
              Column = tvSelectTypeRoomsSelected
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.FocusCellOnTab = True
          OptionsView.Footer = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderAutoHeight = True
          object tvSelectTypeRecId: TcxGridDBColumn
            DataBinding.FieldName = 'RecId'
            Visible = False
          end
          object tvSelectTyperoomType: TcxGridDBColumn
            Caption = 'Room Type'
            DataBinding.FieldName = 'roomType'
            Options.Editing = False
            Width = 90
          end
          object tvSelectTypeRoomTypeDescription: TcxGridDBColumn
            Caption = 'Type Description'
            DataBinding.FieldName = 'RoomTypeDescription'
            Options.Editing = False
            Width = 172
          end
          object tvSelectTypeAvailable: TcxGridDBColumn
            DataBinding.FieldName = 'Available'
            HeaderAlignmentHorz = taRightJustify
            Options.Editing = False
            Width = 86
          end
          object tvSelectTypeSelected: TcxGridDBColumn
            DataBinding.FieldName = 'Selected'
            PropertiesClassName = 'TcxSpinEditProperties'
            Properties.AssignedValues.MinValue = True
            Properties.ImmediatePost = True
            Properties.MaxValue = 500.000000000000000000
            Properties.OnEditValueChanged = tvSelectTypeSelectedPropertiesEditValueChanged
            Properties.OnValidate = tvSelectTypeSelectedPropertiesValidate
            HeaderAlignmentHorz = taRightJustify
            Options.ShowEditButtons = isebAlways
            Width = 91
          end
          object tvSelectTypeTotalFree: TcxGridDBColumn
            Caption = 'Remaning'
            DataBinding.FieldName = 'TotalFree'
            PropertiesClassName = 'TcxSpinEditProperties'
            Properties.ReadOnly = True
            HeaderAlignmentHorz = taRightJustify
            Options.Editing = False
            Width = 78
          end
          object tvSelectTypeNoRooms: TcxGridDBColumn
            DataBinding.FieldName = 'NoRooms'
            PropertiesClassName = 'TcxSpinEditProperties'
            Properties.ImmediatePost = True
            Properties.MaxValue = 300.000000000000000000
            Properties.OnChange = tvSelectTypeNoRoomsPropertiesChange
            Properties.OnValidate = tvSelectTypeNoRoomsPropertiesValidate
            HeaderAlignmentHorz = taRightJustify
            Options.ShowEditButtons = isebAlways
            Styles.Content = cxStyle2
            Styles.OnGetContentStyle = tvSelectTypeNoRoomsStylesGetContentStyle
            Width = 73
          end
          object tvSelectTypeRoomsSelected: TcxGridDBColumn
            DataBinding.FieldName = 'RoomsSelected'
            PropertiesClassName = 'TcxLabelProperties'
            Visible = False
            Options.Editing = False
            Width = 87
          end
          object tvSelectTypePriorityRule: TcxGridDBColumn
            DataBinding.FieldName = 'PriorityRule'
            Visible = False
            Width = 200
          end
        end
        object lvSelectType: TcxGridLevel
          GridView = tvSelectType
        end
      end
      object sPanel4: TsPanel
        Left = 609
        Top = 72
        Width = 700
        Height = 477
        Align = alClient
        TabOrder = 2
        SkinData.SkinSection = 'PANEL'
      end
    end
    object tabSelectRooms: TsTabSheet
      Caption = 'Select Rooms'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object panSelectRoomsTop: TsPanel
        Left = 0
        Top = 0
        Width = 1309
        Height = 97
        Align = alTop
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object sLabel2: TsLabel
          Left = 257
          Top = 7
          Width = 66
          Height = 13
          Alignment = taRightJustify
          Caption = 'Total rooms : '
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object labTotalSelected: TsLabel
          Left = 329
          Top = 7
          Width = 39
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = '0'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object sLabel3: TsLabel
          Left = 272
          Top = 26
          Width = 51
          Height = 13
          Alignment = taRightJustify
          Caption = 'Selected : '
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object labTotalRoomsSelected: TsLabel
          Left = 329
          Top = 26
          Width = 39
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = '0'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object sLabel5: TsLabel
          Left = 294
          Top = 45
          Width = 29
          Height = 13
          Alignment = taRightJustify
          Caption = 'Left : '
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object sLabel6: TsLabel
          Left = 329
          Top = 45
          Width = 39
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = '0'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object btnAutoSelectRooms: TsButton
          Left = 8
          Top = 5
          Width = 208
          Height = 25
          Caption = 'Autoselect'
          Images = DImages.PngImageList1
          TabOrder = 0
          OnClick = btnAutoSelectRoomsClick
          SkinData.SkinSection = 'BUTTON'
        end
        object btnSetAllAsNoRoom: TsButton
          Left = 8
          Top = 36
          Width = 208
          Height = 25
          Caption = 'Set All as No-Room'
          TabOrder = 1
          OnClick = btnSetAllAsNoRoomClick
          SkinData.SkinSection = 'BUTTON'
        end
        object cbxFilterSelectedTypes: TsCheckBox
          Left = 8
          Top = 69
          Width = 188
          Height = 20
          Caption = 'Only show rooms of selected types'
          Checked = True
          State = cbChecked
          TabOrder = 2
          OnClick = cbxFilterSelectedTypesClick
          ImgChecked = 0
          ImgUnchecked = 0
        end
      end
      object grSelectRooms: TcxGrid
        Left = 0
        Top = 97
        Width = 1309
        Height = 452
        Align = alClient
        TabOrder = 1
        LookAndFeel.NativeStyle = False
        object tvSelectRooms: TcxGridDBBandedTableView
          Navigator.Buttons.CustomButtons = <>
          DataController.DataSource = mSelectRoomsDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.HeaderAutoHeight = True
          Bands = <
            item
              Caption = 'Room'
              FixedKind = fkLeft
              Width = 813
            end
            item
              Caption = 'Equipments'
            end
            item
              Caption = 'More'
              Visible = False
            end
            item
              Caption = 'Hidden'
              Visible = False
            end>
          object tvSelectRoomsSelect: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Select'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.OnEditValueChanged = tvSelectRoomsSelectPropertiesEditValueChanged
            Width = 45
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvSelectRoomsRoom: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Room'
            PropertiesClassName = 'TcxTextEditProperties'
            Options.ShowEditButtons = isebAlways
            Width = 94
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvSelectRoomsDescription: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Description'
            Options.Editing = False
            Width = 145
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvSelectRoomsRoomType: TcxGridDBBandedColumn
            Caption = 'Type'
            DataBinding.FieldName = 'RoomType'
            Options.Editing = False
            Width = 60
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvSelectRoomsRoomTypeDescription: TcxGridDBBandedColumn
            Caption = 'Type description'
            DataBinding.FieldName = 'RoomTypeDescription'
            Options.Editing = False
            Width = 132
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvSelectRoomsRoomTypeGroup: TcxGridDBBandedColumn
            DataBinding.FieldName = 'RoomTypeGroup'
            Visible = False
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object tvSelectRoomsRoomTypeGroupDescription: TcxGridDBBandedColumn
            Caption = 'Room Class'
            DataBinding.FieldName = 'RoomTypeGroupDescription'
            Options.Editing = False
            Width = 119
            Position.BandIndex = 0
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
          object tvSelectRoomsStatus: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Status'
            Options.Editing = False
            Width = 38
            Position.BandIndex = 1
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvSelectRoomsLocation: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Location'
            Visible = False
            Position.BandIndex = 0
            Position.ColIndex = 8
            Position.RowIndex = 0
          end
          object tvSelectRoomsLocationDescription: TcxGridDBBandedColumn
            Caption = 'Location'
            DataBinding.FieldName = 'LocationDescription'
            Options.Editing = False
            Width = 103
            Position.BandIndex = 0
            Position.ColIndex = 10
            Position.RowIndex = 0
          end
          object tvSelectRoomsFloor: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Floor'
            Options.Editing = False
            Width = 47
            Position.BandIndex = 0
            Position.ColIndex = 9
            Position.RowIndex = 0
          end
          object tvSelectRoomsNumberGuests: TcxGridDBBandedColumn
            Caption = 'Guests'
            DataBinding.FieldName = 'NumberGuests'
            PropertiesClassName = 'TcxSpinEditProperties'
            Properties.MaxValue = 100.000000000000000000
            Options.Editing = False
            Width = 68
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvSelectRoomsEquipments: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Equipments'
            Options.Editing = False
            Width = 139
            Position.BandIndex = 1
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvSelectRoomsSqrMeters: TcxGridDBBandedColumn
            Caption = 'm2'
            DataBinding.FieldName = 'SqrMeters'
            Options.Editing = False
            Width = 36
            Position.BandIndex = 1
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvSelectRoomsBedSize: TcxGridDBBandedColumn
            Caption = 'Bed'
            DataBinding.FieldName = 'BedSize'
            HeaderHint = 'Bed size'
            Options.Editing = False
            Width = 41
            Position.BandIndex = 1
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvSelectRoomsBath: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Bath'
            Visible = False
            Width = 49
            Position.BandIndex = 1
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvSelectRoomsShower: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Shower'
            Visible = False
            Width = 46
            Position.BandIndex = 1
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvSelectRoomsActive: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Active'
            Visible = False
            Position.BandIndex = 2
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvSelectRoomsOrderIndex: TcxGridDBBandedColumn
            DataBinding.FieldName = 'OrderIndex'
            Visible = False
            Position.BandIndex = 2
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvSelectRoomsuseInNationalReport: TcxGridDBBandedColumn
            DataBinding.FieldName = 'useInNationalReport'
            Visible = False
            Position.BandIndex = 2
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvSelectRoomsBookable: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Bookable'
            Visible = False
            Position.BandIndex = 2
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvSelectRoomsStatistics: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Statistics'
            Visible = False
            Position.BandIndex = 2
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvSelectRoomshidden: TcxGridDBBandedColumn
            DataBinding.FieldName = 'hidden'
            Visible = False
            Position.BandIndex = 2
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvSelectRoomsRecId: TcxGridDBBandedColumn
            DataBinding.FieldName = 'RecId'
            Visible = False
            Position.BandIndex = 3
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvSelectRoomsID: TcxGridDBBandedColumn
            DataBinding.FieldName = 'ID'
            Visible = False
            Position.BandIndex = 3
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvSelectRoomsDorm: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Dorm'
            Visible = False
            Position.BandIndex = 3
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvSelectRoomsDetailedDescription: TcxGridDBBandedColumn
            DataBinding.FieldName = 'DetailedDescription'
            Visible = False
            Position.BandIndex = 3
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvSelectRoomstmp: TcxGridDBBandedColumn
            DataBinding.FieldName = 'tmp'
            Visible = False
            Position.BandIndex = 3
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
        end
        object lvSelectRooms: TcxGridLevel
          GridView = tvSelectRooms
        end
      end
    end
    object tabRoomRates: TsTabSheet
      Caption = 'Room Rates'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object panTopRoomRates: TsPanel
        Left = 0
        Top = 0
        Width = 1309
        Height = 140
        Align = alTop
        TabOrder = 1
        SkinData.SkinSection = 'PANEL'
        object gbxSelectedRoom: TsGroupBox
          AlignWithMargins = True
          Left = 214
          Top = 1
          Width = 211
          Height = 138
          Margins.Top = 0
          Margins.Bottom = 0
          Align = alLeft
          Caption = 'Selected room'
          TabOrder = 1
          SkinData.SkinSection = 'GROUPBOX'
          object btdEditRoomRate: TsButton
            Left = 3
            Top = 14
            Width = 205
            Height = 25
            Caption = 'Change per date'
            TabOrder = 0
            OnClick = btdEditRoomRateClick
            SkinData.SkinSection = 'BUTTON'
          end
          object sButton3: TsButton
            Left = 3
            Top = 45
            Width = 205
            Height = 25
            Caption = 'Apply to all roomtypes'
            TabOrder = 1
            OnClick = sButton3Click
            SkinData.SkinSection = 'BUTTON'
          end
          object sButton4: TsButton
            Left = 3
            Top = 76
            Width = 205
            Height = 25
            Caption = 'Apply to same roomtype'
            TabOrder = 2
            OnClick = sButton4Click
            SkinData.SkinSection = 'BUTTON'
          end
        end
        object gbxRefresh: TsGroupBox
          AlignWithMargins = True
          Left = 4
          Top = 1
          Width = 204
          Height = 138
          Margins.Top = 0
          Margins.Bottom = 0
          Align = alLeft
          Caption = 'Refresh'
          TabOrder = 0
          SkinData.SkinSection = 'GROUPBOX'
          object btnRefresh: TsButton
            Left = 3
            Top = 14
            Width = 198
            Height = 25
            Caption = 'Refresh Rate'
            ImageIndex = 28
            Images = DImages.PngImageList1
            TabOrder = 0
            OnClick = btnRefreshClick
            SkinData.SkinSection = 'BUTTON'
          end
          object sButton1: TsButton
            Left = 3
            Top = 45
            Width = 198
            Height = 25
            Caption = 'Set All as No-Room'
            TabOrder = 1
            OnClick = sButton1Click
            SkinData.SkinSection = 'BUTTON'
          end
        end
        object sPanel5: TsPanel
          Left = 428
          Top = 1
          Width = 196
          Height = 138
          Align = alLeft
          BevelOuter = bvNone
          TabOrder = 2
          SkinData.SkinSection = 'TRANSPARENT'
          object lblChannels: TsLabel
            Left = 3
            Top = 93
            Width = 43
            Height = 13
            Caption = 'Channel:'
          end
          object cbxChannels: TsComboBox
            Left = 3
            Top = 112
            Width = 186
            Height = 21
            Alignment = taLeftJustify
            SkinData.SkinSection = 'COMBOBOX'
            VerticalAlignment = taAlignTop
            Style = csDropDownList
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = -1
            ParentFont = False
            TabOrder = 1
            OnChange = cbxChannelsChange
          end
          object chkAutoUpdateNullPrice: TsCheckBox
            Left = 7
            Top = 18
            Width = 126
            Height = 20
            Caption = 'Auto update Null Price'
            Checked = True
            State = cbChecked
            TabOrder = 0
            SkinData.SkinSection = 'CHECKBOX'
            ImgChecked = 0
            ImgUnchecked = 0
          end
        end
        object pgcExtraAndAlert: TsPageControl
          Left = 624
          Top = 1
          Width = 441
          Height = 138
          ActivePage = sTabSheet1
          Align = alLeft
          TabOrder = 3
          SkinData.SkinSection = 'PAGECONTROL'
          object sTabSheet1: TsTabSheet
            Caption = 'Extra'
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object sPanel2: TsPanel
              Left = -2
              Top = 0
              Width = 435
              Height = 110
              Align = alRight
              BevelOuter = bvNone
              TabOrder = 0
              SkinData.SkinSection = 'PANEL'
              object lblExtraCurrency: TsLabel
                Left = 343
                Top = 32
                Width = 16
                Height = 13
                Alignment = taRightJustify
                Caption = 'ISK'
              end
              object Shape1: TShape
                Left = 17
                Top = 18
                Width = 398
                Height = 2
              end
              object lblPerPerson: TsLabel
                Left = 366
                Top = 32
                Width = 12
                Height = 13
                Hint = 'Per person'
                Caption = 'PP'
              end
              object lblPrice: TsLabel
                Left = 289
                Top = 5
                Width = 23
                Height = 13
                Alignment = taRightJustify
                Caption = 'Price'
              end
              object lblBreakfast: TsLabel
                Left = 21
                Top = 32
                Width = 50
                Height = 13
                Alignment = taRightJustify
                Caption = 'Breakfast:'
              end
              object edtBreakfastPrice: TsCurrencyEdit
                Left = 269
                Top = 29
                Width = 65
                Height = 21
                AutoSize = False
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                SkinData.SkinSection = 'EDIT'
                GlyphMode.Blend = 0
                GlyphMode.Grayed = False
              end
              object cbxBreakfast: TsComboBox
                Left = 84
                Top = 29
                Width = 145
                Height = 21
                Alignment = taLeftJustify
                VerticalAlignment = taAlignTop
                Style = csDropDownList
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ItemIndex = -1
                ParentFont = False
                TabOrder = 0
                OnChange = cbxBreakfastChange
              end
            end
          end
          object Alerts: TsTabSheet
            Caption = 'Alerts'
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
          end
        end
      end
      object grRoomRes: TcxGrid
        Left = 0
        Top = 140
        Width = 1309
        Height = 409
        Align = alClient
        TabOrder = 0
        LookAndFeel.NativeStyle = False
        object tvRoomRes: TcxGridDBTableView
          Navigator.Buttons.CustomButtons = <>
          Navigator.InfoPanel.Visible = True
          DataController.DataSource = mRoomResDS
          DataController.DetailKeyFieldNames = 'RoomReservation'
          DataController.KeyFieldNames = 'RoomReservation'
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Format = '###0.;###0.'
              Kind = skSum
              FieldName = 'Guests'
              Column = tvRoomResGuests
            end
            item
              Format = '###0.;###0.'
              Kind = skSum
              FieldName = 'ChildrenCount'
              Column = tvRoomResChildrenCount
            end
            item
              Format = '###0.;###0.'
              Kind = skSum
              FieldName = 'infantCount'
              Column = tvRoomResinfantCount
            end
            item
              Format = '###0.00;###0.00'
              Kind = skSum
              FieldName = 'AvragePrice'
              Column = tvRoomResAvragePrice
            end
            item
              Format = '###0.00;###0.00'
              Kind = skAverage
              FieldName = 'AvragePrice'
              Column = tvRoomResAvragePrice
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.FocusCellOnTab = True
          OptionsData.DeletingConfirmation = False
          OptionsData.Inserting = False
          OptionsView.Footer = True
          OptionsView.FooterAutoHeight = True
          OptionsView.FooterMultiSummaries = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderAutoHeight = True
          object tvRoomResRoomReservation: TcxGridDBColumn
            DataBinding.FieldName = 'RoomReservation'
            Visible = False
          end
          object tvRoomResColumn1: TcxGridDBColumn
            Caption = 'Edit'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Caption = 'Refresh'
                Default = True
                ImageIndex = 88
                Kind = bkGlyph
              end>
            Properties.Images = DImages.PngImageList1
            Properties.ViewStyle = vsButtonsOnly
            Properties.OnButtonClick = tvRoomResColumn1PropertiesButtonClick
            Options.ShowEditButtons = isebAlways
            Width = 39
          end
          object tvRoomResRoom: TcxGridDBColumn
            DataBinding.FieldName = 'Room'
            Options.Editing = False
            Width = 83
          end
          object tvRoomResRoomDescription: TcxGridDBColumn
            Caption = 'Description'
            DataBinding.FieldName = 'RoomDescription'
            Options.Editing = False
            Width = 118
          end
          object tvRoomResRoomType: TcxGridDBColumn
            Caption = 'Type'
            DataBinding.FieldName = 'RoomType'
            Options.Editing = False
            Width = 68
          end
          object tvRoomResRoomTypeDescription: TcxGridDBColumn
            Caption = 'Description'
            DataBinding.FieldName = 'RoomTypeDescription'
            Visible = False
            Options.Editing = False
            Width = 111
          end
          object tvRoomResArrival: TcxGridDBColumn
            DataBinding.FieldName = 'Arrival'
            Options.Editing = False
            Width = 88
          end
          object tvRoomResExpectedTimeOfArrival: TcxGridDBColumn
            Caption = 'Exp TOA'
            DataBinding.FieldName = 'ExpectedTimeOfarrival'
            PropertiesClassName = 'TcxTimeEditProperties'
            Properties.Alignment.Horz = taCenter
            Properties.ClearKey = 46
            Properties.SpinButtons.Visible = False
            Properties.TimeFormat = tfHourMin
            OnGetDisplayText = FormatTextToShortFormat
            OnGetProperties = GetLocaTimeEditProperties
            HeaderAlignmentHorz = taCenter
            MinWidth = 5
            Width = 62
          end
          object tvRoomResDeparture: TcxGridDBColumn
            DataBinding.FieldName = 'Departure'
            Options.Editing = False
            Width = 79
          end
          object tvRoomResexpectedCheckouttime: TcxGridDBColumn
            Caption = 'Exp COT'
            DataBinding.FieldName = 'ExpectedCheckOutTime'
            PropertiesClassName = 'TcxTimeEditProperties'
            Properties.Alignment.Horz = taCenter
            Properties.ClearKey = 46
            Properties.SpinButtons.Visible = False
            Properties.TimeFormat = tfHourMin
            OnGetDisplayText = FormatTextToShortFormat
            OnGetProperties = GetLocaTimeEditProperties
            HeaderAlignmentHorz = taCenter
            MinWidth = 5
            Width = 62
          end
          object tvRoomResGuests: TcxGridDBColumn
            DataBinding.FieldName = 'Guests'
            PropertiesClassName = 'TcxSpinEditProperties'
            Properties.MaxValue = 100.000000000000000000
            Properties.MinValue = 1.000000000000000000
            Properties.OnEditValueChanged = tvRoomResGuestsPropertiesEditValueChanged
            Width = 45
          end
          object tvRoomResChildrenCount: TcxGridDBColumn
            Caption = 'Children'
            DataBinding.FieldName = 'ChildrenCount'
            PropertiesClassName = 'TcxSpinEditProperties'
            Properties.MaxValue = 10.000000000000000000
            Properties.OnEditValueChanged = tvRoomResChildrenCountPropertiesEditValueChanged
            Width = 59
          end
          object tvRoomResinfantCount: TcxGridDBColumn
            Caption = 'Infants'
            DataBinding.FieldName = 'infantCount'
            PropertiesClassName = 'TcxSpinEditProperties'
            Properties.MaxValue = 10.000000000000000000
            Properties.OnEditValueChanged = tvRoomResinfantCountPropertiesEditValueChanged
            Width = 45
          end
          object tvRoomResMainGuest: TcxGridDBColumn
            Caption = 'Main Guest'
            DataBinding.FieldName = 'MainGuest'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Caption = '...'
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = tvRoomResMainGuestPropertiesButtonClick
            Width = 150
          end
          object tvRoomResRatePlanCode: TcxGridDBColumn
            Caption = 'Rate Code'
            DataBinding.FieldName = 'RatePlanCode'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              '')
            Properties.OnEditValueChanged = tvRoomResRatePlanCodePropertiesEditValueChanged
            Width = 67
          end
          object tvRoomResRoomRate: TcxGridDBColumn
            DataBinding.FieldName = 'RoomRate'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            Properties.OnEditValueChanged = tvRoomResRoomRatePropertiesEditValueChanged
            OnGetProperties = tvRoomResGetCurrencyProperties
          end
          object tvRoomResDiscount: TcxGridDBColumn
            DataBinding.FieldName = 'Discount'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0.0 %'
            Properties.OnEditValueChanged = tvRoomResDiscountPropertiesEditValueChanged
            OnGetProperties = tvRoomResDiscountGetProperties
          end
          object tvRoomResIsPercentage: TcxGridDBColumn
            Caption = 'Percentage'
            DataBinding.FieldName = 'IsPercentage'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.OnEditValueChanged = tvRoomResIsPercentagePropertiesEditValueChanged
            HeaderAlignmentHorz = taCenter
            Width = 40
          end
          object tvRoomResAvragePrice: TcxGridDBColumn
            Caption = 'Netto Rate'
            DataBinding.FieldName = 'AvragePrice'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            Properties.OnEditValueChanged = tvRoomResAvragePricePropertiesEditValueChanged
            OnGetProperties = tvRoomResGetCurrencyProperties
            Width = 73
          end
          object __tvRoomResColumn2: TcxGridDBColumn
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                ImageIndex = 17
                Kind = bkGlyph
              end>
            Properties.Images = DImages.cxSmallImagesFlat
            Properties.OnButtonClick = __tvRoomResColumn2PropertiesButtonClick
            HeaderGlyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000B6793C2AB4793A6DB578399CB4783A9DB579
              396FB379392C0000000000000000000000000000000000000000000000000000
              000000000000B6793C15B578399CB4783AF1B5793AFFB5793AFFB5793AFFB579
              3AFFB47839F3B57839A3B676361C000000000000000000000000000000000000
              0000B5783981B5793AFFB47839EAB5793AFFB578398EB87F3812AF7F3F10B579
              3A88B5793AFFB57839DEB47839F7B5793A91000000000000000000000000B478
              3AC0B47939F4B1793717B4793AD2B479397800000000B5793AA6B5793AA20000
              0000B3783870B47839D8AA7F2A06B5783AD3B4783AD17F7F0002B57939F2B579
              3AFF00000000B37C3725B47839F7AF7F3F10B5793A7AB5783AD3B5793AFFB478
              39E600000000B4793AF0B5793B4500000000B5783ACDB5793AFFB5793973B579
              3AFFB4793A82B5793973B47939ACBB77330FB5793AFFB57939FCB5793AFFB579
              3AFFB67F360EB47939A8B3783870B4793B63B5793AFFB578397D00000000B479
              3A7EB5793AFFB5793AFFB57839DEB1793717B57839ADB5793AFFB5793AFFB579
              39B0B6793C15B47939D9B5793AFFB5793AFFB5793A8800000000000000000000
              0000B4783966B5793AFFB5793AFFB5793AFFB5783AE0B4793AFEB4793AFEB479
              3ADFB5793AFFB5793AFFB5793AFFB4793A6D0000000000000000000000000000
              000000000000B2773B1EB4783AA5B5793AFFB5793AFFB5793AFFB5793AFFB579
              3AFFB5793AFFB57839A9B4783C22000000000000000000000000000000000000
              0000000000000000000000000000B6773931B4793A71B478399AB478399AB579
              3973B4783C330000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000}
            Width = 23
          end
          object tvRoomResAvrageDiscount: TcxGridDBColumn
            Caption = 'Average Discount'
            DataBinding.FieldName = 'AvrageDiscount'
            OnGetProperties = tvRoomResGetCurrencyProperties
            Options.Editing = False
          end
          object tvRoomResPackage: TcxGridDBColumn
            DataBinding.FieldName = 'Package'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                ImageIndex = 124
                Kind = bkGlyph
              end>
            Properties.Images = DImages.PngImageList1
            Properties.OnButtonClick = tvRoomResPackagePropertiesButtonClick
            Options.ShowEditButtons = isebAlways
            Width = 75
          end
          object tvRoomResPackagePrice: TcxGridDBColumn
            Caption = 'Package Price'
            DataBinding.FieldName = 'PackagePrice'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            Properties.DisplayFormat = ',0.00;-,0.00'
            Properties.ReadOnly = True
            OnGetProperties = tvRoomResGetCurrencyProperties
          end
          object tvRoomResRateCount: TcxGridDBColumn
            Caption = 'Rate Count'
            DataBinding.FieldName = 'RateCount'
            PropertiesClassName = 'TcxSpinEditProperties'
            Properties.DisplayFormat = '###0.;###0.'
            Visible = False
            Options.Editing = False
          end
          object tvRoomResStockItemsCount: TcxGridDBColumn
            Caption = 'Extras'
            DataBinding.FieldName = 'StockItemsCount'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = tvRoomResStockItemsCountPropertiesButtonClick
            Options.ShowEditButtons = isebAlways
          end
          object tvRoomResStockitemsPrice: TcxGridDBColumn
            Caption = 'Extras Price'
            DataBinding.FieldName = 'StockitemsPrice'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            Properties.DisplayFormat = ',0.00;-,0.00'
            Properties.ReadOnly = True
            OnGetProperties = tvRoomResGetCurrencyProperties
          end
          object tvRoomResPriceCode: TcxGridDBColumn
            DataBinding.FieldName = 'PriceCode'
            Options.Editing = False
            Width = 74
          end
        end
        object tvRoomRates: TcxGridDBTableView
          Navigator.Buttons.CustomButtons = <>
          DataController.DataModeController.SyncMode = False
          DataController.DataSource = mRoomRatesDS
          DataController.DetailKeyFieldNames = 'RoomReservation'
          DataController.KeyFieldNames = 'RoomReservation'
          DataController.MasterKeyFieldNames = 'RoomReservation'
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.FocusCellOnTab = True
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Inserting = False
          OptionsView.GroupByBox = False
          OptionsView.HeaderAutoHeight = True
          object tvRoomRatesReservation: TcxGridDBColumn
            DataBinding.FieldName = 'Reservation'
            Visible = False
          end
          object tvRoomRatesRoomReservation: TcxGridDBColumn
            DataBinding.FieldName = 'RoomReservation'
            Visible = False
          end
          object tvRoomRatesRoomNumber: TcxGridDBColumn
            Caption = 'Room'
            DataBinding.FieldName = 'RoomNumber'
            Visible = False
          end
          object tvRoomRatesRateDate: TcxGridDBColumn
            Caption = 'Date'
            DataBinding.FieldName = 'RateDate'
          end
          object tvRoomRatesPriceCode: TcxGridDBColumn
            Caption = 'Price code'
            DataBinding.FieldName = 'PriceCode'
            Visible = False
          end
          object tvRoomRatesRate: TcxGridDBColumn
            Caption = 'Room Rate'
            DataBinding.FieldName = 'Rate'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvRoomResGetCurrencyProperties
          end
          object tvRoomRatesDiscount: TcxGridDBColumn
            DataBinding.FieldName = 'Discount'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0.0 %'
            OnGetProperties = tvRoomRatesDiscountGetProperties
          end
          object tvRoomRatesisPercentage: TcxGridDBColumn
            Caption = 'is %'
            DataBinding.FieldName = 'isPercentage'
          end
          object tvRoomRatesShowDiscount: TcxGridDBColumn
            Caption = 'Show Discount'
            DataBinding.FieldName = 'ShowDiscount'
            Visible = False
          end
          object tvRoomRatesisPaid: TcxGridDBColumn
            Caption = 'Paid'
            DataBinding.FieldName = 'isPaid'
            Visible = False
          end
          object tvRoomRatesDiscountAmount: TcxGridDBColumn
            Caption = 'Total discount'
            DataBinding.FieldName = 'DiscountAmount'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvRoomResGetCurrencyProperties
          end
          object tvRoomRatesCurrency: TcxGridDBColumn
            DataBinding.FieldName = 'Currency'
          end
          object tvRoomRatesRentAmount: TcxGridDBColumn
            Caption = 'Total Rent'
            DataBinding.FieldName = 'RentAmount'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvRoomResGetCurrencyProperties
          end
          object tvRoomRatesNativeAmount: TcxGridDBColumn
            Caption = 'Native'
            DataBinding.FieldName = 'NativeAmount'
            OnGetProperties = tvRoomRatesNativeAmountGetProperties
          end
        end
        object lvRoomRes: TcxGridLevel
          GridView = tvRoomRes
          object lvRoomRates: TcxGridLevel
            GridView = tvRoomRates
          end
        end
      end
    end
  end
  object mRoomResDS: TDataSource
    DataSet = mRoomRes
    Left = 92
    Top = 592
  end
  object mSelectTypes: TdxMemData
    Indexes = <>
    SortOptions = []
    OnCalcFields = mSelectTypesCalcFields
    Left = 632
    Top = 592
    object mSelectTypesRoomtype: TStringField
      FieldName = 'roomType'
      Size = 10
    end
    object mSelectTypesRoomTypeDescription: TStringField
      FieldName = 'RoomTypeDescription'
    end
    object mSelectTypesSelected: TIntegerField
      FieldName = 'Selected'
    end
    object mSelectTypesNoRooms: TIntegerField
      FieldName = 'NoRooms'
    end
    object mSelectTypesAvailable: TIntegerField
      FieldName = 'Available'
    end
    object mSelectTypesTotalFree: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'TotalFree'
      Calculated = True
    end
    object mSelectTypesRoomsSelected: TIntegerField
      FieldName = 'RoomsSelected'
    end
    object mSelectTypesPriorityRule: TStringField
      FieldName = 'PriorityRule'
      Size = 50
    end
  end
  object mSelectTypesDS: TDataSource
    DataSet = mSelectTypes
    Left = 692
    Top = 592
  end
  object mSelectRooms: TdxMemData
    Indexes = <>
    SortOptions = []
    OnNewRecord = mSelectRoomsNewRecord
    OnFilterRecord = mSelectRoomsFilterRecord
    Left = 536
    Top = 592
    object mSelectRoomsID: TStringField
      FieldName = 'ID'
    end
    object mSelectRoomsActive: TBooleanField
      FieldName = 'Active'
    end
    object mSelectRoomsRoom: TStringField
      FieldName = 'Room'
      Size = 10
    end
    object mSelectRoomsRoomType: TStringField
      FieldName = 'RoomType'
      Size = 10
    end
    object mSelectRoomsDescription: TStringField
      FieldName = 'Description'
      Size = 30
    end
    object mSelectRoomsDetailedDescription: TMemoField
      FieldName = 'DetailedDescription'
      BlobType = ftMemo
    end
    object mSelectRoomsSqrMeters: TFloatField
      FieldName = 'SqrMeters'
    end
    object mSelectRoomsBedSize: TStringField
      FieldName = 'BedSize'
      Size = 1
    end
    object mSelectRoomsEquipments: TStringField
      FieldName = 'Equipments'
      Size = 100
    end
    object mSelectRoomsBookable: TBooleanField
      FieldName = 'Bookable'
    end
    object mSelectRoomsStatistics: TBooleanField
      FieldName = 'Statistics'
    end
    object mSelectRoomsStatus: TStringField
      FieldName = 'Status'
      Size = 1
    end
    object mSelectRoomsOrderIndex: TIntegerField
      FieldName = 'OrderIndex'
    end
    object mSelectRoomshidden: TBooleanField
      FieldName = 'hidden'
    end
    object mSelectRoomsLocation: TStringField
      FieldName = 'Location'
      Size = 10
    end
    object mSelectRoomsFloor: TIntegerField
      FieldName = 'Floor'
    end
    object mSelectRoomsDorm: TStringField
      FieldName = 'Dorm'
    end
    object mSelectRoomsuseInNationalReport: TBooleanField
      FieldName = 'useInNationalReport'
    end
    object mSelectRoomsLocationDescription: TStringField
      FieldName = 'LocationDescription'
      Size = 35
    end
    object mSelectRoomsRoomTypeDescription: TStringField
      FieldName = 'RoomTypeDescription'
      Size = 30
    end
    object mSelectRoomsRoomTypeGroupDescription: TStringField
      FieldName = 'RoomTypeGroupDescription'
      Size = 35
    end
    object mSelectRoomsBath: TBooleanField
      FieldName = 'Bath'
    end
    object mSelectRoomsShower: TBooleanField
      FieldName = 'Shower'
    end
    object mSelectRoomsSafe: TBooleanField
      FieldName = 'Safe'
    end
    object mSelectRoomsTV: TBooleanField
      FieldName = 'TV'
    end
    object mSelectRoomsVideo: TBooleanField
      FieldName = 'Video'
    end
    object mSelectRoomsRadio: TBooleanField
      FieldName = 'Radio'
    end
    object mSelectRoomsCDPlayer: TBooleanField
      FieldName = 'CDPlayer'
    end
    object mSelectRoomsTelephone: TBooleanField
      FieldName = 'Telephone'
    end
    object mSelectRoomsPress: TBooleanField
      FieldName = 'Press'
    end
    object mSelectRoomsCoffee: TBooleanField
      FieldName = 'Coffee'
    end
    object mSelectRoomsKitchen: TBooleanField
      FieldName = 'Kitchen'
    end
    object mSelectRoomsMinibar: TBooleanField
      FieldName = 'Minibar'
    end
    object mSelectRoomsFridge: TBooleanField
      FieldName = 'Fridge'
    end
    object mSelectRoomsHairdryer: TBooleanField
      FieldName = 'Hairdryer'
    end
    object mSelectRoomsInternetPlug: TBooleanField
      FieldName = 'InternetPlug'
    end
    object mSelectRoomsFax: TBooleanField
      FieldName = 'Fax'
    end
    object mSelectRoomsNumberGuests: TIntegerField
      FieldName = 'NumberGuests'
    end
    object mSelectRoomsRoomTypeGroup: TStringField
      FieldName = 'RoomTypeGroup'
      Size = 10
    end
    object mSelectRoomsSelect: TBooleanField
      FieldName = 'Select'
    end
    object mSelectRoomstmp: TStringField
      FieldName = 'tmp'
    end
  end
  object mSelectRoomsDS: TDataSource
    DataSet = mSelectRooms
    Left = 468
    Top = 589
  end
  object mRoomRatesDS: TDataSource
    DataSet = mRoomRates
    Left = 344
    Top = 592
  end
  object mDS: TDataSource
    DataSet = m_
    Left = 220
    Top = 589
  end
  object mOcc_: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 616
    Top = 360
    object mOcc_aDate: TDateTimeField
      FieldName = 'aDate'
    end
    object mOcc_Roomtype: TStringField
      FieldName = 'RoomType'
      Size = 10
    end
    object mOcc_isNoRoom: TBooleanField
      FieldName = 'isNoRoom'
    end
    object mOcc_Status: TStringField
      FieldName = 'Status'
      Size = 1
    end
    object mOcc_RoomCount: TIntegerField
      FieldName = 'RoomCount'
    end
  end
  object mOccDS: TDataSource
    DataSet = mOcc_
    Left = 564
    Top = 365
  end
  object m_: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 184
    Top = 592
    object m_RoomType: TStringField
      FieldName = 'RoomType'
      Size = 10
    end
    object m_aDate: TDateTimeField
      FieldName = 'aDate'
    end
    object m_RoomTypeGroup: TStringField
      FieldName = 'RoomTypeGroup'
    end
    object m_MaxFree: TIntegerField
      FieldName = 'MaxFree'
    end
    object m_occTotal: TIntegerField
      FieldName = 'occTotal'
    end
    object m_occDeparted: TIntegerField
      FieldName = 'occDeparted'
    end
    object m_occGuest: TIntegerField
      FieldName = 'occGuest'
    end
    object m_occOrder: TIntegerField
      FieldName = 'occOrder'
    end
    object m_occAllotment: TIntegerField
      FieldName = 'occAllotment'
    end
    object m_occWaitinglist: TIntegerField
      FieldName = 'occWaitinglist'
    end
    object m_occNoShow: TIntegerField
      FieldName = 'occNoShow'
    end
    object m_occBlocked: TIntegerField
      FieldName = 'occBlocked'
    end
    object m_nrTotal: TIntegerField
      FieldName = 'nrTotal'
    end
    object m_nrDeparted: TIntegerField
      FieldName = 'nrDeparted'
    end
    object m_nrGuest: TIntegerField
      FieldName = 'nrGuest'
    end
    object m_nrOrder: TIntegerField
      FieldName = 'nrOrder'
    end
    object m_nrAllotment: TIntegerField
      FieldName = 'nrAllotment'
    end
    object m_nrWaitingList: TIntegerField
      FieldName = 'nrWaitingList'
    end
    object m_nrNoShow: TIntegerField
      FieldName = 'nrNoShow'
    end
    object m_nrBlocked: TIntegerField
      FieldName = 'nrBlocked'
    end
    object m_FreeRooms: TIntegerField
      FieldName = 'FreeRooms'
    end
    object m_Description: TStringField
      FieldName = 'Description'
      Size = 30
    end
    object m_nrWaitingListNonOptional: TIntegerField
      FieldName = 'nrWaitingListNonOptional'
    end
    object m_occWaitingListNonOptional: TIntegerField
      FieldName = 'occWaitingListNonOptional'
    end
  end
  object StoreMain: TcxPropertiesStore
    Components = <
      item
        Component = Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Position'
          'Top'
          'Width')
      end>
    StorageName = 'Software\Roomer\FormStatus\QuickReservation'
    StorageType = stRegistry
    Left = 32
    Top = 112
  end
  object mnuFinish: TPopupMenu
    Images = DImages.PngImageList1
    Left = 800
    Top = 640
    object mnuFinishAndShow: TMenuItem
      Caption = 'Finish and show reservation'
      ImageIndex = 56
      OnClick = mnuFinishAndShowClick
    end
  end
  object mRoomRes: TdxMemData
    Indexes = <
      item
        FieldName = 'Room'
        SortOptions = []
      end>
    SortOptions = []
    Left = 16
    Top = 592
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
    object mRoomResRoomRate: TFloatField
      FieldName = 'RoomRate'
    end
    object mRoomResDiscount: TFloatField
      FieldName = 'Discount'
    end
    object mRoomResIsPercentage: TBooleanField
      FieldName = 'IsPercentage'
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
    object mRoomResMainGuest: TWideStringField
      FieldName = 'MainGuest'
      Size = 200
    end
    object mRoomResroomNotes: TMemoField
      FieldName = 'roomNotes'
      BlobType = ftMemo
    end
    object mRoomResPackagePrice: TFloatField
      FieldName = 'PackagePrice'
    end
    object mRoomResPersonsProfilesId: TIntegerField
      FieldName = 'PersonsProfilesId'
    end
    object mRoomResRatePlanCode: TStringField
      FieldName = 'RatePlanCode'
      Size = 15
    end
    object mRoomResManualChannelId: TIntegerField
      FieldName = 'ManualChannelId'
    end
    object mRoomResExpectedTimeOfArrival: TStringField
      FieldName = 'ExpectedTimeOfArrival'
    end
    object mRoomResExpectedCheckOutTime: TStringField
      FieldName = 'ExpectedCheckOutTime'
    end
    object mRoomResStockItemsCount: TIntegerField
      FieldName = 'StockItemsCount'
    end
    object mRoomResStockitemsPrice: TFloatField
      FieldName = 'StockitemsPrice'
    end
  end
  object mRoomRates: TdxMemData
    Indexes = <
      item
        FieldName = 'roomreservation'
        SortOptions = []
      end>
    SortOptions = []
    Left = 272
    Top = 591
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
    object mRoomRatesRateDate: TDateField
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
    object mRoomRatesCurrency: TStringField
      FieldName = 'Currency'
      Size = 5
    end
    object mRoomRatesCurrencyRate: TFloatField
      FieldName = 'CurrencyRate'
    end
  end
  object mRoomRatesTmp: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 568
    Top = 424
    object mRoomRatesTmpReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mRoomRatesTmproomreservation: TIntegerField
      FieldName = 'roomreservation'
    end
    object mRoomRatesTmpRoomNumber: TStringField
      FieldName = 'RoomNumber'
      Size = 10
    end
    object mRoomRatesTmpRateDate: TDateField
      FieldName = 'RateDate'
    end
    object mRoomRatesTmpPriceCode: TStringField
      FieldName = 'PriceCode'
      Size = 10
    end
    object mRoomRatesTmpRate: TFloatField
      FieldName = 'Rate'
    end
    object mRoomRatesTmpDiscount: TFloatField
      FieldName = 'Discount'
    end
    object mRoomRatesTmpisPercentage: TBooleanField
      FieldName = 'isPercentage'
    end
    object mRoomRatesTmpShowDiscount: TBooleanField
      FieldName = 'ShowDiscount'
    end
    object mRoomRatesTmpisPaid: TBooleanField
      FieldName = 'isPaid'
    end
    object mRoomRatesTmpDiscountAmount: TFloatField
      FieldName = 'DiscountAmount'
    end
    object mRoomRatesTmpRentAmount: TFloatField
      FieldName = 'RentAmount'
    end
    object mRoomRatesTmpNativeAmount: TFloatField
      FieldName = 'NativeAmount'
    end
    object mRoomRatesTmpCurrency: TStringField
      FieldName = 'Currency'
      Size = 5
    end
    object mRoomRatesTmpCurrencyRate: TFloatField
      FieldName = 'CurrencyRate'
    end
  end
  object mRatesEdit: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 632
    Top = 431
    object mRatesEditReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mRatesEditroomreservation: TIntegerField
      FieldName = 'roomreservation'
    end
    object mRatesEditRoomNumber: TStringField
      FieldName = 'RoomNumber'
      Size = 10
    end
    object mRatesEditRateDate: TDateField
      FieldName = 'RateDate'
    end
    object mRatesEditPriceCode: TStringField
      FieldName = 'PriceCode'
      Size = 10
    end
    object mRatesEditRate: TFloatField
      FieldName = 'Rate'
    end
    object mRatesEditDiscount: TFloatField
      FieldName = 'Discount'
    end
    object mRatesEditisPercentage: TBooleanField
      FieldName = 'isPercentage'
    end
    object mRatesEditShowDiscount: TBooleanField
      FieldName = 'ShowDiscount'
    end
    object mRatesEditisPaid: TBooleanField
      FieldName = 'isPaid'
    end
    object mRatesEditDiscountAmount: TFloatField
      FieldName = 'DiscountAmount'
    end
    object mRatesEditRentAmount: TFloatField
      FieldName = 'RentAmount'
    end
    object mRatesEditNativeAmount: TFloatField
      FieldName = 'NativeAmount'
    end
    object mRatesEditCurrency: TStringField
      FieldName = 'Currency'
      Size = 5
    end
    object mRatesEditCurrencyRate: TFloatField
      FieldName = 'CurrencyRate'
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 536
    Top = 104
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clRed
    end
    object cxStyle2: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = clWhite
      TextColor = clCaptionText
    end
    object cxStyle3: TcxStyle
    end
  end
  object mExtras: TdxMemData
    Indexes = <>
    SortOptions = []
    OnCalcFields = mExtrasCalcFields
    Left = 912
    Top = 368
    object mExtrasRoomreservation: TIntegerField
      FieldName = 'Roomreservation'
    end
    object mExtrasItemid: TIntegerField
      FieldName = 'Itemid'
    end
    object mExtrasCount: TIntegerField
      FieldName = 'Count'
    end
    object mExtrasPricePerItemPerDay: TFloatField
      FieldName = 'PricePerItemPerDay'
    end
    object mExtrasFromdate: TDateTimeField
      FieldName = 'Fromdate'
    end
    object mExtrasToDate: TDateTimeField
      FieldName = 'ToDate'
    end
    object mExtrasItem: TStringField
      FieldName = 'Item'
    end
    object mExtrasDescription: TStringField
      FieldName = 'Description'
    end
    object mExtrasTotalPrice: TFloatField
      FieldKind = fkCalculated
      FieldName = 'TotalPrice'
      Calculated = True
    end
  end
end
