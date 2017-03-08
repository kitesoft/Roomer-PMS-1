unit uRoomerCanonicalDataModel_SimpleTypes;

interface

uses
   Classes
   , SysUtils
   , Spring.Collections.Lists
   , Spring.Collections
   , uRoomerSchema
   , XMLIntf
   , OXmlPDOM
   ;

type

{$SCOPEDENUMS ON}
  TxsdISO31661alpha2CountryCode = (
			AF,
			AX,
			AL,
			DZ,
			AS_,
			AD,
			AO,
			AI,
			AQ,
			AG,
			AR,
			AM,
			AW,
			AU,
			AT,
			AZ,
			BS,
			BH,
			BD,
			BB,
			BY,
			BE,
			BZ,
			BJ,
			BM,
			BT,
			BO,
			BQ,
			BA,
			BW,
			BV,
			BR,
			IO,
			BN,
			BG,
			BF,
			BI,
			KH,
			CM,
			CA,
			CV,
			KY,
			CF,
			TD,
			CL,
			CN,
			CX,
			CC,
			CO,
			KM,
			CG,
			CD,
			CK,
			CR,
			CI,
			HR,
			CU,
			CW,
			CY,
			CZ,
			DK,
			DJ,
			DM,
			DO_,
			EC,
			EG,
			SV,
			GQ,
			ER,
			EE,
			ET,
			FK,
			FO,
			FJ,
			FI,
			FR,
			GF,
			PF,
			TF,
			GA,
			GM,
			GE,
			DE,
			GH,
			GI,
			GR,
			GL,
			GD,
			GP,
			GU,
			GT,
			GG,
			GN,
			GW,
			GY,
			HT,
			HM,
			VA,
			HN,
			HK,
			HU,
			IS_,
			IN_,
			ID,
			IR,
			IQ,
			IE,
			IM,
			IL,
			IT,
			JM,
			JP,
			JE,
			JO,
			KZ,
			KE,
			KI,
			KP,
			KR,
			KW,
			KG,
			LA,
			LV,
			LB,
			LS,
			LR,
			LY,
			LI,
			LT,
			LU,
			MO,
			MK,
			MG,
			MW,
			MY,
			MV,
			ML,
			MT,
			MH,
			MQ,
			MR,
			MU,
			YT,
			MX,
			FM,
			MD,
			MC,
			MN,
			ME,
			MS,
			MA,
			MZ,
			MM,
			NA,
			NR,
			NP,
			NL,
			NC,
			NZ,
			NI,
			NE,
			NG,
			NU,
			NF,
			MP,
			NO,
			OM,
			PK,
			PW,
			PS,
			PA,
			PG,
			PY,
			PE,
			PH,
			PN,
			PL,
			PT,
			PR,
			QA,
			RE,
			RO,
			RU,
			RW,
			BL,
			SH,
			KN,
			LC,
			MF,
			PM,
			VC,
			WS,
			SM,
			ST,
			SA,
			SN,
			RS,
			SC,
			SL,
			SG,
			SX,
			SK,
			SI,
			SB,
			SO,
			ZA,
			GS,
			SS,
			ES,
			LK,
			SD,
			SR,
			SJ,
			SZ,
			SE,
			CH,
			SY,
			TW,
			TJ,
			TZ,
			TH,
			TL,
			TG,
			TK,
			TO_,
			TT,
			TN,
			TR,
			TM,
			TC,
			TV,
			UG,
			UA,
			AE,
			GB,
			US,
			UM,
			UY,
			UZ,
			VU,
			VE,
			VN,
			VG,
			VI,
			WF,
			EH,
			YE,
			ZM,
			ZW
  );

  TxsdISO31661alpha2CountryCodeHelper = record helper for TxsdISO31661alpha2CountryCode
    class function FromString(const aString: string): TxsdISO31661alpha2CountryCode; static;
    function AsString: String;
  end;

  TxsdISO4217CurrencyCode = (
			AFN,
			AED,
			ALL,
			AMD,
			ANG,
			AOA,
			ARS,
			AUD,
			AWG,
			AZN,
			BAM,
			BBD,
			BDT,
			BGN,
			BHD,
			BIF,
			BMD,
			BND,
			BOB,
			BOV,
			BRL,
			BSD,
			BTN,
			BWP,
			BYR,
			BZD,
			CAD,
			CDF,
			CHE,
			CHF,
			CHW,
			CLF,
			CLP,
			CNY,
			COP,
			COU,
			CRC,
			CUC,
			CUP,
			CVE,
			CZK,
			DJF,
			DKK,
			DOP,
			DZD,
			EGP,
			ERN,
			ETB,
			EUR,
			FJD,
			FKP,
			GBP,
			GEL,
			GHS,
			GIP,
			GMD,
			GNF,
			GTQ,
			GYD,
			HKD,
			HNL,
			HRK,
			HTG,
			HUF,
			IDR,
			ILS,
			INR,
			IQD,
			IRR,
			ISK,
			JMD,
			JOD,
			JPY,
			KES,
			KGS,
			KHR,
			KMF,
			KPW,
			KRW,
			KWD,
			KYD,
			KZT,
			LAK,
			LBP,
			LKR,
			LRD,
			LSL,
			LTL,
			LVL,
			LYD,
			MAD,
			MDL,
			MGA,
			MKD,
			MMK,
			MNT,
			MOP,
			MRO,
			MUR,
			MVR,
			MWK,
			MXN,
			MXV,
			MYR,
			MZN,
			NAD,
			NGN,
			NIO,
			NOK,
			NPR,
			NZD,
			OMR,
			PAB,
			PEN,
			PGK,
			PHP,
			PKR,
			PLN,
			PYG,
			QAR,
			RON,
			RSD,
			RUB,
			RWF,
			SAR,
			SBD,
			SCR,
			SDG,
			SEK,
			SGD,
			SHP,
			SLL,
			SOS,
			SRD,
			SSP,
			STD,
			SVC,
			SYP,
			SZL,
			THB,
			TJS,
			TMT,
			TND,
			TOP,
			TRY_,
			TTD,
			TWD,
			TZS,
			UAH,
			UGX,
			USD,
			USN,
			USS,
			UYI,
			UYU,
			UZS,
			VEF,
			VND,
			VUV,
			WST,
			XAF,
			XAG,
			XAU,
			XBA,
			XBB,
			XBC,
			XBD,
			XCD,
			XDR,
			XOF,
			XPD,
			XPF,
			XPT,
			XSU,
			XTS,
			XUA,
			XXX,
			YER,
			ZAR,
			ZMW,
			ZWL
  );
  TxsdISO4217CurrencyCodeHelper = record helper for TxsdISO4217CurrencyCode
    class function FromString(const aString: string): TxsdISO4217CurrencyCode; static;
    function AsString: String;
  end;


