unit uCurrencyConstants;

interface

uses
  SysUtils
  ;

type

  TCurrencyCode = string[3];

  /// <summary>
  ///   Base Excepton for everything that goes wrong when dealing with currencies
  /// </summary>
  ECurrencyException = class(Exception);



implementation

end.
