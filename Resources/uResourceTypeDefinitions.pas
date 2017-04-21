unit uResourceTypeDefinitions;

interface

uses
  Classes
  , SysUtils
  ;


type
  EResourceTypeDefinitionException = class(Exception);

{% SCOPEDENUMS ON}
  TResourceType = ( rtAnyFile,
                    rtGuestEmailTemplate,
                    rtCancelEmailTemplate,
                    rtPreArrivalEmailTemplate,
                    rtPostDepartureEmailTemplate,
                    rtRoomImage,
                    rtRoomClassImage,
                    rtCustomerDocument,
                    rtBooking,
                    rtRoomBooking,
                    rtGuest
                    );

  TResourceTypeHelper = record helper for TResourceType
  private
    const cNames: array[TResourceType] of string = ('ANY_FILE',
                                                    'GUEST_EMAIL_TEMPLATE',
                                                    'CANCEL_EMAIL_TEMPLATE',
                                                    'PRE_ARRIVAL_MAIL_TEMPLATE',
                                                    'POST_DEPARTURE_MAIL_TEMPLATE',
                                                    'ROOMIMAGE_%s',
                                                    'ROOMCLASSIMAGE_%s',
                                                    'CUSTOMERRESOURCES_%s',
                                                    'BOOKING_RESOURCE_%s',
                                                    'ROOM_BOOKING_RESOURCE_%s',
                                                    'GUEST_RESOURCE_%s'
                                                    );


    const cDefaultFilename: array[TResourceType] of string = ( '',
                                                              'Booking_Confirmation_%s.html',
                                                              'Cancel_Confirmation__%s.html',
                                                              'Pre_arrival_email_%s.html',
                                                              'Post_departure_email_%s.html',
                                                              '',
                                                              '',
                                                              '',
                                                              '',
                                                              '',
                                                              ''
                                                            );
  public
    class function FromString(const aValue: string): TResourceType; static;
    class procedure AsStrings(aItemList: TStrings); static;
    function ToKeyString(const aParam: string = ''): string;
    function AsReadableString: string;
    function DefaultFilename: string;
  end;

  TResourceTypeSet = set of TResourceType;
  TResourceTypeSetHelper = record helper for TResourceTypeSet
  public
    procedure AsStrings(aItemList: TStrings);
    function Count: integer;
  end;


  TResourceAccessType = (ratOpen, ratRestricted);
  TResourceAccesTypeHelper = record helper for TResourceAccessType
  private
    const cNames: array[TResourceAccessType] of string = ('OPEN', 'RESTRICTED');
    const cFolders: array[TResourceAccessType] of string = ('/direct/', '/private/');
  public
    class function FromString(const aValue: string): TResourceAccessType; static;
    function ToString: string;
    function AsReadableString: string;
    function ResourceFolder: string;
  end;

const
  cEmailTemplateResourceTypes: TResourceTypeSet = [rtGuestEmailTemplate, rtCancelEmailTemplate, rtPreArrivalEmailTemplate, rtPostDepartureEmailTemplate];

implementation

uses
  PrjConst
  ,uDateUtils
  ;

{ TResourceAccesTypeHelper }

function TResourceAccesTypeHelper.AsReadableString: string;
begin
  case Self of
    ratOpen:        Result := GetTranslatedText('shTx_ResourceAccesType_OPEN');
    ratRestricted:  Result := GetTranslatedText('shTx_ResourceAccesType_RESTRICTED');
  else
    Result := '';
  end;
end;

function TResourceAccesTypeHelper.ResourceFolder: string;
begin
  Result := cFolders[Self];
end;

class function TResourceAccesTypeHelper.FromString(const aValue: string): TResourceAccessType;
var
  lType: TResourceAccessType;
  lFound: boolean;
begin
  lFound := false;
  result := ratOpen;
  for lType := Low(lType) to High(lType) do
    if cNames[lType].toUpper.Equals(aValue.ToUpper) then
    begin
      Result := lType;
      lFound := true;
      Break;
    end;

  if not lFound then
    raise EResourceTypeDefinitionException.CreateFmt('Unknown ResourceType: [%s]', [aValue]);
