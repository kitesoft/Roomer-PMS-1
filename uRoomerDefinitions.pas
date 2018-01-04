unit uRoomerDefinitions;

interface

uses Graphics;

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
