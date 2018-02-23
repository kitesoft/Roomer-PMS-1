unit uMobileAPI;

interface
uses
    cmpRoomerDataset
  , SysUtils
  ;

type
  EMobileAPICallerException = class(Exception);

  TBaseMobileAPICaller = class abstract(TObject)
  protected
  /// <summary>
  ///   Get the URI without a trailing backslash
  /// </summary>
    function getURI: string; virtual;
  end;

implementation

uses
  uD
  ;

{ TBaseMobileAPICaller }

function TBaseMobileAPICaller.getURI: string;
begin
  Result :=  ''; //d.roomerMainDataSet.RoomerUri.TrimEnd(['/']);
end;

end.
