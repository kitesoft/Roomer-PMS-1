unit uRoomerConfirmationDialogs;

interface

function openLogin(var userName, password : string; AuthValueIndex : Integer = -1) : boolean;

implementation

uses RoomerLoginForm,
     uG,
     uRoomerVersionInfo,
     uD
     , uRoomerDefinitions;

function openLogin(var userName, password : string; AuthValueIndex : Integer = -1) : boolean;
var hotelId : String;
    lastMessage : String;
begin
  result      := false;
  lastMessage := '';
  hotelId     := g.qHotelCode;
//  showmessage(username+' // '+password);

  if (AskUserForCredentials(userName, password, hotelId, lastMessage, AuthValueIndex) in cLoginFormSuccesfull) then
  begin
      try
        d.roomerMainDataSet.Login(hotelId, username, password, cOpenAPIAppicationID, TRoomerVersionInfo.FileVersion);
        result := true;
      except
        result := false;
      end;
  end;

end;


end.
