inherited FrmResources: TFrmResources
  Caption = 'Resources'
  ClientHeight = 561
  ClientWidth = 991
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  ExplicitWidth = 1007
  ExplicitHeight = 600
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 541
    Width = 991
    ExplicitTop = 541
    ExplicitWidth = 991
  end
  object pnlHolder: TsPanel [1]
    Left = 0
    Top = 0
    Width = 991
    Height = 541
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object sPanel1: TsPanel
      Left = 0
      Top = 0
      Width = 991
      Height = 48
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      object btnInsert: TsButton
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 114
        Height = 36
        Hint = 'Add new record'
        Margins.Bottom = 9
        Align = alLeft
        Caption = 'New'
        ImageIndex = 23
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = btnInsertClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnDelete: TsButton
        AlignWithMargins = True
        Left = 243
        Top = 3
        Width = 114
        Height = 36
        Hint = 'Delete current record'
        Margins.Bottom = 9
        Align = alLeft
        Caption = 'Delete'
        Enabled = False
        ImageIndex = 24
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = btnDeleteClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnClose: TsButton
        AlignWithMargins = True
        Left = 888
        Top = 3
        Width = 100
        Height = 36
        Margins.Bottom = 9
        Align = alRight
        Cancel = True
        Caption = 'Close'
        ImageIndex = 27
        Images = DImages.PngImageList1
        ModalResult = 8
        TabOrder = 2
        OnClick = btnCloseClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnView: TsButton
        AlignWithMargins = True
        Left = 123
        Top = 3
        Width = 114
        Height = 36
        Hint = 'Delete current record'
        Margins.Bottom = 9
        Align = alLeft
        Caption = 'View'
        Enabled = False
        ImageIndex = 17
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = btnViewClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnEdit: TsButton
        AlignWithMargins = True
        Left = 483
        Top = 3
        Width = 114
        Height = 36
        Hint = 'Delete current record'
        Margins.Bottom = 9
        Align = alLeft
        Caption = 'Edit'
        Enabled = False
        ImageIndex = 25
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        Visible = False
        OnClick = btnEditClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnRename: TsButton
        AlignWithMargins = True
        Left = 363
        Top = 3
        Width = 114
        Height = 36
        Hint = 'Delete current record'
        Margins.Bottom = 9
        Align = alLeft
        Caption = 'Name and subject'
        Enabled = False
        ImageIndex = 29
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        OnClick = btnRenameClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnSource: TsButton
        AlignWithMargins = True
        Left = 603
        Top = 3
        Width = 114
        Height = 36
        Hint = 'Delete current record'
        Margins.Bottom = 9
        Align = alLeft
        Caption = 'Source'
        Enabled = False
        ImageIndex = 115
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 6
        Visible = False
        OnClick = btnSourceClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object sPanel2: TsPanel
      Left = 0
      Top = 499
      Width = 991
      Height = 42
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 1
      Visible = False
      SkinData.SkinSection = 'PANEL'
      object sButton1: TsButton
        AlignWithMargins = True
        Left = 876
        Top = 3
        Width = 112
        Height = 36
        Align = alRight
        Cancel = True
        Caption = 'Cancel'
        ImageIndex = 27
        Images = DImages.PngImageList1
        ModalResult = 2
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
      object sButton2: TsButton
        AlignWithMargins = True
        Left = 760
        Top = 3
        Width = 110
        Height = 36
        Align = alRight
        Caption = 'OK'
        Default = True
        ImageIndex = 82
        Images = DImages.PngImageList1
        ModalResult = 1
        TabOrder = 1
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object grData: TcxGrid
      Left = 0
      Top = 48
      Width = 991
      Height = 451
      Align = alClient
      PopupMenu = PopupMenu1
      TabOrder = 2
      object tvResources: TcxGridDBTableView
        Navigator.Buttons.CustomButtons = <>
        OnCellDblClick = tvResourcesCellDblClick
        DataController.DataSource = dsGrid
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsData.Deleting = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.CellSelect = False
        Styles.StyleSheet = cxssRoomerGridTableView
        object tvResourcesID: TcxGridDBColumn
          DataBinding.FieldName = 'ID'
          Visible = False
        end
        object tvResourcesResourceType: TcxGridDBColumn
          Caption = 'Reource Type'
          DataBinding.FieldName = 'ResourceType'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.Alignment.Horz = taLeftJustify
          OnGetDisplayText = tvResourcesResourceTypeGetDisplayText
          Width = 163
        end
        object tvResourcesOriginalName: TcxGridDBColumn
          Caption = 'File name'
          DataBinding.FieldName = 'original_name'
          Width = 191
        end
        object tvResourcesExtraInfo: TcxGridDBColumn
          Caption = 'Subject'
          DataBinding.FieldName = 'EXTRA_INFO'
          Width = 210
        end
        object tvResourcesURI: TcxGridDBColumn
          Caption = 'Address'
          DataBinding.FieldName = 'URI'
          Width = 261
        end
        object tvResourcesUser: TcxGridDBColumn
          DataBinding.FieldName = 'User'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.Alignment.Horz = taCenter
          BestFitMaxWidth = 64
        end
        object tvResourcesLastModified: TcxGridDBColumn
          Caption = 'Last modified'
          DataBinding.FieldName = 'LAST_MODIFIED'
          Width = 133
        end
        object tvResourcesColumn1: TcxGridDBColumn
          Caption = 'Access'
          DataBinding.FieldName = 'ACCESS'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.Alignment.Horz = taLeftJustify
          OnGetDisplayText = tvResourcesColumn1GetDisplayText
        end
      end
      object lvlResources: TcxGridLevel
        GridView = tvResources
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
  object PopupMenu1: TPopupMenu
    OnPopup = PopupMenu1Popup
    Left = 224
    Top = 264
    object C2: TMenuItem
      Caption = 'Copy'
      ShortCut = 16451
      OnClick = C2Click
    end
    object P1: TMenuItem
      Caption = 'Paste'
      ShortCut = 16470
      OnClick = P1Click
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object V1: TMenuItem
      Caption = 'View'
      Default = True
      OnClick = btnViewClick
    end
    object D1: TMenuItem
      Caption = 'Download'
      OnClick = D1Click
    end
    object U1: TMenuItem
      Caption = 'Upload'
      OnClick = btnInsertClick
    end
    object D2: TMenuItem
      Caption = 'Delete'
      OnClick = btnDeleteClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object C1: TMenuItem
      Caption = 'Copy link'
      OnClick = C1Click
    end
  end
  object dlgSaveFile: TsSaveDialog
    Filter = 
      'Any file (*.*)|*.*|Acrobat PDF files (*.pdf)|*.pdf|Microsoft Wor' +
      'd (*.doc;*.docx)|*.doc;*.docx|Images (*.jpg;*.png;*.bmp;*.gif)|*' +
      '.jpg;*.png;*.bmp;*.gif|Videos (*.wmv;*.avi;*.mp4)|*.wmv;*.avi;*.' +
      'mp4|Sound (*.mp3)|*.mp3'
    FilterIndex = 0
    Left = 160
    Top = 184
  end
  object dlgOpenFile: TsOpenDialog
    Filter = 
      'Any file (*.*)|*.*|Acrobat PDF files (*.pdf)|*.pdf|Microsoft Wor' +
      'd (*.doc;*.docx)|*.doc;*.docx|Images (*.jpg;*.png;*.bmp;*.gif)|*' +
      '.jpg;*.png;*.bmp;*.gif|Videos (*.wmv;*.avi;*.mp4)|*.wmv;*.avi;*.' +
      'mp4|Sound (*.mp3)|*.mp3'
    FilterIndex = 0
    Left = 160
    Top = 136
  end
  object DropComboTarget1: TDropComboTarget
    DragTypes = [dtCopy, dtLink]
    OnDrop = DropComboTarget1Drop
    Target = grData
    Left = 372
    Top = 304
  end
  object dsResources: TObjectDataSet
    AfterScroll = dsResourcesAfterScroll
    BeforeDelete = dsResourcesBeforeDelete
    Left = 408
    Top = 152
  end
  object dsGrid: TDataSource
    DataSet = dsResources
    Left = 488
    Top = 144
  end
  object DropFileSource1: TDropFileSource
    DragTypes = [dtCopy]
    Left = 368
    Top = 368
  end
end