implementation

{ TxsdISO31661alpha2CountryCodeHelper }

uses
  uUtils
  , TypInfo
  ;

function TxsdISO31661alpha2CountryCodeHelper.asString: String;
begin
  Result := Copy(GetEnumAsString(TypeInfo(TxsdISO31661alpha2CountryCode), ord(Self)), 1, 2);
end;

class function TxsdISO31661alpha2CountryCodeHelper.FromString(const aString: string): TxsdISO31661alpha2CountryCode;
var
  lOrd: integer;
begin
  lOrd := GetEnumValue(TypeInfo(TxsdISO31661alpha2CountryCode), aString);
  if lOrd < 0 then
    lOrd := GetEnumValue(TypeInfo(TxsdISO31661alpha2CountryCode), aString + '_');

  Result := TxsdISO31661alpha2CountryCode(lOrd);
end;

{ TxsdISO4217CurrencyCodeHelper }

function TxsdISO4217CurrencyCodeHelper.AsString: String;
begin
  Result := Copy(GetEnumAsString(TypeInfo(TxsdISO4217CurrencyCode), ord(Self)), 1, 3);
end;

class function TxsdISO4217CurrencyCodeHelper.FromString(const aString: string): TxsdISO4217CurrencyCode;
var
  lOrd: integer;
begin
  lOrd := GetEnumValue(TypeInfo(TxsdISO4217CurrencyCode), aString);
  if lOrd < 0 then
    lOrd := GetEnumValue(TypeInfo(TxsdISO4217CurrencyCode), aString + '_');

  Result := TxsdISO4217CurrencyCode(lOrd);
end;

end.
