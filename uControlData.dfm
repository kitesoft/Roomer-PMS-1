object frmControlData: TfrmControlData
  Left = 794
  Top = 186
  BorderIcons = []
  Caption = 'Settings'
  ClientHeight = 811
  ClientWidth = 1261
  Color = clBtnFace
  ParentFont = True
  KeyPreview = True
  OldCreateOrder = True
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object __Panel2: TPanel
    Left = 0
    Top = 3
    Width = 1261
    Height = 775
    Align = alClient
    TabOrder = 1
    object sLabel4: TsLabel
      Left = 248
      Top = 120
      Width = 40
      Height = 14
      Caption = 'sLabel4'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object LMDBackPanel1: TsPanel
      Left = 1
      Top = 1
      Width = 1259
      Height = 28
      Align = alTop
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'TOOLBAR'
      object labHeader: TsLabel
        Left = 1
        Top = 1
        Width = 71
        Height = 26
        Align = alLeft
        Caption = 'Select'
        ParentFont = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -23
        Font.Name = 'Verdana'
        Font.Style = []
        ExplicitHeight = 28
      end
    end
    object LMDBackPanel2: TsPanel
      Left = 1
      Top = 29
      Width = 156
      Height = 745
      Align = alLeft
      TabOrder = 1
      SkinData.SkinSection = 'PANEL'
      object tvSelection: TsTreeView
        Left = 1
        Top = 1
        Width = 154
        Height = 743
        Align = alClient
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        Indent = 19
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
        OnChange = tvSelectionChange
        OnChanging = tvSelectionChanging
        OnCustomDrawItem = tvSelectionCustomDrawItem
        Items.NodeData = {
          030D000000280000000000000001000000FFFFFFFFFFFFFFFF00000000000000
          0000000000010548006F00740065006C00260000000000000002000000FFFFFF
          FFFFFFFFFF000000000000000000000000010449004400270073002C00000000
          00000009000000FFFFFFFFFFFFFFFF000000000000000003000000010749006E
          0076006F006900630065002E0000000000000003000000FFFFFFFFFFFFFFFF00
          00000000000000000000000108430061007000740069006F006E0073002E0000
          000000000004000000FFFFFFFFFFFFFFFF000000000000000000000000010853
          0065007400740069006E00670073002C0000000000000005000000FFFFFFFFFF
          FFFFFF000000000000000000000000010752006F007500740069006E00670038
          0000000000000006000000FFFFFFFFFFFFFFFF00000000000000000000000001
          0D52006F006F006D002000680061006E0064006C0069006E0067002600000000
          00000000000000FFFFFFFFFFFFFFFF00000000000000000200000001044C006F
          006F006B00340000000000000008000000FFFFFFFFFFFFFFFF00000000000000
          0000000000010B4D00610069006E002000730063007200650065006E002A0000
          000000000012000000FFFFFFFFFFFFFFFF000000000000000000000000010643
          006F006C006F00720073003A000000000000000E000000FFFFFFFFFFFFFFFF00
          0000000000000000000000010E50004F005300200063006F006E006E00650063
          00740069006F006E0032000000000000000D000000FFFFFFFFFFFFFFFF000000
          000000000000000000010A4100630063006F0075006E00740069006E0067002E
          0000000000000011000000FFFFFFFFFFFFFFFF00000000000000000000000001
          084D006F006E00690074006F00720073003C000000000000000B000000FFFFFF
          FFFFFFFFFF000000000000000000000000010F4300680061006E006E0065006C
          0020006D0061006E00610067006500720036000000000000000A000000FFFFFF
          FFFFFFFFFF000000000000000000000000010C52006500730065007200760061
          00740069006F006E007300480000000000000013000000FFFFFFFFFFFFFFFF00
          000000000000000000000001154D0061006E006400610074006F007200790020
          0069006E0066006F0072006D006100740069006F006E00380000000000000015
          000000FFFFFFFFFFFFFFFF000000000000000000000000010D45006D00610069
          006C00200073006500720076006900630065003A0000000000000014000000FF
          FFFFFFFFFFFFFF000000000000000000000000010E4200650074006100200046
          0075006E006300740069006F006E007300}
        SkinData.SkinSection = 'EDIT'
      end
    end
    object __LMDBackPanel3: TsPanel
      Left = 157
      Top = 29
      Width = 1103
      Height = 745
      Align = alClient
      TabOrder = 2
      SkinData.SkinSection = 'PANEL'
      object mainPage: TsPageControl
        Left = 1
        Top = 1
        Width = 1101
        Height = 743
        ActivePage = tsInvoiceSystem
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        SkinData.SkinSection = 'PAGECONTROL'
        object tsNull: TsTabSheet
          Caption = 'tsNull'
          SkinData.SkinSection = 'FORM'
        end
        object tsCompany: TsTabSheet
          Caption = 'Company'
          object gbxCompany: TsGroupBox
            Left = 3
            Top = 4
            Width = 438
            Height = 131
            Caption = 'Hotel'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object clabCompanyCode: TsLabel
              Left = 131
              Top = 18
              Width = 68
              Height = 14
              Alignment = taRightJustify
              Caption = 'Hotel code :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabCompanyPID: TsLabel
              Left = 236
              Top = 18
              Width = 60
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Hotel ID :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labCompanyName: TsLabel
              Left = 128
              Top = 46
              Width = 71
              Height = 14
              Alignment = taRightJustify
              Caption = 'Hotel name :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel18: TsLabel
              Left = 71
              Top = 74
              Width = 128
              Height = 14
              Alignment = taRightJustify
              Caption = 'UTC Time zone offset :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblNumShifts: TsLabel
              Left = 101
              Top = 102
              Width = 98
              Height = 14
              Alignment = taRightJustify
              Caption = 'Number of shifts :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object editCompanyID: TsEdit
              Left = 207
              Top = 15
              Width = 32
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              ReadOnly = True
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object editCompanyPID: TsEdit
              Left = 304
              Top = 15
              Width = 127
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
            end
            object editCompanyName: TsEdit
              Left = 207
              Top = 43
              Width = 224
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              SkinData.SkinSection = 'EDIT'
            end
            object __editTZ: TsComboBox
              Left = 207
              Top = 71
              Width = 224
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'EDIT'
              VerticalAlignment = taAlignTop
              Style = csDropDownList
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = -1
              ParentFont = False
              TabOrder = 3
              Items.Strings = (
                '-12:00'
                '-11:00'
                '-10:00'
                '-09:00'
                '-08:00'
                '-07:00'
                '-06:00'
                '-05:00'
                '-04:00'
                '-03:00'
                '-02:00'
                '-01:00'
                '+00:00'
                '+01:00'
                '+02:00'
                '+03:00'
                '+04:00'
                '+05:00'
                '+06:00'
                '+07:00'
                '+08:00'
                '+09:00'
                '+10:00'
                '+11:00'
                '+12:00'
                '+13:00'
                '+14:00')
            end
            object edtNumShifts: TsEdit
              Left = 207
              Top = 99
              Width = 66
              Height = 22
              Alignment = taRightJustify
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              NumbersOnly = True
              ParentFont = False
              TabOrder = 4
              SkinData.SkinSection = 'EDIT'
            end
          end
          object gbxAddress: TsGroupBox
            Left = 3
            Top = 141
            Width = 438
            Height = 162
            Caption = 'Address'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object clabAddress1: TsLabel
              Left = 154
              Top = 19
              Width = 51
              Height = 14
              Alignment = taRightJustify
              Caption = 'Address :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblCountry: TsLabel
              Left = 154
              Top = 131
              Width = 51
              Height = 14
              Alignment = taRightJustify
              Caption = 'Country :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object editAddress1: TsEdit
              Left = 213
              Top = 16
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object editAddress2: TsEdit
              Left = 213
              Top = 44
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
            end
            object editAddress3: TsEdit
              Left = 213
              Top = 72
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              SkinData.SkinSection = 'EDIT'
            end
            object editAddress4: TsEdit
              Left = 213
              Top = 100
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 3
              SkinData.SkinSection = 'EDIT'
            end
            inline fraCountry: TfraCountryPanel
              Left = 213
              Top = 128
              Width = 218
              Height = 20
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 4
              ExplicitLeft = 213
              ExplicitTop = 128
              ExplicitWidth = 218
              inherited pnlLookup: TsPanel
                Width = 218
                ExplicitWidth = 218
                inherited lblDescription: TsLabel
                  Width = 125
                  Height = 20
                end
              end
            end
          end
          object gbxContact: TsGroupBox
            Left = 3
            Top = 309
            Width = 440
            Height = 172
            Caption = 'Contact'
            TabOrder = 2
            SkinData.SkinSection = 'GROUPBOX'
            object clabTelephone1: TsLabel
              Left = 151
              Top = 20
              Width = 54
              Height = 14
              Alignment = taRightJustify
              Caption = 'Phone 1 :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabTelephone2: TsLabel
              Left = 151
              Top = 48
              Width = 54
              Height = 14
              Alignment = taRightJustify
              Caption = 'Phone 2 :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabFax: TsLabel
              Left = 179
              Top = 76
              Width = 26
              Height = 14
              Alignment = taRightJustify
              Caption = 'Fax :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabCompanyEmail: TsLabel
              Left = 125
              Top = 104
              Width = 80
              Height = 14
              Alignment = taRightJustify
              Caption = 'Email address :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabCompanyHomePage: TsLabel
              Left = 154
              Top = 132
              Width = 51
              Height = 14
              Alignment = taRightJustify
              Caption = 'website :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object editTelephone1: TsEdit
              Left = 213
              Top = 17
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object editTelephone2: TsEdit
              Left = 213
              Top = 45
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
            end
            object editFax: TsEdit
              Left = 213
              Top = 73
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              SkinData.SkinSection = 'EDIT'
            end
            object editCompanyEmail: TsEdit
              Left = 213
              Top = 101
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 3
              SkinData.SkinSection = 'EDIT'
            end
            object editCompanyHomePage: TsEdit
              Left = 213
              Top = 129
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 4
              SkinData.SkinSection = 'EDIT'
            end
          end
          object gbxBank: TsGroupBox
            Left = 447
            Top = 4
            Width = 471
            Height = 77
            Caption = 'Account'
            TabOrder = 3
            SkinData.SkinSection = 'GROUPBOX'
            object labCompanyVATno: TsLabel
              Left = 183
              Top = 19
              Width = 50
              Height = 14
              Alignment = taRightJustify
              Caption = 'VAT no.:'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labCompanyBankInfo: TsLabel
              Left = 116
              Top = 47
              Width = 117
              Height = 14
              Alignment = taRightJustify
              Caption = 'Hotel bank Account :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object editCompanyVATNo: TsEdit
              Left = 239
              Top = 16
              Width = 194
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object editCompanyBankInfo: TsEdit
              Left = 239
              Top = 44
              Width = 194
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
            end
          end
          object gbxComputer: TsGroupBox
            Left = 447
            Top = 88
            Width = 471
            Height = 105
            Caption = 'Computer'
            TabOrder = 4
            SkinData.SkinSection = 'GROUPBOX'
            object clabComputerName: TsLabel
              Left = 136
              Top = 19
              Width = 97
              Height = 14
              Alignment = taRightJustify
              Caption = 'Computer Name :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labSessionTimeoutSeconds: TsLabel
              Left = 179
              Top = 45
              Width = 54
              Height = 14
              Alignment = taRightJustify
              Caption = 'Timeout :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labSessionSec: TsLabel
              Left = 323
              Top = 48
              Width = 69
              Height = 15
              AutoSize = False
              Caption = 'sec.'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edHomeComputerName: TsEdit
              Left = 239
              Top = 16
              Width = 194
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object edSessionTimeoutSeconds: TsSpinEdit
              Left = 239
              Top = 44
              Width = 78
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              NumbersOnly = True
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
              AllowNegative = False
              Increment = 10
              MaxValue = 5400
              MinValue = 60
              Value = 0
            end
            object cbxBackupMachine: TsCheckBox
              Left = 239
              Top = 72
              Width = 132
              Height = 20
              Caption = 'Offline Backup Client'
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object sGroupBox10: TsGroupBox
            Left = 447
            Top = 199
            Width = 471
            Height = 130
            Caption = 'Options'
            TabOrder = 5
            SkinData.SkinSection = 'GROUPBOX'
            object lblPMSEntryPage: TsLabel
              Left = 92
              Top = 79
              Width = 91
              Height = 14
              Alignment = taRightJustify
              Caption = 'PMS entry page:'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbxLocationPerRoomType: TsCheckBox
              Left = 68
              Top = 24
              Width = 249
              Height = 20
              Caption = 'Room Location determined by Room type'
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxDefaultSendCCEmailToHotel: TsCheckBox
              Left = 68
              Top = 47
              Width = 362
              Height = 20
              Caption = 'Always send a blind copy of emails to the hotel'#39's email address'
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxPmsEntryPage: TsComboBox
              Left = 189
              Top = 76
              Width = 194
              Height = 22
              Alignment = taLeftJustify
              VerticalAlignment = taAlignTop
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = 0
              ParentFont = False
              TabOrder = 2
              Text = 'Day View'
              Items.Strings = (
                'Day View'
                'Period View'
                'Groups'
                'Dashboard'
                'Rates'
                'Frontdesk')
            end
            object cbxPreloadPreviousGuests: TsCheckBox
              Left = 68
              Top = 105
              Width = 232
              Height = 20
              Caption = 'Preload ALL previous guests for lookup'
              TabOrder = 3
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object sGroupBox18: TsGroupBox
            Left = 449
            Top = 335
            Width = 471
            Height = 105
            Caption = 'Various Services'
            TabOrder = 6
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel34: TsLabel
              Left = 52
              Top = 27
              Width = 179
              Height = 14
              Alignment = taRightJustify
              Caption = 'Currency synchronization source:'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object __CurrencySyncSource: TsComboBox
              Left = 237
              Top = 24
              Width = 194
              Height = 22
              Alignment = taLeftJustify
              VerticalAlignment = taAlignTop
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = 0
              ParentFont = False
              TabOrder = 0
              Text = '<No synchronization>'
              Items.Strings = (
                '<No synchronization>'
                'EUR_FEED_GOGGLE'
                'ISK_FEED_LANDSBANKI')
            end
          end
        end
        object tsSystemItemIDs: TsTabSheet
          Caption = 'ID Numbers'
          object cbxIdNumbers: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 137
            Align = alTop
            Caption = 'ID numbers'
            Enabled = False
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object clabLasIinvoiceNo: TsLabel
              Left = 178
              Top = 19
              Width = 93
              Height = 14
              Alignment = taRightJustify
              Caption = 'Last invoice no. :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabLastPerson: TsLabel
              Left = 178
              Top = 47
              Width = 93
              Height = 14
              Alignment = taRightJustify
              Caption = 'Last person no. :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabLastReservation: TsLabel
              Left = 155
              Top = 75
              Width = 116
              Height = 14
              Alignment = taRightJustify
              Caption = 'Last reservation no. :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabLastRoomReservation: TsLabel
              Left = 123
              Top = 103
              Width = 148
              Height = 14
              Alignment = taRightJustify
              Caption = 'Last room reservation no. :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object EditLastRoomRes: TsSpinEdit
              Left = 275
              Top = 100
              Width = 82
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object EditLastInvoice: TsSpinEdit
              Left = 275
              Top = 16
              Width = 82
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object EditLastPerson: TsSpinEdit
              Left = 275
              Top = 44
              Width = 82
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object EditLastReservation: TsSpinEdit
              Left = 275
              Top = 72
              Width = 82
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 3
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
          end
          object cbcCustomerID: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 146
            Width = 1087
            Height = 105
            Align = alTop
            Caption = 'Customer ID'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object clabCustomerNumber: TsLabel
              Left = 165
              Top = 19
              Width = 107
              Height = 14
              Alignment = taRightJustify
              Caption = 'Last customer no. :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabCustomerIDLength: TsLabel
              Left = 225
              Top = 47
              Width = 47
              Height = 14
              Alignment = taRightJustify
              Caption = 'Length :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object clabCustomerIdFillChar: TsLabel
              Left = 201
              Top = 75
              Width = 71
              Height = 14
              Alignment = taRightJustify
              Caption = 'Left fill char :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edCustIdLength: TsSpinEdit
              Left = 276
              Top = 44
              Width = 82
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object edCustIdLast: TsSpinEdit
              Left = 276
              Top = 16
              Width = 82
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object edCustIdFill: TsEdit
              Left = 276
              Top = 72
              Width = 82
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              MaxLength = 1
              ParentFont = False
              TabOrder = 2
              Text = '0'
              SkinData.SkinSection = 'EDIT'
            end
          end
          object sGroupBox11: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 257
            Width = 1087
            Height = 85
            Align = alTop
            Caption = 'Reservation defaults'
            TabOrder = 2
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel20: TsLabel
              Left = 64
              Top = 34
              Width = 206
              Height = 14
              Alignment = taRightJustify
              Caption = 'Channel confirmation email template :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbxEmailTemplates: TsComboBox
              Left = 276
              Top = 32
              Width = 469
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
              TabOrder = 0
            end
            object btnResources: TsButton
              Left = 751
              Top = 30
              Width = 125
              Height = 25
              Caption = 'Resources'
              TabOrder = 1
              OnClick = btnResourcesClick
              SkinData.SkinSection = 'BUTTON'
            end
          end
        end
        object tsInvoiceTexts: TsTabSheet
          Caption = 'Invoice texts'
          object AdvPageControl2: TsPageControl
            Left = 0
            Top = 0
            Width = 1093
            Height = 714
            ActivePage = tsInvTexts_Laser2
            Align = alClient
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            SkinData.SkinSection = 'PAGECONTROL'
            object tsInvTexts_Laser1: TsTabSheet
              Caption = '1'
              object gbxInvoiceHead: TsGroupBox
                Left = 4
                Top = 4
                Width = 417
                Height = 74
                Caption = 'Invoice head text'
                TabOrder = 0
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel1: TsLabel
                  Left = 1
                  Top = 19
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'If Invoice :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel2: TsLabel
                  Left = 1
                  Top = 47
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'If Credit invoice :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtHeadDebit: TsEdit
                  Left = 189
                  Top = 16
                  Width = 219
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadKredit: TsEdit
                  Left = 190
                  Top = 44
                  Width = 219
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxInvoiceHeadInfo: TsGroupBox
                Left = 429
                Top = 4
                Width = 417
                Height = 380
                Caption = 'Invoice head captions'
                TabOrder = 3
                SkinData.SkinSection = 'GROUPBOX'
                object clabInvoiceDate: TsLabel
                  Left = 1
                  Top = 47
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Invoice date :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabInvoiceHeadCustomerNumber: TsLabel
                  Left = 1
                  Top = 131
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Customer number :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabInvoicePayDate: TsLabel
                  Left = 1
                  Top = 75
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Invoice pay date :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabInvoiceDueDate: TsLabel
                  Left = 1
                  Top = 103
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Invoice due date :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabNativeCurrency: TsLabel
                  Left = 1
                  Top = 159
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Native currency :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabInvoiceCurrency: TsLabel
                  Left = 1
                  Top = 187
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Invoice currency :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabCurrencyRate: TsLabel
                  Left = 1
                  Top = 215
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Currency rate :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabReservationID: TsLabel
                  Left = 1
                  Top = 243
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Reservation Id :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabCreditInvoiceReference: TsLabel
                  Left = 1
                  Top = 271
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Credit invoice reference :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabOrginalInvoiceRefernce: TsLabel
                  Left = 1
                  Top = 299
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Original invoice reference :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabGuestName: TsLabel
                  Left = 1
                  Top = 327
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Guest name :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabInvTxtHeadInfoNumber: TsLabel
                  Left = 1
                  Top = 19
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Invoice number :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabGuestRoom: TsLabel
                  Left = 1
                  Top = 355
                  Width = 170
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Guest room :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtHeadInfoDate: TsEdit
                  Left = 177
                  Top = 44
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoCustomerNo: TsEdit
                  Left = 177
                  Top = 128
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoGjalddagi: TsEdit
                  Left = 177
                  Top = 72
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 3
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoEindagi: TsEdit
                  Left = 177
                  Top = 100
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 4
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoLocalCurrency: TsEdit
                  Left = 177
                  Top = 156
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 5
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoCurrency: TsEdit
                  Left = 177
                  Top = 184
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 6
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoCurrencyRate: TsEdit
                  Left = 177
                  Top = 212
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 7
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoReservation: TsEdit
                  Left = 177
                  Top = 240
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 8
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoCreditInvoice: TsEdit
                  Left = 177
                  Top = 268
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 9
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoOrginalInfo: TsEdit
                  Left = 177
                  Top = 296
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 10
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoGuest: TsEdit
                  Left = 177
                  Top = 324
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 11
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoNumber: TsEdit
                  Left = 177
                  Top = 16
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadInfoRoom: TsEdit
                  Left = 177
                  Top = 352
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 12
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxInvoicelines: TsGroupBox
                Left = 4
                Top = 84
                Width = 417
                Height = 187
                Caption = 'Invoice items column captions'
                TabOrder = 1
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel15: TsLabel
                  Left = 1
                  Top = 20
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'V'#246'run'#250'mer :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel16: TsLabel
                  Left = 1
                  Top = 48
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Text :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel17: TsLabel
                  Left = 1
                  Top = 76
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Amount :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel18: TsLabel
                  Left = 1
                  Top = 104
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Unit Price :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel19: TsLabel
                  Left = 1
                  Top = 132
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Amount :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel20: TsLabel
                  Left = 1
                  Top = 160
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Discount :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtLinesItemNo: TsEdit
                  Left = 191
                  Top = 17
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtLinesItemText: TsEdit
                  Left = 191
                  Top = 45
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtLinesItemCount: TsEdit
                  Left = 191
                  Top = 73
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtLinesItemPrice: TsEdit
                  Left = 191
                  Top = 101
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 3
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtLinesItemAmount: TsEdit
                  Left = 191
                  Top = 129
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 4
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtLinesItemTotal: TsEdit
                  Left = 191
                  Top = 157
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 5
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxInvoiceCompany: TsGroupBox
                Left = 4
                Top = 277
                Width = 417
                Height = 216
                Caption = 'Company captions'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel46: TsLabel
                  Left = 1
                  Top = 49
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Address :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel47: TsLabel
                  Left = 1
                  Top = 21
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Company name :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel48: TsLabel
                  Left = 1
                  Top = 77
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Phone 1 :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel49: TsLabel
                  Left = 1
                  Top = 105
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Phone 2 :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel50: TsLabel
                  Left = 1
                  Top = 133
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Fax :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel51: TsLabel
                  Left = 1
                  Top = 161
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Email :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel52: TsLabel
                  Left = 1
                  Top = 189
                  Width = 180
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Web page :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtCompanyName: TsEdit
                  Left = 191
                  Top = 18
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCompanyAddress: TsEdit
                  Left = 191
                  Top = 46
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCompanyTel1: TsEdit
                  Left = 191
                  Top = 74
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCompanyTel2: TsEdit
                  Left = 191
                  Top = 102
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 3
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCompanyFax: TsEdit
                  Left = 191
                  Top = 130
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 4
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCompanyEmail: TsEdit
                  Left = 191
                  Top = 158
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 5
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCompanyHomePage: TsEdit
                  Left = 191
                  Top = 186
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 6
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object GbxBankInfo: TsGroupBox
                Left = 430
                Top = 390
                Width = 417
                Height = 103
                Caption = 'Bank / account'
                TabOrder = 4
                SkinData.SkinSection = 'GROUPBOX'
                object clabVATid: TsLabel
                  Left = 1
                  Top = 48
                  Width = 171
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'VAT ID  :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabCustomerID: TsLabel
                  Left = 0
                  Top = 20
                  Width = 171
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Company ID :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object clabBankAccount: TsLabel
                  Left = 1
                  Top = 76
                  Width = 171
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Bank account :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtCompanyPID: TsEdit
                  Left = 177
                  Top = 17
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCompanyVATId: TsEdit
                  Left = 177
                  Top = 45
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCompanyBankInfo: TsEdit
                  Left = 177
                  Top = 73
                  Width = 231
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
              end
            end
            object tsInvTexts_Laser2: TsTabSheet
              Caption = '2'
              object gbxVATlist: TsGroupBox
                Left = 440
                Top = 6
                Width = 420
                Height = 214
                Caption = 'VAT columns'
                TabOrder = 3
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel25: TsLabel
                  Left = 4
                  Top = 18
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Caption :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel26: TsLabel
                  Left = 4
                  Top = 46
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Description column :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel27: TsLabel
                  Left = 4
                  Top = 74
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'No VAT column :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel28: TsLabel
                  Left = 4
                  Top = 102
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'With VAT column :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel36: TsLabel
                  Left = 4
                  Top = 158
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'VAT amount column :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel37: TsLabel
                  Left = 4
                  Top = 186
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Total column :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel45: TsLabel
                  Left = 4
                  Top = 130
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'VAT % Column % :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtVATListHead: TsEdit
                  Left = 193
                  Top = 15
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtVATListDescription: TsEdit
                  Left = 193
                  Top = 43
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtVATListwoVAT: TsEdit
                  Left = 193
                  Top = 71
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtVATListwVAT: TsEdit
                  Left = 193
                  Top = 99
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 3
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtVATListVATAmount: TsEdit
                  Left = 193
                  Top = 155
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 5
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtVATListTotal: TsEdit
                  Left = 193
                  Top = 183
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 6
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtVATListVATpr: TsEdit
                  Left = 193
                  Top = 127
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 4
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxPaymentLine: TsGroupBox
                Left = 4
                Top = 255
                Width = 417
                Height = 75
                Caption = 'Payments Column'
                TabOrder = 1
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel29: TsLabel
                  Left = 4
                  Top = 19
                  Width = 181
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Header :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel30: TsLabel
                  Left = 4
                  Top = 47
                  Width = 181
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'between :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtPaymentLineHead: TsEdit
                  Left = 192
                  Top = 16
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtPaymentLineSeperator: TsEdit
                  Left = 192
                  Top = 44
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxPaymentList: TsGroupBox
                Left = 4
                Top = 3
                Width = 417
                Height = 246
                Caption = 'Payment list columns'
                TabOrder = 0
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel31: TsLabel
                  Left = 7
                  Top = 21
                  Width = 179
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Caption :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel32: TsLabel
                  Left = 7
                  Top = 49
                  Width = 179
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Name column :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel33: TsLabel
                  Left = 7
                  Top = 77
                  Width = 179
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Amount column :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel34: TsLabel
                  Left = 7
                  Top = 105
                  Width = 179
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Date column :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel35: TsLabel
                  Left = 7
                  Top = 133
                  Width = 179
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Total :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object sLabel6: TsLabel
                  Left = 6
                  Top = 161
                  Width = 179
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Description :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object sLabel8: TsLabel
                  Left = 6
                  Top = 189
                  Width = 179
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Pre Paid :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object sLabel9: TsLabel
                  Left = 6
                  Top = 217
                  Width = 179
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Balance :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtPaymentListHead: TsEdit
                  Left = 192
                  Top = 18
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtPaymentListCode: TsEdit
                  Left = 192
                  Top = 46
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtPaymentListAmount: TsEdit
                  Left = 192
                  Top = 74
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtPaymentListDate: TsEdit
                  Left = 192
                  Top = 102
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 3
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtPaymentListTotal: TsEdit
                  Left = 192
                  Top = 130
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 4
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtPaymentListDescription: TsEdit
                  Left = 192
                  Top = 158
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 5
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadPrePaid: TsEdit
                  Left = 192
                  Top = 186
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 6
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtHeadBalance: TsEdit
                  Left = 192
                  Top = 214
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 7
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxVATline: TsGroupBox
                Left = 440
                Top = 226
                Width = 420
                Height = 74
                Caption = 'VAT row'
                TabOrder = 4
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel38: TsLabel
                  Left = 7
                  Top = 18
                  Width = 181
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Caption :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel39: TsLabel
                  Left = 7
                  Top = 46
                  Width = 181
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Separator :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtVATLineHead: TsEdit
                  Left = 193
                  Top = 15
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtVATLineSeperator: TsEdit
                  Left = 193
                  Top = 43
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxTotals: TsGroupBox
                Left = 3
                Top = 336
                Width = 417
                Height = 104
                Caption = 'Totals'
                TabOrder = 2
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel40: TsLabel
                  Left = 3
                  Top = 20
                  Width = 183
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Total no VAT :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel41: TsLabel
                  Left = 4
                  Top = 48
                  Width = 183
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Total VAT :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel42: TsLabel
                  Left = 4
                  Top = 76
                  Width = 183
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Total with VAT :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtTotalwoVAT: TsEdit
                  Left = 192
                  Top = 17
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtTotalVATAmount: TsEdit
                  Left = 192
                  Top = 45
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtTotalTotal: TsEdit
                  Left = 192
                  Top = 73
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxExtra: TsGroupBox
                Left = 440
                Top = 306
                Width = 420
                Height = 74
                Caption = 'Extra lines'
                TabOrder = 5
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel43: TsLabel
                  Left = 73
                  Top = 46
                  Width = 115
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Extra line 2 :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel44: TsLabel
                  Left = 73
                  Top = 18
                  Width = 115
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Extra line 1 :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtExtra1: TsEdit
                  Left = 193
                  Top = 15
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtExtra2: TsEdit
                  Left = 193
                  Top = 43
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
              end
            end
            object AdvTabSheet15: TsTabSheet
              Caption = '3'
              object GroupBox3: TsGroupBox
                AlignWithMargins = True
                Left = 3
                Top = 3
                Width = 1079
                Height = 78
                Align = alTop
                Caption = 'Orginal/copy'
                TabOrder = 0
                SkinData.SkinSection = 'GROUPBOX'
                object Label31: TsLabel
                  Left = 4
                  Top = 21
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Text if orginal :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object Label32: TsLabel
                  Left = 4
                  Top = 49
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Text if copy :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtOriginal: TsEdit
                  Left = 193
                  Top = 18
                  Width = 217
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtCopy: TsEdit
                  Left = 193
                  Top = 46
                  Width = 217
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object GroupBox4: TsGroupBox
                AlignWithMargins = True
                Left = 3
                Top = 87
                Width = 1079
                Height = 78
                Align = alTop
                Caption = 'Lodging tax'
                TabOrder = 1
                SkinData.SkinSection = 'GROUPBOX'
                object Label33: TsLabel
                  Left = 4
                  Top = 21
                  Width = 185
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Tax name :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object Label34: TsLabel
                  Left = 4
                  Top = 49
                  Width = 185
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Night :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edIvhTxtTotalStayTax: TsEdit
                  Left = 193
                  Top = 18
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edIvhTxtTotalStayTaxNights: TsEdit
                  Left = 193
                  Top = 46
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object gbxBottomLines: TsGroupBox
                AlignWithMargins = True
                Left = 3
                Top = 171
                Width = 1079
                Height = 135
                Align = alTop
                Caption = 'Page botton lines'
                TabOrder = 2
                SkinData.SkinSection = 'GROUPBOX'
                object LMDSimpleLabel21: TsLabel
                  Left = 6
                  Top = 22
                  Width = 52
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Line 1 :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel22: TsLabel
                  Left = 6
                  Top = 50
                  Width = 52
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Line 2 :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel23: TsLabel
                  Left = 6
                  Top = 78
                  Width = 52
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Line 3 :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object LMDSimpleLabel24: TsLabel
                  Left = 6
                  Top = 106
                  Width = 52
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Line 4 :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edinvTxtFooterLine1: TsEdit
                  Left = 64
                  Top = 19
                  Width = 628
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtFooterLine2: TsEdit
                  Left = 64
                  Top = 47
                  Width = 628
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtFooterLine3: TsEdit
                  Left = 64
                  Top = 75
                  Width = 628
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  SkinData.SkinSection = 'EDIT'
                end
                object edinvTxtFooterLine4: TsEdit
                  Left = 64
                  Top = 103
                  Width = 628
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 3
                  SkinData.SkinSection = 'EDIT'
                end
              end
              object sGroupBox8: TsGroupBox
                AlignWithMargins = True
                Left = 3
                Top = 312
                Width = 1079
                Height = 53
                Align = alTop
                Caption = 'Proforma header'
                TabOrder = 3
                SkinData.SkinSection = 'GROUPBOX'
                object sLabel15: TsLabel
                  Left = 4
                  Top = 22
                  Width = 184
                  Height = 15
                  Alignment = taRightJustify
                  AutoSize = False
                  Caption = 'Profrma header :'
                  ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = 15789037
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                end
                object edProformaheader: TsEdit
                  Left = 193
                  Top = 21
                  Width = 218
                  Height = 22
                  Color = clWhite
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlack
                  Font.Height = -12
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  SkinData.SkinSection = 'EDIT'
                end
              end
            end
          end
        end
        object tsInvoiceSystem: TsTabSheet
          Caption = 'Invoice Settings'
          object LMDGroupBox5: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 141
            Align = alTop
            Caption = 'System Sale items'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object Label24: TsLabel
              Left = 111
              Top = 18
              Width = 212
              Height = 20
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Breakfast item : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label25: TsLabel
              Left = 111
              Top = 41
              Width = 212
              Height = 19
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Room rent item : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label26: TsLabel
              Left = 111
              Top = 110
              Width = 212
              Height = 19
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Payment item : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label27: TsLabel
              Left = 111
              Top = 87
              Width = 212
              Height = 20
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Phone item : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label28: TsLabel
              Left = 111
              Top = 64
              Width = 212
              Height = 20
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Room discount item : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labBreakFastItemDescription: TsLabel
              Left = 453
              Top = 18
              Width = 4
              Height = 14
              Caption = '-'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labRoomRentItemDescription: TsLabel
              Left = 453
              Top = 41
              Width = 4
              Height = 14
              Caption = '-'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labDiscountItemDescription: TsLabel
              Left = 453
              Top = 64
              Width = 4
              Height = 14
              Caption = '-'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labPhoneUseItemDescription: TsLabel
              Left = 453
              Top = 87
              Width = 4
              Height = 14
              Caption = '-'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labPaymentItemDescription: TsLabel
              Left = 453
              Top = 110
              Width = 4
              Height = 14
              Caption = '-'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object editBreakFastItem: TsComboEdit
              Left = 327
              Top = 15
              Width = 117
              Height = 22
              AutoSize = False
              Color = clWhite
              Ctl3D = True
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              MaxLength = 20
              ParentCtl3D = False
              ParentFont = False
              TabOrder = 0
              Text = ''
              OnDblClick = editBreakFastItemDblClick
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              OnButtonClick = editBreakFastItemDblClick
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
              DirectInput = False
            end
            object editRoomRentItem: TsComboEdit
              Left = 327
              Top = 38
              Width = 117
              Height = 22
              AutoSize = False
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              MaxLength = 20
              ParentFont = False
              TabOrder = 1
              Text = ''
              OnDblClick = editRoomRentItemDblClick
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              OnButtonClick = editRoomRentItemDblClick
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
              DirectInput = False
            end
            object editDiscountItem: TsComboEdit
              Left = 327
              Top = 61
              Width = 117
              Height = 22
              AutoSize = False
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              MaxLength = 20
              ParentFont = False
              TabOrder = 2
              Text = ''
              OnDblClick = editDiscountItemDblClick
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              OnButtonClick = editDiscountItemDblClick
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
              DirectInput = False
            end
            object editPhoneUseItem: TsComboEdit
              Left = 327
              Top = 84
              Width = 117
              Height = 22
              AutoSize = False
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              MaxLength = 20
              ParentFont = False
              TabOrder = 3
              Text = ''
              OnDblClick = editPhoneUseItemDblClick
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              OnButtonClick = editPhoneUseItemDblClick
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
              DirectInput = False
            end
            object editPaymentItem: TsComboEdit
              Left = 327
              Top = 107
              Width = 117
              Height = 22
              AutoSize = False
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              MaxLength = 20
              ParentFont = False
              TabOrder = 4
              Text = ''
              OnDblClick = editPaymentItemDblClick
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              OnButtonClick = editPaymentItemDblClick
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
              DirectInput = False
            end
          end
          object LMDGroupBox1: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 396
            Width = 1087
            Height = 71
            Align = alTop
            Caption = 'Room rate '
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            ExplicitTop = 412
            object Label1: TsLabel
              Left = 6
              Top = 22
              Width = 237
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Use Arrival date rate :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label2: TsLabel
              Left = 6
              Top = 42
              Width = 237
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Breakfast included in room rent :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel7: TsLabel
              Left = 294
              Top = 22
              Width = 151
              Height = 14
              Alignment = taRightJustify
              Caption = 'VAT Included in roomrent :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object CheckBoxArrivalDateRulesPrice: TsCheckBox
              Left = 249
              Top = 20
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object CheckBoxBreakfastInclDefault: TsCheckBox
              Left = 249
              Top = 40
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object sCheckBox1: TsCheckBox
              Left = 450
              Top = 20
              Width = 20
              Height = 20
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object LMDGroupBox2_new: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 150
            Width = 1087
            Height = 99
            Align = alTop
            Caption = 'Various'
            TabOrder = 2
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel3: TsLabel
              Left = 226
              Top = 18
              Width = 97
              Height = 14
              Alignment = taRightJustify
              Caption = 'Native currency : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel21: TsLabel
              Left = 117
              Top = 44
              Width = 206
              Height = 14
              Alignment = taRightJustify
              Caption = 'Show room rent per day on invoice : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lbShowIncludedBreakfastOnInvoice: TsLabel
              Left = 562
              Top = 44
              Width = 206
              Height = 14
              Alignment = taRightJustify
              Caption = 'Show included breakfasts on invoice :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblAllowDeleteItemsFromInvoice: TsLabel
              Left = 540
              Top = 72
              Width = 228
              Height = 14
              Alignment = taRightJustify
              Caption = 'Allow deletion of items added to invoice :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lbDefaultAddressType: TsLabel
              Left = 204
              Top = 72
              Width = 117
              Height = 14
              Alignment = taRightJustify
              Caption = 'Default address type:'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbShowIncludedBreakfastOnInvoice: TsCheckBox
              Left = 774
              Top = 44
              Width = 20
              Height = 16
              TabOrder = 3
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxRoomRentPerDay: TsComboBox
              Left = 327
              Top = 41
              Width = 162
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'COMBOBOX'
              VerticalAlignment = taAlignTop
              Style = csDropDownList
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = -1
              ParentFont = False
              TabOrder = 1
            end
            object cbAllowDeleteItemsFromInvoice: TsCheckBox
              Left = 774
              Top = 70
              Width = 20
              Height = 16
              TabOrder = 4
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            inline fraCurrencyPnl: TfraCurrencyPanel
              Left = 327
              Top = 15
              Width = 250
              Height = 20
              TabOrder = 0
              ExplicitLeft = 327
              ExplicitTop = 15
              inherited pnlLookup: TsPanel
                ExplicitTop = -1
                inherited lblDescription: TsLabel
                  Width = 157
                  Height = 20
                end
              end
            end
            object cbxInvoiceAddressType: TsComboBox
              Left = 327
              Top = 69
              Width = 162
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'COMBOBOX'
              VerticalAlignment = taAlignTop
              Style = csDropDownList
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = -1
              ParentFont = False
              TabOrder = 2
            end
          end
          object LMDGroupBox26: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 343
            Width = 1087
            Height = 47
            Align = alTop
            Caption = 'A/R '
            TabOrder = 3
            SkinData.SkinSection = 'GROUPBOX'
            ExplicitTop = 359
            object Label65: TsLabel
              Left = 109
              Top = 20
              Width = 212
              Height = 17
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Payment type for A/R :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labInvPriceGroup: TsLabel
              Left = 453
              Top = 20
              Width = 4
              Height = 14
              Caption = '-'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edInvPriceGroup: TsComboEdit
              Left = 327
              Top = 17
              Width = 117
              Height = 22
              AutoSize = False
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              Text = ''
              OnDblClick = edInvPriceGroupDblClick
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
            end
          end
          object sGroupBox19: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 574
            Width = 1087
            Height = 107
            Align = alTop
            Caption = 'Payments'
            TabOrder = 4
            SkinData.SkinSection = 'GROUPBOX'
            ExplicitTop = 590
            object sLabel12: TsLabel
              Left = 202
              Top = 18
              Width = 242
              Height = 14
              Alignment = taRightJustify
              Caption = 'Allow payment higher than invoice balance :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblRequireExactClosingPayment: TsLabel
              Left = 111
              Top = 58
              Width = 333
              Height = 14
              Alignment = taRightJustify
              Caption = 'Require closing payment to be equal to the invoice balance :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel17: TsLabel
              Left = 185
              Top = 38
              Width = 259
              Height = 14
              Alignment = taRightJustify
              Caption = 'Allow withdrawal without payment guarantee :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblAllowPaymentModifications: TsLabel
              Left = 266
              Top = 78
              Width = 178
              Height = 14
              Alignment = taRightJustify
              Caption = 'Allow modification of payments :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object chkNegInvoice: TsCheckBox
              Left = 450
              Top = 18
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxRequireExactClosingPayment: TsCheckBox
              Left = 450
              Top = 58
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxWithdrawalWithoutGuarantee: TsCheckBox
              Left = 450
              Top = 38
              Width = 20
              Height = 20
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbAllowPaymentModification: TsCheckBox
              Left = 450
              Top = 77
              Width = 20
              Height = 20
              TabOrder = 3
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object sPanel2: TsPanel
            AlignWithMargins = True
            Left = 3
            Top = 473
            Width = 1087
            Height = 95
            Align = alTop
            AutoSize = True
            BevelOuter = bvNone
            TabOrder = 5
            ExplicitTop = 489
            object cxGroupBox5: TsGroupBox
              Left = 0
              Top = 0
              Width = 280
              Height = 95
              Caption = 'Start price for phone - Choose one'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'GROUPBOX'
              object Label69: TsLabel
                Left = -2
                Top = 70
                Width = 184
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Minium price :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object Label70: TsLabel
                Left = 33
                Top = 20
                Width = 149
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Start rate :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object Label71: TsLabel
                Left = 8
                Top = 45
                Width = 175
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Minimum steps :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object edCallMinUnits: TsSpinEdit
                Left = 191
                Top = 42
                Width = 76
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = edCallMinUnitsChange
                SkinData.SkinSection = 'EDIT'
                MaxValue = 9999999
                MinValue = -1
                Value = 0
              end
              object edCallMinPrice: TsCalcEdit
                Left = 191
                Top = 67
                Width = 76
                Height = 22
                AutoSize = False
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = edCallMinPriceChange
                SkinData.SkinSection = 'EDIT'
                GlyphMode.Blend = 0
                GlyphMode.Grayed = False
              end
              object edCallStartPrice: TsCalcEdit
                Left = 191
                Top = 17
                Width = 76
                Height = 22
                AutoSize = False
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = edCallStartPriceChange
                SkinData.SkinSection = 'EDIT'
                GlyphMode.Blend = 0
                GlyphMode.Grayed = False
              end
            end
            object cxGroupBox4: TsGroupBox
              Left = 311
              Top = 0
              Width = 338
              Height = 95
              Caption = 'Phone log'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'GROUPBOX'
              object Label66: TsLabel
                Left = -6
                Top = 66
                Width = 139
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Minimum time (sec) :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object Label67: TsLabel
                Left = 29
                Top = 18
                Width = 104
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Level :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object Label68: TsLabel
                Left = 29
                Top = 43
                Width = 104
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Log internal :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object chkCallLogInternal: TsCheckBox
                Left = 139
                Top = 41
                Width = 20
                Height = 20
                TabOrder = 0
                SkinData.SkinSection = 'CHECKBOX'
                ImgChecked = 0
                ImgUnchecked = 0
              end
              object cbxCallType: TsComboBox
                Left = 139
                Top = 15
                Width = 129
                Height = 22
                Alignment = taLeftJustify
                SkinData.SkinSection = 'COMBOBOX'
                VerticalAlignment = taAlignTop
                Style = csDropDownList
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ItemIndex = 3
                ParentFont = False
                TabOrder = 1
                Text = 'Just charged'
                Items.Strings = (
                  'All calls '
                  'Just Incoming calls'
                  'Just Outgoing calls'
                  'Just charged')
              end
              object edCallMinSec: TsSpinEdit
                Left = 139
                Top = 63
                Width = 128
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                SkinData.SkinSection = 'EDIT'
                MaxValue = 9999999
                MinValue = -1
                Value = 0
              end
            end
          end
          object sGroupBox4: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 255
            Width = 1087
            Height = 82
            Align = alTop
            Caption = 'Citytax'
            TabOrder = 6
            SkinData.SkinSection = 'GROUPBOX'
            ExplicitTop = 271
            object lbUseStayTax: TsLabel
              Left = 332
              Top = 13
              Width = 87
              Height = 14
              Alignment = taRightJustify
              Caption = 'Enable staytax :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lbAllowTogglingOfCityTaxesOnInvoice: TsLabel
              Left = 216
              Top = 35
              Width = 203
              Height = 14
              Alignment = taRightJustify
              Caption = 'Allow toggling of city tax on invoice :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lbAggregateCityTax: TsLabel
              Left = 195
              Top = 56
              Width = 224
              Height = 14
              Alignment = taRightJustify
              Caption = 'Aggregate citytax on invoice by default :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbUseStaytax: TsCheckBox
              Left = 425
              Top = 11
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbAllowTogglingOfCityTaxesOnInvoice: TsCheckBox
              Left = 425
              Top = 34
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbAggregateCityTax: TsCheckBox
              Left = 425
              Top = 55
              Width = 20
              Height = 20
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
        end
        object tsInvoiceRouting: TsTabSheet
          Caption = 'Invoice Routing'
          object sGroupBox15: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 121
            Align = alTop
            Caption = 'Room-invoices'
            Color = 14540253
            Font.Charset = DEFAULT_CHARSET
            Font.Color = 4013373
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentBackground = False
            ParentColor = False
            ParentFont = False
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel29: TsLabel
              Left = 127
              Top = 29
              Width = 152
              Height = 14
              Alignment = taRightJustify
              Caption = 'Default invoice indexes for :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel25: TsLabel
              Left = 213
              Top = 58
              Width = 66
              Height = 14
              Alignment = taRightJustify
              Caption = 'Room rent :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel26: TsLabel
              Left = 137
              Top = 86
              Width = 142
              Height = 14
              Alignment = taRightJustify
              Caption = 'Connected POS systems :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edtRIIndexRoomRent: TsSpinEdit
              Left = 283
              Top = 55
              Width = 82
              Height = 22
              Alignment = taCenter
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              NumbersOnly = True
              ParentFont = False
              TabOrder = 0
              Text = '1'
              SkinData.SkinSection = 'EDIT'
              MaxValue = 10
              MinValue = 1
              Value = 1
            end
            object edtRIIndexPosItems: TsSpinEdit
              Left = 283
              Top = 83
              Width = 82
              Height = 22
              Alignment = taCenter
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              NumbersOnly = True
              ParentFont = False
              TabOrder = 1
              Text = '1'
              SkinData.SkinSection = 'EDIT'
              MaxValue = 10
              MinValue = 1
              Value = 1
            end
          end
          object sGroupBox16: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 130
            Width = 1087
            Height = 121
            Align = alTop
            Caption = 'Group-invoices'
            Color = 14540253
            Font.Charset = DEFAULT_CHARSET
            Font.Color = 4013373
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentBackground = False
            ParentColor = False
            ParentFont = False
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel27: TsLabel
              Left = 127
              Top = 29
              Width = 152
              Height = 14
              Alignment = taRightJustify
              Caption = 'Default invoice indexes for :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel28: TsLabel
              Left = 213
              Top = 58
              Width = 66
              Height = 14
              Alignment = taRightJustify
              Caption = 'Room rent :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel30: TsLabel
              Left = 137
              Top = 86
              Width = 142
              Height = 14
              Alignment = taRightJustify
              Caption = 'Connected POS systems :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edtGIIndexRoomRent: TsSpinEdit
              Left = 283
              Top = 55
              Width = 82
              Height = 22
              Alignment = taCenter
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              NumbersOnly = True
              ParentFont = False
              TabOrder = 0
              Text = '1'
              SkinData.SkinSection = 'EDIT'
              MaxValue = 10
              MinValue = 1
              Value = 1
            end
            object edtGIIndexPosItems: TsSpinEdit
              Left = 283
              Top = 83
              Width = 82
              Height = 22
              Alignment = taCenter
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              NumbersOnly = True
              ParentFont = False
              TabOrder = 1
              Text = '1'
              SkinData.SkinSection = 'EDIT'
              MaxValue = 10
              MinValue = 1
              Value = 1
            end
          end
        end
        object tsRoomStatusColors: TsTabSheet
          Caption = 'Room Status Texts'
          object LMDGroupBox3: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 279
            Width = 1087
            Height = 106
            Align = alTop
            Caption = 'Room status texts'
            TabOrder = 0
            Visible = False
            SkinData.SkinSection = 'GROUPBOX'
            object EditGreenColor: TsEdit
              Left = 10
              Top = 20
              Width = 195
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object EditPurpleColor: TsEdit
              Left = 10
              Top = 46
              Width = 195
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
            end
            object EditFuchsiaColor: TsEdit
              Left = 10
              Top = 72
              Width = 195
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              SkinData.SkinSection = 'EDIT'
            end
            object Edit4: TsEdit
              Left = 211
              Top = 20
              Width = 20
              Height = 21
              TabStop = False
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 3
              SkinData.SkinSection = 'UNKNOWN'
            end
            object Edit5: TsEdit
              Left = 211
              Top = 46
              Width = 20
              Height = 21
              TabStop = False
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 4
              SkinData.SkinSection = 'UNKNOWN'
            end
            object Edit6: TsEdit
              Left = 211
              Top = 72
              Width = 20
              Height = 21
              TabStop = False
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 5
              SkinData.SkinSection = 'UNKNOWN'
            end
          end
          object sGroupBox6: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 83
            Width = 1087
            Height = 74
            Align = alTop
            Caption = 'Set unclean'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object Label56: TsLabel
              Left = 3
              Top = 23
              Width = 419
              Height = 16
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Set unclean when checked out'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel11: TsLabel
              Left = 3
              Top = 45
              Width = 419
              Height = 19
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Set unclean overnight'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object chkUseSetUnclean: TsCheckBox
              Left = 432
              Top = 23
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object ChkMakeRoomsDirtyOvernight: TsCheckBox
              Left = 432
              Top = 45
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object sGroupBox9: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 74
            Align = alTop
            Caption = 'Check in/out'
            TabOrder = 2
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel16: TsLabel
              Left = 3
              Top = 19
              Width = 419
              Height = 18
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Open details dialog during check-in'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel22: TsLabel
              Left = 3
              Top = 42
              Width = 419
              Height = 18
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Open payment dialog during check-out'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbxCheckInDetailsDialog: TsCheckBox
              Left = 432
              Top = 19
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxCheckOutPaymentsDialog: TsCheckBox
              Left = 432
              Top = 41
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object sGroupBox17: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 163
            Width = 1087
            Height = 110
            Align = alTop
            Caption = 'Various options'
            TabOrder = 3
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel31: TsLabel
              Left = 3
              Top = 23
              Width = 419
              Height = 16
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Warn when checking in to a dirty room'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel32: TsLabel
              Left = 3
              Top = 45
              Width = 419
              Height = 19
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Warn when manually making an overbooking'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel33: TsLabel
              Left = 3
              Top = 69
              Width = 419
              Height = 19
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Warn when moving room to a different room-type'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edtWarnCheckInDirtyRoom: TsCheckBox
              Left = 432
              Top = 23
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object edtWarnWhenOverbooking: TsCheckBox
              Left = 432
              Top = 45
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object edtWarnMoveRoomToNewRoomtype: TsCheckBox
              Left = 432
              Top = 67
              Width = 20
              Height = 20
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
        end
        object tsMail: TsTabSheet
          Caption = 'Mail'
          TabVisible = False
          object sLabel5: TsLabel
            Left = 24
            Top = 17
            Width = 94
            Height = 14
            Caption = 'Channel manager'
            ParentFont = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = 15789037
            Font.Height = -12
            Font.Name = 'Tahoma'
            Font.Style = []
          end
          object LMDGroupBox8: TsGroupBox
            Left = 4
            Top = 4
            Width = 350
            Height = 69
            Caption = 'Mail Servers'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object Label16: TsLabel
              Left = 58
              Top = 19
              Width = 60
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'POP :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 15789037
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label17: TsLabel
              Left = 58
              Top = 41
              Width = 60
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'SMPT :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 15789037
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object editMailHost: TsEdit
              Left = 124
              Top = 15
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 4737096
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object editSmtpHost: TsEdit
              Left = 124
              Top = 39
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 4737096
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
            end
          end
          object LMDGroupBox9: TsGroupBox
            Left = 6
            Top = 76
            Width = 350
            Height = 129
            Caption = 'Email'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object Label18: TsLabel
              Left = 9
              Top = 21
              Width = 109
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Address :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 15789037
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label19: TsLabel
              Left = 9
              Top = 41
              Width = 109
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'User :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 15789037
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label20: TsLabel
              Left = 9
              Top = 63
              Width = 109
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Password :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 15789037
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label21: TsLabel
              Left = 9
              Top = 85
              Width = 109
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'MachineName :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 15789037
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label22: TsLabel
              Left = 9
              Top = 107
              Width = 109
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Active :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 15789037
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object editEmailAddress: TsEdit
              Left = 123
              Top = 17
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 4737096
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object editMailUser: TsEdit
              Left = 123
              Top = 39
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 4737096
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
            end
            object editMailPassword: TsEdit
              Left = 123
              Top = 61
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 4737096
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              SkinData.SkinSection = 'EDIT'
            end
            object editMailMachineName: TsEdit
              Left = 123
              Top = 84
              Width = 218
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 4737096
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 3
              SkinData.SkinSection = 'EDIT'
            end
            object CheckBoxMailActive: TsCheckBox
              Left = 124
              Top = 108
              Width = 20
              Height = 20
              TabOrder = 4
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
        end
        object tsLookMainScreen: TsTabSheet
          Caption = 'tsLookMainScreen'
          object GroupBox1: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 139
            Align = alTop
            Caption = 'One day grid'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object Label10: TsLabel
              Left = 102
              Top = 24
              Width = 182
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Font : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label12: TsLabel
              Left = 102
              Top = 52
              Width = 182
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Row height : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblShowRoomAsPaidWhenZero: TsLabel
              Left = 50
              Top = 77
              Width = 230
              Height = 14
              Alignment = taRightJustify
              Caption = 'Show room as paid when balance is zero :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edGrandRowHeight: TsSpinEdit
              Left = 288
              Top = 49
              Width = 60
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object rgrNameOrder: TsRadioGroup
              Left = 583
              Top = 13
              Width = 185
              Height = 100
              Caption = 'Nameorder'
              ParentBackground = False
              TabOrder = 1
              SkinData.SkinSection = 'GROUPBOX'
              Items.Strings = (
                'Reservation - guest'
                'Guest - reservation'
                'Guest'
                'Reservation')
            end
            object fcCurrentFontName: TsFontComboBox
              Left = 288
              Top = 21
              Width = 218
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'COMBOBOX'
              VerticalAlignment = taAlignTop
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              OnCloseUp = fcCurrentFontNameCloseUp
            end
            object edCurrentFontSize: TsSpinEdit
              Left = 512
              Top = 21
              Width = 63
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 3
              SkinData.SkinSection = 'EDIT'
              MaxValue = 72
              MinValue = 6
              Value = 0
            end
            object cbxShowRoomAsPaidWhenZero: TsCheckBox
              Left = 288
              Top = 77
              Width = 20
              Height = 20
              TabOrder = 4
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object GroupBox2: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 148
            Width = 1087
            Height = 127
            Align = alTop
            Caption = 'Period grid'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object Label13: TsLabel
              Left = 89
              Top = 21
              Width = 195
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Font : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label14: TsLabel
              Left = 103
              Top = 47
              Width = 180
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Days to show : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label15: TsLabel
              Left = 103
              Top = 72
              Width = 180
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Row height : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label23: TsLabel
              Left = 89
              Top = 98
              Width = 195
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Col width : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edFiveDayColWidth: TsSpinEdit
              Left = 288
              Top = 96
              Width = 60
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object edFiveDayRowHeight: TsSpinEdit
              Left = 288
              Top = 70
              Width = 60
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object edFiveDayColCount: TsSpinEdit
              Left = 288
              Top = 44
              Width = 60
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              SkinData.SkinSection = 'EDIT'
              MaxValue = 9999999
              MinValue = -1
              Value = 0
            end
            object rgrNameOrderPeriod: TsRadioGroup
              Left = 583
              Top = 9
              Width = 185
              Height = 105
              Caption = 'Nameorder'
              ParentBackground = False
              TabOrder = 3
              SkinData.SkinSection = 'GROUPBOX'
              Items.Strings = (
                'Reservation - guest'
                'Guest - reservation'
                'Guest'
                'Reservation')
            end
            object cxGroupBox1: TsGroupBox
              Left = 354
              Top = 37
              Width = 221
              Height = 80
              Caption = 'Day format in header'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 4
              SkinData.SkinSection = 'GROUPBOX'
              object Label29: TsLabel
                Left = 3
                Top = 23
                Width = 69
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Row 1 : '
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object Label30: TsLabel
                Left = 2
                Top = 49
                Width = 69
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Row 2 : '
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object edFiveDayDateFormat1: TsEdit
                Left = 77
                Top = 20
                Width = 137
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                SkinData.SkinSection = 'EDIT'
              end
              object edFiveDayDateFormat2: TsEdit
                Left = 77
                Top = 46
                Width = 137
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                SkinData.SkinSection = 'EDIT'
              end
            end
            object fc5DayFontName: TsFontComboBox
              Left = 288
              Top = 16
              Width = 218
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'COMBOBOX'
              VerticalAlignment = taAlignTop
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 5
              OnCloseUp = fcCurrentFontNameCloseUp
            end
            object ed5DayFontSize: TsSpinEdit
              Left = 512
              Top = 16
              Width = 63
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 6
              SkinData.SkinSection = 'EDIT'
              MaxValue = 72
              MinValue = 6
              Value = 0
            end
          end
        end
        object tsInvoiceMain: TsTabSheet
          Caption = 'tsInvoiceMain'
          object LMDGroupBox10: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 80
            Align = alTop
            Caption = 'Invoice template'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            DesignSize = (
              1087
              80)
            object Label4: TsLabel
              Left = 95
              Top = 21
              Width = 83
              Height = 14
              Alignment = taRightJustify
              Caption = 'Native invoice :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label6: TsLabel
              Left = 89
              Top = 47
              Width = 89
              Height = 14
              Alignment = taRightJustify
              Caption = 'Foreign invoice :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edInvoiceFormFileISL: TsFilenameEdit
              Left = 181
              Top = 20
              Width = 898
              Height = 21
              Anchors = [akLeft, akTop, akRight]
              AutoSize = False
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              MaxLength = 255
              ParentFont = False
              TabOrder = 0
              Text = ''
              OnChange = edInvoiceFormFileISLChange
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
            end
            object edInvoiceFormFileERL: TsFilenameEdit
              Left = 181
              Top = 47
              Width = 898
              Height = 20
              Anchors = [akLeft, akTop, akRight]
              AutoSize = False
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              MaxLength = 255
              ParentFont = False
              TabOrder = 1
              Text = ''
              OnChange = edInvoiceFormFileERLChange
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
            end
          end
          object LMDGroupBox21: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 89
            Width = 1087
            Height = 74
            Align = alTop
            Caption = 'Printers'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object Label8: TsLabel
              Left = 92
              Top = 19
              Width = 87
              Height = 14
              Alignment = taRightJustify
              Caption = 'Invoice printer :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label9: TsLabel
              Left = 94
              Top = 47
              Width = 85
              Height = 14
              Alignment = taRightJustify
              Caption = 'Report printer :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbxInvoicePrinter: TComboBox
              Left = 182
              Top = 16
              Width = 392
              Height = 22
              Style = csDropDownList
              TabOrder = 0
              Items.Strings = (
                'Default printer'
                'Prenrari n'#250'mer eitt'
                'Prenrari n'#250'mer 2'
                'Printer three')
            end
            object cbxReportPrinter: TComboBox
              Left = 182
              Top = 44
              Width = 392
              Height = 22
              Style = csDropDownList
              TabOrder = 1
              Items.Strings = (
                'Default printer'
                'Prenrari n'#250'mer eitt'
                'Prenrari n'#250'mer 2'
                'Printer three')
            end
          end
        end
        object tsInvEmail: TsTabSheet
          Caption = 'Reservations'
          object LMDGroupBox25: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 48
            Align = alTop
            Caption = 'Default customer (Rack Customer)'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object Label64: TsLabel
              Left = 6
              Top = 21
              Width = 131
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Customer :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            inline fraRackCustomerPanel: TfraCustomerPanel
              AlignWithMargins = True
              Left = 147
              Top = 19
              Width = 935
              Height = 20
              Margins.Left = 145
              Align = alTop
              TabOrder = 0
              ExplicitLeft = 147
              ExplicitTop = 19
              ExplicitWidth = 935
              inherited pnlLookup: TsPanel
                Width = 935
                ExplicitWidth = 935
                inherited lblDescription: TsLabel
                  Width = 809
                  Height = 20
                end
              end
            end
          end
          object gbxExcludeRoomStatusFromStats: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 57
            Width = 1087
            Height = 91
            Align = alTop
            Caption = 'Exclude from App and LiveData statistics:'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object chkExcluteWaitingList: TsCheckBox
              Left = 14
              Top = 21
              Width = 112
              Height = 20
              Caption = 'Optional booking'
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkExcluteAllotment: TsCheckBox
              Left = 14
              Top = 41
              Width = 73
              Height = 20
              Caption = 'Allotment'
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkExcluteOrder: TsCheckBox
              Left = 14
              Top = 61
              Width = 51
              Height = 20
              Caption = 'Order'
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkExcluteNoShow: TsCheckBox
              Left = 276
              Top = 41
              Width = 68
              Height = 20
              Caption = 'No show'
              TabOrder = 3
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkExcluteDeparted: TsCheckBox
              Left = 141
              Top = 21
              Width = 71
              Height = 20
              Caption = 'Departed'
              TabOrder = 4
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkExcluteBlocked: TsCheckBox
              Left = 276
              Top = 21
              Width = 62
              Height = 20
              Caption = 'Blocked'
              TabOrder = 5
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkExcluteGuest: TsCheckBox
              Left = 141
              Top = 41
              Width = 52
              Height = 20
              Caption = 'Guest'
              TabOrder = 6
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object gbxReservationLifeCyclemailerSettings: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 251
            Width = 1087
            Height = 198
            Align = alTop
            Caption = 'Reservation Lifecycle Mailer settings'
            TabOrder = 2
            SkinData.SkinSection = 'GROUPBOX'
            object lblPreArrival: TsLabel
              Left = 38
              Top = 27
              Width = 82
              Height = 14
              Alignment = taRightJustify
              Caption = 'Pre Arrival mail:'
            end
            object lblPostDeparture: TsLabel
              Left = 9
              Top = 91
              Width = 111
              Height = 14
              Alignment = taRightJustify
              Caption = 'Post Departure mail:'
            end
            object cbxPreArrivalEnabled: TsCheckBox
              Left = 141
              Top = 25
              Width = 20
              Height = 20
              TabOrder = 0
              OnClick = cbxPreArrivalEnabledClick
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxPostDepartureEnabled: TsCheckBox
              Left = 141
              Top = 89
              Width = 20
              Height = 20
              TabOrder = 2
              OnClick = cbxPostDepartureEnabledClick
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object pnlPreArrival: TsPanel
              AlignWithMargins = True
              Left = 202
              Top = 16
              Width = 880
              Height = 65
              Margins.Left = 200
              Margins.Top = 0
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 1
              SkinData.SkinSection = 'PANEL'
              object sLabel37: TsLabel
                Left = 21
                Top = 11
                Width = 75
                Height = 14
                Alignment = taRightJustify
                Caption = 'Hours before:'
              end
              object sLabel38: TsLabel
                Left = 207
                Top = 11
                Width = 105
                Height = 14
                Alignment = taRightJustify
                Caption = 'Email address from:'
              end
              object sLabel39: TsLabel
                Left = 294
                Top = 39
                Width = 18
                Height = 14
                Alignment = taRightJustify
                Caption = 'CC:'
              end
              object edHoursBefore: TsSpinEdit
                Left = 102
                Top = 8
                Width = 92
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                NumbersOnly = True
                ParentFont = False
                TabOrder = 0
                SkinData.SkinSection = 'EDIT'
                MaxValue = 9999999
                MinValue = 1
                Value = 0
              end
              object edPreArrivalMailFromAddress: TsEdit
                Left = 318
                Top = 8
                Width = 209
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = checkEmailRegEx
                OnExit = checkEmailRegEx
                SkinData.SkinSection = 'EDIT'
              end
              object edPreArrivalCCMailTo: TsEdit
                Left = 318
                Top = 36
                Width = 209
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = checkEmailRegEx
                OnExit = checkEmailRegEx
              end
            end
            object pnlPostDeparture: TsPanel
              AlignWithMargins = True
              Left = 202
              Top = 84
              Width = 880
              Height = 73
              Margins.Left = 200
              Margins.Top = 0
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 3
              SkinData.SkinSection = 'PANEL'
              object sLabel41: TsLabel
                Left = 31
                Top = 7
                Width = 65
                Height = 14
                Alignment = taRightJustify
                Caption = 'Hours after:'
              end
              object sLabel42: TsLabel
                Left = 207
                Top = 7
                Width = 105
                Height = 14
                Alignment = taRightJustify
                Caption = 'Email address from:'
              end
              object sLabel43: TsLabel
                Left = 294
                Top = 35
                Width = 18
                Height = 14
                Alignment = taRightJustify
                Caption = 'CC:'
              end
              object edHoursAfter: TsSpinEdit
                Left = 102
                Top = 4
                Width = 92
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                NumbersOnly = True
                ParentFont = False
                TabOrder = 0
                MaxValue = 9999999
                MinValue = 1
                Value = 0
              end
              object edPostDepartureMailFromAddress: TsEdit
                Left = 318
                Top = 4
                Width = 209
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = checkEmailRegEx
                OnExit = checkEmailRegEx
              end
              object edPostDepartureCCMailTo: TsEdit
                Left = 318
                Top = 32
                Width = 209
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = checkEmailRegEx
                OnExit = checkEmailRegEx
              end
            end
          end
          object gbxReservationProfileFunctionality: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 154
            Width = 1087
            Height = 91
            Align = alTop
            Caption = 'ReservationProfile functionality'
            TabOrder = 3
            SkinData.SkinSection = 'GROUPBOX'
            object chkChangeNationality: TsCheckBox
              Left = 22
              Top = 29
              Width = 189
              Height = 20
              Caption = 'Change nationality of all guests'
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkAllowAllotmentStateChange: TsCheckBox
              Left = 22
              Top = 55
              Width = 420
              Height = 20
              Caption = 
                'Allow changing reservation state from Allotment to Reservation a' +
                'nd back'
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
        end
        object AdvTabSheet3: TsTabSheet
          Caption = 'Channelmanager'
          object sGroupBox1: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 46
            Align = alTop
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object labChannelManager: TsLabel
              Left = 202
              Top = 20
              Width = 4
              Height = 14
              Caption = '-'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labDefaultChannelManager: TsLabel
              Left = 13
              Top = 20
              Width = 106
              Height = 14
              Caption = 'Channel manager : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edChannelManager: TsComboEdit
              Left = 128
              Top = 17
              Width = 68
              Height = 22
              AutoSize = False
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              Text = ''
              OnDblClick = edChannelManagerDblClick
              CheckOnExit = True
              SkinData.SkinSection = 'EDIT'
              OnButtonClick = edChannelManagerDblClick
              GlyphMode.Blend = 0
              GlyphMode.Grayed = False
            end
          end
          object sGroupBox3: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 55
            Width = 1087
            Height = 184
            Align = alTop
            Caption = 'Revenue Management Parameters'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object labExpensiveChannelsLevelFrom: TsLabel
              Left = 13
              Top = 27
              Width = 244
              Height = 15
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Expensive Channels Compensation Level :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labspringStarts: TsLabel
              Left = 13
              Top = 55
              Width = 109
              Height = 15
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Spring starts :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labsummerStarts: TsLabel
              Left = 13
              Top = 83
              Width = 109
              Height = 15
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Summer starts :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labautumnStarts: TsLabel
              Left = 13
              Top = 111
              Width = 109
              Height = 15
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Autumn starts :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labwinterStarts: TsLabel
              Left = 13
              Top = 139
              Width = 109
              Height = 15
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Winter starts :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object edExpensiveChannelsLevelFrom: TsSpinEdit
              Left = 263
              Top = 24
              Width = 78
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
              MaxValue = 99999
              MinValue = 0
              Value = 0
            end
            object __cbxSpringStartsMonth: TsComboBox
              Left = 128
              Top = 52
              Width = 129
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'COMBOBOX'
              VerticalAlignment = taAlignTop
              Style = csDropDownList
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = 0
              ParentFont = False
              TabOrder = 1
              Text = 'January '
              OnChange = __cbxSpringStartsMonthChange
              Items.Strings = (
                'January '
                'February'
                'March'
                'April '
                'May '
                'June'
                'July'
                'August '
                'September'
                'October'
                'November '
                'December ')
            end
            object edspringStartsDay: TsSpinEdit
              Left = 263
              Top = 52
              Width = 78
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              Text = '1'
              SkinData.SkinSection = 'EDIT'
              MaxValue = 31
              MinValue = 1
              Value = 1
            end
            object __cbxsummerStartsMonth: TsComboBox
              Left = 128
              Top = 80
              Width = 129
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'COMBOBOX'
              VerticalAlignment = taAlignTop
              Style = csDropDownList
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = 0
              ParentFont = False
              TabOrder = 3
              Text = 'January '
              OnChange = __cbxsummerStartsMonthChange
              Items.Strings = (
                'January '
                'February'
                'March'
                'April '
                'May '
                'June'
                'July'
                'August '
                'September'
                'October'
                'November '
                'December ')
            end
            object edsummerStartsDay: TsSpinEdit
              Left = 263
              Top = 80
              Width = 78
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 4
              Text = '1'
              SkinData.SkinSection = 'EDIT'
              MaxValue = 31
              MinValue = 1
              Value = 1
            end
            object __cbxAutumnStartsMonth: TsComboBox
              Left = 128
              Top = 108
              Width = 129
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'COMBOBOX'
              VerticalAlignment = taAlignTop
              Style = csDropDownList
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = 0
              ParentFont = False
              TabOrder = 5
              Text = 'January '
              OnChange = __cbxAutumnStartsMonthChange
              Items.Strings = (
                'January '
                'February'
                'March'
                'April '
                'May '
                'June'
                'July'
                'August '
                'September'
                'October'
                'November '
                'December ')
            end
            object edautumnStartsDay: TsSpinEdit
              Left = 263
              Top = 108
              Width = 78
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 6
              Text = '1'
              SkinData.SkinSection = 'EDIT'
              MaxValue = 31
              MinValue = 1
              Value = 1
            end
            object __cbxWinterStartsMonth: TsComboBox
              Left = 128
              Top = 136
              Width = 129
              Height = 22
              Alignment = taLeftJustify
              SkinData.SkinSection = 'COMBOBOX'
              VerticalAlignment = taAlignTop
              Style = csDropDownList
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemIndex = 0
              ParentFont = False
              TabOrder = 7
              Text = 'January '
              OnChange = __cbxWinterStartsMonthChange
              Items.Strings = (
                'January '
                'February'
                'March'
                'April '
                'May '
                'June'
                'July'
                'August '
                'September'
                'October'
                'November '
                'December ')
            end
            object edwinterStartsDay: TsSpinEdit
              Left = 263
              Top = 136
              Width = 78
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 8
              Text = '1'
              SkinData.SkinSection = 'EDIT'
              MaxValue = 31
              MinValue = 1
              Value = 1
            end
          end
          object sGroupBox14: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 245
            Width = 1087
            Height = 98
            Align = alTop
            Caption = 'Various Settings'
            TabOrder = 2
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel23: TsLabel
              Left = 43
              Top = 20
              Width = 383
              Height = 14
              Alignment = taRightJustify
              Caption = 
                'Automatically add guests of incoming bookings to the Guest portf' +
                'olio:'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel24: TsLabel
              Left = 324
              Top = 42
              Width = 102
              Height = 14
              Alignment = taRightJustify
              Caption = 'Master-rate active:'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lbTopClassAvaiabilityOrderActive: TsLabel
              Left = 168
              Top = 65
              Width = 258
              Height = 14
              Alignment = taRightJustify
              Caption = 'RevPar Guru - Top-class availability-order active:'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblMasterRateCurrency: TsLabel
              Left = 504
              Top = 40
              Width = 125
              Height = 14
              Alignment = taRightJustify
              Caption = 'Master rate currency : '
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbxAutoAddToGuestPortfolio: TsCheckBox
              Left = 436
              Top = 20
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxMasterRateActive: TsCheckBox
              Left = 436
              Top = 42
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbTopClassAvaiabilityOrderActive: TsCheckBox
              Left = 436
              Top = 65
              Width = 20
              Height = 20
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object cbxCurrencyCalculation: TsCheckBox
              Left = 632
              Top = 64
              Width = 174
              Height = 20
              Caption = 'Perform currency calculation'
              TabOrder = 3
              ImgChecked = 0
              ImgUnchecked = 0
            end
            inline fraMasterRateCurrency: TfraCurrencyPanel
              Left = 632
              Top = 36
              Width = 250
              Height = 21
              TabOrder = 4
              ExplicitLeft = 632
              ExplicitTop = 36
              ExplicitHeight = 21
              inherited pnlLookup: TsPanel
                inherited lblDescription: TsLabel
                  Width = 157
                  Height = 20
                end
              end
            end
          end
        end
        object AdvTabSheet5: TsTabSheet
          Caption = '-'
        end
        object AdvTabSheet6: TsTabSheet
          Caption = 'Accounting'
          object gbxForceExternalIdCorrectness: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 110
            Align = alTop
            Caption = 'Force External Correctness'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object edForceExternalCustomerIdCorrectness: TsLabel
              Left = 5
              Top = 33
              Width = 203
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Customer :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labforceExternalProductIdCorrectness: TsLabel
              Left = 5
              Top = 55
              Width = 203
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Product :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labforceExternalPaymentTypeIdCorrectness: TsLabel
              Left = 5
              Top = 78
              Width = 203
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Payment :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object __SyncResult: TsLabel
              Left = 8
              Top = 150
              Width = 334
              Height = 14
              AutoSize = False
            end
            object chkforceExternalCustomerIdCorrectness: TsCheckBox
              Left = 219
              Top = 34
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkForceExternalProductIdCorrectness: TsCheckBox
              Left = 219
              Top = 56
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkForceExternalPaymentTypeIdCorrectness: TsCheckBox
              Left = 219
              Top = 79
              Width = 20
              Height = 20
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object btnSynchronizeFinanceTables: TsButton
              Left = 288
              Top = 43
              Width = 337
              Height = 41
              Caption = 'Synchronize data with external finance system'
              TabOrder = 3
              OnClick = btnSynchronizeFinanceTablesClick
              SkinData.SkinSection = 'BUTTON'
            end
          end
          object sGroupBox7: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 119
            Width = 1087
            Height = 90
            Align = alTop
            Caption = 'External Invoice System - Template Entities'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel13: TsLabel
              Left = 5
              Top = 33
              Width = 203
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Customer :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sLabel14: TsLabel
              Left = 5
              Top = 60
              Width = 203
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Product :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object sSpeedButton1: TsSpeedButton
              Left = 308
              Top = 31
              Width = 23
              Height = 21
              Caption = '...'
              OnClick = sSpeedButton1Click
              SkinData.SkinSection = 'SPEEDBUTTON'
            end
            object sSpeedButton2: TsSpeedButton
              Left = 308
              Top = 58
              Width = 23
              Height = 21
              Caption = '...'
              OnClick = sSpeedButton2Click
              SkinData.SkinSection = 'SPEEDBUTTON'
            end
            object edtInvoiceSystemCustomerTemplate: TsEdit
              Left = 214
              Top = 31
              Width = 92
              Height = 21
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              TextHint = 'dbl-click to select from list'
              SkinData.SkinSection = 'EDIT'
            end
            object edtInvoiceSystemProductTemplate: TsEdit
              Left = 214
              Top = 58
              Width = 92
              Height = 21
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              TextHint = 'dbl-click to select from list'
              SkinData.SkinSection = 'EDIT'
            end
          end
          object sGroupBox12: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 387
            Width = 1087
            Height = 71
            Align = alTop
            Caption = 'Other'
            TabOrder = 2
            SkinData.SkinSection = 'GROUPBOX'
            object labAutoInvoiceTransfer: TsLabel
              Left = 5
              Top = 33
              Width = 203
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Automatic transfer of invoices :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object chkAutoInvoiceTransfer: TsCheckBox
              Left = 219
              Top = 31
              Width = 20
              Height = 20
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object sGroupBox13: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 215
            Width = 1087
            Height = 71
            Align = alTop
            Caption = 'Invoice Export Template'
            TabOrder = 3
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel19: TsLabel
              Left = 149
              Top = 35
              Width = 60
              Height = 14
              Alignment = taRightJustify
              Caption = 'Template :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbxInvoiceExport: TsComboBox
              Left = 214
              Top = 33
              Width = 469
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
              TabOrder = 0
            end
            object btnInvoiceTemplateResources: TsButton
              Left = 689
              Top = 31
              Width = 125
              Height = 25
              Caption = 'Resources'
              TabOrder = 1
              OnClick = btnInvoiceTemplateResourcesClick
              SkinData.SkinSection = 'BUTTON'
            end
          end
          object gbxExternalPOS: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 292
            Width = 1087
            Height = 89
            Align = alTop
            Caption = 'External POS System - End-Of-Day constants'
            TabOrder = 4
            SkinData.SkinSection = 'GROUPBOX'
            object lblCustomer: TsLabel
              Left = 5
              Top = 22
              Width = 203
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Customer :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblUser: TsLabel
              Left = 5
              Top = 48
              Width = 203
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'User :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            inline fraEndOfDayCustomerPanel: TfraCustomerPanel
              AlignWithMargins = True
              Left = 216
              Top = 19
              Width = 866
              Height = 20
              Margins.Left = 214
              Align = alTop
              TabOrder = 0
              ExplicitLeft = 216
              ExplicitTop = 19
              ExplicitWidth = 866
              inherited pnlLookup: TsPanel
                Width = 866
                ExplicitWidth = 866
                inherited lblDescription: TsLabel
                  Width = 740
                  Height = 20
                end
              end
            end
            inline fraStaffMemberPanel: TfraStaffMemberPanel
              AlignWithMargins = True
              Left = 216
              Top = 45
              Width = 866
              Height = 20
              Margins.Left = 214
              Align = alTop
              TabOrder = 1
              ExplicitLeft = 216
              ExplicitTop = 45
              ExplicitWidth = 866
              inherited pnlLookup: TsPanel
                Width = 866
                ExplicitWidth = 866
                inherited lblDescription: TsLabel
                  Width = 773
                  Height = 20
                end
              end
            end
          end
        end
        object AdvTabSheet7: TsTabSheet
          Caption = 'Pos'
          object LMDSimplePanel2: TsPanel
            Left = 0
            Top = 0
            Width = 1093
            Height = 61
            Align = alTop
            TabOrder = 0
            SkinData.SkinSection = 'PANEL'
            object LMDSimpleLabel68: TsLabel
              Left = 16
              Top = 33
              Width = 97
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Connection :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label5: TsLabel
              Left = 11
              Top = 8
              Width = 102
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Auto :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object Label11: TsLabel
              Left = 147
              Top = 8
              Width = 186
              Height = 13
              Alignment = taRightJustify
              AutoSize = False
              Caption = 'Use native currency :'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object cbxAccountType: TComboBox
              Left = 122
              Top = 30
              Width = 233
              Height = 22
              Style = csDropDownList
              TabOrder = 0
              OnChange = cbxAccountTypeChange
              Items.Strings = (
                'No Connection'
                'post'
                'Touch Screen System - Text entries'
                'Touch Screen System - XML'
                'TOK windows')
            end
            object chkXmlDoExportInLocalCurrency: TsCheckBox
              Left = 338
              Top = 8
              Width = 20
              Height = 20
              TabOrder = 1
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object chkXmlDoExport: TsCheckBox
              Left = 122
              Top = 8
              Width = 20
              Height = 20
              TabOrder = 2
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
          object PageAccount: TsPageControl
            Left = 0
            Top = 61
            Width = 1093
            Height = 653
            ActivePage = AdvTabSheet11
            Align = alClient
            TabOrder = 1
            SkinData.SkinSection = 'PAGECONTROL'
            object AdvTabSheet8: TsTabSheet
              Caption = 'Nothing'
              object clabNoAccontConnection: TsLabel
                Left = 8
                Top = 8
                Width = 128
                Height = 14
                Caption = 'No account connection'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
            end
            object AdvTabSheet9: TsTabSheet
              Caption = 'poster'
              object LMDSimplePanel3: TsPanel
                Left = 0
                Top = 0
                Width = 1085
                Height = 56
                Align = alTop
                TabOrder = 0
                SkinData.SkinSection = 'PANEL'
                object LMDGroupBox22: TsGroupBox
                  Left = 12
                  Top = 5
                  Width = 685
                  Height = 45
                  Caption = 'Invoice export'
                  TabOrder = 0
                  SkinData.SkinSection = 'GROUPBOX'
                  DesignSize = (
                    685
                    45)
                  object LMDSimpleLabel67: TsLabel
                    Left = 4
                    Top = 18
                    Width = 108
                    Height = 14
                    Caption = 'Path to export file :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object edxmlPath_invoice: TAdvDirectoryEdit
                    Left = 109
                    Top = 15
                    Width = 580
                    Height = 22
                    DefaultHandling = True
                    EmptyTextStyle = []
                    Flat = False
                    LabelFont.Charset = DEFAULT_CHARSET
                    LabelFont.Color = clWindowText
                    LabelFont.Height = -11
                    LabelFont.Name = 'Tahoma'
                    LabelFont.Style = []
                    Lookup.Font.Charset = DEFAULT_CHARSET
                    Lookup.Font.Color = clWindowText
                    Lookup.Font.Height = -11
                    Lookup.Font.Name = 'Arial'
                    Lookup.Font.Style = []
                    Lookup.Separator = ';'
                    Anchors = [akLeft, akTop, akRight]
                    Color = clWindow
                    ReadOnly = True
                    TabOrder = 0
                    Text = ''
                    Visible = True
                    Version = '1.5.0.0'
                    ButtonStyle = bsButton
                    ButtonWidth = 18
                    Etched = False
                    Glyph.Data = {
                      CE000000424DCE0000000000000076000000280000000C0000000B0000000100
                      0400000000005800000000000000000000001000000000000000000000000000
                      8000008000000080800080000000800080008080000080808000C0C0C0000000
                      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00F00000000FFF
                      00000088888880FF00000B088888880F00000BB08888888000000BBB00000000
                      00000BBBBBBB0B0F00000BBB00000B0F0000F000BBBBBB0F0000FF0BBBBBBB0F
                      0000FF0BBB00000F0000FFF000FFFFFF0000}
                    BrowseDialogText = 'Select Directory'
                  end
                end
              end
              object AdvPageControl4: TsPageControl
                Left = 0
                Top = 56
                Width = 1085
                Height = 568
                ActivePage = AdvTabSheet12
                Align = alClient
                TabOrder = 1
                SkinData.SkinSection = 'PAGECONTROL'
                object AdvTabSheet12: TsTabSheet
                  Caption = '-'
                  object LMDSimpleLabel70: TsLabel
                    Left = 6
                    Top = 20
                    Width = 241
                    Height = 14
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'CompanyID :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LMDSimpleLabel73: TsLabel
                    Left = 10
                    Top = 72
                    Width = 237
                    Height = 14
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'Customer account key :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LMDSimpleLabel74: TsLabel
                    Left = 10
                    Top = 46
                    Width = 237
                    Height = 15
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'Product account key :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LMDSimpleLabel75: TsLabel
                    Left = 6
                    Top = 98
                    Width = 241
                    Height = 15
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'Sales person :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LMDSimpleLabel76: TsLabel
                    Left = 6
                    Top = 121
                    Width = 241
                    Height = 15
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'Language id :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LMDSimpleLabel77: TsLabel
                    Left = 6
                    Top = 147
                    Width = 241
                    Height = 15
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'Credit term :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LMDSimpleLabel78: TsLabel
                    Left = 6
                    Top = 173
                    Width = 241
                    Height = 15
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'Delivery term :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LMDSimpleLabel79: TsLabel
                    Left = 6
                    Top = 197
                    Width = 241
                    Height = 14
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'Price type :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LMDSimpleLabel80: TsLabel
                    Left = 8
                    Top = 223
                    Width = 241
                    Height = 15
                    Alignment = taRightJustify
                    AutoSize = False
                    Caption = 'Currency :'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object EDswCust_GL_numberID_INFO: TsLabel
                    Left = 410
                    Top = 46
                    Width = 7
                    Height = 14
                    Caption = '0'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LabswCust_GL_numberID: TsLabel
                    Left = 422
                    Top = 46
                    Width = 7
                    Height = 14
                    Caption = '0'
                    ParentFont = False
                    Visible = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LABswCust_iAccountFK: TsLabel
                    Left = 423
                    Top = 72
                    Width = 7
                    Height = 14
                    Caption = '0'
                    ParentFont = False
                    Visible = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LABswCust_iAccountFK_info: TsLabel
                    Left = 412
                    Top = 72
                    Width = 7
                    Height = 14
                    Caption = '0'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LabswCust_lDeliveryTermsFK: TsLabel
                    Left = 418
                    Top = 173
                    Width = 7
                    Height = 14
                    Caption = '0'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object LabswCust_SalesPersonID: TsLabel
                    Left = 413
                    Top = 98
                    Width = 7
                    Height = 14
                    Caption = '0'
                    ParentFont = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                  end
                  object edswCust_sCurrCode: TsEdit
                    Left = 255
                    Top = 221
                    Width = 81
                    Height = 22
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 0
                    SkinData.SkinSection = 'EDIT'
                  end
                  object EDswCust_GL_numberID: TsEdit
                    Left = 255
                    Top = 43
                    Width = 81
                    Height = 22
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 1
                    SkinData.SkinSection = 'EDIT'
                  end
                  object edswCust_iAccountFK: TsEdit
                    Left = 255
                    Top = 69
                    Width = 81
                    Height = 22
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 2
                    SkinData.SkinSection = 'EDIT'
                  end
                  object cbxDeliveryTerms: TColumnComboBox
                    Left = 255
                    Top = 171
                    Width = 145
                    Height = 22
                    Color = clWindow
                    Version = '1.5.1.0'
                    Visible = True
                    Ctl3D = True
                    Columns = <
                      item
                        Color = clWindow
                        ColumnType = ctText
                        Width = 30
                        Alignment = taLeftJustify
                        Font.Charset = DEFAULT_CHARSET
                        Font.Color = clWindowText
                        Font.Height = -12
                        Font.Name = 'Tahoma'
                        Font.Style = []
                        ParentFont = False
                      end
                      item
                        Color = clSilver
                        ColumnType = ctText
                        Width = 100
                        Alignment = taLeftJustify
                        Font.Charset = DEFAULT_CHARSET
                        Font.Color = clWindowText
                        Font.Height = -12
                        Font.Name = 'Tahoma'
                        Font.Style = []
                        ParentFont = False
                      end>
                    ComboItems = <>
                    EditColumn = -1
                    EditHeight = 16
                    EmptyText = ''
                    EmptyTextStyle = []
                    DropWidth = 145
                    DropHeight = 200
                    Enabled = True
                    FocusBorder = True
                    GridLines = True
                    ItemIndex = -1
                    LookupColumn = 0
                    LabelCaption = ''
                    LabelFont.Charset = DEFAULT_CHARSET
                    LabelFont.Color = clWindowText
                    LabelFont.Height = -11
                    LabelFont.Name = 'Tahoma'
                    LabelFont.Style = []
                    ParentCtl3D = False
                    SortColumn = 0
                    TabOrder = 3
                    OnChange = cbxDeliveryTermsChange
                  end
                  object cbxEmployees: TColumnComboBox
                    Left = 255
                    Top = 95
                    Width = 145
                    Height = 22
                    Color = clWindow
                    Version = '1.5.1.0'
                    Visible = True
                    Ctl3D = True
                    Columns = <
                      item
                        Color = clWindow
                        ColumnType = ctText
                        Width = 30
                        Alignment = taLeftJustify
                        Font.Charset = DEFAULT_CHARSET
                        Font.Color = clWindowText
                        Font.Height = -12
                        Font.Name = 'Tahoma'
                        Font.Style = []
                        ParentFont = False
                      end
                      item
                        Color = clSilver
                        ColumnType = ctText
                        Width = 100
                        Alignment = taLeftJustify
                        Font.Charset = DEFAULT_CHARSET
                        Font.Color = clWindowText
                        Font.Height = -12
                        Font.Name = 'Tahoma'
                        Font.Style = []
                        ParentFont = False
                      end>
                    ComboItems = <>
                    EditColumn = -1
                    EditHeight = 16
                    EmptyText = ''
                    EmptyTextStyle = []
                    DropWidth = 145
                    DropHeight = 200
                    Enabled = True
                    FocusBorder = True
                    GridLines = True
                    ItemIndex = -1
                    LookupColumn = 0
                    LabelCaption = ''
                    LabelFont.Charset = DEFAULT_CHARSET
                    LabelFont.Color = clWindowText
                    LabelFont.Height = -11
                    LabelFont.Name = 'Tahoma'
                    LabelFont.Style = []
                    ParentCtl3D = False
                    SortColumn = 0
                    TabOrder = 4
                    OnChange = cbxEmployeesChange
                  end
                  object btnGetSwCust_GL_numberID: TsButton
                    Left = 344
                    Top = 42
                    Width = 56
                    Height = 23
                    Caption = '...'
                    TabOrder = 5
                    SkinData.SkinSection = 'BUTTON'
                  end
                  object btnGetSwCust_iAccountFK: TsButton
                    Left = 344
                    Top = 68
                    Width = 56
                    Height = 23
                    Caption = '...'
                    TabOrder = 6
                    SkinData.SkinSection = 'BUTTON'
                  end
                  object edswCust_CreditTerms: TsSpinEdit
                    Left = 255
                    Top = 145
                    Width = 81
                    Height = 22
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 7
                    SkinData.SkinSection = 'EDIT'
                    MaxValue = 9999999
                    MinValue = -1
                    Value = 0
                  end
                  object edswCust_iLanguage: TsSpinEdit
                    Left = 255
                    Top = 119
                    Width = 81
                    Height = 22
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 8
                    SkinData.SkinSection = 'EDIT'
                    MaxValue = 9999999
                    MinValue = -1
                    Value = 0
                  end
                  object edswCust_iPriceType: TsSpinEdit
                    Left = 255
                    Top = 194
                    Width = 81
                    Height = 22
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 9
                    SkinData.SkinSection = 'EDIT'
                    MaxValue = 9999999
                    MinValue = -1
                    Value = 0
                  end
                  object edswCust_CompanyID: TsSpinEdit
                    Left = 255
                    Top = 17
                    Width = 81
                    Height = 22
                    Color = clWhite
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clBlack
                    Font.Height = -12
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentFont = False
                    TabOrder = 10
                    SkinData.SkinSection = 'EDIT'
                    MaxValue = 9999999
                    MinValue = -1
                    Value = 0
                  end
                end
              end
            end
            object AdvTabSheet10: TsTabSheet
              Caption = 'Touch Text Entries'
              object LMDSimpleLabel71: TsLabel
                Left = 26
                Top = 20
                Width = 82
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Path : '
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object Label57: TsLabel
                Left = 3
                Top = 46
                Width = 107
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Field seperator : '
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object edSnFieldSeparator: TsEdit
                Left = 114
                Top = 44
                Width = 45
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                MaxLength = 1
                ParentFont = False
                TabOrder = 0
                SkinData.SkinSection = 'EDIT'
              end
              object edSnPath: TAdvDirectoryEdit
                Left = 114
                Top = 17
                Width = 383
                Height = 22
                DefaultHandling = True
                EmptyTextStyle = []
                Flat = False
                LabelFont.Charset = DEFAULT_CHARSET
                LabelFont.Color = clWindowText
                LabelFont.Height = -11
                LabelFont.Name = 'Tahoma'
                LabelFont.Style = []
                Lookup.Font.Charset = DEFAULT_CHARSET
                Lookup.Font.Color = clWindowText
                Lookup.Font.Height = -11
                Lookup.Font.Name = 'Arial'
                Lookup.Font.Style = []
                Lookup.Separator = ';'
                Color = clWindow
                ReadOnly = True
                TabOrder = 1
                Text = ''
                Visible = True
                Version = '1.5.0.0'
                ButtonStyle = bsButton
                ButtonWidth = 18
                Etched = False
                Glyph.Data = {
                  CE000000424DCE0000000000000076000000280000000C0000000B0000000100
                  0400000000005800000000000000000000001000000000000000000000000000
                  8000008000000080800080000000800080008080000080808000C0C0C0000000
                  FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00F00000000FFF
                  00000088888880FF00000B088888880F00000BB08888888000000BBB00000000
                  00000BBBBBBB0B0F00000BBB00000B0F0000F000BBBBBB0F0000FF0BBBBBBB0F
                  0000FF0BBB00000F0000FFF000FFFFFF0000}
                BrowseDialogText = 'Select Directory'
              end
            end
            object tabTouchStoreXML: TsTabSheet
              Caption = 'Touch XML'
              object LMDSimpleLabel81: TsLabel
                Left = 3
                Top = 21
                Width = 121
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Sale info path : '
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object LMDSimpleLabel82: TsLabel
                Left = 3
                Top = 72
                Width = 121
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'XML encoding : '
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object LMDSimpleLabel85: TsLabel
                Left = 3
                Top = 46
                Width = 121
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Guest path : '
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object rgHomeExportPOSType: TsRadioGroup
                Left = 3
                Top = 120
                Width = 202
                Height = 94
                Caption = 'Export Type (This computer)'
                ParentBackground = False
                TabOrder = 0
                SkinData.SkinSection = 'GROUPBOX'
                Items.Strings = (
                  'Do Not Export'
                  'Export to folder'
                  'Export to Database')
              end
              object edSnXMLEncoding: TsEdit
                Left = 130
                Top = 69
                Width = 75
                Height = 22
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                Text = 'UTF-8'
                SkinData.SkinSection = 'EDIT'
              end
              object edSnPathXML: TsDirectoryEdit
                Left = 130
                Top = 19
                Width = 393
                Height = 21
                AutoSize = False
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                MaxLength = 255
                ParentFont = False
                TabOrder = 2
                Text = ''
                CheckOnExit = True
                SkinData.SkinSection = 'EDIT'
                GlyphMode.Blend = 0
                GlyphMode.Grayed = False
                Root = 'rfDesktop'
              end
              object edSnPathCurrentGuestsXML: TsDirectoryEdit
                Left = 130
                Top = 44
                Width = 393
                Height = 21
                AutoSize = False
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                MaxLength = 255
                ParentFont = False
                TabOrder = 3
                Text = ''
                CheckOnExit = True
                SkinData.SkinSection = 'EDIT'
                GlyphMode.Blend = 0
                GlyphMode.Grayed = False
                Root = 'rfDesktop'
              end
            end
            object AdvTabSheet11: TsTabSheet
              Caption = 'TOK Windows'
            end
          end
        end
        object AdvTabSheet13: TsTabSheet
          Caption = 'AdvTabSheet13'
        end
        object AdvTabSheet14: TsTabSheet
          Caption = 'Quick Booking'
        end
        object tsIncomingMonitor: TsTabSheet
          Caption = 'Incoming Monitor'#13#10
          object LMDGroupBox23: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 87
            Align = alTop
            Caption = 'Incoming POS sales'
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object labSec: TsLabel
              Left = 265
              Top = 54
              Width = 20
              Height = 14
              Caption = 'Sec'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object labInPosSeconds: TsLabel
              Left = 79
              Top = 53
              Width = 91
              Height = 14
              Alignment = taRightJustify
              Caption = 'labInPosSeconds'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object ChkinPosMonitorUse: TsCheckBox
              Left = 16
              Top = 24
              Width = 97
              Height = 20
              Caption = 'Monitor active'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object edinPosMonitorChkSec: TsSpinEdit
              Left = 176
              Top = 51
              Width = 83
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              OnChange = edinPosMonitorChkSecChange
              SkinData.SkinSection = 'EDIT'
              MaxValue = 36000
              MinValue = -1
              Value = 0
            end
          end
          object sGroupBox5: TsGroupBox
            AlignWithMargins = True
            Left = 3
            Top = 96
            Width = 1087
            Height = 98
            Align = alTop
            Caption = 'Auto Turnover/payments confirm'
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel10: TsLabel
              Left = 266
              Top = 61
              Width = 32
              Height = 14
              Caption = '00:01'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object lblConfirmMinuteFromMidnight: TsLabel
              Left = 50
              Top = 61
              Width = 121
              Height = 14
              Alignment = taRightJustify
              Caption = 'Minute from midnight:'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object chkConfirmAuto: TsCheckBox
              Left = 17
              Top = 25
              Width = 54
              Height = 20
              Caption = 'Active'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'CHECKBOX'
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object edConfirmMinuteOfTheDay: TsSpinEdit
              Left = 177
              Top = 58
              Width = 83
              Height = 22
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              Text = '1'
              OnChange = edConfirmMinuteOfTheDayChange
              SkinData.SkinSection = 'EDIT'
              MaxValue = 1440
              MinValue = 1
              Value = 1
            end
          end
        end
        object tsColors: TsTabSheet
          Caption = 'tsColors'
          object Panel4: TsPanel
            Left = 0
            Top = 0
            Width = 399
            Height = 714
            Align = alLeft
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            object cxGroupBox2: TsGroupBox
              Left = 4
              Top = 12
              Width = 361
              Height = 198
              Caption = 'Colors in one day grid'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'GROUPBOX'
              object labBackgroundColor: TsLabel
                Left = 2
                Top = 61
                Width = 114
                Height = 17
                AutoSize = False
                Caption = 'Background color:'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object cxLabel5: TsLabel
                Left = 2
                Top = 85
                Width = 114
                Height = 17
                AutoSize = False
                Caption = 'Font color :'
                ParentFont = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
              end
              object chkBold: TsCheckBox
                Left = 119
                Top = 111
                Width = 43
                Height = 20
                Caption = 'Bold'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                SkinData.SkinSection = 'CHECKBOX'
                ImgChecked = 0
                ImgUnchecked = 0
              end
              object chkItalic: TsCheckBox
                Left = 119
                Top = 129
                Width = 45
                Height = 20
                Caption = 'Italic'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                SkinData.SkinSection = 'CHECKBOX'
                ImgChecked = 0
                ImgUnchecked = 0
              end
              object chkUnderline: TsCheckBox
                Left = 237
                Top = 111
                Width = 71
                Height = 20
                Caption = 'Underline'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                SkinData.SkinSection = 'CHECKBOX'
                ImgChecked = 0
                ImgUnchecked = 0
              end
              object chkStrikeOut: TsCheckBox
                Left = 237
                Top = 129
                Width = 70
                Height = 20
                Caption = 'Strikeout'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 4
                SkinData.SkinSection = 'CHECKBOX'
                ImgChecked = 0
                ImgUnchecked = 0
              end
              object Panel1: TsPanel
                Left = 2
                Top = 156
                Width = 357
                Height = 40
                Align = alBottom
                TabOrder = 3
                SkinData.SkinSection = 'PANEL'
                object btnUpdateOneColor: TsButton
                  Left = 8
                  Top = 9
                  Width = 111
                  Height = 25
                  Caption = 'Update'
                  ImageIndex = 2
                  Images = DImages.PngImageList1
                  TabOrder = 0
                  OnClick = btnUpdateOneColorClick
                  SkinData.SkinSection = 'BUTTON'
                end
                object btnOneColorToDefault: TsButton
                  Left = 127
                  Top = 9
                  Width = 111
                  Height = 25
                  Caption = 'Default'
                  ImageIndex = 104
                  Images = DImages.PngImageList1
                  TabOrder = 1
                  OnClick = btnOneColorToDefaultClick
                  SkinData.SkinSection = 'BUTTON'
                end
              end
              object cbxStatusAttr_: TsComboBox
                Left = 119
                Top = 19
                Width = 229
                Height = 22
                Alignment = taLeftJustify
                SkinData.SkinSection = 'COMBOBOX'
                VerticalAlignment = taAlignTop
                Style = csDropDownList
                Color = clWhite
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ItemIndex = -1
                ParentFont = False
                TabOrder = 5
                OnCloseUp = cbxStatusAttr_CloseUp
                Items.Strings = (
                  'Checked in - Staying more than one day'
                  'Checked in - Departing tomorrow'
                  'Checked in - Departing today  '
                  'Not Arrived - Confirmed order'
                  'Not Arrived - Alotment'
                  'Not Arrived - Waitinglist'
                  'New guest coming - other departing '
                  'Departed'
                  'No-show'
                  'Blocked'
                  'Canceled'
                  'Other 1'
                  'Other 2'
                  'Waiting list')
              end
              object cbxFontColor: TAdvOfficeColorSelector
                Left = 119
                Top = 83
                Width = 110
                Height = 22
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                NotesFont.Charset = DEFAULT_CHARSET
                NotesFont.Color = clWindowText
                NotesFont.Height = -11
                NotesFont.Name = 'Tahoma'
                NotesFont.Style = []
                ParentFont = False
                Version = '1.6.0.1'
                TabOrder = 6
                AllowFloating = False
                CloseOnSelect = False
                CaptionAppearance.BorderColor = clNone
                CaptionAppearance.Color = 13198890
                CaptionAppearance.ColorTo = clNone
                CaptionAppearance.Direction = gdHorizontal
                CaptionAppearance.TextColor = clWhite
                CaptionAppearance.TextColorHot = clBlack
                CaptionAppearance.TextColorDown = clBlack
                CaptionAppearance.ButtonAppearance.ColorChecked = 16111818
                CaptionAppearance.ButtonAppearance.ColorCheckedTo = 16367008
                CaptionAppearance.ButtonAppearance.ColorDisabled = 15921906
                CaptionAppearance.ButtonAppearance.ColorDisabledTo = 15921906
                CaptionAppearance.ButtonAppearance.ColorDown = 16111818
                CaptionAppearance.ButtonAppearance.ColorDownTo = 16367008
                CaptionAppearance.ButtonAppearance.ColorHot = 16117985
                CaptionAppearance.ButtonAppearance.ColorHotTo = 16372402
                CaptionAppearance.ButtonAppearance.ColorMirrorHot = 16107693
                CaptionAppearance.ButtonAppearance.ColorMirrorHotTo = 16775412
                CaptionAppearance.ButtonAppearance.ColorMirrorDown = 16102556
                CaptionAppearance.ButtonAppearance.ColorMirrorDownTo = 16768988
                CaptionAppearance.ButtonAppearance.ColorMirrorChecked = 16102556
                CaptionAppearance.ButtonAppearance.ColorMirrorCheckedTo = 16768988
                CaptionAppearance.ButtonAppearance.ColorMirrorDisabled = 11974326
                CaptionAppearance.ButtonAppearance.ColorMirrorDisabledTo = 15921906
                DragGripAppearance.BorderColor = clGray
                DragGripAppearance.Color = clWhite
                DragGripAppearance.ColorTo = clWhite
                DragGripAppearance.ColorMirror = clSilver
                DragGripAppearance.ColorMirrorTo = clWhite
                DragGripAppearance.Gradient = ggVertical
                DragGripAppearance.GradientMirror = ggVertical
                DragGripAppearance.BorderColorHot = clBlue
                DragGripAppearance.ColorHot = 16117985
                DragGripAppearance.ColorHotTo = 16372402
                DragGripAppearance.ColorMirrorHot = 16107693
                DragGripAppearance.ColorMirrorHotTo = 16775412
                DragGripAppearance.GradientHot = ggRadial
                DragGripAppearance.GradientMirrorHot = ggRadial
                DragGripPosition = gpTop
                Appearance.ColorChecked = 16111818
                Appearance.ColorCheckedTo = 16367008
                Appearance.ColorDisabled = 15921906
                Appearance.ColorDisabledTo = 15921906
                Appearance.ColorDown = 16111818
                Appearance.ColorDownTo = 16367008
                Appearance.ColorHot = 16117985
                Appearance.ColorHotTo = 16372402
                Appearance.ColorMirrorHot = 16107693
                Appearance.ColorMirrorHotTo = 16775412
                Appearance.ColorMirrorDown = 16102556
                Appearance.ColorMirrorDownTo = 16768988
                Appearance.ColorMirrorChecked = 16102556
                Appearance.ColorMirrorCheckedTo = 16768988
                Appearance.ColorMirrorDisabled = 11974326
                Appearance.ColorMirrorDisabledTo = 15921906
                SelectedColor = clNone
                ShowRGBHint = True
                ColorDropDown = 16251129
                ColorDropDownFloating = 16374724
                SelectionAppearance.ColorChecked = 16111818
                SelectionAppearance.ColorCheckedTo = 16367008
                SelectionAppearance.ColorDisabled = 15921906
                SelectionAppearance.ColorDisabledTo = 15921906
                SelectionAppearance.ColorDown = 16111818
                SelectionAppearance.ColorDownTo = 16367008
                SelectionAppearance.ColorHot = 16117985
                SelectionAppearance.ColorHotTo = 16372402
                SelectionAppearance.ColorMirrorHot = 16107693
                SelectionAppearance.ColorMirrorHotTo = 16775412
                SelectionAppearance.ColorMirrorDown = 16102556
                SelectionAppearance.ColorMirrorDownTo = 16768988
                SelectionAppearance.ColorMirrorChecked = 16102556
                SelectionAppearance.ColorMirrorCheckedTo = 16768988
                SelectionAppearance.ColorMirrorDisabled = 11974326
                SelectionAppearance.ColorMirrorDisabledTo = 15921906
                SelectionAppearance.TextColorChecked = clBlack
                SelectionAppearance.TextColorDown = clWhite
                SelectionAppearance.TextColorHot = clWhite
                SelectionAppearance.TextColor = clBlack
                SelectionAppearance.TextColorDisabled = clGray
                SelectionAppearance.Rounded = False
                Tools = <
                  item
                    BackGroundColor = clBlack
                    Caption = 'Automatic'
                    CaptionAlignment = taCenter
                    Enable = True
                    Hint = 'Automatic'
                    ImageIndex = -1
                    ItemType = itFullWidthButton
                  end
                  item
                    BackGroundColor = clBlack
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 13209
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 13107
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 13056
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 6697728
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clNavy
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 3486515
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 3355443
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clMaroon
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 26367
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clOlive
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clGreen
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clTeal
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clBlue
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 10053222
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clGray
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clRed
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 39423
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 52377
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 6723891
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 13421619
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 16737843
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clPurple
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 10066329
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clFuchsia
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 52479
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clYellow
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clLime
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clAqua
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 16763904
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 6697881
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clSilver
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 13408767
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 10079487
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 10092543
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 13434828
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 16777164
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 16764057
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = 16751052
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = clWhite
                    CaptionAlignment = taCenter
                    Enable = True
                    ImageIndex = -1
                  end
                  item
                    BackGroundColor = -2
                    Caption = 'More Colors...'
                    CaptionAlignment = taCenter
                    Enable = True
                    Hint = 'More Colors'
                    ImageIndex = -1
                    ItemType = itFullWidthButton
                  end>
                OnSelectColor = cbxBackColorSelectColor
              end
            end
            object cbxBackColor: TAdvOfficeColorSelector
              Left = 123
              Top = 69
              Width = 110
              Height = 22
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              NotesFont.Charset = DEFAULT_CHARSET
              NotesFont.Color = clWindowText
              NotesFont.Height = -11
              NotesFont.Name = 'Tahoma'
              NotesFont.Style = []
              ParentFont = False
              Version = '1.6.0.1'
              TabOrder = 1
              AllowFloating = False
              CloseOnSelect = False
              CaptionAppearance.BorderColor = clNone
              CaptionAppearance.Color = 13198890
              CaptionAppearance.ColorTo = clNone
              CaptionAppearance.Direction = gdHorizontal
              CaptionAppearance.TextColor = clWhite
              CaptionAppearance.TextColorHot = clBlack
              CaptionAppearance.TextColorDown = clBlack
              CaptionAppearance.ButtonAppearance.ColorChecked = 16111818
              CaptionAppearance.ButtonAppearance.ColorCheckedTo = 16367008
              CaptionAppearance.ButtonAppearance.ColorDisabled = 15921906
              CaptionAppearance.ButtonAppearance.ColorDisabledTo = 15921906
              CaptionAppearance.ButtonAppearance.ColorDown = 16111818
              CaptionAppearance.ButtonAppearance.ColorDownTo = 16367008
              CaptionAppearance.ButtonAppearance.ColorHot = 16117985
              CaptionAppearance.ButtonAppearance.ColorHotTo = 16372402
              CaptionAppearance.ButtonAppearance.ColorMirrorHot = 16107693
              CaptionAppearance.ButtonAppearance.ColorMirrorHotTo = 16775412
              CaptionAppearance.ButtonAppearance.ColorMirrorDown = 16102556
              CaptionAppearance.ButtonAppearance.ColorMirrorDownTo = 16768988
              CaptionAppearance.ButtonAppearance.ColorMirrorChecked = 16102556
              CaptionAppearance.ButtonAppearance.ColorMirrorCheckedTo = 16768988
              CaptionAppearance.ButtonAppearance.ColorMirrorDisabled = 11974326
              CaptionAppearance.ButtonAppearance.ColorMirrorDisabledTo = 15921906
              DragGripAppearance.BorderColor = clGray
              DragGripAppearance.Color = clWhite
              DragGripAppearance.ColorTo = clWhite
              DragGripAppearance.ColorMirror = clSilver
              DragGripAppearance.ColorMirrorTo = clWhite
              DragGripAppearance.Gradient = ggVertical
              DragGripAppearance.GradientMirror = ggVertical
              DragGripAppearance.BorderColorHot = clBlue
              DragGripAppearance.ColorHot = 16117985
              DragGripAppearance.ColorHotTo = 16372402
              DragGripAppearance.ColorMirrorHot = 16107693
              DragGripAppearance.ColorMirrorHotTo = 16775412
              DragGripAppearance.GradientHot = ggRadial
              DragGripAppearance.GradientMirrorHot = ggRadial
              DragGripPosition = gpTop
              Appearance.ColorChecked = 16111818
              Appearance.ColorCheckedTo = 16367008
              Appearance.ColorDisabled = 15921906
              Appearance.ColorDisabledTo = 15921906
              Appearance.ColorDown = 16111818
              Appearance.ColorDownTo = 16367008
              Appearance.ColorHot = 16117985
              Appearance.ColorHotTo = 16372402
              Appearance.ColorMirrorHot = 16107693
              Appearance.ColorMirrorHotTo = 16775412
              Appearance.ColorMirrorDown = 16102556
              Appearance.ColorMirrorDownTo = 16768988
              Appearance.ColorMirrorChecked = 16102556
              Appearance.ColorMirrorCheckedTo = 16768988
              Appearance.ColorMirrorDisabled = 11974326
              Appearance.ColorMirrorDisabledTo = 15921906
              SelectedColor = clNone
              ShowRGBHint = True
              ColorDropDown = 16251129
              ColorDropDownFloating = 16374724
              SelectionAppearance.ColorChecked = 16111818
              SelectionAppearance.ColorCheckedTo = 16367008
              SelectionAppearance.ColorDisabled = 15921906
              SelectionAppearance.ColorDisabledTo = 15921906
              SelectionAppearance.ColorDown = 16111818
              SelectionAppearance.ColorDownTo = 16367008
              SelectionAppearance.ColorHot = 16117985
              SelectionAppearance.ColorHotTo = 16372402
              SelectionAppearance.ColorMirrorHot = 16107693
              SelectionAppearance.ColorMirrorHotTo = 16775412
              SelectionAppearance.ColorMirrorDown = 16102556
              SelectionAppearance.ColorMirrorDownTo = 16768988
              SelectionAppearance.ColorMirrorChecked = 16102556
              SelectionAppearance.ColorMirrorCheckedTo = 16768988
              SelectionAppearance.ColorMirrorDisabled = 11974326
              SelectionAppearance.ColorMirrorDisabledTo = 15921906
              SelectionAppearance.TextColorChecked = clBlack
              SelectionAppearance.TextColorDown = clWhite
              SelectionAppearance.TextColorHot = clWhite
              SelectionAppearance.TextColor = clBlack
              SelectionAppearance.TextColorDisabled = clGray
              SelectionAppearance.Rounded = False
              Tools = <
                item
                  BackGroundColor = clBlack
                  Caption = 'Automatic'
                  CaptionAlignment = taCenter
                  Enable = True
                  Hint = 'Automatic'
                  ImageIndex = -1
                  ItemType = itFullWidthButton
                end
                item
                  BackGroundColor = clBlack
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 13209
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 13107
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 13056
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 6697728
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clNavy
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 3486515
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 3355443
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clMaroon
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 26367
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clOlive
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clGreen
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clTeal
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clBlue
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 10053222
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clGray
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clRed
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 39423
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 52377
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 6723891
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 13421619
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 16737843
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clPurple
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 10066329
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clFuchsia
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 52479
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clYellow
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clLime
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clAqua
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 16763904
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 6697881
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clSilver
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 13408767
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 10079487
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 10092543
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 13434828
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 16777164
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 16764057
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = 16751052
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = clWhite
                  CaptionAlignment = taCenter
                  Enable = True
                  ImageIndex = -1
                end
                item
                  BackGroundColor = -2
                  Caption = 'More Colors...'
                  CaptionAlignment = taCenter
                  Enable = True
                  Hint = 'More Colors'
                  ImageIndex = -1
                  ItemType = itFullWidthButton
                end>
              OnSelectColor = cbxBackColorSelectColor
            end
          end
          object Panel5: TsPanel
            Left = 399
            Top = 0
            Width = 694
            Height = 714
            Align = alClient
            TabOrder = 1
            SkinData.SkinSection = 'GROUPBOX'
            object sLabel1: TsLabel
              Left = 200
              Top = 8
              Width = 40
              Height = 14
              Caption = 'sLabel1'
              ParentFont = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
            end
            object panDeparted: TsPanel
              Tag = 7
              Left = 1
              Top = 176
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Departed'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 0
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panOrder: TsPanel
              Tag = 3
              Left = 1
              Top = 76
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Not Arrived - Confirmed order'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 1
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panDeparting: TsPanel
              Tag = 2
              Left = 1
              Top = 51
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Checked in - Departing today'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 2
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panGuestLeavingNextDay: TsPanel
              Tag = 1
              Left = 1
              Top = 26
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Checked in - Departing tomorrow'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 3
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panGuestStaying: TsPanel
              Left = 1
              Top = 1
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Checked in - Staying more than one day'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 4
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panBlocked: TsPanel
              Tag = 9
              Left = 1
              Top = 226
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Blocked'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 5
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panArrivingOtherLeaving: TsPanel
              Tag = 6
              Left = 1
              Top = 151
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'New guest coming - other departing'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 6
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panNoShow: TsPanel
              Tag = 8
              Left = 1
              Top = 201
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'No-show'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 7
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panOptionalBooking: TsPanel
              Tag = 5
              Left = 1
              Top = 126
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Not Arrived - Waitinglist'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 8
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panAllotment: TsPanel
              Tag = 4
              Left = 1
              Top = 101
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Not Arrived - Alotment'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 9
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object Panel6: TsPanel
              Left = 1
              Top = 674
              Width = 692
              Height = 39
              Align = alBottom
              TabOrder = 10
              SkinData.SkinSection = 'PANEL'
              object btnUpdateAllColors: TsButton
                Left = 8
                Top = 8
                Width = 111
                Height = 25
                Caption = 'Update all'
                ImageIndex = 103
                Images = DImages.PngImageList1
                TabOrder = 0
                OnClick = btnUpdateAllColorsClick
                SkinData.SkinSection = 'BUTTON'
              end
              object btnAllColorsToDefault: TsButton
                Left = 125
                Top = 8
                Width = 111
                Height = 25
                Caption = 'All to Default '
                ImageIndex = 104
                Images = DImages.PngImageList1
                TabOrder = 1
                OnClick = btnAllColorsToDefaultClick
                SkinData.SkinSection = 'BUTTON'
              end
            end
            object panCanceled: TsPanel
              Tag = 10
              Left = 1
              Top = 251
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Canceled'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 11
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panTmp2: TsPanel
              Tag = 12
              Left = 1
              Top = 301
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Awaiting Payment'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 12
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panTmp1: TsPanel
              Tag = 11
              Left = 1
              Top = 276
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = '[Unused]'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 13
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
            object panWaitinglistNonOptional: TsPanel
              Tag = 13
              Left = 1
              Top = 326
              Width = 692
              Height = 25
              Align = alTop
              Alignment = taLeftJustify
              Caption = 'Waiting list'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentBackground = False
              ParentFont = False
              TabOrder = 14
              OnClick = panGuestStayingClick
              OnDblClick = panGuestStayingDblClick
              SkinData.SkinSection = 'UNKNOWN'
            end
          end
        end
        object tabMandatory: TsTabSheet
          Caption = 'Mandatory info'
          object pcMandatoryInfo: TsPageControl
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 1087
            Height = 708
            ActivePage = tabGuestInformation
            Align = alClient
            TabOrder = 0
            object tabGuestInformation: TsTabSheet
              Caption = 'Mandatory Guest information'
              object clbMandatoryFields: TsCheckListBox
                AlignWithMargins = True
                Left = 20
                Top = 53
                Width = 390
                Height = 616
                Margins.Left = 20
                Margins.Top = 20
                Margins.Bottom = 10
                Align = alLeft
                BorderStyle = bsSingle
                Columns = 1
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -12
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                SkinData.SkinSection = 'GROUPBOX'
                DblClickToggle = True
              end
              object pnlManInfoButtons: TsPanel
                Left = 0
                Top = 0
                Width = 1079
                Height = 33
                Align = alTop
                TabOrder = 1
                SkinData.SkinSection = 'GROUPBOX'
                object btnMFSelectNone: TsButton
                  AlignWithMargins = True
                  Left = 120
                  Top = 4
                  Width = 91
                  Height = 25
                  Margins.Left = 5
                  Align = alLeft
                  Caption = 'Select none'
                  TabOrder = 0
                  OnClick = btnMFSelectNoneClick
                end
                object btnMFSelectAll: TsButton
                  AlignWithMargins = True
                  Left = 21
                  Top = 4
                  Width = 91
                  Height = 25
                  Margins.Left = 20
                  Align = alLeft
                  Caption = 'Select all'
                  TabOrder = 1
                  OnClick = btnMFSelectAllClick
                end
              end
            end
          end
        end
        object tsBetaFunctions: TsTabSheet
          Caption = 'Beta Functions'
          object gbxInvoiceBeta: TsGroupBox
            Left = 0
            Top = 0
            Width = 1093
            Height = 105
            Align = alTop
            Caption = 'Invoice Beta functionaity'
            TabOrder = 0
            object cbxNewTaxCalcMethod: TsCheckBox
              Left = 24
              Top = 24
              Width = 159
              Height = 20
              Caption = 'Use new Taxcalc method'
              TabOrder = 0
              ImgChecked = 0
              ImgUnchecked = 0
            end
          end
        end
        object tabEmailService: TsTabSheet
          Caption = 'EmailService'
          object sGroupBox2: TsGroupBox
            Left = 48
            Top = 43
            Width = 489
            Height = 430
            Caption = '[ SMTP Service Settings ]'
            TabOrder = 0
            object lbSmtpServer: TsLabel
              Left = 54
              Top = 41
              Width = 74
              Height = 14
              Alignment = taRightJustify
              Caption = 'SMTP Server:'
              Enabled = False
            end
            object lbSmtpFromEmail: TsLabel
              Left = 21
              Top = 69
              Width = 107
              Height = 14
              Alignment = taRightJustify
              Caption = 'From email address:'
              Enabled = False
            end
            object lbSmtpPort: TsLabel
              Left = 62
              Top = 97
              Width = 66
              Height = 14
              Alignment = taRightJustify
              Caption = 'Server port:'
              Enabled = False
            end
            object lbSmtpUsername: TsLabel
              Left = 134
              Top = 267
              Width = 58
              Height = 14
              Alignment = taRightJustify
              Caption = 'Username:'
              Enabled = False
            end
            object lbSmtpPassword: TsLabel
              Left = 137
              Top = 297
              Width = 55
              Height = 14
              Alignment = taRightJustify
              Caption = 'Password:'
              Enabled = False
            end
            object edSmtpServer: TsEdit
              Left = 134
              Top = 38
              Width = 273
              Height = 22
              Color = clWhite
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              SkinData.SkinSection = 'EDIT'
            end
            object edSmtpFromEmail: TsEdit
              Left = 134
              Top = 66
              Width = 273
              Height = 22
              Color = clWhite
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
            end
            object cbSmtpAuthenticate: TsCheckBox
              Left = 132
              Top = 236
              Width = 92
              Height = 20
              Caption = 'Authenticate'
              Enabled = False
              TabOrder = 4
              OnClick = cbSmtpAuthenticateClick
              ImgChecked = 0
              ImgUnchecked = 0
            end
            object edSmtpUsername: TsEdit
              Left = 198
              Top = 264
              Width = 209
              Height = 22
              Color = clWhite
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 5
            end
            object edSmtpPassword: TsEdit
              Left = 198
              Top = 294
              Width = 209
              Height = 22
              Color = clWhite
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              PasswordChar = '*'
              TabOrder = 6
            end
            object edSmtpPort: TsSpinEdit
              Left = 134
              Top = 94
              Width = 273
              Height = 22
              Color = clWhite
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              FlatSpinButtons = False
              ShowSpinButtons = False
              MaxValue = 65535
              MinValue = 1
              Value = 0
            end
            object rgEncryption: TsRadioGroup
              Left = 132
              Top = 122
              Width = 275
              Height = 105
              Caption = 'Encryption'
              TabOrder = 3
              Items.Strings = (
                'None'
                'SSL/TLS'
                'STARTTLS')
            end
          end
          object cbSmtpServiceActive: TsCheckBox
            Left = 48
            Top = 17
            Width = 294
            Height = 20
            Caption = 'Use the below SMTP server for all outgoing emails'
            TabOrder = 1
            OnClick = cbSmtpServiceActiveClick
            ImgChecked = 0
            ImgUnchecked = 0
          end
        end
      end
    end
  end
  object Panel3: TsPanel
    Left = 0
    Top = 0
    Width = 1261
    Height = 3
    Align = alTop
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
  end
  object sPanel1: TsPanel
    Left = 0
    Top = 778
    Width = 1261
    Height = 33
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    DesignSize = (
      1261
      33)
    object btnOK: TsButton
      Left = 1099
      Top = 4
      Width = 75
      Height = 25
      HelpContext = 6
      Anchors = [akTop, akRight]
      Caption = 'OK'
      Default = True
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 0
      OnClick = okBtnClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnCancel: TsButton
      Left = 1180
      Top = 4
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Cancel'
      ImageIndex = 4
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 1
      OnClick = btnCancelClick
      SkinData.SkinSection = 'BUTTON'
    end
  end
end
