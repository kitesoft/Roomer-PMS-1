object ImageViewerDemoMainForm: TImageViewerDemoMainForm
  Left = 125
  Top = 125
  Width = 965
  Height = 741
  Caption = 'ExpressEditors ImageViewer Demo'
  Color = clBtnFace
  Constraints.MinHeight = 200
  Constraints.MinWidth = 650
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object dxGalleryControl: TdxGalleryControl
    Left = 0
    Top = 31
    Width = 454
    Height = 672
    Align = alClient
    ItemCheckMode = icmSingleRadio
    OnItemClick = dxGalleryControlItemClick
  end
  object cxSplitter1: TcxSplitter
    Left = 454
    Top = 31
    Width = 2
    Height = 672
    AlignSplitter = salRight
    Control = gbRightPanel
  end
  object pnlToolBar: TPanel
    Left = 0
    Top = 0
    Width = 949
    Height = 31
    Align = alTop
    BevelOuter = bvNone
    Caption = 'pnlToolBar'
    FullRepaint = False
    TabOrder = 2
    object imToolBar: TImage
      Left = 0
      Top = 0
      Width = 949
      Height = 31
      Align = alClient
      Picture.Data = {
        0B546478504E47496D61676589504E470D0A1A0A0000000D4948445200000005
        0000001F0802000000A040904F000000017352474200AECE1CE9000000046741
        4D410000B18F0BFC61050000007B494441542853B5CC390EC2300044D1B9FF29
        B80187A0E602C8742856229684D859BC922E5F8816E915F39B514899944B25AD
        A9927CA824B756D2B814D2B014523F17D273CAA487CFA4BB4BA46E4CA4F61D49
        7688A4A60F24D338FA437BD3ECB6FFAFB6DE8018DBFED193B13B5DDB99747B45
        D2F9D2910EC7137D00F4F0AEAB6D731ECC0000000049454E44AE426082}
      Stretch = True
    end
    object sbTextSettings: TcxButton
      Left = 4
      Top = 2
      Width = 93
      Height = 27
      Caption = 'Text Alignment'
      TabOrder = 0
      TabStop = False
      OnClick = sbTextSettingsClick
      OptionsImage.Glyph.Data = {
        DA010000424DDA010000000000003600000028000000090000000F0000000100
        180000000000A401000000000000000000000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF
        00FFFF00FF00FF00FFFF00FFFF00FF000000000000000000FF00FFFF00FFFF00
        FF00FF00FFFF00FF000000000000000000000000000000FF00FFFF00FF00FF00
        FF000000000000000000000000000000000000000000FF00FF00FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF00}
      OptionsImage.Layout = blGlyphRight
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Flat = True
      SpeedButtonOptions.Transparent = True
    end
    object sbColumnSettings: TcxButton
      Left = 103
      Top = 2
      Width = 101
      Height = 27
      Caption = 'Column Count'
      TabOrder = 1
      TabStop = False
      OnClick = sbColumnSettingsClick
      OptionsImage.Glyph.Data = {
        DA010000424DDA010000000000003600000028000000090000000F0000000100
        180000000000A401000000000000000000000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF
        00FFFF00FF00FF00FFFF00FFFF00FF000000000000000000FF00FFFF00FFFF00
        FF00FF00FFFF00FF000000000000000000000000000000FF00FFFF00FF00FF00
        FF000000000000000000000000000000000000000000FF00FF00FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FF00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF00}
      OptionsImage.Layout = blGlyphRight
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Flat = True
      SpeedButtonOptions.Transparent = True
    end
    object tbItemSize: TcxTrackBar
      Left = 366
      Top = 2
      TabStop = False
      Position = 1
      Properties.Max = 7
      Properties.Min = 1
      Properties.ShowChangeButtons = True
      Properties.ShowTicks = False
      Properties.TickSize = 1
      Properties.OnChange = tbItemSizePropertiesChange
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 2
      Transparent = True
      Height = 27
      Width = 115
    end
    object lbItemSize: TcxLabel
      Left = 317
      Top = 6
      Caption = 'Item Size:'
      Transparent = True
    end
    object cbSorted: TcxCheckBox
      Left = 210
      Top = 4
      TabStop = False
      Caption = 'Sort By Genre'
      TabOrder = 4
      Transparent = True
      OnClick = cbSortedClick
      Width = 95
    end
    object sbHidePanel: TcxButton
      Left = 887
      Top = 2
      Width = 27
      Height = 27
      Hint = 'Switch preview on/off'
      Anchors = [akTop, akRight]
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      TabStop = False
      OnClick = sbHidePanelClick
      OptionsImage.Glyph.Data = {
        42010000424D4201000000000000760000002800000011000000110000000100
        040000000000CC00000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00DDDDDDDDDDDD
        DDDDD0000000DDDDDDDDDDDDDDDDD0000000DCCCCCCCCCCCCCCCC0000000DCFF
        FFFFFFCEEEEEC0000000DCFFFFFFFFCECCCEC0000000DCFFFFFFFFCECCCEC000
        0000DCFFFFFFFFCEEEEEC0000000DCFFFFFFFFCEEEEEC0000000DCFFFFFFFFCE
        EEEEC0000000DCFFFFFFFFCEEEEEC0000000DCFFFFFFFFCEEEEEC0000000DCFF
        FFFFFFCEEEEEC0000000DCCCCCCCCCCEEEEEC0000000DCFFFFFFFFCEEEEEC000
        0000DCFFFFFFFFCEEEEEC0000000DCCCCCCCCCCCCCCCC0000000DDDDDDDDDDDD
        DDDDD0000000}
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Flat = True
      SpeedButtonOptions.Transparent = True
    end
    object sbInfo: TcxButton
      Left = 917
      Top = 2
      Width = 27
      Height = 27
      Hint = 'About this demo'
      Anchors = [akTop, akRight]
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      TabStop = False
      OnClick = sbInfoClick
      OptionsImage.Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        1800000000000003000000000000000000000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFE9E2DBDED8D1D5CFC8D4CEC7DBD5CEE5DED7F2EBE3FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFEAE3DCBEAB9A9B74558E552A8E
        49158D48148A5126926B4DB39F90E3DDD5FF00FFFF00FFFF00FFFF00FFFF00FF
        E9E2DBAD8C72A76837D39768ECBF9AF9D9B9F8D6B5E9B88ECD8D5A9C5D2B9A7A
        60DED8D1FF00FFFF00FFFF00FFEFE8E0B59277BD7D4AEEC5A3EEB788DD8B4CBF
        6620BD6623CC7A3BE6A875E7B387B06C379B7A61E4DDD6FF00FFF8F1E9D2BCAA
        B57749F1D1B4EEAB71E07E2CC1661BDDC2ADF3EAE3B8733CCC6517DC8A4CE7B5
        899D5E2EB6A293F3ECE4F4EDE5BD906DE1B28CF8D5B2EEA059E99348C5732EFC
        FBF9FFFFFFCB956CCF6618D06719E8AB7ACF905F966F51E7E0D9F2EBE3B87541
        F7E1CDF7C596F1A964EEA159D5843DC48B5CCFA17DB8631FD66D1DD56B1BDE8C
        4DEBBD9791582BDED8D1F3ECE4B96726FEF8F3F9BF87F5B270F2AB65EEA159C2
        7E43D0A581BD6720DC721FD96F1ED9762BF9DDC3964F19D9D3CCF4EDE5C1712B
        FEFAF5FAC894F8BB7EEDAB6AE79C5ACF9664FFFFFFDBB799BD6C29D26D1CDD7B
        2FF9E1CB99511BDBD5CEF7F0E8CF8E52FAEADBFCD9B4FAC38CD49964E2BEA0CD
        925EE9D0BAFFFFFFF3E8E0C2702CE79758F0CAA99E6235E3DDD5FF00FFDEB286
        EFCCA8FEEAD7FBCA98DBAD85FFFFFFE7CCB3DEB794FFFFFFFFFFFFCB8449F2BF
        95DCA275AF8362EDE6DFFF00FFEEDAC3E0A870FAEBDAFDDFBFDEA673ECD8C4FF
        FFFFFFFFFFFFFFFFDFBDA0D49055F2D1B3BC7944CFB9A7F7F0E8FF00FFFF00FF
        E8C7A2E7B784FAEBDBFBE5D1E4B68DD9A77AD6A476D5A072E2B48BF2D4B9D08C
        54C59E7FF0E9E1FF00FFFF00FFFF00FFFF00FFEBCBA6E5B177F2D0ACFBECDCFE
        FAF5FEF9F4F9E5D1E9BA91CA884ECDA685F1EAE2FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFF3DFC9E7C093DDA263D28A3ED08237CE8C4FD5A67BE3CCB6F6EF
        E7FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFBF4ECFAF3EBF8
        F1E9F8F1E9F8F1E9F9F2EAFF00FFFF00FFFF00FFFF00FFFF00FF}
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Flat = True
      SpeedButtonOptions.Transparent = True
    end
    object sbResize: TcxButton
      Left = 784
      Top = 2
      Width = 101
      Height = 27
      Anchors = [akTop, akRight]
      Caption = 'Resize Image...'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 7
      TabStop = False
      OnClick = sbResizeClick
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Flat = True
      SpeedButtonOptions.Transparent = True
    end
  end
  object gbRightPanel: TcxGroupBox
    Left = 456
    Top = 31
    Align = alRight
    Constraints.MinWidth = 390
    PanelStyle.Active = True
    Style.BorderStyle = ebsNone
    TabOrder = 3
    Height = 672
    Width = 493
    object cxGroupBox2: TcxGroupBox
      Left = 3
      Top = 0
      Anchors = [akLeft, akTop, akRight, akBottom]
      Style.BorderStyle = ebsUltraFlat
      TabOrder = 0
      Height = 665
      Width = 487
      object pbMain: TPaintBox
        Left = 2
        Top = 5
        Width = 483
        Height = 624
        Align = alClient
        OnPaint = pbMainPaint
      end
      object cxGroupBox4: TcxGroupBox
        Left = 2
        Top = 629
        Align = alBottom
        Style.BorderStyle = ebsNone
        TabOrder = 0
        Height = 34
        Width = 483
        object ztbZoom: TdxZoomTrackBar
          Left = 288
          Top = 0
          Anchors = [akTop, akRight]
          Properties.OnChange = ztbZoomPropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 0
          Transparent = True
          Height = 33
          Width = 196
        end
        object lbZoom: TcxLabel
          Left = 255
          Top = 6
          Anchors = [akTop, akRight]
          Caption = '100%'
          Transparent = True
        end
        object ceBackColor: TdxColorEdit
          Left = 98
          Top = 4
          Anchors = [akLeft, akTop, akRight]
          Properties.OnChange = ceBackColorPropertiesChange
          Style.BorderColor = clBlack
          Style.Color = clBtnFace
          Style.TransparentBorder = True
          Style.ButtonTransparency = ebtNone
          StyleFocused.Color = clBtnFace
          StyleHot.Color = clBtnFace
          TabOrder = 2
          Width = 135
        end
        object lbBackColor: TcxLabel
          Left = 5
          Top = 6
          Caption = 'Background Color:'
          Transparent = True
        end
      end
    end
  end
  object cdsFilms: TClientDataSet
    Aggregates = <>
    Filtered = True
    Params = <>
    Left = 304
    Top = 88
    object cdsFilmsID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object cdsFilmsCAPTION: TStringField
      FieldName = 'CAPTION'
      Size = 50
    end
    object cdsFilmsYEAR: TIntegerField
      FieldName = 'YEAR'
    end
    object cdsFilmsTAGLINE: TStringField
      FieldName = 'TAGLINE'
      Size = 250
    end
    object cdsFilmsPLOTOUTLINE: TStringField
      DisplayWidth = 50
      FieldName = 'PLOTOUTLINE'
      Size = 200
    end
    object cdsFilmsRUNTIME: TIntegerField
      FieldName = 'RUNTIME'
    end
    object cdsFilmsCOLOR: TStringField
      FieldName = 'COLOR'
      Size = 50
    end
    object cdsFilmsPHOTO: TBlobField
      FieldName = 'PHOTO'
      Size = 10
    end
    object cdsFilmsICON: TBlobField
      FieldName = 'ICON'
      Size = 10
    end
    object cdsFilmsWEBSITE: TStringField
      FieldName = 'WEBSITE'
      Size = 50
    end
  end
  object pmTextSettings: TPopupMenu
    Left = 300
    Top = 135
    object miInvisible: TMenuItem
      AutoCheck = True
      Caption = 'None'
      RadioItem = True
      OnClick = miInvisibleClick
    end
    object miTopSide: TMenuItem
      AutoCheck = True
      Caption = 'Top'
      RadioItem = True
      OnClick = miTopSideClick
    end
    object miLeftSide: TMenuItem
      AutoCheck = True
      Caption = 'Left'
      RadioItem = True
      OnClick = miLeftSideClick
    end
    object miRightSide: TMenuItem
      AutoCheck = True
      Caption = 'Right'
      RadioItem = True
      OnClick = miRightSideClick
    end
    object miBottomSide: TMenuItem
      AutoCheck = True
      Caption = 'Bottom'
      RadioItem = True
      OnClick = miBottomSideClick
    end
  end
  object pmColumnSettings: TPopupMenu
    Left = 332
    Top = 135
    object miAutoColumnCount: TMenuItem
      AutoCheck = True
      Caption = 'Auto'
      RadioItem = True
      OnClick = miAutoColumnCountClick
    end
    object miLine: TMenuItem
      AutoCheck = True
      Caption = '-'
      RadioItem = True
    end
    object miThreeColumns: TMenuItem
      AutoCheck = True
      Caption = '3'
      RadioItem = True
      OnClick = miThreeColumnsClick
    end
    object miFourColumns: TMenuItem
      AutoCheck = True
      Caption = '4'
      RadioItem = True
      OnClick = miFourColumnsClick
    end
    object miFiveColumns: TMenuItem
      AutoCheck = True
      Caption = '5'
      RadioItem = True
      OnClick = miFiveColumnsClick
    end
  end
  object cxLookAndFeelController1: TcxLookAndFeelController
    SkinName = 'Black'
    Left = 376
    Top = 136
  end
  object cdsGenres: TClientDataSet
    Aggregates = <>
    Params = <>
    Left = 344
    Top = 88
    object cdsGenresID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object cdsGenresNAME: TStringField
      FieldName = 'NAME'
      Size = 50
    end
  end
  object cdsFilmsGenres: TClientDataSet
    Aggregates = <>
    Params = <>
    Left = 384
    Top = 88
    object cdsFilmsGenresID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object cdsFilmsGenresFILMID: TIntegerField
      FieldName = 'FILMID'
    end
    object cdsFilmsGenresGENREID: TIntegerField
      FieldName = 'GENREID'
    end
    object cdsFilmsGenresPHOTO: TBlobField
      FieldName = 'PHOTO'
    end
    object cdsFilmsGenresICON: TBlobField
      FieldName = 'ICON'
    end
  end
end
