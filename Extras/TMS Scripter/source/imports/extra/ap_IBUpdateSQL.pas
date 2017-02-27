unit ap_IBUpdateSQL;
{$DEFINE ENABLE_IMPORT}
{$WARN GARBAGE OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$WARN UNIT_PLATFORM OFF}
{$WARN UNIT_DEPRECATED OFF}
{$IFDEF ENABLE_IMPORT}
  {$IFDEF VER150}
    {$I ..\..\..\imports\delphi7\ap_IBUpdateSQL.pas}
  {$ELSE}
    {$IF CompilerVersion >= 24}
      {$LEGACYIFEND ON}
    {$IFEND}

    {$IF CompilerVersion >= 28}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 27}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 26}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 25}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 24}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 23}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 22}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 21}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 20}
      interface implementation end.
    {$ELSEIF CompilerVersion >= 18.5}
      interface implementation end.
    {$IFEND}
  {$ENDIF}
{$ELSE}
  interface implementation end.
{$ENDIF}
