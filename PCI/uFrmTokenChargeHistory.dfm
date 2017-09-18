inherited FrmTokenChargeHistory: TFrmTokenChargeHistory
  Caption = 'Paycards of reservation'
  ClientHeight = 600
  ClientWidth = 926
  Font.Height = -11
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  ExplicitWidth = 942
  ExplicitHeight = 639
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 580
    Width = 926
    ExplicitTop = 580
    ExplicitWidth = 926
  end
  object sPanel1: TsPanel [1]
    Left = 0
    Top = 0
    Width = 926
    Height = 113
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      926
      113)
    object sLabel3: TsLabel
      Left = 128
      Top = 21
      Width = 62
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Reservation:'
      ParentBiDiMode = False
    end
    object sLabel4: TsLabel
      Left = 98
      Top = 40
      Width = 92
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Room Reservation:'
      ParentBiDiMode = False
    end
    object sLabel5: TsLabel
      Left = 159
      Top = 59
      Width = 31
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Room:'
      ParentBiDiMode = False
    end
    object sLabel6: TsLabel
      Left = 158
      Top = 78
      Width = 32
      Height = 13
      Alignment = taRightJustify
      BiDiMode = bdLeftToRight
      Caption = 'Guest:'
      ParentBiDiMode = False
    end
    object lbReservation: TsLabel
      Left = 201
      Top = 21
      Width = 31
      Height = 13
      BiDiMode = bdLeftToRight
      Caption = '[N/A]'
      ParentBiDiMode = False
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object lbRoomReservation: TsLabel
      Left = 201
      Top = 40
      Width = 31
      Height = 13
      BiDiMode = bdLeftToRight
      Caption = '[N/A]'
      ParentBiDiMode = False
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object lbRoom: TsLabel
      Left = 201
      Top = 59
      Width = 31
      Height = 13
      BiDiMode = bdLeftToRight
      Caption = '[N/A]'
      ParentBiDiMode = False
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object lbGuest: TsLabel
      Left = 201
      Top = 78
      Width = 31
      Height = 13
      BiDiMode = bdLeftToRight
      Caption = '[N/A]'
      ParentBiDiMode = False
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object btnRefresh: TsButton
      Left = 818
      Top = 78
      Width = 96
      Height = 31
      Anchors = [akTop, akRight]
      Caption = 'Refresh'
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 0
      OnClick = btnRefreshClick
    end
  end
  object sPanel2: TsPanel [2]
    Left = 0
    Top = 113
    Width = 926
    Height = 467
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object sPanel3: TsPanel
      Left = 0
      Top = 0
      Width = 449
      Height = 467
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      object sLabel2: TsLabel
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 443
        Height = 13
        Align = alTop
        Caption = 'Available paycards'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ExplicitWidth = 107
      end
      object lvTokens: TsListView
        AlignWithMargins = True
        Left = 3
        Top = 22
        Width = 436
        Height = 401
        Margins.Right = 10
        Align = alClient
        Checkboxes = True
        Color = clWhite
        Columns = <
          item
            Caption = 'Card number'
            Width = 150
          end
          item
            Caption = 'User'
            Width = 80
          end
          item
            Caption = 'When'
            Width = 120
          end
          item
            Caption = 'Room'
            Width = 100
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        FlatScrollBars = True
        GridLines = True
        HideSelection = False
        ReadOnly = True
        RowSelect = True
        ParentFont = False
        TabOrder = 0
        ViewStyle = vsReport
        OnDblClick = lvTokensDblClick
        OnSelectItem = lvTokensSelectItem
      end
      object sPanel6: TsPanel
        Left = 0
        Top = 426
        Width = 449
        Height = 41
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 1
        object btnTokenView: TsButton
          AlignWithMargins = True
          Left = 154
          Top = 5
          Width = 138
          Height = 31
          Margins.Top = 5
          Margins.Right = 10
          Margins.Bottom = 5
          Align = alLeft
          Caption = 'View'
          Enabled = False
          ImageIndex = 130
          Images = DImages.PngImageList1
          TabOrder = 0
          OnClick = btnTokenViewClick
        end
        object btnTokenNew: TsButton
          AlignWithMargins = True
          Left = 3
          Top = 5
          Width = 138
          Height = 31
          Margins.Top = 5
          Margins.Right = 10
          Margins.Bottom = 5
          Align = alLeft
          Caption = 'New'
          DropDownMenu = mnuTokenNew
          ImageIndex = 59
          Images = DImages.PngImageList1
          Style = bsSplitButton
          TabOrder = 1
        end
        object btnCharge: TsButton
          AlignWithMargins = True
          Left = 305
          Top = 5
          Width = 138
          Height = 31
          Margins.Top = 5
          Margins.Right = 10
          Margins.Bottom = 5
          Align = alLeft
          Caption = 'Card action'
          DropDownMenu = pupCard
          Enabled = False
          ImageIndex = 89
          Images = DImages.PngImageList1
          Style = bsSplitButton
          TabOrder = 2
        end
      end
    end
    object sPanel4: TsPanel
      Left = 449
      Top = 0
      Width = 477
      Height = 467
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object sLabel1: TsLabel
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 471
        Height = 13
        Align = alTop
        Caption = 'Paycard charge history'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ExplicitWidth = 131
      end
      object lvCharges: TsListView
        AlignWithMargins = True
        Left = 3
        Top = 22
        Width = 464
        Height = 334
        Margins.Right = 10
        Align = alClient
        Color = clWhite
        Columns = <
          item
            Caption = 'When'
            Width = 120
          end
          item
            Caption = 'Operation'
            Width = 100
          end
          item
            Caption = 'Result code'
            Width = 100
          end
          item
            Alignment = taRightJustify
            Caption = 'Amount'
            Width = 100
          end
          item
            Caption = 'Currency'
            Width = 60
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        FlatScrollBars = True
        GridLines = True
        HideSelection = False
        ReadOnly = True
        RowSelect = True
        ParentFont = False
        TabOrder = 0
        ViewStyle = vsReport
        OnChange = lvChargesChange
        OnDblClick = lvChargesDblClick
        OnSelectItem = lvChargesSelectItem
      end
      object sPanel5: TsPanel
        Left = 0
        Top = 426
        Width = 477
        Height = 41
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 1
        object btnChargeView: TsButton
          AlignWithMargins = True
          Left = 3
          Top = 5
          Width = 126
          Height = 31
          Margins.Top = 5
          Margins.Right = 10
          Margins.Bottom = 5
          Align = alLeft
          Caption = 'View'
          Enabled = False
          ImageIndex = 130
          Images = DImages.PngImageList1
          TabOrder = 0
          OnClick = btnChargeViewClick
        end
        object btnRefundOrCapture: TsButton
          AlignWithMargins = True
          Left = 142
          Top = 5
          Width = 126
          Height = 31
          Margins.Top = 5
          Margins.Right = 10
          Margins.Bottom = 5
          Align = alLeft
          Caption = 'Charge action'
          DropDownMenu = pupCharge
          Enabled = False
          ImageIndex = 130
          Images = DImages.PngImageList1
          Style = bsSplitButton
          TabOrder = 1
        end
      end
      object sPanel7: TsPanel
        Left = 0
        Top = 359
        Width = 477
        Height = 67
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 2
        object sLabel7: TsLabel
          Left = 79
          Top = 26
          Width = 45
          Height = 13
          Alignment = taRightJustify
          BiDiMode = bdLeftToRight
          Caption = 'Charged:'
          ParentBiDiMode = False
        end
        object lbCharged: TsLabel
          Left = 130
          Top = 26
          Width = 80
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          BiDiMode = bdLeftToRight
          Caption = '0.00'
          ParentBiDiMode = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
        end
        object sLabel9: TsLabel
          Left = 6
          Top = 3
          Width = 76
          Height = 16
          BiDiMode = bdLeftToRight
          Caption = 'Card status'
          ParentBiDiMode = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
        end
        object sLabel10: TsLabel
          Left = 49
          Top = 45
          Width = 75
          Height = 13
          Alignment = taRightJustify
          BiDiMode = bdLeftToRight
          Caption = 'Pre-authorized:'
          ParentBiDiMode = False
        end
        object lbPreAuth: TsLabel
          Left = 130
          Top = 45
          Width = 80
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          BiDiMode = bdLeftToRight
          Caption = '0.00'
          ParentBiDiMode = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
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
    Left = 896
    Top = 360
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 816
    Top = 360
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
  object mnuTokenNew: TPopupMenu
    Left = 112
    Top = 480
    object mnuNewForRes: TMenuItem
      Caption = 'New pay-card for reservation'
      OnClick = mnuNewForResClick
    end
    object mnuNewForRoom: TMenuItem
      Caption = 'New pay-card for room '
      OnClick = mnuNewForRoomClick
    end
  end
  object pupCard: TPopupMenu
    Left = 376
    Top = 504
    object mnuCharge: TMenuItem
      Caption = 'Charge'
      OnClick = mnuChargeClick
    end
    object mnuPreAuth: TMenuItem
      Caption = 'Pre-authorize'
      OnClick = mnuPreAuthClick
    end
  end
  object pupCharge: TPopupMenu
    OnPopup = pupChargePopup
    Left = 688
    Top = 520
    object mnuCapture: TMenuItem
      Caption = 'Capture'
      OnClick = mnuCaptureClick
    end
    object mnuVoid: TMenuItem
      Caption = 'Void'
      OnClick = mnuVoidClick
    end
    object mnyRefund: TMenuItem
      Caption = 'Refund'
      OnClick = mnyRefundClick
    end
  end
end
