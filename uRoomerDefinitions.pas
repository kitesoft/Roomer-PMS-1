unit uRoomerDefinitions;

interface

uses
  Graphics
  , WinAPI.Messages
  ;

const
  cHotelInvoice  = 0;
  cCreditInvoive = 1;
  cCashInvoice   = 2;

const
  qcCompany        = 'Roomer';
  cRoomerFolder    = 'Roomer';
  cRoomerUpgradeFolder = 'Upgrades';
  cRoomerLoggingFolder = 'RoomerLogging';
  qcApplication    = 'Roomer PMS';
  cUpgradeDaemon   = 'RoomerUpgradeDaemon.exe';
  cOpenAPIApplicationID = 'ROOMERPMS';
  testCompanyID    = '00';
  testCompanyName  = 'Hotel Trial';
  testExpDate      = 30;
  testRoomCount    = 10;
  testMeetingsRoomCount = 0;
  testConnStr      = '';
  testConnStr2     = '';
  testDiskSerial   = 'HHHH-JJJJ';

  TIM_MILLI_SECOND = 1;
  TIM_SECOND       = TIM_MILLI_SECOND * 1000;
  TIM_MINUTE       = TIM_SECOND * 60;
  TIM_10_MINUTES   = TIM_MINUTE * 10;
  TIM_15_MINUTES   = TIM_MINUTE * 15;
  TIM_HALF_HOUR    = TIM_MINUTE * 30;
  TIM_HOUR         = TIM_MINUTE * 60;
  TIM_DAY          = TIM_HOUR * 24;


  // Registry keys
const
  secAppRegistration = 'AppReg';
  indApplicationID = 'Application_ID';
  indAppKey = 'Application_Key';
  indAppSecret = 'Application_Secret';

// Windows events
const
  WM_SET_DATE_FROM_MAIN = WM_User + 31;
  WM_REFRESH_ARRIVAL_DATE = WM_User + 32;
  WM_REFRESH_DEPARTURE_DATE = WM_User + 33;
  WM_REFRESH_DATE = WM_User + 41;
  WM_REFRESH_PERIOD_VIEW_BOTTOM = WM_User + 392;
  WM_REFRESH_PERIOD_VIEW_BOTTOM_REFRESH = WM_User + 393;
  WM_REFRESH_SKIN_MANAGER = WM_User + 391;
  WM_REFRESH_STAFF_COMM_NOTIFIER = WM_User + 394;


const
  peExportNot     = 0;
  peExportFolder  = 1;
  peExportLogFile = 2;

  PAYMENT_GUARANTEE_TYPE : Array[0..2] of String = ('CREDIT_CARD','DOWN_PAYMENT','NONE');

const
  RESERVATION_STATUS_STRING = 'PGDCONABCWZX';

type
  recStatusAttr = record
    backgroundColor : TColor;
    fontColor	      : TColor;
    isBold          : Boolean;
    isItalic        : boolean;
    isUnderline     : boolean;
    isStrikeOut     : boolean;
  end;


implementation

end.
