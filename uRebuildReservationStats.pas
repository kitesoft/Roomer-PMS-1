unit uRebuildReservationStats;

interface

uses
    Winapi.Windows
  , Winapi.Messages
  , System.SysUtils
  , System.Variants
  , System.Classes

  , Vcl.Graphics
  , Vcl.Controls
  , Vcl.Forms
  , Vcl.Dialogs
  , Vcl.Menus
  , Vcl.ComCtrls
  , Vcl.StdCtrls
  , shellApi

  , Data.DB
  , Data.Win.ADODB
  , Vcl.ExtCtrls

  , _Glob
  , hData
  , uG

  , cxGridExportLink

  , cxGraphics
  , cxLookAndFeels
  , cxLookAndFeelPainters
  , cxControls
  , cxContainer
  , cxEdit
  , cxStyles
  , cxCustomData
  , cxFilter
  , cxData
  , cxDataStorage
  , cxNavigator
  , cxDBData
  , cxGridCustomTableView
  , cxGridTableView
  , cxGridDBTableView
  , cxGridLevel
  , cxClasses
  , cxGridCustomView
  , cxGrid
  , dxmdaset
  , cxProgressBar
  , dxStatusBar
  , cxButtons, kbmMemTable, kbmMemSQL

  , cmpRoomerDataSet
  , cmpRoomerConnection, dxSkinsCore, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin, dxSkinOffice2013White,
  dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld
  ;

type
  TfrmRebuildReservationStats = class(TForm)
    dxStatusBar1: TdxStatusBar;
    dxStatusBar1Container1: TdxStatusBarContainerControl;
    barProcess: TcxProgressBar;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);



  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmRebuildReservationStats: TfrmRebuildReservationStats;

implementation

{$R *.dfm}

uses
  uD
 ,uSqlDefinitions
;



function DateRangeIndex(aDate,dateFrom,DateTo : TdateTime) : integer;
var
  index1 : integer;
  index2 : integer;
begin
  result := -1;
  index1 := trunc(aDate)-trunc(dateFrom);
  index2 := trunc(dateTo)-trunc(aDate);
  if (index1 >= 0) and (index2 >0) then
  begin
    result := index1;
  end;
end;


procedure TfrmRebuildReservationStats.Button1Click(Sender: TObject);
begin
  screen.Cursor := crHourGlass;
  try
    d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'pms/business/home_to_roomer_roomsdate');
    showmessage('Finished')
  finally
    screen.Cursor := crDefault;
  end;
end;


end.




