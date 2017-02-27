unit uCallDLL;

{$I ascript.inc}

interface

{$IFDEF MSWINDOWS}

uses
  SysUtils, Windows
  {$IFDEF DELPHI6_LVL}
  , Variants
  {$ENDIF}
  ;

type
  TCallingConvention = (ccStdCall, ccRegister, ccPascal, ccCDecl, ccSafeCall);
  openarray = array of TVarRec;

function CallDllFunction(AFile, AFunction: string; AArgs, AArgTypes: openarray;
  AReturnType: integer=vtInteger; ACalling: TCallingConvention = ccStdCall): variant;

// AReturnType and each AArgTypes item must be one of:
// vtInteger    = 0;
// vtBoolean    = 1;
// vtChar       = 2;
// vtExtended   = 3;
// vtString     = 4;
// vtPointer    = 5;
// vtPChar      = 6;
// vtObject     = 7;
// vtClass      = 8;
// vtWideChar   = 9;
// vtPWideChar  = 10;
// vtAnsiString = 11;
// vtCurrency   = 12;
// vtVariant    = 13;
// vtInterface  = 14;
// vtWideString = 15;
// vtInt64      = 16;

{$ENDIF}

implementation

{$IFDEF MSWINDOWS}

uses
  atScript
{$IFDEF DLL_RTTI}
  ,TypInfo, Rtti
{$ENDIF}
  ;

function TypeConst(v: integer): string;
begin
  case v of
    0: result := 'vtInteger';
    1: result := 'vtBoolean';
    2: result := 'vtChar';
    3: result := 'vtExtended';
    4: result := 'vtString';
    5: result := 'vtPointer';
    6: result := 'vtPChar';
    7: result := 'vtObject';
    8: result := 'vtClass';
    9: result := 'vtWideChar';
    10: result := 'vtPWideChar';
    11: result := 'vtAnsiString';
    12: result := 'vtCurrency';
    13: result := 'vtVariant';
    14: result := 'vtInterface';
    15: result := 'vtWideString';
    16: result := 'vtInt64';
    {$IFDEF DELPHI2009_LVL}
    17: result := 'vtUnicodeString';
    {$ENDIF}
    else result := IntToStr(v);
  end;
end;

procedure splitDouble(d:double; var x, y: integer);
var li: array[1..2] of integer absolute d;
begin
  x := li[2];
  y := li[1];
end;

procedure splitExtended(e: extended; var x, y, z: integer);
var li: array[1..3] of integer absolute e;
begin
  x := li[3];
  y := li[2];
  z := li[1];
end;

procedure splitInt64(i64: Int64; var x, y: integer);
var li: array[1..2] of integer absolute i64;
begin
  x := li[2];
  y := li[1];
end;

procedure splitVariant(v: Variant; var x, y, z, k: integer);
var li: array[1..4] of integer absolute v;
begin
  x := li[4];
  y := li[3];
  z := li[2];
  k := li[1];
end;
 {$O-}

{$IFDEF DLL_RTTI}
function CallDllFunction(AFile, AFunction: string; AArgs, AArgTypes: openarray;
  AReturnType: integer; ACalling: TCallingConvention): variant;
var dll: THandle;
    proc: FARPROC;
    iarg: integer;
    arg: TVarRec;
    varg: TValue;
    parg: pointer;
    loaded: boolean;
    InArgs: TArray<TValue>;
    ReturnInfo: PTypeInfo;
    ReturnValue: TValue;
    CallConv: TCallConv;