end;

function TResourceAccesTypeHelper.ToString: string;
begin
  Result := cNames[Self];
end;

{ TResourceTypeHelper }

function TResourceTypeHelper.AsReadableString: string;
begin
  case Self of
    rtAnyFile:                  Result := GetTranslatedText('shTx_ResourceType_ANYFILE');
    rtGuestEmailTemplate:       Result := GetTranslatedText('shTx_ResourceType_GUEST_EMAIL');
    rtCancelEmailTemplate:      Result := GetTranslatedText('shTx_ResourceType_CANCEL_EMAIL');
    rtPreArrivalEmailTemplate:    Result := GetTranslatedText('shTx_ResourceType_PRE_ARRIVAL_EMAIL');
    rtPostDepartureEmailTemplate: Result := GetTranslatedText('shTx_ResourceType_POST_DEPARTURE_EMAIL');
    rtRoomImage:                  Result := GetTranslatedText('shTx_ResourceType_ROOM_IMAGE');
    rtRoomClassImage:             Result := GetTranslatedText('shTx_ResourceType_ROOM_CLASS_IMAGE');
    rtCustomerDocument:           Result := GetTranslatedText('shTx_ResourceType_CUSTOMER_DOCUMENT');
    rtBooking:                    Result := GetTranslatedText('shTx_ResourceType_BOOKING');
    rtRoomBooking:                Result := GetTranslatedText('shTx_ResourceType_ROOM_BOOKING');
    rtGuest:                      Result := GetTranslatedText('shTx_ResourceType_GUEST');
  else
    Result := '';
  end;

end;

class procedure TResourceTypeHelper.AsStrings(aItemList: TStrings);
var
  lType: TResourceType;
begin
  aItemList.BeginUpdate;
  try
    aItemList.Clear;
    for lType := low(lTYpe) to High(lType) do
      aItemList.Add(ltype.AsReadableString);
  finally
    aItemList.EndUpdate;
  end;
end;

function TResourceTypeHelper.DefaultFilename: string;
begin
  Result := cDefaultFileName[Self];
  if not Result.IsEmpty then
    Result :=  Format(Result, [dateToSqlString(now)]);
end;

class function TResourceTypeHelper.FromString(const aValue: string): TResourceType;
var
  lType: TResourceType;
  lFound: boolean;
  t1, t2: string;
begin
  lFound := false;
  Result := rtAnyFile;
  for lType := Low(lType) to High(lType) do
  begin
    t1 := cNames[lType].toUpper;
    t2 := cNames[lType].toUpper.Replace('%S', '', [rfReplaceAll, rfIgnoreCase]);

    if (cNames[lType].toUpper.Equals(aValue.ToUpper)) or
      (aValue.ToUpper.StartsWith(cNames[lType].toUpper.Replace('%S', '', [rfReplaceAll, rfIgnoreCase])))  then
    begin
      Result := lType;
      lFound := true;
      Break;
    end;

  end;
  if not lFound then
    raise EResourceTypeDefinitionException.CreateFmt('Unknown ResourceType: [%s]', [aValue]);
end;

function TResourceTypeHelper.ToKeyString(const aParam: string): string;
begin
  Result := cNames[Self];
  if Result.Contains('%s') then
    if aParam.IsEmpty then
      raise EResourceTypeDefinitionException.CreateFmt('No param provided for KeyString [%s]', [cNAmes[Self]])
    else
      Result := Format(Result, [aParam]);
end;

{ TResourceTypeSetHelper }

procedure TResourceTypeSetHelper.AsStrings(aItemList: TStrings);
var
  lType: TResourceType;
begin
  aItemList.BeginUpdate;
  try
    aItemList.Clear;
      for lType in Self do
        aItemList.AddObject(lType.AsReadableString, TObject(ord(lType)));
  finally
    aItemList.EndUpdate;
  end;
end;

function TResourceTypeSetHelper.Count: integer;
var
  lType: TResourceType;
begin
  Result := 0;
  for lType in Self do
    inc(Result);
end;

end.
