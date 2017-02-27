inherited frmOlapBrowser: TfrmOlapBrowser
  Left = 228
  Top = 187
  Caption = 'PivotGrid - OLAP Browser Demo'
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  inherited lbDescrip: TLabel
    Caption = 
      'This demo shows you how to mine data from an OLAP cube. To run t' +
      'his demo you must have the MSOLAP 10.0 OLE DB provider properly ' +
      'installed on your system.'
  end
  object UnboundPivotGrid: TcxPivotGrid [1]
    Left = 244
    Top = 32
    Width = 563
    Height = 512
    Customization.Site = Panel1
    OLAPDataSource = OLAPDataSource
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Groups = <>
    ParentFont = False
    TabOrder = 0
  end
  object Panel1: TPanel [2]
    Left = 0
    Top = 32
    Width = 236
    Height = 512
    Align = alLeft
    TabOrder = 1
  end
  object cxSplitter1: TcxSplitter [3]
    Left = 236
    Top = 32
    Width = 8
    Height = 512
    HotZoneClassName = 'TcxSimpleStyle'
    HotZone.SizePercent = 75
  end
  inherited mmMain: TMainMenu
    inherited miFile: TMenuItem
      object NewConnection1: TMenuItem [0]
        Caption = 'New Connection'
        OnClick = NewConnection1Click
      end
      object N3: TMenuItem [1]
        Caption = '-'
      end
    end
  end
  object OLAPDataSource: TcxPivotGridOLAPDataSource
    CacheLocalCubes = True
    Active = False
    Left = 712
  end
end