begin
  { library load (if not loaded yet) }
  dll := GetModuleHandle(PChar(AFile));
  loaded := dll = 0;
  if loaded then
  begin
    dll := SafeLoadLibrary(PChar(AFile));
    if dll = 0 then
      raise exception.CreateFmt('Cannot load library %s', [AFile]);
  end;

  { procedure address }
  proc := GetProcAddress(dll, PChar(AFunction));
  if not assigned(proc) then
    raise exception.CreateFmt('Function %s not found in library %s', [AFunction, AFile]);

  { relation between values and argument types }
  if length(AArgs) <> length(AArgTypes) then
    raise exception.CreateFmt('%d argument values but %d types', [length(AArgs), length(AArgTypes)]);

  { build input arguments }
  SetLength(InArgs, Length(AArgs));
  for iarg := 0 to Length(AArgs) - 1 do
  begin
    { get argument value }
    arg := AArgs[iarg];
    varg := TValue.Empty;
    parg := nil;
    case AArgTypes[iArg].VInteger of
      vtInteger:    varg := TValue.From<integer>(arg.VInteger);
      vtBoolean:    varg := TValue.From<boolean>(arg.VBoolean);
      vtChar:       varg := TValue.From<AnsiChar>(arg.VChar);
      vtExtended:   varg := TValue.From<extended>(arg.VExtended^);
      vtString:     {p}varg := TValue.From<ShortString>(arg.VString^);
      vtPointer:    {p}varg := TValue.From<Pointer>(arg.VPointer);
      vtPChar:      {p}varg := TValue.From<PAnsiChar>(arg.VPChar);
      vtObject:     {p}varg := TValue.From<TObject>(arg.VObject);
      vtWideChar:   varg := TValue.From<WideChar>(arg.VWideChar);
      vtPWideChar:  {p}varg := TValue.From<PWideChar>(arg.VPWideChar);
      vtAnsiString: {p}varg := TValue.From<AnsiString>(AnsiString(arg.VAnsiString));
      vtCurrency:   {p}varg := TValue.From<Currency>(arg.VCurrency^);
      vtWideString: {p}varg := TValue.From<WideString>(WideString(arg.VWideString));
      vtVariant:    varg := TValue.From<Variant>(arg.VVariant^);
      vtClass:      varg := TValue.From<TClass>(arg.VClass);
      {$IFDEF DELPHI2009_LVL}
      vtUnicodeString: {p}varg := arg.VUnicodeString;
      {$ENDIF}
      vtInt64:      varg := TValue.From<Int64>(arg.VInt64^);

      vtLongint:    varg := TValue.From<Longint>(Ord(arg.VInteger));
      vtCardinal:   varg := TValue.From<Cardinal>(Ord(arg.VInteger));
      vtLongword:   varg := TValue.From<LongWord>(Ord(arg.VInteger));
      vtSingle:     varg := TValue.From<Single>(PSingle(arg.VInteger)^);
      vtByte:       varg := TValue.From<Byte>(Ord(arg.VChar));
      vtShortint:   varg := TValue.From<ShortInt>(Ord(arg.VChar));
      vtWord:       varg := TValue.From<Word>(Ord(arg.VWideChar));
      vtSmallint:   varg := TValue.From<SmallInt>(Ord(arg.VWideChar));
      vtDouble:     varg := TValue.From<Double>(PDouble(arg.VCurrency)^);
      vtReal:       varg := TValue.From<Real>(PReal(arg.VCurrency)^);
      vtDateTime:   varg := TValue.From<TDateTime>(PDouble(arg.VCurrency)^);
      vtComp:       varg := TValue.From<Comp>(PComp(arg.VCurrency)^);
    else
      raise exception.CreateFmt('Argument #%d value (%s) not supported', [iarg, TypeConst(AArgTypes[iArg].VInteger)]);
    end;
    InArgs[iarg] := varg;
  end;

  case ACalling of
    ccRegister:
      CallConv := TCallConv.ccReg;
    ccPascal:
      CallConv := TCallConv.ccPascal;
    ccCDecl:
      CallConv := TCallConv.ccCdecl;
    ccSafeCall:
      CallConv := TCallConv.ccSafeCall
  else
    CallConv := TCallConv.ccStdCall; // default
  end;

  { returning value }
  case AReturnType of
    vtBoolean:
      ReturnInfo := TypeInfo(boolean);
    vtChar:
      ReturnInfo := TypeInfo(AnsiChar);
    vtExtended:
      ReturnInfo := TypeInfo(extended);
    vtString:
      ReturnInfo := TypeInfo(ShortString);
    vtPointer:
      ReturnInfo := TypeInfo(Pointer);
    vtPChar:
      ReturnInfo := TypeInfo(PAnsiChar);
    vtObject:
      ReturnInfo := TypeInfo(TObject);
    vtClass:
      ReturnInfo := TypeInfo(TClass);
    vtWideChar:
      ReturnInfo := TypeInfo(WideChar);
    vtPWideChar:
      ReturnInfo := TypeInfo(PWideChar);
    vtAnsiString:
      ReturnInfo := TypeInfo(AnsiString);
    vtCurrency:
      ReturnInfo := TypeInfo(Currency);
    vtVariant:
      ReturnInfo := TypeInfo(Variant);
    vtWideString:
      ReturnInfo := TypeInfo(WideString);
    vtInt64:
      ReturnInfo := TypeInfo(Int64);
    vtSmallInt:
      ReturnInfo := TypeInfo(Smallint);
    vtLongint:
      ReturnInfo := TypeInfo(Longint);
    vtCardinal:
      ReturnInfo := TypeInfo(Cardinal);
    vtLongword:
      ReturnInfo := TypeInfo(Longword);
    vtSingle:
      ReturnInfo := TypeInfo(Single);
    vtByte:
      ReturnInfo := TypeInfo(Byte);
    vtShortint:
      ReturnInfo := TypeInfo(Shortint);
    vtWord:
      ReturnInfo := TypeInfo(Word);
    vtDouble:
      ReturnInfo := TypeInfo(Double);
    vtReal:
      ReturnInfo := TypeInfo(Real);
    vtDateTime:
      ReturnInfo := TypeInfo(TDateTime);
    vtComp:
      ReturnInfo := TypeInfo(Comp);
  else
    ReturnInfo := TypeInfo(integer);
  end;

  ReturnValue := Rtti.Invoke(proc, InArgs, CallConv, ReturnInfo);

  { returning value }
  case AReturnType of
    vtInteger:
      Result := ReturnValue.AsInteger;
    vtBoolean:
      Result := ReturnValue.AsBoolean;
    vtChar:
      Result := string(ReturnValue.AsType<AnsiChar>);
    vtExtended:
      Result := ReturnValue.AsExtended;
    vtString:
      Result := string(ReturnValue.AsType<ShortString>);
    vtPointer:
      Result := PointerToVar(ReturnValue.AsType<Pointer>);
    vtPChar:
      Result := string(ReturnValue.AsType<PChar>);
    vtObject:
      Result := ObjectToVar(ReturnValue.AsObject);
    vtClass:
      Result := PointerToVar(ReturnValue.AsClass);
    vtWideChar:
      Result := ReturnValue.AsType<WideChar>;
    vtPWideChar:
      Result := string(ReturnValue.AsType<PWideChar>);
    vtAnsiString:
      Result := ReturnValue.AsString;
    vtCurrency:
      Result := ReturnValue.AsCurrency;
    vtVariant:
      Result := ReturnValue.AsVariant;
    vtWideString:
      Result := ReturnValue.AsString;
    vtInt64:
      Result := ReturnValue.AsInt64;
    vtLongint:
      Result := ReturnValue.AsType<Longint>;
    vtCardinal:
      Result := ReturnValue.AsType<Cardinal>;
    vtLongword:
      Result := ReturnValue.AsType<Longword>;
    vtSingle:
      Result := ReturnValue.AsType<Single>;
    vtByte:
      Result := ReturnValue.AsType<Byte>;
    vtShortint:
      Result := ReturnValue.AsType<Shortint>;
    vtWord:
      Result := ReturnValue.AsType<Word>;
    vtSmallInt:
      Result := ReturnValue.AsType<SmallInt>;
    vtDouble:
      Result := ReturnValue.AsType<Double>;
    vtReal:
      Result := ReturnValue.AsType<Real>;
    vtDateTime:
      Result := ReturnValue.AsType<TDateTime>;
    vtComp:
      Result := ReturnValue.AsType<Comp>;
  else
    Result := ReturnValue.AsInteger;
  end;
