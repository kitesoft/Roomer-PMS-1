unit uSocketHelpers;

interface

uses
  Forms,
  winsock,
  Windows;

type
  TAvailablePortArray = array of Word;


function findAvailableTCPPort( const ipAddressStr : AnsiString; portStart : Word = 62989; portEnd : Word = 62999; findCount : Byte = 2 ) : TAvailablePortArray;

implementation

function findAvailableTCPPort( const ipAddressStr : AnsiString; portStart : Word = 62989; portEnd : Word = 62999; findCount : Byte = 2 ) : TAvailablePortArray;
var
  client    : sockaddr_in;
  sock      : TSocket;
  wsdata    : WSAData;
  dwPort    : Word;
  iFound    : Byte;
  arrFound  : TAvailablePortArray;
begin
  SetLength( Result, 0 );
  if ( portStart = 0 ) or ( portStart > portEnd ) or ( findCount = 0 ) then
    Exit;

  //initiates use of the Winsock DLL
  if ( WSAStartup(SMALLINT(2), wsdata) <> 0 ) then
    Exit;

  try
    //Set the protocol to use , in this case (IPv4)
    fillChar( client, sizeOf( client ), 0 );
    client.sin_family      := AF_INET;
    client.sin_addr.s_addr := inet_addr(PAnsiChar(ipAddressStr));

    dwPort := portStart;
    SetLength( arrFound, findCount );
    iFound := 0;
    try

      repeat
        sock := socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);    //creates a socket
        if sock = INVALID_SOCKET then Break;

        try
          if GetQueueStatus(QS_ALLINPUT) <> 0 then
            Application.ProcessMessages();

          client.sin_port := htons(dwPort); //convert to TCP/IP network byte order (big-endian)

          if bind(sock, PSockAddr(@client)^, sizeOf(client)) = 0 then
          begin
            arrFound[iFound] := dwPort;
            Inc( iFound );
          end;
        finally
          closesocket(sock);
        end;

        Inc(dwPort);
      until ( iFound = findCount ) or ( dwPort > portEnd );
    finally
      SetLength(arrFound, iFound);
    end;
  finally
    WSACleanup();
  end;

  Result := arrFound;
end;

end.
