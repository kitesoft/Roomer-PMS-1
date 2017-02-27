unit ap_Forms;
{$IFDEF MSWINDOWS}
  {$DEFINE ENABLE_IMPORT}
{$ENDIF}
{$WARN GARBAGE OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$WARN UNIT_PLATFORM OFF}
{$WARN UNIT_DEPRECATED OFF}
{$IFDEF ENABLE_IMPORT}
  {$IFDEF VER150}
    {$I ..\..\..\imports\delphi7\ap_Forms.pas}
  {$ELSE}
    {$IF CompilerVersion >= 24}
      {$LEGACYIFEND ON}
    {$IFEND}

    {$IF CompilerVersion >= 28}
      {$I ..\..\..\imports\delphixe7\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 27}
      {$I ..\..\..\imports\delphixe6\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 26}
      {$I ..\..\..\imports\delphixe5\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 25}
      {$I ..\..\..\imports\delphixe4\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 24}
      {$I ..\..\..\imports\delphixe3\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 23}
      {$I ..\..\..\imports\delphixe2\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 22}
      {$I ..\..\..\imports\delphi2011\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 21}
      {$I ..\..\..\imports\delphi2010\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 20}
      {$I ..\..\..\imports\delphi2009\ap_Forms.pas}
    {$ELSEIF CompilerVersion >= 18.5}
      {$I ..\..\..\imports\delphi2007\ap_Forms.pas}
    {$IFEND}
  {$ENDIF}
{$ELSE}
  interface implementation end.
{$ENDIF}
