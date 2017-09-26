inherited FrmTokenChargeHistory: TFrmTokenChargeHistory
  BorderStyle = bsSizeable
  Caption = 'Paycards of reservation'
  ClientHeight = 471
  ClientWidth = 1000
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  ExplicitWidth = 1016
  ExplicitHeight = 510
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 451
    Width = 1000
    ExplicitTop = 465
    ExplicitWidth = 1000
  end
  object pnlTop: TsPanel [1]
    Left = 0
    Top = 0
    Width = 1000
    Height = 113
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      1000
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
      Left = 892
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
  object pnlBottom: TsPanel [2]
    Left = 0
    Top = 113
    Width = 1000
    Height = 295
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 3
    ExplicitHeight = 309
    object splGrids: TsSplitter
      AlignWithMargins = True
      Left = 452
      Top = 3
      Height = 282
      Margins.Bottom = 10
      Color = clSkyBlue
      ParentColor = False
      ExplicitLeft = 200
      ExplicitTop = 0
      ExplicitHeight = 424
    end
    object pnlLeftGrid: TsPanel
      Left = 0
      Top = 0
      Width = 449
      Height = 295
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      ExplicitHeight = 309
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
        Width = 443
        Height = 229
        Align = alClient
        Checkboxes = True
        Color = clWhite
        Columns = <
          item
            AutoSize = True
            Caption = 'Card number'
            MinWidth = 50
          end
          item
            AutoSize = True
            Caption = 'User'
            MinWidth = 50
          end
          item
            AutoSize = True
            Caption = 'When'
            MinWidth = 50
          end
          item
            AutoSize = True
            Caption = 'Room'
            MinWidth = 50
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
        ExplicitHeight = 243
      end
      object sPanel6: TsPanel
        Left = 0
        Top = 254
        Width = 449
        Height = 41
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 1
        ExplicitTop = 268
      end
    end
    object pnlRightGrid: TsPanel
      Left = 461
      Top = 0
      Width = 539
      Height = 295
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      ExplicitHeight = 309
      object sLabel1: TsLabel
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 533
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
        Width = 526
        Height = 162
        Margins.Right = 10
        Align = alClient
        Color = clWhite
        Columns = <
          item
            AutoSize = True
            Caption = 'When'
            MinWidth = 120
          end
          item
            AutoSize = True
            Caption = 'Res / RoomRes'
            MinWidth = 50
          end
          item
            AutoSize = True
            Caption = 'Operation'
            MinWidth = 50
          end
          item
            AutoSize = True
            Caption = 'Result code'
            MinWidth = 50
          end
          item
            Alignment = taRightJustify
            AutoSize = True
            Caption = 'Amount'
            MinWidth = 50
          end
          item
            AutoSize = True
            Caption = 'Currency'
            MinWidth = 50
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
        OnDblClick = lvChargesDblClick
        OnSelectItem = lvChargesSelectItem
        ExplicitHeight = 176
      end
      object sPanel5: TsPanel
        Left = 0
        Top = 254
        Width = 539
        Height = 41
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 1
        ExplicitTop = 268
      end
      object sPanel7: TsPanel
        Left = 0
        Top = 187
        Width = 539
        Height = 67
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 2
        ExplicitTop = 201
        DesignSize = (
          539
          67)
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
        object btnChargeView: TsButton
          AlignWithMargins = True
          Left = 303
          Top = 5
          Width = 105
          Height = 31
          Margins.Top = 5
          Margins.Right = 10
          Margins.Bottom = 5
          Anchors = [akTop, akRight]
          Caption = 'View Charge'
          Enabled = False
          ImageIndex = 130
          Images = DImages.PngImageList1
          TabOrder = 0
          OnClick = btnChargeViewClick
        end
        object btnRefundOrCapture: TsButton
          AlignWithMargins = True
          Left = 421
          Top = 5
          Width = 105
          Height = 31
          Margins.Top = 5
          Margins.Right = 10
          Margins.Bottom = 5
          Anchors = [akTop, akRight]
          Caption = 'Charge action'
          DropDownMenu = pupCharge
          Enabled = False
          Images = DImages.PngImageList1
          Style = bsSplitButton
          TabOrder = 1
          OnClick = btnClickDropDown
        end
      end
    end
  end
  inherited pnlButtons: TsPanel
    Top = 408
    Width = 1000
    ExplicitTop = 422
    ExplicitWidth = 1000
    inherited btnOK: TsButton
      Left = 684
      ExplicitLeft = 684
    end
    inherited btnCancel: TsButton
      Left = 790
      ExplicitLeft = 790
    end
    inherited btnClose: TsButton
      Left = 896
      ExplicitLeft = 896
    end
    object btnTokenNew: TsButton
      AlignWithMargins = True
      Left = 4
      Top = 6
      Width = 105
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
      TabOrder = 3
      OnClick = btnClickDropDown
    end
    object btnTokenView: TsButton
      AlignWithMargins = True
      Left = 122
      Top = 6
      Width = 105
      Height = 31
      Margins.Top = 5
      Margins.Right = 10
      Margins.Bottom = 5
      Align = alLeft
      Caption = 'Card info'
      Enabled = False
      ImageIndex = 130
      Images = DImages.PngImageList1
      TabOrder = 4
      OnClick = btnTokenViewClick
    end
    object btnCharge: TsButton
      AlignWithMargins = True
      Left = 240
      Top = 6
      Width = 105
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
      TabOrder = 5
      OnClick = btnClickDropDown
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 384
    Top = 8
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 304
    Top = 8
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
  object mnuTokenNew: TPopupMenu
    Left = 568
    Top = 16
    object mnuNewCardForRes: TMenuItem
      Caption = 'New pay-card for reservation'
      OnClick = mnuNewCardForResClick
    end
    object mnuNewCardForRoom: TMenuItem
      Caption = 'New pay-card for room '
      OnClick = mnuNewCardForRoomClick
    end
  end
  object pupCard: TPopupMenu
    Left = 648
    Top = 16
    object mnuChargeForReservation: TMenuItem
      Caption = 'Charge for reservation'
      OnClick = mnuChargeForReservationClick
    end
    object mnuChargeForRoom: TMenuItem
      Caption = 'Charge for Room'
      OnClick = mnuChargeForRoomClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object mnuPreAuthForReservation: TMenuItem
      Caption = 'Pre-authorize for reservation'
      OnClick = mnuPreAuthForReservationClick
    end
    object mnuPreAuthforRoom: TMenuItem
      Caption = 'Pre-authorize for Room'
      OnClick = mnuPreAuthforRoomClick
    end
  end
  object pupCharge: TPopupMenu
    OnPopup = pupChargePopup
    Left = 720
    Top = 16
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
