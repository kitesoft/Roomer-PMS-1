unit uExceptionUtils;

interface

uses
  SysUtils
  ;

type
  ENotYetImplementedException = class(Exception);


procedure RaiseMethodNotImplementedException;

implementation

procedure  RaiseMethodNotImplementedException;
begin
{$ifdef DEBUG}
  raise ENotYetImplementedException.Create('Method is not yet implemented');
{$endif}
end;




end.