end;

{$ELSE}
function CallDllFunction(AFile, AFunction: string; AArgs, AArgTypes: openarray;
  AReturnType: integer; ACalling: TCallingConvention): variant;
var dll: THandle;
    proc: FARPROC;
    iarg, next, argtype, argInt, x, y, z, k,
    eaxv, edxv, ecxv, stacksize, c, lastreg: integer;
    argFlt: extended;
    argDbl: double;
    arg: TVarRec;
    varg: variant;
    parg: pointer;
    loaded: boolean;
    vresult: variant;
    sresult: AnsiString;
    wresult: widestring;
    {$IFDEF DELPHI2009_LVL}
    uresult: UnicodeString;
    {$ENDIF}

  procedure RegArg(var X);
  begin
    case lastreg of
      0: eaxv := integer(X);
      1: edxv := integer(X);
      2: ecxv := integer(X);
    end;
    inc(lastreg);
  end;

begin

// Directive	Parameter order	Clean-up Passes parameters in registers?
// register	Left-to-right	Routine	 Yes
// pascal	Left-to-right	Routine	 No
// cdecl	Right-to-left	Caller	 No
// stdcall	Right-to-left	Routine	 No
// safecall	Right-to-left	Routine	 No

  { library load (if not loaded yet) }
  dll := GetModuleHandle(PChar(AFile));
  loaded := dll = 0;
  if loaded then
  begin
    dll := SafeLoadLibrary(PChar(AFile));
    if dll = 0 then
      raise exception.CreateFmt('Cannot load library %s', [AFile]);
  end;

  { procedure address }
  proc := GetProcAddress(dll, PChar(AFunction));
  if not assigned(proc) then
    raise exception.CreateFmt('Function %s not found in library %s', [AFunction, AFile]);

  { relation between values and argument types }
  if length(AArgs) <> length(AArgTypes) then
    raise exception.CreateFmt('%d argument values but %d types', [length(AArgs), length(AArgTypes)]);

  if ACalling in [ccRegister, ccPascal] then { left => right }
  begin

    { For a string, dynamic array, method pointer, or Variant result,
      the effects are the same as if the function result were declared as an additional var parameter
      following the declared parameters.
      In other words, the caller passes an additional 32-bit pointer that points to a variable in which to return the function result. }
    if AReturnType in [vtAnsiString, vtVariant,
      {$IFDEF DELPHI2009_LVL}
      vtUnicodeString,
      {$ENDIF}
      vtWideString] then
    begin
      SetLength(AArgs,Length(AArgs)+1);
      SetLength(AArgTypes,Length(AArgTypes)+1);
      AArgs[ High(AArgs) ].VType := vtPointer;
      AArgTypes[ High(AArgTypes) ].VInteger := vtPointer;
      case AReturnType of
        vtAnsiString: AArgs[ High(AArgs) ].VPointer := @sresult;
        vtVariant: AArgs[ High(AArgs) ].VPointer := @vresult;
        vtWideString: AArgs[ High(AArgs) ].VPointer := @wresult;
        {$IFDEF DELPHI2009_LVL}
        vtUnicodeString: AArgs[ High(AArgs) ].VPointer := @uresult;
        {$ENDIF}
      end;
    end;

    next := 1;
    iarg := low(AArgs);
  end
  else { right => left }
  begin

    { For a string, dynamic array, method pointer, or Variant result,
      the effects are the same as if the function result were declared as an additional var parameter
      following the declared parameters.
      In other words, the caller passes an additional 32-bit pointer that points to a variable in which to return the function result. }
    if AReturnType in [vtAnsiString, vtVariant,
      {$IFDEF DELPHI2009_LVL}
      vtUnicodeString,
      {$ENDIF}
      vtWideString] then
    begin
      SetLength(AArgs,Length(AArgs)+1);
      SetLength(AArgTypes,Length(AArgTypes)+1);
      for c:=Length(AArgs)-2 downto 0 do
      begin
        AArgs[c+1] := AArgs[c];
        AArgTypes[c+1] := AArgTypes[c];
      end;
      AArgs[ 0 ].VType := vtPointer;
      AArgTypes[ 0 ].VInteger := vtPointer;
      case AReturnType of
        vtAnsiString: AArgs[ 0 ].VPointer := @sresult;
        vtVariant: AArgs[ 0 ].VPointer := @vresult;
        vtWideString: AArgs[ 0 ].VPointer := @wresult;
        {$IFDEF DELPHI2009_LVL}
        vtUnicodeString: AArgs[ 0 ].VPointer := @uresult;
        {$ENDIF}
      end;
    end;

    iarg := high(AArgs);
    next := -1;
  end;

  { push arguments on stack }
  stacksize := 0;
  lastreg := 0;
  while (iarg >= low(AArgs)) and (iarg <= high(AArgs)) do
  begin
    { get argument value }
    arg := AArgs[iarg];
    varg := NULL;
    parg := nil;                               
    case arg.VType of
      vtInteger:    varg := arg.VInteger;
      vtBoolean:    varg := integer(arg.VBoolean);
      vtChar:       varg := integer(arg.VChar);
      vtExtended:   varg := arg.VExtended^;
      vtString:     parg := arg.VString;
      vtPointer:    parg := arg.VPointer;
      vtPChar:      parg := arg.VPChar;
      vtObject:     parg := pointer(arg.VObject);
      vtWideChar:   varg := arg.VWideChar;
      vtPWideChar:  parg := arg.VPWideChar;
      vtAnsiString: parg := arg.VAnsiString;
      vtCurrency:   parg := arg.VCurrency;
      vtWideString: parg := arg.VWideString;
      vtVariant:    varg := arg.VVariant^;
      vtClass:      varg := integer(arg.VClass);
      {$IFDEF DELPHI2009_LVL}
      vtUnicodeString: parg := arg.VUnicodeString;
      {$ENDIF}
      vtInt64:      {use arg.VInt64^};
      else
        raise exception.CreateFmt('Argument #%d value (%s) not supported', [iarg, TypeConst(arg.VType)]);
    end;

    { argument type }
    argtype := AArgTypes[iarg].VInteger;

    if (ACalling = ccRegister) and (lastreg < 3) then { values on registers (at most 3) }
    begin
      case argtype of
        vtInteger, vtBoolean, vtChar, vtClass, vtWideChar:
          begin
            argInt := varg;
            RegArg(argInt);
          end;
        vtExtended:
          begin
            { always push extended arguments on stack }
            splitExtended(varg, x, y, z);
            asm
              push x
              push y
              push z
            end;
          end;
        vtCurrency:
          begin
            { always push currency/double arguments on stack }
            splitDouble(PDouble(parg)^, x, y);
            asm
              push x
              push y
            end;
          end;
        vtString, vtAnsiString, vtWideString, vtPointer, vtObject, vtPChar,
        {$IFDEF DELPHI2009_LVL}
        vtUnicodeString,
        {$ENDIF}
        vtPWideChar:
          RegArg(parg);
        vtInt64:
          begin
            { always push int64 arguments on stack }
            splitInt64(arg.VInt64^, x, y);
            asm
              push x
              push y
            end;
          end;
        else if argtype > 0 then
          raise exception.CreateFmt('Argument #%d type (%s) not supported', [iarg, TypeConst(argtype)]);
      end;
    end
    else { stack arguments }
    begin
      case argtype of
        vtInteger, vtBoolean, vtChar, vtClass, vtWideChar:
          begin
            argInt := varg;
            asm
              push argInt
            end;
            inc(stacksize);
          end;
        vtExtended:
          begin
            splitExtended(varg, x, y, z);
            asm
              push x
              push y
              push z
            end;
            inc(stacksize, 3);
          end;
        vtCurrency:
          begin
            splitDouble(PDouble(parg)^, x, y);
            asm
              push x
              push y
            end;
            inc(stacksize, 2);
          end;
        vtString, vtAnsiString, vtWideString, vtPointer, vtObject, vtPChar,
        {$IFDEF DELPHI2009_LVL}
        vtUnicodeString,
        {$ENDIF}
        vtPWideChar:
          begin
            asm
              push parg
            end;
            inc(stacksize);
          end;
        vtInt64:
          begin
            splitInt64(arg.VInt64^, x, y);
            asm
              push x
              push y
            end;
            inc(stacksize, 2);
          end;
        vtVariant:
          begin
            splitVariant(varg, x, y, z, k);
            asm
              push x
              push y
              push z
              push k
            end;                          // system.pas tvardata
            inc(stacksize, 4);
          end;

        else
          if argtype > 0 then
            raise exception.CreateFmt('Argument #%d type (%s) not supported', [iarg, TypeConst(argtype)]);
      end;

    end;

    inc(iarg, next);
  end;

  { register values }
  if ACalling = ccRegister then
  asm
    mov eax, eaxv
    mov edx, edxv
    mov ecx, ecxv
  end;

  { procedure call }
  asm
    call proc
    mov argInt, eax
    mov parg, eax
  end;

  { returning value }
  case AReturnType of
    vtExtended:                  
      begin
        asm
          fstp tbyte ptr [argFlt]
        end;
        result := argFlt;
      end;

    vtCurrency:
      begin
        asm
          fstp qword ptr [argDbl]
        end;
        result := argDbl;
      end;

    {$IFNDEF DELPHI2009_LVL}
    vtPChar, vtPWideChar:
      result := string(PChar(parg));
    {$ELSE}
    vtPChar:
      result := AnsiString(PAnsiChar(parg));
    vtPWideChar:
      result := string(PChar(parg));
    {$ENDIF}

    vtWideChar, vtChar:
      result := char(argInt);

    vtString, vtAnsiString:
      result := sresult;

    vtWideString:
      result := wresult;

    {$IFDEF DELPHI2009_LVL}
    vtUnicodeString:
      result := uresult;
    {$ENDIF}

    vtVariant:
      result := vresult;
    vtLongint:
      result := argInt;
    vtCardinal:
      result := argInt;
    vtLongword:
      result := argInt;
    vtByte:
      result := argInt;
    vtShortint:
      result := argInt;
    vtWord:
      result := argInt;
    vtSmallint:
      result := argInt;
    vtSingle,
    vtDouble,
    vtReal,
    vtDateTime,
    vtComp:
      begin
        asm
          fstp qword ptr [argDbl]
        end;
        result := argDbl;
      end;
    else
      result := argInt;
  end;

  { cdecl: clear stack after call }
  if ACalling = ccCDecl then
    for iarg := 0 to stacksize do
    asm
      pop eax
    end;
end;
{$ENDIF}

{$ENDIF} {MSWINDOWS}

end.

