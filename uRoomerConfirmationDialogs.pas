unit uRoomerConfirmationDialogs;

interface

function openLogin(var userName, password : string) : boolean;

implementation

uses RoomerLoginForm,
     uG,
     uRoomerVersionInfo,
     uD
     ;

function openLogin(var userName, password : string) : boolean;
var hotelId : String;
    lastMessage : String;
begin
  result      := false;
  lastMessage := '';
  hotelId     := g.qHotelCode;
//  showmessage(username+' // '+password);

  if (AskUserForCredentials(userName, password, hotelId, lastMessage) in cLoginFormSuccesfull) then
  begin
      try
        d.roomerMainDataSet.Login(hotelId, username, password, 'ROOMERPMS', TRoomerVersionInfo.FileVersion);
        result := true;
      except
        result := false;
      end;
  end;

end;


end.
