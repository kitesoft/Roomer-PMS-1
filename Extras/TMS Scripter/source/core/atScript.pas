{***************************************************************************}
{ TMS Scripter Components for Delphi & C++Builder                           }
{ Version 6.5.2.1                                                           }
{                                                                           }
{ written by TMS Software                                                   }
{            copyright � 1997 - 2014                                        }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{                                                                           }
{ For information about version history, check the section "What's New"     }
{ at TMS Scripter manual.                                                   }
{                                                                           }
{ The source code is given as is. The author is not responsible             }
{ for any possible damage done due to the use of this code.                 }
{ The component can be freely used in any application. The complete         }
{ source code remains property of the author and may not be distributed,    }
{ published, given or sold in any form as such. No parts of the source      }
{ code can be included in any other component or application without        }
{ written authorization of the author.                                      }
{***************************************************************************}

{$DEFINE CODE_OPTIMIZATION}
unit atScript;

{$I ASCRIPT.INC}

interface

uses
  Types, SysUtils, Classes, atParser,
  {$IFDEF NEXTGEN}
  Generics.Defaults,
  Generics.Collections,
  {$ELSE}
  Contnrs,
  {$ENDIF}
  TypInfo, Math
  {$IFDEF DELPHI6_LVL}
  , Variants
  {$ENDIF}
  {$IFDEF DELPHI2010_LVL}
  , Rtti
  {$ENDIF}
  ;

{$WARNINGS OFF}

type
  {Internal structure}
  TInstruction = (
    inPrepare,            // Allocate space in stack for local variables
    inPushInteger, // Push an integer in stack
    inPushDouble, // Push a double in stack
    inPushString, // Push a string in stack
    inPushConst, // Push a Null variant in stack
    inPushOutput, // Push the output result of a function in the stack
    inPushClass, // Push a class reference in stack
    inDuplicate, // // obsolete
    inDuplicate2, // // obsolete
    inDrop2, // // obsolete
    inSwap2, // // obsolete
    inOperNE, // Remove 2 values from stack, test if they are not equal, push the result in stack
    inOperGE, // Remove 2 values from stack, test if first is greater or equal to second, push the result in stack
    inOperLE, // Remove 2 values from stack, test if first is less or equal to second, push the result in stack
    inOperEqual,          // Remove 2 values from stack, test if first is equal to second, push the result in stack
    inOperGreater,        // Remove 2 values from stack, test if first is greater than second, push the result in stack
    inOperLess,           // Remove 2 values from stack, test if first is less than second, push the result in stack
    inOperAdd, // Remove 2 values from stack, add them and push the result in stack
    inOperConcat, // Remove 2 values from stack, concatenate them and push the result in stack
    inOperSub,            // Remove 2 values from stack, subtract the second from the first and push the result in stack
    inOperOr, // Remove 2 values from stack, perform the logic OR operation and push the result in stack
    inOperXor,            // Remove 2 values from stack, perform the logic XOR operation and push the result in stack
    inOperMul,            // Remove 2 values from stack, multiply the first by the second and push the result in stack
    inOperSlash,          // Remove 2 values from stack, divide the first by the second and push the result in stack with "/"
    inOperDiv,            // Remove 2 values from stack, divide the first by the second and push the result in stack as integer
    inOperMod,            // Remove 2 values from stack, divide the first by the second and push the rest as the result
    inOperAnd,            // Remove 2 values from stack, perform the logic AND operation and push the result in stack
    inOperShl,            // Remove 2 values from stack, perform the logic SHL operation and push the result in stack
    inOperShr,            // Remove 2 values from stack, perform the logic SHR operation and push the result in stack
    inOperExp,            // Remove 2 values from stack, raise the first to the power of the second and push the result in stack
    inOperIs, // Remove 2 values from stack, test if the class of the first corresponds or is derivated from the second, return the logic result of the test
    inOperNeg, // Complement the sign of the value in top of stack
    inOperNot, // Complement the value in top of stack using the logic NOT operation
    inJumpIfFalse, // Remove the value in top of stack and jump if it is zero
    inJumpIfTrue, // Remove the value in top of stack and jump if it is not zero
    inJump, // Jump unconditionally with no return
    inStoreVar, // Remove the value in top of stack and store it in the variable
    inStoreVarRef,        // Remove the value in top of stack and store it in the variable passed by reference
    inStoreIdxVar, // Remove the value in top of stack and store it in the variable
    inStoreIdxVarRef,     // Remove the value in top of stack and store it in the variable passed by reference
    inStoreVarInteger, // Store an integer parameter directly into the variable
    inStoreVarRefInteger, // Store an integer parameter directly into the variable passed by reference
    inStoreVarDouble, // Store a numeric (non integer) parameter directly into the variable
    inStoreVarRefDouble,  // Store a numeric (non integer) parameter directly into the variable passed by reference
    inStoreVarString, // Store a string parameter directly into the variable
    inStoreVarRefString, // Store a string parameter directly into the variable passed by reference
    inStoreVarConst, // Store a constant directly into the variable
    inStoreVarRefConst, // Store a constant directly into the variable passed by reference
    inCopyVar, // Copy the content of one variable to another without using the stack
    inCopyVarRef,         // Copy the content of one variable to another passed by reference without using the stack
    inStoreInput, // Store a subroutine input argument in a variable
    inPushVar, // Stack the content of a local variable
    inPushIdxVar, // Stack the content of a local indexed variable
    inPushVarByRef, // Stack a reference to a local variable
    inVarTest,            // Compare the value of the variable to the expression in the top of the stack, and jump to vInteger according to vByte
    inVarTestInteger,     // Compare the value of the variable to the integer parameter, and jump to vInteger according to vByte
    inVarTestDouble,      // Compare the value of the variable to the numeric (non integer) parameter, and jump to vInteger according to vByte
    inVarTestString,      // Compare the value of the variable to the string parameter, and jump to vInteger according to vByte
    inVarTestVar,         // Compare the value of the variable to the value of other variable, and jump to vInteger according to vByte
    inStoreGlobalVar, // Remove the value in top of stack and store it in the global variable
    inStoreGlobalIdxVar, // Remove the value in top of stack and store it in the global variable
    inPushGlobalVar, // Stack the content of a global variable
    inPushGlobalIdxVar, // Stack the content of a global indexed variable
    inPushGlobalVarByRef, // Stack a reference to the global variable
    inCall, // Jump to internal subroutine
    inRet, // Return from subroutine/end of try..except block. vInteger = 0 (ret); vInteger = 1 (try..execept)
    inExecFun, // Execute an external function
    inCallProc, // Execute a special procedure call
    inTryFinally, // Execute a code block protected with guaranteed conclusion
    inTryExcept, // Execute a code block protected with exception handling
    inCallClassProc, // Execute a procedure call to a class member (method or property)
    inBreakPoint, // Entry point to all debugger funcionalities
    inAbort, // Create a silent execution
    inArrayOf, // Create an array of variants with values in stack
    inCastClass, // Forces the object in stack to the class defined in instruction
    inWithObject,         // Adjust the instance to be used by the next CallProc instruction (With expression)
    inGlobalPrepare, // Allocate space in stack to global variables
    inTestIfFalse, // Jump if current stack is false, without removing value from stack
    inTestIfTrue, // Jump if current stack is true, without removing value from stack
    inSaveStackValue, // Pop the current stack value and save it in a secondary stack
    inLoadStackValue // Push back the stack value previously saved with inSaveStackValue

    );

const
  StackSize = 3000; // runtime stack size
  TempStackSize = 50;
  CODEFILE_VERSION = 4; // current scripter version
  CURRENT_VERSION = 4; // current scripter version

  DefaultTypeInfoFilter = [TTypeKind(tkInteger), TTypeKind(tkChar), TTypeKind(tkEnumeration),
    TTypeKind(tkFloat), TTypeKind(tkString), TTypeKind(tkSet), TTypeKind(tkClass),
    TTypeKind(tkWChar), TTypeKind(tkLString), TTypeKind(tkWString), TTypeKind(tkVariant),
  {$IFDEF DELPHI2009_LVL}
  TTypeKind(tkUString),
  {$ENDIF}
  TTypeKind(tkArray),
  TTypeKind(tkInt64)
  ];

type
  PInteger = ^integer;
  PBoolean = ^boolean;
  PPointer = ^pointer;
  PPChar = ^PChar;
  {$IFDEF DELPHIXE2_LVL}
  IntObject = NativeInt;
  {$ELSE}
  IntObject = integer;
  {$ENDIF}
  { Internal structure }
  TGenericProc = procedure of object;

  {$IFDEF NEWSTACK}
  TScriptValue = TValue;
  PScriptValue = ^TScriptValue;

  TStackValue = record
  strict private
    FValue: TValue;
  public
    class operator Implicit(const Value: TScriptValue): TStackValue;
    class operator Implicit(const Value: TStackValue): TScriptValue;
    property RawValue: TValue read FValue write FValue;
  end;
  PStackValue = ^TStackValue;
  {$ELSE}
  TScriptValue = Variant;
  PScriptValue = ^TScriptValue;
  TStackValue = Variant;
  PStackValue = ^TStackValue;
  {$ENDIF}

  ///  <summary>
  ///  This is the type of user-defined procedure.
  ///  Input param can contain one or more variant values. Results must be put in Output parameter.
  ///  </summary>
  TBuiltInProc = procedure(Input: Variant; var Output: Variant) of object;

  { Internal structure }
  pSimplifiedCode = ^TSimplifiedCode;

  // elements order and zise must be keeped
  // this structure was fixed on 48 bytes size
  // BE CAREFUL: when changing this structure, keep record size
  // a multiple of 8, to keep alignment in the variant part of the record

  ///  <summary>
  ///  TSimplifiedCode is the atomic structure for a virtual machine pseudo-code. In other words,
  ///  a compiled code is a list of TSimplified code records.
  ///  </summary>
  TSimplifiedCode = record
    OpCode      : TInstruction;    // instruction op-code 1 byte
    vByte       : byte;            // first byte parameter 1 byte
    vSmallInt   : smallint;        // first smallint parameter 2 bytes
    vInteger    : integer;         // first integer parameter 4 bytes
    vInteger1   : integer;         // second integer parameter 4 bytes
    vString     : string;          // string parameter: element name 4 bytes
    vDebugInfo  : integer;         // debug information: source code position 4 bytes
    Next        : pSimplifiedCode; // Next instruction pointer 4 bytes
    Compute     : TGenericProc;    // instruction method pointer 8 bytes
    vString2    : string;          // string parameter: second element name 4 bytes
    Dummy       : integer;         // add unused 4 bytes in the record to keep record size a multiple of 8
    {$IFDEF NEWSTACK}
    vObj: TObject;
    vInst: pSimplifiedCode;
    vInst2: pSimplifiedCode;
    {$ELSE}
    vPointer    : IntObject;
    vPointer2   : IntObject;       // 2 adicional pointers. 8 bytes on 32-bit, 16 bytes on 64-bit
    {$ENDIF}

    {$IFDEF NEXTGEN}
    vProc: TGenericProc;
    {$ENDIF}
    // Extra parameters
    case byte of
      0: ( vDouble:double );               // 1 double parameter - 8 bytes
      {$IFNDEF NEXTGEN}
      1: ( vProc:TGenericProc );           // 1 method parameter - 8 bytes - 16 bytes in 64-bit
      {$ENDIF}
      2: ( vInteger2,vInteger3:integer );  // 2 adicional integer parameters - 8 bytes.
      3: ( vSave1, vSave2: IntObject );    // parameters for saving this part of record. Must be IntObject to save vProc data correctly
      {$IFDEF DELPHI6_LVL}
      4: ( vInt64: Int64 );                // Int64 value (8 bytes)
      {$ELSE}
      4: ( vInt64: Integer );              // Delphi 5 doesn't support Int64 in Variants.
    {$ENDIF}
  end;

  ///  <summary>
  ///  Open arrays.
  ///  </summary>
  intarray = array of integer;
  // openarray = array of TVarRec;

  ///  <summary>
  ///  Internal structure.
  ///  </summary>
  TSingleStepProc = procedure(p: pSimplifiedCode) of object;

  ///  <summary>
  ///  Internal structure.
  ///  </summary>
  TStackType = (
    stPendingOperators, // stack of pending operators (unstacking follows an order of precedence)
    stIdentifierList, // stack of identifiers of procedures and local variables
    stContext, // generic context stack for IF, FOR, WHILE, REPEAT and ARG_LIST
    stTempVariables );  // stack of local context temporary variables (ex.: for context of structures like With)

  ///  <summary>
  ///  Internal structure.
  ///  </summary>
  pStackElement = ^TStackElement;

  ///  <summary>
  ///  Internal structure.
  ///  </summary>
  TStackElement = record
    Previous: pStackElement;
    Element: TScriptValue;
    Index: integer;
  end;

  ///  <summary>
  ///  Internal structure.
  ///  </summary>
  pAddress = ^TAddress;

  TAddress = record
    Address: IntObject; // Line number that references label
    Code: pSimplifiedCode; // Pointer to instruction
    Next: pAddress; // Pointer to the next label reference
  end;

  ///  <summary>
  ///  Internal structure.
  ///  </summary>
  pLabelSpec = ^TLabelSpec;

  ///  <summary>
  ///  Internal structure.
  ///  </summary>
  TLabelSpec = record
    Name: string; // label name
    Address: IntObject; // line number where label was defined
    FirstRef: pAddress; // pointer to the first label reference
    LastRef: pAddress; // pointer to the last label reference
    Next: pLabelSpec; // pointer to the next label
  end;

  { SIMPLIFIED CODE FILE STRUCTURE }
  { <TCodeFileHeader> }
  { TCodeFileHeader.ImplicitRefCount * <TImplicitClassRef> }
  { N * <TInstructionDescriptor> }

  ///  <summary>
  ///  atPascal simplified code file implicit class reference.
  ///  </summary>
  TImplicitClassRef = record
    ClassIndex: integer; // relative to TatClasses instance
    ElementIndex: integer; // relative to TatMethods or TatProperties
    ElementIsMethod: boolean; // true if element is a method, false if element is a property
    ClassNameSize: integer;
    ElementNameSize: integer;
    ElementClassIndex: integer;
    ElementClassNameSize: integer;
  end;

  TUsedUnitRec = record
    UnitNameSize: integer;
    IsDefault: boolean;
    IsScript: boolean;
    DeclSourcePos: integer;
  end;

  ///  <summary>
  ///  atPascal simplified code file header.
  ///  </summary>
  TCodeFileHeader = record
    Signature: array [0 .. 24] of char; // Signature: 'atPascal Executable File'#26
    Version: byte; // Version byte identifier
    ImplicitRefCount: integer; // Implicit class referencing collection size
    UsedUnitCount: integer; // Number of used units in source code
    ScriptInfoSize: integer;
    Reserved: array [0 .. 27] of byte; // for future use (always 0)
  end;

  ///  <summary>
  ///  atPascal simplified instruction when saved to file.
  ///  </summary>
  TInstructionDetails = record
    OpCode: byte;
    vByte: byte;
    vSmallInt: smallint;
    vDebugInfo: integer;
    vInteger: integer;
    vInteger1: integer;
    vSave1: IntObject;
    vSave2: IntObject;
    { * vString : string * }
  end;

  ///  <summary>
  ///  Descriptor for instructions when saved to file.
  ///  </summary>
  TInstructionDescriptor = record
    Size: integer;
    Size2: integer;
    Details: TInstructionDetails;
  end;

  ///  <summary>
  ///  Internal structure.
  ///  </summary>
  TDataOperation = (
    doRead,     // leitura de dado
    doWrite, // escrita de dado
    doExec, // execução de código
    doAddr  );  // endereçamento de código

  ///  <summary>
  ///  Class reference types.
  ///  </summary>
  TClassReference = (crNone, crGetter, crSetter, crMethod);

  ///  <summary>
  ///  EatScripterRuntime is raised when a runtime error occurs in script.
  ///  </summary>
  EatScripterRuntime = class(Exception);
  ///  <summary>
  ///  EatRuntimeError is raised when a runtime error occurs in script.
  ///  </summary>
  EatRuntimeError = class(Exception);
  ///  <summary>
  ///  EatCompileError is raised when a compile error occurs during script compilation.
  ///  </summary>
  EatCompileError = class(Exception);
  ///  <summary>
  ///  Exception raised from the scripter component.
  ///  </summary>
  EatInternalError = class(Exception);
  ///  <summary>
  ///  Exception raised from the scripter component.
  ///  </summary>
  EatScriptInfoError = class(Exception);
  ///  <summary>
  ///  Exception raised from the scripter component.
  ///  </summary>
  EatDefinitionError = class(Exception);
  ///  <summary>
  ///  Exception raised from the scripter component.
  ///  </summary>
  EatScripterFatal = class(Exception);
  ///  <summary>
  ///  Exception raised from the scripter component.
  ///  </summary>
  EatScripterDebug = class(Exception);

  pAddrVector = ^TAddrVector;
  TAddrVector = array[0..0] of pSimplifiedCode;

  CORE_CONST = (coTrue, coFalse, coNull, coUnassigned, coNil);

  TatCallingConvention = (ccStdCall, ccRegister, ccPascal, ccCDecl, ccSafeCall);
  PReal = ^Real;
  {$WARNINGS OFF}
  PComp = ^Comp;
  {$WARNINGS ON}

const
  { tipos de dados adicionais (continuando a partir dos tipos declarados no System.pas }
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
  vtLongint = 0100; { =0 }
  vtCardinal = 0200; { =0 }
  vtLongword = 0300; { =0 }
  vtSingle = 0400; { =0 }
  vtByte = 0502; { =2 }
  vtShortint = 0602; { =2 }
  vtWord = 0709; { =9 }
  vtSmallint = 0809; { =9 }
  vtDouble = 0912; { =12 }
  vtReal = 1012; { =12 }
  vtDateTime = 1112; { =12 }
  vtComp = 1212; { =12 }

type
  TatCustomScripter = class;
  TatClasses = class;
  TatClass = class;
  TatObjects = class;
  TatObject = class;
  TatProperties = class;
  TatProperty = class;
  TatMethods = class;
  TatMethod = class;
  TatDataDefs = class;
  TatDataDef = class;
  TatClassRefs = class;
  TatClassRef = class;
  TatUsedUnits = class;
  TatUsedUnit = class;
  TatScriptInfo = class;
  TatRoutinesInfo = class;
  TatRoutineInfo = class;
  TatVariablesInfo = class;
  TatVariableInfo = class;
  TatScriptBreakPoints = class;
  TatScriptBreakPoint = class;
  TatScripts = class;
  TatScript = class;
  TatVirtualMachines = class;
  TatVirtualMachine = class;
  TatDebugWatch = class;
  TatDebugWatches = class;
  TatScripterWatch = class;
  TatScripterWatches = class;

  IScriptBasedObject = interface
    function GetRunScript: TatScript;
  end;


  TScriptBaseObject = class;
  TScriptBaseObjectClass = class of TScriptBaseObject;

  ///  <summary>
  ///  For event support.
  ///  </summary>
  TatScripterEventBroker = class;
  TatEventAdapters = class;
  TatEventAdapter = class;
  TatEventDispatchers = class;
  TatEventDispatcher = class;
  TatDispatcherRemoveNotificator = class;
  TDispatcherClass = class of TatEventDispatcher;

  ///  <remarks>
  ///  Specifies how a event handler set from script will replace a previously set event handler for the object event.
  ///  epReplaceCall: replaces the event handler (previous event handler is not called)
  ///  epTopCall: executes the new event handler, then calls the previous event handler
  ///  etBottomCall: calls the previous event handler, then execute the new event handler}
  ///  </remarks>
  TatEventPlacement = (epReplaceCall, epTopCall, epBottomCall);

  ///  <remarks>
  ///  Specifies how a event handler set from script will replace a previously set event handler for the object event.
  ///  esReplaceEvent: replaces the event handler (previous event handler is not called)
  ///  esAddEventOnTop: executes the new event handler, then calls the previous event handler
  ///  esAddEventOnBottom: calls the previous event handler, then execute the new event handler}
  ///  </remarks>
  TEventSetMode = (esReplaceEvent, esAddEventOnTop, esAddEventOnBottom);

  ///  <remarks>
  ///  Specifies what happens when a event handler set from script is then removed. For example, when caling UnsetEvent or
  ///  when calling from script MyButton.OnClick := '';
  ///  euReplaceNil: event handler will be empty script routine
  ///  euOriginalEvent: event handler will be the original Delphi event
  ///  euClearEvent: event handler will be set to nil pointer
  ///  euPreviousEvent: the previously set event handler will be used
  ///  </remarks>
  TEventUnsetMode = (euReplaceNil, euOriginalEvent, euClearEvent, euPreviousEvent);

  TExecuteEventProc = procedure(AEventDispatcher: TatEventDispatcher; var AExecute: boolean)
    of object;
  TSettingEventProc = procedure(Sender: TObject; AInstance: TObject; APropName: string;
    ARoutineName: string; AScripter: TatCustomScripter; APlacement: TatEventPlacement;
    var AProcede: boolean) of object;
  TSetEventProc = procedure(AEventDispatcher: TatEventDispatcher) of object;
  TUnsetEventProc = procedure(AEventDispatcher: TatEventDispatcher; var AProcede: boolean)
    of object;
  TTranslateMethodGetterProc = procedure(AMachine: TatVirtualMachine; AInstance: TObject;
    APropInfo: PPropInfo; var AValue: TScriptValue) of object;
  TTranslateMethodSetterProc = procedure(AMachine: TatVirtualMachine; AInstance: TObject;
    APropInfo: PPropInfo; AValue: TScriptValue) of object;

  TScriptClass = class of TatScript;
  TMachineClass = class of TatVirtualMachine;
  TatScripterLibraryClass = class of TatScripterLibrary;
  TatScripterLibrary = class;

  ///  <summary>
  ///  Argument modifiers for use in atPascal class methods.
  ///  </summary>
  TatArgumentModifier = (moNone, moConst, moVar);

  ///  <summary>
  ///  Specifies which argument modifiers applies to a param.
  ///  </summary>
  TatArgumentModifiers = set of TatArgumentModifier;

  ///  <remarks>
  ///  TScriptErrorEvent event is called when an error occurs in script. The error message is provided in msg
  ///  parameter, and you can change it from here. Row and col parameters contain the position in the source code where
  ///  the error occured. ShowException is true by default. If it is true, an EatScriptRuntime (or EatCompileError) exception will be raised
  ///  with the message specified by msg. If ShowException is false, an Abort exception will raised.
  ///  </remarks>
  TScriptErrorEvent = procedure(Sender: TObject; var msg: string; row, col: integer;
    var ShowException: boolean) of object;

  ///  <summary>
  ///  TBeforeExecuteEvent is called before a script routine (or main block) is executed. ALabel contains the name of the
  ///  routine to be executed. If the main block is to be executed, ALabel is an empty string.
  ///  </summary>
  TBeforeExecuteEvent = procedure(AMachine: TatVirtualMachine; ALabel: string) of object;

  ///  <summary>
  ///  TMachineProc is a multi-purpose event mostly used when a script compiled p-code is being executed by the virtual machine.
  ///  The machine executing the code is passed in AMachine parameter.
  ///  </summary>
  TMachineProc = procedure(AMachine: TatVirtualMachine) of object;

  ///  <summary>
  ///  Type kinds for use in atPascal classes.
  ///  </summary>
  TatTypeKind = (tkNone, tkInteger, tkChar, tkEnumeration, tkFloat, tkString, tkSet, tkClass,
    tkMethod, tkWChar, tkLString, tkWString, tkVariant, tkArray, tkRecord, tkInterface, tkInt64,
    tkDynArray
    {$IFDEF DELPHI2009_LVL}
    , tkUString
    {$ENDIF} ); // from TypInfo

  /// Description:
  /// TWatchStatus holds the possible status for a specified scripter watch.
  /// wsNotEvaluated - The watch value was not yet computed
  /// wsEvaluated - The watch value was computed and is available in LastResult property
  /// wsCompileError - The expression caused a compile error during evaluation
  /// wsRuntimeError - The expression caused a runtime error during evaluation
  /// wsProcessNotAvailable - The script is not running so the watch cannot be evaluated
  /// See Also:
  /// TatScripterWatch.WatchStatus
  TWatchStatus = (wsNotEvaluated, wsEvaluated, wsCompileError, wsRuntimeError,
    wsProcessNotAvailable);

  {$IFDEF DELPHI2010_LVL}
  TMemberVisibilitySet = set of TMemberVisibility;
  TRedefineOption = (roNone, roInclude, roOverwrite);
  {$ENDIF}

  ///  <summary>
  ///  TScripterLibraryOptions holds some environment/running options for the scripts being compiled/executed.
  ///  It contains info like search path, default file extension, and some other available options.
  ///  </summary>
  TScripterLibraryOptions = class(TPersistent)
  private
    FUseScriptFiles: boolean;
    FCompiledFileExt: string;
    FSourceFileExt: string;
    FFormFileExt: string;
    FSearchPath: TStrings;
    procedure SetSearchPath(const Value: TStrings);
  public
    constructor Create;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    ///  <remarks>
    ///  SearchPath holds a list of valid directory names to be used as search paths for script compilation/execution.
    ///  Whenever the compiler (or virtual machine) finds a reference to a file and needs to find one, it will search
    ///  in the list of search paths. The order is important, it will try to find the file in the first path in the list,
    ///  if not found, the second path is used, an so on. You can the following macros in path.
    ///  <code>
    ///  $(CURDIR): Contains the current directory
    ///  $(APPDIR): Contains the application (.exe) directory
    ///  </code>
    ///  </remarks>
    ///  <example>
    ///  $(CURDIR)\MyPath}
    ///  </example>
    property SearchPath: TStrings read FSearchPath write SetSearchPath;

    ///  <remarks>
    ///  Contains the default extension for source code files. When scripter finds a reference to a file unit (like in "uses"
    ///  clause for example), it tries to find the source code file for that file. If it doesn't find, then it tries to find
    ///  the compiled code. Similar to the way Delphi does when compiling an application.
    ///  So, for example, if SourceFileExt is ".pas", then if the script states "uses SomeFile;", the compiler will try to find
    ///  SomeFile.pas in the source path.
    ///  </remarks>
    property SourceFileExt: string read FSourceFileExt write FSourceFileExt;

    ///  <remarks>
    ///  Contains the default extension for compiled unit files. When scripter finds a reference to a file unit (like in "uses"
    ///  clause for example), it tries to find the source code file for that file. If it doesn't find, then it tries to find
    ///  the compiled code. Similar to the way Delphi does when compiling an application.
    ///  So, for example, if CompiledFileExt is ".pcu", then if the compiler states "uses SomeFile;", the compiler will
    ///  try to find the source code file (for example, SomeFile.pas). If not found, the compiler will try to find SomeFile.pcu
    ///  in the source path.
    ///  </remarks>
    property CompiledFileExt: string read FCompiledFileExt write FCompiledFileExt;

    ///  <summary>
    ///  Contains the default extension for form files. When scripter finds a reference to a form ($FORM directive), it tries
    ///  to find the form (dfm) file in the source path. The FormFileExt extension is used as the extension of that file.
    ///  </summary>
    property FormFileExt: string read FFormFileExt write FFormFileExt;

    ///  <remarks>
    ///  When UseScriptFiles is true, the scripter enabled file-based script libraries. For example, if the script has the
    ///  following uses clause.
    ///  <code>
    ///  uses MyScript;
    ///  </code>
    ///  If MyScript is a library added from code (imported by import tool, for example), then everything works ok. If the
    ///  MyScript library is not found, an error occurs.
    ///  But if UseScriptFiles is set to true, it also tries to find script files in the search path with name MyScript.
    ///  The default file extension is specified by SourceFileExt and CompiledFileExt. So, for example, the compiler tries
    ///  to find MyScript.pas or MyScript.pcu files in search path. If found, then the file is also compiled and used as a library
    ///  by the original script.
    ///  By default, UseScriptFiles is false.
    ///  </remarks>
    property UseScriptFiles: boolean read FUseScriptFiles write FUseScriptFiles;
  end;

  TElementContext = record
    HasArgList: boolean;
    HasUpnode: boolean;
    HasSubNode: boolean;
    IsNewClause: boolean;
    Operation: TDataOperation;
    ArgCount: integer;
    IdxCount: integer;
    RepeatChecking: boolean;
    ElementName: string;
    CurrentClass: TatClass;
  end;

  TUnknownElementEvent = procedure(Sender: TObject; var Context: TElementContext) of object;
  TScriptFormClass = TComponentClass;
  TBaseScriptForm = TComponent;

  TScriptFormFactory = class
  public
    function CreateScriptForm(AOwner: TComponent; AMachine: TatVirtualMachine): TBaseScriptForm; virtual; abstract;
  end;

  ///  <remarks>
  ///  TatCustomScripter component is the base class for all scripter components (TatPascalScripter, TatBasicScripter,
  ///  TatScripter, etc.). TatCustomScripter holds a collection of scripts in the Scripts property. You can add scripts,
  ///  compile and execute. For the scripts to access Delphi variables, classes, methods and properties, the scripter must
  ///  know that information. Some properties and methods and provides to registered such information, like DefineMethod,
  ///  DefineClass, etc. All registered information about available classes, methods and properties are kept in Classes
  ///  property collection.
  ///  </remarks>
  TatCustomScripter = class(TComponent)
  private
    { scripter configuration }
    FDeferObjectResolution: boolean; // permite o adiamento da resolução de classes para runtime
    FScriptClass: TScriptClass; // descendente de TatScript a ser usado
    FMachineClass: TMachineClass; // descendente de TatVirtualMachine a ser usado
    FTypeInfoFilter: TTypeKinds; // knowledgeable types on RTTI member loading
    { aggregated parts }
    FScripts: TatScripts; // coleção interna de scripts
    FCurrentScript: TatScript; // script padrão do componente
    FDefaultInstances: TatObjects; // instâncias padrão
    FClasses: TatClasses; // classes conhecidas
    FLibInstances: TList; // instâncias das bibliotecas conhecidas
    FInternalInstance: TatObject; // to store global members
    { PCode - memory stream }
    FPCode: TMemoryStream; // for streamming purpose
    FOptionExplicit: boolean;
    FOnCompileError: TScriptErrorEvent;
    FOnRuntimeError: TScriptErrorEvent;
    FOnBeforeExecute: TBeforeExecuteEvent;
    { event handling }
    FOnTranslateMethodGetter: TTranslateMethodGetterProc; // for internal purpose
    FOnTranslateMethodSetter: TTranslateMethodSetterProc; // for internal purpose
    FEventSupport: boolean;
    FEventSetMode: TEventSetMode;
    FEventUnsetMode: TEventUnsetMode;
    FEventBroker: TatScripterEventBroker;
    FLoadedScripts: TList;
    FShortBooleanEval: boolean;
    FSaveCompiledCode: boolean;
    FLibOptions: TScripterLibraryOptions;
    FAllowDLLCalls: boolean;
    FOnUnknownElement: TUnknownElementEvent;
    FOnRunningChanged: TNotifyEvent;
    FOnDebugHook: TNotifyEvent;
    FOnSingleDebugHook: TNotifyEvent;
    FLastRunning: boolean; // holds the last overall running status for the scripter
    FOnBreakpointStop: TNotifyEvent;
    FWatches: TatScripterWatches;
    FScriptFormClass: TComponentClass;
    FLoadFormEvents: boolean;
    FScriptBaseObjectClass: TScriptBaseObjectClass;
    FLibraryNameUnderRegistration: string;
    // FOnExecuteEvent  : TExecuteEventProc;
    // FOnSettingEvent  : TSettingEventProc;
    // FOnSetEvent      : TSetEventProc;
    // FOnUnsettingEvent    : TUnsetEventProc;
    { internal }
    procedure ReadPCodeProp(Stream: TStream);
    procedure WritePCodeProp(Stream: TStream);
    function PCodeEquals(pcode: TStream): boolean;
    function GetBreakPoints: TatScriptBreakPoints;
    function GetCompiled: boolean;
    function GetCurrentObject: TObject;
    function GetCurrentClass: TatClass;
    function GetFirstInstruction: pSimplifiedCode;
    function GetHalted: boolean;
    function GetLastExceptionClassName: string;
    function GetLastExceptionHelpContext: integer;
    function GetLastExceptionMessage: string;
    function GetLastExceptionCol: integer;
    function GetLastExceptionLine: integer;
    function GetNextInstruction: pSimplifiedCode;
    function GetOnExecHook: TNotifyEvent;
    function GetOnPauseChanged: TNotifyEvent;
    function GetPaused: boolean;
    function GetRunning: boolean;
    function GetSourceCode: TStrings;
    procedure SetCompiled(const Value: boolean);
    procedure SetOnExecHook(const Value: TNotifyEvent);
    procedure SetOnPauseChanged(const Value: TNotifyEvent);
    procedure SetPaused(const Value: boolean);
    procedure SetRunning(const Value: boolean);
    procedure SetSourceCode(const Value: TStrings);
    procedure CreateLibraries;
    procedure SetClasses(const Value: TatClasses);
    function GetScriptInfo: TatScriptInfo;
    procedure SetEventSetMode(const Value: TEventSetMode);
    procedure SetEventSupport(const Value: boolean);
    procedure SetEventUnsetMode(const Value: TEventUnsetMode);
    procedure TranslateMethodGetter(AMachine: TatVirtualMachine; AInstance: TObject;
      APropInfo: PPropInfo; var AValue: TScriptValue);
    procedure TranslateMethodSetter(AMachine: TatVirtualMachine; AInstance: TObject;
      APropInfo: PPropInfo; AValue: TScriptValue);
    function GetOnExecuteEvent: TExecuteEventProc;
    function GetOnSetEvent: TSetEventProc;
    function GetOnSettingEvent: TSettingEventProc;
    function GetOnUnsettingEvent: TUnsetEventProc;
    procedure SetOnExecuteEvent(const Value: TExecuteEventProc);
    procedure SetOnSetEvent(const Value: TSetEventProc);
    procedure SetOnSettingEvent(const Value: TSettingEventProc);
    procedure SetOnUnsettingEvent(const Value: TUnsetEventProc);
    procedure FreeLibInstances;
    procedure InternalCompileError(msg: string; debuginfo: integer; AScript: TatScript); overload;
    procedure InternalCompileError(msg: string; row, col: integer; AScript: TatScript); overload;
    procedure InternalRuntimeError(msg: string; AScript: TatScript);
    procedure SetOnBeforeExecute(const Value: TBeforeExecuteEvent);
    function GetSilentCompiled: boolean;
    procedure SetSilentCompiled(const Value: boolean);
    function DoSaveCompiledCode: boolean;
    function FindFileInSearchPath(const CompName, SrcName: string): string;
    function FindScriptFile(AName: string): string;
    function IsFileRegisteredAsLibrary(AFileName: string; var ALib: TatScripterLibrary): boolean;
    procedure SetLibOptions(const Value: TScripterLibraryOptions);
    function GetCallExecHookEvent: boolean;
    procedure SetCallExecHookEvent(const Value: boolean);
    procedure ScriptBaseObjectCreateProc(AMachine: TatVirtualMachine);
    function FindFormFile(AName: string): string;
    procedure ScriptFormCreateProc(AMachine: TatVirtualMachine);
    procedure ComponentCreateProc(AMachine: TatVirtualMachine);
    procedure CheckRunningChanged(AMachine: TatVirtualMachine);
    function IsAnyRunning: boolean;
    function GetCurrentDebugScript: TatScript;
    procedure SetScriptBaseObjectClass(const Value: TScriptBaseObjectClass);
    procedure SetScriptFormClass(const Value: TScriptFormClass);
    {$IFDEF DELPHI2010_LVL}
    function ScrClassType(AType: TRttiType): TClass;
    function ScrClassName(AType: TRttiType): string;
    procedure GenericMethodMachineProc(AMachine: TatVirtualMachine);
    procedure GenericPropGetterMachineProc(AMachine: TatVirtualMachine);
    procedure GenericPropSetterMachineProc(AMachine: TatVirtualMachine);
    procedure GenericFieldGetterMachineProc(AMachine: TatVirtualMachine);
    procedure GenericFieldSetterMachineProc(AMachine: TatVirtualMachine);
    procedure GenericRecordFieldGetterMachineProc(AMachine: TatVirtualMachine);
    procedure GenericRecordFieldSetterMachineProc(AMachine: TatVirtualMachine);
    procedure RecordCreateProc(AMachine: TatVirtualMachine);
    procedure RecordFreeProc(AMachine: TatVirtualMachine);
    {$ENDIF}
    {$IFDEF DELPHIXE2_LVL}
    procedure GenericIdxPropGetterMachineProc(AMachine: TatVirtualMachine);
    procedure GenericIdxPropSetterMachineProc(AMachine: TatVirtualMachine);
    {$ENDIF}
    function GetProductVersion: string;
    procedure CheckMachine;
  protected
    procedure DoCompileError(var msg: string; row, col: integer; var AShow: boolean;
      AScript: TatScript); virtual;
    procedure Loaded; override;
    procedure DoUnknownElement(var Context: TElementContext);
    procedure BeforeExecute(AMachine: TatVirtualMachine; ALabel: string);
    procedure DefineInternalClasses; virtual;
    procedure DefineProperties(Filer: TFiler); override;
    procedure BeforeCompile; virtual;
    procedure BeforeLoadCode; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure DoRunningChanged(AMachine: TatVirtualMachine); virtual;
    function DoDebugHook(AMachine: TatVirtualMachine): boolean; virtual;
    procedure SingleDebugHook(AMachine: TatVirtualMachine); virtual;
    procedure SourceCodeChanged(AScript: TatScript); virtual;
    function DefaultScriptClass: TScriptClass; virtual;
    procedure DoBreakpointStop; virtual;
    property ScriptClass: TScriptClass read FScriptClass write FScriptClass;
    property MachineClass: TMachineClass read FMachineClass write FMachineClass;
    property OnTranslateMethodGetter: TTranslateMethodGetterProc read FOnTranslateMethodGetter
      write FOnTranslateMethodGetter;
    property OnTranslateMethodSetter: TTranslateMethodSetterProc read FOnTranslateMethodSetter
      write FOnTranslateMethodSetter;
    property EventSupport: boolean read FEventSupport write SetEventSupport default True;
    property EventSetMode: TEventSetMode read FEventSetMode write SetEventSetMode
      default esReplaceEvent;
    property EventUnsetMode: TEventUnsetMode read FEventUnsetMode write SetEventUnsetMode
      default euReplaceNil;
    property OnExecuteEvent: TExecuteEventProc read GetOnExecuteEvent write SetOnExecuteEvent;
    property OnSettingEvent: TSettingEventProc read GetOnSettingEvent write SetOnSettingEvent;
    property OnSetEvent: TSetEventProc read GetOnSetEvent write SetOnSetEvent;
    property OnUnsettingEvent: TUnsetEventProc read GetOnUnsettingEvent write SetOnUnsettingEvent;
  public
    {$IFDEF DELPHI2010_LVL}
    function ScrTypeKind(AType: TRttiType): TatTypeKind;
    function ScrPrepareValue(AType: TRttiType; AValue: TScriptValue): TValue;
    {$ENDIF}
    property ProductVersion: string read GetProductVersion;

    ///  <summary>
    ///  Create component method.
    ///  </summary>
    constructor Create(AOwner: TComponent); override;

    ///  <summary>
    ///  Destroy component method.
    ///  </summary>
    destructor Destroy; override;

    ///  <summary>
    ///  Initialize all internal structures, disposing memory resources and clearing internal state
    ///  variables. This method is automaticlly called before any compiling.
    ///  </summary>
    procedure Clear; virtual;

    ///  <summary>
    ///  Load compiled code from the file specified by AFileName parameter.
    ///  </summary>
    procedure LoadCodeFromFile(AFileName: string);

    ///  <summary>
    ///  Save compiled code in the file specified by AFileName parameter.
    ///  </summary>
    procedure SaveCodeToFile(AFileName: string);

    ///  <summary>
    ///  Load compiled code from the stream specified by AStream parameter.
    ///  </summary>
    procedure LoadCodeFromStream(AStream: TStream);

    ///  <summary>
    ///  Save compiled code in the stream specified by AStream parameter.
    ///  </summary>
    procedure SaveCodeToStream(AStream: TStream);

    ///  <remarks>
    ///  This method is deprecated. Use DefineMethod instead.
    ///  Add a new user-function to the TatPascalScripter component.
    ///  Input argument for TBuiltInProc always is a variant array of variants. As atPascal allows free
    ///  parameter transfering, the user's implemented functions always should test length and variant
    ///  types of input arguments. Output variant may be a single variant value or a variant array of
    ///  variants. Although atPascal explicitly manipulate only strings and double values you are able
    ///  to use or produce another variant types, such as varInteger, varDate, varDouble, varVariant
    ///  and others.
    ///  </remarks>
    procedure AddFunction(Name: string; Address: TBuiltInProc);

    ///  <summary>
    ///  Compile the current script. See TatScript.Compile for more details.
    ///  </summary>
    procedure Compile; virtual;

    ///  <remarks>
    ///  SilentCompile does the same job of Compile, but instead it continue compilations if any error
    ///  occurs. The Compiled flag is not set in this case, but some information about source code is loaded.
    ///  In it calls SilentCompile method of current script. See TatScript.SilentCompile for more information.
    ///  </remarks>
    procedure SilentCompile;

    ///  <remarks>
    ///  Executes the current script. If the script is not compiled, compilation is performed automatically.
    ///  The input parameter is deprecated and not used anymore.
    ///  The Execute function result contains value returned by the script main block. In pascal, you can use
    ///  return variable to pass the return value, even in the script main block.
    ///  In Basic, you must set MAIN variable to provide the return value.
    ///  </remarks>
    {$IFDEF NEWSTACK}
    function Execute(Input: array of const): TScriptValue; overload; virtual;
    {$ELSE}
    function Execute(Input: Variant): Variant; overload; virtual;
    {$ENDIF}
    function Execute: TScriptValue; overload; virtual;
    function ExecuteAsVariant: Variant;

    ///  <remarks>
    ///  Executes a specific routine (procedure) declared in current script. If
    ///  program is still not compiled, compilation is performed automatically.
    ///  ALabel must contain the name of the routine to be execute, no matching case is performed.
    ///  if the routine doesn't exist, an exception is raised. You can previously check if the routine
    ///  exists using TatScriptInfo.RoutineByName method.
    ///  Input parameter can contain values that will be passed to the script routine. Input
    ///  can be a single Variant-type value, or an array of variant, or an array of const.
    ///  These values are passed to the script routine as parameters. If the routine parameter is declared
    ///  as a parameter by reference - for example, MyScriptFunction(var MyParam: integer); - then to have your
    ///  variable to be updated, you must use the array of const version of ExecuteSubRoutine, passing a variant of
    ///  type Variant.
    ///  </remarks>
    ///  <example>
    ///  <code>
    ///  //script
    ///  procedure MultiplyMyVar(var AValue: integer; AFactor: integer);
    ///  begin
    ///  AValue := AValue * AFactor;
    ///  end;
    ///  //Delphi
    ///  var
    ///  SomeVar: Variant; //MUST BE of Variant type
    ///  begin
    ///  SomeVar := 10;
    ///  atScripter1.ExecuteSubroutine('DoubleMyVar', [SomeVar, 3]);
    ///  //At this point, SomeVar will have value of 30
    ///  end;
    ///  </code>
    ///  The ExecuteSubRoutine function result contains value returned by the called function.
    ///  </example>
    {$IFNDEF NEWSTACK}
    function ExecuteSubroutine(ALabel: string; Input: Variant): Variant; overload;
    {$ENDIF}
    function ExecuteSubroutine(ALabel: string): TScriptValue; overload;
    function ExecuteSubroutine(ALabel: string; Input: array of const): TScriptValue; overload;
    function ExecuteSubroutineAsVariant(ALabel: string): Variant; overload;
    function ExecuteSubroutineAsVariant(ALabel: string; Input: array of const): Variant; overload;

    ///  <summary>
    ///  Calls GetArrayIndex for current virtual machine. See TatVirtualMachine.GetArrayIndex.
    ///  </summary>
    function GetArrayIndex(ADim: integer): TScriptValue;

    ///  <summary>
    ///  Calls InputArgCount for current virtual machine. See TatVirtualMachine.InputArgCount.
    ///  </summary>
    function InputArgCount: integer;

    ///  <summary>
    ///  Calls GetInputArg for current virtual machine. See TatVirtualMachine.GetInputArg.
    ///  </summary>
    function GetInputArg(AIndex: integer): TScriptValue;

    ///  <summary>
    ///  Calls GetInputArgAsString for current virtual machine. See TatVirtualMachine.GetInputArgAsString.
    ///  </summary>
    function GetInputArgAsString(AIndex: integer): string;

    ///  <summary>
    ///  Calls GetInputArgAsClass for current virtual machine. See TatVirtualMachine.GetInputArgAsClass.
    ///  </summary>
    function GetInputArgAsClass(AIndex: integer): TClass;

    ///  <summary>
    ///  Calls GetInputArgAsWideString for current virtual machine. See TatVirtualMachine.GetInputArgAsWideString.
    ///  </summary>
    {$IFNDEF NEXTGEN}
    function GetInputArgAsWideString(AIndex: integer): Widestring;
    {$ENDIF}

    ///  <summary>
    ///  Calls GetInputArgAsInteger for current virtual machine. See TatVirtualMachine.GetInputArgAsInteger.
    ///  </summary>
    function GetInputArgAsInteger(AIndex: integer): integer;

    ///  <summary>
    ///  Calls GetInputArgAsInt64 for current virtual machine. See TatVirtualMachine.GetInputArgAsInt64
    ///  </summary>
    function GetInputArgAsInt64(AIndex: integer): Int64;

    ///  <summary>
    ///  Calls GetInputArgAsBoolean for current virtual machine. See TatVirtualMachine.GetInputArgAsBoolean.
    ///  </summary>
    function GetInputArgAsBoolean(AIndex: integer): boolean;

    ///  <summary>
    ///  Calls GetInputArgAsFloat for current virtual machine. See TatVirtualMachine.GetInputArgAsFloat.
    ///  </summary>
    function GetInputArgAsFloat(AIndex: integer): double;

    ///  <summary>
    ///  Calls GetInputArgAsDateTime for current virtual machine. See TatVirtualMachine.GetInputArgAsDateTime.
    ///  </summary>
    function GetInputArgAsDateTime(AIndex: integer): TDateTime;

    ///  <summary>
    ///  Calls SetInputArg for current virtual machine. See TatVirtualMachine.SetInputArg.
    ///  </summary>
    procedure SetInputArg(AIndex: integer; const AValue: TScriptValue);

    ///  <summary>
    ///  Calls SetInputArgIfByRef for current virtual machine. See TatVirtualMachine.SetInputArgIfByRef.
    ///  </summary>
    procedure SetInputArgIfByRef(AIndex: integer; const AValue: TScriptValue);

    ///  <summary>
    ///  Calls ReturnOutputArg for current virtual machine. See TatVirtualMachine.ReturnOutputArg.
    ///  </summary>
    procedure ReturnOutputArg(AValue: TScriptValue);

    ///  <summary>
    ///  Convert a script source position to a row and column information.
    ///  </summary>
    procedure GetRowColFromSource(APos: integer; var row, col: integer);

    ///  <summary>
    ///  Calls SolveAbsoluteAddressing for current virtual machine. See TatVirtualMachine.SolveAbsoluteAddressing.
    ///  </summary>
    procedure SolveAbsoluteAddressing;

    ///  <summary>
    ///  Calls Halt for current virtual machine. See TatVirtualMachine.Halt.
    ///  </summary>
    procedure Halt;

    ///  <summary>
    ///  Calls InstructionByLine for current virtual machine. See TatVirtualMachine.InstructionByLine.
    ///  </summary>
    function InstructionByLine(ARow: integer): pSimplifiedCode;

    ///  <summary>
    ///  Calls EntryPoint for current virtual machine. See TatVirtualMachine.EntryPoint.
    ///  </summary>
    function EntryPoint(ALabel: string): pSimplifiedCode;

    ///  <summary>
    ///  Calls DebugTraceInto for current virtual machine. See TatVirtualMachine.DebugTraceInto.
    ///  </summary>
    procedure DebugTraceInto;

    ///  <summary>
    ///  Calls DebugStepOver for current virtual machine. See TatVirtualMachine.DebugStepOver.
    ///  </summary>
    procedure DebugStepOver;

    ///  <summary>
    ///  Calls DebugTraceIntoLine for current virtual machine. See TatVirtualMachine.DebugTraceIntoLine.
    ///  </summary>
    procedure DebugTraceIntoLine;

    ///  <summary>
    ///  Calls DebugStepOverLine for current virtual machine. See TatVirtualMachine.DebugStepOverLine.
    ///  </summary>
    procedure DebugStepOverLine;

    ///  <summary>
    ///  Calls DebugRunUntilReturn for current virtual machine. See TatVirtualMachine.DebugRunUntilReturn.
    ///  </summary>
    procedure DebugRunUntilReturn;

    ///  <summary>
    ///  Calls DebugRunToPoint for current virtual machine. See TatVirtualMachine.DebugRunToPoint.
    ///  </summary>
    procedure DebugRunToPoint(AInstruction: pSimplifiedCode);

    ///  <summary>
    ///  Calls DebugRunToLine for current virtual machine. See TatVirtualMachine.DebugRunToLine.
    ///  </summary>
    procedure DebugRunToLine(ALine: integer);

    ///  <summary>
    ///  Calls DebugToggleBreakPoint for current virtual machine. See TatVirtualMachine.DebugToggleBreakPoint.
    ///  </summary>
    function DebugToggleBreakPoint(AInstruction: pSimplifiedCode): boolean;

    ///  <summary>
    ///  Calls DebugToggleBreakLine for current virtual machine. See TatVirtualMachine.DebugToggleBreakLine.
    ///  </summary>
    function DebugToggleBreakLine(ALine: integer): pSimplifiedCode;

    ///  <summary>
    ///  Calls DebugExecutionLine for current virtual machine. See TatVirtualMachine.DebugExecutionLine.
    ///  </summary>
    function DebugExecutionLine: integer;

    ///  <summary>
    ///  Calls ExpandedDebugInfo for current script. See TatScript.ExpandedDebugInfo.
    ///  </summary>
    function ExpandedDebugInfo: boolean;

    ///  <summary>
    ///  Calls ExpandDebugInfo for current script. See TatScript.ExpandDebugInfo.
    ///  </summary>
    procedure ExpandDebugInfo(RequiresCompilation: boolean = True);

    ///  <summary>
    ///  Same as Classes.ClassByName, please refer to TatClasses reference.
    ///  </summary>
    function ClassByName(AName: string): TatClass;

    ///  <summary>
    ///  Deprecated. Use DefineClass instead.
    ///  </summary>
    function AddDelphiClass(AClass: TClass): TatClass; // obsolete

    ///  <summary>
    ///  Same as Classes.DefineClass, please refer to TatClasses reference.
    ///  </summary>
    function DefineClass(AClass: TClass; AClassName: string = ''): TatClass;

    {$IFDEF DELPHI2010_LVL}
    ///  <summary>
    ///  Register a record structure to be used in Scripter like a class
    ///  (see TatClasses.AddRecord) and define constructor/destructor methods.
    ///  </summary>
    function DefineRecord(ATypeInfo: PTypeInfo; ARecordName: string = ''): TatClass;
    {$ENDIF}
    ///  <summary>
    ///  Registers the component specified by AComp to be accessible from all scripts. The component will be accessible
    ///  by its name. Published properties of component will also be automatically available for reading/writing.
    ///  </summary>
    procedure AddComponent(AComp: TComponent);

    ///  <remarks>
    ///  Register all the components owned by AComp to be accessible from all scripts. The components will be accessible
    ///  by their name. Published properties of components will also be automatically available for reading/writing.
    ///  Be aware that AComp itself is not register - only the components owned by it.
    ///  </remarks>
    procedure AddComponents(AComp: TComponent);

    ///  <remarks>
    ///  DefineFormClass is similar to DefineClass, with the difference that all components owned by the form/component
    ///  are made available as properties of the form class. This way if you have an object MyForm you can access
    ///  their components directly using for example MyForm.Edit1.
    ///  Although this method mimics the behavior of a Form, any component can be passed, not only forms
    ///  </remarks>
    function DefineFormClass(AForm: TComponent; AFormClassName: string = ''): TatClass;

    ///  <remarks>
    ///  AddForm registers the form instance specified by AForm to be accessible from all scripts. The form will be
    ///  accessible by its name. AddForm is similar to AddComponent, but the difference is that all components owned by the form
    ///  are made available as properties of the form class. This way if you have an object MyForm you can access
    ///  their components directly using for example MyForm.Edit1.
    ///  Although this method mimics the behavior of a Form, any component can be passed, not only forms
    ///  </remarks>
    procedure AddForm(AForm: TComponent; AFormClassName: string = '');

    ///  <remarks>
    ///  AddDataModule registers the data module instance specified by ADataModule to be accessible from all scripts. The data module will be
    ///  accessible by its name. AddDataModule is similar to AddComponent, but the difference is that all components owned by the data module
    ///  are made available as properties of the data module class. This way if you have an object MyDataModule you can access
    ///  their components directly using for example MyDataModule.Table1.
    ///  </remarks>
    procedure AddDataModule(ADataModule: TDataModule; ADataModuleClassName: string = '');

    ///  <remarks>
    ///  Register the object specified by AObject to be acessible from all scripts. The object will be acessible by the name specified
    ///  by AName. Published properties of component will also be automatically available for reading/writing.
    ///  This method is similar to AddComponent, with the difference that you must specify the name from which the object will
    ///  be acessible from script.
    ///  </remarks>
    procedure AddObject(AName: string; AObject: TObject);

    ///  <summary>
    ///  Register a constant specified by AValue to be accessible from all scripts by the name AName.
    ///   Example: AddConstant('Pi', 3.1415);
    ///  </summary>
    procedure AddConstant(AName: string; AValue: TScriptValue);

    {$IFNDEF NEXTGEN}
    ///  <summary>
    ///  AddVariable is deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: Variant); overload;
    ///  <summary>
    ///  AddVariable is deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: extended); overload;
    ///  <summary>
    ///  AddVariable is deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: double); overload;
    ///  <summary>
    ///  AddVariable is deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: string); overload;
    ///  <summary>
    ///  AddVariable is deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: Widestring); overload;
    ///  <summary>
    ///  AddVariable is deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: integer); overload;
    ///  <summary>
    ///  AddVariable is deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: boolean); overload;
    {$ENDIF}

    ///  <remarks>
    ///  Adds an enumerated type to be accessible from all scripts. All enumerated type items will be accessible from all scripts
    ///  by their name, and the value will be the integer value of enumerated type item. Only enumerated types with RTTI
    ///  can be included using this method. A better and more generic approach is to use AddConstant for each enumerated type.
    ///  <code>
    ///  AddConstant('alClient', alClient);
    ///  </code>
    ///  </remarks>
    procedure AddEnumeration(ATypeInfo: PTypeInfo);

    ///  <remarks>
    ///  Use DefineProp to define a "global" property. DefineProp can be called from an existing TatClass object to register a new
    ///  property in that class. When you call DefineProp directly from scripter component, the property is not included in a class,
    ///  but globally in scripter. Thus the property will behave as a global variable, being accessible from all scripts without
    ///  needing to define an object from which the property will be used.
    ///  For more details about usage of DefineProp, see TatClasses.DefineProp.
    ///  </remarks>
    function DefineProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TMachineProc;
      APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
      : TatProperty;

    ///  <summary>
    ///  Remove the property specified by the name AName.
    ///  </summary>
    procedure RemoveProperty(AName: string);

    ///  <remarks>
    ///  Use DefineMethod to define a "global" method. DefineMethod can be called from an existing TatClass object to register a new
    ///  method in that class. When you call DefineMethod directly from scripter component, the method is not included in a class,
    ///  but globally in scripter. Thus the method will behave as a regular procedure/function, being accessible from scripts without
    ///  needing to define an object from which the method will be called.
    ///  For more details about usage of DefineMethod, see TatClasses.DefineMethod.
    ///  </remarks>
    function DefineMethod(AName: string; AArgCount: integer; AResultDataType: TatTypeKind;
      AResultClass: TClass; AProc: TMachineProc; AIsClassMethod: boolean = false;
      ADefArgCount: integer = 0; AParameterHints: string = ''): TatMethod;

    ///  <remarks>
    ///  UsesObject makes methods and properties of AObject to be accessible directly from script. In other words, the methods of
    ///  the object behave as regular procedures, and properties as global variables. For example, if you have the object MyObj for the
    ///  class TMyClass and that class is registered in scripter with method MyMethod and property MyProperty. If you call
    ///  <code>
    ///  UsesObject(MyObj);
    ///  </code>
    ///  then you will be able to use MyMethod and MyProperty directly from script as if they were global.
    ///  <code>
    ///  //Script
    ///  MyProperty := SomeValue;
    ///  MyMethod(Param1);
    ///  </code>
    ///  Alternatively you can specify the name of object using AName. In this case, you can optionally also use the name of object
    ///  as if it were a regular object. Using methods and properties directly still works. See following example.
    ///  <code>
    ///  UsesObject(MyObj, 'MyObj');
    /// 
    ///  //Script
    ///  MyObj.MyProperty := SomeValue;
    ///  MyObj.MyMethod(Param1);
    ///  MyProperty := SomeValue;
    ///  MyMethod(Param1);
    ///  </code>
    ///  Just like any other object in scripter, only published properties will be accessible, unless you previously
    ///  register the class of the object and register its methods and properties. Do not use AClassName parameter, it's
    ///  for internal use.
    ///  </remarks>
    function UsesObject(AObject: TObject; AName: string = ''; AClassName: string = ''): TatClass;

    ///  <remarks>
    ///  AddLibraryInstance adds a new library to be available in scripter. You should rarely use this method, call AddLibrary instead.
    ///  AddLibraryInstance requires an already instantiated TatScripterLibrary object, to be passed in ALibrary parameter.
    ///  AName must contain the name which the library instance will be accessible (e.g., if AName is "MyLibrary", you access
    ///  library methods and properties with MyLibrary.MyMethod). Used only if AddMethod is true.
    ///  ADefault parameter indicates if the library methods and properties will be accessible from all scripts without needing
    ///  to use the library name prefix. For example, if ADefault is true, you can directly access MyMethod from script, without
    ///  needing to use MyLibrary.MyMethod.
    ///  AddMethod allows you to access library methods and properties as if the library was an object. The object name is
    ///  specified by AName parameter. (e.g., if AddMethod is true and AName is "MyLibrary", you access library methods and
    ///  properties using MyLibrary.MyMethod).
    ///  LibName is the name of the class of the library. You can use it, for example, when the library has class methods.
    ///  If LibName is empty, the name of the Delphi class will be used. For example, if the class of your library is TatMyLibrary,
    ///  and LibName is empty, you can access class methods using TatMyLibrary.MyClassMethod. If LibName is not empty, for example,
    ///  if LibName is "TMyNewLibraryClassName", then you can access class methods using TMyNewLibraryClassName.MyClassMethod.
    ///  AddLibraryInstance calls the Init method of library to perform the registration of the library.
    ///  </remarks>
    procedure AddLibraryInstance(ALibrary: TatScripterLibrary; AName: string;
      ADefault: boolean = True; AddMethod: boolean = True; LibName: string = '');

    ///  <remarks>
    ///  RemoveLibraryInstance removes a library instance previously registered with AddLibraryInstance. If the library was
    ///  previously registered using a method name, then you must provide the AName method for the library to be removed.
    ///  RemoveLibraryInstance calls library's Finalize method to perform finalization operations. It's up to the library to
    ///  include correct code in Finalize method to remove previously classes, methods and properties registered by Init method.
    ///  </remarks>
    procedure RemoveLibraryInstance(ALibrary: TatScripterLibrary; AName: string);

    ///  <remarks>
    ///  AddLibrary registers the library specified by ALibraryClass in the scripter registration system. You don't need to
    ///  instantiate the library, just provide the name of the library class. Scripter will automatically instantiate it
    ///  and call AddLibraryInstance method to register the library. The library's Init method will be called to initiate the
    ///  library. If the library class has been already registered, nothing will be done.
    ///  The methods and properties of the library will be accessible through the name specified by LibraryName method declared
    ///  in the library class. For example, if LibraryName returns 'MyLibrary', then methods and properties will be accessible the following way.
    ///  <code>
    ///  MyLibrary.MyMethod;
    ///  </code>
    ///  If ADefault parameter is true, you have the option to omit library name and call the method directly from script.
    ///  <code>
    ///  MyMethod;
    ///  </code>
    ///  Example of use.
    ///  atScripter1.AddLibrary(TatButtonsLibrary);
    ///  </remarks>
    function AddLibrary(ALibraryClass: TatScripterLibraryClass; ADefault: boolean = True)
      : TatScripterLibrary;

    ///  <remarks>
    ///  FindLibraryByClass searches for all libraries registered in the scripter and returns the library instance if found.
    ///  If there are no registered libraries of the class ALibraryClass, then the function returns false.
    ///  <code>
    ///  MyClassesLibrary := atScripter1.FindLibraryClass(TatClassesLibrary);
    ///  </code>
    ///  </remarks>
    function FindLibraryByClass(ALibraryClass: TatScripterLibraryClass): TatScripterLibrary;

    ///  <remarks>
    ///  LoadLibrary loads a library with the name specified by ALibraryName. LoadLibrary is the most generic way to load
    ///  libraries, since it tries to load different kinds of libraries (Delphi-based libraries, file-based libraries, etc.)
    ///  given an unique name. When the compiler finds an "uses" clause in the script, it calls LoadLibrary for each "used" unit.
    ///  So, calling LoadLibrary "simulates" a unit usage specified in an uses clause. Here is what happens when LoadLibrary
    ///  is called.
    /// 
    ///  1. Scripter tries to find a Delphi-based library with the name ALibraryName. Delphi-based libraries are those libraries
    ///  inherited from TatScripterLibrary that were previously registered with RegisterScripterLibrary. The ALibraryName must
    ///  match the method LibraryName of the registered library. If found, the library is added to scripter with a call to
    ///  AddLibrary method
    /// 
    ///  2. If Delphi-based library is not found, scripter tries to find a script-based library. It searches for all scripts
    ///  in the Scripts collection, which UnitName is the same as ALibraryName. If the script is found, then the script is registered
    ///  as a library. In other words, SelfRegisterAsLibrary is called for that script.
    /// 
    ///  3. If still no library are found, the scripter tries to find a file-based library (if LibOptions.UseScriptFiles is true).
    ///  It tries to find a script file which matches the name specified by ALibraryName. See TatCustomScripter.LibOptions property
    ///  to see the rules for searching the file (search path, default extensions, etc.). If the file is founds, it is loaded
    ///  in the Scripts collection, compiled (not needed if the file found is already a compiled p-code file), and registered
    ///  using SelfRegisterAsLibrary method
    /// 
    ///  If ADefault parameter is true, you have the option to omit library name and call the method directly from script.
    ///  if no library is found, an exception is raised. If ASilent parameter is true, then no exception is raised and nothing happens.
    ///  </remarks>
    function LoadLibrary(ALibraryName: string; ADefault: boolean = True; ASilent: boolean = false)
      : TatScripterLibrary;

    ///  <summary>
    ///  LoadLibrary2 is a work around for C++ automatic header generation. It just calls LoadLibrary method.
    ///  </summary>
    procedure LoadLibrary2(ALibraryName: string; ADefault: boolean = True);

    ///  <summary>
    ///  Calls InProcessExecute method of current virtual machine. See TatVirtualMachine.IncProcessExecute method.
    ///  </summary>
    function InProcessExecute(AScriptStub: string): boolean;

    ///  <remarks>
    ///  BuildEventHandlerName is a function which builds a friendly name for a script procedure
    ///  which will be an event handler for the event PropName in the component Instance. So, for example, if
    ///  Instance is the button Button1 and PropName is 'OnClick', BuildEventHandlerName returns 'Button1Click'.
    ///  </remarks>
    function BuildEventHandlerName(Instance: TComponent; PropName: string): string;

    ///  <summary>
    ///  DeclareEventHandler will include a event handler declaration in script for the AProcName procedure
    ///  The result of function is the line on which the code must be written, not the line of declaration itself.
    ///  </summary>
    function DeclareEventHandler(AProcName: string): integer;

    ///  <summary>
    ///  For internal use only. Do not use this method.
    ///  </summary>
    procedure GetInfoFromRoutineName(var RName: string; var AMachine: TatVirtualMachine);

    {$IFDEF DELPHI2010_LVL}
    ///  <remarks>
    ///  DefineClassByRTTI register AClass and its methods, properties and fields into Scripter,
    ///  using RTTI to retrieve information about given class.
    ///  AClassName: custom name for registered class, the original class name is used if empty.
    ///  AVisibilityFilter: register only members whose visibility is in this set.
    ///  ARecursive: if true, register also types used by methods and properties of this class.
    ///  ARedefine: default behavior if AClass is already registered in scripter.
    ///  roNone: keeps currently registered class and does not register anything new.
    ///  roInclude: adds methods and properties that are not defined yet to registered class.
    ///  roOverwrite: defines the class and its members overwriting the currently registered one.
    ///  </remarks>
    function DefineClassByRTTI(AClass: TClass; AClassName: string = '';
      AVisibilityFilter: TMemberVisibilitySet = [mvPublic, mvPublished];
      ARecursive: boolean = false; ARedefine: TRedefineOption = roNone): TatClass; overload;
    function DefineClassByRTTI(AClass: TClass; ARedefine: TRedefineOption;
      ARecursive: boolean = false; AClassName: string = '';
      AVisibilityFilter: TMemberVisibilitySet = [mvPublic, mvPublished]): TatClass; overload;

    ///  <remarks>
    ///  DefineRecordByRTTI register the record structure specified by ATypeInfo into Scripter,
    ///  using RTTI to retrieve information about given record. Records registered in Scripter
    ///  will work like a class and need to be instantiated (TRecord.Create).
    ///  The TatClass object representing the record is returned
    ///  </remarks>
    function DefineRecordByRTTI(ATypeInfo: pointer): TatClass;
    {$ENDIF}
    ///  <summary>
    ///  EventBroker property provides access to the TatScripterEventBroker object which controls the binding between
    ///  scripter and Delphi events. See TatScripterEventBroker class for more information.
    ///  </summary>
    property EventBroker: TatScripterEventBroker read FEventBroker;

    ///  <remarks>
    ///  DefaultInstances holds a list of objects which are treated by scripter as default objects. A default object is
    ///  an object which methods and properties are directly accessible from all scripts without the need to prepend the method
    ///  name with the object name. For example, if an object MyObject has the method MyMethod, and it is added as a default
    ///  instance in DefaultInstances property, you can access the method directly the following way.
    ///  <code>
    ///  MyMethod;
    ///  </code>
    ///  You will rarely add objects directly to DefaultInstances, you should use UsesObject method instead.
    ///  </remarks>
    property DefaultInstances: TatObjects read FDefaultInstances;

    ///  <remarks>
    ///  Classes property holds the list of all registered classes in scripter. For the scripter to know about a class and
    ///  the class to be accessible from all scripts, it must be in this collection. Each registered class is a TatClass object
    ///  which holds information about all methods and properties known by the scripter. When the scripter finds in script
    ///  a reference to an object of a specified class, it will look for that class in the Classes property to find all
    ///  the methods and properties that can be accessed from that object.
    ///  When you call a DefineClass method, an entry is added in this collection.
    ///  </remarks>
    property Classes: TatClasses read FClasses write SetClasses;

    ///  <remarks>
    ///  SystemLibrary returns the instance of the TatClass object which holds information about all methods and properties
    ///  registered in the default system library. This reference is useful when you want to find and remove/change a
    ///  specified method or property in the system library.
    ///  The system library is a collection of basic methods and constants (like IntToStr, Format, Date, etc.) that are registered
    ///  by default in the scripter component.
    ///  </remarks>
    function SystemLibrary: TatClass;

    ///  <summary>
    ///  This property provides access to the SourceCode property of current script. See TatScript.SourceCode for more details.
    ///  Compilation is NOT called automatically when changing this property.
    ///  </summary>
    property SourceCode: TStrings read GetSourceCode write SetSourceCode;

    ///  <summary>
    ///  Provides access to LastExceptionMessage property of current virtual machine. See TatVirtualMachine.LastExceptionMessage for more details.
    ///  </summary>
    property LastExceptionMessage: string read GetLastExceptionMessage;

    property LastExceptionLine: integer read GetLastExceptionLine;
    property LastExceptionCol: integer read GetLastExceptionCol;

    ///  <summary>
    ///  Provides access to LastExceptionHelpContext property of current virtual machine.
    ///  See TatVirtualMachine.LastExceptionHelpContext for more details.
    ///  </summary>
    property LastExceptionHelpContext: integer read GetLastExceptionHelpContext;

    ///  <summary>
    ///  Provides access to LastExceptionClassName property of current virtual machine.
    ///  See TatVirtualMachine.LastExceptionClassName for more details.
    ///  </summary>
    property LastExceptionClassName: string read GetLastExceptionClassName;

    ///  <summary>
    ///  Provides access to ScriptInfo property of current script. See TatScript.ScriptInfo for more details.
    ///  </summary>
    property ScriptInfo: TatScriptInfo read GetScriptInfo;

    ///  <summary>
    ///  Provides access to CurrentObject property of current virtual machine. See TatVirtualMachine.CurrentObject for more details.
    ///  </summary>
    property CurrentObject: TObject read GetCurrentObject;

    ///  <summary>
    ///  Provides access to CurrentClass property of current virtual machine. See TatVirtualMachine.CurrentClass for more details.
    ///  </summary>
    property CurrentClass: TatClass read GetCurrentClass;

    ///  <summary>
    ///  Provides access to Compiled property of current script. See TatScript.Compiled for more details.
    ///  </summary>
    property Compiled: boolean read GetCompiled write SetCompiled stored DoSaveCompiledCode;

    ///  <summary>
    ///  Deprecated property. This should be always false.
    ///  </summary>
    property SaveCompiledCode: boolean read FSaveCompiledCode write FSaveCompiledCode;

    ///  <summary>
    ///  Provides access to SilentCompiled property of current script. See TatScript.SilentCompiled for more details.
    ///  </summary>
    property SilentCompiled: boolean read GetSilentCompiled write SetSilentCompiled;

    ///  <summary>
    ///  Deprecated property. Don't use it.
    ///  </summary>
    property pcode: TMemoryStream read FPCode write FPCode;

    { Provides access to BreakPoints property of current virtual machine. See TatVirtualMachine.BreakPoints for more details }
    property BreakPoints: TatScriptBreakPoints read GetBreakPoints;

    ///  <summary>
    ///  Provides access to Halted property of current virtual machine. See TatVirtualMachine.Halted for more details.
    ///  </summary>
    property Halted: boolean read GetHalted;

    ///  <remarks>
    ///  Running property indicates if a script is being executed by the scripter component. If the scripter holds multiple
    ///  scripts, Running property will be true if any of the scripts is running. If not script is running, the value will
    ///  be false.
    ///  When setting Running to true of false, it will change the Running value of the current virtual machine.
    ///  See TatVirtualMachine.Running for more details.
    ///  </remarks>
    property Running: boolean read GetRunning write SetRunning;

    ///  <summary>
    ///  Provides access to Paused property of current virtual machine. See TatVirtualMachine.Paused for more details.
    ///  </summary>
    property Paused: boolean read GetPaused write SetPaused;

    ///  <summary>
    ///  Enables OnExecHook event. If CallExecHookEvent is true, OnExecHook event is fired, otherwise it's disabled.
    ///  CallExecHookEvent is false by default.
    ///  </summary>
    property CallExecHookEvent: boolean read GetCallExecHookEvent write SetCallExecHookEvent;

    ///  <summary>
    ///  Provides acess to FirstInstruction property of current script. See TatScript.FirstInstruction for more details.
    ///  </summary>
    property FirstInstruction: pSimplifiedCode read GetFirstInstruction;

    ///  <remarks>
    ///  OnDebugHook event is a callback event that is called when a script running but in paused condition. When the script
    ///  is paused, the main application loop is executed by scripter not by VCL. OnDebugHook is then a way to have a callback
    ///  from this loop and perform operations like updating the application user-interface.
    ///  OnDebugHook is called many times while the script execution is paused. See also OnSingleDebugHook which is fired only once.
    ///  </remarks>
    property OnDebugHook: TNotifyEvent read FOnDebugHook write FOnDebugHook;

    ///  <remarks>
    ///  OnSingleDebugHook event is called whenever the script execution is paused or a debug action is performed (like StepOver,
    ///  TraceInto, etc.. Different from OnDebugHook, which is called many times inside a loop when the script is paused,
    ///  OnSingleDebugHook is called only once. It provides a better performance if the purpose is to update a debugging IDE
    ///  when a debug action takes place.
    ///  </remarks>
    property OnSingleDebugHook: TNotifyEvent read FOnSingleDebugHook write FOnSingleDebugHook;

    ///  <summary>
    ///  OnExecHook event is called during scripter execution. It's a callback event that you can use for performing operations
    ///  while a script is being executed. For performance reasons, OnExecHook is only called when CallExecHookEvent property is true.
    ///  </summary>
    property OnExecHook: TNotifyEvent read GetOnExecHook write SetOnExecHook;

    ///  <summary>
    ///  OnPauseChanged is fired whenever Paused property value is changed.
    ///  </summary>
    property OnPauseChanged: TNotifyEvent read GetOnPauseChanged write SetOnPauseChanged;

    ///  <summary>
    ///  OnRunningChanged event is fired whenever value of Running property changes.
    ///  </summary>
    property OnRunningChanged: TNotifyEvent read FOnRunningChanged write FOnRunningChanged;

    ///  <summary>
    ///  Provides access to NextInstruction property of current virtual machine. See TatVirtualMachine.NextInstruction for more details.
    ///  </summary>
    property NextInstruction: pSimplifiedCode read GetNextInstruction;

    ///  <remarks>
    ///  CurrentScript returns the current selected script among the available scripts in the Scripts collection.
    ///  When the scripter is running, CurrentScript contains the current script object that is being executed.
    ///  It might change from time to time depending on the calls inside the script source code: if the current script
    ///  calls functions and procedures in another script, the current script changes when the subroutine is executed.
    ///  </remarks>
    property CurrentScript: TatScript read FCurrentScript write FCurrentScript;

    ///  <remarks>
    ///  CurrentDebugScript is similar to CurrentScript, with a small difference when it comes to forms.
    ///  When a new form instance is created, a new script is created in Scripts collection, and the script information
    ///  (source code, etc.) is copied from original form script. When the form executes its script, then CurrentScript
    ///  changes, but CurrentDebugScript continues pointing to the original script object which generated the form instance.
    ///  </remarks>
    property CurrentDebugScript: TatScript read GetCurrentDebugScript;

    ///  <remarks>
    ///  ScriptFormClass property specifies the class of script form that are to be created
    ///  dynamically by scripter when a new form is instantiated from script. Default value is TScriptForm, but you can set any
    ///  other form class that descends from TScriptForm.
    ///  </remarks>
    property ScriptFormClass: TScriptFormClass read FScriptFormClass write SetScriptFormClass;

    ///  <remarks>
    ///  ScriptBaseObjectClass property specifies the class of script that are to be created
    ///  dynamically by scripter when a new class is instantiated from script. Default value is TScriptBaseObject, but you can set any
    ///  other class that descends from TScriptBaseObject.
    ///  </remarks>
    property ScriptBaseObjectClass: TScriptBaseObjectClass read FScriptBaseObjectClass
      write SetScriptBaseObjectClass;

    ///  <remarks>
    ///  Scripts property holds a collection of existing scripts in the scripter component. A scripter can hold one or more
    ///  scripts, each of them can be individually compiled and executed (one at time) and each one holds script information
    ///  like source code, variables, routines, etc.. A script is analog to a unit in a Delphi project.
    ///  </remarks>
    property Scripts: TatScripts read FScripts;

    ///  <remarks>
    ///  When OptionExplicit is true, you must declare variables inside script. When OptionExplicit is false, you don't need
    ///  to declare variables, just initializing a variable will automatically declare it.
    ///  <code>
    ///  begin
    ///  MyNewVar := 0;
    ///  end;
    ///  </code>
    ///  the above code is valid when OptionExplicit is false. If it is set to true, a compilation error will be raised, and
    ///  you be explicity declare the variable.
    ///  <code>
    ///  var
    ///  MyNewVar: integer;
    ///  begin
    ///  MyNewVar := 0;
    ///  end;
    ///  </code>
    ///  Even when OptionExplicit is false, you cannot use a variable before it is initialized. The following code is invalid
    ///  in any situation.
    ///  <code>
    ///  begin
    ///  ShowMessage(IntToStr(MyNewVar)); //Error, MyNewVar not declared/initialized
    ///  end;
    ///  </code>
    ///  OptionExplicit is false by default in TatPascalScripter and TatBasicScripter components, for backward compatibility purposes,
    ///  but it is true by default in the new TatScripter component.
    ///  </remarks>
    property OptionExplicit: boolean read FOptionExplicit write FOptionExplicit;

    ///  <remarks>
    ///  Watches property holds a collection of current watches for debugging purposes. You can add, edit and delete watches
    ///  in this collection, specify the expression for each watch and retrieve its result value. This property is mostly used
    ///  for building debugging IDE's, but you can use it programmatically as well.
    ///  </remarks>
    property Watches: TatScripterWatches read FWatches;

    ///  <summary>
    ///  OnCompileError event is fired whenever an error occurs during a script compilation.
    ///  </summary>
    property OnCompileError: TScriptErrorEvent read FOnCompileError write FOnCompileError;

    ///  <summary>
    ///  OnRuntimeError event is fired whenever a runtime error occurs during a script execution.
    ///  </summary>
    property OnRuntimeError: TScriptErrorEvent read FOnRuntimeError write FOnRuntimeError;

    ///  <remarks>
    ///  When DeferObjectResolution is true, the compiler will ignore class types and defer all methods/properties
    ///  resolution to runtime. For example, if you have "MyButton.Click;" in your script, it will not check if
    ///  MyButton is a class which holds a valid Click method. All will be defered to runtime.
    ///  Default value for DeferObjectResolution is false. You should rarely use this property.
    ///  </remarks>
    property DeferObjectResolution: boolean read FDeferObjectResolution
      write FDeferObjectResolution;

    ///  <summary>
    ///  OnBeforeExecute is called before a script routine (or main block) is executed. ALabel contains the name of the
    ///  routine to be executed. If the main block is to be executed, ALabel is an empty string.
    ///  </summary>
    property OnBeforeExecute: TBeforeExecuteEvent read FOnBeforeExecute write SetOnBeforeExecute;

    ///  <remarks>
    ///  When ShortBooleanEval property is true, the boolean expression will be available only when needed, just like Delphi.
    ///  For example, for an expression "if (IsEnabled) or (IsVisible) then..." , if IsEnabled returns true, the method
    ///  IsVisible is not even called, because the boolean value of expression is already known to be true.
    ///  When ShortBooleanEval property is false, the whole boolean expression is evaluated.
    ///  ShortBooleanEval is false by default in old TatPascalScripter and TatBasicScripter for backward compatibility.
    ///  In TatScripter component, it is true by default.
    ///  </remarks>
    property ShortBooleanEval: boolean read FShortBooleanEval write FShortBooleanEval;

    ///  <remarks>
    ///  When AllowDllCalls is true, you can call dll functions directly from script, using a syntax similar to Delphi.
    ///  <code>
    ///  function MessageBox(hwnd: pointer; text, caption: AnsiString;
    ///  msgtype: integer): integer; stdcall; external 'User32.dll' name 'MessageBoxA';
    ///  </code>
    ///  MessageBox(nil, 'Are you sure?', 'Confirmation', MB_ICONQUESTION + MB_YESNO);
    /// 
    ///  For security purposes, AllowDllCalls is false by default.
    ///  </remarks>
    property AllowDLLCalls: boolean read FAllowDLLCalls write FAllowDLLCalls;

    ///  <summary>
    ///  LibOptions property holds a TScripterLibraryOptions object with configuration about how libraries are found and
    ///  loaded in scripter environment. See TScripterLibraryOptions class for more information.
    ///  </summary>
    property LibOptions: TScripterLibraryOptions read FLibOptions write SetLibOptions;

    ///  <remarks>
    ///  OnUnknownElement event is fired during a script compilation when the compiler finds an identifier it cannot recognize.
    ///  Attach an event handler to this event to add properties, methods and references on the fly, according to the identifiers
    ///  used in the script.
    ///  </remarks>
    property OnUnknownElement: TUnknownElementEvent read FOnUnknownElement write FOnUnknownElement;

    ///  <remarks>
    ///  Set LoadFormEvents to true to allow loading dfm files which contain event handlers.
    ///  When a script form is compiled, the dfm file specified in directive $FORM is loaded.
    ///  Usually, if the dfm contain specified event handlers, like for example "OnClick = Button1Click",
    ///  an error will raised. When LoadFormEvents is true, it will check if the script contains
    ///  a routine named Button1Click, and if it does, it sets the correct event handler to the
    ///  component's event, as specified in the dfm. By default, LoadFormEvents is false.
    ///  </remarks>
    property LoadFormEvents: boolean read FLoadFormEvents write FLoadFormEvents;

    ///  <summary>
    ///  OnBreakpointStop event is fired whenever a breakpoint is reached in a script execution, and the execution goes to
    ///  paused state.
    ///  </summary>
    property OnBreakpointStop: TNotifyEvent read FOnBreakpointStop write FOnBreakpointStop;
  end;

  ///  <remarks>
  ///  TatScripterWatches class holds a collection of TatScripterWatch objects which represent watches in an IDE interface.
  ///  Using a watch you can define its expression and check its value while the script is running/paused. This collection
  ///  is mostly used from a IDE interface, so you will rarely use it directly.
  ///  </remarks>
  TatScripterWatches = class(TOwnedCollection)
  private
    function GetItem(i: integer): TatScripterWatch;
    function Scripter: TatCustomScripter;
  public
    ///  <summary>
    ///  Add method creates and adds a new TatScripterWatch object to the collection.
    ///  </summary>
    function Add: TatScripterWatch;

    ///  <summary>
    ///  Provides indexed access to all TatScripterWatch objects in the collection.
    ///  </summary>
    property Items[i: integer]: TatScripterWatch read GetItem; default;

    ///  <summary>
    ///  Updates the result value of all watches.
    ///  </summary>
    procedure EvaluateAll;
  end;

  ///  <summary>
  ///  TatScripterWatch holds information about a watch in scripter system, for debugging purposes.
  ///  It holds the expression of the watch, calculate its value, among other properties.
  ///  </summary>
  TatScripterWatch = class(TCollectionItem)
  private
    FExpression: string;
    FDebugScript: TatScript;
    FEnabled: boolean;
    FWatchStatus: TWatchStatus;
    FLastResult: TScriptValue;
    procedure SetExpression(const Value: string);
    procedure ScriptDestroyed(Sender: TObject);
    function Watches: TatScripterWatches;
    function Scripter: TatCustomScripter;
    procedure Reset;
    procedure InternalEvaluate(AMachine: TatVirtualMachine);
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;

    ///  <summary>
    ///  Call Evaluate method to update the value of the watch. The value can be retrieved using LastResult property.
    ///  if the watch is not enabled, nothing happens.
    ///  </summary>
    procedure Evaluate;

    ///  <summary>
    ///  Expression property holds the string which contains the expression of the watch to be evaluated. Expression
    ///  can be a variable name, a constant or a complex expression. Examples: 'MyVar', '10 + 20', 'MyArray[c]'.
    ///  </summary>
    property Expression: string read FExpression write SetExpression;

    ///  <summary>
    ///  WatchStatus is a read-only property which contains the current status of the watch. For example, you can use it to check
    ///  if the watch was already evaluated, or if the expression was incorrect (raising a compiling error).
    ///  </summary>
    property WatchStatus: TWatchStatus read FWatchStatus;

    ///  <remarks>
    ///  LastResult contains the calculated value of the watch for the last evaluation. If no evaluation was done before,
    ///  WatchStatus is wsNotEvaluated and LastResult will hold an invalid value. To update the value of LastResult,
    ///  call Evaluate method.
    ///  </remarks>
    property LastResult: TScriptValue read FLastResult;

    ///  <summary>
    ///  Enabled property enables/disables the current watch. If the watch is disabled, calling Evaluate does nothing and
    ///  LastResult is never updated.
    ///  </summary>
    property Enabled: boolean read FEnabled write FEnabled;
  end;

  ///  <summary>
  ///  TatScripts holds a collection of TatScript objects belonging to the scripter. You can add, delete and iterate through the
  ///  available scripts.
  ///  </summary>
  TatScripts = class(TCollection)
  private
    FScripter: TatCustomScripter;
    function GetItem(i: integer): TatScript;
  public
    constructor Create(AScripter: TatCustomScripter);

    ///  <summary>
    ///  Adds a new script. You can then set source code, set language type, compile, execute the script, among other
    ///  actions.
    ///  </summary>
    function Add: TatScript;

    ///  <summary>
    ///  FindByUnitName method searchs for a script which unit name matches AUnitName parameter. It's useful to search
    ///  for script-based libraries, which usually have a non-empty UnitName.
    ///  </summary>
    function FindByUnitName(AUnitName: string): TatScript;

    ///  <summary>
    ///  Provides indexed access to the TatScript objects in the Scripts collection.
    ///  </summary>
    property Items[i: integer]: TatScript read GetItem; default;
  end;

  ///  <remarks>
  ///  TScriptBaseObject is the base class for script classes, a special kind of class declared in script. Script class are defined
  ///  using the $CLASS directive. When this happens, the scripter understands the script as a "class declaration", and all
  ///  methods and properties declared in script are treated as if they were methods and properties of the class.
  ///  You can instantiate such classes from another script. All classes instantiated that way are inherited from TScriptBaseObject class.
  ///  </remarks>
  TScriptBaseObject = class(TPersistent, IScriptBasedObject)
  private
    function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
  private
    FDestroying: boolean;
    FRunScript: TatScript;
    procedure NewObjectInstance(AMachine: TatVirtualMachine);
    function GetRunScript: TatScript;
  protected
    ///  <remarks>
    ///  RunScript retrieves the underlying script object which has the source code for the script-based class. The script routines
    ///  will behave as class methods. Each object instance has its own RunScript. When an object is instantiated, a new RunScript
    ///  is created and its content is copied from the base script where the script-based class was declared.
    ///  </remarks>
    property RunScript: TatScript read GetRunScript write FRunScript;
  public
    destructor Destroy; override;
    procedure BeforeDestruction; override;

    ///  <summary>
    ///  CreateFromScript constructor is called from scripter engine when a script-based object is instantiated by a script code.
    ///  You will not need to call CreateFromScript method nor to instantiate a TScriptBaseObject class directly.
    ///  </summary>
    constructor CreateFromScript(AMachine: TatVirtualMachine); virtual;
  end;

  IScriptBasedForm = interface(IScriptBasedObject)
  ['{3E41EA7D-B868-4F10-A9EF-59D9A39113CE}']
    // SaveProps is name/value pairs (format PropName=Value) used by the
    // script-based form to set properties in the form at runtime after form is instantiated
    function GetSaveProps: TStrings;

    // SaveEvents is name/value pairs (format CompName.PropName=Value) used by the
    // script-based form to set events in the form at runtime after form is instantiated
    function GetSaveEvents: TStrings;

    // The form itself
    function GetForm: TComponent;

    // Methods to get/set the associated run script
    function GetRunScript: TatScript;
    procedure SetRunScript(const Value: TatScript);

    // Event to be called when form is loaded
    procedure SetOnReadState(Handler: TNotifyEvent);
  end;

  TScriptFormLoader = class
  private
    FForm: IScriptBasedForm;
    FLastSearchedMethod: string;
    procedure ReaderFindMethod(Reader: TReader; const MethodName: string; var Address: pointer;
      var Error: boolean);
    procedure ReaderError(Reader: TReader; const Message: string; var Handled: boolean);
    procedure RestoreSavedProps(AfterReading: boolean);
    procedure RestoreSavedEvents;
    procedure ReadStateEvent(Sender: TObject);
  public
    constructor Create(AForm: IScriptBasedForm);
    procedure LoadFormResource(AFormRes: string; ALoadEvents: boolean);
  end;

  TatScriptBasedLibrary = class;

  ///  <summary>
  ///  TatScriptRefactor is an auxiliary class that provides useful methods for safely change a script source code,
  ///  like adding a unit in the uses clause, changing the form directive, among others.
  ///  </summary>
  TatScriptRefactor = class(TPersistent)
  private
    FScript: TatScript;
    FDirtySource: boolean;
    FUpcaseSource: string;
    function GetSource: TStrings;
    function GetUpcaseSource: string;
  protected
    function BuildMethodHint(meth: TatMethod): string; virtual;
    function BuildRoutineHint(routine: TatRoutineInfo): string; virtual;
    function BuildPropertyHint(prop: TatProperty): string; virtual;
    function BuildVariableHint(AVar: TatVariableInfo): string; virtual;

    function IsStatementEndChar(ch: char): boolean; virtual; abstract;
    function IsQualifiedIdentifierChar(ch: char): boolean; virtual;

    ///  <summary>
    ///  Retrieves the source code of the script associated with this refactor.
    ///  </summary>
    property Source: TStrings read GetSource;

    ///  <summary>
    ///  Retrieves the script source code all in upper case.
    ///  </summary>
    property UpcaseSource: string read GetUpcaseSource;

    ///  <summary>
    ///  Retrieve the position of the SubStr in the source code. Search starts from the position indicated by FromPos.
    ///  </summary>
    function SourcePos(SubStr: string; FromPos: integer = 1): integer;
  public
    constructor Create(AScript: TatScript);

    function BuildMethodHeader(meth: TatMethod): string; virtual; abstract;
    function BuildPropertyDeclaration(prop: TatProperty): string; virtual; abstract;
    function BuildPropertyArgs(prop: TatProperty): string;
    function BuildMethodArgs(meth: TatMethod): string;

    ///  <summary>
    ///  Call BeginRefactor before doing any change to script source. This avoids the scripter engine to clear some references
    ///  attached to the script, like events.
    ///  </summary>
    procedure BeginRefactor;

    ///  <summary>
    ///  Call EndRefactor after doing any change to script source using the refactor.
    ///  </summary>
    procedure EndRefactor;

    ///  <remarks>
    ///  Create (or update) the FORM directive in the script giving the AFormClass (form class name)
    ///  and AFileName (form file name). For example, the code below.
    ///  <code>
    ///  UpdateFormHeader('TMyForm', 'myform.dfm');
    ///  </code>
    ///  will create (or update) the form directive in the script as following (in this case,
    ///  the example is in Basic syntax).
    ///  <code>
    ///  #FORM TMyForm, myform.dfm
    ///  </code>
    ///  </remarks>
    procedure UpdateFormHeader(AFormClass, AFileName: string); virtual;

    ///  <remarks>
    ///  Declare a routine named ProcName in source code, and return the line number
    ///  of the declared routine. The line number returned is not the line where the
    ///  routine is declared, but the line with the first statement. For example, in pascal,
    ///  it returns the line after the "begin" of the procedure.
    ///  </remarks>
    function DeclareRoutine(ProcName: string): integer; overload;

    ///  <remarks>
    ///  Declare a routine in source code, and return the line number
    ///  of the declared routine. The line number returned is not the line where the
    ///  routine is declared, but the line with the first statement. For example, in pascal,
    ///  it returns the line after the "begin" of the procedure.
    ///  This method uses the AInfo property to retrieve information about the procedure
    ///  to be declared. Basicaly it uses AInfo.Name as the name of routine to be declared,
    ///  and also uses AInfo.Variables to declare the parameters. The following code is an exmaple.
    ///  <code>
    ///  AInfo.Name := 'MyRoutine';
    ///  AInfo.IsFunction := true;
    ///  AInfo.ResultTypeDecl := 'string';
    ///  With AInfo.Variables.Add do
    ///  begin
    ///  VarName := 'MyParameter';
    ///  Modifier := moVar;
    ///  TypeDecl := 'integer';
    ///  end;
    ///  With AInfo.Variables.Add do
    ///  begin
    ///  VarName := 'SecondPar';
    ///  Modifier := moNone;
    ///  TypeDecl := 'TObject';
    ///  end;
    ///  ALine := Script.DeclareRoutine(AInfo);
    ///  </code>
    ///  The script below will declare the following routine (in pascal).
    ///  <code>
    ///  function MyRoutine(var MyParameter: integer; SecondPar: TObject): string;
    ///  </code>
    ///  </remarks>
    function DeclareRoutine(AInfo: TatRoutineInfo): integer; overload; virtual;

    ///  <remarks>
    ///  Adds a unit named AUnitName to the list of used units in the uses clause.
    ///  If the unit is already being used, nothing is done. If the uses clause is not
    ///  present in the script, it is included, like the following code.
    ///  <code>
    ///  AddUsedUnit('Classes');
    ///  </code>
    ///  You can also include several units at once by separating them with commas.
    ///  <code>
    ///  AddUsedUnit('Classes,Graphics,Controls');
    ///  </code>
    ///  </remarks>
    procedure AddUsedUnit(AUnitName: string); virtual;

    ///  <summary>
    ///  Returns the script object which the refactor belongs to.
    ///  </summary>
    property Script: TatScript read FScript;
  end;

  TRefactorClass = class of TatScriptRefactor;

  {$IFDEF NEXTGEN}
  TBreakPointList = class(TObjectList<TatScriptBreakPoint>)
  end;
  {$ELSE}
  TBreakPointList = class(TObjectList)
  end;
  {$ENDIF}

  ///  <summary>
  ///  TatScriptBreak contains information about a breakpoint set in the script. Use this class to programatically
  ///  set a breakpoint in the script source code for debugging purposes.
  ///  </summary>
  TatScriptBreak = class(TCollectionItem)
  private
    FLine: integer;
    FBreakList: TBreakPointList;
    FAutoDestroy: boolean;
    function Script: TatScript;
    procedure SetLine(const Value: integer);
    procedure UpdateBreakPoints;
    procedure BreakpointDestroyed(ABreakPoint: TatScriptBreakPoint);
    procedure RemoveBreakPoints;
    procedure TemporaryBreakProc;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;

    ///  <summary>
    ///  Use Line property to get or set the line number in the source code in which the breakpoint will be set.
    ///  </summary>
    property Line: integer read FLine write SetLine;

    ///  <summary>
    ///  AutoDestroy is a read-only property. If it's true, it indicates that the breakpoint will be removed when
    ///  script execution stops at it. In other words, it will only stop once in this breakpoint.
    ///  </summary>
    property AutoDestroy: boolean read FAutoDestroy;
  end;

  ///  <summary>
  ///  TatScriptBreaks holds a collection of all breakpoints set in the script. Use this collection to programatically add, edit
  ///  and remove breakpoints in script source code.
  ///  </summary>
  TatScriptBreaks = class(TOwnedCollection)
  private
    function GetItem(Index: integer): TatScriptBreak;
    function Script: TatScript;
    procedure UpdateAll;
  public
    ///  <summary>
    ///  Adds (if it doesn't exist) or removes (if it exists) a breakpoint at the line specified by ALine.
    ///  </summary>
    procedure ToggleBreak(ALine: integer);

    ///  <summary>
    ///  Retrieves the TatScriptBreak object related to the breakpoint set at the line specified by ALine. If no breakpoint
    ///  is set at that line, FindByLine returns nil.
    ///  </summary>
    function FindByLine(ALine: integer): TatScriptBreak;

    ///  <summary>
    ///  Add a new TatScriptBreak object in the TatScriptBreaks collection. You should not usually use Add method.
    ///  Use ToggleBreak method instead.
    ///  </summary>
    function Add: TatScriptBreak;

    ///  <summary>
    ///  Provides indexed access to all breakpoints set in the script.
    ///  </summary>
    property Items[Index: integer]: TatScriptBreak read GetItem; default;
  end;

  {$IFDEF NEXTGEN}
  TatScriptList = class(TObjectList<TatScript>)
  end;
  {$ELSE}
  TatScriptList = class(TObjectList)
  end;
  {$ENDIF}

  ///  <remarks>
  ///  TatScript object contains all information related to a script in the scripter component. The scripts are kept
  ///  in the Scripts property which is a TatScripts collection.
  ///  TatScript allows you to set the source code of the script using SourceCode property. Several methods are provided
  ///  for clearing the script (Clear), compiling (Compile), executing (Execute). Information about the compiled script
  ///  is also provided in the ScriptInfo property which holds the list of declared routines, global variables, etc.
  ///  Many other properties and methods related to a single script are available.
  ///  </remarks>
  TatScript = class(TCollectionItem)
  private
    FScripter: TatCustomScripter;
    FParser: TatSyntaxParser; // referência à sintaxe da linguagem
    FVirtualMachines: TatVirtualMachines; // máquinas virtuais para execução de scripts
    FVirtualMachine: TatVirtualMachine; // máquina virtual para execução do script
    { auxiliary code generation variables }
    FStack: array[TStackType] of pStackElement; // auxiliar stack
    FCodeLine: integer; // índice para a instrução corrente na geração de código
    FFirstLabelSpec: pLabelSpec; // ponteiro para o primeiro rótulo gerado
    FLastLabelSpec: pLabelSpec; // ponteiro para o último rótulo gerado
    FCurrentRoutine: TatRoutineInfo;
    FIsDebugScript: boolean;
    FDebugScriptMainRoutine: TatRoutineInfo;
    // para evitar a declaração de um novo Main quando compilar um debug script
    { script source information }
    FSourceCode: TStrings;
    { compiled script runtime information }
    FFirstInstruction: pSimplifiedCode; // primeiro instrução executável
    FLastInstruction: pSimplifiedCode; // última instrução executável
    FScriptInfo: TatScriptInfo; // script symbols information
    FCompiled: boolean; // indicates that last compilation was successful
    FSilentCompiled: boolean; // indicates that scripter was compiled silently
    FSolvedAddressing: boolean; // indica se o enderecamento absoluto ja foi resolvido
    FExpandedDebugInfo: boolean;
    // indica que o campo vDebugInfo já contem linha e coluna do programa-fonte
    FUsedUnits: TatUsedUnits;
    FCounterInit: integer;
    // inicializador de contadores para geração de variáveis internas (ver DebugExecute)
    FOnDestroy: TNotifyEvent; // para resolução de links internos (como nos DebugWatches)
    FRollbackSourceCode: boolean;
    FLibraries: TList;
    FSilentCompilation: boolean;
    FFileName: string;
    FUnitName: string;
    FLoadedDLL: boolean;
    FDefInstances: TatObjects;
    FIntInstance: TatObject;
    FScriptForm: TBaseScriptForm;
    FDesignScriptForm: TBaseScriptForm;
    FOriginalForm: TBaseScriptForm;
    FRefactor: TatScriptRefactor;
    FRefactorClass: TRefactorClass;
    FDesignFormResource: string;
    FCodeStream: TStream;
    FBreaks: TatScriptBreaks;
    FOriginalScript: TatScript;
    FDerivedScripts: TatScriptList;
    FCompiling: boolean;
    FOriginalObject: TScriptBaseObject;
    FClearingScript: boolean;
    FRefactoring: integer;
    procedure InternalCompile(Silent: boolean);
    procedure DisposeDLL;
    procedure RemoveAttachedEvents(RemoveAll: boolean);
    function GetFormFileAsString(AFormFile: string): string;
    procedure InternalSaveCodeToStream(AStream: TStream);
    procedure SetCompiled(const Value: boolean);
    function CheckRegisteredAsLibrary(AScripter: TatCustomScripter;
      var ALib: TatScripterLibrary): boolean;
    procedure SetOriginalScript(AScript: TatScript);
    procedure DoBreakpointStop;
    function _FindClass(idx: integer; AName: string): TatClass;
    function _FindMethod(AClass: TatClass; idx: integer; AName: string): TatMethod;
    function _FindProperty(AClass: TatClass; idx: integer; AName: string): TatProperty;
    procedure InternalLoadCodeFromStream(AStream: TStream; AUseBehavior: boolean);
    procedure GetRowColFromInst(Inst: pSimplifiedCode; var row, col: integer);
    function DefineProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TMachineProc;
      APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
      : TatProperty;
    procedure GetSelfBaseObjectProc(AMachine: TatVirtualMachine);
    procedure CheckMachine;
    procedure CheckScriptFormClass;
  protected
    procedure DoUnknownElement(var Context: TElementContext);
    procedure CompileError(msg: string; debuginfo: integer); overload;
    procedure CompileError(msg: string; row, col: integer); overload;

    procedure StackPush(StackType: TStackType; x: TScriptValue);
    procedure StackPushDelimitter(StackType: TStackType);
    function EmptyStack(StackType: TStackType): boolean;
    function StackPop(StackType: TStackType): TScriptValue;
    function StackPopAsString(StackType: TStackType): string;
    function StackPopAsDouble(StackType: TStackType): double;
    function StackPopAsInt(StackType: TStackType): integer;
    function StackPopAsBool(StackType: TStackType): boolean;
    function StackView(StackType: TStackType): TScriptValue;
    function StackViewAsInt(StackType: TStackType): integer;
    function StackDelimitterFound(StackType: TStackType): boolean;
    function GetStack(st: TStackType): pStackElement;
    procedure ClearStacks;

    function NewLabelSpec(Name: string): pLabelSpec;
    function FindLabelSpec(Name: string): pLabelSpec;
    function RegisterReference(Name: string): integer;
    procedure SolveReference(LabelSpec: pLabelSpec);
    procedure DefineReferenceAddress(Name: string);
    procedure ClearLabelSpecs;
    procedure SolveUndefinedReferences;
    function RegisterVariableReference(id: string): TatVariableInfo;
    function DeclareVariable(AName: string; AArgIndex: integer = -1;
      AModifier: TatArgumentModifier = moNone; AGlobal: boolean = false; ASourcePos: integer = -1)
      : TatVariableInfo;
    function AppendInstruction(i: TInstruction): pSimplifiedCode; overload;
    function RemoveLastInstruction: pSimplifiedCode;
    procedure AppendInstruction(AInstruction: pSimplifiedCode); overload;
    procedure OptimizeStoreVar(AVar: TatVariableInfo; AIgnoreConstant: boolean = false);
    procedure OptimizeVarTest(ACaseVarIndex: integer; ACaseVarName, AJumpLabel: string;
      ACondition: boolean);
    procedure SetSourceCode(Value: TStrings);
    function ErrorComplement(APos: integer): string;
    procedure SourceCodeChange(Sender: TObject);
    procedure DisposeCode(var Code: pSimplifiedCode);

    procedure RelativeMethodRef(AMethod: TatMethod; AInst: pSimplifiedCode);
    procedure RelativeGetterRef(AProperty: TatProperty; AInst: pSimplifiedCode);
    procedure RelativeSetterRef(AProperty: TatProperty; AInst: pSimplifiedCode);

    property CodeLine: integer read FCodeLine write FCodeLine;
    property LastInstruction: pSimplifiedCode read FLastInstruction write FLastInstruction;
    property CurrentRoutine: TatRoutineInfo read FCurrentRoutine write FCurrentRoutine;
    property CounterInit: integer read FCounterInit write FCounterInit;
    property DebugScriptMainRoutine: TatRoutineInfo read FDebugScriptMainRoutine
      write FDebugScriptMainRoutine;
    property IsDebugScript: boolean read FIsDebugScript write FIsDebugScript;

    ///  <summary>
    ///  RefactorClass property indicates which descendant of TatScriptRefactor will be used as Refactor object.
    ///  Used only when creating descendants of TatScript.
    ///  </summary>
    property RefactorClass: TRefactorClass read FRefactorClass write FRefactorClass;

    ///  <remarks>
    ///  Override EncodeSingleAssign to provide a standard way to represent a single function
    ///  in a script. Commonly used in debugger watches. WARNING: EncondeSingleAssign must assure
    ///  that the variable is declared as local.
    ///  </remarks>
    function EncodeSingleAssign(AVarName, AExpression: string): string; virtual; abstract;

    function DeclareEventHandler(AProcName: string): integer; virtual;

    function SelfRegisterAsLibrary(AScripter: TatCustomScripter; AName: string; AClassRef: TClass;
      AClassName: string; ADefault: boolean; AddMethod: boolean): TatScripterLibrary; overload;

    procedure CompileForm(AFormClassName, AFormFile: string);
    procedure RegisterForm;
    procedure UnregisterForm;
    procedure CompileScriptClass(AClassName: string);
    procedure RegisterScriptClass;
    procedure UnregisterScriptClass;
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;

    ///  <summary>
    ///  Raises a runtime error with the specified message
    ///  </summary>
    procedure RuntimeError(msg: string);

    ///  <remarks>
    ///  Use Clear method to clear all info about script compilation. When Clear method is called, the Compiled property is
    ///  set to false, all meta-information in ScriptInfo is erased, events attached to the script are removed, and other
    ///  clean up operations. Please note that Clear method only refers to compilation information. It doesn't clear the source
    ///  code, or other information like unit name, etc.
    ///  You cannot clear a script if it is running.
    ///  </remarks>
    procedure Clear; virtual;

    ///  <remarks>
    ///  Call Compile method to compile the current script source code. After a successful compilation is performed, the Compiled
    ///  property is set to true, and the compiled code is saved into a internal stream in memory for further execution.
    ///  SilentCompiled property is also set to true after a sucessful compilation.
    ///  If compilation fails, an exception is raised.
    ///  </remarks>
    procedure Compile; virtual;

    ///  <remarks>
    ///  Call SilentCompile method to compile the current script source code in silent mode. Silent mode means that if the compilation
    ///  fails, no exception is raised, and still the scripter will save information about the compilation until the point it was
    ///  succesful. SilentCompile is useful when you want to extract meta information from the script (declared routines, variables, etc.)
    ///  without worrying about if the script is compilable or not.
    ///  SilentCompiled property is always set to true when SilentCompile is called.
    ///  Compiled property is always set to false, regardless if the compilation was sucessful or not.
    ///  </remarks>
    procedure SilentCompile;

    ///  <summary>
    ///  ExpandDebugInfo is a deprecated method. It was used to update debug information in the compiled p-code of the script.
    ///  Now this is done automatically and you don't need to call it anymore.
    ///  </summary>
    procedure ExpandDebugInfo(RequiresCompilation: boolean = True);

    ///  <remarks>
    ///  Use GetRowColFromSource to retrieve the row and column values of a specified position in the source code.
    ///  The position is provided in APos variable, and is considered as if the source code was a single string, including
    ///  special characters like #13 and #10. The calculated row and column values are set in row and col parameters.
    ///  </remarks>
    procedure GetRowColFromSource(APos: integer; var row, col: integer);

    ///  <summary>
    ///  LoadCodeFromFile loads a compiled p-code from the file specified by AFileName. It calls LoadCodeFromStream internally
    ///  to perform the loading operation. See LoadCodeFromStream method for more details.
    ///  </summary>
    procedure LoadCodeFromFile(AFileName: string);

    ///  <summary>
    ///  SaveCodeToFile saves a compiled p-code to the file specified by AFileName. It calls SaveCodetToStream internally
    ///  to perform the saving operation. See SaveCodetToStream method for more details.
    ///  </summary>
    procedure SaveCodeToFile(AFileName: string);

    ///  <remarks>
    ///  Use LoadCodeFromStream to load a compiled script p-code previously saved with SaveCodeToStream. The stream must be
    ///  specified by AStream parameter. After calling LoadCodeFromStream the compiled p-code is loaded into the internal
    ///  memory stream when the script is executed, no compilation is performed. The meta information about the script is also
    ///  loaded (declared routines, variables, used units, etc.
    ///  </remarks>
    procedure LoadCodeFromStream(AStream: TStream); virtual;

    ///  <remarks>
    ///  Use SaveCodeToStream to save a compiled script p-code to the stream specified by AStream. SaveCodeToStream does not automatically
    ///  compile the script, so you must do it previously before saving the code.
    ///  You can save the compiled p-code to a stream in order to load it later using LoadCodeFromStream method. Saving and loading p-code
    ///  prevents recompilation of the script, making it faster for script execution. SaveCodeToStream also saves the meta information
    ///  of the script (ScriptInfo object, with all declared routines, methods, etc.).
    ///  Form resources are also saved, so you don't need the form file when loading the code.
    ///  You must be aware that the script might use classes, methods and properties registered in the scripter. Those are not saved in the
    ///  compiled p-code, so when you later load the code, you must be sure that the same used classes, methods
    ///  and properties are registered in the scripter otherwise the loaded code might not execute properly.
    ///  </remarks>
    procedure SaveCodeToStream(AStream: TStream); virtual;

    ///  <summary>
    ///  Use IsRegisteredAsLibrary to check if the script is registered as a script-based library in the scripter component
    ///  specified by AScripter component.
    ///  </summary>
    function IsRegisteredAsLibrary(AScripter: TatCustomScripter): boolean;

    ///  <remarks>
    ///  SelfRegisterAsLibrary method registers the script as a library in the scripter component specified by AScripter.
    ///  This means that all routines and global variables in the script (except those declared as private) will be acessible and
    ///  can be called from any other script in the specified scripter component. If the current script is not compiled, it will be
    ///  automatically compiled. If AName is not empty, the methods and variables can also be accessible prefixed with the AName, for
    ///  example: MyLibrary.MyMethod;
    ///  The function result value will be the instance of the library object created and registered in the scripter.
    ///  </remarks>
    function SelfRegisterAsLibrary(AScripter: TatCustomScripter; AName: string = '')
      : TatScripterLibrary; overload;

    ///  <summary>
    ///  SelfRegisterAsLibrary method registered the current script as a library in the scripter component that owns this script.
    ///  </summary>
    function SelfRegisterAsLibrary(AName: string = ''): TatScripterLibrary; overload;

    ///  <remarks>
    ///  Use SelfUnregisterAsLibrary to remove the script as a registered library in the scripter component specified by AScripter.
    ///  If the script was previously registered using SelfRegisterAsLibrary, you can use this method to remove it. All routines
    ///  and global variables of the script will not be accessible anymore from other scripts.
    ///  </remarks>
    procedure SelfUnregisterAsLibrary(AScripter: TatCustomScripter; AName: string = ''); overload;

    ///  <summary>
    ///  Use SelfUnregisterAsLIbrary to remove the script as a register library previously registered by SelfRegisterAsLibrary.
    ///  The script will be removed from the scripter component which owns the script.
    ///  </summary>
    procedure SelfUnregisterAsLibrary(AName: string = ''); overload;

    ///  <summary>
    ///  Calls Scripter.LoadLibrary method. See TatCustomScriper.LoadLibrary method for more information.
    ///  </summary>
    function LoadLibrary(ALibraryName: string; ADefault: boolean = True): TatScripterLibrary;

    ///  <remarks>
    ///  Call UsesObject to access the methods and properties of the object directly from script without using an object name.
    ///  UsesObject behaves exactly like TatCustomScripter.UsesObject (see this method documentation for more information).
    ///  The only difference is that while UsesObject of the scripter makes the object accessible for all scripts in the scripter
    ///  component, this script-only UsesObject method only registered the object for this specified script. Other scripts will
    ///  not be able to access it.
    ///  </remarks>
    function UsesObject(AObject: TObject; AName: string = ''; AClassName: string = ''): TatClass;

    ///  <remarks>
    ///  UnuseObject removes an used object previously registered with UsesObject method. Instead of passing the object instance,
    ///  you must pass the class name used to register the object when calling UsesObject. If no class name was specified when
    ///  calling UsesObject, then the class name will be the name of the object class.
    ///  </remarks>
    procedure UnuseObject(AClassName: string);

    ///  <remarks>
    ///  Register the object specified by AObject to be acessible from this script. The object will be acessible by the name specified
    ///  by AName. Published properties of component will also be automatically available for reading/writing.
    ///  This method is similar to TatCustomScripter.AddObject method, but while the latter allows the object to accessible from
    ///  all scripts in the scripter component, this one makes the object accessible from this script only.
    ///  </remarks>
    procedure AddObject(AName: string; AObject: TObject);

    ///  <summary>
    ///  Removes an object previously registered with AddObject method. It can remove objects registered by TatCustomScripter.AddObject
    ///  method. Those are global to all scripts and can't be individually removed from a specific script.
    ///  </summary>
    procedure RemoveObject(AName: string);

    ///  <remarks>
    ///  UsedUnits holds a collection of all units (libraries) used by the script in the uses/imports clause. Only libraries declared
    ///  in the script source code will be available here, libraries registered programatically with methods like AddLibrary,
    ///  SelfRegisterAsLibrary, etc., will not be listed.
    ///  </remarks>
    property UsedUnits: TatUsedUnits read FUsedUnits;

    ///  <summary>
    ///  VirtualMachine property provides access to the script virtual machine. The virtual machine is the object which effectively
    ///  executes the compiled p-code. See TatVirtualMachine class for more info.
    ///  </summary>
    property VirtualMachine: TatVirtualMachine read FVirtualMachine write FVirtualMachine;

    ///  <summary>
    ///  Not used, current version only allows one virtual machine per script.
    ///  </summary>
    property VirtualMachines: TatVirtualMachines read FVirtualMachines;

    ///  <summary>
    ///  Use Scripter property to get access to the TatCustomScripter component that owns the script.
    ///  </summary>
    property Scripter: TatCustomScripter read FScripter;

    ///  <remarks>
    ///  SourceCode property holds the current source code for the script. Executing a script is as simple as setting the
    ///  SourceCode property and calling Execute method.
    ///  You cannot change SourceCode if the script is running. An exception will be raised and change will not be performed.
    ///  When you change the source code of the script, the script is cleared (see Clear method) and a new compilation is needed
    ///  before executing the script.
    ///  </remarks>
    property SourceCode: TStrings read FSourceCode write SetSourceCode;

    ///  <remarks>
    ///  ScriptInfo property gives access to the TatScriptInfo object which holds meta-information about the script. In ScriptInfo
    ///  you can check declared methods, variables, and other information about the script source code.
    ///  ScriptInfo is empty even after you set script source code, information is only available after a compilation.
    ///  Silent compilation (SilentCompile method) also fills information in ScriptInfo object.
    ///  </remarks>
    property ScriptInfo: TatScriptInfo read FScriptInfo;

    ///  <remarks>
    ///  Use Compiled property to check if the script is already compiled and ready to execute. You can also set Compiled property
    ///  value to true or false. Setting to true compiles the script (if it's not already compiled), and setting to false clears
    ///  the script.
    ///  </remarks>
    property Compiled: boolean read FCompiled write SetCompiled;

    ///  <summary>
    ///  Use SilentCompiled property to check if the script was compiled in silent mode (a call to SilentCompile method was
    ///  performed). Setting SilentCompiled to true doesn't perform a silent compilation, it only sets the property value to true.
    ///  </summary>
    property SilentCompiled: boolean read FSilentCompiled write FSilentCompiled;

    ///  <summary>
    ///  FirstInstruction contains the pointer to the very first p-code instruction of the compiled script. The virtual machine
    ///  uses this property to start executing the compiled p-code. You will not need to use this property.
    ///  </summary>
    property FirstInstruction: pSimplifiedCode read FFirstInstruction;

    ///  <summary>
    ///  ExpandedDebugInfo is true after ExpandDebugInfo method is called. This property is rarely used, since scripter expands
    ///  the debug info automatically when needed.
    ///  </summary>
    property ExpandedDebugInfo: boolean read FExpandedDebugInfo;

    ///  <summary>
    ///  Provides access to the parser object that parses the script source code.
    ///  </summary>
    property Parser: TatSyntaxParser read FParser;

    ///  <remarks>
    ///  DefInstances holds a list of objects which are treated by script as default objects. A default object is
    ///  an object which methods and properties are directly accessible from the script without the need to prepend the method
    ///  name with the object name. For example, if an object MyObject has the method MyMethod, and it is added as a default
    ///  instance in DefaultInstances property, you can access the method directly the following way.
    ///  <code>
    ///  MyMethod;
    ///  </code>
    ///  You will rarely add objects directly to DefInstances, you should use TatScript.UsesObject method instead.
    ///  </remarks>
    property DefInstances: TatObjects read FDefInstances;

    ///  <summary>
    ///  IntInstance is the first object added automatically to the script using UsesObject. It's used internally by
    ///  the scripter.
    ///  </summary>
    property IntInstance: TatObject read FIntInstance;

    ///  <summary>
    ///  Refactor property gives you access to the TatScriptRefactor object that allows refactoring operation in the script
    ///  source code. See TatScriptRefactor for more information.
    ///  </summary>
    property Refactor: TatScriptRefactor read FRefactor;

    ///  <remarks>
    ///  When compiling a form script, the compiler needs to load the form file in order to check which controls
    ///  are on the form. If DesignScriptForm is set to a valid TScriptForm, then the compiler does not load the form file,
    ///  but instead uses the instantiated form specified by DesignScriptForm to retrieve the names of controls.
    ///  This property should be used only for internal purposes, like the IDE environment.
    ///  </remarks>
    property DesignScriptForm: TBaseScriptForm read FDesignScriptForm write FDesignScriptForm;

    ///  <remarks>
    ///  When compiling a form script, the compiler needs to load the form file to retrieve the form resource. The form
    ///  resource is saved "inside" the script in the property ScriptInfo.FormResource, so that the form resource is saved
    ///  when the script is saved as a pcode. If DesignFormResource is set to a valid form resource, then the
    ///  compiler does not load the form file, but instead uses the DesignFormResource as the valid form resource to be saved
    ///  with the compiled script.
    ///  </remarks>
    property DesignFormResource: string read FDesignFormResource write FDesignFormResource;

    ///  <remarks>
    ///  UnitName is used for script-based libraries. If a script adds "uses UNIT", the compiler
    ///  searches for files named "UNIT", and also for scripts inside Scripts collection which UnitName
    ///  matches "UNIT". There is UnitName property in both TatScript and TatScriptInfo classes.
    ///  Both are used for the same purpose, the difference is that TatScriptInfo.UnitName is only
    ///  filled after script is compiled, and it's also saved with compiled code. So, you must set
    ///  TatScript.UnitName if you want the unit to be found *before* it's compiled.
    ///  See TatCustomScripter.LoadLibrary for more info on libraries.
    ///  </remarks>
    {$WARNINGS OFF}
    property UnitName: string read FUnitName write FUnitName;

    ///  <remarks>
    ///  Breaks property provides access to a TatScriptBreaks collection which holds the breakpoints for the script.
    ///  The different from Breaks to VirtualMachine.BreakPoints is that the latter is a low-level breakpoint
    ///  collection based on p-code, and should be rarely used. Breaks property, instead, is a higher level breakpoints collection
    ///  based on lines. Use Breaks instead of VirtualMachine.Breakpoints for better control of debugging and breakpoints.
    ///  </remarks>
    property Breaks: TatScriptBreaks read FBreaks;

    ///  <summary>
    ///  OnDestroy event is fired when the script object is destroyed.
    ///  </summary>
    property OnDestroy: TNotifyEvent read FOnDestroy write FOnDestroy;

    ///  <summary>
    ///  If the script was loaded as a library from a file, contains the original file name
    ///  where the script was loaded from.
    ///  </summary>
    property FileName: string read FFileName;
  end;

  ///  <remarks>
  ///  TatVirtualMachines is a collection of virtual machines. Currently this collection holds only one virtual machine, since
  ///  a script can't have more than one virtual machine.
  ///  You should not use this collection.
  ///  </remarks>
  TatVirtualMachines = class(TOwnedCollection)
  private
    function GetItems(i: integer): TatVirtualMachine;
  public
    ///  <summary>
    ///  Adds a new virtual machine. Should not be used, the script object already creates the first and only virtual machine
    ///  it needs
    ///  </summary>
    function Add: TatVirtualMachine;

    ///  <summary>
    ///  Provides indexed access to existing virtual machines.
    ///  </summary>
    property Items[i: integer]: TatVirtualMachine read GetItems; default;
  end;

  ///  <remarks>
  ///  TatVirtualMachine object is used to execute a script compiled p-code. After the script is compiled, the compiled p-code
  ///  is saved in the memory and the script holds a reference to it. When the script is then executed, it uses the virtual machine
  ///  object to execute the code. The virtual machine then uses the compiled p-code in memory to run the script.
  ///  During script execution, several internal variables are updated by virtual machine. Specially when Delphi interoperation is
  ///  performed (accessing Delphi methods, properties, variables, etc.), the information kept by virtual machine is useful.
  ///  For example, the current object being accessed, the parameters passed to the current subroutine being executed, and so on.
  ///  Those information are useful for the methods that implement Delphi interoperability (those methods call the real Delphi
  ///  methods using the information provided by the virtual machine).
  ///  </remarks>
  TatVirtualMachine = class(TCollectionItem)
  private
    FScript: TatScript; // referencia o script correspondente
    FScripter: TatCustomScripter;
    { scripter configuration }
    FOnExecHook: TNotifyEvent;
    FOnPauseChanged: TNotifyEvent;
    FOnRunningChanged: TNotifyEvent;
    { compile time variables }
    FCurrentObject: TObject; // in-CallProc associated object
    FCurrentClass: TatClass; // in-CallProc associated class
    {$IFDEF DELPHI2010_LVL}
    //FCurrentRecordName: string;
    {$ENDIF}
    {$IFDEF MSWINDOWS}
    FCurrentOleObject: Variant; // in-CallProc associated variant interface
    {$ENDIF}
    { compiled script runtime information }
    FProcStack: array [0 .. StackSize - 1] of TStackValue; // pilha de execução
    FStackTop: integer; // índice de topo da pilha
    FStackBase: integer; // índice de base da pilha
    FInputBase: integer; // índice de base dos argumentos de entrada
    FOutputBase: integer; // índice de base dos resultados de saída
    FInputOffset: integer; // número de variáveis de entrada
    FOutputOffset: integer; // número de variáveis de saída
    FCurrentInputArgBase: integer; // in-CallProc input argument index
    FCurrentArrayIndexBase: integer; // in-CallProc input array index base
    FCurrentOutputArgIndex: integer; // in-CallProc output argument index
    FNextInstruction: pSimplifiedCode; // ponteiro para a próxima instrução a ser executada
    FCurrentInstruction: pSimplifiedCode; // ponteiro para a instrução corrente na execução
    FLastExceptionMessage: string; // última mensagem de exceção ocorrida
    FLastExceptionLine: integer;
    FLastExceptionCol: integer;
    FLastExceptionHelpContext: integer; // último contexto de ajuda de execção ocorrida
    FLastExceptionClassName: string; // último nome de classe de execção ocorrida
    FPrepareInstruction: pSimplifiedCode; // Current runtime process (prepare instruction pointer)
    FBreakPoints: TatScriptBreakPoints; // runtime break point collection
    FHalted: boolean; // sinaliza que um Halt foi processado
    FRunning: boolean; // indica que o script está rodando ou está pausado
    FPaused: boolean; // indica que o script está pausado
    FCallExecHookEvent: boolean;
    FComputeProcs: array [TInstruction] of TGenericProc; // métodos semânticos para as instruções

    FMainBegin: pSimplifiedCode;
    // aponta para a instrução de preparação do bloco principal (quando script já inicializado)
    FInitialStackTop: integer;
    // points to the initial stack top position (only valid if FInitialized is true)

    FDebugWatches: TatDebugWatches; // watches para depuração
    FStopInstruction: pSimplifiedCode;
    FInitialized: boolean;
    // indicates if the initialization block of the script was executed (mainly for global constants initialization)
    FInTryExcept: integer; // indicates if execution flow is in a try..except block
    FFastSolving: boolean;

    FAutoPause: boolean;
    FAutoPauseCurLine: integer;

    FTempStack: array[0..TempStackSize - 1] of TStackValue;
    FTempStackTop: integer;
    FDebugStackLevel: integer;
    FMaxPauseStackLevel: integer;
    procedure CheckAutoPause; {$IFDEF DELPHI2006_LVL}inline;{$ENDIF}
    { execution control }
    function ExecProcess(ParamCount: integer): integer;
    { semântica }
    procedure _GlobalPrepare;
    procedure _Prepare;
    procedure _PushDouble;
    procedure _PushVar;
    procedure _PushIdxVar;
    procedure _PushVarByRef;
    procedure _PushString;
    procedure _PushOutput;
    procedure _PushConst;
    procedure _Duplicate;
    procedure _Duplicate2;
    procedure _Drop2;
    procedure _Swap;
    procedure _OperNE;
    procedure _OperGE;
    procedure _OperLE;
    procedure _OperEqual;
    procedure _OperGreater;
    procedure _OperLess;
    procedure _OperAdd;
    procedure _OperConcat;
    procedure _OperSub;
    procedure _OperOr;
    procedure _OperXor;
    procedure _OperMul;
    procedure _OperSlash;
    procedure _OperDiv;
    procedure _OperMod;
    procedure _OperAnd;
    procedure _OperShl;
    procedure _OperShr;
    procedure _OperExp;
    procedure _OperNeg;
    procedure _OperNot;
    procedure _JumpIfFalse;
    procedure _JumpIfTrue;
    procedure _Jump;
    procedure _StoreVar;
    procedure _StoreIdxVar;
    procedure _StoreVarInteger;
    procedure _StoreVarDouble;
    procedure _StoreVarString;
    procedure _StoreVarConst;
    procedure _CopyVar;
    procedure _StoreVarRef;
    procedure _StoreIdxVarRef;
    procedure _StoreVarRefInteger;
    procedure _StoreVarRefDouble;
    procedure _StoreVarRefString;
    procedure _StoreVarRefConst;
    procedure _CopyVarRef;
    procedure _Call;
    procedure _Ret;
    procedure _StoreInput;
    procedure _ExecFun;
    procedure _PushInteger;
    procedure _TryFinally;
    procedure _TryExcept;
    procedure _CallProc;
    procedure _CallClassProc;
    procedure _BreakPoint;
    procedure _VarTest;
    procedure _VarTestInteger;
    procedure _VarTestDouble;
    procedure _VarTestString;
    procedure _VarTestVar;
    procedure _Abort;
    procedure _ArrayOf;
    procedure _CastClass;
    procedure _OperIs;
    procedure _PushClass;
    procedure _WithObject;
    procedure _StoreGlobalVar;
    procedure _StoreGlobalIdxVar;
    procedure _PushGlobalVar;
    procedure _PushGlobalIdxVar;
    procedure _PushGlobalVarByRef;
    procedure _TestIfFalse;
    procedure _TestIfTrue;
    procedure _SaveStackValue;
    procedure _LoadStackValue;
    { Undefined _CallProc }
    procedure UndefinedGetterProc;
    procedure UndefinedSetterProc;
    procedure UndefinedMethodProc;
    { internal }
    procedure SetRunning(const Value: boolean);
    procedure SetPaused(const Value: boolean);
    function HandleScriptRunException(ex: Exception): boolean;
    procedure DoExecHook;
    function GetStackContentAsString: string;

    function GetVariantArrayElement(v: Variant; ADim: integer): Variant;
    {$IFDEF NEWSTACK}
    function GetValueArrayElement(v: TValue; ADim: integer): TValue;
    {$ENDIF}
    function GetScriptArrayElement(v: TScriptValue; ADim: integer): TScriptValue;

    function SetVariantArrayElement(v: Variant; ADim: integer; AValue: Variant): Variant;
    {$IFDEF NEWSTACK}
    function SetValueArrayElement(v: TValue; ADim: integer; AValue: TValue): TValue;
    {$ENDIF}
    function SetScriptArrayElement(v: TScriptValue; ADim: integer; AValue: TScriptValue): TScriptValue;

    function InternalExecuteSubroutine(AInstruction: pSimplifiedCode;
      AInputParamCount: integer = 0): TScriptValue;
    procedure CompileDebugScript(AScript: TatScript);
    procedure ExecuteDebugScript(AScript: TatScript; AScripterWatch: TatScripterWatch = nil;
      ADebugWatch: TatDebugWatch = nil);

    procedure CheckHalted;
    procedure InitializeScript(ADoBeforeExecute: boolean);
    function TranslateClass(AValue: TScriptValue): TClass;
    function GetOnDebugHook: TNotifyEvent;
    procedure SetOnDebugHook(const Value: TNotifyEvent);
    function GetScriptObjectClassName(AObject: TObject): string;
    function GetCurrentClass: TatClass;
    function IntExecuteSubroutine(ALabel: string;
      const Input: array of TScriptValue): TScriptValue;
  protected
    procedure PerformShowMessage(const msg: string); virtual; abstract;
    function PerformInputQuery(const ACaption, APrompt: string; var Value: string): boolean;
      virtual; abstract;
    function PerformMessageBox(AText: string; AType: integer = -1; ACaption: string = ''): integer; virtual; abstract;
    procedure DoDebugHook; virtual; abstract;
    procedure DoRunningChanged; virtual;
    procedure ScripterSingleDebugHook;
    function ScripterDoDebugHook: boolean;

    // Creates a new run script associated with tha form specified by AForm
    // the run script will represent an instance of the form. The current form "class"
    // is the current class in the machine.
    function CreateFormRunScript(AForm: TComponent): TatScript;
    property StopInstruction: pSimplifiedCode read FStopInstruction;
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;

    ///  <summary>
    ///  Raises a runtime error with the specified message
    ///  </summary>
    procedure RuntimeError(msg: string);

    ///  <summary>
    ///  Clear method resets the virtual machine, clearing several internal variables, erasing the stack, among other
    ///  operations. You don't need to call Clear method, it's called internally by other methods of virtual machine.
    ///  </summary>
    procedure Clear;

    ///  <summary>
    ///  SolveAbsoluteAddressing method is used to translate address references to direct pointers, which are used by
    ///  p-code jump instructions. You don't need to call this method, it's automatically called by the virtual machine when needed.
    ///  </summary>
    procedure SolveAbsoluteAddressing; virtual;

    ///  <remarks>
    ///  InProcessExecute method executes a script code using the current virtual machine context. For example, if you call
    ///  <code>
    ///  InProcessExecute('ShowMessage(MyVar);');
    ///  </code>
    ///  And MyVar is a global variable in the virtual machine being executed, it will work fine. You should rarely use in process
    ///  executions, this is mostly used for evaluating watches while debugging a script. For that purpose, use higher-level objects,
    ///  like TatCustomScripter.Watches property.
    ///  </remarks>
    procedure InProcessExecute(AScriptStr: string);

    ///  <remarks>
    ///  Executes the script associated with the virtual machine.
    ///  If the script is not compiled, compilation is performed automatically.
    ///  <code>
    ///  The input parameter is deprecated and not used anymore.
    ///  </code>
    ///  The Execute function result contains value returned by the script main block. In pascal, you can use
    ///  return variable to pass the return value, even in the script main block.
    ///  In Basic, you must set MAIN variable to provide the return value.
    ///  </remarks>
    {$IFDEF NEWSTACK}
    function Execute(Input: array of const): TScriptValue; overload; virtual;
    {$ELSE}
    function Execute(Input: Variant): Variant; overload; virtual;
    {$ENDIF}
    function Execute: TScriptValue; overload; virtual;

    ///  <remarks>
    ///  Executes a specific routine (procedure) declared in the script associated with the virtual machine. If
    ///  program is still not compiled, compilation is performed automatically.
    ///  ALabel must contain the name of the routine to be execute, no matching case is performed.
    ///  if the routine doesn't exist, an exception is raised. You can previously check if the routine
    ///  exists using TatScriptInfo.RoutineByName method.
    ///  Input parameter can contain values that will be passed to the script routine. Input
    ///  can be a single Variant-type value, or an array of variant, or an array of const.
    ///  These values are passed to the script routine as parameters. If the routine parameter is declared
    ///  as a parameter by reference - for example, MyScriptFunction(var MyParam: integer); - then to have your
    ///  variable to be updated, you must use the array of const version of ExecuteSubRoutine, passing a variant of
    ///  type Variant.
    ///  </remarks>
    ///  <example>
    ///  <code>
    ///  //script
    ///  procedure MultiplyMyVar(var AValue: integer; AFactor: integer);
    ///  begin
    ///  AValue := AValue * AFactor;
    ///  end;
    /// 
    ///  //Delphi
    ///  var
    ///  SomeVar: Variant; //MUST BE of Variant type
    ///  begin
    ///  SomeVar := 10;
    ///  atScripter1.ExecuteSubroutine('DoubleMyVar', [SomeVar, 3]);
    ///  //At this point, SomeVar will have value of 30
    ///  end;
    ///  </code>
    ///  //The ExecuteSubRoutine function result contains value returned by the called function.
    ///  </example>
    {$IFNDEF NEWSTACK}
    function ExecuteSubroutine(ALabel: string; Input: Variant): Variant; overload;
    {$ENDIF}
    function ExecuteSubroutine(ALabel: string): TScriptValue; overload;
    function ExecuteSubroutine(ALabel: string; Input: array of const): TScriptValue; overload;

    ///  <remarks>
    ///  GetArrayIndex provides the index value of a Delphi indexed property being executed. The desired dimension
    ///  is specified in ADim parameter.
    ///  For example, if the virtual machine is executing a get (or set) operation of an indexed property, like this.
    ///  <code>
    ///  //script
    ///  MyObject.MyIndexedProperty['customer', 5] := 10;
    ///  </code>
    ///  then calling GetArrayIndex(0) will return 'customer' and GetArrayIndex(1) will return 5.
    ///  </remarks>
    function GetArrayIndex(ADim: integer): TScriptValue; overload;

    function GetArrayIndexAsInteger(ADim: integer): integer; overload;
    function GetArrayIndexAsString(ADim: integer): string; overload;

    ///  <remarks>
    ///  Returns the number of arguments passed to the Delphi method being executed.
    ///  <code>
    ///  //script being executed
    ///  MyObject.MyMethod('param', 20, 0);
    ///  </code>
    ///  When the virtual machine executes the method wrapper for MyMethod above,
    ///  InputArgCount will be 3.
    ///  </remarks>
    function InputArgCount: integer;

    ///  <remarks>
    ///  Returns the value of the parameter passed to the Delphi method being executed.
    ///  The parameter is indexed by AIndex. For the first parameter, index must be 0.
    ///  <code>
    ///  //script being executed
    ///  MyObject.MyMethod('param', 20, 0);
    ///  </code>
    ///  When the virtual machine executes the method wrapper for MyMethod above,
    ///  GetInputArg(0) will be 'param' and GetInputArg(1) will be 20.
    ///  </remarks>
    function GetInputArg(AIndex: integer): TScriptValue;
    function GetInputArgAsVariant(AIndex: integer): Variant;

    ///  <remarks>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as a string value.
    ///  The parameter is indexed by AIndex. For the first parameter, index must be 0.
    ///  <code>
    ///  //script being executed
    ///  MyObject.MyMethod('param', 20, 0);
    ///  </code>
    ///  When the virtual machine executes the method wrapper for MyMethod above,
    ///  GetInputArgAsString(0) will be 'param' and GetInputArgAsString(1) will be '20'.
    ///  </remarks>
    function GetInputArgAsString(AIndex: integer): string;

    ///  <remarks>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as a string value.
    ///  The parameter is indexed by AIndex. For the first parameter, index must be 0.
    ///  <code>
    ///  //script being executed
    ///  MyObject.MyMethod('param', 20, 0);
    ///  </code>
    ///  When the virtual machine executes the method wrapper for MyMethod above,
    ///  GetInputArgAsString(0) will be 'param' and GetInputArgAsString(1) will be '20'.
    ///  </remarks>
    function GetInputArgAsClass(AIndex: integer): TClass;

    {$IFNDEF NEXTGEN}
    ///  <summary>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as a wide string value.
    ///  See GetInputArg for more info.
    ///  </summary>
    function GetInputArgAsWideString(AIndex: integer): Widestring;
    {$ENDIF}

    ///  <summary>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as an integer value.
    ///  See GetInputArg for more info.
    ///  </summary>
    function GetInputArgAsInteger(AIndex: integer): integer;

    ///  <summary>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as an object value.
    ///  See GetInputArg for more info.
    ///  </summary>
    function GetInputArgAsObject(AIndex: integer): TObject;

    ///  <summary>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as an Int64 value.
    ///  See GetInputArg for more info.
    ///  </summary>
    function GetInputArgAsInt64(AIndex: integer): Int64;

    ///  <remarks>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as a boolean value.
    ///  For scripter, a boolean value is a integer test to zero. If zero, then boolean value is false. Otherwise,
    ///  it's true. An exception is raised if the value cannot be converted to an integer.
    ///  See GetInputArg for more info.
    ///  </remarks>
    function GetInputArgAsBoolean(AIndex: integer): boolean;

    ///  <summary>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as a float value.
    ///  See GetInputArg for more info.
    ///  </summary>
    function GetInputArgAsFloat(AIndex: integer): double;

    ///  <summary>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as a date time value.
    ///  See GetInputArg for more info.
    ///  </summary>
    function GetInputArgAsDateTime(AIndex: integer): TDateTime;

    ///  <summary>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as a char value.
    ///  See GetInputArg for more info.
    ///  </summary>
    function GetInputArgAsChar(AIndex: integer): char;

    ///  <summary>
    ///  Returns the value of the parameter passed to the Delphi method being executed, as a wide char value.
    ///  See GetInputArg for more info.
    ///  </summary>
    function GetInputArgAsWideChar(AIndex: integer): WideChar;

    ///  <remarks>
    ///  Sets the value of a parameter passed to a Delphi method by reference. The parameter is specified by index AIndex,
    ///  and the AValue must contain the value to be set. For example, if a Delphi method with the following signature was registered
    ///  in scripter.
    ///  <code>
    ///  MyMethod(AName, ATest: string; ACode: integer; var AStrResult: string);
    ///  </code>
    ///  when that method is executed by virtual machine, the method wrapper can set the value of AStrResult to 'ok' using the following code.
    ///  <code>
    ///  AMachine.SetInputArg(3, 'ok');
    ///  </code>
    ///  if the parameter specified by AIndex is not passed as reference, an exception is raised.
    ///  </remarks>
    procedure SetInputArg(AIndex: integer; const AValue: TScriptValue);

    ///  <summary>
    ///  Same as SetInputArg, with one difference: if the parameter is not passed by reference, nothing happens, while SetInputArg
    ///  raises an exception. See SetInputArg for more information.
    ///  </summary>
    procedure SetInputArgIfByRef(AIndex: integer; const AValue: TScriptValue);

    {$IFDEF DELPHI2010_LVL}
    ///  <summary>
    ///  Same as SetInputArg, but receives a TValue record instead a variant.
    ///  </summary>
    procedure SetInputArgValue(AIndex: integer; const AValue: TValue);
    {$ENDIF}
    ///  <remarks>
    ///  Use ReturnOutputArg to set the return value of a Delphi function called by virtual machine. For example, if the machine
    ///  is executing a function with the following signature.
    ///  <code>
    ///  function DoubleTheValue(AValue: integer): integer;
    ///  </code>
    ///  you can set the return value of the function this way, in the method wrapper.
    ///  <code>
    ///  AMachine.ReturnOutputArg(AMachine.GetInputArgAsInteger(0) * 2);
    ///  </code>
    ///  </remarks>
    procedure ReturnOutputArg(AValue: TScriptValue);
    procedure ReturnOutputArgAsVariant(AValue: Variant);

    {$IFDEF DELPHI2010_LVL}
    ///  <summary>
    ///  Same as ReturnOutputArg, but receives a TValue record instead a variant.
    ///  </summary>
    procedure ReturnOutputArgValue(AValue: TValue);
    {$ENDIF}
    ///  <summary>
    ///  Stops the current script execution. Same as setting Running property to false.
    ///  </summary>
    procedure Halt;

    ///  <summary>
    ///  Returns the first p-code instruction that corresponds to the source code line specified by ARow.
    ///  </summary>
    function InstructionByLine(ARow: integer): pSimplifiedCode;

    ///  <summary>
    ///  Returns the first p-code instruction of the routine specified by ALabel.
    ///  </summary>
    function EntryPoint(ALabel: string): pSimplifiedCode;

    ///  <summary>
    ///  Performs debug trace info operation in current script. This method should not be used very often because it works
    ///  at p-code instruction level. Use DebugTraceIntoLine instead.
    ///  </summary>
    procedure DebugTraceInto;

    ///  <summary>
    ///  Performs debug step over operation in current script. This method should not be used very often because it works
    ///  at p-code instruction level. Use DebugStepOverLine instead.
    ///  </summary>
    procedure DebugStepOver;

    ///  <remarks>
    ///  Performs debug trace into operation in script. A trace into operation executes the current line and pauses the execution
    ///  in the very next line. If the current line being executed is a routine call, then the execution stops at the first line
    ///  of the routine.
    ///  </remarks>
    procedure DebugTraceIntoLine;

    ///  <summary>
    ///  Performs debug step over operation in script. A step over operation executes the current line and pauses the execution
    ///  in the very next line. If the current line being executed is a routine call, the whole routine is executed at once.
    ///  </summary>
    procedure DebugStepOverLine;

    ///  <summary>
    ///  Unpauses the script (if paused) and continues script execution until current routine is terminated (or script main block).
    ///  </summary>
    procedure DebugRunUntilReturn;

    ///  <summary>
    ///  Unpauses the script (if paused) and continues script execution until the instruction specified by AInstruction is reached.
    ///  When that happens, the script execution is paused again.
    ///  </summary>
    procedure DebugRunToPoint(AInstruction: pSimplifiedCode);

    ///  <summary>
    ///  Unpauses the script (if paused) and continues script execution until the line specified by ALine is reached.
    ///  When that happens, the script execution is paused again.
    ///  </summary>
    procedure DebugRunToLine(ALine: integer);

    ///  <summary>
    ///  Create a breakpoint (or remove if there is already one) in the instruction specified by AInstruction. This method returns
    ///  true if a breakpoint was previously set, false otherwise. Do not use this method very often, use DebugToggleBreakLine instead.
    ///  </summary>
    function DebugToggleBreakPoint(AInstruction: pSimplifiedCode): boolean;

    ///  <summary>
    ///  Create a breakpoint (or remove if there is already one) in the line specified by ALine. This method returns
    ///  the first p-code instruction that correspondes to the line.
    ///  </summary>
    function DebugToggleBreakLine(ALine: integer): pSimplifiedCode;

    ///  <summary>
    ///  Returns the number of the next line in source code to be executed.
    ///  </summary>
    function DebugExecutionLine: integer;

    ///  <summary>
    ///  Returns the name of the Delphi property being accessed by the virtual machine. This function is useful when you have a single
    ///  wrapper for multiple Delphi properties, this way you can tell which specific property is being accessed.
    ///  </summary>
    function CurrentPropertyName: string;

    ///  <summary>
    ///  Returns the name of the Delphi method being called by the virtual machine. This function is useful when you have a single
    ///  wrapper for multiple Delphi method, this way you can tell which specific method is being called.
    ///  </summary>
    function CurrentMethodName: string;

    ///  <summary>
    ///  Returns the TatScript object which this virtual machine belongs to.
    ///  </summary>
    property Script: TatScript read FScript;

    ///  <summary>
    ///  Returns the TatScripter component which this virtual machine belongs to.
    ///  </summary>
    property Scripter: TatCustomScripter read FScripter;

    ///  <summary>
    ///  Contains the error message of the last exception raised during script execution. Same as accessing Message property of the
    ///  exception object.
    ///  </summary>
    property LastExceptionMessage: string read FLastExceptionMessage;

    property LastExceptionLine: integer read FLastExceptionLine;
    property LastExceptionCol: integer read FLastExceptionCol;

    ///  <summary>
    ///  Contains the help context of the last exception raised during script execution. Same as accessing HelpContext property of the
    ///  exception object.
    ///  </summary>
    property LastExceptionHelpContext: integer read FLastExceptionHelpContext;

    ///  <summary>
    ///  Contains the class name of the last exception raised during script execution. For example, if the last exception raised was
    ///  EConvertError, this function will return 'EConvertError'.
    ///  </summary>
    property LastExceptionClassName: string read FLastExceptionClassName;

    ///  <remarks>
    ///  Contains a reference to the Delphi object which property/method is being accessed/called. For example, if the script
    ///  contains a call like this.
    ///  <code>
    ///  MyObject.MyMethod(1);
    ///  </code>
    ///  CurrentObject will return the reference to MyObject. You will often use CurrentObject in the wrappers to access the actual
    ///  object properties or call its methods.
    ///  </remarks>
    property CurrentObject: TObject read FCurrentObject;

    ///  <remarks>
    ///  Contains a reference to the Delphi class which class property/method is being accessed/called. For example, if the script
    ///  contains a call like this.
    ///  <code>
    ///  TPersistent.Create;
    ///  </code>
    ///  CurrentClass will return the reference to TPersistent class. You can use CurrentClass in the wrappers to access the actual
    ///  class properties or call its methods.
    ///  </remarks>
    property CurrentClass: TatClass read GetCurrentClass;

    ///  <summary>
    ///  Deprecated. Use TatScript.Breaks instead.
    ///  </summary>
    property BreakPoints: TatScriptBreakPoints read FBreakPoints write FBreakPoints;

    ///  <summary>
    ///  Returns true if the script has been halted and is still being executed. Halted property will always be false if the
    ///  script is not running.
    ///  </summary>
    property Halted: boolean read FHalted;

    ///  <summary>
    ///  Use Running property to check if the current script is being executed (regardless of the value of Paused property). You can
    ///  also set Running to true to execute a script, or set it to false to halt execution.
    ///  </summary>
    property Running: boolean read FRunning write SetRunning;

    ///  <remarks>
    ///  Indicates if the current script is Paused. You can also set Paused property to true to pause current execution, or to ensure
    ///  that the script will stop at its first instruction when it is executed. Setting Paused to true or false doesn't change
    ///  the value of Running property, they are independent.
    ///  </remarks>
    property Paused: boolean read FPaused write SetPaused;

    ///  <summary>
    ///  Do not use this property, use TatCustomScripter.CallExecHookEvent instead.
    ///  </summary>
    property CallExecHookEvent: boolean read FCallExecHookEvent write FCallExecHookEvent;

    ///  <summary>
    ///  Do not use this event, use TatCustomScripter.OnDebugHook instead.
    ///  </summary>
    property OnDebugHook: TNotifyEvent read GetOnDebugHook write SetOnDebugHook;

    ///  <summary>
    ///  Do not use this event, use TatCustomScripter.OnExecHook instead.
    ///  </summary>
    property OnExecHook: TNotifyEvent read FOnExecHook write FOnExecHook;

    ///  <summary>
    ///  OnPausedChanged is fired whenever the value of Paused property changes.
    ///  </summary>
    property OnPauseChanged: TNotifyEvent read FOnPauseChanged write FOnPauseChanged;

    ///  <summary>
    ///  OnRunningChanged event is fired whenever the value of Running property changes.
    ///  </summary>
    property OnRunningChanged: TNotifyEvent read FOnRunningChanged write FOnRunningChanged;

    ///  <summary>
    ///  Returns the current p-code instruction being executed by the virtual machine.
    ///  </summary>
    property CurrentInstruction: pSimplifiedCode read FCurrentInstruction;

    ///  <summary>
    ///  Returns the next p-code instruction to be executed by the virtual machine.
    ///  </summary>
    property NextInstruction: pSimplifiedCode read FNextInstruction write FNextInstruction;

    ///  <remarks>
    ///  PrepareInstruction contains a reference to the last p-code Prepare instruction executed. When PrepareInstruction
    ///  is not nil, it means that the script is being executed. When script finishes its execution, the PrepareInstruction is
    ///  reverted to the state previously to script execution. Used by internal methods to verify if the current script is
    ///  being executed with reentrant calls (a script is being executed and a Delphi event fires causing the execution of
    ///  a subroutine of the same script.
    ///  You will rarely need to access this property.
    ///  </remarks>
    property PrepareInstruction: pSimplifiedCode read FPrepareInstruction;

    ///  <summary>
    ///  Deprecated, do not use it. For watches manipulation, use TatScript.Watches instead.
    ///  </summary>
    property DebugWatches: TatDebugWatches read FDebugWatches;
  end;

  ///  <remarks>
  ///  Indicates how the script behaves in the scripting system.
  ///  sbNormal: the script is a regular script
  ///  sbClass: the script is treated as a class. The class name is defined with $CLASS directive.
  ///  All global variabels are treated as properties of the class, and routines are class methods.
  ///  sbForm: the script is treated as a form. The form script is defined with $FORM directive.
  ///  All global variabels are treated as properties of the form, and routines are form methods.
  ///  </remarks>
  TatScriptBehavior = (sbNormal, sbClass, sbForm);

  ///  <remarks>
  ///  TatScriptInfo object provides information about the current script, such as the declared routines (available in Routines property),
  ///  global variables (available in Globals property), among others. Information is only available if the current script was compiled (with Compile method) or silent compiled
  ///  (with SilentCompile method).
  ///  </remarks>
  TatScriptInfo = class(TComponent)
  private
    FRoutines: TatRoutinesInfo;
    FCodeSize: integer;
    FGlobals: TatVariablesInfo;
    FScript: TatScript;
    FMainRoutine: TatRoutineInfo;
    FScriptClassName: string;
    FFormResource: string;
    FBehavior: TatScriptBehavior;
    // FIsForm: boolean;
    // FIsClass: boolean;
    FUnitName: string;
    procedure UpdateRoutineInfoPointers;
    procedure SetGlobals(const Value: TatVariablesInfo);
    procedure SetRoutines(const Value: TatRoutinesInfo);
    function GetMainRoutineName: string;
    procedure SetMainRoutineName(const Value: string);
    function GetIsClass: boolean;
    function GetIsForm: boolean;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    ///  <summary>
    ///  Erases all available information. To populate the information again, you will need to recompile the script. Note that
    ///  calling Clear method does not set the TatScript.Compiled flag to false.
    ///  </summary>
    procedure Clear;

    ///  <summary>
    ///  Retrieves the TatRoutineInfo object associated with the script routine specified by AName. If the routine doesn't exist
    ///  in the script, RoutineByName returns nil.
    ///  </summary>
    function RoutineByName(AName: string): TatRoutineInfo;

    ///  <summary>
    ///  Adds a new routine in the script info Routines collection. Do not call this method direclty, it's used internally
    ///  by the compiler.
    ///  </summary>
    function DeclareRoutine(AName: string; ADeclInst: pSimplifiedCode; AIsFunction: boolean)
      : TatRoutineInfo;

    ///  <summary>
    ///  Retrives the number of p-code instructions generated after compilation. In other words, it's the size of the "executable".
    ///  </summary>
    property CodeSize: integer read FCodeSize;

    ///  <summary>
    ///  Provides access to the TatScript object that owns this script info.
    ///  </summary>
    property Script: TatScript read FScript;

    ///  <summary>
    ///  Retrieves the TatRoutineInfo obejct associated with the script main block (which is treated in a similar way as
    ///  any other routine in script).
    ///  </summary>
    property MainRoutine: TatRoutineInfo read FMainRoutine write FMainRoutine;

    ///  <summary>
    ///  IsForm property indicates if the current script is a regular script (IsForm is false) or a form script (IsForm is true).
    ///  A script is a form script when it contains the $FORM directive.
    ///  </summary>
    property IsForm: boolean read GetIsForm;

    ///  <remarks>
    ///  IsClass property indicates if the current script is a regular script (IsClass is false) or a class script (IsClass is true).
    ///  A script is a class script when it contains the $CLASS directive.
    ///  Note that if the script is a form, IsClass will be false, despite the fact a form is also a class.
    ///  </remarks>
    property IsClass: boolean read GetIsClass;
  published
    ///  <summary>
    ///  Provides access to the TatRoutinesInfo collection which holds information about all routines declared in the script.
    ///  </summary>
    property Routines: TatRoutinesInfo read FRoutines write SetRoutines;

    ///  <summary>
    ///  Provides access to the TatVariablesInfo collection which holds information about all global variables declared in the script.
    ///  </summary>
    property Globals: TatVariablesInfo read FGlobals write SetGlobals;

    ///  <summary>
    ///  Used only for streaming (saving of compiled code) purposes. Do not use this property.
    ///  </summary>
    property MainRoutineName: string read GetMainRoutineName write SetMainRoutineName;

    ///  <remarks>
    ///  If the current script is a form or class script, then it behaves as a form/class declaration (all routines act as the form methods,
    ///  and all global variables are form properties). In that case, ScriptClassName will hold the name of the class ('TMyForm',
    ///  for example). That's the name that will be accessible from script, for creating a form or class instance, for example: TMyForm.Create.
    ///  </remarks>
    property ScriptClassName: string read FScriptClassName write FScriptClassName;

    ///  <remarks>
    ///  If the current script is a form script, once the script is compiled, the dfm file referenced by it is loaded, and saved
    ///  in FormResource property, for further usage (instantiating new forms, saving compiled code to file, etc.). The dfm file
    ///  is not used anymore, unless the script is cleared, which will require a new compilation.
    ///  </remarks>
    property FormResource: string read FFormResource write FFormResource;

    ///  <remarks>
    ///  Indicates how the current script behaves, based on the tyep TatScriptBehavior.
    ///  Usually the script can be a regular script, or a script that represents a class (or a form).
    ///  In the latter case, variables and treated as class properties, and routines are treated as class methods
    ///  </remarks>
    property Behavior: TatScriptBehavior read FBehavior write FBehavior;

    {$WARNINGS OFF}
    ///  <remarks>
    ///  UnitName is used for script-based libraries. If a script adds "uses UNIT", the compiler
    ///  searches for files named "UNIT", and also for scripts inside Scripts collection which UnitName
    ///  matches "UNIT".
    ///  </remarks>
    property UnitName: string read FUnitName write FUnitName;
  end;

  ///  <summary>
  ///  TatRoutinesInfo holds a list of TatRoutineInfo objects which contains information about the routines declared in script,
  ///  such as the routine name, parameters, etc.. The main routine is also present in the collection.
  ///  </summary>
  TatRoutinesInfo = class(TOwnedCollection)
  private
    FScriptInfo: TatScriptInfo;
    function GetItem(i: integer): TatRoutineInfo;
  public
    ///  <summary>
    ///  Returns the index, in the collection, of the routine specified by AName. If there is no such routine, IndexOf returns -1.
    ///  </summary>
    function IndexOf(AName: string): integer;

    ///  <summary>
    ///  Fills the AStrings object with the names of declared routines.
    ///  </summary>
    procedure GetNames(AStrings: TStrings);

    ///  <summary>
    ///  Provides indexed-access to the TatRoutineInfo objects in the collection.
    ///  </summary>
    property Items[i: integer]: TatRoutineInfo read GetItem; default;
  end;

  ///  <remarks>
  ///  Indicates if the routine was declared as private or public in the script. When the script is registered as a script library,
  ///  its routines are available from other scripts, except when it is declared as private.
  ///  rvPublic - Routine was declared as public (visible to other scripts)
  ///  rvPrivate - Routine was declared as private (visible only from script itself)
  ///  </remarks>
  TatRoutineVisibility = (rvPublic, rvPrivate);

  ///  <summary>
  ///  TatRoutineInfo holds information about the routine declared in script. You can retrieve parameters, local variables,
  ///  visibility, and more.
  ///  </summary>
  TatRoutineInfo = class(TCollectionItem)
  private
    FVariables: TatVariablesInfo;
    FName: string;
    FDeclarationInstruction: pSimplifiedCode;
    FIsFunction: boolean;
    FArgCount: integer;
    FByRefArgMask: integer;
    FResultIndex: integer;
    FPrototype: TatRoutineInfo;
    FCallingConvention: TatCallingConvention;
    FExternalDll: string;
    FExternalName: string;
    FResultTypeDecl: string;
    FResultClass: TatClass;
    FVisibility: TatRoutineVisibility;
    procedure SetVariables(const Value: TatVariablesInfo);
    function ResultClass: TatClass;
    {$IFDEF MSWINDOWS}
    procedure DispatchDllCall(AMachine: TatVirtualMachine);
    function ResultTypeKind: TatTypeKind;
    function ResultClassRef: TClass;
    {$ENDIF}
    function GetResultTypeDecl: string;
    procedure SetResultTypeDecl(const Value: string);
    procedure SetTypeFromString(ATypeStr: string);
    function GetResultClassName: string;
    procedure SetResultClassName(const Value: string);
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;

    ///  <summary>
    ///  Returns a reference to the TatScriptInfo object which owns this routine info.
    ///  </summary>
    function ScriptInfo: TatScriptInfo;

    ///  <summary>
    ///  Returns a TatVariableInfo object related to the variable (or parameter) specified by the name AName. If the variable
    ///  or parameter doesn't exist, VariableByName returns nil.
    ///  </summary>
    function VariableByName(AName: string): TatVariableInfo;

    ///  <remarks>
    ///  Check if an input parameter is specified to be passed by reference.
    ///  IsByRefArg returns true if the n-th input parameter indicated by n is declared to be passed by reference. For the first
    ///  input parameter, n must be zero.
    ///  See SetVarArgs method for more information.
    ///  </remarks>
    function IsByRefArg(n: byte): boolean;

    ///  <remarks>
    ///  Returns the number of local variables declared in the routine. This function doesn't take into account the routine
    ///  parameters, only effective local variables. Note that the result variable (in case of a function routine) is also
    ///  considered as a local variable.
    ///  </remarks>
    function LocalVarCount: integer;

    ///  <summary>
    ///  Do not call DeclareVariable directly. It's used by internal parsers/compilers.
    ///  </summary>
    function DeclareVariable(AName: string; ASourcePos: integer; AArgIndex: integer = -1;
      AModifier: TatArgumentModifier = moNone): TatVariableInfo;

    ///  <remarks>
    ///  DeclarationInstruction contains the Prepare p-code instruction related to the routine. It's the first p-code to be
    ///  executed and allocates space in stack for local variables and parameters.
    ///  You will rarely need to use this property.
    ///  </remarks>
    property DeclarationInstruction: pSimplifiedCode read FDeclarationInstruction
      write FDeclarationInstruction;

    ///  <summary>
    ///  Retrieves the name of the declared result class. If the variable type is not a class type, but a scalar type
    ///  (string, integer, etc.), ResultClassName value will be an empty string.
    ///  </summary>
    property ResultClassName: string read GetResultClassName write SetResultClassName;

    ///  <remarks>
    ///  If a routine had a previous declaration using forward directive, then there will be two TatRoutineInfo objects in the
    ///  Routines collection. In this case, the second routine declaration (after the forward one), will have the Prototype property
    ///  set. This property contains a reference to the routine prototype (declared with forward directive). If the routine
    ///  doesn't have a previous prototype declaration, Prototype property will be nil.
    ///  </remarks>
    property Prototype: TatRoutineInfo read FPrototype write FPrototype;

    ///  <summary>
    ///  Do not use this method directly. Used for internal purposes only.
    ///  </summary>
    procedure PrepareExternalClass;

    ///  <summary>
    ///  Used by scripter engine only.
    ///  </summary>
    function Internal: boolean;
  published
    ///  <summary>
    ///  Contains the name of the declared routine.
    ///  </summary>
    property Name: string read FName write FName;

    ///  <summary>
    ///  Holds a list of TatVariableInfo objects with information about all the parameters and local variables
    ///  declared in the routine.
    ///  </summary>
    property Variables: TatVariablesInfo read FVariables write SetVariables;

    ///  <summary>
    ///  Returns true if the routine returns a result value. In other words, IsFunction is true when the routine is a function,
    ///  false if the routine is a procedure/sub.
    ///  </summary>
    property IsFunction: boolean read FIsFunction write FIsFunction;

    ///  <summary>
    ///  ArgCount returns the number of input parameters declared in the routine. Note that it doesn't take local variables into account,
    ///  just input parameters.
    ///  </summary>
    property ArgCount: integer read FArgCount write FArgCount;

    ///  <remarks>
    ///  ByRefArgMask contains information about which input parameters in the routine were declared by reference (using var/byref
    ///  modified). ByRefArgMask is a bit mask, in which each bit represents a parameter, being the less significant bit the first
    ///  parameter, and so on. Below are some examples.
    ///  <code>
    ///  //Parameter AResult is by reference. Index of AResult is 2 (3rd parameter)
    ///  //ByRefArgMask will be in binary 100 (3rd less signficant bit set)
    ///  //So ByRefArgMas integer value will be 4
    ///  procedure MyRoutine(AName: string; AValue: integer; var AResult: boolean);
    /// 
    ///  //Parameters Value1, Value2 and Error are passed by reference.
    ///  //Index of parameters are 0, 1 and 3 (1st, 2nd and 4th parameters)
    ///  //ByRefArgMask will be in binary 1011
    ///  //So ByRefArgMas integer value will be 11
    ///  procedure SwapValues(var Value1, Value2: integer; Flag: string; var Error: integer);
    ///  </code>
    ///  </remarks>
    property ByRefArgMask: integer read FByRefArgMask write FByRefArgMask;

    ///  <remarks>
    ///  Contains the index of the variable (in Variables collection) that corresponds to the function result. When a
    ///  function is declared, the function result value is declared as a local variable. Its index in the Variables collection
    ///  is provided by this property.
    ///  </remarks>
    property ResultIndex: integer read FResultIndex write FResultIndex;

    ///  <summary>
    ///  Contains information about the calling convention of the declared routine. Used only in dll function calls.
    ///  </summary>
    property CallingConvention: TatCallingConvention read FCallingConvention
      write FCallingConvention;

    ///  <summary>
    ///  Contains the name of the dll declared in the routine prototype. This is only used when the declared routine is a
    ///  prototype for a dll function call.
    ///  </summary>
    property ExternalDll: string read FExternalDll write FExternalDll;

    ///  <summary>
    ///  Contains the real name of the function to be called in the dll. This is only used when the declared routine is a
    ///  prototype for a dll function call.
    ///  </summary>
    property ExternalName: string read FExternalName write FExternalName;

    ///  <remarks>
    ///  Contains the identifier of the result type of the declared function routine. For example, if you declare the
    ///  following routine in script.
    ///  <code>
    ///  function MyFunction: string;
    ///  </code>
    ///  ResultTypeDecl will be 'string'.
    ///  </remarks>
    property ResultTypeDecl: string read GetResultTypeDecl write SetResultTypeDecl;

    ///  <summary>
    ///  Indicates the visibility of the routine (private or public).
    ///  </summary>
    property Visibility: TatRoutineVisibility read FVisibility write FVisibility;
  end;

  ///  <remarks>
  ///  TatVariablesInfo is a collection of TatVariableInfo objects that hold information about variables declared in script.
  ///  If the TatVariablesInfo relates to a routine, then it will contain all declared local variables, the input parameters
  ///  of the routine, and the variable result value (if it's a function). If TatVariablesInfo relates to the script as a whole,
  ///  it will contain the global variables declared in script.
  ///  </remarks>
  TatVariablesInfo = class(TOwnedCollection)
  private
    function GetItem(i: integer): TatVariableInfo;
  public
    ///  <summary>
    ///  Adds a new variable in the collection. Do not call this directly, it will not effectively change source code to declare
    ///  a new variable. This is used by the compiler to add information in the collection.
    ///  </summary>
    function Add: TatVariableInfo;

    ///  <summary>
    ///  Returns the index of the variable which name is specified by AName. If no variable is found, IndexOf returns -1.
    ///  </summary>
    function IndexOf(AName: string): integer;

    ///  <summary>
    ///  Returns the TatVariableInfo object which corresponds to the variable which name is specified by Name. If no variable
    ///  is found, FindByName returns nil.
    ///  </summary>
    function FindByName(AName: string): TatVariableInfo;

    ///  <summary>
    ///  Provides indexed access to the TatVariableInfo objects in the collection.
    ///  </summary>
    property Items[i: integer]: TatVariableInfo read GetItem; default;
  end;

  ///  <remarks>
  ///  Indicates if the global variable was declared as private or public in the script. When the script is registered
  ///  as a script library, its global variables are available from other scripts, except when it is declared as private.
  ///  vvPublic - Global variable was declared as public (visible to other scripts)
  ///  vvPrivate - Global variable was declared as private (visible only from script itself)
  ///  </remarks>
  TatVariableVisibility = (vvPublic, vvPrivate);

  ///  <remarks>
  ///  Holds information about a variable declared in the script. Although the word "variable" here, it's important to
  ///  note that not only local and global variables, but also routine input parameters and function result value also have
  ///  an associated TatVariableInfo object.
  ///  </remarks>
  TatVariableInfo = class(TCollectionItem)
  private
    FVarName: string;
    FDeclarationSourcePos: integer;
    FArgIndex: integer; // indica que a variável é um argumento de subrotina
    FModifier: TatArgumentModifier; // indica o modificador do argumento de subrotina
    FDeclaredClass: TatClass; // classe declarada para a variável
    FGlobal: boolean;
    FTypeDecl: string;
    // string contendo informações sobre o tipo da variável ou argumento de subrotina
    FSystemType: integer;
    FVisibility: TatVariableVisibility;
    function GetValue: TScriptValue;
    procedure SetValue(AValue: TScriptValue);
    function Script: TatScript;
    function routine: TatRoutineInfo;
    function GetDeclaredClassName: string;
    procedure SetDeclaredClassName(const Value: string);
    procedure PullSystemType;
  public
    constructor Create(ACollection: TCollection); override;
    procedure Assign(ASource: TPersistent); override;

    ///  <summary>
    ///  Used by compiler. Do not use this function.
    ///  </summary>
    procedure SetTypeFromString(ATypeStr: string);

    ///  <summary>
    ///  Provides a reference to the TatScriptInfo object that holds information about this variable.
    ///  </summary>
    function ScriptInfo: TatScriptInfo;

    ///  <summary>
    ///  Indicates if the variable is an internal variable, like for-loops variable. Ignore variables that are
    ///  declared as internal.
    ///  </summary>
    function Internal: boolean;

    ///  <remarks>
    ///  VarIndex is used by the compiler to know the position of the variable in the stack, relative to the current
    ///  stack base. With regarding to the stack, local variables are located in a positive index from stack base,
    ///  and input parameters are with negative values.
    ///  You don't need to use this method.
    ///  </remarks>
    function VarIndex: integer;

    ///  <remarks>
    ///  Returns true if the variable has the same declaration as the variable passed in AVariable parameter.
    ///  This method is used to check if a routine prototype contains the same declaration and the routine implementation,
    ///  so the compiler can checks for inconsistences and generate a compile error if, for example, the input parameters are different.
    ///  </remarks>
    function SameDeclaration(AVariable: TatVariableInfo): boolean;

    ///  <remarks>
    ///  Retrieves or sets the effective value of the variable in script. This only makes sense when the script is running,
    ///  for example, if you have a local routine variable and/or input parameter, the variable will only exist when the script execution
    ///  reaches that routine. The only exception are global variables. In this case, you can set or read the value even before or
    ///  after the script execution.
    ///  </remarks>
    property Value: TScriptValue read GetValue write SetValue;

    ///  <summary>
    ///  Retrieves the TatClass object associated with the declared type of variable. If the variable type is not a class, DeclaredClass
    ///  will contain nil.
    ///  </summary>
    property DeclaredClass: TatClass read FDeclaredClass write FDeclaredClass;
  published
    ///  <summary>
    ///  Holds the name of the declared variable.
    ///  </summary>
    property VarName: string read FVarName write FVarName;

    ///  <summary>
    ///  Contains the position in the source code where the variable was declared.
    ///  </summary>
    property DeclarationSourcePos: integer read FDeclarationSourcePos write FDeclarationSourcePos;

    ///  <remarks>
    ///  If the TatVariableInfo object refers to an input parameter, ArgIndex will have the position of the input parameter
    ///  in the list of parameters. First parameter has ArgIndex of 0. If the variable is not an input parameter, ArgIndex
    ///  will be -1. For example, for the following routine declared in script.
    ///  <code>
    ///  procedure MyRoutine(Param1, Param2: integer);
    ///  var
    ///  MyVar1, MyVar2: integer;
    ///  begin
    ///  end;
    ///  </code>
    ///  ArgIndex of Param1 will be 0, Param2 will be 1, and both MyVar1 and MyVar2 will have ArgIndex set to -1.
    ///  </remarks>
    property ArgIndex: integer read FArgIndex write FArgIndex;

    ///  <summary>
    ///  If it is an input parameter, Modifier will hold the modifier used in routine declaration ("var", "const", none, etc.).
    ///  </summary>
    property Modifier: TatArgumentModifier read FModifier write FModifier;

    ///  <summary>
    ///  Indicates if the variable is a global variable or not.
    ///  </summary>
    property Global: boolean read FGlobal write FGlobal;

    ///  <summary>
    ///  Retrieves the name of the declared variable class. If the variable type is not a class type, but a scalar type
    ///  (string, integer, etc.), DeclaredClassName value will be an empty string.
    ///  </summary>
    property DeclaredClassName: string read GetDeclaredClassName write SetDeclaredClassName;

    ///  <remarks>
    ///  Contains the name of the declared type of variable. For example, if the variable was declared.
    ///  <code>
    ///  var MyVar: integer;
    ///  </code>
    ///  TypeDecl will contain 'integer'.
    ///  </remarks>
    property TypeDecl: string read FTypeDecl write FTypeDecl;

    ///  <summary>
    ///  For internal use only. SystemType contains the TVarType value of the declared variable. This value is extracted and
    ///  calculated by the compiler based on the value of TypeDecl property.
    ///  </summary>
    property SystemType: integer read FSystemType write FSystemType;

    ///  <summary>
    ///  Indicates the visibility of the variable (private or public).
    ///  </summary>
    property Visibility: TatVariableVisibility read FVisibility write FVisibility;
  end;

  ///  <summary>
  ///  Internal interface used from manipulation of record types
  ///  </summary>
  IatInterfacedObject = interface
    ['{44284F76-2152-4326-9CB7-DEC05852B5CA}']
    function GetObjectReference: TObject;
  end;

  {$M+}

  ///  <remarks>
  ///  TatRecordWrapper is a class used to allow scripter to iteract with record types. All records in scripter are
  ///  treated as objects descending from TatRecordWraper. When scripter needs to receive or send a record type from/to
  ///  Delphi methods, it encapsulates the record in the TatRecordWrapper object. Each record type must have its own
  ///  class descending from TatRecordWrapper, implementing the record fields as object properties.
  ///  </remarks>
  TatRecordWrapper = class(TInterfacedObject, IatInterfacedObject)
  public
    function GetObjectReference: TObject;
  end;
  {$M-}

  ///  <remarks>
  ///  Deprecated.
  ///  Allows manipulation of breakpoints at p-code level. Do not use this approach, use TatScriptBreaks collection instead.
  ///  See TatScript.Breaks property.
  ///  </remarks>
  TatScriptBreakPoints = class(TCollection)
  private
    FMachine: TatVirtualMachine;
    function GetItem(i: integer): TatScriptBreakPoint;
  public
    constructor Create(AMachine: TatVirtualMachine);
    function InsertNormalBreak(ATargetInst: pSimplifiedCode): TatScriptBreakPoint;
    function InsertTempBreak(ATargetInst: pSimplifiedCode): TatScriptBreakPoint;
    function RemoveBreakPoint(ATargetInst: pSimplifiedCode): boolean;
    function BreakPointByLine(ALine: integer): TatScriptBreakPoint;
    function Add: TatScriptBreakPoint;
    property Items[i: integer]: TatScriptBreakPoint read GetItem; default;
  end;

  ///  <remarks>
  ///  Deprecated.
  ///  Contains information about a breakpoint at p-code level. Do not use this approach, use TatScriptBreaks collection
  ///  and TatScriptBreak objects instead. See TatScript.Breaks property.
  ///  </remarks>
  TatScriptBreakPoint = class(TCollectionItem)
  private
    FOriginalInst: TSimplifiedCode; // Contains a copy of original instruction
    FBreakInst: pSimplifiedCode; // Points to the inserted break instruction
    FPassCount: integer;
    FEnabled: boolean;
    FAutoDestroy: boolean;
    FNotifyBreak: TatScriptBreak;
    // function GetBreakLine: integer;
    procedure SetBreakInst(ATargetInst: pSimplifiedCode);
    procedure RemoveBreak;
    procedure NormalBreakProc;
    procedure TemporaryBreakProc;
    // function GetBreakLine: integer;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    function Machine: TatVirtualMachine;
    property OriginalInst: TSimplifiedCode read FOriginalInst write FOriginalInst;
    // property BreakInst: pSimplifiedCode read FBreakInst  write FBreakInst;
    property PassCount: integer read FPassCount write FPassCount;
    property Enabled: boolean read FEnabled write FEnabled;
    property AutoDestroy: boolean read FAutoDestroy write FAutoDestroy;
  end;

  ///  <summary>
  ///  Internal use only.
  ///  </summary>
  TLoopStatement = (lsNone, lsFor, lsWhile, lsRepeat);

  {$IFDEF DELPHI2010_LVL}
  TDefineClassOptions = class
  private
    FRecursive: boolean;
    FVisibilityFilter: TMemberVisibilitySet;
    FRedefine: TRedefineOption;
    FProperties: TArray<TRttiProperty>;
    FFields: TArray<TRttiField>;
    FCustomProperties: boolean;
    FCustomFields: boolean;
  public
    constructor Create;
    property VisibilityFilter: TMemberVisibilitySet read FVisibilityFilter write FVisibilityFilter;
    property Recursive: boolean read FRecursive write FRecursive;
    property Redefine: TRedefineOption read FRedefine write FRedefine;
    property CustomProperties: boolean read FCustomProperties write FCustomProperties;
    property Properties: TArray<TRttiProperty> read FProperties write FProperties;
    property CustomFields: boolean read FCustomFields write FCustomFields;
    property Fields: TArray<TRttiField> read FFields write FFields;
  end;
  {$ENDIF}

  ///  <remarks>
  ///  TatClasses holds a collection of TatClass objects that contain information abuot all Delphi classes registered in scripter system,
  ///  including its methods and properties. When a Delphi class is registered, scripter knows about it and can interact with
  ///  the class accordingly.
  ///  </remarks>
  TatClasses = class(TCollection)
  private
    FScripter: TatCustomScripter;
    FRegLevel: integer;
    function GetItem(i: integer): TatClass;
    function GetImplicitCount: integer;
    procedure SetLibraryContext(AClass: TatClass);
  protected
    function AddClassByRTTI(AClass: TClass; AClassName: string = ''): TatClass;
    function AddRecord(ATypeInfo: PTypeInfo; ARecordName: string = ''): TatClass;
    function CheckLoaded(AClass: TClass; AClassName: string = ''): TatClass;
    property ImplicitCount: integer read GetImplicitCount;
  public
    {$IFDEF DELPHI2010_LVL}
    function DefineClass(AClass: TClass; Options: TDefineClassOptions; AClassName: string = ''): TatClass;
    {$ENDIF}
  public
    constructor Create(AScripter: TatCustomScripter);

    ///  <summary>
    ///  Returns the index of a class which name is specified by AName. If the class is not found, IndexOf returns -1.
    ///  </summary>
    function IndexOf(AName: string): integer;

    ///  <summary>
    ///  Returns the TatClass object corresponding to the class which name is specified by AName.
    ///  If the class is not found, ClassByName returns nil.
    ///  </summary>
    function ClassByName(AName: string): TatClass;

    ///  <summary>
    ///  Use by internal methods only. Do not call directly.
    ///  </summary>
    function TestCheckLoaded(AClass: TClass; var ACurrentClass: TatClass;
      AClassName: string = ''): boolean;

    ///  <summary>
    ///  Provides indexed access to the TatClass objects in the collection.
    ///  </summary>
    property Items[i: integer]: TatClass read GetItem; default;
  end;

  ///  <summary>
  ///  Holds information about a Delphi class registered in scripter. A TatClass object holds information about the Delphi registered
  ///  class, its methods, properties, and provides methods for registering new methods and properties in the class.
  ///  </summary>
  TatClass = class(TCollectionItem)
  private
    FName: string;
    FProperties: TatProperties;
    FMethods: TatMethods;
    FClassRef: TClass; // para uso com RTTI tobject
    FRecordRef: PTypeInfo;
    FAncestorName: string;
    FAncestor: TatClass;
    FDescendants: TList;
    FDefaultProperty: TatProperty;
    // For internal use only, it's used when the class is registered by a SelfRegisterAsLibrary
    FBaseScript: TatScript;
    FImplicitClassRef: TatClassRef;
    FLibContext: string;
    procedure SetLibContext(Meth: TatMethod); overload;
    procedure SetLibContext(Prop: TatProperty); overload;
    procedure Inherits(AAncestorName: string);
    { VCL classes - helper procs }
    procedure RemoveDescendant(ADescendant: TatClass);
    procedure InsertDescendant(ADescendant: TatClass);
    procedure NotifyDescendants;
    procedure AncestorDestroyed;
    procedure SetMethods(const Value: TatMethods);
    procedure SetProperties(const Value: TatProperties);
    function GetIsImplicit: boolean;
    function Scripter: TatCustomScripter;
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;

    function IsDefaultInstance: boolean;

    ///  <summary>
    ///  For internal use.
    ///  </summary>
    procedure SetImplicitElement(const Value: TCollectionItem);

    ///  <summary>
    ///  Deprecated. Use DefineMethod instead.
    ///  </summary>
    function SetProc(AName: string; ACode: pointer; AArgCount: integer;
      AResultDataType: TatTypeKind; AProc: TGenericProc; AResultClass: TClass;
      AIsClassMethod: boolean = false; ADefArgCount: integer = 0; AParameterHints: string = '')
      : TatMethod;

    ///  <summary>
    ///  Deprecated. Use DefineNewMethod instead.
    ///  </summary>
    function AddProc(AName: string; ACode: pointer; AArgCount: integer;
      AResultDataType: TatTypeKind; AProc: TGenericProc; AResultClass: TClass;
      AIsClassMethod: boolean = false; ADefArgCount: integer = 0): TatMethod;

    ///  <summary>
    ///  Returns the TatProperty object associated with the property specified by AName. If such property doesn't exist,
    ///  PropertyByName returns nil.
    ///  </summary>
    function PropertyByName(AName: string): TatProperty;

    ///  <summary>
    ///  Returns the TatProperty object associated with the class property specified by AName. If such property doesn't exist,
    ///  ClassPropertyByName returns nil.
    ///  </summary>
    function ClassPropertyByName(AName: string): TatProperty;

    ///  <summary>
    ///  Returns the TatMethod object associated with the method specified by AName. If such method doesn't exist,
    ///  MethodByName returns nil.
    ///  </summary>
    function MethodByName(AName: string): TatMethod;

    ///  <summary>
    ///  Returns the TatMethod object associated with the class method specified by AName. If such method doesn't exist,
    ///  ClassMethodByName returns nil.
    ///  </summary>
    function ClassMethodByName(AName: string): TatMethod;

    ///  <remarks>
    ///  Returns the TatClass corresponding to AClassName, only if the current class is descendant from the specified class.
    ///  For example, if this object refers to Delphi class TForm, when you call.
    ///  CastFromString('TWinControl')
    ///  the TatClass corresponding to TWinControl will be retrieved. If TWinControl is not an ancestor or not found, an exception
    ///  is raised.
    ///  </remarks>
    function CastFromString(AClassName: string): TatClass;

    ///  <summary>
    ///  Remove the property specified by the name AName.
    ///  </summary>
    procedure RemoveProperty(AName: string);

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddEnumeration(ATypeInfo: PTypeInfo);

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddObject(AName: string; AObject: TObject);

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddConstant(AName: string; AValue: TScriptValue);

    {$IFNDEF NEXTGEN}
    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: Variant); overload;

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: extended); overload;

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: double); overload;

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: string); overload;

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: Widestring); overload;

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: integer); overload;

    ///  <summary>
    ///  Deprecated. Use DefineProp instead.
    ///  </summary>
    procedure AddVariable(AName: string; var AVar: boolean); overload;
    {$ENDIF}

    ///  <summary>
    ///  Deprecated. Use DefineNewProp/DefineProp instead.
    ///  </summary>
    function AddProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TGenericProc;
      APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
      : TatProperty;

    ///  <summary>
    ///  Deprecated. Use DefineNewProp/DefineProp instead.
    ///  </summary>
    function SetProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TGenericProc;
      APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
      : TatProperty;

    ///  <summary>
    ///  Deprecated. Use DefineNewProp/DefineProp instead.
    ///  </summary>
    procedure AddIntegerProp(AName: string; AGetter, ASetter: TGenericProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Deprecated. Use DefineNewProp/DefineProp instead.
    ///  </summary>
    procedure AddStringProp(AName: string; AGetter, ASetter: TGenericProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Deprecated. Use DefineNewProp/DefineProp instead.
    ///  </summary>
    procedure AddBooleanProp(AName: string; AGetter, ASetter: TGenericProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Deprecated. Use DefineNewProp/DefineProp instead.
    ///  </summary>
    procedure AddFloatProp(AName: string; AGetter, ASetter: TGenericProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Deprecated. Use DefineNewProp/DefineProp instead.
    ///  </summary>
    procedure AddVariantProp(AName: string; AGetter, ASetter: TGenericProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Deprecated. Use DefineNewProp/DefineProp instead.
    ///  </summary>
    procedure AddObjectProp(AName: string; AGetter, ASetter: TGenericProc; APropertyClass: TClass;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Declare the object specified by AObject as a property in the class, accessible through the name AName. You can then access
    ///  AObject instance from script as if it was a property of another object.
    ///  </summary>
    procedure AddDelphiObjectProp(AName: string; AObject: TObject);

    ///  <summary>
    ///  Registers a new property in the class. You don't need to register published properties since they are imported automatically
    ///  by Delphi scripter.
    ///  </summary>
    ///  <param name="ASetter">
    ///  The method wrapper which will be called by the script when the property is written from script. Those are the methods that should actually read or write the real Delphi property.
    /// </param>
    ///  <param name="AGetter">
    ///  The method wrapper which will be called by the script when the property is read from script. Those are the methods that should actually read or write the real Delphi property.
    /// </param>
    ///  <param name="AIsClassProp">
    ///  Indicates if the property is a regular property (accessible from object instance) or a class property.
    /// </param>
    ///  <param name="AName">
    ///  The name by which the property will be accessible from script.
    /// </param>
    ///  <param name="ADataType">
    ///  The data type of the property.
    /// </param>
    ///  <param name="AIndexCount">
    ///  If the registered property is an indexed property, then AIndexCount must contain the number of dimensions of the property.
    /// 
    ///  The function will return the newly created TatProperty.
    ///  If a property with the name AName already exists in the class, nothing is created, and the function will return the existing TatProperty object.
    /// </param>
    ///  <param name="APropertyClass">
    ///  If ADataType is tkClass, then APropertyClass must contain the class of the property (TFont, for example). Otherwise, PropertyClass must be nil.
    /// </param>
    function DefineProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TMachineProc;
      APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
      : TatProperty;

    ///  <remarks>
    ///  Registers a new property in the class. DefineNewProp works the same as DefineProp, with the small difference that
    ///  regardless if a property named AName already exists in the class or not, a new TatProperty will be created. If there was already
    ///  a property with same name, two objects TatProperty relating to the same property will exist in the class.
    ///  Scripter will always use the last one added, so it will work as expected. The advantage of creating two TatProperty objects
    ///  is that you can destroy your created object and still you have the previous one. The disadvantage is that if you call
    ///  DefineNewProp too many times, you will end up with much more memory consumed because of duplicated properties in the TatClass object.
    ///  See DefineProp for more information.
    ///  </remarks>
    function DefineNewProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TMachineProc;
      APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
      : TatProperty;

    ///  <summary>
    ///  Declares an integer property. See DefineProp for more details.
    ///  </summary>
    procedure DefineIntegerProp(AName: string; AGetter, ASetter: TMachineProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Declares a string property. See DefineProp for more details.
    ///  </summary>
    procedure DefineStringProp(AName: string; AGetter, ASetter: TMachineProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Declares a boolean property. See DefineProp for more details.
    ///  </summary>
    procedure DefineBooleanProp(AName: string; AGetter, ASetter: TMachineProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Declares a float property. See DefineProp for more details.
    ///  </summary>
    procedure DefineFloatProp(AName: string; AGetter, ASetter: TMachineProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Declares a variant property. See DefineProp for more details.
    ///  </summary>
    procedure DefineVariantProp(AName: string; AGetter, ASetter: TMachineProc;
      AIsClassProp: boolean = false);

    ///  <summary>
    ///  Declares an object property. See DefineProp for more details.
    ///  </summary>
    procedure DefineObjectProp(AName: string; AGetter, ASetter: TMachineProc;
      APropertyClass: TClass; AIsClassProp: boolean = false);

    ///  <summary>
    ///  Deprecated. Use DefineMethod/DefineNewMethod instead.
    ///  </summary>
    function AddMethod(AName: string; AArgCount: integer; AResultDataType: TatTypeKind;
      AResultClass: TClass; AProc: TGenericProc; AIsClassMethod: boolean = false;
      ADefArgCount: integer = 0): TatMethod;

    ///  <remarks>
    ///  Registers a new method in the class. DefineNewMethod works the same as DefineMethod, with the small difference that
    ///  regardless if a method named AName already exists in the class or not, a new TatMethod will be created. If there was already
    ///  a method with same name, two objects TatMethod relating to the same method will exist in the class.
    ///  Scripter will always use the last one added, so it will work as expected. The advantage of creating two TatMethod objects
    ///  is that you can later destroy your created object and still you have the previous one. The disadvantage is that if you call
    ///  DefineNewMethod too many times, you will end up with much more memory consumed because of duplicated method in the TatClass object.
    ///  See DefineMethod for more information.
    ///  </remarks>
    function DefineNewMethod(AName: string; AArgCount: integer; AResultDataType: TatTypeKind;
      AResultClass: TClass; AProc: TMachineProc; AIsClassMethod: boolean = false;
      ADefArgCount: integer = 0): TatMethod;

    ///  <summary>
    ///  Registers a new method in the class.
    ///  </summary>
    ///  <param name="AParameterHints">
    ///  Optionally you can pass textual info used by scripter to provide code parameter hints. The string must be
    ///  in pascal format, types and default values can be ommited. See the following examples.
    ///  'ParamName;ParamName2'
    ///  'ParamName:string;ParamName2:integer'
    ///  'ParamName1:TObject;ParamName2:integer=0;ParamName3:boolean=false'
    ///  Please note that the content of this string is used only for parameter hinting, and so does not
    ///  affect other important info passed in other parameters, like the number of input parameters
    ///  (AArgCount) or the number of default parameters (ADefArgCount). You still need to properly provide
    ///  such information correctly in other parameters, as they are being ignored in AParameterHints
    /// 
    ///  DefineMethod will return the newly created TatMethod object.
    ///  If a method with the name AName already exists in the class, nothing is created, and DefineMethod will return the existing TatMethod object.
    /// </param>
    ///  <param name="AProc">
    ///  The method wrapper which will be called by the script when the method is to be called from script. This is the method that should actually execute real Delphi method.
    /// </param>
    ///  <param name="AName">
    ///  The name by which the method will be accessible from script.
    /// </param>
    ///  <param name="AResultClass">
    ///  If AResultDataType is tkClass, then AResultClass must contain the class of the result value (TFont, for example). Otherwise, AResultClass must be nil.
    /// </param>
    ///  <param name="AResultDataType">
    ///  The data type returns by the method, in case method is function. If the method is a procedure, this must be tkNone.
    /// </param>
    ///  <param name="AArgCount">
    ///  The number of input arguments received by the method.
    /// </param>
    ///  <param name="ADefArgCount">
    ///  The number of default arguments of the method. Must be equal or lower than AArgCount.
    ///  If AArgCount is 5 and ADefArgCount is 2, for example, it means that last 2 input parameters are optional, so the method can be
    ///  called with 3, 4 or 5 input parameters.
    /// </param>
    ///  <param name="AIsClassMethod">
    ///  Indicates if the method is a regular method (accessible from object instance) or a class method.
    /// </param>
    function DefineMethod(AName: string; AArgCount: integer; AResultDataType: TatTypeKind;
      AResultClass: TClass; AProc: TMachineProc; AIsClassMethod: boolean = false;
      ADefArgCount: integer = 0; AParameterHints: string = ''): TatMethod;

    ///  <summary>
    ///  Contains the name of the class as it is known by scripter. For example, 'TButton'.
    ///  </summary>
    property Name: string read FName write FName;

    ///  <summary>
    ///  Holds the list of properties declared in the class.
    ///  </summary>
    property Properties: TatProperties read FProperties write SetProperties;

    ///  <summary>
    ///  Holds the list of methods declared in the class.
    ///  </summary>
    property Methods: TatMethods read FMethods write SetMethods;

    ///  <summary>
    ///  Contains the name of the class which is the direct ancestor of current class.
    ///  </summary>
    property AncestorName: string read FAncestorName write FAncestorName;

    ///  <summary>
    ///  Holds the Delphi TClass reference that is associated with the current registered class.
    ///  </summary>
    property ClassRef: TClass read FClassRef write FClassRef;

    ///  <summary>
    ///  Contains a reference to the TatClass object which is a direct ancestor of this registered class.
    ///  </summary>
    property Ancestor: TatClass read FAncestor write FAncestor;

    ///  <summary>
    ///  Indicates which is the default property of the class. Used for indexed properties.
    ///  </summary>
    property DefaultProperty: TatProperty read FDefaultProperty write FDefaultProperty;

    /// <summary>
    ///   For internal use only. Do not use this property.
    /// </summary>
    property IsImplicit: boolean read GetIsImplicit;

    /// <summary>
    ///   Indicates the library that registered the class. Used as a kind of
    ///   "namespace" for the class.
    /// </summary>
    property LibContext: string read FLibContext;
  end;

  ///  <summary>
  ///  Holds the list of TatProperty objects which are the registered properties for the class.
  ///  </summary>
  TatProperties = class(TCollection)
  private
    FClass: TatClass;
    function GetItem(i: integer): TatProperty;
  public
    constructor Create(AClass: TatClass);

    ///  <summary>
    ///  Provides indexed access to the TatProperty objects in the collection.
    ///  </summary>
    property Items[i: integer]: TatProperty read GetItem; default;

    ///  <summary>
    ///  Registers a new property using RTTI info for the property. You don't need to call this method because the scripter already
    ///  registers all published properties automatically using AddByRTTI, so will rarely need to use it.
    ///  </summary>
    function AddByRTTI(APropInfo: PPropInfo): TatProperty;

    ///  <summary>
    ///  Returns the index of the TatProperty object associated with the property specified by AName.
    ///  </summary>
    function IndexOf(AName: string): integer;

    ///  <summary>
    ///  Returns the TatProperty object associated with the property specified by AName.
    ///  </summary>
    function PropertyByName(AName: string): TatProperty;

    ///  <summary>
    ///  Returns the TatProperty object associated with the class property specified by AName.
    ///  </summary>
    function ClassPropertyByName(AName: string): TatProperty;

    ///  <summary>
    ///  Provides a reference to the TatClass object in which this property collection is registered.
    ///  </summary>
    property atClass: TatClass read FClass;
  end;

  ///  <summary>
  ///  Contains information about a property registered in scripter system. This information is used by the scripter to know
  ///  if a class contains a specified property, and how this property should be accessed.
  ///  </summary>
  TatProperty = class(TCollectionItem)
  private
    FScripter: TatCustomScripter;
    FName: string;
    FDataType: TatTypeKind;
    FGetter: TGenericProc;
    FSetter: TGenericProc;
    FPropertyClass: TClass;
    FPropertyClassName: string;
    FPropInfo: PPropInfo; // for use with RTTI
    FValue: TScriptValue; // class values
    FIsClassProp: boolean;
    FIndexCount: integer; // > 0 if property is an array
    FLibContext: string;
    procedure RTTIGetterProc(AMachine: TatVirtualMachine);
    procedure RTTISetterProc(AMachine: TatVirtualMachine);
    procedure GetFormComponentProc(AMachine: TatVirtualMachine);
    procedure GetDelphiObjectPropProc(AMachine: TatVirtualMachine);
    procedure GetScriptValuePropProc(AMachine: TatVirtualMachine);
    {$IFNDEF NEXTGEN}
    procedure GetBoolVariablePropProc(AMachine: TatVirtualMachine);
    procedure GetExtVariablePropProc(AMachine: TatVirtualMachine);
    procedure GetDblVariablePropProc(AMachine: TatVirtualMachine);
    procedure GetIntVariablePropProc(AMachine: TatVirtualMachine);
    procedure GetStrVariablePropProc(AMachine: TatVirtualMachine);
    procedure GetWStrVariablePropProc(AMachine: TatVirtualMachine);
    procedure GetVarVariablePropProc(AMachine: TatVirtualMachine);
    procedure SetBoolVariablePropProc(AMachine: TatVirtualMachine);
    procedure SetExtVariablePropProc(AMachine: TatVirtualMachine);
    procedure SetDblVariablePropProc(AMachine: TatVirtualMachine);
    procedure SetIntVariablePropProc(AMachine: TatVirtualMachine);
    procedure SetStrVariablePropProc(AMachine: TatVirtualMachine);
    procedure SetWStrVariablePropProc(AMachine: TatVirtualMachine);
    procedure SetVarVariablePropProc(AMachine: TatVirtualMachine);
    {$ENDIF}
    procedure SetPropExtra(AGetter, ASetter: TGenericProc; AValue: TScriptValue);
    function GetWriteable: boolean;
  protected
    function GetDisplayName: string; override;
  public
    constructor Create(ACollection: TCollection); override;
    procedure Assign(Source: TPersistent); override;

    ///  <remarks>
    ///  Used by internal compiler, you don't need to use this method.
    ///  When a property type is a class, then calling UpdateObjectInfo will retrieve in ACurrentClass the class object the
    ///  corresponds to the property class type. If the class doesn't exist, the scripter automatically registers it and load
    ///  its published properties. Returns true if the property is a class property.
    ///  </remarks>
    function UpdateObjectInfo(var ACurrentClass: TatClass): boolean;

    ///  <summary>
    ///  Provides a reference to the TatClass object in which this property is registered.
    ///  </summary>
    function atClass: TatClass;

    ///  <summary>
    ///  Provides a reference to the scripter object which this registered property belongs to.
    ///  </summary>
    property Scripter: TatCustomScripter read FScripter write FScripter;

    ///  <summary>
    ///  Contains the name of the property.
    ///  </summary>
    property Name: string read FName write FName;

    ///  <summary>
    ///  Holds the method wrapper which will be called by the script when the property is read from script. This is the method
    ///  that should actually read the real Delphi property.
    ///  </summary>
    property Getter: TGenericProc read FGetter write FGetter;

    ///  <summary>
    ///  Holds the method wrapper which will be called by the script when the property is written in script. This is the method
    ///  that should actually write the real Delphi property.
    ///  </summary>
    property Setter: TGenericProc read FSetter write FSetter;

    ///  <summary>
    ///  Holds the data type of the property.
    ///  </summary>
    property DataType: TatTypeKind read FDataType write FDataType;

    ///  <summary>
    ///  Not used.
    ///  </summary>
    property Value: TScriptValue read FValue write FValue;

    ///  <summary>
    ///  Indicates if the property is a regular property (accessible from object instance) or a class property.
    ///  </summary>
    property IsClassProp: boolean read FIsClassProp write FIsClassProp;

    ///  <summary>
    ///  Holds the class of the property. If DataType property is tkClass, then PropertyClass must contain the class of the
    ///  property (TFont, for example). Otherwise, PropertyClass must be nil.
    ///  </summary>
    property PropertyClass: TClass read FPropertyClass write FPropertyClass;

    ///  <summary>
    ///  PropInfo holds RTTI information about the registered property. This property only has a valid value for published properties,
    ///  otherwise its value is nil.
    ///  </summary>
    property PropInfo: PPropInfo read FPropInfo write FPropInfo;

    ///  <summary>
    ///  If the registered property is an indexed property, then IndexCount must contain the number of dimensions of the property.
    ///  </summary>
    property IndexCount: integer read FIndexCount write FIndexCount;

    /// <summary>
    ///   Indicates the library that registered the property. Used as a kind of
    ///   "namespace" for the property.
    /// </summary>
    property LibContext: string read FLibContext;

    property Writeable: boolean read GetWriteable;
  end;

  ///  <summary>
  ///  Holds the list of TatMethod objects which are the registered method for the class.
  ///  </summary>
  TatMethods = class(TCollection)
  private
    FClass: TatClass;
    function GetItem(i: integer): TatMethod;
  public
    constructor Create(AClass: TatClass);

    ///  <summary>
    ///  Provides indexed access to the TatMethod objects in the collection
    ///  </summary>
    property Items[i: integer]: TatMethod read GetItem; default;

    ///  <summary>
    ///  Returns the index of the TatMethod object associated with the method specified by AName.
    ///  </summary>
    function IndexOf(AName: string): integer;

    ///  <summary>
    ///  Returns the TatMethod object associated with the method specified by AName.
    ///  </summary>
    function MethodByName(AName: string): TatMethod;

    ///  <summary>
    ///  Returns the TatMethod object associated with the class method specified by AName.
    ///  </summary>
    function ClassMethodByName(AName: string): TatMethod;

    ///  <summary>
    ///  Provides a reference to the TatClass object in which this method is registered.
    ///  </summary>
    property atClass: TatClass read FClass;
  end;

  ///  <summary>
  ///  Contains information about a method registered in scripter system. This information is used by the scripter to know
  ///  if a class contains a specified method, and how this method should be accessed.
  ///  </summary>
  TatMethod = class(TCollectionItem)
  private
    FScripter: TatCustomScripter;
    FName: string;
    FProc: TGenericProc;
    FResultDataType: TatTypeKind;
    FArgCount: integer;
    FCode: pointer; // for use with internal procs
    FResultClass: TClass;
    FArgDefs: TatDataDefs;
    FIsClassMethod: boolean;
    FByRefArgMask: integer;
    FDefArgCount: integer;
    FResultClassName: string;
    FLibContext: string;
    procedure SetArgDefs(const Value: TatDataDefs);
    // variable arguments bit mask (just initial 32 arguments will be checked in compile time!!!)
    procedure AdjustArgDefsCount;
    procedure SetArgCount(const Value: integer);
  protected
    function GetDisplayName: string; override;
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;

    ///  <remarks>
    ///  Used by internal compiler, you don't need to use this method.
    ///  When a method result type is a class, then calling UpdateObjectInfo will retrieve in ACurrentClass the class object that
    ///  corresponds to the method return type. If the class doesn't exist, the scripter automatically registers it and load
    ///  its published properties. Returns true if the method return type is a class.
    ///  </remarks>
    function UpdateObjectInfo(var ACurrentClass: TatClass): boolean;

    ///  <remarks>
    ///  Use SetVarArgs to specify which input parameters must be passed by reference to the method. argi must contain an array
    ///  of byte with the index of the parameters, zero being the first parameter. For example, if you have the following Delphi
    ///  method you want to register in scriper.
    ///  <code>
    ///  procedure MyDelphiMethod(var A, B; integer; C: string; var D: string);
    ///  </code>
    ///  you can register that method this way.
    ///  <code>
    ///  with DefineMethod('MyDelphiMethod', 4, tkNone, nil, MyDelphiMethodProc, 0) do
    ///  SetVarArgs([0, 1, 4]); //First, Second and Third parameters are passed by reference
    ///  </code>
    ///  </remarks>
    procedure SetVarArgs(argi: array of byte);

    ///  <remarks>
    ///  Check if an input parameter is specified to be passed by reference.
    ///  IsByRefArg returns true if the n-th input parameter indicated by n is declared to be passed by reference. For the first
    ///  input parameter, n must be zero.
    ///  See SetVarArgs method for more information.
    ///  </remarks>
    function IsByRefArg(n: byte): boolean;

    ///  <summary>
    ///  Provides a reference to the TatClass object in which this method is registered.
    ///  </summary>
    function atClass: TatClass;

    ///  <remarks>
    ///  Use this method to define textual info of the method to by used by scripter to provide code parameter hints. The string must be
    ///  in pascal format, types and default values can be ommited. See following examples.
    ///  'ParamName;ParamName2'
    ///  'ParamName:string;ParamName2:integer'
    ///  'ParamName1:TObject;ParamName2:integer=0;ParamName3:boolean=false'
    ///  Please note that the content of this string is used only for parameter hinting, and so does not
    ///  affect other important properties like the number of input parameters
    ///  (ArgCount) or the number of default parameters (DefArgCount). You still need to properly provide
    ///  such information correctly in other parameters, as they are being ignored in AParameterHints
    ///  </remarks>
    procedure UpdateParameterHints(const AParameterHints: string);

    ///  <summary>
    ///  Provides a reference to the scripter object which this registered method belongs to.
    ///  </summary>
    property Scripter: TatCustomScripter read FScripter write FScripter;

    ///  <summary>
    ///  Contains the name by which the method will be accessible from script.
    ///  </summary>
    property Name: string read FName write FName;

    ///  <summary>
    ///  Contains the method wrapper which will be called by the script when the method referenced. This is the method that
    ///  should actually execute real Delphi method.
    ///  </summary>
    property Proc: TGenericProc read FProc write FProc;

    ///  <summary>
    ///  Holds the data type returned by the method, in case method is function. If the method is a procedure, this must be tkNone.
    ///  </summary>
    property ResultDataType: TatTypeKind read FResultDataType write FResultDataType;

    ///  <summary>
    ///  Contains the number of input arguments received by the method.
    ///  </summary>
    property ArgCount: integer read FArgCount write SetArgCount;

    ///  <remarks>
    ///  Contains the number of default arguments of the method. Must be equal or lower than ArgCount.
    ///  If ArgCount is 5 and ADefArgCount is 2, for example, it means that last 2 input parameters are optional, so the method can be
    ///  called with 3, 4 or 5 input parameters.
    ///  </remarks>
    property DefArgCount: integer read FDefArgCount write FDefArgCount;

    ///  <summary>
    ///  ArgDefs is a collection of TatDataDef objects that hold extra information about the method's input parameters.
    ///  </summary>
    property ArgDefs: TatDataDefs read FArgDefs write SetArgDefs;

    ///  <summary>
    ///  Indicates if the method is a regular method (accessible from object instance) or a class method.
    ///  </summary>
    property IsClassMethod: boolean read FIsClassMethod write FIsClassMethod;

    { Not used. }
    property Code: pointer read FCode write FCode;

    ///  <summary>
    ///  if ResultDataType is tkClass, then ResultClass must contain the class of the result value (TFont, for example).
    ///  Otherwise, ResultClass must be nil.
    ///  </summary>
    property ResultClass: TClass read FResultClass write FResultClass;

    ///  <remarks>
    ///  ByRefArgMask contains information about which input parameters in the method must be passed by reference (using var/byref
    ///  modifier), according to what was previously set using SetVarArgs method. ByRefArgMask is a bit mask, in which each bit
    ///  represents a parameter, being the less significant bit the first parameter, and so on. Below are some examples.
    ///  <code>
    ///  //Parameter AResult is by reference. Index of AResult is 2 (3rd parameter)
    ///  //ByRefArgMask will be in binary 100 (3rd less signficant bit set)
    ///  //So ByRefArgMas integer value will be 4
    ///  procedure MyRoutine(AName: string; AValue: integer; var AResult: boolean);
    /// 
    ///  //Parameters Value1, Value2 and Error are passed by reference.
    ///  //Index of parameters are 0, 1 and 3 (1st, 2nd and 4th parameters)
    ///  //ByRefArgMask will be in binary 1011
    ///  //So ByRefArgMas integer value will be 11
    ///  procedure SwapValues(var Value1, Value2: integer; Flag: string; var Error: integer);
    /// 
    ///  DO NOT set ByRefArgMask directly to specify which parameters are passed by reference, use SetVarArgs method instead.
    ///  </code>
    ///  </remarks>
    property ByRefArgMask: integer read FByRefArgMask write FByRefArgMask;

    /// <summary>
    ///   Indicates the library that registered the method. Used as a kind of
    ///   "namespace" for the method.
    /// </summary>
    property LibContext: string read FLibContext;
  end;

  ///  <summary>
  ///  TatDataDefs is a collection of TatDataDef objects that hold information about the input parameters of a specified method.
  ///  You can have name, modifier, data type, among other information for each input parameter.
  ///  </summary>
  TatDataDefs = class(TCollection)
  private
    function GetItem(i: integer): TatDataDef;
  public
    constructor Create(AClass: TatClass);

    ///  <summary>
    ///  Provides indexed-access to a TatDataDef object in the collection.
    ///  </summary>
    property Items[i: integer]: TatDataDef read GetItem; default;

    ///  <summary>
    ///  Adds a new TatDataDef object in the collection. Do not call this method directly, it's only used internally
    ///  by the scripter.
    ///  </summary>
    function Add(AName: string; ADataType: TatTypeKind; AModifier: TatArgumentModifier): TatDataDef;
  end;

  ///  <summary>
  ///  Holds information about a input parameter in a registered method.
  ///  </summary>
  TatDataDef = class(TCollectionItem)
  private
    FName: string;
    FDataType: TatTypeKind;
    FModifier: TatArgumentModifier;
    FDataTypeName: string;
    FDefaultValueText: string;
  public
    procedure Assign(ASource: TPersistent); override;

    ///  <summary>
    ///  Contains the name of the input parameters. It's not being used for now, in future this might be used for code-insight
    ///  operations, for example.
    ///  </summary>
    property Name: string read FName;

    ///  <summary>
    ///  Contains the data type of the input parameter. This information is not being used by the scripter yet.
    ///  </summary>
    property DataType: TatTypeKind read FDataType;

    ///  <summary>
    ///  Contains the modifier of the input parameter (const, var, etc.).
    ///  </summary>
    property Modifier: TatArgumentModifier read FModifier write FModifier;

    ///  <summary>
    ///  Contains the textual data type of the input parameter. For example, 'string' or 'TObject'
    ///  </summary>
    property DataTypeName: string read FDataTypeName;

    ///  <summary>
    ///  Contains the textual default value of input parameter, for example 'false' or '0'.
    ///  If the param doesn't have a default value, this is an empty string
    ///  </summary>
    property DefaultValueText: string read FDefaultValueText;
  end;

  ///  <summary>
  ///  Holds a list of object instances that are being accessible from scripts in a "default" way (methods and properties
  ///  are directly accessed).
  ///  </summary>
  TatObjects = class(TCollection)
  private
    FClasses: TatClasses;
    function GetItem(i: integer): TatObject;
  public
    constructor Create(AClasses: TatClasses);

    ///  <summary>
    ///  Adds a new object instance. See TatCustomScripter.UsesObject for more info on parameters.
    ///  </summary>
    function Add(AInstance: TObject; AName: string = ''; AClassName: string = ''): TatObject;

    ///  <summary>
    ///  Returns the index of TatObject which holds the method specified by AMethodName. If the method is found,
    ///  a reference to it is returned in AMethod parameter.
    ///  </summary>
    function FindInstanceByMethodName(AMethodName: string; var AMethod: TatMethod): integer;

    ///  <summary>
    ///  Returns the index of TatObject which holds the property specified by APropertyName. If the property is found,
    ///  a reference to it is returned in AProperty parameter.
    ///  </summary>
    function FindInstanceByPropertyName(APropertyName: string; var AProperty: TatProperty): integer;

    ///  <summary>
    ///  Returns the TatObject instance which correspondes to the class name specified by AClassName.
    ///  See TatCustomScripter.UsesObject for more information.
    ///  </summary>
    function FindInstanceByClassName(AClassName: string): TatObject;

    ///  <summary>
    ///  Returns the index in the collection of the object specified by AName.
    ///  </summary>
    function IndexOf(AName: string): integer;

    ///  <summary>
    ///  Provides indexed-access to the TatObject objects in the collection.
    ///  </summary>
    property Items[i: integer]: TatObject read GetItem; default;
  end;

  ///  <summary>
  ///  Holds information about an object instance that is being accessible from scripts in a "default" way (methods and properties
  ///  are directly accessed).
  ///  </summary>
  TatObject = class(TCollectionItem)
  private
    FName: string;
    FInstance: TObject;
    FatClass: TatClass;
    procedure SeTatClass(const Value: TatClass);
  public
    procedure Assign(ASource: TPersistent); override;

    ///  <summary>
    ///  Holds the name by which the object can be accessed from script.
    ///  </summary>
    property Name: string read FName write FName;

    ///  <summary>
    ///  Holds the instance of the object that can be accessed from script.
    ///  </summary>
    property Instance: TObject read FInstance write FInstance;

    ///  <summary>
    ///  Contains a reference to the TatClass object holding information about the class of the object, its methods and
    ///  properties than can be accessed in a default way.
    ///  </summary>
    property atClass: TatClass read FatClass write SeTatClass;
  end;

  ///  <remarks>
  ///  This class is used internally by scripter system. Do not bother about it.
  ///  Contains a list of classes referenced implicit from the script (like a property of type TFont being accessed,
  ///  a reference for TFont is registered.
  ///  This is used for saving compiled code properly, so when loading the code, scripter can recover/re-register all
  ///  classes implicitly registered during compilation.
  ///  </remarks>
  TatClassRefs = class(TCollection)
  private
    FScript: TatScript;
    function GetItem(i: integer): TatClassRef;
  public
    constructor Create(AScript: TatScript);
    function Add(AClassIndex, AElementIndex, AElementClassIndex: integer; AElementIsMethod: boolean;
      AClassName, AElementName, AElementClassName: string): TatClassRef;
    property Items[i: integer]: TatClassRef read GetItem; default;
  end;

  ///  <summary>
  ///  Used internally by scripter system. Do not use it.
  ///  See TatClassRefs for more details.
  ///  </summary>
  TatClassRef = class(TCollectionItem)
  private
    FClassIndex: integer; // relative to TatClasses instance
    FElementIndex: integer; // relative to TatMethods or TatProperties
    FElementIsMethod: boolean; // true if element is a method, false if element is a property
    FElementName: string;
    FClassName: string;
    FElementClassName: string;
    FElementClassIndex: integer;
  public
    procedure CheckLoaded;
    property ClassIndex: integer read FClassIndex;
    property ElementIndex: integer read FElementIndex;
    property ElementIsMethod: boolean read FElementIsMethod;
    property ElementClassIndex: integer read FElementClassIndex;
  end;

  ///  <summary>
  ///  Holds information about a unit used in the script. See TatScript.UsedUnits property for more info.
  ///  </summary>
  TatUsedUnit = class(TCollectionItem)
  private
    FIsDefault: boolean;
    FUnitName: string;
    FIsScript: boolean;
    FDeclSourcePos: integer;
  public
    {$WARNINGS OFF}
    ///  <summary>
    ///  Contains the name of used unit.
    ///  </summary>
    property UnitName: string read FUnitName write FUnitName;

    ///  <summary>
    ///  Indicates if the unit, as a library, was registered using Default parameter. See RegisterScripterLibrary procedure
    ///  for more information.
    ///  </summary>
    property IsDefault: boolean read FIsDefault write FIsDefault;

    ///  <summary>
    ///  Indicates if the used unit was a script-based library.
    ///  </summary>
    property IsScript: boolean read FIsScript write FIsScript;

    ///  <summary>
    ///  Indicates the position of the source code in which the used unit was declared (in uses clause).
    ///  </summary>
    property DeclSourcePos: integer read FDeclSourcePos write FDeclSourcePos;
  end;

  ///  <summary>
  ///  Holds a collection of TatUsedUnit objects related to the used units in the script. See TatScript.UsedUnits property for more info.
  ///  </summary>
  TatUsedUnits = class(TCollection)
  private
    FScripter: TatCustomScripter;
    function GetItem(i: integer): TatUsedUnit;
  public
    constructor Create(AScripter: TatCustomScripter);

    ///  <summary>
    ///  Returns the TatUsedUnit object for the used unit specified by the name AUnitName.
    ///  </summary>
    function FindByName(AUnitName: string): TatUsedUnit;

    ///  <summary>
    ///  Adds a new used unit. Do not use this method, it is used internally by the compiler.
    ///  </summary>
    function Add: TatUsedUnit;

    ///  <summary>
    ///  Provides indexed-access to the TatUsedUnit objects in the collection.
    ///  </summary>
    property Items[i: integer]: TatUsedUnit read GetItem; default;
  end;

  {$M+}

  ///  <remarks>
  ///  TatScripterLibrary is the ancestor class for all Delphi-based libraries that can be registered in the scripter.
  ///  Descendants of this class can be registered in script system using RegisterScripterLibrary procedure, or
  ///  TatCustomScripter.AddLibrary method. See also TatCustomScripter.LoadLibrary.
  ///  Main method in class is Init. Override Init method to register classes, methods and properties in scripter.
  ///  Other methods can be overriden as well, like Finalize and LibraryName.
  ///  </remarks>
  TatScripterLibrary = class
  private
    FScripter: TatCustomScripter;

    ///  <summary>
    ///  Used to destroy the default instance create. For now, this is just for internal use
    ///  in AddLibraryInstance and RemoveLibraryInstance.
    ///  </summary>
    FDefaultInstanceName: string;
    procedure SelfProc(AMachine: TatVirtualMachine);
  protected
    ///  <remarks>
    ///  Init method is called when this library is registered using TatCustomScripter.AddLibrary method, or when the
    ///  library is initialized after found by the scripter in the uses clause of some script.
    ///  You must override Init method in your libraries to register classes, methods and properties in the scripter.
    ///  </remarks>
    procedure Init; virtual; abstract;

    ///  <summary>
    ///  Finalize method is called by the scripter when the library is removed from the scripter. Override Finalize method
    ///  to remove all classes, methods and properties you have previously registered in Init method.
    ///  </summary>
    procedure Finalize; virtual;

    ///  <summary>
    ///  Provides a reference to the Scripter object in which you this library must register the classes, methods and properties.
    ///  </summary>
    property Scripter: TatCustomScripter read FScripter;
  public
    ///  <summary>
    ///  Override class function LibraryName to provide the name for which the library will be known by scripter.
    ///  </summary>
    class function LibraryName: string; virtual;

    ///  <summary>
    ///  Creates a new library instance. You do not need to create scripter library instances, they are created automatically
    ///  by scripter
    ///  </summary>
    constructor Create(AScripter: TatCustomScripter); virtual;
  end;
  {$M-}

  ///  <remarks>
  ///  TatDLL is a special TatScripterLibrary descendant that holds registered methods that will actually call dll functions.
  ///  TatDLL holds a reference to a internal TatClass object.
  ///  When a script declares a function that is a prototype to a dll function, a new method is registered in the internal class
  ///  so that scripter recognized that method as a valid procedure. When that method is called, the actual dll function is executed.
  ///  </remarks>
  TatDLL = class(TatScripterLibrary)
  private
    FScript: TatScript;
    FFileName: string;
    FatClass: TatClass;
  public
    ///  <summary>
    ///  Initialized the library. Just registered the class of this library in the scripter.
    ///  </summary>
    procedure Init; override;

    ///  <summary>
    ///  Remove all methods registered in the class.
    ///  </summary>
    procedure Finalize; override;

    ///  <summary>
    ///  Returns the internal _DLL_ name for the library.
    ///  </summary>
    class function LibraryName: string; override;
  end;

  ///  <remarks>
  ///  TatScriptBasedLibrary is a special TatScripterLibrary descendant that allows scripts to be registered as libraries.
  ///  When a script is registered as a library, its methods and properties are accessible from script. This class
  ///  helps it make it happen.
  ///  You will not need to use this class, it is used internally by the scripter to allow script-based libraries.
  ///  </remarks>
  TatScriptBasedLibrary = class(TatScripterLibrary)
  private
    FInternalScript: TatScript;
    FName: string;
    FMethodList: TList;
    FPropList: TList;
    FRegClass: TClass;
    FRegClassName: string;
    FNewClass: TatClass;
    function GetRunScript(AMachine: TatVirtualMachine): TatScript;
    procedure ExecSubRoutineProc(AMachine: TatVirtualMachine);
    procedure GetScriptVarProc(AMachine: TatVirtualMachine);
    procedure SetScriptVarProc(AMachine: TatVirtualMachine);
  protected
    ///  <summary>
    ///  Registers the routines and global variables in the script as default methods and properties in the scripter to
    ///  be accessible from other scripts.
    ///  </summary>
    procedure Init; override;

    ///  <summary>
    ///  Removes all methods and properties registered by Init method.
    ///  </summary>
    procedure Finalize; override;
  public
    constructor Create(AScripter: TatCustomScripter); override;
    destructor Destroy; override;
  end;

  ///  <summary>
  ///  Holds information about a library registered with RegisterScripterLibrary.
  ///  You don't need to use this class, it's used internally by scripter.
  ///  </summary>
  TatLibraryListItem = class(TCollectionItem)
  private
    FLibraryClass: TatScripterLibraryClass;
    FExplicitLoad: boolean;
  public
    procedure Assign(Source: TPersistent); override;

    ///  <summary>
    ///  Contains the reference to the library class. This class will be instantiated in the case of the library to be
    ///  requested from a script in the uses clause.
    ///  </summary>
    property LibraryClass: TatScripterLibraryClass read FLibraryClass write FLibraryClass;

    ///  <remarks>
    ///  When ExplicitLoad is true, the library specified by LibraryClass will always be instantiated and automaticaly used
    ///  when a new scripter component is created. If it is false, the library will only be used if it is explicity requested
    ///  from script in a uses clause.
    ///  <code>
    ///  uses MyLibrary;
    ///  </code>
    ///  </remarks>
    property ExplicitLoad: boolean read FExplicitLoad write FExplicitLoad;
  end;

  ///  <summary>
  ///  Holds a list of the libraries registered with RegisterScripterLibrary.
  ///  You don't need to use this class, it's used internally by scripter.
  ///  </summary>
  TatLibraryList = class(TCollection)
  private
    function GetItem(Index: integer): TatLibraryListItem;
  public
    ///  <summary>
    ///  Adds a new item. Do not use it. See RegisterScripterLibrary procedure for more information.
    ///  </summary>
    function Add: TatLibraryListItem;

    ///  <summary>
    ///  Removes an item. Do not use it. See RegisterScripterLibrary procedure for more information.
    ///  </summary>
    procedure Remove(ALibrary: TatScripterLibraryClass);

    ///  <summary>
    ///  Finds a library by its name. Do not use it. See RegisterScripterLibrary procedure for more information.
    ///  </summary>
    function FindByLibraryName(ALibName: string): TatLibraryListItem;

    ///  <summary>
    ///  Provides indexed-access to the library items. Do not use it. See RegisterScripterLibrary procedure for more information.
    ///  </summary>
    property Items[Index: integer]: TatLibraryListItem read GetItem; default;
  end;

  ///  <remarks>
  ///  TatScripterEventBroker is a class used by scripter to manipulate Delphi events. You will often set Delphi event handlers
  ///  from script, and want the events to be handled by script routines. This broker makes this happen, providing you methods
  ///  to set events, remove events, informing the object, the event name, and the script routine that will handle the event.
  ///  In addition, the event broker provides a stack mechanism, where the event handler set by the broker doesn't need to completely
  ///  remove th previous event set. Instead, you have the option to keep the previous event being executed.
  ///  Also, when you remove the event set by the broker, the previous event set is recovered.
  ///  </remarks>
  TatScripterEventBroker = class(TComponent)
  private
    FScripter: TatCustomScripter;
    FDispatchers: TatEventDispatchers;
    FOnExecuteEvent: TExecuteEventProc;
    FOnSettingEvent: TSettingEventProc;
    FOnSetEvent: TSetEventProc;
    FOnUnsettingEvent: TUnsetEventProc;
    FEventAdapters: TatEventAdapters;
    function InternalSetEvent(AInstance: TObject; APropInfo: PPropInfo; ARoutineName: string;
      AScripter: TatCustomScripter; APlacement: TatEventPlacement; AScript: TatScript)
      : TatEventDispatcher;
    function InternalUnsetEvent(AInstance: TObject; APropInfo: PPropInfo; ARoutineName: string;
      AScripter: TatCustomScripter): boolean;
    function InternalUnsetEvents(AInstance: TObject; APropInfo: PPropInfo): boolean;
    procedure SetDispatchers(const Value: TatEventDispatchers);
    procedure SetOnExecuteEvent(const Value: TExecuteEventProc);
    procedure SetOnSetEvent(const Value: TSetEventProc);
    procedure SetOnUnsettingEvent(const Value: TUnsetEventProc);
    function GetOldMethod(m: TMethod): TMethod;
    function MethodIsDesiredDispatcher(m: TMethod; ARoutineName: string;
      AScripter: TatCustomScripter): boolean;
    function GetDispatcherFromMethod(m: TMethod): TatEventDispatcher;
    procedure SetOnSettingEvent(const Value: TSettingEventProc);
    function GetMethodPropEx(AInstance: TObject; APropInfo: PPropInfo): TMethod;
    procedure SetMethodPropEx(AInstance: TObject; APropInfo: PPropInfo; AMethod: TMethod);
  protected
    { Protected declarations }
  public
    { Public declarations }
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    ///  <summary>
    ///  Sets a new event handler for a Delphi object's event.
    ///  </summary>
    ///  <param name="AInstance">
    ///  Contains the instance of the object for which the event will be set, for example, a button object
    /// </param>
    ///  <param name="ARoutineName">
    ///  Contains the name of the script routine name that will handle the event, for example, 'Button1Click'
    /// </param>
    ///  <param name="AScripter">
    ///  Contains the scripter object which holds the script containing the routine
    /// </param>
    ///  <param name="APlacement">
    ///  Indicates how this new event will replace the existing one
    /// </param>
    ///  <param name="APropName">
    ///  Contains the name of the event to be set, for example, 'OnClick'
    /// </param>
    ///  <param name="AScript">
    ///  Contains the script object which holds the routine. If AScript is nil, the current script of scripter component will be used
    /// 
    ///  This method creates a new TatEventDispatcher object to handle the object's event, and return it as the result value.
    /// </param>
    function SetEvent(AInstance: TObject; APropName: string; ARoutineName: string;
      AScripter: TatCustomScripter; APlacement: TatEventPlacement; AScript: TatScript = nil)
      : TatEventDispatcher;

    ///  <summary>
    ///  Unsets an event handler for a Delphi object's event which was previously set with SetEvent.
    ///  </summary>
    ///  <param name="AInstance">
    ///  Contains the instance of the object for which the event will be unset
    /// </param>
    ///  <param name="ARoutineName">
    ///  Must be empty if you want to remove the last event set. If you want to remove an event that was not the last
    ///  one set, then specify the script routine name to be removed
    /// </param>
    ///  <param name="AScripter">
    ///  Contains the scripter object which holds the script routine to be removed as an event handler
    /// 
    ///  Unset event returns true if the event handler did exist and was removed. It returns false if for example the routine name
    ///  didn't exist, or the object event was just not previously set with SetEvent.
    /// </param>
    ///  <param name="APropName">
    ///  Contains the name of the event to be unset, for example, 'OnClick'
    /// </param>
    function UnsetEvent(AInstance: TObject; APropName: string; ARoutineName: string = '';
      AScripter: TatCustomScripter = nil): boolean;

    ///  <summary>
    ///  Remove all event handlers set in the object AInstance for the event specified by APropName.
    ///  See UnsetEvent method for more information.
    ///  </summary>
    function UnsetEvents(AInstance: TObject; APropName: string): boolean;

    ///  <summary>
    ///  Returns the name of script routine currently assigned to be the handler of the object's event.
    ///  </summary>
    ///  <param name="AInstance">
    ///  the instance of the object which contains the event
    /// </param>
    ///  <param name="APropName">
    ///  the name of the event. For example, 'OnClick'
    /// </param>
    ///  <param name="AScripter">
    ///  the scripter component which holds the routine assigned to the event
    /// 
    ///  If no script routine is assigned, the method returns an empty string.
    /// </param>
    function GetAssignedRoutineName(AInstance: TObject; APropName: string;
      AScripter: TatCustomScripter): string;

    ///  <summary>
    ///  Unset all events assigned by this event broker. See UnsetEvent for more details.
    ///  </summary>
    procedure UnsetAllEvents;

    ///  <summary>
    ///  Holds a list of event adapters registered in scripting system. This is just a pointer to the global variable
    ///  EventAdapters.
    ///  </summary>
    property EventAdapters: TatEventAdapters read FEventAdapters write FEventAdapters;
  published
    ///  <summary>
    ///  Holds the list of current event dispatcher. An event dispatcher is created for each event set. See
    ///  TatEventDispatchers for more info.
    ///  </summary>
    property Dispatchers: TatEventDispatchers read FDispatchers write SetDispatchers;

    ///  <summary>
    ///  OnExecuteEvent is fired whenever an event is fired in Delphi object and handled by the dispatcher.
    ///  </summary>
    property OnExecuteEvent: TExecuteEventProc read FOnExecuteEvent write SetOnExecuteEvent;

    ///  <summary>
    ///  OnSettingEvent is fired when an event is about to be set by the event broker.
    ///  </summary>
    property OnSettingEvent: TSettingEventProc read FOnSettingEvent write SetOnSettingEvent;

    ///  <summary>
    ///  OnSetEvent is fired when an event is set by the event broker.
    ///  </summary>
    property OnSetEvent: TSetEventProc read FOnSetEvent write SetOnSetEvent;

    ///  <summary>
    ///  OnUnsettingEvent is fired when an event is about to be unset by the event broker.
    ///  </summary>
    property OnUnsettingEvent: TUnsetEventProc read FOnUnsettingEvent write SetOnUnsettingEvent;
  end;

  ///  <remarks>
  ///  Holds a collection of all event adapters registered in the scripter. You need to register an adapter for each event type.
  ///  For example, TNotifyEvent must have an adapter. Once you register it, all events in any object that are of TNotifyEvent type
  ///  (Button OnClick, Combo OnChange, OnEnter, OnExit, etc.) are supported by the scripter.
  ///  You must include a new event adapter using method or procedure DefineEventAdapter.
  ///  </remarks>
  TatEventAdapters = class(TCollection)
  private
    function GetItem(i: integer): TatEventAdapter;
  public
    ///  <summary>
    ///  Do not call this directly. Use DefineEventAdapter instead.
    ///  </summary>
    function Add: TatEventAdapter;

    ///  <summary>
    ///  Provides indexed-access to all adapters registered in the scripter.
    ///  </summary>
    property Items[i: integer]: TatEventAdapter read GetItem; default;

    ///  <summary>
    ///  Finds the event adapter for the event type specified by ARttiInfo. If no adapter is registered for the event type,
    ///  FindAdapter returns nil.
    ///  </summary>
    function FindAdapter(ARttiInfo: PTypeInfo): TatEventAdapter;

    ///  <summary>
    ///  Finds the event adapter for the event property specified by APropInfo. If no adapter is registered for the event type,
    ///  AdapterByPropInfo returns nil.
    ///  </summary>
    function AdapterByPropInfo(APropInfo: PPropInfo): TatEventAdapter;

    ///  <param name="ARttiInfo">
    ///  Contains RTTI info about the event type being supported (TNotifyEvent, for example)
    /// </param>
    ///  <param name="ADispatcherClass">
    ///  Contains class of the TatEventDispatcher descendant that will be instantiated when an event is set. The dispatcher will implement the event handling, taking care of calling the script routine name to be executed and passing the correct parameters.
    /// </param>
    ///  <param name="AMethodCode">
    ///  Contains the address of a method in the dispatcher class that will be called when the event fires.
    /// </param>
    ///  <param name="ACheck">
    ///  If true, it will first check if an adapter already exists for the event. If it does, then it updates the current adapter. If Check is false, it will always create a new adapter.
    /// 
    ///  This method returns the created TatEventAdapter object. You will rarely need this returned object.
    /// 
    /// </param>
    ///  <remarks>
    ///  Defines a new event adapter for the event type specified by ARttiInfo.
    ///  For example, TNotifyEvent must have an adapter. Once you register it, all events in any object that are of TNotifyEvent type
    ///  (Button OnClick, Combo OnChange, OnEnter, OnExit, etc.) are supported by the scripter.
    ///  </remarks>
    ///  <example>
    ///  To define an event adapter for the TKeyEvent. The TKeyEvent is declared in the VCL as following.
    ///  <code>
    ///  TKeyEvent = procedure( Sender: TObject; var Key: Word;  Shift: TShiftState) of object;
    ///  </code>
    ///  So you need to register a new adapter using the following call to DefineEventAdapter.
    ///  <code>
    ///  DefineEventAdapter(TypeInfo(TKeyEvent), TatMyKeyEventDispatcher, @TatMyKeyEventDispatcher.__TKeyEvent);
    ///  </code>
    ///  In the first parameter you pass the type info of the TKeyEvent type.
    ///  In second parameter, the dispatcher class to be instantiated that will handle the event and dispatch it to scritper.
    ///  In third parameter, the address of the method in dispatcher class that will be called when the event fires.
    /// 
    ///  You can then implement your dispatcher this way.
    ///  <code>
    ///  TatMyKeyEventDispatcher = class(TatEventDispatcher)
    ///  private
    ///  procedure __TKeyEvent( Sender: TObject; var Key: Word;  Shift: TShiftState);
    ///  end;
    /// 
    ///  procedure TatMyKeyEventDispatcher.__TKeyEvent( Sender: TObject; var Key: Word;  Shift: TShiftState);
    ///  var
    ///  KeyTemp: variant;
    ///  ShiftTempSet: TShiftState;
    ///  ShiftTemp: variant;
    ///  begin
    ///  if DoOnExecuteEvent then
    ///  begin
    ///  //Call event previous set
    ///  if AssignedMethod(BeforeCall) then
    ///  TKeyEvent(BeforeCall)(Sender,Key,Shift);
    /// 
    ///  //Put Key in a variant type so that script routine can update its value
    ///  KeyTemp := Integer(Key);
    /// 
    ///  //Converts TShiftState to integer so it can be read from script
    ///  ShiftTempSet := Shift;
    ///  ShiftTemp := IntFromSet(ShiftTempSet, SizeOf(ShiftTempSet));
    /// 
    ///  //Execute the script routine that will handle the event, passing the event parameters to it
    ///  if Assigned(Scripter) and (RoutineName > '') then
    ///  Scripter.ExecuteSubroutine(RoutineName, [Sender,KeyTemp,ShiftTemp]);
    /// 
    ///  //Update the Key parameter received from the script
    ///  Key := VarToInteger(KeyTemp);
    /// 
    ///  //Call event previous set
    ///  if AssignedMethod(AfterCall) then
    ///  TKeyEvent(AfterCall)(Sender,Key,Shift);
    ///  end;
    ///  </code>
    ///  </example>
    function DefineEventAdapter(ARttiInfo: PTypeInfo; ADispatcherClass: TDispatcherClass;
      AMethodCode: pointer; ACheck: boolean): TatEventAdapter;
  end;

  ///  <summary>
  ///  Holds the information for the event adapter. You don't need to use this class, it holds only private information.
  ///  </summary>
  TatEventAdapter = class(TCollectionItem)
  private
    FRttiInfo: PTypeInfo;
    FMethodCode: pointer;
    FDispatcherClass: TDispatcherClass;
  public
    procedure Assign(ASource: TPersistent); override;
  end;

  ///  <remarks>
  ///  Holds the collection of the event dispatchers created by the event broker. When an event is set, a dispatcher is created
  ///  to take care of event handling and passing the execution control to the specified script routine.
  ///  You will rarely need to deal with dispatchers, they are created and destroyed automatically by scripter
  ///  when you set or unset events.
  ///  </remarks>
  TatEventDispatchers = class(TOwnedCollection)
  private
    function GetItem(i: integer): TatEventDispatcher;
  public
    function Add: TatEventDispatcher;
    property Items[i: integer]: TatEventDispatcher read GetItem; default;
  end;

  ///  <remarks>
  ///  Contains information about how to dispatch an event from Delphi to scripter. When the event broker sets a new event,
  ///  it creates a new TatEventDispatcher object to handle the event fired from Delphi. The dispatcher will take care
  ///  of passing the event handling to the specified script routine.
  ///  You will rarely need to deal with dispatchers, they are created and destroyed automatically by scripter
  ///  when you set or unset events.
  ///  </remarks>
  TatEventDispatcher = class(TCollectionItem)
  private
    FBeforeCall: TMethod;
    FAfterCall: TMethod;
    FOldCall: TMethod; // just for event restoring
    FScripter: TatCustomScripter;
    FRoutineName: string;
    FCustomCall: TMethod; // for use instead of Scripter + RoutineName
    FAdapter: TatEventAdapter; // general usage, like a event runtime type information
    FInstance: TObject; // general usage, like a event runtime type information
    FPropInfo: PPropInfo; // general usage, like a event runtime type information
    FNotificator: TatDispatcherRemoveNotificator;
    // allow remove notifications from Instance (TComponent) to be perceived
    FIsComponent: boolean;
    FScript: TatScript;
    procedure SetScripter(const Value: TatCustomScripter);
    procedure SetAfterCall(const Value: TMethod);
    procedure SetBeforeCall(const Value: TMethod);
    procedure SetOldCall(const Value: TMethod);
    procedure SetAdapter(const Value: TatEventAdapter);
    procedure SetInstance(const Value: TObject);
    procedure SetPropInfo(const Value: PPropInfo);
  protected
    function DoOnExecuteEvent: boolean;
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;

    ///  <summary>
    ///  Unset the event of this dispatcher.
    ///  </summary>
    procedure Unset;

    ///  <summary>
    ///  Provides a reference to the event broker which owns this dispatcher.
    ///  </summary>
    function EventBroker: TatScripterEventBroker;

    ///  <summary>
    ///  Provides a reference to the scripter component which contains the script routine which to be executed when
    ///  the Delphi event fires.
    ///  </summary>
    property Scripter: TatCustomScripter read FScripter write SetScripter;

    ///  <summary>
    ///  Provides a reference to the script object containing the routine to be executed when the Delphi event fires.
    ///  </summary>
    property Script: TatScript read FScript write FScript;

    ///  <summary>
    ///  Contains a pointer to the Delphi method to be called when the Delphi event fires, before the script routine is executed.
    ///  </summary>
    property BeforeCall: TMethod read FBeforeCall write SetBeforeCall;

    ///  <summary>
    ///  Contains a pointer to the Delphi method to be called when the Delphi event fires, after the script routine is executed.
    ///  </summary>
    property AfterCall: TMethod read FAfterCall write SetAfterCall;

    ///  <summary>
    ///  Contains a pointer to the Delphi method that was the previous event handler before the script routine was set.
    ///  </summary>
    property OldCall: TMethod read FOldCall write SetOldCall;

    ///  <summary>
    ///  Contains the name of the script routine that will be executed when the Delphi event fires.
    ///  </summary>
    property RoutineName: string read FRoutineName write FRoutineName;

    ///  <summary>
    ///  Contains a reference to the event adapter used to handle this event.
    ///  </summary>
    property Adapter: TatEventAdapter read FAdapter write SetAdapter;

    ///  <summary>
    ///  Contains the instance of the object for which the event will be handled.
    ///  </summary>
    property Instance: TObject read FInstance write SetInstance;

    ///  <summary>
    ///  Contains the RTTI information about the event property being handled by this dispatcher.
    ///  </summary>
    property PropInfo: PPropInfo read FPropInfo write SetPropInfo;

    ///  <summary>
    ///  Not used.
    ///  </summary>
    property CustomCall: TMethod read FCustomCall write FCustomCall;
  end;

  ///  <summary>
  ///  Used internally by the scripter.
  ///  </summary>
  TatDispatcherRemoveNotificator = class(TComponent)
  private
    FDispatcher: TatEventDispatcher;
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  end;

  ///  <summary>
  ///  Deprecated class.
  ///  Use TatScriptWatches for handling watches for debugging purposes. See TatCustomScripter.Watches property.
  ///  </summary>
  TatDebugWatches = class(TOwnedCollection)
  private
    function GetItem(i: integer): TatDebugWatch;
  public
    function Add: TatDebugWatch;
    property Items[i: integer]: TatDebugWatch read GetItem; default;
    procedure Reset;
    procedure CompileAndEvaluateAll;
    procedure EvaluateAll;
    procedure Evaluate(AWatch: TatDebugWatch);
    procedure CompileAndEvaluate(AWatch: TatDebugWatch);
  end;

  ///  <summary>
  ///  Deprecated class.
  ///  Use TatScriptWatches for handling watches for debugging purposes. See TatCustomScripter.Watches property.
  ///  </summary>
  TatDebugWatch = class(TCollectionItem)
  private
    FExpression: string;
    FDebugScript: TatScript;
    FLastResult: TScriptValue;
    FWatchStatus: TWatchStatus;
    FAlwaysCompile: boolean;
    FEnabled: boolean;
    FResultChanged: boolean;
    procedure SetLastResult(const Value: TScriptValue);
    procedure Reset;
    procedure SetExpression(const Value: string);
    procedure ScriptDestroyed(Sender: TObject);
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;
    procedure CompileAndEvaluate;
    function Machine: TatVirtualMachine;
    procedure Evaluate;
    procedure FullEvaluate;
    property Expression: string read FExpression write SetExpression;
    property DebugScript: TatScript read FDebugScript write FDebugScript;
    property WatchStatus: TWatchStatus read FWatchStatus write FWatchStatus;
    property LastResult: TScriptValue read FLastResult write SetLastResult;
    property ResultChanged: boolean read FResultChanged write FResultChanged;
    property AlwaysCompile: boolean read FAlwaysCompile write FAlwaysCompile;
    property Enabled: boolean read FEnabled write FEnabled;
  end;

  {$IFDEF DELPHI2010_LVL}

  ///  <summary>
  ///  Generic event dispatcher class, for auto-definition of classes using RTTI
  ///  (see TatCustomScripter.DefineClassByRTTI).
  ///  </summary>
  TGenericEventDispatcher = class(TatEventDispatcher)
  public
    procedure RaiseEvent;
  end;

  ///  <summary>
  ///  Generic record wrapper class, for auto-definition of records using RTTI
  ///  (see TatCustomScripter.DefineRecordByRTTI).
  ///  </summary>
  TGenericRecordWrapper = class(TatRecordWrapper)
  private
    FRecordType: TRttiType;
    FRecordValue: TValue;
    FContext: TRttiContext;
    function GetFieldValue(AFieldName: string): TValue;
    function RecordName: string;
  strict protected
    procedure SetFieldValue(AFieldName: string; AValue: TValue);
  public
    constructor Create(const AValue: TValue);
    function Rec: Pointer;
  end;
  {$ENDIF}

  TCodeCompletionEntry = class(TCollectionItem)
  private
    FToken: string;
    FValue: string;
  public
    property Token: string read FToken write FToken;
    property Value: string read FValue write FValue;
  end;

  TCodeCompletionEntries = class(TCollection)
  private
    function GetItem(Index: integer): TCodeCOmpletionEntry;
  published
  public
    constructor Create;
    function Add(AToken: string; AValue: string): TCodeCOmpletionEntry;
    property Items[Index: integer]: TCodeCOmpletionEntry read GetItem; default;
  end;

  ///  <summary>
  ///  Internal class used to hold last choices made by end-user, so we can offer best choices for him next time.
  ///  </summary>
  TCodeInsightContext = class
  private
    FLastEntries: TCodeCompletionEntries;
    FLastUsedToken: string;
  published
  public
    constructor Create;
    destructor Destroy; override;
    property LastEntries: TCodeCompletionEntries read FLastEntries;
    property LastUsedToken: string read FLastUsedToken write FLastUsedToken;
  end;

  ///  <summary>
  ///  Internal use
  ///  </summary>
  TIgnorePair = record
    Open: char;
    Close: char;
  end;

  ///  <remarks>
  ///  TScripterCodeInsight is a helper class used to provide code insight capabilities
  ///  (code completion and parameter hints). This class offers useful methods to retrieve
  ///  completino and parameter hints information to be provided to the TIDEMemo or just another
  ///  custom IDE/memo. It also keep tracks of latest completion calls to improve user experience,
  ///  like providing the last choice made
  ///  </remarks>
  TScripterCodeInsight = class
  private
    FScript: TatScript;
    FIgnoreLevel: array of integer;
    FIgnorePairs: array of TIgnorePair;
    FContext: TCodeInsightContext;
    function DoPair(Open, Close: char): TIgnorePair;
    procedure SetIgnorePairs(const APairs: array of TIgnorePair);
    function IgnoreCount: integer;
    procedure FillMatchingItems(AClass: TatClass; AName: string; AList: TStrings);
    procedure FillAllMatchingItems(AClass: TatClass; AName: string; AList: TStrings; Scope: TatRoutineInfo);
    function FindResultClass(AClass: TatClass; AName: string): TatClass;
    function FindAnyResultClass(AClass: TatClass; AName: string; Scope: TatRoutineInfo): TatClass;
    procedure AddItemToList(AList: TStrings; AClassName, AName: string; AValue: TObject);
    function ExtractExpression(s: string; pos: integer): string;
    function IgnoringIndex: integer;
    function NextChar(s: string; var pos: integer): char;
    function PreviousChar(s: string; var pos: integer): char;
    function SplitList(s: string; const sep: string): TStringList;
    class procedure ConvertListToOldStyle(AList: TStrings);
    function GetCompletionListFromToken(AToken: string; AExactMatch: boolean;
      AInputPos: integer; var DefaultIndex: integer): TStringList;
    function GetParameterHintFromObject(obj: TObject): string;
    function FindScopeRoutine(AInputPos: integer): TatRoutineInfo;
  public
    constructor Create(AScript: TatScript);
    destructor Destroy; override;

    ///  <summary>
    ///  Provides context information about the parameter hint to be displayed
    ///  </summary>
    ///  <param name="AInputText">
    ///  The current source code of the script (Script.SourceCode property is not used)
    /// </param>
    ///  <param name="AToken">
    ///  the returned token used for parameter hint. This is usually the qualified name of the
    ///  method for which parameter hints will be displayed (example, 'MyForm.Show')
    /// </param>
    ///  <param name="AParIndex">
    ///  The index of parameter to be displayed (0 is first parameter, 1 second, etc.
    /// </param>
    ///  <param name="AInputPos">
    ///  The current cursor position in the input text in which parameter hint will be displayed
    /// </param>
    ///  <returns>
    ///  Function returns true if there is a valid parameter hint to be displayed at this position. False otherwise.
    ///  </returns>
    function GetParameterHintInfo(AInputText: string; AInputPos: integer; var AToken: string;
      var AParIndex: integer): boolean;

    ///  <summary>
    ///  Returns the parameter hint to be displayed given an specified token
    ///  </summary>
    ///  <param name="AToken">
    ///  the token used to display the parameter hint. Usually this token is previously retrieved
    ///  using GetParameterHintInfo
    /// </param>
    ///  <returns>
    ///  The parameter hint to be displayed in text format
    ///  </returns>
    function GetParameterHint(AToken: string; AInputPos: integer): string;

    ///  <summary>
    ///  Builds a string list containing code completion suggestions related to a input string AInputText (source code)
    ///  and an cursor position (AInputPos).
    ///  </summary>
    ///  <param name="AInputText">
    ///  The current source code of the script (Script.SourceCode property is not used)
    /// </param>
    ///  <param name="ADefaultIndex">
    ///  The suggested index of the completion list to be selected. This is only calculated if Context property is set.
    /// </param>
    ///  <param name="AInputPos">
    ///  The current cursor position in the input text in which code completion will be displayed
    /// </param>
    ///  <returns>
    ///  A TStrings list containing the code completion suggestions. You must be sure to destroy this list
    ///  after using it.
    ///  Important: in the Objects part of the list there is a reference to the script object related to the list
    ///  For example, if the list item is 'MyForm.Caption', it relates to a property of a caption. So the
    ///  object related to this item points to the TatProperty object related to the 'Caption' property.
    ///  The types of objects that can be in the Objects property are the following.
    ///  TatMethod (for methods)
    ///  TatProperty (for properties)
    ///  TatVariableInfo (for script variables)
    ///  TatRoutineInfo (for script routines)
    ///  If you want different info to be provided in the Objects section, see CreateCodeCompletionList method
    ///  </returns>
    function GetCodeCompletion(AInputText: string; AInputPos: integer; var DefaultIndex: integer)
      : TStringList;

    ///  <remarks>
    ///  Builds a string list containing code completion suggestions related to a input string AInputText (source code)
    ///  and an cursor position (AInputPos).
    /// 
    ///  This method works exactly like GetCodeCompletion method (see documentation about this method)
    ///  with a single difference: the Objects[] in the returned string list comes with different information.
    ///  Each object associated with the string item is actually an integer (you must typecast the object to integer)
    ///  indicating what type of code completion is each item. Here are the valid integer values.
    /// 
    ///  0 - Property
    ///  1 - Method (procedure)
    ///  2 - Method (function)
    ///  3 - Event
    ///  16 - variable (script or Delphi-based)
    ///  17 - procedure (script or Delphi-based)
    ///  18 - function (script or Delphi-based)
    ///  </remarks>
    function CreateCodeCompletionList(AInputText: string; AInputPos: integer;
      var DefaultIndex: integer): TStringList;

    ///  <summary>
    ///  Set this property if you want code completion methods to use historical choices from user.
    ///  Those methods will load and update this context. If this is not set, it will be ignored.
    ///  </summary>
    property Context: TCodeInsightContext read FContext write FContext;
  end;

  ///  <summary>
  ///  Returns true if the method specified by m is assigned.
  ///  </summary>
function AssignedMethod(m: TMethod): boolean;

///  <remarks>
///  Use RegisterScripterLibrary to make a new TatScripterLibrary class available to scripting system. You must
///  pass the class of library that inherits from TatScripterLibrary. Once the library is registered, all scripter
///  components in the application will know that the library exists. When an user tries to use a library using "uses" clause
///  in the script, the scripter component will try to load the library by searching the current registered libraries.
///  If AExplicitLoad is true, then the library is already instantiated and added in all scripter components of the application.
///  See TatCustomScripter.LoadLibrary method for more info about libraries.
///  </remarks>
procedure RegisterScripterLibrary(ALibrary: TatScripterLibraryClass;
  AExplicitLoad: boolean = false);

///  <summary>
///  Converts a script value to a Variant. This function is useful if you want to write
///  common code for both desktop and mobile appliations using scripter.
///  For desktop applications, this function makes no difference, since script values are
///  variants. For mobile, script values are TValue records, thus this function
///  converts it to a variant value.
///  </summary>
function ToVariant(const Value: TScriptValue): Variant; {$IFDEF DELPHI2006}inline;{$ENDIF}

/// <summary>
///   Verifies if the specified script value is holds a string value. Returns
///   true if value is string, false otherwise.
/// </summary>
/// <param name="Value">
///   Script value to be testeed.
/// </param>
function ScriptValueIsString(const Value: TScriptValue): boolean;

function ScriptValueIsDateTime(const Value: TScriptValue): boolean;

/// <summary>
///   Verifies if the specified script value is holds an ordinal value
///   (integer or enumerated types).
///   Returns true if value is string, false otherwise.
/// </summary>
/// <param name="Value">
///   Script value to be testeed.
/// </param>
function ScriptValueIsOrdinal(const Value: TScriptValue): boolean;

function ScriptValueAsInt64(const V1: TScriptValue): Int64; {$IFDEF DELPHI2006}inline;{$ENDIF}
function ScriptValueAsString(const V1: TScriptValue): string; {$IFDEF DELPHI2006}inline;{$ENDIF}

///  <summary>
///  Unregisters a library previously registered with RegisterScripterLibrary.
///  </summary>
procedure UnregisterScripterLibrary(ALibrary: TatScripterLibraryClass);

///  <summary>
///  Converts a variant type to TObject.
///  </summary>
function VarToObject(const v: TScriptValue): TObject;

///  <summary>
///  Converts a TObject to Variant type
///  </summary>
function ObjectToVar(const obj: TObject): TScriptValue;

///  <summary>
///  Converts a Pointer to Variant type
///  </summary>
function PointerToVar(p: pointer): Variant;

///  <summary>
///  Converts a variant type to Pointer.
///  </summary>
function VarToPointer(v: Variant): pointer;

///  <summary>
///  Converts a variant type to an integer (32 or 64 bit) value that represents the object
///  </summary>
function VarToIntObject(const v: Variant): IntObject;

///  <summary>
///  Converts a string value to double. It tries using both '.' and ',' as decimal separator,
///  and it doesn't raise a convert error in case s is a invalid float value.
///  </summary>
function StrVal(s: string): double;

///  <summary>
///  Converts a variant type to integer.
///  </summary>
function VarToInteger(v: Variant): integer;

///  <summary>
///  Converts a variant type to Int64.
///  </summary>
function VarToInt64(v: Variant): Int64;

///  <remarks>
///  Converts a variant type to an enumerated value. The variant can have the enumerated name
///  in string type. For example, 'alClient'. You must provide the PropType of enumerated type so
///  such conversion is possible.
///  </remarks>
function VarToEnumInteger(v: Variant; PropType: PTypeInfo): integer;

///  <summary>
///  Converts a variant type to a set type. The variant is an array of string with the names of enumerated
///  types belonging to the set. The PropType parameter must receive the RTTI info about the enumerated type.
///  </summary>
function VarToSet(v: TScriptValue; PropType: PTypeInfo): integer;

///  <summary>
///  Converts a variant to double.
///  </summary>
function VarToFloat(v: Variant): double;

///  <summary>
///  Converts a variant to boolean. Value is false if variant is zero, true otherwise.
///  </summary>
function VarToBoolean(v: Variant): boolean;

///  <summary>
///  Returns a text description describing the content of the variant.
///  </summary>
function VarContent(v: Variant): string;

///  <summary>
///  Converts an integer value to a set type. You must provide the size of set type in ASize parameter.
///  </summary>
procedure IntToSet(var ASet; AInt: integer; ASize: integer = 4);

///  <summary>
///  Converts a set type to an integer. You must provide the size of set type in ASize parameter.
///  </summary>
function IntFromSet(var ASet; ASize: integer = 4): integer;

///  <summary>
///  Deprecated.
///  </summary>
function IntFromConstSet(const ASet): integer;

///  <summary>
///  Raises an EatScriptInfoError exception.
///  </summary>
procedure ScriptInfoError(msg: string);

///  <summary>
///  Raises an EatRuntimeError exception.
///  </summary>
procedure RaiseRuntimeError(msg: string);

///  <summary>
///  Raises an EatDefinitionError exception.
///  </summary>
procedure DefinitionError(msg: string);

///  <summary>
///  Raises an EatInternalError exception.
///  </summary>
procedure InternalError(msg: string);

///  <summary>
///  Turns an existing variant into a variant with a ByRef flag set.
///  </summary>
function MakeVarByRef(var v: Variant): Variant;

///  <summary>
///  Returns the line number in source code corresponding to the p-code instruction specified by inst.
///  </summary>
function LineNumberFromInstruction(Inst: pSimplifiedCode): integer;

///  <summary>
///  Returns the column number in source code corresponding to the p-code instruction specified by inst.
///  </summary>
function ColNumberFromInstruction(Inst: pSimplifiedCode): integer;

///  <summary>
///  Returns true if the instruction specified by inst in the provided scripter contains executable code.
///  Some instructions might not be executable, but only preparation instructions (saving space in stack, for example).
///  </summary>
function InstructionIsExecutable(Script: TatCustomScripter; Inst: pSimplifiedCode): boolean;

///  <remarks>
///  Use DefineEventAdapter to allow scripter to support a new event type specified by ARttiInfo.
///  For example, TNotifyEvent must have an adapter. Once you register it, all events in any object that are of TNotifyEvent type
///  (Button OnClick, Combo OnChange, OnEnter, OnExit, etc.) are supported by the scripter.
///  You must include a new event adapter using method or procedure DefineEventAdapter.
///  See TatEventAdapters.DefineEventAdapter for more info about the parameters and how to define an adapter. Both
///  methods work the same way.
///  </remarks>
function DefineEventAdapter(ARttiInfo: PTypeInfo; ADispatcherClass: TDispatcherClass;
  AMethodCode: pointer; ACheck: boolean = True): TatEventAdapter;

///  <summary>
///  Builds a string list containning code completion suggestions related to a input string AInputText (source code)
///  and an cursor position (AInputPos).
///  </summary>
function CreateCodeCompletionList(AScripter: TatCustomScripter; AInputText: string;
  AInputPos: integer; var AExprPos, AExprLen: integer): TStringList; overload;

///  <summary>
///  Builds a string list containning code completion suggestions related to a input string AInputText (source code)
///  and an cursor position (AInputPos).
///  </summary>
function CreateCodeCompletionList(AScript: TatScript; AInputText: string; AInputPos: integer;
  var AExprPos, AExprLen: integer): TStringList; overload;

///  <summary>
///  Deprecated. Use TatCustomScripter.Watches property.
///  </summary>
function EvaluateWatch(AScripter: TatCustomScripter; AExpression: string): TScriptValue;

function ScriptArrayHigh(V: TScriptValue): integer;
function ScriptArrayLow(V: TScriptValue): integer;
{$IFDEF NEWSTACK}
function ScriptArrayValue(const V: TScriptValue; const AIndex: integer): TScriptValue;
{$ENDIF}

{$IFNDEF DELPHI7_LVL}
function VarTypeAsText(const AType: integer): string;
{$ENDIF}

var
  ///  <summary>
  ///  atLibraryList global variable holds a collection of all library classes registered with RegisterScripterLibrary procedure.
  ///  </summary>
  atLibraryList: TatLibraryList;

  ///  <summary>
  ///  Used internally by the scripter.
  ///  </summary>
  CoreConst: array [CORE_CONST] of TScriptValue;

  ///  <remarks>
  ///  OnGlobalScripterCreate is a global event that is fired whenever a scripter component is created in the application.
  ///  Assign an event handler to this variable to have access to any scripter created, in case you want to register classes, methods,
  ///  properties in all scripter components without having direct access to the instance variables.
  ///  The newly created scripter component is passed in the Sender parameter. You must typecast it to the desired scripter class
  ///  (you will often use TatCustomScripter(Sender).
  ///  </remarks>
  OnGlobalScripterCreate: TNotifyEvent;

  ///  <remarks>
  ///  OnGlobalScripterLoaded is a global event that is fired whenever a scripter component is loaded (from dfm) in the application.
  ///  Assign an event handler to this variable to have access to any scripter created and loaded, in case you want to register
  ///  classes, methods, properties in all scripter components without having direct access to the instance variables.
  ///  The loaded scripter component is passed in the Sender parameter. You must typecast it to the desired scripter class
  ///  (you will often use TatCustomScripter(Sender).
  ///  </remarks>
  OnGlobalScripterLoaded: TNotifyEvent;

type
  /// <summary>
  ///   For internal use only.
  /// </summary>
  TatInternalObject = class(TObject);

type
  TAddCodeCompletionItemEvent = procedure(AClassName: String; var AName: string) of object;

var
  OnGlobalAddCodeCompletionItem: TAddCodeCompletionItemEvent;
  DefaultMachineClass: TMachineClass = nil;
  DefaultScriptFormClass: TScriptFormClass = nil;
  ScriptFormFactory: TScriptFormFactory;
  UndefinedClass: TatClass; // internal use

var
  NullValue: TScriptValue;

implementation

{$WARNINGS OFF}

uses
  uSystemLibrary
//  {$IFNDEF DELPHIXE2_LVL}, Vcl.ScripterInit{$ENDIF}
  {$IFDEF DELPHI2009_LVL}, Character{$ENDIF}
  {$IFDEF MSWINDOWS} , DispatchLib, uCallDLL {$ENDIF};

const
  NilMethod: TMethod = (Code: nil; Data: nil);
  SCurDir = '$(CURDIR)';
  SAppDir = '$(APPDIR)';

var
  EventAdapters: TatEventAdapters;

{ Script array functions }

function ScriptArrayHigh(V: TScriptValue): integer;
begin
  {$IFDEF NEWSTACK}
  Result := V.GetArrayLength - 1;
  {$ELSE}
  Result := VarArrayHighBound(V, 1);
  {$ENDIF}
end;

function ScriptArrayLow(V: TScriptValue): integer;
begin
  {$IFDEF NEWSTACK}
  Result := 0;
  {$ELSE}
  Result := VarArrayLowBound(V, 1);
  {$ENDIF}
end;

{$IFDEF NEWSTACK}
function ScriptArrayValue(const V: TScriptValue; const AIndex: integer): TScriptValue;
begin
  Result := V.GetArrayElement(AIndex);
  if Result.TypeInfo = TypeInfo(TValue) then
    Result := Result.AsType<TValue>;
end;
{$ENDIF}

{$IFDEF NEWSTACK}
class operator TStackValue.Implicit(const Value: TStackValue): TScriptValue;
begin
  Result := Value.FValue;
end;
{$ENDIF}

{$IFDEF NEWSTACK}
class operator TStackValue.Implicit(const Value: TScriptValue): TStackValue;
begin
  Result.FValue := Value;
end;
{$ENDIF}

  { ------------------------------------------------------------------------------ }
  { Variant type helper functions }
  { ------------------------------------------------------------------------------ }

function TypeInfoName(TypeInfo: PTypeInfo): string;
begin
  {$IFDEF NEXTGEN}
  Result := GetTypeName(TypeInfo);
  {$ELSE}
  Result := TypeInfo.Name;
  {$ENDIF}
end;

function PropInfoName(PropInfo: PPropInfo): string;
begin
  {$IFDEF NEXTGEN}
  Result := GetPropName(PropInfo);
  {$ELSE}
  Result := PropInfo.Name;
  {$ENDIF}
end;

{$IFNDEF DELPHI7_LVL}
function FindVarData(const v: Variant): PVarData;
begin
  Result := @TVarData(v);
  while Result.VType = varByRef or varVariant do
    Result := PVarData(Result.vPointer);
end;

function VarIsType(const v: Variant; const AVarTypes: array of integer): boolean;
var
  i: integer;
begin
  Result := false;
  with FindVarData(v)^ do
    for i := Low(AVarTypes) to High(AVarTypes) do
      if VType = AVarTypes[i] then
      begin
        Result := True;
        Break;
      end;
end;

{ function VarToInt2(V: Variant): integer;
  begin
  while TVarData(V).VType and varByRef <> 0 do
  V := Variant(TVarData(V).VPointer^);
  result := V;
  end; }

function VarTypeAsText(const AType: integer): string;
const
  CText: array [varEmpty .. $0014] of string = ('Empty', 'Null', 'Smallint', // Do not localize
    'Integer', 'Single', 'Double', 'Currency', 'Date', 'OleStr', 'Dispatch', // Do not localize
    'Error', 'Boolean', 'Variant', 'Unknown', 'Decimal', '$0F', 'ShortInt', // Do not localize
    'Byte', 'Word', 'LongWord', 'Int64'); // Do not localize
begin
  if AType and varTypeMask <= $0014 then
    Result := CText[AType and varTypeMask]
  else if AType = varString then
    Result := 'String' // Do not localize
  else if AType = varAny then
    Result := 'Any' // Do not localize
  else
    Result := HexDisplayPrefix + IntToHex(AType and varTypeMask, 4);

  if AType and varArray <> 0 then
    Result := 'Array ' + Result; // Do not localize
  if AType and varByRef <> 0 then
    Result := 'ByRef ' + Result; // Do not localize
end;
{$ENDIF}

//function ValueToVar(V: TScriptValue): Variant; {$IFNDEF NEWSTACK} inline; {$ENDIF}
//begin
//  {$IFDEF NEWSTACK}
//  Result := V.AsVariant;
//  {$ELSE}
//  Result := V;
//  {$ENDIF}
//end;
//
//function VarToValue(V: Variant): TScriptValue; {$IFNDEF NEWSTACK} inline; {$ENDIF}
//begin
//  {$IFDEF NEWSTACK}
//  {$ELSE}
//  Result := V;
//  {$ENDIF}
//end;

function VarToStr(v: Variant): string;
begin
  while TVarData(v).VType and varByRef <> 0 do
    v := Variant(TVarData(v).vPointer^);

  if not VarIsNull(v) then
    Result := v
  else
    Result := '';
end;

function ToVariant(const Value: TScriptValue): Variant;
begin
  {$IFDEF NEWSTACK}
  Result := Value.AsVariant;
  {$ELSE}
  Result := Value;
  {$ENDIF}
end;

function ScriptValueIsNull(const Value: TScriptValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := Value.IsEmpty;
  {$ELSE}
  Result := VarIsNull(Value);
  {$ENDIF}
end;

function IsReference(const Value: TStackValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := Value.RawValue.TypeInfo = TypeInfo(PScriptValue);
  {$ELSE}
  Result := TVarData(Value).VType and varByRef <> 0;
  {$ENDIF}
end;

function DerefValue(Value: TStackValue): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  if not IsReference(Value) then
    Result := Value
  else
    Result := Value.RawValue.AsType<PScriptValue>^;
  {$ELSE}
  if not IsReference(Value) then
    Result := Value
  else
    Result := Variant(TVarData(Value).vPointer^);
  {$ENDIF}
end;

procedure SetRefValue(const Ref: TStackValue; const Value: TScriptValue); {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Ref.RawValue.AsType<PScriptValue>^ := Value;
  {$ELSE}
  PVariant(TVarData(Ref).vPointer)^ := Value;
  {$ENDIF}
end;

function CreateReferenceValue(v: PScriptValue): TStackValue;
begin
  {$IFDEF NEWSTACK}
  while v^.TypeInfo = TypeInfo(PScriptValue) do
    v := v^.AsType<PScriptValue>;
  Result.RawValue := TValue.From<PScriptValue>(v);
  {$ELSE}
  while TVarData(v^).VType and varByRef <> 0 do
    v := PScriptValue(TVarData(v^).vPointer);

  TVarData(Result).VType := varVariant or varByRef;
  TVarData(Result).vPointer := v;
  {$ENDIF}
end;


//procedure SetStackValue(Ref: PStackValue; const Value: TScriptValue); inline;
//begin
//  {$IFDEF NEWSTACK}
//
//  {$ELSE}
//  if IsReference(Ref^) then
//    SetRefValue(Ref^, Value)
//  else
//    Ref^ := Value;
//  {$ENDIF}
//end;

//procedure SetStackValueNoRef(Ref: PStackValue; const Value: TScriptValue); inline;
//begin
//  {$IFDEF NEWSTACK}
//  Ref^.ScriptValue := Value;
//  {$ELSE}
//  Ref^ := Value;
//  {$ENDIF}
//end;

function MakeVarByRef(var v: Variant): Variant;
begin
  { cria um novo variant com o bit varByRef ligado e apontando para o variant dado }
  Result := v;
  TVarData(Result).VType := varVariant or varByRef;
  TVarData(Result).vPointer := @v;
end;

function ScriptValueEqual(const V1, V2: TScriptValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsVariant = V2.AsVariant;
  {$ELSE}
  Result := V1 = V2;
  {$ENDIF}
end;

function ScriptValueGreater(const V1, V2: TScriptValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsVariant > V2.AsVariant;
  {$ELSE}
  Result := V1 > V2;
  {$ENDIF}
end;

function ScriptValueGreaterOrEqual(const V1, V2: TScriptValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsVariant >= V2.AsVariant;
  {$ELSE}
  Result := V1 >= V2;
  {$ENDIF}
end;

function ScriptValueLess(const V1, V2: TScriptValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsVariant < V2.AsVariant;
  {$ELSE}
  Result := V1 < V2;
  {$ENDIF}
end;

function ScriptValueLessOrEqual(const V1, V2: TScriptValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsVariant <= V2.AsVariant;
  {$ELSE}
  Result := V1 <= V2;
  {$ENDIF}
end;

function ScriptValueAdd(const V1, V2: TScriptValue): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.FromVariant(V1.AsVariant + V2.AsVariant);
  {$ELSE}
  Result := V1 + V2;
  {$ENDIF}
end;

function ScriptValueSubtract(const V1, V2: TScriptValue): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.FromVariant(V1.AsVariant - V2.AsVariant);
  {$ELSE}
  Result := V1 - V2;
  {$ENDIF}
end;

function ScriptValueMultiply(const V1, V2: TScriptValue): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.FromVariant(V1.AsVariant * V2.AsVariant);
  {$ELSE}
  Result := V1 * V2;
  {$ENDIF}
end;

function ScriptValueDivide(const V1, V2: TScriptValue): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.FromVariant(V1.AsVariant / V2.AsVariant);
  {$ELSE}
  Result := V1 / V2;
  {$ENDIF}
end;

function ScriptValueConcat(const V1, V2: TScriptValue): string; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsString + V2.AsString;
  {$ELSE}
  Result := VarToStr(V1) + VarToStr(V2);
  {$ENDIF}
end;

function ScriptValueOr(const V1, V2: TScriptValue): integer; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal or V2.AsOrdinal;
  {$ELSE}
  Result := round(V1) or round(V2);
  {$ENDIF}
end;

function ScriptValueNot(const V1: TScriptValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := not V1.AsBoolean;
  {$ELSE}
  Result := (round(V1) = 0);
  {$ENDIF}
end;

function ScriptValueNeg(const V1: TScriptValue): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.FromVariant(-V1.AsVariant);
  {$ELSE}
  Result := -V1;
  {$ENDIF}
end;

function ScriptValueXor(const V1, V2: TScriptValue): integer; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal xor V2.AsOrdinal;
  {$ELSE}
  Result := round(V1) xor round(V2);
  {$ENDIF}
end;

function ScriptValueAnd(const V1, V2: TScriptValue): integer; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal and V2.AsOrdinal;
  {$ELSE}
  Result := round(V1) and round(V2);
  {$ENDIF}
end;

function ScriptValueShl(const V1, V2: TScriptValue): integer; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal shl V2.AsOrdinal;
  {$ELSE}
  Result := round(V1) shl round(V2);
  {$ENDIF}
end;

function ScriptValueShr(const V1, V2: TScriptValue): integer; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal shr V2.AsOrdinal;
  {$ELSE}
  Result := round(V1) shr round(V2);
  {$ENDIF}
end;

function ScriptValueDiv(const V1, V2: TScriptValue): integer; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal div V2.AsOrdinal;
  {$ELSE}
  Result := round(V1) div round(V2);
  {$ENDIF}
end;

function ScriptValueMod(const V1, V2: TScriptValue): integer; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal mod V2.AsOrdinal;
  {$ELSE}
  Result := round(V1) mod round(V2);
  {$ENDIF}
end;

function ScriptValueExp(const V1, V2: TScriptValue): double; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := Power(V1.AsExtended, V2.AsExtended);
  {$ELSE}
  Result := Power(double(V1), double(V2));
  {$ENDIF}
end;

function ScriptValueAsBool(const V1: TScriptValue): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := Boolean(V1.AsOrdinal);
  {$ELSE}
  Result := V1;
  {$ENDIF}
end;

function ScriptValueAsInteger(const V1: TScriptValue): integer; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal;
  {$ELSE}
  Result := V1;
  {$ENDIF}
end;

function ScriptValueAsInt64(const V1: TScriptValue): Int64; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsOrdinal;
  {$ELSE}
  Result := V1;
  {$ENDIF}
end;

function ScriptValueAsString(const V1: TScriptValue): string; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := V1.AsString;
  {$ELSE}
  Result := V1;
  {$ENDIF}
end;

function VariantIsString(const Value: Variant): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  Result := VarIsStr(Value);
end;

function ScriptValueIsString(const Value: TScriptValue): boolean;
begin
  {$IFDEF NEWSTACK}
  Result := Value.Kind in [TTypeKind.tkChar, TTypeKind.tkString, TTypeKind.tkWChar,
    TTypeKind.tkLString, TTypeKind.tkWString, TTypeKind.tkUString];
  if (not Result) and (Value.Kind = TTypeKind.tkVariant) then
    Result := VariantIsString(Value.AsVariant);
  {$ELSE}
  Result := VariantIsString(Value);
  {$ENDIF}
end;

function ScriptValueIsDateTime(const Value: TScriptValue): boolean;
begin
  {$IFDEF NEWSTACK}
  Result := (Value.TypeInfo = TypeInfo(TDateTime))
    or (Value.TypeInfo = TypeInfo(TDate))
    or (Value.TypeInfo = TypeInfo(TTime));
  if (not Result) and (Value.Kind = TTypeKind.tkVariant) then
    Result := VarIsType(Value.AsVariant, varDate);
  {$ELSE}
  Result := VarIsType(Value, varDate);
  {$ENDIF}
end;

function VariantIsOrdinal(const Value: Variant): boolean; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  Result := VarIsOrdinal(Value);
end;

function ScriptValueIsOrdinal(const Value: TScriptValue): boolean;
begin
  {$IFDEF NEWSTACK}
  Result := Value.IsOrdinal;
  if (not Result) and (Value.Kind = TTypeKind.tkVariant) then
    Result := VariantIsOrdinal(Value.AsVariant);
  {$ELSE}
  Result := VariantIsOrdinal(Value);
  {$ENDIF}
end;

function DoubleToScriptValue(const V: double): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.From<double>(V);
  {$ELSE}
  Result := V;
  {$ENDIF}
end;

function StringToScriptValue(const V: string): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.From<string>(V);
  {$ELSE}
  Result := V;
  {$ENDIF}
end;

function BoolToScriptValue(const V: boolean): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.From<boolean>(V);
  {$ELSE}
  Result := V;
  {$ENDIF}
end;

function IntToScriptValue(const V: integer): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.From<integer>(V);
  {$ELSE}
  Result := V;
  {$ENDIF}
end;

function Int64ToScriptValue(const V: Int64): TScriptValue; {$IFDEF DELPHI2006}inline;{$ENDIF}
begin
  {$IFDEF NEWSTACK}
  Result := TValue.From<Int64>(V);
  {$ELSE}
  Result := V;
  {$ENDIF}
end;

function VarToIntObject(const v: Variant): IntObject;
begin
  {$IFDEF CPUX64}
  Result := VarToInt64(v);
  {$ELSE}
  Result := VarToInteger(v);
  {$ENDIF}
end;

function VarToObject(const v: TScriptValue): TObject;
begin
  {$IFDEF NEWSTACK}
  Result := v.AsObject;
  {$ELSE}
  Result := TObject(VarToIntObject(v));
  {$ENDIF}
end;

function ObjectToVar(const obj: TObject): TScriptValue;
begin
  {$IFDEF NEWSTACK}
  Result := obj;
  {$ELSE}
  Result := IntObject(obj);
  {$ENDIF}
end;

function PointerToVar(p: pointer): Variant;
begin
  Result := IntObject(p);
end;

function VarToPointer(v: Variant): pointer;
begin
  Result := pointer(VarToIntObject(v));
end;

function StrVal(s: string): double;
var
  p: integer;
begin
  p := pos(',', s);
  if p > 0 then
    s[p] := '.';
  val(s, Result, p);
end;

function VarToInteger(v: Variant): integer;
begin
  case VarType(v) of
    varSmallint, varInteger, varByte, varError, varWord, varLongWord:
      Result := v;
    varSingle, varDouble, varCurrency, varDate:
      Result := round(v);
    varBoolean:
      if v = True then
        Result := 1
      else
        Result := 0;
    varString,
    {$IFDEF DELPHI2009_LVL}
    varUString,
    {$ENDIF}
    varOleStr:
      Result := round(StrVal(v));
    varUnknown, varDispatch:
      Result := 0;
  else
    if VarIsNull(v) then
      Result := 0
    else
      Result := VarAsType(v, varInteger);
  end;
end;

function VarToInt64(v: Variant): Int64;
begin
  {$IFDEF DELPHI6_LVL}
  case VarType(v) of
    varSmallint, varInteger, varByte, varError, varInt64, varWord, varLongWord:
      Result := v;
    varSingle, varDouble, varCurrency, varDate:
      Result := round(v);
    varBoolean:
      if v = True then
        Result := 1
      else
        Result := 0;
    varString,
    {$IFDEF DELPHI2009_LVL}
    varUString,
    {$ENDIF}
    varOleStr:
      Result := round(StrVal(v));
    varUnknown, varDispatch:
      Result := 0;
  else
    if VarIsNull(v) then
      Result := 0
    else
      Result := VarAsType(v, varInteger);
  end;
  {$ELSE}
  Result := VarToInteger(v);
  {$ENDIF}
end;

function VarToChar(v: Variant): char;
begin
  case VarType(v) of
    varSmallint, varInteger, varByte, varError, varWord, varLongWord:
      Result := Chr(integer(v) and $FF);

    varSingle, varDouble, varCurrency, varDate:
      Result := Chr(round(v) and $FF);

    varBoolean:
      if v = True then
        Result := #1
      else
        Result := #0;

    varString,
    {$IFDEF DELPHI2009_LVL}
    varUString,
    {$ENDIF}
    varOleStr:
      if Length(v) > 0 then
        Result := string(v)[1]
      else
        Result := #0;

  else
    Result := #0;
  end;
end;

function VarToWideChar(v: Variant): WideChar;
begin
  case VarType(v) of
    varSmallint, varInteger, varByte, varError, varWord, varLongWord:
      Result := WideChar(integer(v) and $FFFF);

    varSingle, varDouble, varCurrency, varDate:
      Result := WideChar(round(v) and $FFFF);

    varBoolean:
      if v = True then
        Result := #1
      else
        Result := #0;

    varString,
    {$IFDEF DELPHI2009_LVL}
    varUString,
    {$ENDIF}
    varOleStr:
      if Length(v) > 0 then
        {$IFDEF NEXTGEN}
        Result := string(v)[1]
        {$ELSE}
        Result := Widestring(v)[1]
        {$ENDIF}
      else
        Result := #0;

  else
    Result := #0;
  end;
end;

function VarToEnumInteger(v: Variant; PropType: PTypeInfo): integer;
begin
  case VarType(v) of
    varSmallint, varInteger, varByte, varError, varWord, varLongWord:
      Result := v;
    varSingle, varDouble, varCurrency, varDate:
      Result := round(v);
    varBoolean:
      if v = True then
        Result := 1
      else
        Result := 0;
    varString,
    {$IFDEF DELPHI2009_LVL}
    varUString,
    {$ENDIF}
    varOleStr:
      Result := GetEnumValue(PropType, v);
    varUnknown, varDispatch:
      Result := 0;
  else
    if VarIsNull(v) then
      Result := 0
    else
      Result := VarAsType(v, varInteger);
  end;
end;

function VariantToSet(v: Variant; PropType: PTypeInfo): integer;
var
  c, d: integer;
begin
  d := VarArrayDimCount(v);
  if d = 1 then
  begin
    { monta um conjunto através dos itens passados no vetor de variants
      os elementos são tratados como bits e o conjunto é formado pela união
      desses bits }
    Result := 0;
    if Assigned(PropType) then
    begin
      PropType := GetTypeData(PropType).CompType^;
      for c := VarArrayLowBound(v, 1) to VarArrayHighBound(v, 1) do
        Result := Result or (1 shl VarToEnumInteger(v[c], PropType));
    end
    else
      for c := VarArrayLowBound(v, 1) to VarArrayHighBound(v, 1) do
        Result := Result or (1 shl VarToInteger(v[c]));
  end
  else
    case VarType(v) of
      varSmallint, varInteger, varByte, varError, varWord, varLongWord:
        Result := v;
      varSingle, varDouble, varCurrency, varDate:
        Result := round(v);
      varBoolean:
        if v = True then
          Result := 1
        else
          Result := 0;
      varString,
      {$IFDEF DELPHI2009_LVL}
      varUString,
      {$ENDIF}
      varOleStr:
        Result := GetEnumValue(PropType, v);
      varUnknown, varDispatch:
        Result := 0;
    else
      if VarIsNull(v) then
        Result := 0
      else
        Result := VarAsType(v, varInteger);
    end;
end;

{$IFDEF NEWSTACK}
function ValueToSet(v: TScriptValue; PropType: PTypeInfo): integer;
var
  I: integer;
  IntSet: Int64;
  Item: TValue;
begin
  IntSet := 0;
  if v.IsArray then
  begin
    for I := 0 to v.GetArrayLength - 1 do
    begin
      Item := ScriptArrayValue(v, I);
      IntSet := IntSet or (1 shl Item.AsOrdinal);
    end;
  end
  else
    case v.Kind of
      TTypeKind.tkInteger:
        IntSet := V.AsInteger;
      TTypeKind.tkInt64:
        IntSet := V.AsInt64; // just because function result is integer, not Int64
      TTypeKind.tkFloat:
        IntSet := Round(V.AsExtended);
      TTypeKind.tkSet:
        IntSet := V.AsOrdinal; // could be ordinal
//      tkString: ;
//      tkLString: ;
//      tkWString: ;
//      tkUString: ;
      TTypeKind.tkVariant:
        IntSet := VariantToSet(V.AsVariant, PropType);
    else
      V.TryAsType<Int64>(IntSet);
    end;
  Result := integer(IntSet);
end;
{$ENDIF}

function VarToSet(v: TScriptValue; PropType: PTypeInfo): integer;
begin
  {$IFDEF NEWSTACK}
  Result := ValueToSet(v, PropType);
  {$ELSE}
  Result := VariantToSet(v, PropType);
  {$ENDIF}
end;

function VarToFloat(v: Variant): double;
begin
  case VarType(v) of
    varSmallint, varInteger, varByte, varError, varSingle, varDouble, varCurrency, varDate,
    varWord, varLongWord:
      Result := v;
    varBoolean:
      if v = True then
        Result := 1
      else
        Result := 0;
    varString,
    {$IFDEF DELPHI2009_LVL}
    varUString,
    {$ENDIF}
    varOleStr:
      Result := StrVal(v);
    varUnknown, varDispatch:
      Result := 0;
  else
    if VarIsNull(v) then
      Result := 0
    else
      Result := VarAsType(v, varDouble);
  end;
end;

function VarToBoolean(v: Variant): boolean;
begin
  Result := (VarToInteger(v) <> 0);
end;

function VarContent(v: Variant): string;
begin
  try
    case VarType(v) of
      varEmpty:
        Result := 'Empty';
      varNull:
        Result := 'Null';
      varSmallint:
        Result := 'Smallint:' + VarToStr(v);
      varInteger:
        Result := 'Integer:' + VarToStr(v);
      varSingle:
        Result := 'Single:' + VarToStr(v);
      varDouble:
        Result := 'Double:' + VarToStr(v);
      varCurrency:
        Result := 'Currency:' + VarToStr(v);
      varDate:
        Result := 'Date:' + VarToStr(v);
      varOleStr:
        Result := 'OleStr:' + VarToStr(v);
      varDispatch:
        Result := 'Dispatch:' + VarToStr(v);
      varError:
        Result := 'Error:' + VarToStr(v);
      varBoolean:
        Result := 'Boolean:' + VarToStr(v);
      varVariant:
        Result := 'Variant:' + VarToStr(v);
      varUnknown:
        Result := 'Unknown:' + VarToStr(v);
      varByte:
        Result := 'Byte:' + VarToStr(v);
      varString:
        Result := 'String:' + VarToStr(v);
      {$IFDEF DELPHI2009_LVL}
      varUString:
        Result := 'UnicodeString:' + VarToStr(v);
      {$ENDIF}
      varArray:
        Result := 'Array:' + VarToStr(v);
      varByRef:
        Result := 'ByRef:' + VarToStr(v);
      varWord:
        Result := 'Word:' + VarToStr(v);
      varLongWord:
        Result := 'Longword:' + VarToStr(v);
    else
      Result := VarToStr(v);
    end;
  except
    Result := '(unknown)';
  end;
end;

{$IFDEF NEWSTACK}
function ValueContent(v: TScriptValue): string;
begin
  try
    if v.TypeInfo <> nil then
      Result := Format('%s:%s', [TypeInfoName(v.TypeInfo), v.ToString])
    else
      Result := v.ToString;
  except
    Result := '(unknown)';
  end;
end;
{$ENDIF}

function ScriptValueContent(v: TScriptValue): string;
begin
  {$IFDEF NEWSTACK}
  Result := ValueContent(v);
  {$ELSE}
  Result := VarContent(v);
  {$ENDIF}
end;


{$IFNDEF NEWSTACK}
function VariantFromVarRec(v: TVarRec): Variant;
var
  {$IFNDEF NEXTGEN}
  astr: AnsiString;
  {$ENDIF}
  {$IFDEF DELPHI2009_LVL}
  ustr: UnicodeString;
  {$ENDIF}
begin
  with v do
    case VType of
      vtInteger:
        Result := vInteger;
      vtBoolean:
        Result := VBoolean;
      vtExtended:
        Result := VExtended^;
      {$IFNDEF NEXTGEN}
      vtChar:
        Result := VChar;
      vtString:
        Result := vString^;
      vtAnsiString:
        begin
          astr := AnsiString(VAnsiString);
          UniqueString(astr);
          Result := astr;
        end;
      {$ENDIF}
      vtCurrency:
        Result := VCurrency^;
      vtVariant:
        Result := VVariant^;
      vtObject:
        Result := ObjectToVar(VObject);
      {$IFDEF DELPHI2009_LVL}
      vtUnicodeString:
        begin
          ustr := UnicodeString(VUnicodeString);
          UniqueString(ustr);
          Result := ustr;
        end;
      {$ENDIF}
    else
      raise EatScripterFatal.CreateFmt('Unsupported parameter type in array of const: %d', [v.VType]);
    end;
end;
{$ENDIF}

{$IFDEF NEWSTACK}
function ScriptValueFromVarRec(v: TVarRec): TScriptValue;
var
  ustr: UnicodeString;
begin
  with v do
    case VType of
      vtInteger:
        Result := vInteger;
      vtBoolean:
        Result := VBoolean;
      vtExtended:
        Result := VExtended^;
      vtCurrency:
        Result := VCurrency^;
      vtVariant:
        Result := TValue.From<Variant>(VVariant^);
      vtObject:
        Result := TObject(VObject);
      vtWideChar:
        Result := VWideChar;
      vtInt64:
        Result := TValue.From<Int64>(VInt64^);
      vtUnicodeString:
        begin
          ustr := UnicodeString(VUnicodeString);
          UniqueString(ustr);
          Result := ustr;
        end;
    else
      raise EatScripterFatal.CreateFmt('Unsupported parameter type in array of const: %d', [v.VType]);
    end;
end;
{$ENDIF}


{ ------------------------------------------------------------------------------ }
{ Other helper functions }
{ ------------------------------------------------------------------------------ }

function MapTatTypeKind(AKind: TTypeKind): TatTypeKind;
begin
  Result := TatTypeKind(AKind);
end;

function GenericProc(m: TMachineProc): TGenericProc;
begin
  Result := TGenericProc(m);
end;

function AssignedMethod(m: TMethod): boolean;
begin
  Result := (m.Code <> nil) and (m.Data <> nil);
end;

function SameMethod(m1, m2: TMethod): boolean;
begin
  Result := (m1.Code = m2.Code) and (m1.Data = m2.Data);
end;

function LineNumberFromDebugInfo(ADebugInfo: integer): integer;
begin
  Result := ADebugInfo and $FFFFF - 1;
end;

function ColNumberFromDebugInfo(ADebugInfo: integer): integer;
begin
  Result := (ADebugInfo shr 20) - 1;
end;

function LineNumberFromInstruction(Inst: pSimplifiedCode): integer;
begin
  if Assigned(Inst) then
    Result := LineNumberFromDebugInfo(Inst^.vDebugInfo)
  else
    Result := -1;
end;

function ColNumberFromInstruction(Inst: pSimplifiedCode): integer;
begin
  if Assigned(Inst) then
    Result := ColNumberFromDebugInfo(Inst^.vDebugInfo)
  else
    Result := -1;
end;

function InstructionIsExecutable(Script: TatCustomScripter; Inst: pSimplifiedCode): boolean;
begin
  { se for a primeira instrução do programa (jump ou prepare) ou for um prepare considera que a
    instrução não é executável }
  Result := Assigned(Inst) and (Inst^.OpCode <> inPrepare) and
    (not Assigned(Script) or (Inst <> Script.FirstInstruction));
end;

procedure IntToSet(var ASet; AInt: integer; ASize: integer = 4);
begin
  Case ASize of
    1:
      byte(ASet) := byte(AInt);
    2:
      Word(ASet) := Word(AInt);
  else
    integer(ASet) := AInt;
  end;
end;

function IntFromSet(var ASet; ASize: integer = 4): integer;
begin
  Case ASize of
    1:
      Result := byte(ASet);
    2:
      Result := Word(ASet);
  else
    Result := integer(ASet);
  end;
end;

function IntFromConstSet(const ASet): integer;
begin
  Result := integer(ASet);
end;

procedure FatalError(msg: string);
begin
  raise EatScripterFatal.Create(msg);
end;

procedure ScriptInfoError(msg: string);
begin
  raise EatScriptInfoError.Create('ScriptInfo ERROR'#13#10 + msg);
end;

procedure RaiseRuntimeError(msg: string);
begin
  raise EatRuntimeError.Create(msg);
end;

procedure DefinitionError(msg: string);
begin
  raise EatDefinitionError.Create('Definition ERROR'#13#10 + msg);
end;

procedure InternalError(msg: string);
begin
  raise EatInternalError.Create('INTERNAL ERROR'#13#10 + msg);
end;

procedure NoMachineError;
begin
  InternalError('Virtual Machine class not specified. ' +
    'Please add unit "ScripterInit" to the uses clause of your application');
end;

procedure NoScriptFormClassError;
begin
  InternalError('DefaultScriptFormClass class not specified. ' +
    'Please add unit "ScripterInit" to the uses clause of your application');
end;

function EvaluateWatch(AScripter: TatCustomScripter; AExpression: string): TScriptValue;
begin
  if Assigned(AScripter.CurrentScript) and Assigned(AScripter.CurrentScript.VirtualMachine) and
    AScripter.CurrentScript.VirtualMachine.Running then
  begin
    with AScripter.CurrentScript.VirtualMachine.DebugWatches.Add do
      try
        Expression := AExpression;
        CompileAndEvaluate;
        if WatchStatus = wsEvaluated then
          Result := LastResult
        else
          Result := NullValue;
      finally
        Free;
      end;
  end
  else
    Result := NullValue;
end;

function CreateCodeCompletionList(AScripter: TatCustomScripter; AInputText: string;
  AInputPos: integer; var AExprPos, AExprLen: integer): TStringList;
var
  d: integer;
begin
  with TScripterCodeInsight.Create(AScripter.CurrentScript) do
    try
      Result := CreateCodeCompletionList(AInputText, AInputPos, d);
    finally
      Free;
    end;
end;

function CreateCodeCompletionList(AScript: TatScript; AInputText: string; AInputPos: integer;
  var AExprPos, AExprLen: integer): TStringList;
var
  d: integer;
begin
  with TScripterCodeInsight.Create(AScript) do
    try
      Result := CreateCodeCompletionList(AInputText, AInputPos, d);
    finally
      Free;
    end;
end;

{ TatCustomScripter }

constructor TatCustomScripter.Create(AOwner: TComponent);
begin
  { to customize Script and VirtualMachine, set ScriptClass and MachineClass
    onto begining of the descendant constructor }
  inherited Create(AOwner);

  FScriptFormClass := DefaultScriptFormClass;
  FScriptBaseObjectClass := TScriptBaseObject;

  FLastRunning := false;
  FMachineClass := DefaultMachineClass;
  { allow to customize Script and Machine classes }
  DefineInternalClasses;
  FLibOptions := TScripterLibraryOptions.Create;
  FLibOptions.SearchPath.Add(SCurDir);
  FLibOptions.SearchPath.Add(SAppDir);
  FLibOptions.UseScriptFiles := false; { to keep backward compatibility }
  FLoadedScripts := TList.Create;
  { cria a coleção interna de scripts }
  FScripts := TatScripts.Create(self);
  FSaveCompiledCode := false;
  { cria o stream auxiliar PCode em memória }
  FPCode := TMemoryStream.Create;
  { Default value: Não adia a resolução de referências a classes para runtime }
  FDeferObjectResolution := false;
  FTypeInfoFilter := DefaultTypeInfoFilter;
  { cria a estrutura que receberá as informações das classes do scripter }
  FClasses := TatClasses.Create(self);
  { instancia um script para ser usado como padrão no scripter }
  FCurrentScript := FScripts.Add;
  { cria a lista de objetos padrão para a compilação }
  FDefaultInstances := TatObjects.Create(FClasses);
  { event support initialization }
  FEventBroker := TatScripterEventBroker.Create(self);
  FEventBroker.EventAdapters := EventAdapters;
  SetEventSupport(True);
  FEventSetMode := esReplaceEvent;
  FEventUnsetMode := euReplaceNil;
  FWatches := TatScripterWatches.Create(self, TatScripterWatch);

  { Define create for TComponent to avoid problems after declaring TScriptForm.Create. If we don't do that,
    then all ancestors of TScriptForm would have CReate with 0 parameters, because TObject already declared
    Create }
  DefineClass(TComponent).DefineMethod('Create', 1, tkClass, TComponent, ComponentCreateProc, True,
    0, 'AOwner:TComponent');
  DefineClass(TScriptBaseObject).DefineMethod('Create', 0, tkClass, TScriptBaseObject,
    ScriptBaseObjectCreateProc, True);
  if ScriptFormClass <> nil then
    DefineClass(ScriptFormClass).DefineMethod('Create', 1, tkClass, ScriptFormClass, ScriptFormCreateProc,
      True, 0, 'AOwner:TComponent');
  { The first default instance is for free constants,
    free variables and other default properties or methods }
  FInternalInstance := FDefaultInstances.Add(TatInternalObject.Create);
  { Create registered libraries (when ExplicitLoad=false) }
  FLibInstances := TList.Create;
  CreateLibraries;
  AddConstant('True', True);
  AddConstant('False', False);
end;

procedure TatCustomScripter.DefineInternalClasses;
begin
end;

procedure TatCustomScripter.FreeLibInstances;
var
  c: integer;
begin
  with FLibInstances do
    for c := Count - 1 downto 0 do
      TatScripterLibrary(Items[c]).Free;
end;

destructor TatCustomScripter.Destroy;
begin
  FWatches.Free;
  FLibOptions.Free;
  FLoadedScripts.Free;
  FScripts.Free;
  FEventBroker.Free;
  FPCode.Free;
  FreeLibInstances;
  FLibInstances.Free;
  FInternalInstance.Instance.Free;
  FDefaultInstances.Free;
  FClasses.Free;
  inherited;
end;

procedure TatCustomScripter.Clear;
var
  c: integer;
begin
  { ***Check if it is necessary to raise a fatal error is one of scripts are running*** }
  FPCode.Size := 0;

  for c := 0 to FScripts.Count - 1 do
    FScripts[c].Clear;
end;

procedure TatCustomScripter.Compile;
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.Compile;
end;

procedure TatCustomScripter.SilentCompile;
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.SilentCompile;
end;


{$IFDEF NEWSTACK}
function TatCustomScripter.Execute(Input: array of const): TScriptValue;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.Execute([]);
end;
{$ENDIF}

{$IFNDEF NEWSTACK}
function TatCustomScripter.Execute(Input: Variant): Variant;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.Execute(Input);
end;
{$ENDIF}

function TatCustomScripter.Execute: TScriptValue;
begin
  {$IFDEF NEWSTACK}
  Result := Execute([]);
  {$ELSE}
  Result := Execute(null);
  {$ENDIF}
end;

function TatCustomScripter.ExecuteAsVariant: Variant;
begin
  {$IFDEF NEWSTACK}
  Result := Execute.AsVariant;
  {$ELSE}
  Result := Execute;
  {$ENDIF}
end;

{$IFDEF DELPHI2010_LVL}

procedure TatCustomScripter.GenericFieldGetterMachineProc(AMachine: TatVirtualMachine);
var
  Context: TRttiContext;
  rtype: TRttiType;
  field: TRttiField;
  Result: TValue;
begin
  Context := TRttiContext.Create;
  try
    rtype := Context.GetType(AMachine.CurrentObject.ClassType);
    field := rtype.GetField(AMachine.CurrentPropertyName);
    Result := field.GetValue(AMachine.CurrentObject);
    AMachine.ReturnOutputArgValue(Result);
  finally
    Context.Free;
  end;
end;

procedure TatCustomScripter.GenericFieldSetterMachineProc(AMachine: TatVirtualMachine);
var
  Context: TRttiContext;
  rtype: TRttiType;
  field: TRttiField;
begin
  Context := TRttiContext.Create;
  try
    rtype := Context.GetType(AMachine.CurrentObject.ClassType);
    field := rtype.GetField(AMachine.CurrentPropertyName);
    field.SetValue(AMachine.CurrentObject, ScrPrepareValue(field.FieldType,
      AMachine.GetInputArg(0)));
  finally
    Context.Free;
  end;
end;

procedure TatCustomScripter.GenericRecordFieldGetterMachineProc(AMachine: TatVirtualMachine);
var
  Result: TValue;
begin
  if (AMachine.CurrentObject <> nil) and (AMachine.CurrentObject is TGenericRecordWrapper) then
  begin
    Result := TGenericRecordWrapper(AMachine.CurrentObject)
      .GetFieldValue(AMachine.CurrentPropertyName);
    AMachine.ReturnOutputArgValue(Result);
  end;
end;

procedure TatCustomScripter.GenericRecordFieldSetterMachineProc(AMachine: TatVirtualMachine);
var
  field: TRttiField;
begin
  if (AMachine.CurrentObject <> nil) and (AMachine.CurrentObject is TGenericRecordWrapper) then
  begin
    field := TGenericRecordWrapper(AMachine.CurrentObject).FRecordType.GetField(AMachine.CurrentPropertyName);
    field.SetValue(
      TGenericRecordWrapper(AMachine.CurrentObject).FRecordValue.GetReferenceToRawData,
      ScrPrepareValue(field.FieldType, AMachine.GetInputArg(0)));
  end;
end;

procedure TatCustomScripter.GenericMethodMachineProc(AMachine: TatVirtualMachine);
var
  Context: TRttiContext;
  rtype: TRttiType;
  Methods: TArray<TRttiMethod>;
  method: TRttiMethod;
  args: array of TValue;
  params: TArray<TRttiParameter>;
  Result: TValue;
  i, ArgCount: integer;
  metClass: TClass;
  metName: string;
begin
  Context := TRttiContext.Create;
  try
    if AMachine.CurrentObject <> nil then
      metClass := AMachine.CurrentObject.ClassType
    else
      metClass := AMachine.CurrentClass.ClassRef;
    rtype := Context.GetType(metClass);
    ArgCount := AMachine.InputArgCount;

    // retrieve all methods with given name, so we can deal with overloads
    metName := AMachine.CurrentMethodName;
    if metName = '' then
      metName := AMachine.CurrentPropertyName;
    Methods := rtype.GetMethods(metName);
    for method in Methods do
    begin
      params := method.GetParameters;
      if ArgCount = Length(params) then
      begin
        // prepare method input parameters (array of TValue)
        SetLength(args, ArgCount);
        for i := 0 to ArgCount - 1 do
          args[i] := ScrPrepareValue(params[i].ParamType, AMachine.GetInputArg(i));

        // invoke class or instance method
        if method.IsClassMethod or method.IsConstructor then
          Result := method.Invoke(metClass, args)
        else
          Result := method.Invoke(AMachine.CurrentObject, args);

        // return method result, if any
        if (ScrTypeKind(method.ReturnType) <> tkNone) or method.IsConstructor then
          AMachine.ReturnOutputArgValue(Result);

        // set value of arguments passed by reference
        for i := 0 to ArgCount - 1 do
          if (pfVar in params[i].Flags) or (pfOut in params[i].Flags) then
            AMachine.SetInputArgValue(i, args[i]);
        Break;
      end;
    end;
  finally
    Context.Free;
  end;
end;

procedure TatCustomScripter.GenericPropGetterMachineProc(AMachine: TatVirtualMachine);
var
  Context: TRttiContext;
  rtype: TRttiType;
  prop: TRttiProperty;
  Result: TValue;
  v: TScriptValue;
begin
  Context := TRttiContext.Create;
  try
    rtype := Context.GetType(AMachine.CurrentObject.ClassType);
    prop := rtype.GetProperty(AMachine.CurrentPropertyName);
    //AMachine.FCurrentRecordName := '';

    if ScrTypeKind(prop.PropertyType) = atScript.tkMethod then
    begin
      if Assigned(FOnTranslateMethodGetter) and (prop is TRttiInstanceProperty) then
      begin
        v := NullValue;
        FOnTranslateMethodGetter(AMachine, CurrentObject, TRttiInstanceProperty(prop).PropInfo, v);
        ReturnOutputArg(v);
      end
      else
        ReturnOutputArg(NullValue);
    end
    else
    begin
      Result := prop.GetValue(AMachine.CurrentObject);
      AMachine.ReturnOutputArgValue(Result);
    end;
  finally
    Context.Free;
  end;
end;

procedure TatCustomScripter.GenericPropSetterMachineProc(AMachine: TatVirtualMachine);
var
  Context: TRttiContext;
  rtype: TRttiType;
  prop: TRttiProperty;
begin
  Context := TRttiContext.Create;
  try
    rtype := Context.GetType(AMachine.CurrentObject.ClassType);
    prop := rtype.GetProperty(AMachine.CurrentPropertyName);
    if ScrTypeKind(prop.PropertyType) = atScript.tkMethod then
    begin
      if Assigned(FOnTranslateMethodSetter) and (prop is TRttiInstanceProperty) then
        FOnTranslateMethodSetter(AMachine, AMachine.CurrentObject,
          TRttiInstanceProperty(prop).PropInfo, AMachine.GetInputArg(0));
    end
    else
      prop.SetValue(AMachine.CurrentObject, ScrPrepareValue(prop.PropertyType,
        AMachine.GetInputArg(0)));
  finally
    Context.Free;
  end;
end;
{$ENDIF}

{$IFDEF DELPHIXE2_LVL}
procedure TatCustomScripter.GenericIdxPropGetterMachineProc(AMachine: TatVirtualMachine);
var
  Context: TRttiContext;
  rtype: TRttiType;
  prop: TRttiIndexedProperty;
  Indexes: array of TValue;
  Result: TValue;
  idxCount: integer;
  i: integer;
  Meth: TRttiMethod;
begin
  Context := TRttiContext.Create;
  try
    rtype := Context.GetType(AMachine.CurrentObject.ClassType);
    prop := rtype.GetIndexedProperty(AMachine.CurrentPropertyName);
    //AMachine.FCurrentRecordName := '';

    if ScrTypeKind(prop.PropertyType) = atScript.tkMethod then
      ReturnOutputArg(NullValue)
    else
    begin
      if Prop.ReadMethod = nil then
        AMachine.Script.RuntimeError('Could not find getter or setter for indexed property.');
      Meth := Prop.ReadMethod;
      idxCount := Length(Meth.GetParameters);
      SetLength(Indexes, idxCount);
      for i := 0 to idxCount - 1 do
        Indexes[i] := ScrPrepareValue(Meth.GetParameters[i].ParamType, AMachine.GetArrayIndex(i));

      Result := prop.GetValue(AMachine.CurrentObject, Indexes);
      AMachine.ReturnOutputArgValue(Result);
    end;
  finally
    Context.Free;
  end;
end;
{$ENDIF}

{$IFDEF DELPHIXE2_LVL}
procedure TatCustomScripter.GenericIdxPropSetterMachineProc(AMachine: TatVirtualMachine);
var
  Context: TRttiContext;
  rtype: TRttiType;
  prop: TRttiIndexedProperty;
  Meth: TRttiMethod;
  idxCount: integer;
  i: integer;
  Indexes: array of TValue;
begin
  Context := TRttiContext.Create;
  try
    rtype := Context.GetType(AMachine.CurrentObject.ClassType);
    prop := rtype.GetIndexedProperty(AMachine.CurrentPropertyName);
    if ScrTypeKind(prop.PropertyType) <> atScript.tkMethod then
    begin
      if Prop.WriteMethod = nil then
        AMachine.Script.RuntimeError('Could not find getter or setter for indexed property.');
      Meth := Prop.WriteMethod;
      // should subtract one because the last parameter is the property value
      idxCount := Length(Meth.GetParameters) - 1;
      SetLength(Indexes, idxCount);
      for i := 0 to idxCount - 1 do
        Indexes[i] := ScrPrepareValue(Meth.GetParameters[i].ParamType, AMachine.GetArrayIndex(i));

      prop.SetValue(AMachine.CurrentObject, Indexes, ScrPrepareValue(prop.PropertyType,
        AMachine.GetInputArg(0)));
    end;
  finally
    Context.Free;
  end;
end;
{$ENDIF}

function TatCustomScripter.GetArrayIndex(ADim: integer): TScriptValue;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetArrayIndex(ADim);
end;

function TatCustomScripter.InputArgCount: integer;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.InputArgCount;
end;

function TatCustomScripter.GetInputArg(AIndex: integer): TScriptValue;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArg(AIndex);
end;

function TatCustomScripter.GetInputArgAsString(AIndex: integer): string;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArgAsString(AIndex)
end;

function TatCustomScripter.GetInputArgAsClass(AIndex: integer): TClass;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArgAsClass(AIndex)
end;

{$IFNDEF NEXTGEN}
function TatCustomScripter.GetInputArgAsWideString(AIndex: integer): Widestring;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArgAsWideString(AIndex)
end;
{$ENDIF}

function TatCustomScripter.GetInputArgAsInt64(AIndex: integer): Int64;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArgAsInt64(AIndex)
end;

function TatCustomScripter.GetInputArgAsInteger(AIndex: integer): integer;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArgAsInteger(AIndex)
end;

function TatCustomScripter.GetInputArgAsBoolean(AIndex: integer): boolean;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArgAsBoolean(AIndex)
end;

function TatCustomScripter.GetInputArgAsFloat(AIndex: integer): double;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArgAsFloat(AIndex)
end;

function TatCustomScripter.GetInputArgAsDateTime(AIndex: integer): TDateTime;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.GetInputArgAsDateTime(AIndex)
end;

procedure TatCustomScripter.ReturnOutputArg(AValue: TScriptValue);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.ReturnOutputArg(AValue)
end;

procedure TatCustomScripter.SetInputArgIfByRef(AIndex: integer; const AValue: TScriptValue);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.SetInputArgIfByRef(AIndex, AValue)
end;

procedure TatCustomScripter.SetInputArg(AIndex: integer; const AValue: TScriptValue);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.SetInputArg(AIndex, AValue)
end;

{ ------------------------------------------------------------------------------ }
{ Rotina para adicionar funções do usuário }
{ ------------------------------------------------------------------------------ }

procedure TatCustomScripter.AddFunction(Name: string; Address: TBuiltInProc);
begin
  DefinitionError('Use SetProc instead');
end;

{ ------------------------------- }
{ Fake PCode published property }
{ ------------------------------- }

procedure TatCustomScripter.DefineProperties(Filer: TFiler);

  function doWrite: boolean;
  begin
    { testa se existe um ancestral e testa o valor herdado }
    if Filer.Ancestor <> nil then
      { se o conteúdo do ancestral for nulo então só grava se o conteúdo
        do descendente for não nulo }
      if TatCustomScripter(Filer.Ancestor).FPCode.Size = 0 then
        Result := Compiled and SaveCompiledCode
      else
        { se o conteúdo do ancestral for não nulo, só grava se o
          conteúdo do descendente for diferente ou nulo }
        Result := Compiled and SaveCompiledCode and not TatCustomScripter(Filer.Ancestor)
          .PCodeEquals(FPCode)
    else
      { se não tem ancestral então só grava caso o conteúdo seja não nulo }
      Result := Compiled and SaveCompiledCode;
  end;

begin
  inherited;
  Filer.DefineBinaryProperty('PCode', ReadPCodeProp, WritePCodeProp, doWrite);
end;

{$IFDEF DELPHI2010_LVL}

function TatCustomScripter.DefineRecord(ATypeInfo: PTypeInfo; ARecordName: string): TatClass;
begin
  Result := FClasses.AddRecord(ATypeInfo, ARecordName);

  Result.DefineMethod('Create', 0, tkClass, nil, RecordCreateProc, True);
  Result.DefineMethod('Free', 0, tkNone, nil, RecordFreeProc);
end;
{$ENDIF}

function TatCustomScripter.PCodeEquals(pcode: TStream): boolean;
begin
  Result := (FPCode.Size = pcode.Size); // not implemented (fail in heritage)
end;

procedure TatCustomScripter.ReadPCodeProp(Stream: TStream);
var
  Size, p: integer;
begin
  { Carrega o conteúdo da propriedade a partir do stream }

  { lê o tamanho do stream, como cabeçalho }
  Stream.ReadBuffer(Size, sizeof(Size));
  p := Stream.Position;
  { carrega o código do memory stream para a memória executável }
  LoadCodeFromStream(Stream);
  { make a copy of the stream to FPCode stream }
  Stream.Position := p;
  FPCode.CopyFrom(Stream, Size);
end;

{$IFDEF DELPHI2010_LVL}

procedure TatCustomScripter.RecordCreateProc(AMachine: TatVirtualMachine);
var
  Rec: TValue;
begin
  TValue.Make(nil, AMachine.CurrentClass.FRecordRef, Rec);
  AMachine.ReturnOutputArg(ObjectToVar(TGenericRecordWrapper.Create(Rec)));
end;

procedure TatCustomScripter.RecordFreeProc(AMachine: TatVirtualMachine);
begin
  if (AMachine.CurrentObject <> nil) and (AMachine.CurrentObject is TGenericRecordWrapper) then
    TGenericRecordWrapper(AMachine.CurrentObject).Free;
end;

function TatCustomScripter.DefineClassByRTTI(AClass: TClass; AClassName: string;
  AVisibilityFilter: TMemberVisibilitySet; ARecursive: boolean; ARedefine: TRedefineOption)
  : TatClass;
var
  Options: TDefineClassOptions;
begin
  Options := TDefineClassOptions.Create;
  try
    Options.VisibilityFilter := AVisibilityFilter;
    Options.Recursive := ARecursive;
    Options.Redefine := ARedefine;
    Result := FClasses.DefineClass(AClass, Options, AClassName);
  finally
    Options.Free;
  end;
end;

function TatCustomScripter.DefineClassByRTTI(AClass: TClass;
  ARedefine: TRedefineOption; ARecursive: boolean = false; AClassName: string = '';
  AVisibilityFilter: TMemberVisibilitySet = [mvPublic, mvPublished]): TatClass;
begin
  Result := DefineClassByRTTI(AClass, AClassName, AVisibilityFilter, ARecursive, ARedefine);
end;

function TatCustomScripter.DefineRecordByRTTI(ATypeInfo: pointer): TatClass;
var
  Context: TRttiContext;
  atClass: TatClass;
  rtype: TRttiType;
  field: TRttiField;
begin
  Context := TRttiContext.Create;
  try
    rtype := Context.GetType(ATypeInfo);
    atClass := DefineRecord(ATypeInfo);

    for field in rtype.GetFields do
      atClass.DefineProp(field.Name, ScrTypeKind(field.FieldType),
        GenericRecordFieldGetterMachineProc, GenericRecordFieldSetterMachineProc,
        ScrClassType(field.FieldType)).FPropertyClassName := ScrClassName(field.FieldType);

    Result := atClass;
  finally
    Context.Free;
  end;
end;
{$ENDIF}

procedure TatCustomScripter.WritePCodeProp(Stream: TStream);
var
  Size: integer;
begin
  { Armazena no stream o conteúdo da propriedade }

  { Save PCode from executable heap to PCode memory stream }
  SaveCodeToStream(FPCode);
  { grava como cabeçalho o tamanho do stream }
  Size := FPCode.Size;
  Stream.Write(Size, sizeof(Size));
  { grava o conteúdo }
  FPCode.Position := 0;
  Stream.CopyFrom(FPCode, Size);
end;

function TatCustomScripter.GetCompiled: boolean;
begin
  if Assigned(FCurrentScript) then
    Result := FCurrentScript.Compiled
  else
  begin
    InternalError('Default script is not available');
    Result := false;
  end;
end;

function TatCustomScripter.GetFirstInstruction: pSimplifiedCode;
begin
  if Assigned(FCurrentScript) then
    Result := FCurrentScript.FirstInstruction
  else
  begin
    InternalError('Default script is not available');
    Result := nil;
  end;
end;

procedure TatCustomScripter.GetRowColFromSource(APos: integer; var row, col: integer);
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.GetRowColFromSource(APos, row, col)
  else
    InternalError('Default script is not available');
end;

function TatCustomScripter.GetScriptInfo: TatScriptInfo;
begin
  if Assigned(FCurrentScript) then
    Result := FCurrentScript.ScriptInfo
  else
  begin
    InternalError('Default script is not available');
    Result := nil;
  end;
end;

function TatCustomScripter.GetSourceCode: TStrings;
begin
  if Assigned(FCurrentScript) then
    Result := FCurrentScript.SourceCode
  else
  begin
    InternalError('Default script is not available');
    Result := nil;
  end;
end;

procedure TatCustomScripter.SetSourceCode(const Value: TStrings);
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.SourceCode := Value
  else
    InternalError('Default script is not available');
end;

procedure TatCustomScripter.SetCompiled(const Value: boolean);
begin
  CheckMachine;
  if FCurrentScript.VirtualMachine.Running then
    FatalError('Cannot change compiled property while script is running.')
  else
    FCurrentScript.Compiled := Value;
end;

function TatCustomScripter.GetSilentCompiled: boolean;
begin
  if Assigned(FCurrentScript) then
    Result := FCurrentScript.SilentCompiled
  else
  begin
    InternalError('Default script is not available');
    Result := false;
  end;
end;

procedure TatCustomScripter.SetScriptBaseObjectClass(const Value: TScriptBaseObjectClass);
begin
  if FScriptBaseObjectClass <> Value then
  begin
    FScriptBaseObjectClass := Value;
    RegisterClass(FScriptBaseObjectClass);
  end;
end;

procedure TatCustomScripter.SetScriptFormClass(const Value: TScriptFormClass);
begin
  if FScriptFormClass <> Value then
  begin
    if Value.GetInterfaceEntry(IScriptBasedForm) = nil then
      DefinitionError(Format('Invalid value for property ScriptFormClass. '+
        'Class %s does not implement interface IScriptBasedForm',
        [Value.ClassName]));
    FScriptFormClass := Value;
    RegisterClass(FScriptFormClass);
  end;
end;

procedure TatCustomScripter.SetSilentCompiled(const Value: boolean);
begin
  CheckMachine;
  if FCurrentScript.VirtualMachine.Running then
    FatalError('Cannot change compiled property while script is running.')
  else
    FCurrentScript.SilentCompiled := Value
end;

function TatCustomScripter.GetBreakPoints: TatScriptBreakPoints;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.BreakPoints
end;

function TatCustomScripter.GetCurrentObject: TObject;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.CurrentObject
end;

function TatCustomScripter.GetCurrentClass: TatClass;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.CurrentClass
end;

function TatCustomScripter.GetHalted: boolean;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.Halted
end;

function TatCustomScripter.GetLastExceptionClassName: string;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.LastExceptionClassName
end;

function TatCustomScripter.GetLastExceptionCol: integer;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.LastExceptionCol;
end;

function TatCustomScripter.GetLastExceptionHelpContext: integer;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.LastExceptionHelpContext
end;

function TatCustomScripter.GetLastExceptionLine: integer;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.LastExceptionLine;
end;

function TatCustomScripter.GetLastExceptionMessage: string;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.LastExceptionMessage
end;

function TatCustomScripter.GetNextInstruction: pSimplifiedCode;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.NextInstruction
end;

function TatCustomScripter.GetOnExecHook: TNotifyEvent;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.OnExecHook
end;

function TatCustomScripter.GetOnPauseChanged: TNotifyEvent;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.OnPauseChanged
end;

function TatCustomScripter.GetPaused: boolean;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.Paused
end;

function TatCustomScripter.GetCallExecHookEvent: boolean;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.CallExecHookEvent
end;

function TatCustomScripter.GetRunning: boolean;
var
  c: integer;
begin
  Result := false;
  for c := 0 to Scripts.Count - 1 do
    if (Scripts[c].VirtualMachine <> nil) and (Scripts[c].VirtualMachine.Running) then
    begin
      Result := True;
      exit;
    end;
end;

procedure TatCustomScripter.Halt;
var
  c: integer;
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.Halt;
  for c := 0 to Scripts.Count - 1 do
    if Assigned(Scripts[c].VirtualMachine) and (Scripts[c] <> FCurrentScript) then
      Scripts[c].VirtualMachine.Halt;
end;

procedure TatCustomScripter.SetOnExecHook(const Value: TNotifyEvent);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.OnExecHook := Value
end;

procedure TatCustomScripter.SetOnPauseChanged(const Value: TNotifyEvent);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.OnPauseChanged := Value
end;

procedure TatCustomScripter.LoadCodeFromStream(AStream: TStream);
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.LoadCodeFromStream(AStream)
  else
    InternalError('Default script is not available');
end;

procedure TatCustomScripter.SaveCodeToStream(AStream: TStream);
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.SaveCodeToStream(AStream)
  else
    InternalError('Default script is not available');
end;

procedure TatCustomScripter.SolveAbsoluteAddressing;
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.SolveAbsoluteAddressing
end;

procedure TatCustomScripter.SourceCodeChanged(AScript: TatScript);
begin
end;

function TatCustomScripter.ExpandedDebugInfo: boolean;
begin
  if Assigned(FCurrentScript) then
    Result := FCurrentScript.ExpandedDebugInfo
  else
  begin
    InternalError('Default script is not available');
    Result := false;
  end;
end;

procedure TatCustomScripter.ExpandDebugInfo(RequiresCompilation: boolean = True);
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.ExpandDebugInfo(RequiresCompilation)
  else
    InternalError('Default script is not available');
end;

procedure TatCustomScripter.LoadCodeFromFile(AFileName: string);
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.LoadCodeFromFile(AFileName)
  else
    InternalError('Default script is not available');
end;

procedure TatCustomScripter.SaveCodeToFile(AFileName: string);
begin
  if Assigned(FCurrentScript) then
    FCurrentScript.SaveCodeToFile(AFileName)
  else
    InternalError('Default script is not available');
end;

function TatCustomScripter.FindFileInSearchPath(const CompName, SrcName: string): string;

  function TranslateDir(const s: string): string;
  begin
    if CompareText(SCurDir, Copy(s, 1, Length(SCurDir))) = 0 then
      Result := '.' + Copy(s, Length(SCurDir) + 1, Length(s))
    else if CompareText(SAppDir, Copy(s, 1, Length(SAppDir))) = 0 then
      {$IFDEF DELPHI6_LVL}
      Result := ExcludeTrailingPathDelimiter(ExtractFilePath(ParamStr(0))) +
        Copy(s, Length(SAppDir) + 1, Length(s))
      {$ELSE}
      Result := ExcludeTrailingBackslash(ExtractFilePath(ParamStr(0))) +
        Copy(s, Length(SAppDir) + 1, Length(s))
      {$ENDIF}
    else
      Result := s;
  end;

var
  i, p, L: integer;
  DirList: string;
  c: integer;
begin
  DirList := '';
  for c := 0 to FLibOptions.SearchPath.Count - 1 do
    if Trim(FLibOptions.SearchPath[c]) <> '' then
    begin
      if DirList <> '' then
        DirList := DirList + ';';
      DirList := DirList + TranslateDir(FLibOptions.SearchPath[c]);
    end;

  p := 1;
  L := Length(DirList);
  while True do
  begin
    while (p <= L) and (DirList[p] = ';') do
      Inc(p);
    if p > L then
      Break;
    i := p;
    while (p <= L) and (DirList[p] <> ';') do
    begin
      {$IFDEF DELPHI2009_LVL}
      if IsLeadChar(DirList[p]) then
        Inc(p);
      {$ELSE}
      if DirList[p] in LeadBytes then
        Inc(p);
      {$ENDIF}
      Inc(p);
    end;
    Result := Copy(DirList, i, p - i);
    {$IFDEF DELPHI2009_LVL}
    Result := IncludeTrailingPathDelimiter(Result);
    {$ELSE}
    if not(AnsiLastChar(Result)^ in [':', '\']) then
      Result := Result + '\';
    {$ENDIF}
    if FileExists(Result + CompName) then
    begin
      Result := ExpandFileName(Result + CompName);
      exit;
    end
    else if FileExists(Result + SrcName) then
    begin
      Result := ExpandFileName(Result + SrcName);
      exit;
    end;
  end;
  Result := '';
end;

function TatCustomScripter.FindScriptFile(AName: string): string;
begin
  Result := FindFileInSearchPath(ChangeFileExt(AName, FLibOptions.FCompiledFileExt),
    ChangeFileExt(AName, FLibOptions.FSourceFileExt));
end;

function TatCustomScripter.FindFormFile(AName: string): string;
begin
  Result := FindFileInSearchPath(AName, ChangeFileExt(AName, FLibOptions.FFormFileExt));
end;

procedure TatCustomScripter.CreateLibraries;
var
  c: integer;
begin
  { instantiate libraries not marked with ExplicitLoad
    (when ExplicitLoad=true, load occour with method AddLibrary
    or with special script methods - see uSystemLibrary.pas }
  with atLibraryList do
    for c := 0 to Count - 1 do
      with Items[c] do
        if not ExplicitLoad then
          AddLibrary(LibraryClass, True); // auto loaded libraries are also used by scripter
end;

function TatCustomScripter.FindLibraryByClass(ALibraryClass: TatScripterLibraryClass)
  : TatScripterLibrary;
var
  c: integer;
begin
  for c := 0 to FLibInstances.Count - 1 do
    if TatScripterLibrary(FLibInstances[c]).ClassType = ALibraryClass then
    begin
      Result := TatScripterLibrary(FLibInstances[c]);
      exit;
    end;
  Result := nil;
end;

procedure TatCustomScripter.AddLibraryInstance(ALibrary: TatScripterLibrary; AName: string;
  ADefault: boolean = True; AddMethod: boolean = True; LibName: string = '');
begin
  FLibInstances.Add(ALibrary);
  { also register a default property on internal class to get a reference to library instances,
    the property will have the same name of the library (virtual method LibraryName) }
  if AddMethod then
    with FInternalInstance.atClass.DefineMethod(AName, 0, tkClass, ALibrary.ClassType,
      ALibrary.SelfProc) do
    begin
      FResultClassName := LibName;
    end;

  { here the registration process should occur }
  FLibraryNameUnderRegistration := AName;
  ALibrary.Init;
  FLibraryNameUnderRegistration := '';
  ALibrary.FDefaultInstanceName := LibName;
  if ADefault then
    UsesObject(ALibrary, LibName, LibName);
end;

procedure TatCustomScripter.RemoveLibraryInstance(ALibrary: TatScripterLibrary; AName: string);
var
  c: integer;
begin
  ALibrary.Finalize;
  FLibInstances.Remove(ALibrary);
  if FInternalInstance.atClass.MethodByName(AName) <> nil then
    FInternalInstance.atClass.MethodByName(AName).Free;
  if FDefaultInstances.IndexOf(ALibrary.FDefaultInstanceName) <> -1 then
    FDefaultInstances[FDefaultInstances.IndexOf(ALibrary.FDefaultInstanceName)].Free;

  { Since a library was removed, then we need to clear all scripts, because
    the compiled code became outdated and errors might appear. By clearing the scripts,
    we ensure that they will be recompiled in a new execution. This is valid for script-based libraries }
  if ALibrary is TatScriptBasedLibrary then
    for c := 0 to Scripts.Count - 1 do
      if TatScriptBasedLibrary(ALibrary).FInternalScript <> Scripts[c] then
        Scripts[c].Clear;
end;

procedure TatCustomScripter.RemoveProperty(AName: string);
begin
  FInternalInstance.atClass.RemoveProperty(AName);
end;

function TatCustomScripter.AddLibrary(ALibraryClass: TatScripterLibraryClass;
  ADefault: boolean = True): TatScripterLibrary;
begin
  Result := FindLibraryByClass(ALibraryClass);
  { do not duplicate libraries }
  if not Assigned(Result) then
  begin
    Result := ALibraryClass.Create(self);
    AddLibraryInstance(Result, ALibraryClass.LibraryName, ADefault);
  end;
end;

function TatCustomScripter.LoadLibrary(ALibraryName: string; ADefault: boolean = True;
  ASilent: boolean = false): TatScripterLibrary;
var
  c: integer;
  ok: boolean;
  ScriptFileName: string;
  NewScript: TatScript;
begin
  ok := false;
  Result := nil;

  { Check if the library name matches the name of a registered Delphi library }
  with atLibraryList do
    for c := 0 to Count - 1 do
      with Items[c] do
        if SameText(ALibraryName, LibraryClass.LibraryName) then
        begin
          Result := AddLibrary(LibraryClass, ADefault);
          ok := True;
          Break;
        end;

  { Check if there is a script inside Scripts collection with same UnitName as the library being loaded.
    If yes, compile and SelfRegisterAsLibrary }
  if not ok and (ALibraryName <> '') then
  begin
    for c := 0 to Scripts.Count - 1 do
      if SameText(ALibraryName, Scripts[c].UnitName) or
        SameText(ALibraryName, Scripts[c].ScriptInfo.UnitName) then
      begin
        if not Scripts[c].FCompiling then
        begin
          if not Scripts[c].CheckRegisteredAsLibrary(self, Result) then
          begin
            Result := Scripts[c].SelfRegisterAsLibrary(ALibraryName);
          end;
          ok := True;
          Break;
        end
        else
          InternalError(Format('Circular reference for unit %s.', [ALibraryName]));
      end;
  end;

  { Check if there is a compiled script file with the same name in the search path. If yes, register it }
  if LibOptions.UseScriptFiles and not ok then
  begin
    ScriptFileName := FindScriptFile(ALibraryName);
    if (ScriptFileName <> '') then
    begin
      if not IsFileRegisteredAsLibrary(ScriptFileName, Result) then
      begin
        NewScript := Scripts.Add;
        if ExtractFileExt(ScriptFileName) = FLibOptions.FCompiledFileExt then
          NewScript.LoadCodeFromFile(ScriptFileName)
        else
          NewScript.SourceCode.LoadFromFile(ScriptFileName);
        Result := NewScript.SelfRegisterAsLibrary(ALibraryName);
        { Set FFileName AFTER registering as a library, because SelfRegisterAsLibrary call Clear method
          which set FFileName to empty strings }
        NewScript.FFileName := ScriptFileName;
        FLoadedScripts.Add(NewScript);
        ok := True;
      end
      else
        ok := True;
    end;
  end;

  { If no library or script file found, and not silent compilation, then raise an error }
  if not ok and not ASilent then
    InternalError(Format('Library ''%s'' not found', [ALibraryName]));
end;

procedure TatCustomScripter.LoadLibrary2(ALibraryName: string; ADefault: boolean = True);
begin
  LoadLibrary(ALibraryName, ADefault);
end;

function TatCustomScripter.IsFileRegisteredAsLibrary(AFileName: string;
  var ALib: TatScripterLibrary): boolean;
var
  c: integer;
begin
  ALib := nil;
  Result := false;
  for c := 0 to Scripts.Count - 1 do
    if AnsiCompareText(Scripts[c].FFileName, AFileName) = 0 then
    begin
      Result := Scripts[c].CheckRegisteredAsLibrary(self, ALib);
      Break;
    end;
end;

function TatCustomScripter.SystemLibrary: TatClass;
begin
  Result := ClassByName('TatSystemLibrary');
end;

function TatCustomScripter.ClassByName(AName: string): TatClass;
begin
  Result := FClasses.ClassByName(AName);
end;

// obsolete
function TatCustomScripter.AddDelphiClass(AClass: TClass): TatClass;
begin
  Result := FClasses.AddClassByRTTI(AClass);
end;

function TatCustomScripter.DefineClass(AClass: TClass; AClassName: string = ''): TatClass;
begin
  Result := FClasses.AddClassByRTTI(AClass, AClassName);
end;

function TatCustomScripter.UsesObject(AObject: TObject; AName: string = ''; AClassName: string = '')
  : TatClass;
begin
  Result := FDefaultInstances.Add(AObject, AName, AClassName).atClass;
end;

procedure TatCustomScripter.AddComponents(AComp: TComponent);
var
  c: integer;
begin
  for c := 0 to AComp.ComponentCount - 1 do
    FInternalInstance.atClass.AddDelphiObjectProp(AComp.Components[c].Name, AComp.Components[c])
end;

procedure TatCustomScripter.AddDataModule(ADataModule: TDataModule;
  ADataModuleClassName: string = '');
var
  ADMClass: TatClass;
  c: integer;
begin
  if ADataModule.Name = '' then
    DefinitionError('Cannot add data module without a name');

  { register data module as a global property of scripter }
  AddComponent(ADataModule);

  { register the class of data module }
  ADMClass := DefineClass(ADataModule.ClassType, ADataModuleClassName);

  { register subcomponentes in the data module class }
  for c := 0 to ADataModule.ComponentCount - 1 do
    if ADataModule.Components[c].Name <> '' then
      with ADMClass.DefineProp(ADataModule.Components[c].Name, tkClass, nil, nil,
        ADataModule.Components[c].ClassType) do
        Getter := GenericProc(GetFormComponentProc);
end;

function TatCustomScripter.DefineFormClass(AForm: TComponent; AFormClassName: string = '')
  : TatClass;
var
  c: integer;
begin
  { register the form class }
  Result := DefineClass(AForm.ClassType, AFormClassName);

  { register the subcomponents of form }
  for c := 0 to AForm.ComponentCount - 1 do
    if AForm.Components[c].Name <> '' then
      with Result.DefineProp(AForm.Components[c].Name, tkClass, nil, nil,
        AForm.Components[c].ClassType) do
        Getter := GenericProc(GetFormComponentProc);
end;

procedure TatCustomScripter.AddForm(AForm: TComponent; AFormClassName: string = '');
begin
  if AForm.Name = '' then
    DefinitionError('Cannot add form without a name');

  { registers the form as a global property in scripter }
  AddComponent(AForm);

  { registers the form class }
  DefineFormClass(AForm, AFormClassName);
end;

procedure TatCustomScripter.AddComponent(AComp: TComponent);
begin
  FInternalInstance.atClass.AddDelphiObjectProp(AComp.Name, AComp);
end;

procedure TatCustomScripter.AddConstant(AName: string; AValue: TScriptValue);
begin
  FInternalInstance.atClass.AddConstant(AName, AValue);
end;

procedure TatCustomScripter.AddEnumeration(ATypeInfo: PTypeInfo);
begin
  FInternalInstance.atClass.AddEnumeration(ATypeInfo);
end;

procedure TatCustomScripter.AddObject(AName: string; AObject: TObject);
begin
  FInternalInstance.atClass.AddObject(AName, AObject)
end;

{$IFNDEF NEXTGEN}
procedure TatCustomScripter.AddVariable(AName: string; var AVar: Variant);
begin
  FInternalInstance.atClass.AddVariable(AName, AVar)
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatCustomScripter.AddVariable(AName: string; var AVar: extended);
begin
  FInternalInstance.atClass.AddVariable(AName, AVar)
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatCustomScripter.AddVariable(AName: string; var AVar: double);
begin
  FInternalInstance.atClass.AddVariable(AName, AVar)
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatCustomScripter.AddVariable(AName: string; var AVar: string);
begin
  FInternalInstance.atClass.AddVariable(AName, AVar)
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatCustomScripter.AddVariable(AName: string; var AVar: Widestring);
begin
  FInternalInstance.atClass.AddVariable(AName, AVar)
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatCustomScripter.AddVariable(AName: string; var AVar: integer);
begin
  FInternalInstance.atClass.AddVariable(AName, AVar)
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatCustomScripter.AddVariable(AName: string; var AVar: boolean);
begin
  FInternalInstance.atClass.AddVariable(AName, AVar)
end;
{$ENDIF}

function TatCustomScripter.DefineProp(AName: string; ADataType: TatTypeKind;
  AGetter, ASetter: TMachineProc; APropertyClass: TClass; AIsClassProp: boolean;
  AIndexCount: integer): TatProperty;
begin
  Result := FInternalInstance.atClass.DefineProp(AName, ADataType, AGetter, ASetter, APropertyClass,
    AIsClassProp, AIndexCount);
end;

function TatCustomScripter.DefineMethod(AName: string; AArgCount: integer;
  AResultDataType: TatTypeKind; AResultClass: TClass; AProc: TMachineProc;
  AIsClassMethod: boolean = false; ADefArgCount: integer = 0; AParameterHints: string = '')
  : TatMethod;
begin
  Result := FInternalInstance.atClass.DefineMethod(AName, AArgCount, AResultDataType, AResultClass,
    AProc, AIsClassMethod, ADefArgCount, AParameterHints);
end;

procedure TatCustomScripter.SetClasses(const Value: TatClasses);
begin
  FClasses.Assign(Value);
end;

function TatCustomScripter.InProcessExecute(AScriptStub: string): boolean;
begin
  if Assigned(FCurrentScript.VirtualMachine) then
  begin
    FCurrentScript.VirtualMachine.InProcessExecute(AScriptStub);
    Result := True;
  end
  else
    Result := false;
end;

procedure TatCustomScripter.BeforeCompile;
begin
  // Nothing
end;

procedure TatCustomScripter.BeforeLoadCode;
begin
  // Nothing
end;

procedure TatCustomScripter.InternalCompileError(msg: string; row, col: integer;
  AScript: TatScript);
var
  AShow: boolean;
begin
  AShow := True;
  if AScript.FUnitName <> '' then
    msg := 'Unit ' + AScript.FUnitName + ': ' + msg;

  if not AScript.FIsDebugScript then
    DoCompileError(msg, row, col, AShow, AScript);
  if AShow then
    // when the IDE is running an Exception can be triggered here
    // when debugging options "stop on exception" is enabled.
    // This exception is handled correct when run not from the IDE
    raise EatCompileError.Create(msg + '.'#13#10 + 'Source position: ' + inttostr(row) + ',' +
      inttostr(col))
  else
    Abort;
end;

procedure TatCustomScripter.InternalCompileError(msg: string; debuginfo: integer;
  AScript: TatScript);
var
  row, col: integer;
begin
  GetRowColFromSource(debuginfo, row, col);
  InternalCompileError(msg, row, col, AScript);
end;

procedure TatCustomScripter.InternalRuntimeError(msg: string; AScript: TatScript);
var
  AShow: boolean;
  row, col: integer;
  AUnitName: string;
begin
  row := 0;
  col := 0;
  if (AScript <> nil) and (AScript.VirtualMachine <> nil) and
    (AScript.VirtualMachine.FCurrentInstruction <> nil) then
    AScript.GetRowColFromInst(AScript.VirtualMachine.FCurrentInstruction, row, col);

  AShow := True;
  AUnitName := AScript.FUnitName;
  if AUnitName = '' then
    AUnitName := AScript.ScriptInfo.UnitName;
  if AUnitName <> '' then
    msg := 'File library ' + AUnitName + ': ' + msg;

  if not AScript.FIsDebugScript and Assigned(FOnRuntimeError) then
    FOnRuntimeError(self, msg, row, col, AShow);
  if AShow then
    // when the IDE is running an Exception can be triggered here
    // when debugging options "stop on exception" is enabled.
    // This exception is handled correct when run not from the IDE
    raise EatScripterRuntime.CreateFmt('RUNTIME ERROR'#13#10'%s'#13#10'Position: %d, %d',
      [msg, Row, Col])
  else
    Abort;
end;

procedure TatCustomScripter.SetEventSetMode(const Value: TEventSetMode);
begin
  FEventSetMode := Value;
end;

procedure TatCustomScripter.SetEventSupport(const Value: boolean);
begin
  if FEventSupport <> Value then
  begin
    FEventSupport := Value;
    if FEventSupport then
    begin
      Include(FTypeInfoFilter, TTypeKind(tkMethod));
      FOnTranslateMethodGetter := TranslateMethodGetter;
      FOnTranslateMethodSetter := TranslateMethodSetter;
    end
    else
    begin
      Exclude(FTypeInfoFilter, TTypeKind(tkMethod));
      FOnTranslateMethodGetter := nil;
      FOnTranslateMethodSetter := nil;
    end;
  end;
end;

procedure TatCustomScripter.SetEventUnsetMode(const Value: TEventUnsetMode);
begin
  FEventUnsetMode := Value;
end;

function TatCustomScripter.GetOnExecuteEvent: TExecuteEventProc;
begin
  Result := FEventBroker.OnExecuteEvent;
end;

function TatCustomScripter.GetOnSetEvent: TSetEventProc;
begin
  Result := FEventBroker.OnSetEvent;
end;

function TatCustomScripter.GetOnSettingEvent: TSettingEventProc;
begin
  Result := FEventBroker.OnSettingEvent;
end;

function TatCustomScripter.GetOnUnsettingEvent: TUnsetEventProc;
begin
  Result := FEventBroker.OnUnsettingEvent;
end;

procedure TatCustomScripter.SetOnExecuteEvent(const Value: TExecuteEventProc);
begin
  FEventBroker.OnExecuteEvent := Value;
end;

procedure TatCustomScripter.SetOnSetEvent(const Value: TSetEventProc);
begin
  FEventBroker.OnSetEvent := Value;
end;

procedure TatCustomScripter.SetOnSettingEvent(const Value: TSettingEventProc);
begin
  FEventBroker.OnSettingEvent := Value;
end;

procedure TatCustomScripter.SetOnUnsettingEvent(const Value: TUnsetEventProc);
begin
  FEventBroker.OnUnsettingEvent := Value;
end;

procedure TatCustomScripter.BeforeExecute(AMachine: TatVirtualMachine; ALabel: string);
begin
  { allow a external event handler to prepare the scripter for start running
    triggered by Execute or ExecuteSubroutine call }
  if Assigned(OnBeforeExecute) then
    OnBeforeExecute(AMachine, ALabel);
end;

procedure TatCustomScripter.SetOnBeforeExecute(const Value: TBeforeExecuteEvent);
begin
  FOnBeforeExecute := Value;
end;

procedure TatCustomScripter.Notification(AComponent: TComponent; Operation: TOperation);
var
  c: integer;
begin
  inherited;
  if (Operation = opRemove) and (AComponent is TatCustomScripter) and (AComponent <> self) then
    for c := 0 to Scripts.Count - 1 do
      Scripts[c].SelfUnregisterAsLibrary(TatCustomScripter(AComponent));
end;

function TatCustomScripter.BuildEventHandlerName(Instance: TComponent; PropName: string): string;
begin
  if pos('on', LowerCase(PropName)) = 1 then
    Result := Instance.Name + Copy(PropName, 3, MaxInt)
  else
    Result := Instance.Name + PropName;
end;

function TatCustomScripter.DeclareEventHandler(AProcName: string): integer;
begin
  if Assigned(FCurrentScript) then
    Result := FCurrentScript.DeclareEventHandler(AProcName)
  else
    Result := 0;
end;

function TatCustomScripter.DoSaveCompiledCode: boolean;
begin
  Result := FSaveCompiledCode;
end;

procedure TatCustomScripter.SetLibOptions(const Value: TScripterLibraryOptions);
begin
  FLibOptions.Assign(Value);
end;

procedure TatCustomScripter.Loaded;
{$IFDEF TRIAL}
var
  msg: string;
  i: integer;
  {$ENDIF}
begin
  inherited;
  { Must keep in mind that this event is fired after component is loaded, but before any existing code in the descendant is execute }
  if Assigned(OnGlobalScripterLoaded) then
    OnGlobalScripterLoaded(self);
  {$IFDEF TRIAL}
  msg := 'TjMnSi jStcyruihpgtfedrs htyrtigaflr evdesrwsqiaosnx.z sPduerrcfhtagshey ' +
    'urjekgiiosltpeoriejdu hvnebrgsfivocnd fartt yhuthtypg:t/f/rwdwewd.stwmesdsrotfftgwyahruej.uchotmf.';
  i := 2;
  while i < Length(msg) do
  begin
    System.Delete(msg, i, 1);
    Inc(i);
  end;
  if (CurrentScript <> nil) and (CurrentScript.VirtualMachine <> nil) then
    CurrentScript.VirtualMachine.PerformShowMessage(msg);
  {$ENDIF}
end;

procedure TatCustomScripter.DoUnknownElement(var Context: TElementContext);
begin
  if Assigned(FOnUnknownElement) then
    FOnUnknownElement(self, Context);
end;

{$IFDEF DELPHI2010_LVL}
function TatCustomScripter.ScrClassType(AType: TRttiType): TClass;
begin
  if AType <> nil then
  begin
    if AType.TypeKind = TypInfo.tkRecord then
      Result := TGenericRecordWrapper
    else if AType is TRttiInstanceType then
      Result := TRttiInstanceType(AType).MetaclassType
    else
      Result := GetClass(AType.Name);
  end
  else
    Result := nil;
end;
{$ENDIF}

{$IFDEF DELPHI2010_LVL}
function TatCustomScripter.ScrClassName(AType: TRttiType): string;
begin
  if AType <> nil then
  begin
    if AType.TypeKind = TypInfo.tkRecord then
      Result := AType.Name
    else
      Result := '';
  end
  else
    Result := '';
end;
{$ENDIF}

procedure TatCustomScripter.ScriptBaseObjectCreateProc(AMachine: TatVirtualMachine);
var
  AObject: TScriptBaseObject;
begin
  AObject := ScriptBaseObjectClass.CreateFromScript(AMachine);
  AMachine.ReturnOutputArg(ObjectToVar(AObject));
end;

procedure TatCustomScripter.ScriptFormCreateProc(AMachine: TatVirtualMachine);
var
  AForm: TBaseScriptForm;
begin
  AForm := ScriptFormFactory.CreateScriptForm(TComponent(AMachine.GetInputArgAsObject(0)), AMachine);
  AMachine.ReturnOutputArg(ObjectToVar(AForm));
end;

{$IFDEF DELPHI2010_LVL}
function TatCustomScripter.ScrPrepareValue(AType: TRttiType; AValue: TScriptValue): TValue;
{$IFDEF NEWSTACK}
begin
  if AValue.IsInstanceOf(TGenericRecordWrapper) then
    Result := TGenericRecordWrapper(AValue.AsObject).FRecordValue
  else
    Result := AValue;
end;
{$ELSE}
var
  Set1: Byte;
  Set2: Word;
  Set3: Integer;

  {$IFNDEF NEXTGEN}
  asWide: Widestring;
  {$ENDIF}
begin
  if AType.TypeKind = TypInfo.tkClass then
    TValue.Make(AValue, AType.Handle, Result)
  else if AType.TypeKind = TypInfo.tkEnumeration then
    Result := TValue.FromOrdinal(AType.Handle, AValue)
  else if (AType.TypeKind = TypInfo.tkRecord) and (VarToObject(AValue) is TGenericRecordWrapper)
  then
    Result := TGenericRecordWrapper(VarToObject(AValue)).FRecordValue
  else if (AType.TypeKind = TypInfo.tkSet) then
  begin
    case AType.TypeSize of
      1:
        begin
          Set1 := AValue;
          TValue.Make(@Set1, AType.Handle, Result);
        end;
      2:
        begin
          Set2 := AValue;
          TValue.Make(@Set2, AType.Handle, Result);
        end;
    else
      Set3 := AValue;
      TValue.Make(@Set3, AType.Handle, Result);
    end;
  end
  {$IFNDEF NEXTGEN}
  else if AType.Handle = TypeInfo(Widestring) then
  begin
    // Workaround for bug QC 91912 (Internal Tracking 282866
    // Could not set a TValue of type WideString from other string types
    // We must force the value to be widestring now
    asWide := VarToStr(AValue);
    TValue.Make(@asWide, AType.Handle, Result);
  end
  {$ENDIF}
  else
    if (AType.Handle = TypeInfo(Variant)) then
      Result := TValue.From<Variant>(AValue)
    else
      Result := TValue.FromVariant(AValue).Cast(AType.Handle);
end;
{$ENDIF}

function TatCustomScripter.ScrTypeKind(AType: TRttiType): TatTypeKind;
begin
  Result := tkNone;
  if AType <> nil then
  begin
    case AType.TypeKind of
      TypInfo.tkInteger:
        Result := tkInteger;
      TypInfo.tkChar:
        Result := tkChar;
      TypInfo.tkEnumeration:
        Result := tkEnumeration;
      TypInfo.tkFloat:
        Result := tkFloat;
      TypInfo.tkString:
        Result := tkString;
      TypInfo.tkSet:
        Result := tkSet;
      TypInfo.tkClass:
        Result := tkClass;
      TypInfo.tkMethod:
        Result := tkMethod;
      TypInfo.tkWChar:
        Result := tkWChar;
      TypInfo.tkLString:
        Result := tkLString;
      TypInfo.tkWString:
        Result := tkWString;
      TypInfo.tkVariant:
        Result := tkVariant;
      TypInfo.tkArray:
        Result := tkArray;
      TypInfo.tkRecord:
        Result := tkClass;
      TypInfo.tkInterface:
        Result := tkInterface;
      TypInfo.tkInt64:
        Result := tkInt64;
      TypInfo.tkDynArray:
        Result := tkDynArray;
      TypInfo.tkUString:
        Result := tkUString;
    end;
  end;
end;
{$ENDIF}

procedure TatCustomScripter.ComponentCreateProc(AMachine: TatVirtualMachine);
var
  AResult: TScriptValue;
begin
  with AMachine do
  begin
    AResult := ObjectToVar(TComponentClass(CurrentClass.ClassRef)
      .Create(TComponent(GetInputArgAsObject(0))));
    ReturnOutputArg(AResult);
  end;
end;

function TatCustomScripter.DefaultScriptClass: TScriptClass;
begin
  Result := nil;
end;

procedure TatCustomScripter.CheckMachine;
begin
  if not Assigned(FCurrentScript) then
    InternalError('Default script is not available');
  FCurrentScript.CheckMachine;
end;

procedure TatCustomScripter.CheckRunningChanged(AMachine: TatVirtualMachine);
begin
  if FLastRunning <> GetRunning then
  begin
    FLastRunning := GetRunning;
    DoRunningChanged(AMachine);
  end;
end;

procedure TatCustomScripter.DoRunningChanged(AMachine: TatVirtualMachine);
begin
  if Assigned(FOnRunningChanged) then
    FOnRunningChanged(AMachine);
end;

function TatCustomScripter.DoDebugHook(AMachine: TatVirtualMachine): boolean;
begin
  Result := Assigned(FOnDebugHook);
  if Result then
    FOnDebugHook(self);
end;

function TatCustomScripter.IsAnyRunning: boolean;
var
  c: integer;
begin
  Result := false;
  for c := 0 to Scripts.Count - 1 do
    if (Scripts[c].VirtualMachine <> nil) and Scripts[c].VirtualMachine.Running then
    begin
      Result := True;
      Break;
    end;
end;

procedure TatCustomScripter.SingleDebugHook(AMachine: TatVirtualMachine);
begin
  // nothing
  if Assigned(FOnSingleDebugHook) then
    FOnSingleDebugHook(self);
end;

function TatCustomScripter.GetCurrentDebugScript: TatScript;
begin
  Result := CurrentScript;
  if (CurrentScript <> nil) and (CurrentScript.FOriginalScript <> nil) then
    Result := CurrentScript.FOriginalScript;
end;

procedure TatCustomScripter.DoBreakpointStop;
begin
  if Assigned(FOnBreakpointStop) then
    FOnBreakpointStop(self);
end;

procedure TatCustomScripter.DoCompileError(var msg: string; row, col: integer; var AShow: boolean;
  AScript: TatScript);
begin
  if Assigned(FOnCompileError) then
    FOnCompileError(self, msg, row, col, AShow);
end;

function TatCustomScripter.GetProductVersion: string;
begin
  Result := '6.5.2.1';
  {$IFDEF TRIAL}
  Result := Result + ' TRIAL';
  {$ENDIF}
end;

{ TatClasses }

constructor TatClasses.Create(AScripter: TatCustomScripter);
begin
  FScripter := AScripter;
  inherited Create(TatClass);
end;

function TatClasses.GetItem(i: integer): TatClass;
begin
  Result := TatClass(inherited Items[i]);
end;

function TatClasses.AddRecord(ATypeInfo: PTypeInfo; ARecordName: string): TatClass;
var
  i: integer;
begin
  Inc(FRegLevel);
  try
    if ARecordName = '' then
      ARecordName := TypeInfoName(ATypeInfo);

    i := IndexOf(ARecordName);
    if i >= 0 then
      Result := Items[i]
    else
      Result := TatClass(inherited Add);
    SetLibraryContext(Result);

    if not Assigned(Result.FRecordRef) then
    begin
      Result.FName := ARecordName;
      Result.FRecordRef := ATypeInfo;
    end;
  finally
    Dec(FRegLevel);
  end;
end;

function TatClasses.AddClassByRTTI(AClass: TClass; AClassName: string = ''): TatClass;
var
  list: PPropList;
  c, n, Size: integer;
  i: integer;
begin
  Inc(FRegLevel);
  try
    if AClassName = '' then
      AClassName := AClass.ClassName;

    { creates a scripter TatClass based on the Delphi class if it still doesn't exist }
    i := IndexOf(AClassName);
    if i >= 0 then
      Result := Items[i]
    else
    begin
      Result := TatClass(inherited Add);
    end;
    SetLibraryContext(Result);

    { load Delphi class information, if not loaded yet }
    if not Assigned(Result.FClassRef) then
    begin
      Result.FName := AClassName;
      Result.FClassRef := AClass;

      { if the classname is different from aclass.classname, then addbyrtti the
        original class, and the ancestor will be the original class }
      if CompareText(AClass.ClassName, AClassName) <> 0 then
      begin
        { Add the original class with original name }
        AddClassByRTTI(AClass, '');

        { Makes the original class the ancestor }
        Result.FAncestorName := AClass.ClassName;
        Result.Inherits(Result.FAncestorName);
      end
      else
      begin
        { if the Delphi class has an ancestor, then register register the ancestor class in scripter
          and register the inheritance }
        if AClass.ClassParent <> nil then
        begin
          Result.FAncestorName := AClass.ClassParent.ClassName;
          if (Result.FAncestorName > '') then
            Result.Inherits(Result.FAncestorName);
        end;
      end;

      { if class has runtime information, then add member through (old) RTTI }
      if AClass.ClassInfo <> nil then
      begin
        { load class structure from RTTI (only published properties) }
        n := GetPropList(AClass.ClassInfo, FScripter.FTypeInfoFilter, nil);
        Size := n * sizeof(pointer);
        GetMem(list, Size);
        try
          GetPropList(AClass.ClassInfo, FScripter.FTypeInfoFilter, list);
          for c := 0 to n - 1 do
          begin
            if list^[c]^.PropType^^.Kind = TTypeKind(tkArray) then
            begin
            end
            else
              Result.FProperties.AddByRTTI(list^[c]);
          end;
        finally
          FreeMem(list, Size);
        end;
      end;
    end;
  finally
    Dec(FRegLevel);
  end;
end;

{$IFDEF DELPHI2010_LVL}
function TatClasses.DefineClass(AClass: TClass; Options: TDefineClassOptions;
  AClassName: string = ''): TatClass;
var
  i: integer;
  Context: TRttiContext;
  rtype: TRttiType;
  Methods: TArray<TRttiMethod>;
  method: TRttiMethod;
  param: TRttiParameter;
  prop: TRttiProperty;
  {$IFDEF DELPHIXE2_LVL}
  iprops: TArray<TRttiIndexedProperty>;
  iprop: TRttiIndexedProperty;
  {$ENDIF}
  fields: TArray<TRttiField>;
  field: TRttiField;
  Getter, Setter: TMachineProc;
  regClass: TClass;
  regClassName: string;
  TypeKind: TatTypeKind;
  coverloaded: boolean;
  c: integer;
  {$IFDEF DELPHIXE2_LVL}
  idxCount: integer;
  {$ENDIF}

  procedure RecursiveDefine(AType: TRttiType);
  var
    dclass: TClass;
  begin
    if AType <> nil then
    begin
      case AType.TypeKind of
        TypInfo.tkClass:
          begin
            dclass := FScripter.ScrClassType(AType);
            if (dclass <> nil) and (ClassByName(dclass.ClassName) = nil) then
              DefineClass(dclass, Options, dclass.ClassName);
          end;
        TypInfo.tkEnumeration:
          FScripter.AddEnumeration(AType.Handle);
      end;
    end;
  end;

var
  Pars: TArray<TRttiParameter>;
  scriptMethod: TatMethod;
  props: TArray<TRttiProperty>;
  {$IFDEF DELPHIXE2_LVL}
  NewProp: TatProperty;
  {$ENDIF}
begin
  Inc(FRegLevel);
  try
    if AClassName = '' then
      AClassName := AClass.ClassName;

    i := IndexOf(AClassName);
    if i >= 0 then
      Result := Items[i]
    else
      Result := TatClass(inherited Add);
    SetLibraryContext(Result);

    if not Assigned(Result.FClassRef) or (Options.Redefine <> roNone) then
    begin
      // option to overwrite class members when redefining an already registered class
      if Assigned(Result.FClassRef) and (Options.Redefine = roOverwrite) then
      begin
        Result.Methods.Clear;
        Result.Properties.Clear;
        if Assigned(Result.FAncestor) then
          Result.FAncestor.RemoveDescendant(Result);
      end;

      Result.FName := AClassName;
      Result.FClassRef := AClass;

      // if the classname is different from aclass.classname, then addbyrtti the
      // original class, and the ancestor will be the original class}
      if CompareText(AClass.ClassName, AClassName) <> 0 then
      begin
        // Add the original class with original name}
        DefineClass(AClass, Options, '');

        // Makes the original class the ancestor
        Result.FAncestorName := AClass.ClassName;
        Result.Inherits(Result.FAncestorName);
      end
      else
      begin
        // if the Delphi class has an ancestor, then register the ancestor class in scripter
        // and register the inheritance
        if AClass.ClassParent <> nil then
        begin
          DefineClass(AClass.ClassParent, Options, AClass.ClassParent.ClassName);
          Result.FAncestorName := AClass.ClassParent.ClassName;
          if Result.FAncestorName > '' then
            Result.Inherits(Result.FAncestorName);
        end;

        // define class methods and properties, according to visibility filter
        Context := TRttiContext.Create;
        try
          rtype := Context.GetType(AClass);

          // define methods
          Methods := rtype.GetDeclaredMethods;
          coverloaded := false;
          for method in Methods do
          begin
            if method.HasExtendedInfo and (method.Visibility in Options.VisibilityFilter) then
            begin
              if method.IsConstructor then
              begin
                regClass := AClass;
                TypeKind := tkClass;
                regClassName := '';
              end
              else
              begin
                regClass := FScripter.ScrClassType(method.ReturnType);
                TypeKind := FScripter.ScrTypeKind(method.ReturnType);
                regClassName := FScripter.ScrClassName(method.ReturnType);
              end;

              // define only first declared method when there are overloads
              if (Options.Redefine <> roInclude) or (Result.MethodByName(method.Name) = nil) or (method.IsConstructor and not coverloaded)
              then
              begin
                // Do not automatically override TScriptForm.Create method
                if not (AClass.InheritsFrom(FScripter.ScriptFormClass) and SameText(method.Name, 'Create')) then
                begin
                  Pars := method.GetParameters;
                  scriptMethod := Result.DefineMethod(method.Name, Length(Pars), TypeKind, regClass,
                    FScripter.GenericMethodMachineProc, method.IsClassMethod or method.IsConstructor);
                  scriptMethod.FResultClassName := regClassName;
                  if method.IsConstructor then
                    coverloaded := True;

                  for c := 0 to Length(Pars) - 1 do
                  begin
                    // Set VarArgs
                    if (Pars[c].Flags * [pfVar, pfOut] <> []) then
                      scriptMethod.SetVarArgs([c]);

                    // if it's parameter, the copy the param name to method
                    if c < scriptMethod.ArgDefs.Count then
                    begin
                      scriptMethod.ArgDefs[c].FName := Pars[c].Name;
                      if Pars[c].ParamType <> nil then
                        scriptMethod.ArgDefs[c].FDataTypeName := Pars[c].ParamType.ToString
                      else
                        scriptMethod.ArgDefs[c].FDataTypeName := '';
                    end;
                  end;
                end;
              end;

              if Options.Recursive then
              begin
                if regClass <> AClass then
                  RecursiveDefine(method.ReturnType);
                for param in method.GetParameters do
                  RecursiveDefine(param.ParamType);
              end;
            end;
          end;

          // define properties
          if Options.CustomProperties then
            props := Options.Properties
          else
            props := rtype.GetDeclaredProperties;
          for prop in props do
          begin
            if (prop <> nil) and (prop.Visibility in Options.VisibilityFilter) and (prop.PropertyType <> nil) then
            begin
              if prop.IsReadable then
                Getter := FScripter.GenericPropGetterMachineProc
              else
                Getter := nil;
              if prop.IsWritable then
                Setter := FScripter.GenericPropSetterMachineProc
              else
                Setter := nil;
              regClass := FScripter.ScrClassType(prop.PropertyType);
              if (Options.Redefine <> roInclude) or (Result.PropertyByName(prop.Name) = nil) then
                Result.DefineProp(prop.Name, FScripter.ScrTypeKind(prop.PropertyType), Getter, Setter,
                  regClass).FPropertyClassName := FScripter.ScrClassName(prop.PropertyType);

              if prop.PropertyType <> nil then
              begin
                // if prop.PropertyType is TRttiMethodType then // events (disabled)
                // if EventAdapters.FindAdapter(prop.PropertyType.Handle) = nil then
                // EventAdapters.DefineEventAdapter(prop.PropertyType.Handle, TGenericEventDispatcher, @TGenericEventDispatcher.RaiseEvent, True);

                if prop.PropertyType is TRttiRecordType then // records
                  FScripter.DefineRecordByRTTI(prop.PropertyType.Handle);
              end;

              if Options.Recursive then
                RecursiveDefine(prop.PropertyType);
            end;
          end;

          // define indexed properties
          {$IFDEF DELPHIXE2_LVL}
          iprops := rtype.GetDeclaredIndexedProperties;
          for iprop in iprops do
          begin
            if iprop.Visibility in Options.VisibilityFilter then
            begin
              if iprop.IsReadable then
                Getter := FScripter.GenericIdxPropGetterMachineProc
              else
                Getter := nil;
              if iprop.IsWritable then
                Setter := FScripter.GenericIdxPropSetterMachineProc
              else
                Setter := nil;
              regClass := FScripter.ScrClassType(iprop.PropertyType);

              if iProp.ReadMethod <> nil then
                idxCount := Length(iProp.ReadMethod.GetParameters)
              else
              if iProp.WriteMethod <> nil then
                idxCount := Length(iProp.WriteMethod.GetParameters) - 1; // setter has property value as parameter

              if (Options.Redefine <> roInclude) or (Result.PropertyByName(iprop.Name) = nil) then
              begin
                NewProp := Result.DefineProp(iprop.Name, FScripter.ScrTypeKind(iprop.PropertyType), Getter, Setter,
                  regClass, false, idxCount);
                NewProp.FPropertyClassName := FScripter.ScrClassName(iprop.PropertyType);
                Result.DefaultProperty := NewProp;
              end;

              if iprop.PropertyType <> nil then
              begin
                // if prop.PropertyType is TRttiMethodType then // events (disabled)
                // if EventAdapters.FindAdapter(prop.PropertyType.Handle) = nil then
                // EventAdapters.DefineEventAdapter(prop.PropertyType.Handle, TGenericEventDispatcher, @TGenericEventDispatcher.RaiseEvent, True);

                if iprop.PropertyType is TRttiRecordType then // records
                  FScripter.DefineRecordByRTTI(iprop.PropertyType.Handle);
              end;

              if Options.Recursive then
                RecursiveDefine(iprop.PropertyType);
            end;
          end;
          {$ENDIF}

          // define fields as properties
          if Options.CustomFields then
            fields := Options.Fields
          else
            fields := rtype.GetDeclaredFields;
          for field in fields do
          begin
            if (field <> nil) and (field.Visibility in Options.VisibilityFilter) then
            begin
              regClass := FScripter.ScrClassType(field.FieldType);
              if (Options.Redefine <> roInclude) or (Result.PropertyByName(field.Name) = nil) then
                Result.DefineProp(field.Name, FScripter.ScrTypeKind(field.FieldType),
                  FScripter.GenericFieldGetterMachineProc, FScripter.GenericFieldSetterMachineProc,
                  regClass).FPropertyClassName := FScripter.ScrClassName(field.FieldType);

              if Options.Recursive then
                RecursiveDefine(field.FieldType);
            end;
          end;

        finally
          Context.Free;
        end;
      end;
    end;
  finally
    Dec(FRegLevel);
  end;
end;
{$ENDIF}

function TatClasses.IndexOf(AName: string): integer;
begin
  for Result := 0 to Count - 1 do
    if CompareText(AName, Items[Result].FName) = 0 then
      exit;
  Result := -1;
end;

procedure TatClasses.SetLibraryContext(AClass: TatClass);
begin
  { Sets the context (unit, namespace) under which this class was registered.
    Note that registering a class might register other classes automatically as well
    (like registering a TButton might register a TWinControl if it's not yet registered)
    This means register TButton under "StdCtrls" context will also register TWinControl
    in same context (as a second level).
    However, if a class is explicitly redefined by a library (FRegLevel = 1) we will
    force the new context to be changed, because defining a class explicitly has higher
    priority than defining a class implicitly }
  if FScripter <> nil then
    if (AClass.FLibContext = '') or (FRegLevel = 1) then
      AClass.FLibContext := FScripter.FLibraryNameUnderRegistration;
end;

function TatClasses.ClassByName(AName: string): TatClass;
var
  i: integer;
begin
  i := IndexOf(AName);
  if i > -1 then
    Result := Items[i]
  else
    Result := nil;
end;

function TatClasses.CheckLoaded(AClass: TClass; AClassName: string = ''): TatClass;
begin
  Result := AddClassByRTTI(AClass, AClassName);
end;

function TatClasses.TestCheckLoaded(AClass: TClass; var ACurrentClass: TatClass;
  AClassName: string = ''): boolean;
var
  i: integer;
begin
  if AClassName = '' then
    AClassName := AClass.ClassName;

  { return true if class was included }
  i := IndexOf(AClassName);
  Result := ((i = -1) or not Assigned(Items[i].FClassRef));
  if Result then
    ACurrentClass := AddClassByRTTI(AClass, AClassName)
  else
    ACurrentClass := Items[i];
end;

function TatClasses.GetImplicitCount: integer;
var
  i: integer;
begin
  Result := 0;
  for i := 0 to Count - 1 do
    if Items[i].IsImplicit then
      Inc(Result);
end;

{ TatClass }

constructor TatClass.Create(ACollection: TCollection);
begin
  inherited Create(ACollection);
  FDescendants := TList.Create;
  FProperties := TatProperties.Create(self);
  FMethods := TatMethods.Create(self);
end;

destructor TatClass.Destroy;
begin
  NotifyDescendants;
  if Assigned(FAncestor) then
    FAncestor.RemoveDescendant(self);
  FDescendants.Free;
  FMethods.Free;
  FProperties.Free;
  if FImplicitClassRef <> nil then
    FImplicitClassRef.Free;
  inherited;
end;

procedure TatClass.NotifyDescendants;
Var
  c: integer;
begin
  for c := 0 to FDescendants.Count - 1 do
    TatClass(FDescendants[c]).AncestorDestroyed;
end;

procedure TatClass.AncestorDestroyed;
begin
  FAncestor := nil;
end;

procedure TatClass.Inherits(AAncestorName: string); // não deve ser chamada com ''
var
  c: integer;
  Meth: TatMethod;
  Prop: TatProperty;
begin
  { se a classe existe no RTTI e ela possui um ancestral,
    então adiciona esse ancestral automaticamente }
  if Assigned(FClassRef) and (FClassRef.ClassParent <> nil) then
    TatClasses(Collection).AddClassByRTTI(FClassRef.ClassParent);

  { se a classe tiver um ancestral já conhecido então herda dele todas
    as definições que foram introduzidas de forma não automática (sem RTTI) }
  FAncestor := TatClasses(Collection).ClassByName(AAncestorName);

  { If there is an ancestor and descendant is NOT already included in ancestor
    list of descendants }
  if Assigned(FAncestor) and (FAncestor.FDescendants.IndexOf(self) = -1) then
  begin
    FAncestor.InsertDescendant(self);
    if not Self.ClassRef.InheritsFrom(TatInternalObject) then
    begin
      { copia do ancestral, todos os métodos definidos }
      for c := 0 to FAncestor.FMethods.Count - 1 do
      begin
        Meth := TatMethod(FMethods.Add);
        Meth.Assign(FAncestor.FMethods[c]);
        SetLibContext(Meth);
      end;

      { copia do ancestral, todos as propriedades definidas
        (exceto aquelas que foram definidas automaticamente pelo RTTI) }
      for c := 0 to FAncestor.FProperties.Count - 1 do
        if not Assigned(FAncestor.FProperties[c].FPropInfo) then
        begin
          Prop := TatProperty(FProperties.Add);
          Prop.Assign(FAncestor.FProperties[c]);
          SetLibContext(Prop);
        end;
      // inherits default property definition
      if FAncestor.DefaultProperty <> nil then
        DefaultProperty := FProperties.PropertyByName(FAncestor.DefaultProperty.Name);
    end;
  end;
end;

{ user helpful methods }

// deprecated
procedure TatClass.AddObject(AName: string; AObject: TObject);
begin
  AddDelphiObjectProp(AName, AObject);
end;

// deprecated
procedure TatClass.AddConstant(AName: string; AValue: TScriptValue);
begin
  with SetProp(AName, tkVariant, nil, nil, nil) do
    SetPropExtra(GenericProc(GetScriptValuePropProc), nil, AValue);
end;

procedure TatClass.AddEnumeration(ATypeInfo: PTypeInfo);
var
  c: integer;
  typeData: PTypeData;
begin
  if Assigned(ATypeInfo) and (ATypeInfo^.Kind = TypInfo.tkEnumeration) then
  begin
    // Do not register boolean enumerated types. They are already registered (true/false)
    if (ATypeInfo <> TypeInfo(Boolean)) and (ATypeInfo <> TypeInfo(WordBool)) and
      (ATypeInfo <> TypeInfo(LongBool)) and (ATypeInfo <> TypeInfo(ByteBool)) then
    begin
      { declared enumerated values as constants in scripter }
      typeData := GetTypeData(ATypeInfo);
      for c := typeData.MinValue to typeData.MaxValue do
        AddConstant(GetEnumName(ATypeInfo, c), c);
    end;
  end
  else
    InternalError('Invalid type information on call to AddEnumeration');
end;

// deprecated -> use TatCustomScripter.AddVariable
{$IFNDEF NEXTGEN}
procedure TatClass.AddVariable(AName: string; var AVar: Variant);
begin
  try
    with SetProp(AName, tkVariant, nil, nil, nil) do
      SetPropExtra(GenericProc(GetVarVariablePropProc), GenericProc(SetVarVariablePropProc),
        PointerToVar(PVariant(@AVar)));
  except
    DefinitionError('Variable is unassigned or not a variant');
  end;
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatClass.AddVariable(AName: string; var AVar: extended);
begin
  try
    with SetProp(AName, tkVariant, nil, nil, nil) do
      SetPropExtra(GenericProc(GetExtVariablePropProc), GenericProc(SetExtVariablePropProc),
        PointerToVar(PExtended(@AVar)));
  except
    DefinitionError('Variable is unassigned or not a variant');
  end;
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatClass.AddVariable(AName: string; var AVar: double);
begin
  try
    with SetProp(AName, tkVariant, nil, nil, nil) do
      SetPropExtra(GenericProc(GetDblVariablePropProc), GenericProc(SetDblVariablePropProc),
        PointerToVar(PDouble(@AVar)));
  except
    DefinitionError('Variable is unassigned or not a variant');
  end;
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatClass.AddVariable(AName: string; var AVar: string);
begin
  try
    with SetProp(AName, tkVariant, nil, nil, nil) do
      SetPropExtra(GenericProc(GetStrVariablePropProc), GenericProc(SetStrVariablePropProc),
        PointerToVar(PString(@AVar)));
  except
    DefinitionError('Variable is unassigned or not a variant');
  end;
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatClass.AddVariable(AName: string; var AVar: Widestring);
begin
  try
    with SetProp(AName, tkVariant, nil, nil, nil) do
      SetPropExtra(GenericProc(GetWStrVariablePropProc), GenericProc(SetWStrVariablePropProc),
        PointerToVar(PWideString(@AVar)));
  except
    DefinitionError('Variable is unassigned or not a variant');
  end;
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatClass.AddVariable(AName: string; var AVar: integer);
begin
  try
    with SetProp(AName, tkVariant, nil, nil, nil) do
      SetPropExtra(GenericProc(GetIntVariablePropProc), GenericProc(SetIntVariablePropProc),
        PointerToVar(PInteger(@AVar)));
  except
    DefinitionError('Variable is unassigned or not a variant');
  end;
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatClass.AddVariable(AName: string; var AVar: boolean);
begin
  try
    with SetProp(AName, tkVariant, nil, nil, nil) do
      SetPropExtra(GenericProc(GetBoolVariablePropProc), GenericProc(SetBoolVariablePropProc),
        PointerToVar(PBoolean(@AVar)));
  except
    DefinitionError('Variable is unassigned or not a variant');
  end;
end;
{$ENDIF}

{ property creation }

function TatClass.AddProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TGenericProc;
  APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
  : TatProperty;
Var
  c: integer;
begin
  Result := TatProperty(FProperties.Add);
  with Result do
  begin
    SetLibContext(Result);
    FName := AName;
    FDataType := ADataType;
    FGetter := AGetter;
    FSetter := ASetter;
    FPropertyClass := APropertyClass;
    FIsClassProp := AIsClassProp;
    FIndexCount := AIndexCount;
    { propaga esta inclusão nas classes descendentes }
    if Assigned(Self.FClassRef) and not Self.FClassRef.InheritsFrom(TatInternalObject) then
      for c := 0 to FDescendants.Count - 1 do
        {$IFNDEF OverrideDescendants}
        if (TatClass(FDescendants[c]).PropertyByName(FName) = nil) then
          {$ENDIF}
          TatClass(FDescendants[c]).AddProp(FName, FDataType, FGetter, FSetter, FPropertyClass,
            FIsClassProp, FIndexCount);
  end;
end;

function TatClass.SetProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TGenericProc;
  APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
  : TatProperty;
var
  i: integer;
begin
  i := FProperties.IndexOf(AName);
  if i = -1 then
    Result := TatProperty(FProperties.Add)
  else
    Result := FProperties[i];
  with Result do
  begin
    SetLibContext(Result);
    FName := AName;
    FDataType := ADataType;
    FGetter := AGetter;
    FSetter := ASetter;
    FPropertyClass := APropertyClass;
    FIsClassProp := AIsClassProp;
    FIndexCount := AIndexCount;
    { propaga esta alteração nas classes descendentes }
    if Assigned(Self.FClassRef) and not Self.FClassRef.InheritsFrom(TatInternalObject) then
      for i := 0 to FDescendants.Count - 1 do
        {$IFNDEF OverrideDescendants}
        if (TatClass(FDescendants[i]).PropertyByName(FName) = nil) then
          {$ENDIF}
          TatClass(FDescendants[i]).SetProp(FName, FDataType, FGetter, FSetter, FPropertyClass,
            FIsClassProp, FIndexCount);
  end;
end;

procedure TatClass.AddIntegerProp(AName: string; AGetter, ASetter: TGenericProc;
  AIsClassProp: boolean = false);
begin
  SetProp(AName, tkInteger, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.AddStringProp(AName: string; AGetter, ASetter: TGenericProc;
  AIsClassProp: boolean = false);
begin
  SetProp(AName, tkLString, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.AddBooleanProp(AName: string; AGetter, ASetter: TGenericProc;
  AIsClassProp: boolean = false);
begin
  SetProp(AName, tkInteger, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.AddFloatProp(AName: string; AGetter, ASetter: TGenericProc;
  AIsClassProp: boolean = false);
begin
  SetProp(AName, tkFloat, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.AddVariantProp(AName: string; AGetter, ASetter: TGenericProc;
  AIsClassProp: boolean = false);
begin
  SetProp(AName, tkVariant, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.AddObjectProp(AName: string; AGetter, ASetter: TGenericProc;
  APropertyClass: TClass; AIsClassProp: boolean = false);
begin
  SetProp(AName, tkClass, AGetter, ASetter, APropertyClass, AIsClassProp);
end;

procedure TatClass.AddDelphiObjectProp(AName: string; AObject: TObject);
begin
  with SetProp(AName, tkClass, nil, nil, AObject.ClassType) do
    SetPropExtra(GenericProc(GetDelphiObjectPropProc), nil, ObjectToVar(AObject));
end;

function TatClass.DefineProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TMachineProc;
  APropertyClass: TClass = nil; AIsClassProp: boolean = false; AIndexCount: integer = 0)
  : TatProperty;
begin
  { The code below is a workaround. It avoids a problem cause by pieces of code generated by import tool.
    The import tool sometimes redefines properties with no getter or setter. So, this must be avoided }
  if (ADataType = tkVariant) and not AssignedMethod(TMethod(AGetter)) and
    not AssignedMethod(TMethod(ASetter)) and (APropertyClass = nil) then
    Result := nil
  else
    Result := SetProp(AName, ADataType, TGenericProc(AGetter), TGenericProc(ASetter),
      APropertyClass, AIsClassProp, AIndexCount);
end;

function TatClass.DefineNewProp(AName: string; ADataType: TatTypeKind;
  AGetter, ASetter: TMachineProc; APropertyClass: TClass = nil; AIsClassProp: boolean = false;
  AIndexCount: integer = 0): TatProperty;
begin
  { The code below is a workaround. It avoids a problem cause by pieces of code generated by import tool.
    The import tool sometimes redefines properties with no getter or setter. So, this must be avoided }
  if (ADataType = tkVariant) and not AssignedMethod(TMethod(AGetter)) and
    not AssignedMethod(TMethod(ASetter)) and (APropertyClass = nil) then
    Result := nil
  else
    Result := AddProp(AName, ADataType, TGenericProc(AGetter), TGenericProc(ASetter),
      APropertyClass, AIsClassProp, AIndexCount);
end;

(* Var c: integer;
  begin
  result:=TatProperty( FProperties.Add );
  with result do
  begin
  FName:=AName;
  FDataType:=ADataType;
  FGetter := TGenericProc(AGetter);
  FSetter := TGenericProc(ASetter);
  FPropertyClass:=APropertyClass;
  FIsClassProp:=AIsClassProp;
  FIndexCount:=AIndexCount;
  { propaga esta inclusão nas classes descendentes }
  for c:=0 to FDescendants.Count-1 do
  TatClass(FDescendants[c]).DefineProp(
  FName,FDataType,AGetter,ASetter,FPropertyClass,FIsClassProp,FIndexCount);
  end;
  end; *)

procedure TatClass.DefineIntegerProp(AName: string; AGetter, ASetter: TMachineProc;
  AIsClassProp: boolean = false);
begin
  DefineProp(AName, tkInteger, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.DefineStringProp(AName: string; AGetter, ASetter: TMachineProc;
  AIsClassProp: boolean = false);
begin
  DefineProp(AName, tkLString, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.DefineBooleanProp(AName: string; AGetter, ASetter: TMachineProc;
  AIsClassProp: boolean = false);
begin
  DefineProp(AName, tkInteger, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.DefineFloatProp(AName: string; AGetter, ASetter: TMachineProc;
  AIsClassProp: boolean = false);
begin
  DefineProp(AName, tkFloat, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.DefineVariantProp(AName: string; AGetter, ASetter: TMachineProc;
  AIsClassProp: boolean = false);
begin
  DefineProp(AName, tkVariant, AGetter, ASetter, nil, AIsClassProp);
end;

procedure TatClass.DefineObjectProp(AName: string; AGetter, ASetter: TMachineProc;
  APropertyClass: TClass; AIsClassProp: boolean = false);
begin
  DefineProp(AName, tkClass, AGetter, ASetter, APropertyClass, AIsClassProp);
end;

{ method creation }

function TatClass.AddProc(AName: string; ACode: pointer; AArgCount: integer;
  AResultDataType: TatTypeKind; AProc: TGenericProc; AResultClass: TClass;
  AIsClassMethod: boolean = false; ADefArgCount: integer = 0): TatMethod;
Var
  c: integer;
begin
  Result := TatMethod(FMethods.Add);
  with Result do
  begin
    SetLibContext(Result);
    FName := AName;
    FCode := ACode;
    ArgCount := AArgCount;
    FDefArgCount := ADefArgCount;
    FResultDataType := AResultDataType;
    FProc := AProc;
    FResultClass := AResultClass;
    FIsClassMethod := AIsClassMethod;
    { propaga esta inclusão nas classes descendentes }
    if Assigned(Self.FClassRef) and not Self.FClassRef.InheritsFrom(TatInternalObject) then
      for c := 0 to FDescendants.Count - 1 do
        {$IFNDEF OverrideDescendants}
        if (TatClass(FDescendants[c]).MethodByName(FName) = nil) then
          {$ENDIF}
          TatClass(FDescendants[c]).AddProc(FName, FCode, FArgCount, FResultDataType, FProc,
            FResultClass, FIsClassMethod, FDefArgCount);
  end;
end;

function TatClass.SetProc(AName: string; ACode: pointer; AArgCount: integer;
  AResultDataType: TatTypeKind; AProc: TGenericProc; AResultClass: TClass;
  AIsClassMethod: boolean = false; ADefArgCount: integer = 0; AParameterHints: string = '')
  : TatMethod;
var
  i: integer;
begin
  { if method exists, add, otherwise, replace it }
  i := FMethods.IndexOf(AName);
  if i = -1 then
    Result := TatMethod(FMethods.Add)
  else
    Result := FMethods[i];
  with Result do
  begin
    SetLibContext(Result);
    FName := AName;
    FCode := ACode;
    ArgCount := AArgCount;
    FDefArgCount := ADefArgCount;
    FResultDataType := AResultDataType;
    FProc := AProc;
    FResultClass := AResultClass;
    FIsClassMethod := AIsClassMethod;
    UpdateParameterHints(AParameterHints);
    if Assigned(Self.FClassRef) and not Self.FClassRef.InheritsFrom(TatInternalObject) then
      for i := 0 to FDescendants.Count - 1 do
        {$IFNDEF OverrideDescendants}
        if (TatClass(FDescendants[i]).MethodByName(FName) = nil) then
          {$ENDIF}
          TatClass(FDescendants[i]).SetProc(FName, FCode, FArgCount, FResultDataType, FProc,
            FResultClass, FIsClassMethod, FDefArgCount, AParameterHints);
  end;
end;

function TatClass.AddMethod(AName: string; AArgCount: integer; AResultDataType: TatTypeKind;
  AResultClass: TClass; AProc: TGenericProc; AIsClassMethod: boolean = false;
  ADefArgCount: integer = 0): TatMethod;
begin
  Result := AddProc(AName, nil, AArgCount, AResultDataType, AProc, AResultClass, AIsClassMethod,
    ADefArgCount);
end;

function TatClass.DefineNewMethod(AName: string; AArgCount: integer; AResultDataType: TatTypeKind;
  AResultClass: TClass; AProc: TMachineProc; AIsClassMethod: boolean = false;
  ADefArgCount: integer = 0): TatMethod;
begin
  Result := AddProc(AName, nil, AArgCount, AResultDataType, TGenericProc(AProc), AResultClass,
    AIsClassMethod, ADefArgCount);
end;

function TatClass.DefineMethod(AName: string; AArgCount: integer; AResultDataType: TatTypeKind;
  AResultClass: TClass; AProc: TMachineProc; AIsClassMethod: boolean = false;
  ADefArgCount: integer = 0; AParameterHints: string = ''): TatMethod;
begin
  Result := SetProc(AName, nil, AArgCount, AResultDataType, TGenericProc(AProc), AResultClass,
    AIsClassMethod, ADefArgCount, AParameterHints);
end;

(*
  function TatClass.FindGetterProcByName(AName:string;var AGetter:TGenericProc):boolean;
  var i: integer;
  begin
  i:=FProperties.IndexOf(AName);
  if i>-1 then
  begin
  AGetter := FProperties[i].Getter;
  result:=true;
  end
  else
  begin
  with FMethods do
  for i:=0 to Count-1 do
  if (Items[i].FArgCount=0) and
  (CompareText(AName,Items[i].FName)=0) then
  begin
  AGetter := Items[i].Proc;
  result:=true;
  Exit;
  end;
  result:=false;
  end;
  end;
*)

procedure TatClass.InsertDescendant(ADescendant: TatClass);
begin
  FDescendants.Add(ADescendant);
end;

function TatClass.IsDefaultInstance: boolean;
var
  c: integer;
begin
  Result := false;
  if Scripter <> nil then
    for c := 0 to Scripter.DefaultInstances.Count - 1 do
      if Scripter.DefaultInstances[c].atClass = Self then
      begin
        Result := True;
        exit;
      end;
end;

procedure TatClass.RemoveDescendant(ADescendant: TatClass);
begin
  FDescendants.Remove(ADescendant);
end;

procedure TatClass.SetMethods(const Value: TatMethods);
begin
  FMethods.Assign(Value);
end;

procedure TatClass.SetProperties(const Value: TatProperties);
begin
  FProperties.Assign(Value);
end;

function TatClass.ClassMethodByName(AName: string): TatMethod;
begin
  Result := Methods.ClassMethodByName(AName);
end;

function TatClass.ClassPropertyByName(AName: string): TatProperty;
begin
  Result := Properties.ClassPropertyByName(AName);
end;

function TatClass.MethodByName(AName: string): TatMethod;
begin
  Result := Methods.MethodByName(AName);
end;

function TatClass.PropertyByName(AName: string): TatProperty;
begin
  Result := Properties.PropertyByName(AName);
end;

function TatClass.CastFromString(AClassName: string): TatClass;
begin
  { força esta classe ser correspondente ou derivada da classe
    indicada em AClassName, gerando uma exceção caso não seja.
    Retorna uma referência para a classe coergida }
  Result := self;
  while Assigned(Result) do
  begin
    if SameText(Result.Name, AClassName) then
      exit;
    Result := Result.Ancestor;
  end;
end;

procedure TatClass.RemoveProperty(AName: string);
var
  AProp: TatProperty;
begin
  AProp := PropertyByName(AName);
  if AProp <> nil then
    AProp.Free;
end;

function TatClass.GetIsImplicit: boolean;
begin
  Result := FImplicitClassRef <> nil;
end;

function TatClass.Scripter: TatCustomScripter;
begin
  if (Collection is TatClasses) then
    Result := TatClasses(Collection).FScripter
  else
    Result := nil;
end;

procedure TatClass.SetImplicitElement(const Value: TCollectionItem);
var
  prop: TatProperty;
  meth: TatMethod;
begin
  Assert((Value = nil) or (Value is TatMethod) or (Value is TatProperty));
  if FImplicitClassRef <> nil then
    FImplicitClassRef.Free;
  FImplicitClassRef := TatClassRef.Create(nil);
  if Value is TatProperty then
  begin
    prop := TatProperty(Value);
    FImplicitClassRef.FClassIndex := self.Index;
    FImplicitClassRef.FElementIndex := prop.Index;
    FImplicitClassRef.FElementIsMethod := false;
    FImplicitClassRef.FClassName := self.Name;
    FImplicitClassRef.FElementName := prop.Name;
    FImplicitClassRef.FElementClassIndex := prop.atClass.Index;
    FImplicitClassRef.FElementClassName := prop.atClass.Name;
  end
  else
  begin
    meth := TatMethod(Value);
    FImplicitClassRef.FClassIndex := self.Index;
    FImplicitClassRef.FElementIndex := meth.Index;
    FImplicitClassRef.FElementIsMethod := True;
    FImplicitClassRef.FClassName := self.Name;
    FImplicitClassRef.FElementName := meth.Name;
    FImplicitClassRef.FElementClassIndex := meth.atClass.Index;
    FImplicitClassRef.FElementClassName := meth.atClass.Name;
  end;
end;

procedure TatClass.SetLibContext(Meth: TatMethod);
begin
  if Scripter <> nil then
    if Meth.FLibContext = '' then
      Meth.FLibContext := Scripter.FLibraryNameUnderRegistration;
end;

procedure TatClass.SetLibContext(Prop: TatProperty);
begin
  if Scripter <> nil then
    if Prop.FLibContext = '' then
      Prop.FLibContext := Scripter.FLibraryNameUnderRegistration;
end;

{ TatProperties }

function TatProperties.GetItem(i: integer): TatProperty;
begin
  Result := TatProperty(inherited Items[i]);
end;

constructor TatProperties.Create(AClass: TatClass);
begin
  FClass := AClass;
  inherited Create(TatProperty);
end;

function TatProperties.AddByRTTI(APropInfo: PPropInfo): TatProperty;
begin
  Result := TatProperty(inherited Add);
  with Result do
  begin
    atClass.SetLibContext(Result);
    FName := PropInfoName(APropInfo);
    FDataType := MapTatTypeKind(APropInfo^.PropType^^.Kind);
    if Assigned(APropInfo^.GetProc) then
      FGetter := GenericProc(RTTIGetterProc);
    if Assigned(APropInfo^.SetProc) then
      FSetter := GenericProc(RTTISetterProc);
    FPropInfo := APropInfo;
    if APropInfo^.PropType^^.Kind = TypInfo.tkClass then
      FPropertyClass := GetTypeData(FPropInfo^.PropType^)^.ClassType
    else
      FPropertyClass := nil;
  end;
end;

function TatProperties.IndexOf(AName: string): integer;
begin
  for Result := Count - 1 downto 0 do
    if CompareText(AName, Items[Result].FName) = 0 then
      exit;
  Result := -1;
end;

function TatProperties.PropertyByName(AName: string): TatProperty;
var
  i: integer;
begin
  i := IndexOf(AName);
  if i > -1 then
    Result := Items[i]
  else
    Result := nil;
end;

function TatProperties.ClassPropertyByName(AName: string): TatProperty;
var
  i: integer;
begin
  for i := Count - 1 downto 0 do
    if Items[i].IsClassProp and (CompareText(AName, Items[i].FName) = 0) then
    begin
      Result := Items[i];
      exit;
    end;
  Result := nil;
end;

{ TatProperty }

constructor TatProperty.Create(ACollection: TCollection);
begin
  inherited Create(ACollection);
  FScripter := TatClasses(TatProperties(Collection).FClass.Collection).FScripter;
end;

procedure TatProperty.Assign(Source: TPersistent);
begin
  Name := TatProperty(Source).Name;
  DataType := TatProperty(Source).DataType;
  Getter := TatProperty(Source).Getter;
  Setter := TatProperty(Source).Setter;
  PropertyClass := TatProperty(Source).PropertyClass;
  PropInfo := TatProperty(Source).PropInfo;
  Value := TatProperty(Source).Value;
  IsClassProp := TatProperty(Source).IsClassProp;
  IndexCount := TatProperty(Source).IndexCount;
  { ajusta a instância do Getter e do Setter se ela for a propriedade de origem }
  if TMethod(TatProperty(Source).FGetter).Data = Source then
    TMethod(FGetter).Data := self;
  if TMethod(TatProperty(Source).FSetter).Data = Source then
    TMethod(FSetter).Data := self;

  if TMethod(TatProperty(Source).FGetter).Data = TatProperty(Source).Scripter then
    TMethod(FGetter).Data := Self.Scripter;
  if TMethod(TatProperty(Source).FSetter).Data = TatProperty(Source).Scripter then
    TMethod(FSetter).Data := Self.Scripter;
  (*
    { garante que se o Getter ou o Setter referenciar um UserProc, este corresponderá ao Scripter corrente }
    if Scripter<>TatProperty(Source).Scripter then
    begin
    if TObject(TMethod(TatProperty(Source).FGetter).Data) is TatProcCollectionItem then
    with TatProcCollectionItem(TMethod(TatProperty(Source).FGetter).Data) do
    self.Getter := self.Scripter.UserProc( UserProc ); // duplica o UserProc alterando apenas a propriedade Scripter
    if TObject(TMethod(TatProperty(Source).FSetter).Data) is TatProcCollectionItem then
    with TatProcCollectionItem(TMethod(TatProperty(Source).FSetter).Data) do
    self.Setter := self.Scripter.UserProc( UserProc ); // duplica o UserProc alterando apenas a propriedade Scripter
    end;
  *)
end;

procedure TatProperty.RTTIGetterProc(AMachine: TatVirtualMachine);
var
  v: TScriptValue;
  {$IFDEF NEWSTACK}
  C: TRttiContext;
  RttiType: TRttiType;
  {$ENDIF}
begin
  with AMachine do
  begin
    case FDataType of
      // common behavior for both newstack and oldstack
      tkMethod:
        if Assigned(FScripter.FOnTranslateMethodGetter) then
        begin
          v := NullValue;
          { generic event translation from TMethod to a Variant type }
          FScripter.FOnTranslateMethodGetter(AMachine, CurrentObject, FPropInfo, v);
          ReturnOutputArg(v);
        end
        else
          ReturnOutputArg(NullValue);
    else
      // specific code for newstack and oldstack
      {$IFDEF NEWSTACK}
      C := TRttiContext.Create;
      try
        RttiType := C.GetType(FPropInfo^.PropType);
        if RttiType <> nil then
          ReturnOutputArg(RttiType.GetProperty(GetPropName(FPropInfo)).GetValue(CurrentObject));
      finally
        C.Free;
      end;
      {$ELSE}
      case FDataType of
        tkEnumeration:
          if GetTypeData(FPropInfo.PropType^)^.BaseType^ = TypeInfo(boolean) then
            ReturnOutputArg(GetOrdProp(CurrentObject, FPropInfo) <> 0)
          else
            ReturnOutputArg(GetOrdProp(CurrentObject, FPropInfo));
        tkInteger, tkChar, tkSet, tkWChar, tkClass:
          ReturnOutputArg(GetOrdProp(CurrentObject, FPropInfo));
        tkString, tkLString:
          ReturnOutputArg(GetStrProp(CurrentObject, FPropInfo));
        {$IFNDEF NEXTGEN}
        tkWString:
          {$IFDEF DELPHI7_LVL}
          ReturnOutputArg(GetWideStrProp(CurrentObject, FPropInfo));
          {$ELSE}
          ReturnOutputArg(GetStrProp(CurrentObject, FPropInfo));
        {$ENDIF}
        {$ENDIF}
        {$IFDEF DELPHI2009_LVL}
        tkUString:
          {$IFDEF NEXTGEN}
          ReturnOutputArg(GetStrProp(CurrentObject, FPropInfo));
          {$ELSE}
          ReturnOutputArg(GetUnicodeStrProp(CurrentObject, FPropInfo));
          {$ENDIF}
        {$ENDIF}
        tkFloat:
          ReturnOutputArg(GetFloatProp(CurrentObject, FPropInfo));
        tkVariant:
          ReturnOutputArg(GetVariantProp(CurrentObject, FPropInfo));
      else
        ReturnOutputArg(null);
      end;
      {$ENDIF}
    end;
  end;
end;

procedure TatProperty.RTTISetterProc(AMachine: TatVirtualMachine);
{$IFDEF NEWSTACK}
var
  C: TRttiContext;
  RttiType: TRttiType;
{$ENDIF}
begin
  with AMachine do
  begin
    case FDataType of
      // common behavior for both newstack and oldstack
      tkMethod:
        if Assigned(FScripter.FOnTranslateMethodSetter) then
          { generic event translation from Variant to a TMethod type }
          FScripter.FOnTranslateMethodSetter(AMachine, CurrentObject, FPropInfo, GetInputArg(0));
    else
      {$IFDEF NEWSTACK}
      C := TRttiContext.Create;
      try
        RttiType := C.GetType(FPropInfo^.PropType);
        if RttiType <> nil then
          RttiType.GetProperty(GetPropName(FPropInfo)).SetValue(CurrentObject, GetInputArg(0));
      finally
        C.Free;
      end;
      {$ELSE}
      case FDataType of
        tkInteger, tkChar, tkWChar:
          SetOrdProp(CurrentObject, FPropInfo, GetInputArgAsInteger(0));
        tkClass:
          SetOrdProp(CurrentObject, FPropInfo, IntObject(GetInputArgAsObject(0)));
        tkSet:
          SetOrdProp(CurrentObject, FPropInfo, VarToSet(GetInputArg(0), FPropInfo.PropType^));
        tkEnumeration:
          SetOrdProp(CurrentObject, FPropInfo, VarToEnumInteger(GetInputArg(0), FPropInfo.PropType^));
        tkString, tkLString:
          SetStrProp(CurrentObject, FPropInfo, GetInputArgAsString(0));
        {$IFNDEF NEXTGEN}
        tkWString:
          {$IFDEF DELPHI7_LVL}
          SetWideStrProp(CurrentObject, FPropInfo, GetInputArgAsWideString(0));
          {$ELSE}
          SetStrProp(CurrentObject, FPropInfo, GetInputArgAsWideString(0));
          {$ENDIF}
        {$ENDIF}
        {$IFDEF DELPHI2009_LVL}
        tkUString:
          {$IFDEF NEXTGEN}
          SetStrProp(CurrentObject, FPropInfo, GetInputArgAsString(0));
          {$ELSE}
          SetUnicodeStrProp(CurrentObject, FPropInfo, GetInputArgAsString(0));
          {$ENDIF}
        {$ENDIF}
        tkFloat:
          SetFloatProp(CurrentObject, FPropInfo, GetInputArgAsFloat(0));
        tkVariant:
          SetVariantProp(CurrentObject, FPropInfo, GetInputArg(0));
      end;
      {$ENDIF}
    end;
  end;
end;

function TatProperty.UpdateObjectInfo(var ACurrentClass: TatClass): boolean;
begin
  Result := false;
  { se a propriedade referir-se a uma classe então carrega as informações
    desta classe, se ela ainda não havia sido carregada }
  case FDataType of
    tkClass:
      if Assigned(FPropertyClass) then
        if FScripter.FDeferObjectResolution then
          { A resolução do acesso à classe deverá ocorrer efetivamente em runtime }
          ACurrentClass := UndefinedClass // undefined variable instance
        else
          { Carrega as informções da classe referenciada }
          if TatClasses(TatProperties(Collection).FClass.Collection).TestCheckLoaded(FPropertyClass,
            ACurrentClass, FPropertyClassName) then
            Result := True
          else
        else
        begin
          // FatalError(Format('Result class for method ''%s'' not defined',[FName]))
          { class resolution should be procrastinated (runtime resolution) }
          ACurrentClass := UndefinedClass // undefined variable instance
        end;
    tkVariant:
      ACurrentClass := UndefinedClass // undefined variable instance
  else
    ACurrentClass := nil;
  end;
end;

procedure TatProperty.GetDelphiObjectPropProc(AMachine: TatVirtualMachine);
begin
  {$IFDEF NEWSTACK}
  AMachine.ReturnOutputArg(FValue);
  {$ELSE}
  AMachine.ReturnOutputArg(VarToIntObject(FValue));
  {$ENDIF}
end;

procedure TatProperty.GetScriptValuePropProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(FValue);
end;

{$IFNDEF NEXTGEN}
procedure TatProperty.GetVarVariablePropProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(PVariant(VarToPointer(FValue))^);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.SetVarVariablePropProc(AMachine: TatVirtualMachine);
begin
  PVariant(VarToPointer(FValue))^ := AMachine.GetInputArg(0);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.GetIntVariablePropProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(PInteger(VarToPointer(FValue))^);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.SetIntVariablePropProc(AMachine: TatVirtualMachine);
begin
  PInteger(VarToPointer(FValue))^ := AMachine.GetInputArg(0);
end;
{$ENDIF}

procedure TatProperty.SetPropExtra(AGetter, ASetter: TGenericProc; AValue: TScriptValue);
var
  AClass: TatClass;
  i: integer;
  ADescProp: TatProperty;
begin
  AClass := self.atClass;
  FGetter := AGetter;
  FSetter := ASetter;
  FValue := AValue;
  if AClass <> nil then
    for i := 0 to AClass.FDescendants.Count - 1 do
    begin
      ADescProp := TatClass(AClass.FDescendants[i]).PropertyByName(FName);
      if ADescProp <> nil then
        ADescProp.SetPropExtra(AGetter, ASetter, AValue);
    end;
end;

{$IFNDEF NEXTGEN}
procedure TatProperty.GetStrVariablePropProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(PString(VarToPointer(FValue))^);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.SetStrVariablePropProc(AMachine: TatVirtualMachine);
begin
  PString(VarToPointer(FValue))^ := AMachine.GetInputArg(0);
end;
{$ENDIF}

function TatProperty.GetWriteable: boolean;
begin
  Result := Assigned(FSetter);
end;

{$IFNDEF NEXTGEN}
procedure TatProperty.GetWStrVariablePropProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(PWideString(VarToPointer(FValue))^);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.SetWStrVariablePropProc(AMachine: TatVirtualMachine);
begin
  PWideString(VarToPointer(FValue))^ := AMachine.GetInputArg(0);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.GetBoolVariablePropProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(PBoolean(VarToPointer(FValue))^);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.SetBoolVariablePropProc(AMachine: TatVirtualMachine);
begin
  PBoolean(VarToPointer(FValue))^ := AMachine.GetInputArg(0);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.GetDblVariablePropProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(PDouble(VarToPointer(FValue))^);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.SetDblVariablePropProc(AMachine: TatVirtualMachine);
begin
  PDouble(VarToPointer(FValue))^ := AMachine.GetInputArg(0);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.GetExtVariablePropProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(PExtended(VarToPointer(FValue))^);
end;
{$ENDIF}

{$IFNDEF NEXTGEN}
procedure TatProperty.SetExtVariablePropProc(AMachine: TatVirtualMachine);
begin
  PExtended(VarToPointer(FValue))^ := AMachine.GetInputArg(0);
end;
{$ENDIF}

function TatProperty.atClass: TatClass;
begin
  Result := TatProperties(Collection).FClass;
end;

procedure TatProperty.GetFormComponentProc(AMachine: TatVirtualMachine);
begin
  With AMachine do
    if CurrentObject is TComponent then
      ReturnOutputArg(ObjectToVar(TComponent(CurrentObject).FindComponent(CurrentPropertyName)))
    else
      ReturnOutputArg(0);
end;

function TatProperty.GetDisplayName: string;
begin
  Result := Name;
end;

{ TatMethods }

function TatMethods.GetItem(i: integer): TatMethod;
begin
  Result := TatMethod(inherited Items[i]);
end;

constructor TatMethods.Create(AClass: TatClass);
begin
  FClass := AClass;
  inherited Create(TatMethod);
end;

function TatMethods.IndexOf(AName: string): integer;
begin
  for Result := Count - 1 downto 0 do
    if CompareText(AName, Items[Result].FName) = 0 then
      exit;
  Result := -1;
end;

function TatMethods.MethodByName(AName: string): TatMethod;
var
  i: integer;
begin
  i := IndexOf(AName);
  if i > -1 then
    Result := Items[i]
  else
    Result := nil;
end;

function TatMethods.ClassMethodByName(AName: string): TatMethod;
var
  i: integer;
begin
  for i := Count - 1 downto 0 do
    if Items[i].IsClassMethod and (CompareText(AName, Items[i].FName) = 0) then
    begin
      Result := Items[i];
      exit;
    end;
  Result := nil;
end;

{ TatMethod }

constructor TatMethod.Create(ACollection: TCollection);
begin
  inherited Create(ACollection);
  FArgDefs := TatDataDefs.Create(TatMethods(Collection).FClass);
  FScripter := TatClasses(TatProperties(Collection).FClass.Collection).FScripter;
end;

destructor TatMethod.Destroy;
begin
  FArgDefs.Free;
  inherited;
end;

procedure TatMethod.AdjustArgDefsCount;
begin
  while FArgDefs.Count < FArgCount do
    TCollection(FArgDefs).Add;
  while FArgDefs.Count > FArgCount do
    FArgDefs[FArgDefs.Count - 1].Free;
end;

procedure TatMethod.Assign(Source: TPersistent);
begin
  Name := TatMethod(Source).Name;
  Proc := TatMethod(Source).Proc;
  ResultDataType := TatMethod(Source).ResultDataType;
  ArgCount := TatMethod(Source).ArgCount;
  DefArgCount := TatMethod(Source).DefArgCount;
  Code := TatMethod(Source).Code;
  ResultClass := TatMethod(Source).ResultClass;
  ArgDefs := TatMethod(Source).ArgDefs;
  IsClassMethod := TatMethod(Source).IsClassMethod;
  ByRefArgMask := TatMethod(Source).ByRefArgMask;
  { ajusta a instância do Proc se ela for o método de origem }
  if TMethod(TatMethod(Source).FProc).Data = TatMethod(Source).Scripter then
    TMethod(FProc).Data := self.Scripter
  else
  if TMethod(TatMethod(Source).FProc).Data = Source then
    TMethod(FProc).Data := self
  else
    (*
      { garante que se o Proc referenciar um UserProc, este corresponderá ao Scripter corrente }
      if (Scripter<>TatMethod(Source).Scripter) and
      (TObject(TMethod(TatMethod(Source).FProc).Data) is TatProcCollectionItem) then
      with TatProcCollectionItem(TMethod(TatMethod(Source).FProc).Data) do
      self.Proc:=self.Scripter.UserProc( UserProc ); // duplica o UserProc alterando apenas a propriedade Scripter
    *)
end;

function TatMethod.UpdateObjectInfo(var ACurrentClass: TatClass): boolean;
begin
  Result := false;
  { se o método retornar uma classe então carrega as informações
    desta classe, se ela ainda não havia sido carregada }
  Case FResultDataType of
    tkClass:
      if Assigned(FResultClass) then
        if FScripter.FDeferObjectResolution then
          { A resolução do acesso à classe deverá ocorrer efetivamente em runtime }
          ACurrentClass := UndefinedClass // undefined variable instance
        else
          { Carrega as informações da classe referenciada }
          if TatClasses(TatMethods(Collection).FClass.Collection).TestCheckLoaded(FResultClass,
            ACurrentClass, FResultClassName) then
            Result := True
          else
        else
        begin
          // FatalError(Format('Result class for method ''%s'' not defined',[FName]))
          { class resolution should be procrastinated (runtime resolution) }
          ACurrentClass := UndefinedClass // undefined variable instance
        end;
    tkVariant:
      ACurrentClass := UndefinedClass; // undefined variable instance
  else
    ACurrentClass := nil;
  end;
end;

procedure TatMethod.UpdateParameterHints(const AParameterHints: string);
var
  idx: integer;
  pstr: string;
  p: integer;
  Str: string;
  defValue: string;
  paramName: string;
  ParamType: string;
begin
  idx := 0;
  Str := Trim(AParameterHints);
  while (Str <> '') and (idx < ArgDefs.Count) do
  begin
    // Get next parameter (delimited by ";")
    p := pos(';', Str);
    if p > 0 then
    begin
      pstr := Copy(Str, 1, p - 1);
      System.Delete(Str, 1, p);
    end
    else
    begin
      pstr := Str;
      Str := '';
    end;

    // Get default value
    defValue := '';
    p := pos('=', pstr);
    if p > 0 then
    begin
      defValue := Trim(Copy(pstr, p + 1, MaxInt));
      System.Delete(pstr, p, MaxInt);
    end;

    // Get param type
    ParamType := '';
    p := pos(':', pstr);
    if p > 0 then
    begin
      ParamType := Trim(Copy(pstr, p + 1, MaxInt));
      System.Delete(pstr, p, MaxInt);
    end;

    // now param name is what's remaining in string
    paramName := Trim(pstr);

    // Set ArgDefs
    ArgDefs[idx].FName := paramName;
    ArgDefs[idx].FDataTypeName := ParamType;
    ArgDefs[idx].FDefaultValueText := defValue;

    Inc(idx);
  end;
end;

procedure TatMethod.SetVarArgs(argi: array of byte);
var
  ScriptClass: TatClass;
  meth: TatMethod;
  c: integer;
begin
  { adjust FArgDefs.Count to FArgCount }
  AdjustArgDefsCount;

  { sets the TArgumentDef.Modifier property and the ByRefArgMask }
  FByRefArgMask := 0;
  for c := 0 to High(argi) do
  begin
    FArgDefs[argi[c]].FModifier := moVar;
    FByRefArgMask := FByRefArgMask or (1 shl argi[c]);
  end;

  ScriptClass := self.atClass;
  if ScriptClass <> nil then
    for c := 0 to ScriptClass.FDescendants.Count - 1 do
    begin
      meth := TatClass(ScriptClass.FDescendants[c]).MethodByName(FName);
      if (meth <> nil) and (meth.ArgCount = self.ArgCount) then
        meth.SetVarArgs(argi);
    end;
end;

function TatMethod.IsByRefArg(n: byte): boolean;
begin
  Result := (n < FArgDefs.Count) and (FArgDefs[n].Modifier = moVar);
end;

procedure TatMethod.SetArgCount(const Value: integer);
begin
  FArgCount := Value;
  AdjustArgDefsCount;
end;

procedure TatMethod.SetArgDefs(const Value: TatDataDefs);
begin
  FArgDefs.Assign(Value);
end;

function TatMethod.atClass: TatClass;
begin
  Result := TatMethods(Collection).FClass;
end;

function TatMethod.GetDisplayName: string;
begin
  Result := Name;
end;

{ TatDataDefs }

function TatDataDefs.GetItem(i: integer): TatDataDef;
begin
  Result := TatDataDef(inherited Items[i]);
end;

constructor TatDataDefs.Create(AClass: TatClass);
begin
  inherited Create(TatDataDef);
end;

function TatDataDefs.Add(AName: string; ADataType: TatTypeKind; AModifier: TatArgumentModifier)
  : TatDataDef;
begin
  Result := TatDataDef(inherited Add);
  with Result do
  begin
    FName := AName;
    FDataType := ADataType;
    FModifier := AModifier;
  end;
end;

{ TatDataDef }

{ TatObjects }

constructor TatObjects.Create(AClasses: TatClasses);
begin
  inherited Create(TatObject);
  FClasses := AClasses;
  Clear;
end;

function TatObjects.IndexOf(AName: string): integer;
begin
  for Result := 0 to Count - 1 do
    if CompareText(Items[Result].FName, AName) = 0 then
      exit;
  Result := -1;
end;

function TatObjects.GetItem(i: integer): TatObject;
begin
  Result := TatObject(inherited Items[i]);
end;

function TatObjects.Add(AInstance: TObject; AName: string = ''; AClassName: string = ''): TatObject;
var
  i: integer;
begin
  if not Assigned(AInstance) then
    DefinitionError('Invalid atPascal default instance');

  { if AName was not specified then assume a default name }
  if AName = '' then
    if AInstance is TatScripterLibrary then
      AName := TatScripterLibrary(AInstance).LibraryName
    else
      AName := AInstance.ClassName;

  { duplication of instances is not allowed }
  i := IndexOf(AName);
  if i = -1 then
  begin
    Result := TatObject(inherited Add);
    with Result do
    begin
      FInstance := AInstance;
      FatClass := FClasses.CheckLoaded(AInstance.ClassType, AClassName);
      FName := AName;
    end;
  end
  else
    Result := Items[i];
  // else
  // DefinitionError(Format('Default instance ''%s'' already exists',[AInstance.ClassName]));
end;

function TatObjects.FindInstanceByMethodName(AMethodName: string; var AMethod: TatMethod): integer;
begin
  for Result := Count - 1 downto 0 do
  begin
    AMethod := Items[Result].atClass.Methods.MethodByName(AMethodName);
    if Assigned(AMethod) then
      exit;
  end;
  AMethod := nil;
  Result := -1;
end;

function TatObjects.FindInstanceByPropertyName(APropertyName: string;
  var AProperty: TatProperty): integer;
begin
  for Result := Count - 1 downto 0 do
  begin
    AProperty := Items[Result].atClass.Properties.PropertyByName(APropertyName);
    if Assigned(AProperty) then
      exit;
  end;
  AProperty := nil;
  Result := -1;
end;

function TatObjects.FindInstanceByClassName(AClassName: string): TatObject;
var
  c: integer;
begin
  Result := nil;
  for c := Count - 1 downto 0 do
  begin
    if SameText(Items[c].atClass.Name, AClassName) then
    begin
      Result := Items[c];
      Break;
    end;
  end;
end;

{ TatScriptInfo }

constructor TatScriptInfo.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FRoutines := TatRoutinesInfo.Create(self, TatRoutineInfo);
  FRoutines.FScriptInfo := self;
  { coleção de variáveis globais do script }
  FGlobals := TatVariablesInfo.Create(self, TatVariableInfo);
end;

destructor TatScriptInfo.Destroy;
begin
  FGlobals.Free;
  FRoutines.Free;
end;

procedure TatScriptInfo.UpdateRoutineInfoPointers;
var
  Inst: pSimplifiedCode;
  i: integer;
  routine: TatRoutineInfo;
begin
  { load some debug info from compiled code }
  Inst := FScript.FirstInstruction;
  FCodeSize := 0;
  while Inst <> nil do
  begin
    with Inst^ do
    begin
      case OpCode of
        inPrepare:
          begin
            { create or update routine with its name and entry point }
            i := FRoutines.IndexOf(vString);
            if i > -1 then
              routine := FRoutines[i]
            else
              routine := TatRoutineInfo(FRoutines.Add);
            with routine do
            begin
              FName := vString;
              FDeclarationInstruction := Inst;
            end;
          end;
      end;
    end;
    Inst := Inst^.Next;
    Inc(FCodeSize);
  end;
end;

procedure TatScriptInfo.Clear;
begin
  FRoutines.Clear;
  FGlobals.Clear;
  FFormResource := '';
  FScriptClassName := '';
  FBehavior := sbNormal;
  FUnitName := '';
end;

function TatScriptInfo.RoutineByName(AName: string): TatRoutineInfo;
var
  i: integer;
begin
  i := Routines.IndexOf(AName);
  if i > -1 then
    Result := Routines[i]
  else
    Result := nil;
end;

function TatScriptInfo.DeclareRoutine(AName: string; ADeclInst: pSimplifiedCode;
  AIsFunction: boolean): TatRoutineInfo;
begin
  Result := TatRoutineInfo(TCollection(FRoutines).Add);
  with Result do
  begin
    FName := AName;
    FDeclarationInstruction := ADeclInst;
    FIsFunction := AIsFunction;
  end;
end;

procedure TatScriptInfo.SetGlobals(const Value: TatVariablesInfo);
begin
  FGlobals.Assign(Value);
end;

procedure TatScriptInfo.SetRoutines(const Value: TatRoutinesInfo);
begin
  FRoutines.Assign(Value);
end;

function TatScriptInfo.GetIsClass: boolean;
begin
  Result := FBehavior = sbClass;
end;

function TatScriptInfo.GetIsForm: boolean;
begin
  Result := FBehavior = sbForm;
end;

function TatScriptInfo.GetMainRoutineName: string;
begin
  if MainRoutine <> nil then
    Result := MainRoutine.Name
  else
    Result := '';
end;

procedure TatScriptInfo.SetMainRoutineName(const Value: string);
begin
  MainRoutine := RoutineByName(Value);
end;

{ TatRoutinesInfo }

function TatRoutinesInfo.GetItem(i: integer): TatRoutineInfo;
begin
  Result := TatRoutineInfo(inherited Items[i]);
end;

procedure TatRoutinesInfo.GetNames(AStrings: TStrings);
var
  c: integer;
begin
  AStrings.Clear;
  for c := 0 to Count - 1 do
    AStrings.Add(Items[c].Name);
end;

function TatRoutinesInfo.IndexOf(AName: string): integer;
begin
  for Result := 0 to Count - 1 do
    if CompareText(Items[Result].FName, AName) = 0 then
      exit;
  Result := -1;
end;

{ TatRoutineInfo }

constructor TatRoutineInfo.Create(ACollection: TCollection);
begin
  inherited Create(ACollection);
  FVariables := TatVariablesInfo.Create(self, TatVariableInfo);
end;

destructor TatRoutineInfo.Destroy;
begin
  FVariables.Free;
  inherited;
end;

function TatRoutineInfo.VariableByName(AName: string): TatVariableInfo;
var
  i: integer;
begin
  i := FVariables.IndexOf(AName);
  if i > -1 then
    Result := FVariables[i]
  else
    Result := nil;
end;

function TatRoutineInfo.LocalVarCount: integer;
begin
  Result := FVariables.Count - FArgCount;
end;

function TatRoutineInfo.ScriptInfo: TatScriptInfo;
begin
  if Collection is TatRoutinesInfo then
    Result := TatScriptInfo(TatRoutinesInfo(Collection).GetOwner)
  else
    Result := nil;
end;

function TatRoutineInfo.DeclareVariable(AName: string; ASourcePos: integer; AArgIndex: integer = -1;
  AModifier: TatArgumentModifier = moNone): TatVariableInfo;
begin
  Result := FVariables.Add;
  with Result do
  begin
    FVarName := AName;
    FDeclarationSourcePos := ASourcePos;
    FArgIndex := AArgIndex;
    FModifier := AModifier;
  end;
  if AArgIndex > -1 then
    Inc(FArgCount);
  { ajusta a máscara de parâmetros que devem ser passados por referência }
  if AModifier = moVar then
    FByRefArgMask := FByRefArgMask or (1 shl AArgIndex);
end;

procedure TatRoutineInfo.Assign(ASource: TPersistent);
begin
  FVariables.Assign(TatRoutineInfo(ASource).FVariables);
  FName := TatRoutineInfo(ASource).FName;
  FDeclarationInstruction := TatRoutineInfo(ASource).FDeclarationInstruction;
  FIsFunction := TatRoutineInfo(ASource).FIsFunction;
  ArgCount := TatRoutineInfo(ASource).FArgCount;
  FByRefArgMask := TatRoutineInfo(ASource).FByRefArgMask;
  FResultIndex := TatRoutineInfo(ASource).FResultIndex;

  FCallingConvention := TatRoutineInfo(ASource).FCallingConvention;
  FExternalDll := TatRoutineInfo(ASource).FExternalDll;
  FExternalName := TatRoutineInfo(ASource).FExternalName;
  FResultTypeDecl := TatRoutineInfo(ASource).FResultTypeDecl;
  FResultClass := TatRoutineInfo(ASource).FResultClass;
end;

procedure TatRoutineInfo.SetVariables(const Value: TatVariablesInfo);
begin
  FVariables.Assign(Value);
end;

procedure TatRoutineInfo.PrepareExternalClass;
{$IFNDEF MSWINDOWS}
begin
  ScriptInfo.FScript.CompileError('Dll calls not allowed in this platform.',
    ScriptInfo.FScript.FParser.ScanningInputPos);
end;
{$ELSE}
var
  lib: TatDLL;
  met: TatMethod;
  c: integer;
  dllMethodName: string;
begin
  lib := ScriptInfo.FScript.FScripter.LoadLibrary('_DLL_', True) as TatDLL;
  lib.FScript := ScriptInfo.FScript; // forces library destruction when script is destroyed
  lib.FScript.FLoadedDLL := True; // flags that are linked libraries in script
  lib.FFileName := FExternalDll;
  with ScriptInfo.FScript.UsedUnits.Add do
  begin
    UnitName := '_DLL_';
    IsDefault := True;
    IsScript := false;
    DeclSourcePos := -1;
  end;
  { load dll methods }
  with lib.FatClass do
  begin
    { to register the method, remove the @ in front of routine name, if it exists. It might exist when loading the compiled code
      from stream, for example }
    dllMethodName := self.Name;
    if (Length(dllMethodName) > 0) and (dllMethodName[1] = '@') then
      dllMethodName := Copy(dllMethodName, 2, 999);
    { methods }
    if IsFunction then
      met := DefineMethod(dllMethodName, Variables.Count - 1, ResultTypeKind, ResultClassRef,
        DispatchDllCall)
    else
      met := DefineMethod(dllMethodName, Variables.Count, tkNone, nil, DispatchDllCall);
    { arguments by reference }
    if FByRefArgMask > 0 then
    begin
      for c := 0 to Variables.Count - 1 do
        if Variables[c].Modifier = moVar then
          met.SetVarArgs([c]);
    end;
  end;
end;
{$ENDIF}

function TatRoutineInfo.ResultClass: TatClass;
begin
  { retorna a classe correspondente ao ResultTypeDecl }
  Result := FResultClass;
end;

{$IFDEF MSWINDOWS}
function TatRoutineInfo.ResultTypeKind: TatTypeKind;
begin
  { retorna o tipo correspondente ao ResultTypeDecl }
  Result := tkVariant;
end;
{$ENDIF}

{$IFDEF MSWINDOWS}
procedure TatRoutineInfo.DispatchDllCall(AMachine: TatVirtualMachine);
var
  args, argtypes: openarray;
  rettype, VType: integer;
  Result: Variant;
  c, ArgCount: integer;
  astr: array of AnsiString;
  {$IFDEF DELPHI2009_LVL}
  ustr: array of UnicodeString;
  {$ENDIF}
begin
  if Assigned(ScriptInfo.FScript.FScripter) and ScriptInfo.FScript.FScripter.AllowDLLCalls then
    with AMachine do
    begin
      { converts scripter input arguments to an array of const }
      if IsFunction then
      begin
        ArgCount := Variables.Count - 1;
        rettype := Variables[Variables.Count - 1].SystemType;
      end
      else
      begin
        ArgCount := Variables.Count;
        rettype := vtInteger; // dummy
      end;
      SetLength(args, ArgCount);
      SetLength(argtypes, ArgCount);
      SetLength(astr, ArgCount);
      {$IFDEF DELPHI2009_LVL}
      SetLength(ustr, ArgCount);
      {$ENDIF}
      try
        for c := 0 to ArgCount - 1 do
        begin
          { creates a TVarRec from the variant that is in the scripter runtime stack, but respects the type declared in the parameter }
          VType := Variables[c].SystemType;
          argtypes[c].VType := vtInteger;

          { Checks if its by reference or not }
          if Variables[c].Modifier <> moVar then
          begin
            { Parameter NOT by reference }
            {$IFDEF DLL_RTTI}
            argtypes[c].vInteger := VType;
            {$ELSE}
            argtypes[c].vInteger := VType mod 100;
            // uCallDLL uses only standard types declared in System.pas
            {$ENDIF}
            args[c].VType := VType mod 100;
            case VType of
              vtInteger, vtCardinal, vtLongword, vtLongint:
                args[c].vInteger := GetInputArgAsInteger(c);
              vtBoolean:
                args[c].VBoolean := GetInputArgAsBoolean(c);
              vtByte, vtShortint,
              {$IFDEF DELPHI2009_LVL}
              vtChar:
                args[c].VChar := AnsiChar(GetInputArgAsChar(c));
              {$ELSE}
              vtChar:
                args[c].VChar := GetInputArgAsChar(c);
              {$ENDIF}
              vtExtended:
                begin
                  New(args[c].VExtended);
                  args[c].VExtended^ := GetInputArgAsFloat(c);
                end;
              vtString:
                args[c].vString := PShortString(GetInputArgAsString(c));
              vtPointer:
                args[c].vPointer := VarToPointer(GetInputArg(c));
              {$IFDEF DELPHI2009_LVL}
              vtPChar:
                begin
                  { Users must be sure that the string in the parameter is an AnsiString }
                  args[c].VPChar := PAnsiChar(GetInputArgAsString(c));
                end;
              {$ELSE}
              vtPChar:
                args[c].VPChar := PChar(GetInputArgAsString(c));
              {$ENDIF}
              vtObject:
                args[c].VObject := GetInputArgAsObject(c);
              vtClass:
                args[c].VClass := GetInputArgAsClass(c);
              vtWord, vtSmallint, vtWideChar:
                args[c].VWideChar := GetInputArgAsWideChar(c);
              vtPWideChar:
                args[c].VPWideChar := PWideChar(GetInputArgAsString(c));
              vtAnsiString:
                begin
                  astr[c] := AnsiString(GetInputArgAsString(c));
                  args[c].VAnsiString := PAnsiString(astr[c]);
                end;
              {$IFDEF DELPHI2009_LVL}
              vtUnicodeString:
                begin
                  ustr[c] := GetInputArgAsString(c);
                  args[c].VUnicodeString := PUnicodeString(ustr[c]);
                end;
              {$ENDIF}
              vtCurrency:
                begin
                  New(args[c].VCurrency);
                  args[c].VCurrency^ := GetInputArgAsFloat(c);
                end;
              vtVariant:
                begin
                  New(args[c].VVariant);
                  args[c].VVariant^ := GetInputArg(c);
                end;
              vtInterface:
                args[c].VInterface := VarToPointer(GetInputArg(c));
              vtWideString:
                args[c].VWideString := PWideChar(GetInputArgAsWideString(c));
              vtInt64:
                begin
                  New(args[c].vInt64);
                  args[c].vInt64^ := GetInputArgAsInt64(c);
                end;
              vtSingle:
                PSingle(@args[c].vInteger)^ := GetInputArgAsFloat(c);
              vtDateTime, vtDouble:
                begin
                  New(PDouble(args[c].VCurrency));
                  PDouble(args[c].VCurrency)^ := GetInputArgAsFloat(c);
                end;
              vtReal:
                begin
                  New(PReal(args[c].VCurrency));
                  PReal(args[c].VCurrency)^ := GetInputArgAsFloat(c);
                end;
              vtComp:
                begin
                  New(PComp(args[c].VCurrency));
                  PComp(args[c].VCurrency)^ := GetInputArgAsInteger(c);
                end;
            end;
          end
          else
          begin
            { parameter by reference }
            argtypes[c].vInteger := vtPointer;
            args[c].VType := vtPointer;
            case VType of
              vtInteger, vtCardinal, vtLongword, vtLongint:
                begin
                  New(PInteger(args[c].vPointer));
                  PInteger(args[c].vPointer)^ := GetInputArgAsInteger(c);
                end;
              vtBoolean:
                begin
                  New(PBoolean(args[c].vPointer));
                  PBoolean(args[c].vPointer)^ := GetInputArgAsBoolean(c);
                end;
              vtByte, vtShortint, vtChar:
                begin
                  New(PChar(args[c].vPointer));
                  PChar(args[c].vPointer)^ := GetInputArgAsChar(c);
                end;
              vtExtended:
                begin
                  New(PExtended(args[c].vPointer));
                  PExtended(args[c].vPointer)^ := GetInputArgAsFloat(c);
                end;
              vtString:
                begin
                  New(PString(args[c].vPointer));
                  PString(args[c].vPointer)^ := GetInputArgAsString(c);
                end;
              vtPointer:
                begin
                  New(PPointer(args[c].vPointer));
                  PPointer(args[c].vPointer)^ := VarToPointer(GetInputArg(c));
                end;
              {$IFDEF DELPHI2009_LVL}
              vtPChar:
                begin
                  New(PPAnsiChar(args[c].vPointer));
                  astr[c] := AnsiString(GetInputArgAsString(c));
                  PPAnsiChar(args[c].vPointer)^ := PAnsiChar(astr[c]);
                end;
              {$ELSE}
              vtPChar:
                begin
                  New(PPChar(args[c].vPointer));
                  PPChar(args[c].vPointer)^ := PChar(GetInputArgAsString(c));
                end;
              {$ENDIF}
              vtObject:
                begin
                  New(PPointer(args[c].vPointer));
                  PPointer(args[c].vPointer)^ := GetInputArgAsObject(c);
                end;
              vtClass:
                begin
                  New(PPointer(args[c].vPointer));
                  PPointer(args[c].vPointer)^ := GetInputArgAsClass(c);
                end;
              vtWord, vtSmallint, vtWideChar:
                begin
                  New(PWideChar(args[c].vPointer));
                  PWideChar(args[c].vPointer)^ := GetInputArgAsWideChar(c);
                end;
              vtPWideChar:
                begin
                  New(PPointer(args[c].vPointer));
                  PPointer(args[c].vPointer)^ := PWideChar(GetInputArgAsString(c));
                end;
              vtAnsiString:
                begin
                  astr[c] := AnsiString(GetInputArgAsString(c));
                  PPointer(args[c].vPointer)^ := PAnsiString(astr[c]);
                end;
              vtCurrency:
                begin
                  New(PCurrency(args[c].vPointer));
                  PCurrency(args[c].vPointer)^ := GetInputArgAsFloat(c);
                end;
              vtVariant:
                begin
                  New(PVariant(args[c].vPointer));
                  PVariant(args[c].vPointer)^ := GetInputArg(c);
                end;
              vtInterface:
                begin
                  New(PPointer(args[c].vPointer));
                  PPointer(args[c].vPointer)^ := VarToPointer(GetInputArg(c));
                end;
              vtWideString:
                begin
                  New(PPointer(args[c].vPointer));
                  PPointer(args[c].vPointer)^ := PWideChar(GetInputArgAsWideString(c));
                end;
              {$IFDEF DELPHI2009_LVL}
              vtUnicodeString:
                begin
                  ustr[c] := GetInputArgAsString(c);
                  PPointer(args[c].vPointer)^ := PUnicodeString(ustr[c]);
                end;
              {$ENDIF}
              vtInt64:
                begin
                  New(PInt64(args[c].vPointer));
                  PInt64(args[c].vPointer)^ := GetInputArgAsInt64(c);
                end;
              vtSingle:
                begin
                  New(PSingle(args[c].vPointer));
                  PSingle(args[c].vPointer)^ := GetInputArgAsFloat(c);
                end;
              vtDateTime, vtDouble:
                begin
                  New(PDouble(args[c].vPointer));
                  PDouble(args[c].vPointer)^ := GetInputArgAsFloat(c);
                end;
              vtReal:
                begin
                  New(PReal(args[c].vPointer));
                  PReal(args[c].vPointer)^ := GetInputArgAsFloat(c);
                end;
              vtComp:
                begin
                  New(PComp(args[c].vPointer));
                  PComp(args[c].vPointer)^ := GetInputArgAsInteger(c);
                end;
            end;
          end;
        end;

        { builds parameter structure and call the function (uCallDLL.pas) }
        Result := CallDllFunction(ExternalDll, ExternalName, args, argtypes, rettype,
          TCallingConvention(CallingConvention));

        { returns function result to scripter }
        if IsFunction then
          ReturnOutputArg(Result);

      finally
        { frees variable allocated dynamically }
        for c := ArgCount - 1 downto 0 do
          if Variables[c].Modifier <> moVar then
            { frees allocated memory for the parameter frame of the external call }
            case Variables[c].SystemType of
              vtExtended:
                Dispose(args[c].VExtended);
              vtCurrency:
                Dispose(args[c].VCurrency);
              vtVariant:
                Dispose(args[c].VVariant);
              vtInt64:
                Dispose(args[c].vInt64);
              vtDateTime, vtDouble:
                Dispose(PDouble(args[c].VCurrency));
              vtReal:
                Dispose(PReal(args[c].VCurrency));
              vtComp:
                Dispose(PComp(args[c].VCurrency));
            end
          else
          begin
            { modifes the scripter variable which was passed by reference and frees the memory }
            case Variables[c].SystemType of
              vtInteger, vtCardinal, vtLongword, vtLongint:
                begin
                  SetInputArg(c, PInteger(args[c].vPointer)^);
                  Dispose(PInteger(args[c].vPointer));
                end;
              vtBoolean:
                begin
                  SetInputArg(c, PBoolean(args[c].vPointer)^);
                  Dispose(PBoolean(args[c].vPointer));
                end;
              vtByte, vtShortint, vtChar:
                begin
                  SetInputArg(c, PChar(args[c].vPointer)^);
                  Dispose(PChar(args[c].vPointer));
                end;
              vtExtended:
                begin
                  SetInputArg(c, PExtended(args[c].vPointer)^);
                  Dispose(PExtended(args[c].vPointer));
                end;
              vtString:
                begin
                  SetInputArg(c, PString(args[c].vPointer)^);
                  Dispose(PString(args[c].vPointer));
                end;
              {$IFDEF DELPHI2009_LVL}
              vtPChar:
                begin
                  SetInputArg(c, PointerToVar(PPAnsiChar(args[c].vPointer)^));
                  Dispose(PPAnsiChar(args[c].vPointer));
                end;
              {$ELSE}
              vtPChar:
                begin
                  SetInputArg(c, string(PPChar(args[c].vPointer)^));
                  Dispose(PPChar(args[c].vPointer));
                end;
              {$ENDIF}
              vtPointer, vtObject, vtClass:
                begin
                  SetInputArg(c, PointerToVar(args[c].vPointer));
                  Dispose(PPointer(args[c].vPointer));
                end;
              vtWord, vtSmallint, vtWideChar:
                begin
                  SetInputArg(c, PWideChar(args[c].vPointer)^);
                  Dispose(PWideChar(args[c].vPointer));
                end;
              vtPWideChar:
                begin
                  SetInputArg(c, PointerToVar(args[c].vPointer));
                  Dispose(PPointer(args[c].vPointer));
                end;
              vtAnsiString:
                begin
                  SetInputArg(c, astr[c]);
                end;
              {$IFDEF DELPHI2009_LVL}
              vtUnicodeString:
                begin
                  SetInputArg(c, ustr[c]);
                end;
              {$ENDIF}
              vtCurrency:
                begin
                  SetInputArg(c, PCurrency(args[c].vPointer)^);
                  Dispose(PCurrency(args[c].vPointer));
                end;
              vtVariant:
                begin
                  SetInputArg(c, PVariant(args[c].vPointer)^);
                  Dispose(PVariant(args[c].vPointer));
                end;
              vtInterface, vtWideString:
                begin
                  SetInputArg(c, PointerToVar(args[c].vPointer));
                  Dispose(PPointer(args[c].vPointer));
                end;
              vtInt64:
                {$IFDEF DELPHI6_LVL}
                begin
                  SetInputArg(c, PInt64(args[c].vPointer)^);
                  Dispose(PInt64(args[c].vPointer));
                end;
                {$ELSE}
                begin
                  SetInputArg(c, PInteger(args[c].vPointer)^);
                  Dispose(PInteger(args[c].vPointer));
                end;
              {$ENDIF}
              vtSingle:
                begin
                  SetInputArg(c, PSingle(args[c].vPointer)^);
                  Dispose(PSingle(args[c].vPointer));
                end;
              vtDateTime, vtDouble:
                begin
                  SetInputArg(c, PDouble(args[c].vPointer)^);
                  Dispose(PDouble(args[c].vPointer));
                end;
              vtReal:
                begin
                  SetInputArg(c, PReal(args[c].vPointer)^);
                  Dispose(PReal(args[c].vPointer));
                end;
              vtComp:
                begin
                  SetInputArg(c, PComp(args[c].vPointer)^);
                  Dispose(PComp(args[c].vPointer));
                end;
            end;
          end;
      end;
    end
  else
    RaiseRuntimeError
      (Format('Cannot call external function "%s". DLL calls not allowed in scripter.', [Name]));
end;
{$ENDIF}

function TatRoutineInfo.GetResultClassName: string;
begin
  if ResultClass <> nil then
    Result := ResultClass.Name
  else
    Result := '';
end;

function TatRoutineInfo.GetResultTypeDecl: string;
begin
  Result := FResultTypeDecl;
end;

procedure TatRoutineInfo.SetResultClassName(const Value: string);
begin
  SetTypeFromString(Value);
end;

procedure TatRoutineInfo.SetResultTypeDecl(const Value: string);
begin
  FResultTypeDecl := Value;
  SetTypeFromString(FResultTypeDecl);
end;

procedure TatRoutineInfo.SetTypeFromString(ATypeStr: string);
begin
  { tries to define the system type based on the string }

  { if it's a class, then set the result class for scripter }
  if (ScriptInfo <> nil) and (ScriptInfo.Script <> nil) and (ScriptInfo.Script.Scripter <> nil) then
    FResultClass := ScriptInfo.Script.Scripter.Classes.ClassByName(ATypeStr);

  { Choose one of system types based on the string (System.pas) }
  // PullSystemType;
end;

{$IFDEF MSWINDOWS}
function TatRoutineInfo.ResultClassRef: TClass;
begin
  if FResultClass <> nil then
    Result := FResultClass.ClassRef
  else
    Result := nil;
end;
{$ENDIF}

(* procedure TatRoutineInfo.PullSystemType;
  var
  s: string;
  begin
  { descobre o tipo da variável com base em sua declaração }
  { alguns tipos não padrão estão sendo tratados como padrão porque seu tamanho é o mesmo de outros padrão (ex: byte, word, double, ...) }
  s := LowerCase(FResultTypeDecl);
  if s = 'integer'     then FSystemType := vtInteger    else
  if s = 'boolean'     then FSystemType := vtBoolean    else
  if s = 'char'        then FSystemType := vtChar       else
  if s = 'extended'    then FSystemType := vtExtended   else
  if s = 'shortstring' then FSystemType := vtString     else
  if s = 'pointer'     then FSystemType := vtPointer    else
  if s = 'pchar'       then FSystemType := vtPChar      else
  if s = 'tobject'     then FSystemType := vtObject     else
  if s = 'class'       then FSystemType := vtClass      else
  if s = 'widechar'    then FSystemType := vtWideChar   else
  if s = 'pwidechar'   then FSystemType := vtPWideChar  else
  if s = 'ansistring'  then FSystemType := vtAnsiString else
  if s = 'currency'    then FSystemType := vtCurrency   else
  if s = 'variant'     then FSystemType := vtVariant    else
  if s = 'interface'   then FSystemType := vtInterface  else
  if s = 'widestring'  then FSystemType := vtWideString else
  if s = 'int64'       then FSystemType := vtInt64      else
  if s = 'longint'     then FSystemType := vtLongint    else
  if s = 'cardinal'    then FSystemType := vtCardinal   else
  if s = 'longword'    then FSystemType := vtLongword   else
  if s = 'single'      then FSystemType := vtSingle     else
  if s = 'byte'        then FSystemType := vtByte       else
  if s = 'shortint'    then FSystemType := vtShortint   else
  if s = 'word'        then FSystemType := vtWord       else
  if s = 'smallint'    then FSystemType := vtSmallint   else
  if s = 'string'      then FSystemType := vtAnsiString else
  if s = 'double'      then FSystemType := vtDouble     else
  if s = 'real'        then FSystemType := vtReal       else
  if s = 'tdatetime'   then FSystemType := vtDatetime   else
  if s = 'comp'        then FSystemType := vtComp       else
  if Assigned(FDeclaredClass) then FSystemType := vtObject else
  { tipo não suportado. Ex: array of, record of, set of, objeto desconhecido, etc. }
  FSystemType := -1;
  end; *)

function TatRoutineInfo.Internal: boolean;
begin
  Result := (Length(FName) > 0) and (FName[1] = '#');
end;

function TatRoutineInfo.IsByRefArg(n: byte): boolean;
begin
  Result := ((1 shl n) and FByRefArgMask) <> 0;
end;

{ TatVariablesInfo }

function TatVariablesInfo.GetItem(i: integer): TatVariableInfo;
begin
  Result := TatVariableInfo(inherited Items[i]);
end;

function TatVariablesInfo.Add: TatVariableInfo;
begin
  Result := TatVariableInfo(inherited Add);
end;

function TatVariablesInfo.IndexOf(AName: string): integer;
begin
  { pesquisa de traz pra frente para permitir redeclaração (sobrecarga do result) }
  for Result := Count - 1 downto 0 do
    if CompareText(Items[Result].FVarName, AName) = 0 then
      exit;
  Result := -1;
end;

function TatVariablesInfo.FindByName(AName: string): TatVariableInfo;
var
  i: integer;
begin
  i := IndexOf(AName);
  if i > -1 then
    Result := Items[i]
  else
    Result := nil;
end;

{ TatVariableInfo }

function TatVariableInfo.Script: TatScript;
begin
  Result := TatRoutinesInfo(routine.Collection).FScriptInfo.FScript;
end;

function TatVariableInfo.routine: TatRoutineInfo;
begin
  Result := TatRoutineInfo(TatVariablesInfo(Collection).GetOwner);
  if TObject(Result) is TatScriptInfo then
    Result := TatScriptInfo(Result).MainRoutine;
end;

function TatVariableInfo.GetValue: TScriptValue;
begin
  if Global then
  begin
    if Assigned(Script.VirtualMachine) then
    begin
      if not Script.VirtualMachine.FInitialized then
        Script.VirtualMachine.InitializeScript(True);
      Result := DerefValue(Script.VirtualMachine.FProcStack[VarIndex]);
    end;
  end
  else
  begin
    if Assigned(Script.VirtualMachine) and Assigned(Script.VirtualMachine.FPrepareInstruction) then
      with Script.VirtualMachine.FPrepareInstruction^ do
        if (OpCode = inPrepare) and (CompareText(vString, routine.Name) = 0) then
          Result := DerefValue(Script.VirtualMachine.FProcStack[Script.VirtualMachine.FStackBase + VarIndex])
        else
          ScriptInfoError
            (Format('Variable ''%s'' of routine ''%s'' is not available during execution of routine ''%s''',
            [FVarName, routine.Name, vString]))
    else
      ScriptInfoError(Format('Variable ''%s'' is only available while routine ''%s'' is running',
        [FVarName, routine.Name]));
  end;
end;

procedure TatVariableInfo.SetValue(AValue: TScriptValue);
begin
  if Global then
  begin
    if Assigned(Script.VirtualMachine) then
    begin
      if not Script.VirtualMachine.FInitialized then
        Script.VirtualMachine.InitializeScript(True);
      Script.VirtualMachine.FProcStack[VarIndex] := AValue;
    end;
  end
  else
  begin
    if Assigned(Script.VirtualMachine) and Assigned(Script.VirtualMachine.FPrepareInstruction) then
      with Script.VirtualMachine.FPrepareInstruction^ do
        if (OpCode = inPrepare) and (CompareText(vString, routine.Name) = 0) then
          Script.VirtualMachine.FProcStack[Script.VirtualMachine.FStackBase + VarIndex] := AValue
        else
          ScriptInfoError
            (Format('Variable ''%s'' is not available during execution of routine ''%s''',
            [FVarName, routine.Name]))
    else
      ScriptInfoError(Format('Variable ''%s'' is only available while routine ''%s'' is running',
        [FVarName, routine.Name]));
  end;
end;

function TatVariableInfo.Internal: boolean;
begin
  { Retorna True para variáveis internamente declaradas no script.
    Por exemplo: para o FOR, CASE e  WITH }
  Result := (Length(FVarName) > 0) and (FVarName[1] = '#');
end;

function TatVariableInfo.VarIndex: integer;
begin
  { retorna o índice de runtime da variável
    (os argumentos de entrada tem índices negativos e são declarados
    na mesma ordem em que foram passados na chamada à subrotina) }
  if FGlobal then
    Result := Index
  else
    Result := Index - routine.ArgCount;
end;

procedure TatVariableInfo.SetTypeFromString(ATypeStr: string);
begin
  { tenta definir o tipo da variável através da string dada que representa o
    nome do tipo da variável }

  { se o tipo é uma classe então armazena uma referência para a classe do scripter }
  FDeclaredClass := ScriptInfo.Script.Scripter.Classes.ClassByName(ATypeStr);

  { assume um dos tipos padrão para a variável (System.pas) }
  PullSystemType;
end;

function TatVariableInfo.ScriptInfo: TatScriptInfo;
begin
  Result := TatScriptInfo(TatVariablesInfo(Collection).GetOwner);
  if TObject(Result) is TatRoutineInfo then
    Result := TatRoutineInfo(Result).ScriptInfo;
end;

constructor TatVariableInfo.Create(ACollection: TCollection);
begin
  inherited;
  FVisibility := vvPublic;
end;

procedure TatVariableInfo.Assign(ASource: TPersistent);
begin
  FVarName := TatVariableInfo(ASource).FVarName;
  FDeclarationSourcePos := TatVariableInfo(ASource).FDeclarationSourcePos;
  FArgIndex := TatVariableInfo(ASource).FArgIndex;
  FModifier := TatVariableInfo(ASource).FModifier;
  FDeclaredClass := TatVariableInfo(ASource).FDeclaredClass;
  FGlobal := TatVariableInfo(ASource).FGlobal;
end;

function TatVariableInfo.SameDeclaration(AVariable: TatVariableInfo): boolean;
begin
  Result := SameText(VarName, AVariable.VarName) and (ArgIndex = AVariable.ArgIndex) and
    (Modifier = AVariable.Modifier) and (DeclaredClass = AVariable.DeclaredClass);
end;

function TatVariableInfo.GetDeclaredClassName: string;
begin
  if DeclaredClass <> nil then
    Result := DeclaredClass.Name
  else
    Result := '';
end;

procedure TatVariableInfo.SetDeclaredClassName(const Value: string);
begin
  SetTypeFromString(Value);
end;

procedure TatVariableInfo.PullSystemType;
var
  s: string;
begin
  { descobre o tipo da variável com base em sua declaração }
  { alguns tipos não padrão estão sendo tratados como padrão porque seu tamanho é o mesmo de outros padrão (ex: byte, word, double, ...) }
  s := LowerCase(FTypeDecl);
  if s = 'integer' then
    FSystemType := vtInteger
  else if s = 'boolean' then
    FSystemType := vtBoolean
  else if s = 'char' then
    FSystemType := vtChar
  else if s = 'extended' then
    FSystemType := vtExtended
  else if s = 'shortstring' then
    FSystemType := vtString
  else if s = 'pointer' then
    FSystemType := vtPointer
  else
    {$IFDEF DELPHI2009_LVL}
    if s = 'pchar' then
      FSystemType := vtPWideChar
    else
    {$ELSE}
    if s = 'pchar' then
      FSystemType := vtPChar
    else
      {$ENDIF}
      if s = 'pansichar' then
        FSystemType := vtPChar
      else if s = 'tobject' then
        FSystemType := vtObject
      else if s = 'class' then
        FSystemType := vtClass
      else if s = 'widechar' then
        FSystemType := vtWideChar
      else if s = 'pwidechar' then
        FSystemType := vtPWideChar
      else if s = 'ansistring' then
        FSystemType := vtAnsiString
      else if s = 'currency' then
        FSystemType := vtCurrency
      else if s = 'variant' then
        FSystemType := vtVariant
      else if s = 'interface' then
        FSystemType := vtInterface
      else if s = 'widestring' then
        FSystemType := vtWideString
      else if s = 'int64' then
        FSystemType := vtInt64
      else if s = 'longint' then
        FSystemType := vtLongint
      else if s = 'cardinal' then
        FSystemType := vtCardinal
      else if s = 'longword' then
        FSystemType := vtLongword
      else if s = 'single' then
        FSystemType := vtSingle
      else if s = 'byte' then
        FSystemType := vtByte
      else if s = 'shortint' then
        FSystemType := vtShortint
      else if s = 'word' then
        FSystemType := vtWord
      else if s = 'smallint' then
        FSystemType := vtSmallint
      else
        {$IFDEF DELPHI2009_LVL}
        if s = 'string' then
          FSystemType := vtUnicodeString
        else
        {$ELSE}
        if s = 'string' then
          FSystemType := vtAnsiString
        else
          {$ENDIF}
          if s = 'double' then
            FSystemType := vtDouble
          else if s = 'real' then
            FSystemType := vtReal
          else if s = 'tdatetime' then
            FSystemType := vtDateTime
          else if s = 'comp' then
            FSystemType := vtComp
          else if Assigned(FDeclaredClass) then
            FSystemType := vtObject
          else
            { tipo não suportado. Ex: array of, record of, set of, objeto desconhecido, etc. }
            FSystemType := -1;
end;

{ TatClassRefs }

function TatClassRefs.Add(AClassIndex, AElementIndex, AElementClassIndex: integer;
  AElementIsMethod: boolean; AClassName, AElementName, AElementClassName: string): TatClassRef;
begin
  Result := TatClassRef(inherited Add);
  with Result do
  begin
    FClassIndex := AClassIndex;
    FElementIndex := AElementIndex;
    FElementIsMethod := AElementIsMethod;
    FClassName := AClassName;
    FElementName := AElementName;
    FElementClassIndex := AElementClassIndex;
    FElementClassName := AElementClassName;
  end;
end;

constructor TatClassRefs.Create(AScript: TatScript);
begin
  FScript := AScript;
  inherited Create(TatClassRef);
end;

function TatClassRefs.GetItem(i: integer): TatClassRef;
begin
  Result := TatClassRef(inherited Items[i]);
end;

{ TatClassRef }

procedure TatClassRef.CheckLoaded;
var
  AClass: TatClass;
  AMethod: TatMethod;
  AProperty: TatProperty;
begin
  try
    with TatClassRefs(Collection).FScript do
    begin
      // See SolveAbsoluteAddressing comments for explanation of this code
      if (pos('TATINTERNALOBJECT', UpperCase(FElementClassName)) = 1) and
        (Length(FElementClassName) > 17 { Length('TatInternalObject') } ) then
        AClass := FIntInstance.atClass
      else
        AClass := _FindClass(FElementClassIndex, FElementClassName);

      if FElementIsMethod then
      begin
        AMethod := _FindMethod(AClass, FElementIndex, FElementName);
        Scripter.FClasses.CheckLoaded(AMethod.FResultClass, AMethod.FResultClassName);
      end
      else
      begin
        AProperty := _FindProperty(AClass, FElementIndex, FElementName);
        Scripter.FClasses.CheckLoaded(AProperty.FPropertyClass, AProperty.FPropertyClassName);
      end;
    end;
  except
    on ex: Exception do
      InternalError('Error loading implicit class reference.'#13#10 + ex.Message);
  end;
end;

{ TatScripterLibrary }

constructor TatScripterLibrary.Create(AScripter: TatCustomScripter);
begin
  FScripter := AScripter;
end;

class function TatScripterLibrary.LibraryName: string;
begin
  { assume a default library name equal to the class name (excluding intial 'T') }
  if UpperCase(Copy(ClassName, 1, 1)) = 'T' then
    Result := Copy(ClassName, 2, MaxInt)
  else
    Result := ClassName;
end;

procedure TatScripterLibrary.Finalize;
begin
end;

procedure TatScripterLibrary.SelfProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(ObjectToVar(self));
end;

{ TatLibraryList }

function TatLibraryList.Add: TatLibraryListItem;
begin
  Result := TatLibraryListItem(inherited Add);
end;

function TatLibraryList.FindByLibraryName(ALibName: string): TatLibraryListItem;
var
  c: integer;
begin
  for c := 0 to Count - 1 do
    if SameText(ALibName, Items[c].LibraryClass.LibraryName) then
    begin
      Result := Items[c];
      exit;
    end;
  Result := nil;
end;

function TatLibraryList.GetItem(Index: integer): TatLibraryListItem;
begin
  Result := TatLibraryListItem(inherited Items[Index]);
end;

procedure TatLibraryList.Remove(ALibrary: TatScripterLibraryClass);
Var
  c: integer;
begin
  for c := 0 to Count - 1 do
    if ALibrary = Items[c].LibraryClass then
    begin
      Items[c].Free;
      exit;
    end;
end;

{ TatLibraryListItem }

procedure TatLibraryListItem.Assign(Source: TPersistent);
begin
  if Source is TatLibraryListItem then
  begin
    FLibraryClass := TatLibraryListItem(Source).FLibraryClass;
  end
  else
    inherited Assign(Source);
end;

procedure RegisterScripterLibrary(ALibrary: TatScripterLibraryClass;
  AExplicitLoad: boolean = false);
begin
  With atLibraryList.Add do
  begin
    FLibraryClass := ALibrary;
    FExplicitLoad := AExplicitLoad;
  end;
end;

procedure UnregisterScripterLibrary(ALibrary: TatScripterLibraryClass);
begin
  atLibraryList.Remove(ALibrary);
end;

{ TatRecordWrapper }

function TatRecordWrapper.GetObjectReference: TObject;
begin
  Result := self;
end;

{ TatScriptBreakPoints }

constructor TatScriptBreakPoints.Create(AMachine: TatVirtualMachine);
begin
  FMachine := AMachine;
  inherited Create(TatScriptBreakPoint);
end;

function TatScriptBreakPoints.GetItem(i: integer): TatScriptBreakPoint;
begin
  Result := TatScriptBreakPoint(inherited Items[i]);
end;

function TatScriptBreakPoints.RemoveBreakPoint(ATargetInst: pSimplifiedCode): boolean;
begin
  if Assigned(ATargetInst) then
  begin
    { ao tentar remover um BreakPoint de uma instrução Prepare, usa a
      instrução subsequente porque em Prepare não se pode inserir BreakPoint }
    if (ATargetInst^.OpCode = inPrepare) then
      if Assigned(ATargetInst^.Next) and
        (ATargetInst^.vDebugInfo and $FFFFF = ATargetInst^.Next^.vDebugInfo and $FFFFF) then
        ATargetInst := ATargetInst^.Next
      else
      begin
        Result := false;
        exit;
      end;
    if ATargetInst^.OpCode = inBreakPoint then
    begin
      {$IFDEF NEWSTACK}
      Delete(TatScriptBreakPoint(ATargetInst^.vObj).Index);
      {$ELSE}
      Delete(TatScriptBreakPoint(ATargetInst^.vPointer).Index);
      {$ENDIF}
      Result := True;
    end
    else
      Result := false;
  end
  else
    Result := false;
end;

function TatScriptBreakPoints.InsertNormalBreak(ATargetInst: pSimplifiedCode): TatScriptBreakPoint;
begin
  if Assigned(ATargetInst) then
  begin
    { não permite inserir Break em instrução Prepare }
    if ATargetInst^.OpCode = inPrepare then
      if Assigned(ATargetInst^.Next) and
        (ATargetInst^.vDebugInfo and $FFFFF = ATargetInst^.Next^.vDebugInfo and $FFFFF) then
        ATargetInst := ATargetInst^.Next
      else
      begin
        Result := nil;
        exit;
      end;
    { insere uma parada na instrução indicada (ver _BreakPoint) }
    Result := TatScriptBreakPoint(inherited Add);
    Result.SetBreakInst(ATargetInst);
  end
  else
    Result := nil;
end;

function TatScriptBreakPoints.InsertTempBreak(ATargetInst: pSimplifiedCode): TatScriptBreakPoint;
begin
  Result := InsertNormalBreak(ATargetInst);
  if Result <> nil then
    Result.FBreakInst^.vProc := Result.TemporaryBreakProc;
end;

function TatScriptBreakPoints.BreakPointByLine(ALine: integer): TatScriptBreakPoint;
var
  c: integer;
begin
  for c := 0 to Count - 1 do
    if Items[c].FOriginalInst.vDebugInfo and $FFFFF = ALine then
    begin
      Result := Items[c];
      exit;
    end;
  Result := nil;
end;

function TatScriptBreakPoints.Add: TatScriptBreakPoint;
begin
  Result := TatScriptBreakPoint(inherited Add);
end;

{ TatScriptBreakPoint }

constructor TatScriptBreakPoint.Create(Collection: TCollection);
begin
  inherited;
  FPassCount := 0;
  FEnabled := True;
  FAutoDestroy := false;
  FNotifyBreak := nil;
end;

destructor TatScriptBreakPoint.Destroy;
begin
  RemoveBreak;
  if FNotifyBreak <> nil then
  begin
    FNotifyBreak.BreakpointDestroyed(self);
    FNotifyBreak := nil;
  end;
  inherited;
end;

procedure TatScriptBreakPoint.TemporaryBreakProc;
begin
  { BreakPoint falso criado pelo DebugRunToLine }
  with Machine do
  begin
    { paraliza a execução do processamento }
    Paused := True;
    { elimina automaticamente esta paralização,
      restaurando todo o conteúdo original do FCurrentInstruction }

    RemoveBreak;

    { sets next instruction so that original instruction is executed }
    FNextInstruction := FCurrentInstruction;

    Free;
  end;
end;

procedure TatScriptBreakPoint.NormalBreakProc;
begin
  { Regular breakpoint }
  with Machine do
  begin
    { Records the pass count in this breakpoint }
    {$IFDEF NEWSTACK}
    Inc(TatScriptBreakPoint(FCurrentInstruction^.vObj).FPassCount);
    {$ELSE}
    Inc(TatScriptBreakPoint(FCurrentInstruction^.vPointer).FPassCount);
    {$ENDIF}

    { stop execution }
    Paused := True;

    Machine.Script.DoBreakpointStop;
  end;
end;

{ debugger functions }

function TatCustomScripter.InstructionByLine(ARow: integer): pSimplifiedCode;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.InstructionByLine(ARow)
end;

function TatCustomScripter.EntryPoint(ALabel: string): pSimplifiedCode;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.EntryPoint(ALabel)
end;

procedure TatCustomScripter.DebugTraceInto;
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.DebugTraceInto
end;

procedure TatCustomScripter.DebugStepOver;
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.DebugStepOver
end;

procedure TatCustomScripter.DebugTraceIntoLine;
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.DebugTraceIntoLine;
end;

procedure TatCustomScripter.DebugStepOverLine;
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.DebugStepOverLine
end;

procedure TatCustomScripter.DebugRunUntilReturn;
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.DebugRunUntilReturn
end;

procedure TatCustomScripter.DebugRunToPoint(AInstruction: pSimplifiedCode);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.DebugRunToPoint(AInstruction)
end;

procedure TatCustomScripter.DebugRunToLine(ALine: integer);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.DebugRunToLine(ALine)
end;

function TatCustomScripter.DebugToggleBreakPoint(AInstruction: pSimplifiedCode): boolean;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.DebugToggleBreakPoint(AInstruction)
end;

function TatCustomScripter.DebugToggleBreakLine(ALine: integer): pSimplifiedCode;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.DebugToggleBreakLine(ALine)
end;

function TatCustomScripter.DebugExecutionLine: integer;
begin
  CheckMachine;
  Result := FCurrentScript.VirtualMachine.DebugExecutionLine
end;

procedure TatCustomScripter.SetRunning(const Value: boolean);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.SetRunning(Value)
end;

procedure TatCustomScripter.SetPaused(const Value: boolean);
var
  c: integer;
begin
  for c := 0 to Scripts.Count - 1 do
    if (Scripts[c].VirtualMachine <> nil) then
      Scripts[c].VirtualMachine.FPaused := Value;
  if Running then
    SingleDebugHook(CurrentScript.VirtualMachine);
end;

procedure TatCustomScripter.SetCallExecHookEvent(const Value: boolean);
begin
  CheckMachine;
  FCurrentScript.VirtualMachine.CallExecHookEvent := Value
end;

(* function TatScriptBreakPoint.GetBreakLine: integer;
  begin
  result := FOriginalInst.vDebugInfo and $FFFFF;
  end; *)

function TatScriptBreakPoint.Machine: TatVirtualMachine;
begin
  if Collection is TatScriptBreakPoints then
    Result := TatScriptBreakPoints(Collection).FMachine
  else
    Result := nil;
end;

procedure TatScriptBreakPoint.RemoveBreak;
begin
  { remove break point, restoring original instruction }
  if Assigned(FBreakInst) then
  begin
    FBreakInst^.OpCode := FOriginalInst.OpCode;
    FBreakInst^.vByte := FOriginalInst.vByte;
    FBreakInst^.vSmallInt := FOriginalInst.vSmallInt;
    FBreakInst^.vInteger := FOriginalInst.vInteger;
    FBreakInst^.vInteger1 := FOriginalInst.vInteger1;
    FBreakInst^.vString := FOriginalInst.vString;
    FBreakInst^.vDebugInfo := FOriginalInst.vDebugInfo;
    FBreakInst^.Next := FOriginalInst.Next;
    FBreakInst^.Compute := FOriginalInst.Compute;
    FBreakInst^.vProc := FOriginalInst.vProc;
    FBreakInst^.vString2 := FOriginalInst.vString2;
    {$IFDEF NEWSTACK}
    FBreakInst^.vObj := FOriginalInst.vObj;
    FBreakInst^.vInst := FOriginalInst.vInst;
    FBreakInst^.vInst2 := FOriginalInst.vInst2;
    {$ELSE}
    FBreakInst^.vPointer := FOriginalInst.vPointer;
    FBreakInst^.vPointer2 := FOriginalInst.vPointer2;
    {$ENDIF}

    with Machine do
      if FNextInstruction = @OriginalInst then
        FNextInstruction := FBreakInst;

    FBreakInst := nil;
  end;
end;

procedure TatScriptBreakPoint.SetBreakInst(ATargetInst: pSimplifiedCode);
begin
  { Remove a breakpoint if it exists }
  RemoveBreak;

  FBreakInst := ATargetInst;

  { Save original instruction in an internal copy }
  FOriginalInst.OpCode := FBreakInst^.OpCode;
  FOriginalInst.vByte := FBreakInst^.vByte;
  FOriginalInst.vSmallInt := FBreakInst^.vSmallInt;
  FOriginalInst.vInteger := FBreakInst^.vInteger;
  FOriginalInst.vInteger1 := FBreakInst^.vInteger1;
  FOriginalInst.vString := FBreakInst^.vString;
  FOriginalInst.vDebugInfo := FBreakInst^.vDebugInfo;
  FOriginalInst.Next := FBreakInst^.Next;
  FOriginalInst.Compute := FBreakInst^.Compute;
  FOriginalInst.vProc := FBreakInst^.vProc;
  FOriginalInst.vString2 := FBreakInst^.vString2;
  {$IFDEF NEWSTACK}
  FOriginalInst.vObj := FBreakInst^.vObj;
  FOriginalInst.vInst := FBreakInst^.vInst;
  FOriginalInst.vInst2 := FBreakInst^.vInst2;
  {$ELSE}
  FOriginalInst.vPointer := FBreakInst^.vPointer;
  FOriginalInst.vPointer2 := FBreakInst^.vPointer2;
  {$ENDIF}

  { modify original instruct so it become a break instruction }
  with FBreakInst^ do
  begin
    { change some fields and keep other ones the same }
    OpCode := inBreakPoint;
    Compute := Machine.FComputeProcs[inBreakPoint];
    {$IFDEF NEWSTACK}
    vObj := self;
    {$ELSE}
    vPointer := ObjectToVar(self);
    {$ENDIF}
    vProc := NormalBreakProc;
    Next := @FOriginalInst;
  end;
end;

{ TatObject }

procedure TatObject.Assign(ASource: TPersistent);
begin
  Name := TatObject(ASource).Name;
  Instance := TatObject(ASource).Instance;
  FatClass := TatObject(ASource).FatClass;
end;

procedure TatObject.SeTatClass(const Value: TatClass);
begin
  FatClass := TatObjects(Collection).FClasses.ClassByName(Value.Name);
  if not Assigned(FatClass) then
    DefinitionError(Format('Undefined default instance class ''%s''', [Value.Name]));
end;

{ TatDataDef }

procedure TatDataDef.Assign(ASource: TPersistent);
begin
  FName := TatDataDef(ASource).FName;
  FDataType := TatDataDef(ASource).FDataType;
  FModifier := TatDataDef(ASource).FModifier;
  FDataTypeName := TatDataDef(ASource).FDataTypeName;
  FDefaultValueText := TatDataDef(ASource).FDefaultValueText;
end;

{ TatScripts }

function TatScripts.Add: TatScript;
begin
  if (FScripter <> nil) and (FScripter.DefaultScriptClass <> nil) then
    Result := FScripter.DefaultScriptClass.Create(self)
  else
    Result := TatScript(inherited Add);
end;

constructor TatScripts.Create(AScripter: TatCustomScripter);
begin
  FScripter := AScripter;
  if not Assigned(AScripter.FScriptClass) then
    AScripter.FScriptClass := TatScript;
  inherited Create(AScripter.FScriptClass);
end;

function TatScripts.FindByUnitName(AUnitName: string): TatScript;
var
  c: integer;
begin
  Result := nil;
  for c := 0 to Count - 1 do
    if SameText(AUnitName, Items[c].UnitName) then
    begin
      Result := Items[c];
      exit;
    end;
end;

function TatScripts.GetItem(i: integer): TatScript;
begin
  Result := TatScript(inherited Items[i]);
end;

{ TatScript }

constructor TatScript.Create(ACollection: TCollection);
var
  AObject: TatInternalObject;
begin
  FScripter := TatScripts(ACollection).FScripter;
  inherited Create(ACollection);

  FDerivedScripts := TatScriptList.Create(false);
  FBreaks := TatScriptBreaks.Create(self, TatScriptBreak);
  FCodeStream := TMemoryStream.Create;

  { Create Refactor }
  FRefactor := FRefactorClass.Create(self);

  { initialize fields }
  FLibraries := TList.Create;

  { cria o objeto para armazenar informações de depuração }
  FScriptInfo := TatScriptInfo.Create(nil);
  FScriptInfo.FScript := self;

  FSourceCode := TStringList.Create;
  TStringList(FSourceCode).OnChange := SourceCodeChange;

  { cria uma SyntaxParser para uso no compilador }
  FParser := TatSyntaxParser.Create(nil);

  { cria a máquina virtual para execução de scripts }
  FVirtualMachines := TatVirtualMachines.Create(self, Scripter.FMachineClass);
  if Scripter.FMachineClass <> nil then
    FVirtualMachine := FVirtualMachines.Add;

  FUsedUnits := TatUsedUnits.Create(Scripter);
  FRollbackSourceCode := false;

  FDefInstances := TatObjects.Create(Scripter.FClasses);
  AObject := TatInternalObject.Create;
  FIntInstance := FDefInstances.Add(AObject, '', 'TatInternalObject' +
    {$IFDEF NEWSTACK}
    inttostr(IntObject(AObject)));
    {$ELSE}
    inttostr(VarToIntObject(ObjectToVar(AObject))));
    {$ENDIF}
end;

destructor TatScript.Destroy;
var
  FormIntf: IScriptBasedForm;
begin
  { if the script was derived from another script (form), then emove the script itself
    from the list of derived scripts of base (original) script }
  SetOriginalScript(nil);

  { if the script is a base (original) script, then iterate through all derived scripts
    and notify them that the original script is not valid anymore (it's destroyed, so it
    must be set to nil. We don't need to remove the items in FDerivedScripts list, because
    when we set originalscript to nil, the derivedscript automatically removes itself
    from the FCreateList of base script.
    Note that this code should never be executed in normal ways, because it doesn't make
    sense to destroy the base script while there are derived scripts still running }
  while FDerivedScripts.Count > 0 do
    TatScript(FDerivedScripts[0]).SetOriginalScript(nil);

  FDerivedScripts.Free;

  { Set runscript to nil }
  if (FOriginalForm <> nil) and not (csDestroying in FOriginalForm.ComponentState) then
  begin
    if not Supports(FOriginalForm, IScriptBasedForm, FormIntf) then
      RuntimeError('IScriptBasedForm not found in ScriptFormClass');
    FormIntf.SetRunScript(nil);
  end;
  FBreaks.Free;
  FCodeStream.Free;

  if Assigned(FOnDestroy) then
    { permite que o proprietário possa ser notificado sobre a destruição desse script }
    FOnDestroy(self);
  // RemoveAttachedEvents;
  if VirtualMachine <> nil then
    Clear;
  FLibraries.Free;
  FUsedUnits.Free;
  FUsedUnits := nil;
  FVirtualMachines.Free;
  FParser.Free;
  FSourceCode.Free;
  FScriptInfo.Free;
  FIntInstance.Instance.Free;
  FDefInstances.Free;

  if FScriptForm <> nil then
  begin
    FScriptForm.Free;
    FScriptForm := nil;
  end;
  if (FOriginalObject <> nil) and not FOriginalObject.FDestroying then
  begin
    FOriginalObject.FRunScript := nil;
    FOriginalObject.Free;
    FOriginalObject := nil;
  end;

  FRefactor.Free;
  inherited;
end;

procedure TatScript.RemoveAttachedEvents(RemoveAll: boolean);
var
  c: integer;
  total: integer;
begin
  with Scripter.EventBroker do
  begin
    c := 0;
    while c < Dispatchers.Count do
    begin
      total := Dispatchers.Count;
      if Dispatchers[c].Script = self then
      begin
        if (ScriptInfo.RoutineByName(Dispatchers[c].RoutineName) <> nil) or RemoveAll then
          Dispatchers[c].Unset;
      end;
      if total = Dispatchers.Count then
        Inc(c);
    end;
  end;
end;

procedure TatScript.Clear;
var
  st: TStackType;
  c: integer;
begin
  if VirtualMachine = nil then
    NoMachineError;

  { Avoid stack overflow }
  if not FClearingScript then
  begin
    FClearingScript := True;
    try
      if VirtualMachine.Running then
        FatalError('Cannot clear script while script is running.');

      if not FCompiling and (FRefactoring = 0) then
        RemoveAttachedEvents(True);

      { descarrega as DLL que já foram carregadas para este script }
      if FLoadedDLL then
        DisposeDLL;

      { INICIALIZA VARIÁVEIS E ESTRUTURAS PARA GERAR CÓDIGO }

      { Unregister this script whenever it is registered as a library }
      while FLibraries.Count > 0 do
        SelfUnregisterAsLibrary(TatScriptBasedLibrary(FLibraries[0]).Scripter);

      { Unregister the form/object class, if it was registered. It must be called *after* selfunregisteraslibrary,
        because the latter destroys some methods registered in the form/object class. If the form/object class is removed
        before, we get some AV when SelfUnregisterLibrary tries to remove those methods }
      UnregisterForm;
      UnregisterScriptClass;

      { limpa as informações de depuração se não estiver em um script do debugger }
      if not FIsDebugScript then
        FScriptInfo.Clear;

      { leave only one virtual machine, and then clears it. Virtual machine cleaning must
        be *before* disposing p-code (DisposeCode below), due to internal breakpoints }
      for c := FVirtualMachines.Count - 1 downto 1 do
        FVirtualMachines[c].Free;
      FVirtualMachine := FVirtualMachines[0];
      FVirtualMachine.Clear;

      ClearLabelSpecs;

      ClearStacks;

      DisposeCode(FFirstInstruction);
      FLastInstruction := nil;

      { inicializa os stacks internos }
      for st := low(TStackType) to High(TStackType) do
        FStack[st] := nil;

      { inicializa os especificadores de rótulos }
      FFirstLabelSpec := nil;
      FLastLabelSpec := nil;

      { inicialização de propriedades }
      FCodeLine := -1;
      FCompiled := false;
      FSilentCompiled := false;
      FSolvedAddressing := false;
      FExpandedDebugInfo := false;
      FCurrentRoutine := nil;

      { clear used units }
      if FUsedUnits <> nil then
        FUsedUnits.Clear;

      FFileName := '';
      // FUnitName := '';
    finally
      FClearingScript := false;
    end;
  end;
end;

procedure TatScript.DisposeDLL;
var
  c: integer;
begin
  { varre as libraries, verificando se há alguma vinculada ao presente script }
  with FScripter.FLibInstances do
    for c := Count - 1 downto 0 do
      if (TObject(Items[c]) is TatDLL) and (TatDLL(Items[c]).FScript = self) then
        { descarrega a DLL }
        FScripter.RemoveLibraryInstance(TatDLL(Items[c]), TatDLL(Items[c]).LibraryName);
  FLoadedDLL := false;
end;

procedure TatScript.SaveCodeToFile(AFileName: string);
var
  f: TFileStream;
begin
  try
    f := TFileStream.Create(AFileName, fmCreate);
    try
      SaveCodeToStream(f);
    finally
      f.Free;
    end;
  except
    InternalError(Format('Unable to save file %s', [AFileName]));
  end;
end;

procedure TatScript.LoadCodeFromFile(AFileName: string);
var
  f: TFileStream;
begin
  f := TFileStream.Create(AFileName, fmOpenRead or fmShareDenyWrite);
  try
    LoadCodeFromStream(f);
  finally
    f.Free;
  end;
end;

{ ------------------------------------------------------------------------------ }
{ Simplified code - file and stream handling }
{ ------------------------------------------------------------------------------ }
procedure TatScript.InternalSaveCodeToStream(AStream: TStream);
var
  c: integer;
  CodeFileHeader: TCodeFileHeader;
  Instruction: pSimplifiedCode;
  InstructionDescriptor: TInstructionDescriptor;
  ImplicitClassRef: TImplicitClassRef;
  AUsedUnit: TUsedUnitRec;
  ScriptInfoStream: TMemoryStream;
begin
  Self.ExpandDebugInfo(false);
  with Scripter do
  begin
    ScriptInfoStream := TMemoryStream.Create;
    try
      try
        { clear destination stream }
        AStream.Size := 0;

        { Save ScriptInfo }
        ScriptInfoStream.WriteComponent(FScriptInfo);

        { PCODE HEADER }

        { prepare header variables }
        with CodeFileHeader do
        begin
          Signature := 'atPascal Executable File'#26;
          Version := CODEFILE_VERSION;
          ImplicitRefCount := FScripter.Classes.ImplicitCount;
          UsedUnitCount := FUsedUnits.Count;
          ScriptInfoSize := ScriptInfoStream.Size;
          { fill unused bytes }
          FillChar(Reserved, 28, 0);
        end;

        { write header to stream }
        AStream.WriteBuffer(CodeFileHeader, sizeof(TCodeFileHeader));

        { write implicit class references to file }
        for c := 0 to FScripter.Classes.Count - 1 do
        begin
          with FScripter.Classes[c] do
          begin
            if IsImplicit then
            begin
              ImplicitClassRef.ClassIndex := Index;
              ImplicitClassRef.ElementIndex := FImplicitClassRef.ElementIndex;
              // ImplicitElement is either TatMethod or TatProperty
              ImplicitClassRef.ElementIsMethod := FImplicitClassRef.ElementIsMethod;
              ImplicitClassRef.ClassNameSize := Length(Name);
              ImplicitClassRef.ElementNameSize := Length(FImplicitClassRef.FElementName);
              ImplicitClassRef.ElementClassIndex := FImplicitClassRef.ElementClassIndex;
              ImplicitClassRef.ElementClassNameSize := Length(FImplicitClassRef.FElementClassName);

              AStream.WriteBuffer(ImplicitClassRef, sizeof(TImplicitClassRef));
              AStream.WriteBuffer(PChar(Name)^, ImplicitClassRef.ClassNameSize * sizeof(char));
              AStream.WriteBuffer(PChar(FImplicitClassRef.FElementName)^,
                ImplicitClassRef.ElementNameSize * sizeof(char));
              AStream.WriteBuffer(PChar(FImplicitClassRef.FElementClassName)^,
                ImplicitClassRef.ElementClassNameSize * sizeof(char));
            end;
          end;
        end;

        { write used units to file }
        for c := 0 to CodeFileHeader.UsedUnitCount - 1 do
        begin
          with FUsedUnits[c] do
          begin
            AUsedUnit.UnitNameSize := Length(UnitName);
            AUsedUnit.IsDefault := IsDefault;
            AUsedUnit.IsScript := IsScript;
            AUsedUnit.DeclSourcePos := DeclSourcePos;
          end;
          AStream.WriteBuffer(AUsedUnit, sizeof(TUsedUnitRec));
          AStream.WriteBuffer(PChar(FUsedUnits[c].UnitName)^, Length(FUsedUnits[c].UnitName) *
            sizeof(char));
        end;

        { write script info to file }
        ScriptInfoStream.Seek(0, soFromBeginning);
        AStream.CopyFrom(ScriptInfoStream, ScriptInfoStream.Size);

        { INSTRUCTIONS }

        { scan instruction list }
        Instruction := FFirstInstruction;
        while Instruction <> nil do
        begin
          { prepare instruction descriptor variables }
          with InstructionDescriptor do
          begin
            Size := Length(Instruction^.vString);
            Size2 := Length(Instruction^.vString2);

            Details.OpCode := ord(Instruction^.OpCode);
            Details.vByte := Instruction^.vByte;
            Details.vSmallInt := Instruction^.vSmallInt;
            Details.vInteger := Instruction^.vInteger;
            Details.vInteger1 := Instruction^.vInteger1;
            Details.vSave1 := Instruction^.vSave1;
            Details.vSave2 := Instruction^.vSave2;
            Details.vDebugInfo := Instruction^.vDebugInfo;
          end;
          { write instruction to file }
          AStream.WriteBuffer(InstructionDescriptor, sizeof(InstructionDescriptor));
          { manually writes the string variable content }
          AStream.WriteBuffer(PChar(Instruction^.vString)^, Length(Instruction^.vString) *
            sizeof(char));
          AStream.WriteBuffer(PChar(Instruction^.vString2)^, Length(Instruction^.vString2) *
            sizeof(char));
          { get next instruction }
          Instruction := Instruction^.Next;
        end;
      except
        on ex: Exception do
          InternalError(Format('Unable to write stream (%s)', [ex.Message]));
      end;
    finally
      ScriptInfoStream.Free;
    end;
  end;
end;

procedure TatScript.SaveCodeToStream(AStream: TStream);
begin
  with Scripter do
  begin
    if not FCompiled then
      { save operation is not allowed after Execute, thus compilation is made before }
      Compile;

    AStream.Size := 0;
    FCodeStream.Position := 0;
    AStream.CopyFrom(FCodeStream, FCodeStream.Size);
  end;
end;

procedure TatScript.LoadCodeFromStream(AStream: TStream);
begin
  InternalLoadCodeFromStream(AStream, True);
end;

procedure TatScript.InternalLoadCodeFromStream(AStream: TStream; AUseBehavior: boolean);
var
  CodeFileHeader: TCodeFileHeader;
  InstructionDescriptor: TInstructionDescriptor;
  s1, s2, s3: string;
  c1, c2, c3, i: integer;
  ImplicitClassRef: TImplicitClassRef;
  AUsedUnit: TUsedUnitRec;
  ScriptInfoStream: TMemoryStream;
  TempUnitName: string;
  implicitClasses: TatClassRefs;
begin
  CheckMachine;
  if VirtualMachine.Running then
    FatalError('Cannot load code from stream while script is running.');
  Clear;
  if Assigned(FScripter) then
    FScripter.BeforeLoadCode;
  ScriptInfoStream := TMemoryStream.Create;
  implicitClasses := TatClassRefs.Create(self);
  try
    try
      { read stream from current position }

      { PCODE HEADER }

      { read header from file }
      AStream.ReadBuffer(CodeFileHeader, sizeof(TCodeFileHeader));
      with CodeFileHeader do
      begin
        if Signature <> 'atPascal Executable File'#26 then
          InternalError('Invalid executable file signature');
        if Version <> CURRENT_VERSION then
          InternalError(Format('%d not is a valid executable file version, expected %d',
            [Version, CURRENT_VERSION]));
      end;

      { read implicit class references from file }
      { load implicit class into script info structure }
      for i := 0 to CodeFileHeader.ImplicitRefCount - 1 do
      begin
        AStream.ReadBuffer(ImplicitClassRef, sizeof(TImplicitClassRef));

        c1 := ImplicitClassRef.ClassNameSize;
        SetLength(s1, c1);
        AStream.ReadBuffer(PChar(s1)^, c1 * sizeof(char));

        c2 := ImplicitClassRef.ElementNameSize;
        SetLength(s2, c2);
        AStream.ReadBuffer(PChar(s2)^, c2 * sizeof(char));

        c3 := ImplicitClassRef.ElementClassNameSize;
        SetLength(s3, c3);
        AStream.ReadBuffer(PChar(s3)^, c3 * sizeof(char));

        implicitClasses.Add(ImplicitClassRef.ClassIndex, ImplicitClassRef.ElementIndex,
          ImplicitClassRef.ElementClassIndex, ImplicitClassRef.ElementIsMethod, s1, s2, s3);
      end;

      { read used units from file }
      for i := 0 to CodeFileHeader.UsedUnitCount - 1 do
      begin
        AStream.ReadBuffer(AUsedUnit, sizeof(TUsedUnitRec));
        SetLength(TempUnitName, AUsedUnit.UnitNameSize);
        { read the string content }
        AStream.ReadBuffer(PChar(TempUnitName)^, AUsedUnit.UnitNameSize * sizeof(char));
        with FUsedUnits.Add do
        begin
          UnitName := TempUnitName;
          IsDefault := AUsedUnit.IsDefault;
          IsScript := AUsedUnit.IsScript;
          DeclSourcePos := AUsedUnit.DeclSourcePos;
        end;
      end;

      { read script info from file }
      if CodeFileHeader.ScriptInfoSize > 0 then
      begin
        ScriptInfoStream.CopyFrom(AStream, CodeFileHeader.ScriptInfoSize);
        ScriptInfoStream.Seek(0, soFromBeginning);
        ScriptInfoStream.ReadComponent(FScriptInfo);
        if AUseBehavior then
        begin
          case FScriptInfo.Behavior of
            sbClass:
              RegisterScriptClass;
            sbForm:
              begin
                RegisterForm;
              end;
          end;
        end;
      end;

      { load implicit classrefs }
      for i := 0 to implicitClasses.Count - 1 do
        implicitClasses[i].CheckLoaded;

      { INSTRUCTIONS }

      { builds instruction list }
      while AStream.Position < AStream.Size - 1 do
      begin
        { read the instruction descriptor }
        AStream.ReadBuffer(InstructionDescriptor, sizeof(TInstructionDescriptor));

        { alocate memory for wide string }
        c1 := InstructionDescriptor.Size;
        SetLength(s1, c1);

        c2 := InstructionDescriptor.Size2;
        SetLength(s2, c2);

        { read the string content }
        AStream.ReadBuffer(PChar(s1)^, c1 * sizeof(char));
        AStream.ReadBuffer(PChar(s2)^, c2 * sizeof(char));

        { include the readed instruction into code memory }
        with AppendInstruction(TInstruction(InstructionDescriptor.Details.OpCode))^ do
        begin
          vInteger := InstructionDescriptor.Details.vInteger;
          vByte := InstructionDescriptor.Details.vByte;
          vInteger1 := InstructionDescriptor.Details.vInteger1;
          vSave1 := InstructionDescriptor.Details.vSave1;
          vSave2 := InstructionDescriptor.Details.vSave2;
          vSmallInt := InstructionDescriptor.Details.vSmallInt;
          vString := s1;
          vString2 := s2;
          vDebugInfo := InstructionDescriptor.Details.vDebugInfo;
        end;
      end;

      if Assigned(FScripter) then
        for i := 0 to FUsedUnits.Count - 1 do
          FScripter.LoadLibrary(FUsedUnits[i].UnitName, FUsedUnits[i].IsDefault);

      FSolvedAddressing := false;
      FCompiled := True;
      FSilentCompiled := True;
      FExpandedDebugInfo := true;
      FScriptInfo.UpdateRoutineInfoPointers;

      { creates methods for the external calls }
      for i := 0 to ScriptInfo.Routines.Count - 1 do
        if ScriptInfo.Routines[i].ExternalDll > '' then
          ScriptInfo.Routines[i].PrepareExternalClass;
    except
      on ex: EatInternalError do
        raise;
      on ex: Exception do
        InternalError(Format('Unable to read stream (%s)', [ex.Message]));
    end;
  finally
    ScriptInfoStream.Free;
    implicitClasses.Free;
  end;

  { After loading, save the code to an internal stream for reuse }
  FCodeStream.Size := 0;
  // OldIsForm := ScriptInfo.IsForm;
  // ScriptInfo.IsForm := false;
  InternalSaveCodeToStream(FCodeStream);
  // ScriptInfo.IsForm := OldIsForm;
  VirtualMachine.FFastSolving := false;
end;

{ métodos auxiliares para o geração de código usando classes }

procedure TatScript.RelativeGetterRef(AProperty: TatProperty; AInst: pSimplifiedCode);
begin
  { Use only the field vProc.Data to relative class indexing, vProc.Code is ignored
    vProc will entirely replaced by SolveAbsoluteAddressing, after compiling or
    after loading code from file }
  if Assigned(AProperty) then
  begin
    TMethod(AInst^.vProc).Code := nil;
    TMethod(AInst^.vProc).Data := pointer(ord(crGetter) + AProperty.Index shl 2 +
      TatProperties(AProperty.Collection).FClass.Index shl 17);
    AInst^.vString2 := TatProperties(AProperty.Collection).FClass.Name;
  end
  else
  begin
    { Indicate, into field vProc.Data that the reference is for undefined property getter }
    TMethod(AInst^.vProc).Code := nil;
    TMethod(AInst^.vProc).Data := pointer(crGetter);
  end;
end;

procedure TatScript.RelativeSetterRef(AProperty: TatProperty; AInst: pSimplifiedCode);
begin
  { Use only the field vProc.Data to relative class indexing, vProc.Code is ignored
    vProc will entirelly replaced by SolveAbsoluteAddressing, after compiling or
    after loading code from file }
  if Assigned(AProperty) then
  begin
    TMethod(AInst^.vProc).Code := nil;
    TMethod(AInst^.vProc).Data := pointer(ord(crSetter) + AProperty.Index shl 2 +
      TatProperties(AProperty.Collection).FClass.Index shl 17);
    AInst^.vString2 := TatProperties(AProperty.Collection).FClass.Name;
  end
  else
  begin
    { Indicate, into field vProc.Data that the reference is for undefined property setter }
    TMethod(AInst^.vProc).Code := nil;
    TMethod(AInst^.vProc).Data := pointer(crSetter);
  end;
end;

procedure TatScript.RelativeMethodRef(AMethod: TatMethod; AInst: pSimplifiedCode);
begin
  { Use only the field vProc.Data to relative class indexing, vProc.Code is ignored
    vProc will entirelly replaced by SolveAbsoluteAddressing, after compiling or
    after loading code from file }
  if Assigned(AMethod) then
  begin
    TMethod(AInst^.vProc).Code := nil;
    TMethod(AInst^.vProc).Data := pointer(ord(crMethod) + AMethod.Index shl 2 +
      TatMethods(AMethod.Collection).FClass.Index shl 17);
    AInst^.vString2 := TatMethods(AMethod.Collection).FClass.Name;
  end
  else
  begin
    { Indicate, into field vProc.Data that the reference is for undefined method }
    TMethod(AInst^.vProc).Code := nil;
    TMethod(AInst^.vProc).Data := pointer(crMethod);
  end;
end;

{ ------------------------------------------------------------------------------ }
{ Pilhas internas do gerador de código }
{ ------------------------------------------------------------------------------ }

procedure TatScript.StackPush(StackType: TStackType; x: TScriptValue);
var
  prev: pStackElement;
begin
  prev := FStack[StackType];
  New(FStack[StackType]);
  with FStack[StackType]^ do
  begin
    Previous := prev;
    Element := x;
    if ScriptValueIsNull(x) then
      Index := -1
    else if Previous = nil then
      Index := 0
    else
      Index := Previous^.Index + 1;
  end;
end;

procedure TatScript.StackPushDelimitter(StackType: TStackType);
begin
  StackPush(StackType, NullValue);
end;

function TatScript.EmptyStack(StackType: TStackType): boolean;
begin
  Result := (FStack[StackType] = nil);
end;

function TatScript.StackPop(StackType: TStackType): TScriptValue;
var
  aux: pStackElement;
begin
  if FStack[StackType] = nil then
    RuntimeError('Empty stack when trying to pop element ' + GetEnumName(TypeInfo(TStackType),
      ord(StackType)));
  aux := FStack[StackType].Previous;
  Result := FStack[StackType]^.Element;
  Dispose(FStack[StackType]);
  FStack[StackType] := aux;
end;

function TatScript.StackPopAsString(StackType: TStackType): string;
begin
  {$IFDEF NEWSTACK}
  Result := StackPop(StackType).AsString;
  {$ELSE}
  Result := StackPop(StackType);
  {$ENDIF}
end;

function TatScript.StackPopAsDouble(StackType: TStackType): double;
begin
  {$IFDEF NEWSTACK}
  Result := StackPop(StackType).AsExtended;
  {$ELSE}
  Result := StackPop(StackType);
  {$ENDIF}
end;

function TatScript.StackPopAsInt(StackType: TStackType): integer;
begin
  {$IFDEF NEWSTACK}
  Result := StackPop(StackType).AsOrdinal;
  {$ELSE}
  Result := StackPop(StackType);
  {$ENDIF}
end;

function TatScript.StackPopAsBool(StackType: TStackType): boolean;
begin
  {$IFDEF NEWSTACK}
  Result := StackPop(StackType).AsBoolean;
  {$ELSE}
  Result := StackPop(StackType);
  {$ENDIF}
end;

function TatScript.StackView(StackType: TStackType): TScriptValue;
begin
  if FStack[StackType] = nil then
    RuntimeError('Empty stack when trying to pop element ' + GetEnumName(TypeInfo(TStackType),
      ord(StackType)));
  Result := FStack[StackType]^.Element;
end;

function TatScript.StackViewAsInt(StackType: TStackType): integer;
begin
  {$IFDEF NEWSTACK}
  Result := StackView(StackType).AsOrdinal
  {$ELSE}
  Result := StackView(StackType);
  {$ENDIF}
end;

function TatScript.StackDelimitterFound(StackType: TStackType): boolean;
begin
  Result := ScriptValueIsNull(StackView(StackType));
end;

procedure TatScript.ClearStacks;
var
  st: TStackType;
begin
  for st := low(TStackType) to High(TStackType) do
    while not EmptyStack(st) do
      StackPop(st);
end;

{ ------------------------------------------------------------------------------ }
{ Funções para manipulação de desvios - geração e solução de labels }
{ ------------------------------------------------------------------------------ }

function TatScript.NewLabelSpec(Name: string): pLabelSpec;
begin
  { aloca um novo especificador de rótulo - estabelecendo valores apropriados para
    FFirstLabelSpec e FLastLabelSpec }
  New(Result);
  Result^.Name := Name;
  Result^.Address := -1;
  Result^.FirstRef := nil;
  Result^.LastRef := nil;
  Result^.Next := nil;
  if FFirstLabelSpec = nil then
    FFirstLabelSpec := Result
  else
    FLastLabelSpec^.Next := Result;
  FLastLabelSpec := Result;
end;

function TatScript.FindLabelSpec(Name: string): pLabelSpec;
begin
  { devolve o LabelSpec se existir, senão devolve nil }
  Result := FFirstLabelSpec;
  while (Result <> nil) and (UpperCase(Result.Name) <> UpperCase(Name)) do
    Result := Result^.Next;
end;

function TatScript.RegisterReference(Name: string): integer;
var
  LabelSpec: pLabelSpec;
  LastRef: pAddress;
begin
  { esta rotina deve ser chamada após a geração do código que fez a referência
    para o rótulo de endereçamento }

  { encontra o especificador se já existir, senão o cria }
  LabelSpec := FindLabelSpec(name);
  if LabelSpec = nil then
    LabelSpec := NewLabelSpec(name);
  if LabelSpec^.Address > -1 then
  begin
    { se o rótulo já tiver sido definido, não registra a referência }
    Result := LabelSpec^.Address + 1;
    FLastInstruction.vInteger := Result; { aponta para a instrução subseqüente ao rótulo }
  end
  else
  begin
    { empilha a referência ao rótulo dentro do especificador }
    New(LastRef);
    LastRef^.Next := nil;
    LastRef^.Address := FCodeLine;
    LastRef^.Code := FLastInstruction;
    if LabelSpec^.FirstRef = nil then
      LabelSpec^.FirstRef := LastRef
    else
      LabelSpec^.LastRef^.Next := LastRef;
    LabelSpec^.LastRef := LastRef;
    Result := 0; // referência indefinida
  end;
end;

procedure TatScript.SolveReference(LabelSpec: pLabelSpec);
var
  Ref: pAddress;
begin
  with LabelSpec^ do
  begin
    while FirstRef <> nil do
    begin
      FirstRef^.Code.vInteger := Address + 1; // aponta para a instrução subseqüente ao rótulo
      { libera a memória alocada e avança para a próxima referência }
      Ref := FirstRef;
      FirstRef := FirstRef^.Next;
      Dispose(Ref);
    end;
    LastRef := nil;
  end;
end;

function TatScript.DefineProp(AName: string; ADataType: TatTypeKind; AGetter, ASetter: TMachineProc;
  APropertyClass: TClass; AIsClassProp: boolean; AIndexCount: integer): TatProperty;
begin
  Result := FIntInstance.atClass.DefineProp(AName, ADataType, AGetter, ASetter, APropertyClass,
    AIsClassProp, AIndexCount);
end;

procedure TatScript.DefineReferenceAddress(Name: string);
var
  LabelSpec: pLabelSpec;
begin
  { esta rotina deve ser chamada antes da primeira instrução referente ao
    rótulo de endereçamento }

  { A resolução das referências será feita para a instrução subseqüente ao rótulo }

  { encontra o especificador se já existir, senão o cria }
  LabelSpec := FindLabelSpec(name);
  if LabelSpec = nil then
    LabelSpec := NewLabelSpec(name);
  { registra o endereço do rótulo }
  LabelSpec^.Address := FCodeLine;
  { se haviam referências pendentes, resolve-as agora }
  if LabelSpec^.FirstRef <> nil then
    SolveReference(LabelSpec);
end;

procedure TatScript.ClearLabelSpecs;
var
  LabelSpec: pLabelSpec;
  Address: pAddress;
begin
  { elimina toda a estrutura de especificadores de rótulos }
  while FFirstLabelSpec <> nil do
  begin
    while FFirstLabelSpec^.FirstRef <> nil do
    begin
      Address := FFirstLabelSpec^.FirstRef;
      FFirstLabelSpec^.FirstRef := FFirstLabelSpec^.FirstRef^.Next;
      Dispose(Address);
    end;
    LabelSpec := FFirstLabelSpec;
    FFirstLabelSpec := FFirstLabelSpec^.Next;
    Dispose(LabelSpec);
  end;
  FLastLabelSpec := nil;
end;

procedure TatScript.SolveUndefinedReferences;
var
  LabelSpec: pLabelSpec;
  routine: TatRoutineInfo;
begin
  LabelSpec := FFirstLabelSpec;
  while LabelSpec <> nil do
  begin
    with LabelSpec^ do
      if FirstRef <> nil then { referências indefinidas }
      begin
        { se for um script do debugger então dá uma segunda chance para resolver a referência:
          verifica se o endereço se refere a uma rotina com endereço já definido }
        if FIsDebugScript then
        begin
          routine := FScriptInfo.RoutineByName(Name);
          if Assigned(routine) then
          begin
            { resolve a referência de forma absoluta para o endereço de
              início da subrotina }
            LabelSpec^.Address := IntObject(routine.DeclarationInstruction) - 1;
            SolveReference(LabelSpec);
          end
          else
            CompileError(Format('Unknown method ou subroutine: ''%s''', [Name]),
              FirstRef^.Code^.vDebugInfo);
        end
        else
          CompileError(Format('Unknown method ou subroutine: ''%s''', [Name]),
            FirstRef^.Code^.vDebugInfo);
      end;
    LabelSpec := LabelSpec^.Next;
  end;
end;

procedure TatScript.DisposeCode(var Code: pSimplifiedCode);
var
  aux: pSimplifiedCode;
begin
  { libera o programa previamente alocado }
  while Code <> nil do
  begin
    aux := Code;
    Code := Code^.Next;
    Dispose(aux);
  end;
end;

function TatScript.AppendInstruction(i: TInstruction): pSimplifiedCode;
var
  prev: pSimplifiedCode;
begin
  Inc(FCodeLine);
  prev := FLastInstruction;
  New(FLastInstruction);
  Result := FLastInstruction;
  FillChar(Result^, sizeof(TSimplifiedCode), 0);
  Result^.OpCode := i;
  if not Assigned(prev) then
    FFirstInstruction := FLastInstruction
  else
    prev^.Next := FLastInstruction;
end;

procedure TatScript.OptimizeStoreVar(AVar: TatVariableInfo; AIgnoreConstant: boolean = false);
begin
  { Se a última expressão gerada for o empilhamento de uma simples constante ou
    o valor de uma variável então, substitui esta instrução por outra que
    também incui o StoreVar, senão gera um StoreVar genérico (não otimizado) }
  if (AVar.Modifier = moConst) and not AIgnoreConstant then
    CompileError(Format('Cannot assign a value to constant ''%s''', [AVar.VarName]),
      FParser.ScanningInputPos);
  with AVar, FLastInstruction^ do
    if not Global then { *** variáveis globais não suportam otimização por enquanto *** }
      case OpCode of
        inPushInteger:
          { transforma o PushInteger em um StoreVarInteger }
          begin
            if Modifier = moVar then
              OpCode := inStoreVarRefInteger
            else
              OpCode := inStoreVarInteger;
            // vInteger2 := vInteger; // Armazena o valor inteiro a ser carregado na variável
            vInt64 := vInt64;
            vInteger := VarIndex; // Armazena o índice da variável do case
            vString := VarName; // Armazena o nome da variável
          end;
        inPushString:
          { transforma o PushString em um StoreVarString }
          begin
            if Modifier = moVar then
              OpCode := inStoreVarRefString
            else
              OpCode := inStoreVarString;
            vInteger := VarIndex; // Armazena o índice da variável do case
            vInteger3 := Length(vString); // Armazena o comprimento do conteúdo da string
            vString := vString + VarName; // Concatena o conteúdo e o nome da variável
          end;
        inPushDouble:
          { transforma o PushDouble em um StoreVarDouble }
          begin
            if Modifier = moVar then
              OpCode := inStoreVarRefDouble
            else
              OpCode := inStoreVarDouble;
            vInteger := VarIndex; // Armazena o índice da variável
            vString := VarName; // Armazena o nome da variável
          end;
        inPushConst:
          { transforma o PushConst em um StoreVarConst }
          begin
            if Modifier = moVar then
              OpCode := inStoreVarRefConst
            else
              OpCode := inStoreVarConst;
            vInteger := VarIndex; // Armazena o índice da variável
            vInteger3 := Length(vString); // Armazena o comprimento do conteúdo da string
            vString := vString + VarName; // Concatena o nome da constante com o nome da variável
          end;
        inPushVar:
          { transforma o PushVar em um CopyVar }
          begin
            if Modifier = moVar then
              OpCode := inCopyVarRef
            else
              OpCode := inCopyVar;
            vInteger2 := VarIndex; // Armazena o índice da variável do case
            vInteger3 := Length(vString);
            vString := vString + VarName;
            // Concatena a nome da variável origem com o nome da variável destino
          end;
      else
        { Como a expressão não é uma simples constante ou variável então gera uma
          instrução para carga genérica da variável }
        if Modifier = moVar then
          with AppendInstruction(inStoreVarRef)^ do
          begin
            vInteger := VarIndex;
            vString := VarName;
            vDebugInfo := FParser.ScanningInputPos;
          end
        else
          with AppendInstruction(inStoreVar)^ do
          begin
            vInteger := VarIndex;
            vString := VarName;
            vDebugInfo := FParser.ScanningInputPos;
          end;
      end
    else if Modifier = moVar then
      CompileError(Format('Internal error: Trying to generate StoreGlobalVarRef(%s)', [AVar.VarName]
        ), FParser.ScanningInputPos)
    else
      with AppendInstruction(inStoreGlobalVar)^ do
      begin
        vInteger := VarIndex;
        vString := VarName;
        vDebugInfo := FParser.ScanningInputPos;
      end;
end;

procedure TatScript.OptimizeVarTest(ACaseVarIndex: integer; ACaseVarName, AJumpLabel: string;
  ACondition: boolean);
begin
  { .$IFDEF CODE_OPTIMIZATION }
  // Do not optimize anymore!!! p-code instruction record needs additional data (vInteger2, 3, etc.)
  // and now optimization is not that important anymore.
  // case FLastInstruction^.OpCode of
  // inPushInteger:
  // { transforma o PushInteger em um VarTestInteger }
  // with FLastInstruction^ do
  // begin
  // OpCode:=inVarTestInteger;
  // vByte:=byte(ACondition);
  // vInteger2:=ACaseVarIndex; // Armazena o índice da variável do case
  // vInteger3:=vInteger; // Armazena o valor inteiro a ser testado na variável
  // vInteger:=RegisterReference(AJumpLabel); // aqui será armazenado o endereço do desvio condicional
  // vString:=ACaseVarName; // Armazena o nome da variável do teste (e não o rótulo do desvio)
  // end;
  // inPushString:
  // { transforma o PushString em um VarTestString }
  // with FLastInstruction^ do
  // begin
  // OpCode:=inVarTestString;
  // vByte:=byte(ACondition);
  // vInteger2:=ACaseVarIndex; // Armazena o índice da variável do case
  // vInteger3:=length(vString); // Armazena o comprimento do conteúdo da string
  // vInteger:=RegisterReference(AJumpLabel); // aqui será armazenado o endereço do desvio condicional
  // vString:=vString+ACaseVarName; // Concatena o conteúdo e o nome da variável
  // end;
  // inPushDouble:
  // { transforma o PushDouble em um VarTestDouble }
  // with FLastInstruction^ do
  // begin
  // OpCode:=inVarTestDouble;
  // vByte:=byte(ACondition);
  // vInteger1:=ACaseVarIndex; // Armazena o índice da variável do case
  // vInteger:=RegisterReference(AJumpLabel); // aqui será armazenado o endereço do desvio condicional
  // vString:=ACaseVarName; // Armazena o nome da variável do teste (e não o rótulo do desvio)
  // end;
  // inPushVar:
  // { transforma o PushVar em um VarTestVar }
  // with FLastInstruction^ do
  // begin
  // OpCode:=inVarTestVar;
  // vByte:=byte(ACondition);
  // vInteger1:=length(vString); // Armazena o comprimento do conteúdo da string
  // vInteger2:=vInteger;      // Armazena o índice da variável origem
  // vInteger3:=ACaseVarIndex; // Armazena o índice da variável destino
  // vInteger:=RegisterReference(AJumpLabel); // aqui será armazenado o endereço do desvio condicional
  // vString:=vString+ACaseVarName; // Concatena os nomes das variáveis
  // end;
  // else
  // { Como a expressão não é uma simples constante nem variável então gera uma
  // instrução para teste genérica da variável }
  // with AppendInstruction(inVarTest)^ do
  // begin
  // vInteger   := RegisterReference(AJumpLabel);
  // vByte      := byte(ACondition);
  // vInteger2  := ACaseVarIndex;
  // vString    := ACaseVarName;
  // vDebugInfo := FParser.ScanningInputPos;
  // end;
  // end;
  { .$ELSE }
  { Se as otimizações de código estiverem desligadas então não condensa o
    VarTest com o conteúdo que tiver sido salvo na pilha }
  with AppendInstruction(inVarTest)^ do
  begin
    vInteger := RegisterReference(AJumpLabel);
    vByte := byte(ACondition);
    vInteger2 := ACaseVarIndex;
    vString := ACaseVarName;
    vDebugInfo := FParser.ScanningInputPos;
  end;
  { .$ENDIF }
end;

function TatScript.RegisterVariableReference(id: string): TatVariableInfo;
begin
  { atualiza a lista de variáveis do processo }
  { se a variável já existe apenas determina seu índice }
  Result := CurrentRoutine.VariableByName(id);
  if Result = nil then
    Result := ScriptInfo.Globals.FindByName(id);
  if not Assigned(Result) then
    if Scripter.FOptionExplicit and not FSilentCompilation then
      CompileError(Format('Undeclared variable ''%s''', [id]), FParser.ScanningInputPos)
    else
    begin
      { como a variável não existe e OptionExplicit=false então declara-a automaticamente }
      { inclui informações sobre esta variável }
      Result := CurrentRoutine.DeclareVariable(id, FParser.ScanningInputPos);
    end;
end;

function TatScript.DeclareVariable(AName: string; AArgIndex: integer = -1;
  AModifier: TatArgumentModifier = moNone; AGlobal: boolean = false; ASourcePos: integer = -1)
  : TatVariableInfo;
begin
  if ASourcePos = -1 then
    ASourcePos := FParser.ScanningInputPos;
  if AGlobal then
  begin
    { evita que a variável seja declarada mais de uma vez }
    if Assigned(ScriptInfo.Globals.FindByName(AName)) then
      CompileError(Format('Redeclaration of global identifier ''%s''', [AName]),
        FParser.ScanningInputPos);
    { declara o identificador incluindo um item na coleção de variáveis globais }
    Result := ScriptInfo.Globals.Add;
    with Result do
    begin
      FVarName := AName;
      FArgIndex := AArgIndex;
      FModifier := AModifier;
      FGlobal := True;
      FDeclarationSourcePos := ASourcePos
    end;
  end
  else
  begin
    { evita que a variável seja declarada mais de uma vez }
    if Assigned(CurrentRoutine.VariableByName(AName)) then
      CompileError(Format('Redeclaration of identifier ''%s''', [AName]), ASourcePos);
    { inclui informações sobre esta variável }
    Result := CurrentRoutine.DeclareVariable(AName, ASourcePos, AArgIndex, AModifier);
  end;
end;

procedure TatScript.GetRowColFromSource(APos: integer; var row, col: integer);
begin
  GetRowColFromStrings(FParser.Strings, APos, row, col);
end;

procedure TatScript.InternalCompile(Silent: boolean);
var
  row: integer;
  col: integer;
  {$IFDEF TRIAL}
  msg: string;
  i: integer;
  {$ENDIF}
begin
  {$IFDEF TRIAL}
  if (Now > EncodeDate(2015, 12, 31)) then
  begin
    msg := 'Tfhfiesg hSjcgrfidpstcetrg yShtgufdeidof dvcevrfseidofnd wheassz aesxdpfitryeudu.g fPvldecaxssed rrteyguiishtjehrg,f dosrd s'
      + 'tdor tcfognvtcisnwueed sewvratlhunagtbifnvgc sdzotwfnglhoiaodk jam nnhegwf d' +
      'vdefrrstigovnc sfdreormf xhttgtyph:j/u/iwnwhwg.btfmvscsdowfqtawsadreer.fcrotm';
    i := 2;
    while i < Length(msg) do
    begin
      System.Delete(msg, i, 1);
      Inc(i);
    end;
    raise Exception.Create(msg);
  end;
  {$ENDIF}
  CheckMachine;
  FSilentCompilation := Silent;
  FCompiling := True;
  try

    if VirtualMachine.Running then
      FatalError('Cannot compile script while script is running.');

    if Assigned(FScripter) then
      FScripter.BeforeCompile;

    { Inicializa o objeto }
    Clear;

    { Parsing nas strings de entrada }
    with FParser, CheckLanguage do

      if Result <> srCorrect then
      begin
        GetRowColFromSource(MaxInputPos - 1, row, col);
        CompileError('Syntax error', row, col);
      end;
    { Varre a árvore sintática para gerar código executável }
    FParser.ScanSyntaxTree;
    { Tenta resolver referências a identificadores ainda não resolvidos }
    SolveUndefinedReferences;
    FCompiled := not Silent;
    FSilentCompiled := True;

    { conclui informações sobre o script compilado }
    FScriptInfo.FCodeSize := FCodeLine + 1;
    FScriptInfo.UnitName := self.UnitName;

    { After loading, if the script is a form, then save the code to an internal
      stream for reuse when a new form is created }
    if FCompiled then
    begin
      FCodeStream.Size := 0;
      // OldIsForm := ScriptInfo.IsForm;
      // ScriptInfo.IsForm := false;
      InternalSaveCodeToStream(FCodeStream);
      // ScriptInfo.IsForm := OldIsForm;
      RemoveAttachedEvents(false);
    end;
  finally
    FSilentCompilation := false;
    FCompiling := false;
  end;
end;

procedure TatScript.SilentCompile;
begin
  InternalCompile(True);
end;

procedure TatScript.Compile;
begin
  InternalCompile(false);
end;

procedure TatScript.ExpandDebugInfo(RequiresCompilation: boolean = True);
var
  Cur: pSimplifiedCode;
  InputPos: integer; // indica a posição corrida correspondente no programa-fonte
  row, col: integer; // indica a posição decomposta correspondente no programa-fonte

  procedure IncInputPos;
  begin
    if (InputPos > 0) and (InputPos < Length(FParser.Input)) and (FParser.Input[InputPos] = #10)
    then
    begin
//      Inc(InputPos);
      Inc(row);
      col := 1;
    end
    else
      Inc(col);
    Inc(InputPos);
  end;

  procedure DecInputPos;
  begin
    dec(InputPos);
    if (InputPos > 0) and (InputPos < Length(FParser.Input)) and (FParser.Input[InputPos] = #10)
    then
    begin
//      dec(InputPos);
      dec(row);
      col := Length(FParser.Strings[row - 1]) + 1;
    end
    else
      dec(col);
  end;

begin
  if not FExpandedDebugInfo then
  begin
    CheckMachine;
    { verifica se o método compile já foi chamado, senão chama-o automaticamente }
    if not FCompiled and RequiresCompilation then
      Compile;

    // { verifica se o endereçamento absoluto já foi resolvido, senão resolve-o automaticamente }
    if not FSolvedAddressing and RequiresCompilation then
      VirtualMachine.SolveAbsoluteAddressing;
    { Decodifica o campo vDebugInfo do código simplificado }
    { Expande a posição sequencial do programa-fonte em linha e coluna }
    Cur := FFirstInstruction;
    InputPos := 1;
    row := 1;
    col := 1;
    while Cur <> nil do
    begin
      with Cur^ do
      begin
        { converte o campo DebugInfo na linha e coluna correspondente ao programa-fonte }
        { *** este procedimento será desnecessário quando o parser já tiver esta
          informação assim decomposta *** }
        while InputPos < vDebugInfo do
          IncInputPos;
        while InputPos > vDebugInfo do
          DecInputPos;
        vDebugInfo := col shl 20 + row; // esta codificação permite 1048576 linhas e 4096 colunas
      end;
      Cur := Cur^.Next;
    end;
    FExpandedDebugInfo := True;
  end;
  Breaks.UpdateAll;
end;

function TatScript.ErrorComplement(APos: integer): string;
var
  row, col: integer;
begin
  if ExpandedDebugInfo then
  begin
    row := LineNumberFromDebugInfo(APos) + 1;
    col := ColNumberFromDebugInfo(APos) + 1;
  end
  else
    GetRowColFromSource(APos, row, col);
  Result := '.'#13#10 + 'Source position: ' + inttostr(row) + ',' + inttostr(col);
end;

procedure TatScript.GetRowColFromInst(Inst: pSimplifiedCode; var row, col: integer);
begin
  if ExpandedDebugInfo then
  begin
    row := LineNumberFromDebugInfo(Inst^.vDebugInfo) + 1;
    col := ColNumberFromDebugInfo(Inst^.vDebugInfo) + 1;
  end
  else
    GetRowColFromSource(Inst^.vDebugInfo, row, col);
end;

procedure TatScript.SourceCodeChange(Sender: TObject);
begin
  if not FRollbackSourceCode then
  begin
    if (VirtualMachine <> nil) and VirtualMachine.Running then
    begin
      { Script is running, do not change source code (retrieve old source code saved in parser object }
      FRollbackSourceCode := True;
      FSourceCode.Assign(FParser.Strings);
      FRollbackSourceCode := false;
      FatalError('Cannot change script source code while script is running.');
    end
    else
    begin
      FParser.Strings.Assign(FSourceCode);
      FRefactor.FDirtySource := True;
      Scripter.FPCode.Size := 0;
      Clear;
      if not FIsDebugScript then
        Scripter.SourceCodeChanged(self);
    end;
  end;
end;

procedure TatScript.SetSourceCode(Value: TStrings);
begin
  FSourceCode.Assign(Value);
end;

procedure TatScript.CompileError(msg: string; debuginfo: integer);
var
  row, col: integer;
begin
  if not FSilentCompilation then
  begin
    GetRowColFromSource(debuginfo, row, col);
    CompileError(msg, row, col);
  end;
end;

procedure TatScript.CompileError(msg: string; row, col: integer);
begin
  if not FSilentCompilation then
  begin
    if Assigned(FScripter) then
      FScripter.InternalCompileError(msg, row, col, self);
  end;
end;

procedure TatScript.RuntimeError(msg: string);
begin
  if Assigned(FScripter) then
    FScripter.InternalRuntimeError(msg, self);
end;

procedure TatScript.GetSelfBaseObjectProc(AMachine: TatVirtualMachine);
begin
  AMachine.ReturnOutputArg(ObjectToVar(FOriginalObject));
end;

function TatScript.GetStack(st: TStackType): pStackElement;
begin
  Result := FStack[st];
end;

function TatScript.SelfRegisterAsLibrary(AScripter: TatCustomScripter; AName: string;
  AClassRef: TClass; AClassName: string; ADefault: boolean; AddMethod: boolean): TatScripterLibrary;
var
  NewLibrary: TatScriptBasedLibrary;
begin
  FUnitName := AName;
  if not FCompiled then
    Compile;
  SelfUnregisterAsLibrary(AScripter);
  NewLibrary := TatScriptBasedLibrary.Create(AScripter);
  NewLibrary.FInternalScript := self;
  NewLibrary.FName := AName;
  NewLibrary.FRegClass := AClassRef;

  NewLibrary.FRegClassName := AClassName;
  AScripter.AddLibraryInstance(NewLibrary, NewLibrary.FName, ADefault, AddMethod, AClassName);
  FLibraries.Add(NewLibrary);
  if Scripter <> AScripter then
    AScripter.FreeNotification(Scripter);

  Result := NewLibrary;
end;

function TatScript.SelfRegisterAsLibrary(AScripter: TatCustomScripter; AName: string = '')
  : TatScripterLibrary;
var
  AClass: TClass;
  AClassName: string;
  ADefault: boolean;
  AAddMethod: boolean;
begin
  FUnitName := AName;
  { Compile the script to check if it has the $FORM/$CLASS directive. This will affect script behavior }
  if not FCompiled then
    Compile;
  case ScriptInfo.Behavior of
    sbNormal:
      begin
        AClass := TatScriptBasedLibrary;
        AClassName := 'TatScriptBasedLibrary' + AName;
        ADefault := True;
        AAddMethod := True;
      end;
    sbClass:
      begin
        AClass := Scripter.ScriptBaseObjectClass;
        AClassName := ScriptInfo.ScriptClassName;
        ADefault := false;
        AAddMethod := false;
      end;
    sbForm:
      begin
        CheckScriptFormClass;
        AClass := Scripter.ScriptFormClass;
        AClassName := ScriptInfo.ScriptClassName;
        ADefault := false;
        AAddMethod := false;
      end;
  end;
  Result := SelfRegisterAsLibrary(AScripter, AName, AClass, AClassName, ADefault, AAddMethod);
end;

procedure TatScript.SelfUnregisterAsLibrary(AScripter: TatCustomScripter; AName: string = '');
var
  c: integer;
  ALibrary: TatScriptBasedLibrary;
begin
  c := 0;
  while c < FLibraries.Count do
  begin
    ALibrary := TatScriptBasedLibrary(FLibraries[c]);
    if ALibrary.Scripter = AScripter then
      if (AName = '') or (ALibrary.FName = AName) then
      begin
        AScripter.RemoveLibraryInstance(ALibrary, ALibrary.FName);
        ALibrary.Free;
        FLibraries.Delete(c);
        Break;
      end;
    Inc(c);
  end;
end;

function TatScript.SelfRegisterAsLibrary(AName: string = ''): TatScripterLibrary;
begin
  Result := SelfRegisterAsLibrary(Scripter, AName);
end;

procedure TatScript.SelfUnregisterAsLibrary(AName: string = '');
begin
  SelfUnregisterAsLibrary(Scripter, AName);
end;

function TatScript.DeclareEventHandler(AProcName: string): integer;
begin
  if FRefactor <> nil then
    Result := FRefactor.DeclareRoutine(AProcName)
  else
    Result := 0;
end;

procedure TatScript.DoUnknownElement(var Context: TElementContext);
begin
  Scripter.DoUnknownElement(Context);
end;

function TatScript.LoadLibrary(ALibraryName: string; ADefault: boolean): TatScripterLibrary;
begin
  Result := Scripter.LoadLibrary(ALibraryName, ADefault, FSilentCompilation);
end;

function TatScript.UsesObject(AObject: TObject; AName: string = ''; AClassName: string = '')
  : TatClass;
begin
  Result := FDefInstances.Add(AObject, AName, AClassName).atClass;
end;

procedure TatScript.UnuseObject(AClassName: string);
var
  AObj: TatObject;
begin
  AObj := FDefInstances.FindInstanceByClassName(AClassName);
  if AObj <> nil then
    AObj.Free;
end;

procedure TatScript.AddObject(AName: string; AObject: TObject);
begin
  FIntInstance.atClass.AddObject(AName, AObject);
end;

procedure TatScript.RemoveObject(AName: string);
begin
  FIntInstance.atClass.RemoveProperty(AName);
end;

procedure TatScript.CompileScriptClass(AClassName: string);
begin
  { Compilation }
  ScriptInfo.ScriptClassName := AClassName;
  ScriptInfo.Behavior := sbClass;
  RegisterScriptClass;
end;

procedure TatScript.RegisterScriptClass;
var
  AClass: TatClass;
begin
  if ScriptInfo.Behavior = sbClass then
  begin
    { Define the new object class in script. The class will be known as ScriptClassName (TMyClass, for example),
      but the "Delphi" class is still TScriptBaseObject }
    AClass := Scripter.DefineClass(Scripter.ScriptBaseObjectClass, ScriptInfo.ScriptClassName);

    (* ************if (AClass.FBaseScript <> nil) and (AClass.FBaseScript <> Self) then
      RuntimeError(Format('Class "%s" already registered by another script.', [ScriptInfo.ScriptClassName]));************ *)
    AClass.FBaseScript := self;

    { Define Self as tkVariant, not as TkClass, so all method/property resolution will be deferred to
      runtime. If we set the class type here, scripter will try to solve methods/properties at compile time
      but it will raise errors for properties and methods defined in the script, because at this
      time, the script is not compiled itself. For example, if the script has a "Foo" procedure, it
      should be considered a method of Self. But compiler will not recognize Self.Foo because Foo
      will only be added as a method when the script is compiled and self registered as a library. }
    DefineProp('Self', tkVariant, GetSelfBaseObjectProc, nil, nil);
  end;
end;

procedure TatScript.UnregisterScriptClass;
var
  AClass: TatClass;
begin
  { Remove the created object class, because when the script is cleared, we don't want that class
    registered anymore }
  if ScriptInfo.Behavior = sbClass then
  begin
    { Remove the "Self" variable }
    RemoveObject('Self');

    { Remove the default instance }
    UnuseObject(ScriptInfo.ScriptClassName);

    { Remove the class - must be done after the code above, because the code above
      holds reference to the class }
    AClass := Scripter.Classes.ClassByName(ScriptInfo.ScriptClassName);
    if (AClass <> nil) and (AClass.FBaseScript = self) then
    begin
      AClass.Free;
    end;
  end;
end;

procedure TatScript.CompileForm(AFormClassName, AFormFile: string);
begin
  { Compilation }
  ScriptInfo.ScriptClassName := AFormClassName;
  if DesignFormResource <> '' then
    ScriptInfo.FormResource := DesignFormResource
  else
    ScriptInfo.FormResource := GetFormFileAsString(AFormFile);
  ScriptInfo.Behavior := sbForm;
  RegisterForm;
end;

procedure TatScript.RegisterForm;
var
  AClass: TatClass;
  AScriptForm: TBaseScriptForm;
  Loader: TScriptFormLoader;
  FormIntf: IScriptBasedForm;
begin
  CheckScriptFormClass;
  if ScriptInfo.Behavior = sbForm then
  begin
    { Registering. A form instance must be created so that it can be "used" in script, specially the
      components inside it }
    if DesignScriptForm <> nil then
    begin
      AScriptForm := DesignScriptForm;
    end
    else
    begin
      if FScriptForm <> nil then
        FScriptForm.Free;
      FScriptForm := Scripter.ScriptFormClass.Create(nil);
      AScriptForm := FScriptForm;

      { Load form resource only for the purpose of registering the controls and components inside the form }
      if not Supports(AScriptForm, IScriptBasedForm, FormIntf) then
        InternalError('IScriptBasedForm not found in ScriptFormClass');
      Loader := TScriptFormLoader.Create(FormIntf);
      try
        Loader.LoadFormResource(ScriptInfo.FormResource, Scripter.LoadFormEvents);
      finally
        Loader.Free;
      end;
    end;

    { Define the new form class in script. The class will be known as ScriptClassName (TMyForm, for example),
      but the "Delphi" class is still TScriptForm }
    AClass := Scripter.DefineFormClass(AScriptForm, ScriptInfo.ScriptClassName);

    (* ************if (AClass.FBaseScript <> nil) and (AClass.FBaseScript <> Self) then
      RuntimeError(Format('Class "%s" already registered by another script.', [ScriptInfo.ScriptClassName]));************ *)
    AClass.FBaseScript := self;

    UsesObject(AScriptForm, '', ScriptInfo.ScriptClassName);
    AddObject('Self', AScriptForm);
  end;
end;

procedure TatScript.UnregisterForm;
var
  AClass: TatClass;
begin
  { Remove the created form class, because when the script is cleared, we don't want that class
    registered anymore }
  if ScriptInfo.Behavior = sbForm then
  begin
    { Remove the "Self" variable }
    RemoveObject('Self');

    { Remove the default instance }
    UnuseObject(ScriptInfo.ScriptClassName);

    { Remove the class - must be done after the code above, because the code above
      holds reference to the class }
    AClass := Scripter.Classes.ClassByName(ScriptInfo.ScriptClassName);
    if (AClass <> nil) and (AClass.FBaseScript = self) then
    begin
      AClass.Free;
    end;

  end;
end;

function TatScript.GetFormFileAsString(AFormFile: string): string;
var
  FormFileName: string;
  SL: TStringList;
begin
  { Now loads the associated DFM file }
  FormFileName := Scripter.FindFormFile(AFormFile);
  if not FileExists(FormFileName) then
    RuntimeError(Format('Cannot find form file "%s".', [AFormFile]));
  SL := TStringList.Create;
  try
    SL.LoadFromFile(FormFileName);
    Result := SL.Text;
  finally
    SL.Free;
  end;
end;

procedure TatScript.SetCompiled(const Value: boolean);
begin
  if FCompiled <> Value then
  begin
    if Value then
      Compile
    else
      Clear;
  end;
end;

function TatScript.IsRegisteredAsLibrary(AScripter: TatCustomScripter): boolean;
var
  ALib: TatScripterLibrary;
begin
  Result := CheckRegisteredAsLibrary(AScripter, ALib);
end;

procedure TatScript.CheckMachine;
begin
  if not Assigned(VirtualMachine) then
    NoMachineError;
end;

function TatScript.CheckRegisteredAsLibrary(AScripter: TatCustomScripter;
  var ALib: TatScripterLibrary): boolean;
var
  c: integer;
  ALibrary: TatScriptBasedLibrary;
begin
  ALib := nil;
  Result := false;
  for c := 0 to FLibraries.Count - 1 do
  begin
    ALibrary := TatScriptBasedLibrary(FLibraries[c]);
    if ALibrary.Scripter = AScripter then
    begin
      Result := True;
      ALib := ALibrary;
      Break;
    end;
  end;
end;

procedure TatScript.CheckScriptFormClass;
begin
  if not Assigned(Scripter.ScriptFormClass) then
    NoScriptFormClassError;
end;

procedure TatScript.SetOriginalScript(AScript: TatScript);
begin
  if FOriginalScript <> nil then
    FOriginalScript.FDerivedScripts.Remove(self);
  FOriginalScript := AScript;
  if FOriginalScript <> nil then
  begin
    FOriginalScript.FDerivedScripts.Add(self);
    FOriginalScript.Breaks.UpdateAll;
  end;
end;

procedure TatScript.DoBreakpointStop;
begin
  if Scripter <> nil then
    Scripter.DoBreakpointStop;
end;

function TatScript.RemoveLastInstruction: pSimplifiedCode;
var
  Inst: pSimplifiedCode;
begin
  dec(FCodeLine);
  Inst := FFirstInstruction;
  while Inst^.Next <> FLastInstruction do
    Inst := Inst^.Next;
  Result := FLastInstruction;
  FLastInstruction := Inst;
end;

procedure TatScript.AppendInstruction(AInstruction: pSimplifiedCode);
var
  prev: pSimplifiedCode;
begin
  Inc(FCodeLine);
  prev := FLastInstruction;
  FLastInstruction := AInstruction;
  if not Assigned(prev) then
    FFirstInstruction := FLastInstruction
  else
    prev^.Next := FLastInstruction;
end;

{ TatVirtualMachine }

constructor TatVirtualMachine.Create(ACollection: TCollection);
begin
  FFastSolving := True;
  FScript := TatScript(TatVirtualMachines(ACollection).GetOwner);
  FScripter := FScript.Scripter;
  // if (FScript.VirtualMachines.Count>0) and
  // (FScript.Compiled=False) then
  // FatalError('A new virtual machine cannot be created without a compiled script');

  inherited;

  FStopInstruction := nil;
  { cria a coleção de break-points deste script }
  FBreakPoints := TatScriptBreakPoints.Create(self);

  { cria a coleção de watches para depuração }
  FDebugWatches := TatDebugWatches.Create(self, TatDebugWatch);

  { carrega a tabela de rotinas semânticas }
  FComputeProcs[inPrepare] := _Prepare;
  FComputeProcs[inPushDouble] := _PushDouble;
  FComputeProcs[inPushVar] := _PushVar;
  FComputeProcs[inPushIdxVar] := _PushIdxVar;
  FComputeProcs[inPushString] := _PushString;
  FComputeProcs[inPushConst] := _PushConst;
  FComputeProcs[inPushOutput] := _PushOutput;
  FComputeProcs[inPushClass] := _PushClass;
  FComputeProcs[inDuplicate] := _Duplicate;
  FComputeProcs[inDuplicate2] := _Duplicate2;
  FComputeProcs[inDrop2] := _Drop2;
  FComputeProcs[inSwap2] := _Swap;
  FComputeProcs[inOperNE] := _OperNE;
  FComputeProcs[inOperGE] := _OperGE;
  FComputeProcs[inOperLE] := _OperLE;
  FComputeProcs[inOperEqual] := _OperEqual;
  FComputeProcs[inOperGreater] := _OperGreater;
  FComputeProcs[inOperLess] := _OperLess;
  FComputeProcs[inOperAdd] := _OperAdd;
  FComputeProcs[inOperConcat] := _OperConcat;
  FComputeProcs[inOperSub] := _OperSub;
  FComputeProcs[inOperOr] := _OperOr;
  FComputeProcs[inOperXor] := _OperXor;
  FComputeProcs[inOperMul] := _OperMul;
  FComputeProcs[inOperSlash] := _OperSlash;
  FComputeProcs[inOperDiv] := _OperDiv;
  FComputeProcs[inOperMod] := _OperMod;
  FComputeProcs[inOperAnd] := _OperAnd;
  FComputeProcs[inOperShl] := _OperShl;
  FComputeProcs[inOperShr] := _OperShr;
  FComputeProcs[inOperExp] := _OperExp;
  FComputeProcs[inOperIs] := _OperIs;
  FComputeProcs[inOperNeg] := _OperNeg;
  FComputeProcs[inOperNot] := _OperNot;
  FComputeProcs[inJumpIfFalse] := _JumpIfFalse;
  FComputeProcs[inJumpIfTrue] := _JumpIfTrue;
  FComputeProcs[inJump] := _Jump;
  FComputeProcs[inCall] := _Call;
  FComputeProcs[inRet] := _Ret;
  FComputeProcs[inStoreInput] := _StoreInput;
  FComputeProcs[inExecFun] := _ExecFun;
  FComputeProcs[inPushInteger] := _PushInteger;
  FComputeProcs[inTryFinally] := _TryFinally;
  FComputeProcs[inTryExcept] := _TryExcept;
  FComputeProcs[inCallProc] := _CallProc;
  FComputeProcs[inCallClassProc] := _CallClassProc;
  FComputeProcs[inPushVarByRef] := _PushVarByRef;
  FComputeProcs[inBreakPoint] := _BreakPoint;
  FComputeProcs[inStoreVar] := _StoreVar;
  FComputeProcs[inStoreIdxVar] := _StoreIdxVar;
  FComputeProcs[inStoreVarInteger] := _StoreVarInteger;
  FComputeProcs[inStoreVarDouble] := _StoreVarDouble;
  FComputeProcs[inStoreVarString] := _StoreVarString;
  FComputeProcs[inStoreVarConst] := _StoreVarConst;
  FComputeProcs[inCopyVar] := _CopyVar;
  FComputeProcs[inStoreVarRef] := _StoreVarRef;
  FComputeProcs[inStoreIdxVarRef] := _StoreIdxVarRef;
  FComputeProcs[inStoreVarRefInteger] := _StoreVarRefInteger;
  FComputeProcs[inStoreVarRefDouble] := _StoreVarRefDouble;
  FComputeProcs[inStoreVarRefString] := _StoreVarRefString;
  FComputeProcs[inStoreVarRefConst] := _StoreVarRefConst;
  FComputeProcs[inCopyVarRef] := _CopyVarRef;
  FComputeProcs[inVarTest] := _VarTest;
  FComputeProcs[inVarTestInteger] := _VarTestInteger;
  FComputeProcs[inVarTestDouble] := _VarTestDouble;
  FComputeProcs[inVarTestString] := _VarTestString;
  FComputeProcs[inVarTestVar] := _VarTestVar;
  FComputeProcs[inAbort] := _Abort;
  FComputeProcs[inArrayOf] := _ArrayOf;
  FComputeProcs[inCastClass] := _CastClass;
  FComputeProcs[inWithObject] := _WithObject;
  FComputeProcs[inStoreGlobalVar] := _StoreGlobalVar;
  FComputeProcs[inStoreGlobalIdxVar] := _StoreGlobalIdxVar;
  FComputeProcs[inPushGlobalVar] := _PushGlobalVar;
  FComputeProcs[inPushGlobalIdxVar] := _PushGlobalIdxVar;
  FComputeProcs[inPushGlobalVarByRef] := _PushGlobalVarByRef;
  FComputeProcs[inGlobalPrepare] := _GlobalPrepare;
  FComputeProcs[inTestIfFalse] := _TestIfFalse;
  FComputeProcs[inTestIfTrue] := _TestIfTrue;
  FComputeProcs[inSaveStackValue] := _SaveStackValue;
  FComputeProcs[inLoadStackValue] := _LoadStackValue;
end;

destructor TatVirtualMachine.Destroy;
begin
  Clear;
  FDebugWatches.Free;
  FBreakPoints.Free;
  inherited;
end;

procedure TatVirtualMachine.Clear;
var
  c: integer;
begin
  { clear all runtime break points }
  FBreakPoints.Clear;

  // FDebugWatches.Reset; there is a bug here, correct it!
  FDebugStackLevel := 0;
  FRunning := false;
  FMainBegin := nil;
  FInitialized := false;
  FInTryExcept := 0;
  { clear all variable values, including globals }
  for c := StackSize - 1 downto 0 do
    FProcStack[c] := NullValue;
end;

{$IFDEF NEWSTACK}
function TatVirtualMachine.Execute(Input: array of const): TScriptValue;
begin
  Result := ExecuteSubroutine('', Input);
end;
{$ENDIF}

{$IFNDEF NEWSTACK}
function TatVirtualMachine.Execute(Input: Variant): Variant;
begin
  Result := ExecuteSubroutine('', Input);
end;
{$ENDIF}

procedure TatVirtualMachine.CheckAutoPause;
begin
  if FAutoPauseCurLine <> DebugExecutionLine then
  begin
    if FDebugStackLevel <= FMaxPauseStackLevel then
    begin
      FPaused := True;
      FAutoPause := false;
    end;
  end;
end;

procedure TatVirtualMachine.CheckHalted;
begin
  if FHalted then
    FatalError
      ('Script execution is being halted. A new execution can only start after the current execution finishes.');
end;

procedure TatVirtualMachine.InitializeScript(ADoBeforeExecute: boolean);
begin
  { do not initialize twice }
  if FInitialized then
  begin
    exit;
  end
  else
    with Script do
    begin
      { only initialize if scripter is compiled }
      if not FCompiled then
        exit;

      { do not initialize if script is already running }
      if Assigned(PrepareInstruction) then
        exit;

      { allows an external event to prepare scripter for execution }
      if ADoBeforeExecute then
        Scripter.BeforeExecute(self, '');
      CheckHalted;

      { check absolute addressing solving }
      if not FSolvedAddressing then
        SolveAbsoluteAddressing;

      { expand debug info }
      ExpandDebugInfo(false);

      FNextInstruction := nil;

      { *** script initialization *** }
      { execute all different instructions at the beginning of script, until the first iPrepare instruction }
      FCurrentInstruction := FFirstInstruction;
      while (FCurrentInstruction <> nil) and (FCurrentInstruction^.OpCode <> inPrepare) do
      begin
        FNextInstruction := FCurrentInstruction^.Next;
        FCurrentInstruction.Compute;
        FCurrentInstruction := FNextInstruction;
      end;
      FMainBegin := FCurrentInstruction;
      FInitialStackTop := FStackTop;
      FInitialized := True;
    end;
end;

function TatVirtualMachine.InternalExecuteSubroutine(AInstruction: pSimplifiedCode;
  AInputParamCount: integer = 0): TScriptValue;
var
  c: integer;
  outputParamCount: integer;
  dataSize: integer;
  oldNextInstruction: pSimplifiedCode;
  oldcurrent: TatScript;
  WasRunning: boolean;
begin

  { FStackTop and FStackProc should be previously initialized }
  CheckHalted;
  Result := NullValue;
  with Script do
  begin
    { save instruction state for reentrant calls }
    oldNextInstruction := FNextInstruction;

    { subroutine entry point checking }
    FCurrentInstruction := AInstruction;
    FNextInstruction := nil;
    if not Assigned(FCurrentInstruction) then
      exit;
    if not Assigned(FFirstInstruction) then
    begin
      Result := NullValue;
      exit;
    end;
    if FCurrentInstruction^.OpCode <> inPrepare then
      RuntimeError('Invalid subroutine call. Entry point should be a "Prepare" instruction');

    { Limpa variáveis de contexto da execução }
    FLastExceptionMessage := '';
    FLastExceptionHelpContext := 0;
    FLastExceptionClassName := '';
    FLastExceptionLine := 0;
    FLastExceptionCol := 0;
    // FHalted:=false;
    WasRunning := Script.Scripter.IsAnyRunning;
    FRunning := True;
    oldcurrent := self.Script.Scripter.FCurrentScript;
    self.Script.Scripter.FCurrentScript := self.Script;
    if not Assigned(PrepareInstruction) then // not reentrant call
    begin
      { allow user event to get notifications about running state }
      DoRunningChanged;
    end;
    try
      { gets the local variable data size from inPrepare instruction }
      dataSize := FCurrentInstruction^.vInteger;
      { runs the subroutine }
      outputParamCount := ExecProcess(AInputParamCount) - dataSize;
      { returns output arguments }
      if outputParamCount = 0 then
        Result := NullValue
      else
      if outputParamCount = 1 then
        Result := DerefValue(FProcStack[FStackTop + dataSize])
      else
      begin
        {$IFDEF NEWSTACK}
        RuntimeError('Subroutine cannot return more than 1 output parameter.');
        {$ELSE}
        Result := VarArrayCreate([0, outputParamCount - 1], varVariant);
        for c := 0 to outputParamCount - 1 do
          Result[c] := FProcStack[FStackTop + dataSize + c];
        {$ENDIF}
      end;
      { elimina os parâmetros entrada da função chamada }
      dec(FStackTop, AInputParamCount);
    finally
      if not Assigned(PrepareInstruction) then // not reentrant call
      begin
        FNextInstruction := nil;
        {$IFDEF MSWINDOWS}
        VarClear(FCurrentOleObject);
        {$ENDIF}
        FRunning := false;
        { allow user event to get notifications about running state }
        DoRunningChanged;
      end
      else
      { retrieve instruction state for reentrant calls }
      begin
        FNextInstruction := oldNextInstruction;
      end;
      self.Script.Scripter.FCurrentScript := oldcurrent;
      if not WasRunning then
        Paused := false;
    end;
  end;
  FHalted := false;
end;

function TatVirtualMachine.IntExecuteSubroutine(ALabel: string;
  const Input: array of TScriptValue): TScriptValue;
var
  c: integer;
  ParamCount: integer;
  _StackTop: integer;
begin
  with Script do
  begin
    { permite que um evento externo possa preparar o scripter para uma execução }
    Scripter.BeforeExecute(self, ALabel);

    CheckHalted;
    { se a variável PrepareInstruction estiver com algum valor então um script
      já está em execução, portanto esta chamada é re-entrante (não devendo
      interferir com a execução já disparada) }

    { verifica se o método compile já foi chamado, senão chama-o automaticamente }
    if not FCompiled then
      Compile;
    { verifica se o endereçamento absoluto já foi resolvido, senão resolve-o automaticamente }
    if not FSolvedAddressing then
      SolveAbsoluteAddressing;

    { Expand debug information }
    ExpandDebugInfo;

    if (ALabel > '') and (ScriptInfo.RoutineByName(ALabel) = nil) then
      RuntimeError(Format('Subroutine ''%s'' does not exist in script', [ALabel]));

//    _StackTop := 0;
    try
      if not Assigned(PrepareInstruction) then // not reentrat call
      begin
        { runtime stack initialization }
        for c := ScriptInfo.Globals.Count to StackSize - 1 do
          FProcStack[c] := NullValue;

        if not FInitialized then
        begin
         _StackTop := 0;
          FStackTop := 0;
          InitializeScript(false);
        end
        else
        begin
          _StackTop := FInitialStackTop; // review the _stacktop behavior compared to other ExecuteSubRoutine.
          FStackTop := FInitialStackTop;
          FNextInstruction := FMainBegin;
        end;
      end
      else
      begin
        { temos que dar uma posição de pilha livre para alterações (para frente)
          para o processo que vai ser chamado (ExecProcess).
          Para não interferir com a pilha do processo chamador vamos utilizar
          o ponteiro mais distante que temos (OutputBase) }
        _StackTop := FStackTop;
        FStackTop := FOutputBase;
      end;

      { load input arguments }
      ParamCount := High(Input) + 1;
      for c := 0 to ParamCount - 1 do
      begin
        // later we could check what values should be actually put as reference
        // by both checking the routine being called (to see which params are declared
        // as "var" params) and also by checking the Delphi input data type
        // (current only variants can have their values set back to the caller)
        FProcStack[FStackTop] := CreateReferenceValue(@Input[c]);
//        FProcStack[FStackTop].ScriptValue := Input[c]);
        Inc(FStackTop);
      end;

      { execute a subroutine or the main block }
      if ALabel > '' then
        Result := InternalExecuteSubroutine(EntryPoint(ALabel), ParamCount)
      else
        Result := InternalExecuteSubroutine(FMainBegin, ParamCount);

    finally
      { clear internal stack before return (dealocate variants) }
      if not Assigned(PrepareInstruction) then // not reentrant call
        for c := StackSize - 1 downto ScriptInfo.Globals.Count do
          FProcStack[c] := NullValue
      else
        { restore the stack-top of the process that was interrupted by this call }
        FStackTop := _StackTop;
    end;
  end;
  FHalted := false;
end;

function TatVirtualMachine.CreateFormRunScript(AForm: TComponent): TatScript;
var
  ABaseScript: TatScript;
  MS: TMemoryStream;
  AMachine: TatVirtualMachine;
  NewScript: TatScript;
begin
  AMachine := Self;
  ABaseScript := nil;

  { Retrieve initial information from the AMachine }
  if AMachine.Script.Scripter = nil then
    AMachine.RuntimeError('Cannot creat script form: Scripter property of machine is not specified.');
  if AMachine.CurrentClass <> nil then
    ABaseScript := AMachine.CurrentClass.FBaseScript
  else
    AMachine.RuntimeError('Cannot create script form: CurrentClass not specified.');
  if ABaseScript = nil then
    AMachine.RuntimeError('Cannot create script form: BaseScript not assigned.');

  { Add a new script in the scripter component }
  NewScript := AMachine.Script.Scripter.Scripts.Add;

  { We must copy source code from base script to NewScript, because we need debug information
    for breakpoints, etc. }
  NewScript.SourceCode.Text := ABaseScript.SourceCode.Text;

  { Uses the newly created form to be default instance so that methods and properties and objects
    are accessible just like in Delphi: "Edit1.Text" or "Show".
    OBS.: This script preparation must be done before the savecode/loadcode below, because
    when LoadCodeFromStream is caled, it automatically solves absolute addressing, and all default instances
    of new script must be the same as the base script }
  NewScript.UsesObject(AForm, '', ABaseScript.ScriptInfo.ScriptClassName);
  NewScript.AddObject('Self', AForm);

  { Copy compiled script code from base script to newly created script }
  MS := TMemoryStream.Create;
  try
    { Load the saved compiled code of script into the new script }
    ABaseScript.FCodeStream.Position := 0;
    NewScript.InternalLoadCodeFromStream(ABaseScript.FCodeStream, false);
    NewScript.ScriptInfo.Behavior := sbForm;

    { Adds the newly created NewScript to the script list in basescript, and also set basescript as
      "owner" of runscript. This is to keep references between the base and generated script, for breaks purpose,
      and also of course to keep pointers correct }
    NewScript.SetOriginalScript(ABaseScript);
    NewScript.FOriginalForm := AForm;
  finally
    MS.Free;
  end;
  NewScript.ScriptInfo.FormResource := ABaseScript.ScriptInfo.FormResource;
  Result := NewScript;
end;

{$IFNDEF NEWSTACK}
function TatVirtualMachine.ExecuteSubroutine(ALabel: string; Input: Variant): Variant;
var
  c: integer;
  InputParamCount: integer;
  outputParamCount: integer;
  dataSize: integer;
  oldNextInstruction: pSimplifiedCode;
  _StackTop: integer;
  oldcurrent: TatScript;
  WasRunning: boolean;
begin
  with Script do
  begin
    { permite que um evento externo possa preparar o scripter para uma execução }
    Scripter.BeforeExecute(self, ALabel);

    CheckHalted;

    { se a variável PrepareInstruction estiver com algum valor então um script
      já está em execução, portanto esta chamada é re-entrante (não devendo
      interferir com a execução já disparada) }

    { verifica se o método compile já foi chamado, senão chama-o automaticamente }
    if not FCompiled then
      Compile;
    { verifica se o endereçamento absoluto já foi resolvido, senão resolve-o automaticamente }
    if not FSolvedAddressing then
      SolveAbsoluteAddressing;

    { Expand debug information }
    ExpandDebugInfo;

    if (ALabel > '') and (ScriptInfo.RoutineByName(ALabel) = nil) then
      RuntimeError(Format('Subroutine ''%s'' does not exist in script', [ALabel]));

    { Limpa variáveis de contexto da execução }
    FLastExceptionMessage := '';
    FLastExceptionHelpContext := 0;
    FLastExceptionClassName := '';
    FLastExceptionLine := 0;
    FLastExceptionCol := 0;

    oldNextInstruction := FNextInstruction;

    // FHalted := False;
    WasRunning := Script.Scripter.IsAnyRunning;
    FRunning := True;
    oldcurrent := self.Script.Scripter.FCurrentScript;
    self.Script.Scripter.FCurrentScript := self.Script;
    if not Assigned(PrepareInstruction) then // not reentrat call
    begin
      { allow user event to get notifications about running state }
      DoRunningChanged;
      { runtime stack initialization }
      for c := ScriptInfo.Globals.Count to StackSize - 1 do
        FProcStack[c] := NullValue;

      if not FInitialized then
      begin
        _StackTop := 0;
        FStackTop := 0;
        InitializeScript(false);
      end
      else
      begin
        _StackTop := FInitialStackTop;
        FStackTop := FInitialStackTop;
        FNextInstruction := FMainBegin;
      end;
    end
    else
    begin
      { temos que dar uma posição de pilha livre para alterações (para frente)
        para o processo que vai ser chamado (ExecProcess).
        Para não interferir com a pilha do processo chamador vamos utilizar
        o ponteiro mais distante que temos (OutputBase) }
      _StackTop := FStackTop;
      FStackTop := FOutputBase;
    end;
    { preparação do ponteiro para a primeira instrução da rotina a ser executada }
    if ALabel > '' then
      FCurrentInstruction := EntryPoint(ALabel)
    else
      FCurrentInstruction := FMainBegin;
    if not Assigned(FCurrentInstruction) then
      exit;
    if not Assigned(FFirstInstruction) then
    begin
      Result := null;
      exit;
    end;
    if FCurrentInstruction^.OpCode <> inPrepare then
      RuntimeError('Invalid subroutine call. Entry point should be a "Prepare" instruction');

    try
      { load input arguments }
      if not VarIsNull(Input) then
      begin
        if VarIsArray(Input) then
        begin
          InputParamCount := VarArrayHighBound(Input, 1) + 1;
          for c := 0 to InputParamCount - 1 do
            FProcStack[FStackTop + c] := Input[c];
        end
        else
        begin
          InputParamCount := 1;
          FProcStack[FStackTop] := Input;
        end;
        Inc(FStackTop, InputParamCount)
      end
      else
        InputParamCount := 0;
      { gets the local variable data size from inPrepare instruction }
      dataSize := FCurrentInstruction^.vInteger;
      { runs the subroutine }
      outputParamCount := ExecProcess(InputParamCount) - dataSize;
      { returns output arguments }
      if outputParamCount = 0 then
        Result := null
      else if outputParamCount = 1 then
        Result := FProcStack[FStackTop + dataSize]
      else
      begin
        Result := VarArrayCreate([0, outputParamCount - 1], varVariant);
        for c := 0 to outputParamCount - 1 do
          Result[c] := FProcStack[FStackTop + dataSize + c];
      end;
      { elimina os parâmetros entrada da função chamada }
      dec(FStackTop, InputParamCount);
    finally
      if not Assigned(PrepareInstruction) then // not reentrant call
      begin
        FNextInstruction := nil;
        { limpa a pilha de variants usada pelo processo }
        for c := StackSize - 1 downto ScriptInfo.Globals.Count do
          VarClear(FProcStack[c]);
        {$IFDEF MSWINDOWS}
        VarClear(FCurrentOleObject);
        {$ENDIF}
        FRunning := false;
        { allow user event to get notifications about running state }
        DoRunningChanged;
      end
      else
      begin
        { retrieve instruction state for reentrant calls }
        FNextInstruction := oldNextInstruction;
        { restore the stack-top of the process that was interrupted by this call }
        FStackTop := _StackTop;
      end;
      if not WasRunning then
        Paused := false;
      self.Script.Scripter.FCurrentScript := oldcurrent;
    end;
  end;
  FHalted := false;
end;
{$ENDIF}

function TatVirtualMachine.ExecuteSubroutine(ALabel: string; Input: array of const): TScriptValue;
var
  Args: array of TScriptValue;
  I: integer;
begin
  SetLength(Args, Length(Input));

  for I := 0 to Length(Input) - 1 do
  begin
    {$IFDEF NEWSTACK}
    Args[I] := ScriptValueFromVarRec(Input[I]);
    {$ELSE}
    Args[I] := VariantFromVarRec(Input[I]);
    {$ENDIF}
  end;

  Result := IntExecuteSubroutine(ALabel, Args);

  // if const argument is a variant then we can update the value
  // so the caller can get the argument back. Useful when the subroutine
  // take var params
  for I := 0 to Length(Input) - 1 do
  begin
    if Input[I].VType = vtVariant then
      PVariant(Input[I].VVariant)^ :=
        {$IFDEF NEWSTACK}
        Args[I].AsVariant
        {$ELSE}
        Args[I]
        {$ENDIF}
      ;
  end;
end;

function TatVirtualMachine.ExecProcess(ParamCount: integer): integer;
var
  OldStackTop: integer;
  OldStackBase: integer;
  OldInputBase: integer;
  OldOutputBase: integer;
  OldInputOffset: integer;
  OldOutputOffset: integer;
  OldPrepareInstruction: pSimplifiedCode;
  OldCurrentInputArgBase: integer;
  OldCurrentArrayIndexBase: integer;
  OldCurrentOutputArgIndex: integer;
  ReturnInstruction: pSimplifiedCode;
begin
  Result := -1;
  try
    { preserva os apontadores do processo anterior }
    OldStackTop := FStackTop;
    OldStackBase := FStackBase;
    OldInputBase := FInputBase;
    OldOutputBase := FOutputBase;
    OldInputOffset := FInputOffset;
    OldOutputOffset := FOutputOffset;
    OldPrepareInstruction := FPrepareInstruction;
    OldCurrentInputArgBase := FCurrentInputArgBase;
    OldCurrentArrayIndexBase := FCurrentArrayIndexBase;
    OldCurrentOutputArgIndex := FCurrentOutputArgIndex;

    { salva endereço de retorno }
    ReturnInstruction := FNextInstruction;
    { posiciona apontadores para os parâmetros do processo }
    FInputBase := FStackTop - ParamCount;
    FInputOffset := 0;
    Inc(FDebugStackLevel);
    { posiciona o início das variáveis locais }
    FStackBase := FStackTop;
    try
      while FCurrentInstruction <> nil do
      begin
        FNextInstruction := FCurrentInstruction^.Next;
        FCurrentInstruction.Compute;
        if FAutoPause then
          CheckAutoPause;
        if FPaused then
          DoDebugHook;
        if FCallExecHookEvent then
          DoExecHook;
        FCurrentInstruction := FNextInstruction;
      end;
    finally
      if not FHalted then
        { executa a instrução subseqüente a chamada ao ExecProcess (call-ret) }
        FNextInstruction := ReturnInstruction;
      { retorna o número de argumentos de saída gerados nesta rotina }
      Result := FStackTop - OldStackTop;
      { restaura os apontadores do processo anterior }
      Dec(FDebugStackLevel);
      FPrepareInstruction := OldPrepareInstruction;
      FStackTop := OldStackTop;
      FStackBase := OldStackBase;
      FInputBase := OldInputBase;
      FOutputBase := OldOutputBase;
      FInputOffset := OldInputOffset;
      FOutputOffset := OldOutputOffset;
      FCurrentInputArgBase := OldCurrentInputArgBase;
      FCurrentArrayIndexBase := OldCurrentArrayIndexBase;
      FCurrentOutputArgIndex := OldCurrentOutputArgIndex;
    end;
  except
    on ex: Exception do
      if not HandleScriptRunException(ex) then
        raise;
  end;
end;

function TatVirtualMachine.GetScriptObjectClassName(AObject: TObject): string;
var
  FormIntf: IScriptBasedForm;
  TheRunScript: TatScript;
begin
  Result := '';
  if (AObject is TScriptBaseObject) and (TScriptBaseObject(AObject).RunScript <> nil) then
    Result := TScriptBaseObject(AObject).RunScript.ScriptInfo.ScriptClassName;
  if (Scripter.ScriptFormClass <> nil) and (AObject is Scripter.ScriptFormClass) then
  begin
    if not Supports(AObject, IScriptBasedForm, FormIntf) then
      RuntimeError('IScriptBasedForm not found in ScriptFormClass');
    TheRunScript := FormIntf.GetRunScript;
    if TheRunScript <> nil then
      Result := TheRunScript.ScriptInfo.ScriptClassName;
  end;
end;

function TatVirtualMachine.GetStackContentAsString: string;
var
  c, i: integer;
begin
  Result := '';
  if FStackTop > 4 then
    i := FStackTop - 4
  else
    i := 0;
  for c := FStackTop - 1 downto i do
    if Result > '' then
      Result := Result + ',' + ScriptValueContent(DerefValue(FProcStack[c]))
    else
      Result := ScriptValueContent(DerefValue(FProcStack[c]));
  if FStackTop > 4 then
    Result := Result + '...';
end;

function TatVirtualMachine.HandleScriptRunException(ex: Exception): boolean;
begin
  if FInTryExcept > 0 then
  begin
    Result := false;
    exit;
  end;
  { Atualiza o contexto da exceção para uso em runtime }
  FLastExceptionMessage := ex.Message;
  FLastExceptionHelpContext := ex.HelpContext;
  FLastExceptionClassName := ex.ClassName;
  if Assigned(FCurrentInstruction) then
    Script.GetRowColFromInst(FCurrentInstruction, FLastExceptionLine, FLastExceptionCol);
  { tratamento default para exceções }
  if (ex is EatScripterRuntime) or (ex is EAbort) then
    { exceções de runtime são apresentados como foram geradas }
    Result := false
  else
  begin
    Result := True;
    { outras exceções são apresentadas com informações sobre a execução }
    if Assigned(FCurrentInstruction) then
      with FCurrentInstruction^ do
        RuntimeError(Format('%s when evaluating instruction %s ($%X,$%X,$%X,$%X,''%s'').'#13#10 +
          'Stack content is: [%s]' + Script.ErrorComplement(vDebugInfo),
          [ex.Message, Copy(GetEnumName(TypeInfo(TInstruction), ord(OpCode)), 3, MaxInt), vInteger,
          vByte, vInteger2, vInteger3, vString, GetStackContentAsString]))
    else
      RuntimeError('Undefined instruction');
  end;
end;

function TatVirtualMachine.TranslateClass(AValue: TScriptValue): TClass;
{$IFDEF NEWSTACK}
begin
  Result := AValue.AsType<TatClass>.FClassRef
end;
{$ELSE}
begin
  {$WARNINGS OFF}
  Result := TatClass(VarToIntObject(AValue)).FClassRef
  {$WARNINGS ON}
end;
{$ENDIF}

{ --- debugging features --- }

procedure TatVirtualMachine.Halt;
begin
  { Provoca a finalização imediata do script, sem possibilidade de continuação }
  FCurrentInstruction := nil;
  FNextInstruction := nil;
  { Only set FHalted flag if script is running }
  FHalted := FRunning;
  Paused := false;
end;

function TatVirtualMachine.GetArrayIndex(ADim: integer): TScriptValue;
begin
  Result := DerefValue(FProcStack[FCurrentArrayIndexBase + ADim]);
end;

function TatVirtualMachine.GetArrayIndexAsInteger(ADim: integer): integer;
begin
  { retorna o valor do índice de entrada correspondente a dimensão dada }
  Result := ScriptValueAsInteger(GetArrayIndex(ADim));
end;

function TatVirtualMachine.GetArrayIndexAsString(ADim: integer): string;
begin
  { retorna o valor do índice de entrada correspondente a dimensão dada }
  Result := ScriptValueAsString(GetArrayIndex(ADim));
end;

function TatVirtualMachine.GetCurrentClass: TatClass;
begin
  Result := FCurrentClass;
  if FCurrentClass = nil then
    if CurrentObject <> nil then
      Result := Script.Scripter.Classes.ClassByName(CurrentObject.ClassName);
end;

function TatVirtualMachine.InputArgCount: integer;
begin
  Result := FCurrentInstruction^.vByte;
end;

function TatVirtualMachine.GetInputArg(AIndex: integer): TScriptValue;
begin
  Result := DerefValue(FProcStack[FCurrentInputArgBase + AIndex]);
end;

function TatVirtualMachine.GetInputArgAsString(AIndex: integer): string;
begin
  Result := ScriptValueAsString(DerefValue(FProcStack[FCurrentInputArgBase + AIndex]));
end;

function TatVirtualMachine.GetInputArgAsVariant(AIndex: integer): Variant;
begin
  Result := ToVariant(GetInputArg(AIndex));
end;

function TatVirtualMachine.GetInputArgAsClass(AIndex: integer): TClass;
begin
  Result := TranslateClass(DerefValue(FProcStack[FCurrentInputArgBase + AIndex]));
end;

{$IFNDEF NEXTGEN}
function TatVirtualMachine.GetInputArgAsWideString(AIndex: integer): Widestring;
begin
  {$IFDEF DELPHI7_LVL}
  with TVarData(FProcStack[FCurrentInputArgBase + AIndex]) do
    if VType and varByRef = 0 then
      Result := VarToWideStr(FProcStack[FCurrentInputArgBase + AIndex])
    else
      Result := VarToWideStr(Variant(vPointer^));
  {$ELSE}
  Result := GetInputArgAsString(AIndex);
  {$ENDIF}
end;
{$ENDIF}

function TatVirtualMachine.GetInputArgAsInt64(AIndex: integer): Int64;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FCurrentInputArgBase + AIndex]);
  {$IFDEF NEWSTACK}
  Result := Value.AsInt64;
  {$ELSE}
  Result := VarToInt64(Value);
  {$ENDIF}
end;

function TatVirtualMachine.GetInputArgAsInteger(AIndex: integer): integer;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FCurrentInputArgBase + AIndex]);
  {$IFDEF NEWSTACK}
  Result := Value.AsInteger;
  {$ELSE}
  Result := VarToInteger(Value);
  {$ENDIF}
end;

function TatVirtualMachine.GetInputArgAsObject(AIndex: integer): TObject;
begin
  Result := VarToObject(DerefValue(FProcStack[FCurrentInputArgBase + AIndex]));
end;

function TatVirtualMachine.GetInputArgAsChar(AIndex: integer): char;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FCurrentInputArgBase + AIndex]);
  {$IFDEF NEWSTACK}
  Result := Value.AsType<Char>;
  {$ELSE}
  Result := VarToChar(Value);
  {$ENDIF}
end;

function TatVirtualMachine.GetInputArgAsWideChar(AIndex: integer): WideChar;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FCurrentInputArgBase + AIndex]);
  {$IFDEF NEWSTACK}
  Result := Value.AsType<WideChar>;
  {$ELSE}
  Result := VarToWideChar(Value);
  {$ENDIF}
end;

function TatVirtualMachine.GetInputArgAsBoolean(AIndex: integer): boolean;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FCurrentInputArgBase + AIndex]);
  {$IFDEF NEWSTACK}
  Result := Value.AsBoolean;
  {$ELSE}
  Result := VarToInteger(Value) <> 0;
  {$ENDIF}
end;

function TatVirtualMachine.GetInputArgAsFloat(AIndex: integer): double;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FCurrentInputArgBase + AIndex]);
  {$IFDEF NEWSTACK}
  Result := Value.AsExtended;
  {$ELSE}
  Result := VarToFloat(Value);
  {$ENDIF}
end;

function TatVirtualMachine.GetInputArgAsDateTime(AIndex: integer): TDateTime;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FCurrentInputArgBase + AIndex]);
  {$IFDEF NEWSTACK}
  Result := Value.AsType<TDateTime>;
  {$ELSE}
  Result := VarToDateTime(Value);
  {$ENDIF}
end;

procedure TatVirtualMachine.ReturnOutputArg(AValue: TScriptValue);
begin
  { grava o valor do parâmentro indicado por AValue como retorno da subrotina corrente }
  FProcStack[FOutputBase] := AValue;
end;

procedure TatVirtualMachine.ReturnOutputArgAsVariant(AValue: Variant);
begin
  {$IFDEF NEWSTACK}
  ReturnOutputArg(TValue.From<Variant>(AValue));
  {$ELSE}
  ReturnOutputArg(AValue);
  {$ENDIF}
end;

{$IFDEF DELPHI2010_LVL}
procedure TatVirtualMachine.ReturnOutputArgValue(AValue: TValue);
{$IFDEF NEWSTACK}
begin
  ReturnOutputArg(AValue);
end;
{$ELSE}
var
  recWrapper: TGenericRecordWrapper;
begin
  if AValue.IsObject then
    ReturnOutputArg(ObjectToVar(AValue.AsObject))
  else if AValue.Kind = TypInfo.tkRecord then
  begin
    recWrapper := TGenericRecordWrapper.Create(AValue);
    ReturnOutputArg(ObjectToVar(recWrapper));
  end
  else if AValue.TypeInfo = TypeInfo(boolean) then
    ReturnOutputArg(AValue.AsBoolean)
  else if AValue.IsOrdinal then
    ReturnOutputArg(AValue.AsOrdinal)
  else
    ReturnOutputArg(AValue.AsVariant);
end;
{$ENDIF}
{$ENDIF}

procedure TatVirtualMachine.SetInputArgIfByRef(AIndex: integer; const AValue: TScriptValue);
var
  Ref: TStackValue;
begin
  Ref := FProcStack[FCurrentInputArgBase + AIndex];

  // Set AValue in the input parameter specified by AIndex.
  // if value is passed by reference, then change the content of reference
  // otherwise does nothing
  if IsReference(Ref) then
    SetRefValue(Ref, AValue);
end;

{$IFDEF DELPHI2010_LVL}
procedure TatVirtualMachine.SetInputArgValue(AIndex: integer; const AValue: TValue);
begin
  {$IFDEF NEWSTACK}
  SetInputArg(AIndex, AValue);
  {$ELSE}
  if AValue.IsObject then
    SetInputArg(AIndex, ObjectToVar(AValue.AsObject))
  else if AValue.IsType<integer> then
    SetInputArg(AIndex, AValue.AsInteger)
  else if AValue.IsOrdinal then
    SetInputArg(AIndex, AValue.AsOrdinal)
  else
    SetInputArg(AIndex, AValue.AsVariant);
  {$ENDIF}
end;
{$ENDIF}

{$IFNDEF NEWSTACK}
function TatCustomScripter.ExecuteSubroutine(ALabel: string; Input: Variant): Variant;
var
  AMachine: TatVirtualMachine;
begin
  if (Length(ALabel) > 0) and (ALabel[1] = '[') then
  begin
    GetInfoFromRoutineName(ALabel, AMachine);
    if AMachine <> nil then
      Result := AMachine.ExecuteSubroutine(ALabel, Input);
  end
  else if Assigned(FCurrentScript.VirtualMachine) then
    Result := FCurrentScript.VirtualMachine.ExecuteSubroutine(ALabel, Input);
end;
{$ENDIF}

function TatCustomScripter.ExecuteSubroutine(ALabel: string): TScriptValue;
var
  AMachine: TatVirtualMachine;
begin
  if (Length(ALabel) > 0) and (ALabel[1] = '[') then
  begin
    GetInfoFromRoutineName(ALabel, AMachine);
    if AMachine <> nil then
      Result := AMachine.ExecuteSubroutine(ALabel);
  end
  else if Assigned(FCurrentScript.VirtualMachine) then
    Result := FCurrentScript.VirtualMachine.ExecuteSubroutine(ALabel);
end;

function TatCustomScripter.ExecuteSubroutine(ALabel: string; Input: array of const): TScriptValue;
var
  AMachine: TatVirtualMachine;
begin
  if (Length(ALabel) > 0) and (ALabel[1] = '[') then
  begin
    GetInfoFromRoutineName(ALabel, AMachine);
    if AMachine <> nil then
      Result := AMachine.ExecuteSubroutine(ALabel, Input);
  end
  else if Assigned(FCurrentScript.VirtualMachine) then
    Result := FCurrentScript.VirtualMachine.ExecuteSubroutine(ALabel, Input);
end;

function TatCustomScripter.ExecuteSubroutineAsVariant(ALabel: string): Variant;
begin
  {$IFDEF NEWSTACK}
  Result := ExecuteSubroutine(ALabel).AsVariant;
  {$ELSE}
  Result := ExecuteSubroutine(ALabel);
  {$ENDIF}
end;

function TatCustomScripter.ExecuteSubroutineAsVariant(ALabel: string;
  Input: array of const): Variant;
begin
  {$IFDEF NEWSTACK}
  Result := ExecuteSubroutine(ALabel, Input).AsVariant;
  {$ELSE}
  Result := ExecuteSubroutine(ALabel, Input);
  {$ENDIF}
end;

procedure TatCustomScripter.GetInfoFromRoutineName(var RName: string;
  var AMachine: TatVirtualMachine);
var
  AScript: TatScript;
  p: integer;
begin
  { for speed purposes, consider that the routinename is already in format "[1234123]RoutineName" }
  p := pos(']', RName);
  AScript := TatScript(StrToInt(Copy(RName, 2, p - 2)));
  RName := Copy(RName, p + 1, MaxInt);
  if AScript <> nil then
    AMachine := AScript.VirtualMachine
  else
    AMachine := nil;
end;

function TatScript._FindClass(idx: integer; AName: string): TatClass;
var
  i1: integer;
  i2: integer;
begin
  Result := nil;
  if (idx >= 0) and (idx < Scripter.FClasses.Count) and SameText(Scripter.FClasses[idx].Name, AName)
  then
    Result := Scripter.FClasses[idx]
  else
  begin
    i1 := idx - 1;
    i2 := idx + 1;
    while (Result = nil) and ((i1 >= 0) or (i2 < Scripter.FClasses.Count)) do
    begin
      if (i1 >= 0) and (i1 < Scripter.FClasses.Count) then
        if SameText(Scripter.FClasses[i1].Name, AName) then
          Result := Scripter.FClasses[i1];
      if (i2 >= 0) and (i2 < Scripter.FClasses.Count) then
        if SameText(Scripter.FClasses[i2].Name, AName) then
          Result := Scripter.FClasses[i2];
      dec(i1);
      Inc(i2);
    end;
  end;
  if Result = nil then
    RuntimeError(Format('Error in loaded compiled code: Class "%s" not registered', [AName]));
end;

function TatScript._FindMethod(AClass: TatClass; idx: integer; AName: string): TatMethod;
var
  i1, i2: integer;
begin
  Result := nil;
  if (idx >= 0) and (idx < AClass.Methods.Count) and SameText(AClass.Methods[idx].Name, AName) then
    Result := AClass.Methods[idx]
  else
  begin
    i1 := idx - 1;
    i2 := idx + 1;
    while (Result = nil) and ((i1 >= 0) or (i2 < AClass.Methods.Count)) do
    begin
      if i1 >= 0 then
        if SameText(AClass.Methods[i1].Name, AName) then
          Result := AClass.Methods[i1];
      if i2 < AClass.Methods.Count then
        if SameText(AClass.Methods[i2].Name, AName) then
          Result := AClass.Methods[i2];
      dec(i1);
      Inc(i2);
    end;
  end;
  if Result = nil then
    RuntimeError(Format('Error in loaded compiled code: Method "%s.%s" not registered',
      [AClass.Name, AName]));
end;

function TatScript._FindProperty(AClass: TatClass; idx: integer; AName: string): TatProperty;
var
  i1, i2: integer;
begin
  Result := nil;
  if (idx >= 0) and (idx < AClass.Properties.Count) and SameText(AClass.Properties[idx].Name, AName)
  then
    Result := AClass.Properties[idx]
  else
  begin
    i1 := idx - 1;
    i2 := idx + 1;
    while (Result = nil) and ((i1 >= 0) or (i2 < AClass.Properties.Count)) do
    begin
      if (i1 >= 0) and (i1 < AClass.Properties.Count) then
        if SameText(AClass.Properties[i1].Name, AName) then
          Result := AClass.Properties[i1];
      if i2 < AClass.Properties.Count then
        if SameText(AClass.Properties[i2].Name, AName) then
          Result := AClass.Properties[i2];
      dec(i1);
      Inc(i2);
    end;
  end;

  if Result = nil then
    RuntimeError(Format('Error in loaded compiled code: Property "%s.%s" not registered',
      [AClass.Name, AName]));
end;

function TatVirtualMachine.ScripterDoDebugHook: boolean;
begin
  Result := Script.Scripter.DoDebugHook(self);
end;

procedure TatVirtualMachine.ScripterSingleDebugHook;
begin
  Script.Scripter.SingleDebugHook(self);
end;

procedure TatVirtualMachine.SetInputArg(AIndex: integer; const AValue: TScriptValue);
var
  Ref: TStackValue;
begin
  Ref := FProcStack[FCurrentInputArgBase + AIndex];

  // Set AValue in the input parameter specified by AIndex.
  // if value is passed by reference, then change the content of reference
  // otherwise does nothing
  if IsReference(Ref) then
    SetRefValue(Ref, AValue)
  else
    RuntimeError(Format('Method expects argument %d as variable reference', [AIndex]))
end;

function TatVirtualMachine.InstructionByLine(ARow: integer): pSimplifiedCode;
begin
  { varre as instruções compiladas para encontrar a primeira instrução
    correspondente a linha do programa-fonte indicada }
  Result := Script.FFirstInstruction;
  while Result <> nil do
  begin
    if (ARow = Result^.vDebugInfo and $FFFFF) then
      exit;
    Result := Result^.Next;
  end;
  Result := nil;
end;

function TatVirtualMachine.EntryPoint(ALabel: string): pSimplifiedCode;
begin
  { search instructions to find routine name
    (*** would be better if search by RoutineInfo -> future ***) }

  Result := Script.FFirstInstruction;
  { search subroutine start instruction (inPrepare) }
  while Assigned(Result) and ((Result^.OpCode <> inPrepare) or
    (CompareText(Result^.vString, ALabel) <> 0)) do
    Result := Result^.Next;

  { se não encontrou a subrotina então gera uma exceção de runtime }
  if not Assigned(Result) then
    RuntimeError(Format('Subroutine ''%s'' does not exist in script', [ALabel]));
end;

procedure TatVirtualMachine.DebugTraceInto;
begin
  { continua a execução do script em modo pausado }
  if FPaused then
  begin
    FCurrentInstruction := FNextInstruction;
    if FCurrentInstruction <> nil then
    begin
      FNextInstruction := FCurrentInstruction^.Next;
      FCurrentInstruction.Compute;
    end
    else
      Paused := false;
  end;
  Script.Scripter.SingleDebugHook(self);
end;

procedure TatVirtualMachine.DebugStepOver;
begin
  { executa apenas uma instrução sem pausa }
  if FPaused then
  begin
    Paused := false;
    FCurrentInstruction := FNextInstruction;
    if FCurrentInstruction <> nil then
    begin
      FNextInstruction := FCurrentInstruction^.Next;
      FCurrentInstruction.Compute;
      Paused := True;
    end
    else
      Paused := false;
  end;
  Script.Scripter.SingleDebugHook(self);
end;

procedure TatVirtualMachine.DebugTraceIntoLine;
begin
  if FPaused then
  begin
    FAutoPause := True;
    FAutoPauseCurLine := DebugExecutionLine;
    FMaxPauseStackLevel := MaxInt;
    FPaused := false;
  end;
  Script.Scripter.SingleDebugHook(self);
end;

procedure TatVirtualMachine.DebugStepOverLine;
begin
  if FPaused then
  begin
    FAutoPause := True;
    FAutoPauseCurLine := DebugExecutionLine;
    FMaxPauseStackLevel := FDebugStackLevel;
    FPaused := false;
  end;
  Script.Scripter.SingleDebugHook(self);
end;

procedure TatVirtualMachine.DebugRunUntilReturn;
begin
  if FPaused then
  begin
    FAutoPause := True;
    FAutoPauseCurLine := DebugExecutionLine;
    FMaxPauseStackLevel := FDebugStackLevel - 1;
    FPaused := false;
  end;
  Script.Scripter.SingleDebugHook(self);
end;

procedure TatVirtualMachine.DebugRunToPoint(AInstruction: pSimplifiedCode);
begin
  { insere uma paralização auto-destrutível na linha indicada }
  FBreakPoints.InsertTempBreak(AInstruction);
  Paused := false;
  Script.Scripter.Running := True;
  Script.Scripter.SingleDebugHook(self);
end;

procedure TatVirtualMachine.DebugRunToLine(ALine: integer);
begin
  { insere uma paralização auto-destrutível na linha indicada }
  with Script.Breaks.Add do
  begin
    Line := ALine;
    FAutoDestroy := True;
  end;
  Paused := false;
  Script.Scripter.Running := True;
  Script.Scripter.SingleDebugHook(self);
end;

function TatVirtualMachine.DebugToggleBreakPoint(AInstruction: pSimplifiedCode): boolean;
begin
  if Assigned(AInstruction) then
  begin
    { se a instrução já for um break point então a remove, senão a define como break }
    Result := FBreakPoints.RemoveBreakPoint(AInstruction);
    if not Result then
      FBreakPoints.InsertNormalBreak(AInstruction);
  end
  else
    Result := false;
end;

function TatVirtualMachine.DebugToggleBreakLine(ALine: integer): pSimplifiedCode;
begin
  Result := InstructionByLine(ALine);
  DebugToggleBreakPoint(Result);
end;

procedure TatVirtualMachine.DoExecHook;
begin
  if Assigned(FOnExecHook) then
    FOnExecHook(self);
end;

function TatVirtualMachine.DebugExecutionLine: integer;
begin
  if Assigned(FNextInstruction) then
    Result := FNextInstruction^.vDebugInfo and $FFFFF
  else
    Result := -1;
end;

procedure TatVirtualMachine.SetRunning(const Value: boolean);
begin
  { Controla a execução do script }
  if FRunning <> Value then
  begin
    if Value then
      Execute
    else
      Halt;
  end;
end;

procedure TatVirtualMachine.SetPaused(const Value: boolean);
begin
  if FPaused <> Value then
  begin
    { Set this machine, and all other machines to the specified paused value }
    FPaused := Value;
    Script.Scripter.SetPaused(Value);
    if Assigned(FOnPauseChanged) then
      FOnPauseChanged(self);
  end;
end;

{ ----------------------------------------------------------------------------- }
{ Funções da semântica do compilador (pseudo-código de máquina) }
{ Implementação das instruções do SimplifiedCode }
{ ----------------------------------------------------------------------------- }

procedure TatVirtualMachine._Prepare;
var
  c: integer;
begin
  { allocate space in the stack for all local variables of current process }
  FStackTop := FStackTop + FCurrentInstruction^.vInteger;

  { initialize local variables to null }
  for c := FStackTop - FCurrentInstruction^.vInteger to FStackTop - 1 do
    FProcStack[c] := NullValue;

  { atualiza o apontador da primeira instrução do processo corrente (inPrepare) }
  FPrepareInstruction := FCurrentInstruction;
end;

procedure TatVirtualMachine._GlobalPrepare;
begin
  { aloca espaço no FStack para todas as variáveis globais do processo corrente }
  FStackTop := FStackTop + FCurrentInstruction^.vInteger;
end;

procedure TatVirtualMachine._PushDouble;
begin
  { empilha um número real no FStack }
  FProcStack[FStackTop] := DoubleToScriptValue(FCurrentInstruction^.vDouble);
  Inc(FStackTop);
end;

procedure TatVirtualMachine._PushVar;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger]);
  FProcStack[FStackTop] := Value;
  Inc(FStackTop);
end;

procedure TatVirtualMachine._PushIdxVar;
var
  Value: TScriptValue;
begin
  Value := DerefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger]);

  { push the indexed element of variable }
  with FCurrentInstruction^ do
  begin
    dec(FStackTop, vByte);
    FProcStack[FStackTop] := GetScriptArrayElement(Value, 1);
    Inc(FStackTop);
  end;
end;

procedure TatVirtualMachine._PushVarByRef;
begin
  { push a reference to the variable in the stack }
  FProcStack[FStackTop] := CreateReferenceValue(
    {$IFDEF NEWSTACK}
    @(FProcStack[FStackBase + FCurrentInstruction^.vInteger].RawValue));
    {$ELSE}
    @(FProcStack[FStackBase + FCurrentInstruction^.vInteger]));
    {$ENDIF}

//  TVarData(FProcStack[FStackTop]).VType := varVariant or varByRef;
//  with TVarData(FProcStack[FStackBase + FCurrentInstruction^.vInteger]) do
//    if VType and varByRef = 0 then
//      TVarData(FProcStack[FStackTop]).vPointer :=
//        @FProcStack[FStackBase + FCurrentInstruction^.vInteger]
//    else
//      TVarData(FProcStack[FStackTop]).vPointer := vPointer;

  Inc(FStackTop);
end;

procedure TatVirtualMachine._PushString;
begin
  { empilha uma string no FStack }
  FProcStack[FStackTop] := StringToScriptValue(FCurrentInstruction^.vString);
  Inc(FStackTop);
end;

procedure TatVirtualMachine._PushConst;
begin
  { empilha uma string no FStack }
  case CORE_CONST(FCurrentInstruction^.vByte) of
    coNull:
      FProcStack[FStackTop] := NullValue;
    coTrue:
      FProcStack[FStackTop] := BoolToScriptValue(True);
    coFalse:
      FProcStack[FStackTop] := BoolToScriptValue(False);
    coUnassigned:
      {$IFDEF NEWSTACK}
      FProcStack[FStackTop] := NullValue;
      {$ELSE}
      FProcStack[FStackTop] := Unassigned;
      {$ENDIF}
    coNil:
      {$IFDEF NEWSTACK}
      FProcStack[FStackTop] := NullValue;
      {$ELSE}
      FProcStack[FStackTop] := 0;
      {$ENDIF}
  end;
  Inc(FStackTop);
end;

procedure TatVirtualMachine._PushOutput;
begin
  { empilha o valor do parâmentro de saída do processo chamado }
  FProcStack[FStackTop] := FProcStack[FOutputBase + FCurrentInstruction^.vInteger];
  Inc(FStackTop);
end;

procedure TatVirtualMachine._PushClass;
begin
  with Script, FCurrentInstruction^ do
  begin
    { solve class reference at runtime using name, if not solved yet }
    {$IFDEF NEWSTACK}
    if vObj = nil then
    begin
      vObj := Scripter.Classes.ClassByName(vString);
      if vObj = nil then
        RuntimeError(Format('Invalid class reference ''%s''' + Script.ErrorComplement(vDebugInfo),
          [vString]));
    end;
    FProcStack[FStackTop] := ObjectToVar(vObj);
    {$ELSE}
    if vPointer = 0 then
    begin
      vPointer := ObjectToVar(Scripter.Classes.ClassByName(vString));
      if vPointer <= 0 then
        RuntimeError(Format('Invalid class reference ''%s''' + Script.ErrorComplement(vDebugInfo),
          [vString]));
    end;
    FProcStack[FStackTop] := vPointer;
    {$ENDIF}
  end;
  Inc(FStackTop);
end;

procedure TatVirtualMachine._Duplicate; // obsolete
begin
  { duplica o topo do FStack }
  FProcStack[FStackTop] := FProcStack[FStackTop - 1];
  Inc(FStackTop);
end;

procedure TatVirtualMachine._Duplicate2; // obsolete
begin
  { duplica os dois valores de topo do FStack }
  FProcStack[FStackTop] := FProcStack[FStackTop - 2];
  FProcStack[FStackTop + 1] := FProcStack[FStackTop - 1];
  Inc(FStackTop, 2);
end;

procedure TatVirtualMachine._Drop2; // obsolete
begin
  { elimina os dois valores de topo do FStack }
  dec(FStackTop, 2);
end;

procedure TatVirtualMachine._Swap;
var
  aux: TStackValue;
begin
  { troca os dois valore de topo do FStack }
  aux := FProcStack[FStackTop - 1];
  FProcStack[FStackTop - 1] := FProcStack[FStackTop - 2];
  FProcStack[FStackTop - 2] := aux;
end;

procedure TatVirtualMachine._OperNE;
begin
  FProcStack[FStackTop - 2] :=
    BoolToScriptValue(
      not ScriptValueEqual(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperGE;
begin
  FProcStack[FStackTop - 2] :=
    BoolToScriptValue(
      ScriptValueGreaterOrEqual(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))

    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperLE;
begin
  FProcStack[FStackTop - 2] :=
    BoolToScriptValue(
      ScriptValueLessOrEqual(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperEqual;
begin
  FProcStack[FStackTop - 2] :=
    BoolToScriptValue(
      ScriptValueEqual(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperGreater;
begin
  FProcStack[FStackTop - 2] :=
    BoolToScriptValue(
      ScriptValueGreater(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperLess;
begin
  FProcStack[FStackTop - 2] :=
    BoolToScriptValue(
      ScriptValueLess(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperAdd;
begin
  { soma o primeiro parâmetro com o segundo no FStack devolvendo o resultado no topo }
  FProcStack[FStackTop - 2] :=
    ScriptValueAdd(
      DerefValue(FProcStack[FStackTop - 2]),
      DerefValue(FProcStack[FStackTop - 1]));
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperConcat;
begin
  { soma o primeiro parâmetro com o segundo no FStack devolvendo o resultado no topo }
  FProcStack[FStackTop - 2] :=
    StringToScriptValue(
      ScriptValueConcat(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperSub;
begin
  FProcStack[FStackTop - 2] :=
    ScriptValueSubtract(
      DerefValue(FProcStack[FStackTop - 2]),
      DerefValue(FProcStack[FStackTop - 1]));
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperOr;
begin
  FProcStack[FStackTop - 2] :=
    IntToScriptValue(
      ScriptValueOr(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperXor;
begin
  FProcStack[FStackTop - 2] :=
    IntToScriptValue(
      ScriptValueXor(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperAnd;
begin
  FProcStack[FStackTop - 2] :=
    IntToScriptValue(
      ScriptValueAnd(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperShl;
begin
  FProcStack[FStackTop - 2] :=
    IntToScriptValue(
      ScriptValueShl(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperShr;
begin
  FProcStack[FStackTop - 2] :=
    IntToScriptValue(
      ScriptValueShr(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperMul;
begin
  FProcStack[FStackTop - 2] :=
    ScriptValueMultiply(
      DerefValue(FProcStack[FStackTop - 2]),
      DerefValue(FProcStack[FStackTop - 1]));
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperSlash;
begin
  FProcStack[FStackTop - 2] :=
    ScriptValueDivide(
      DerefValue(FProcStack[FStackTop - 2]),
      DerefValue(FProcStack[FStackTop - 1]));
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperDiv;
begin
  FProcStack[FStackTop - 2] :=
    IntToScriptValue(
      ScriptValueDiv(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperMod;
begin
  FProcStack[FStackTop - 2] :=
    IntToScriptValue(
      ScriptValueMod(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperExp;
begin
  FProcStack[FStackTop - 2] :=
    DoubleToScriptValue(
      ScriptValueExp(
        DerefValue(FProcStack[FStackTop - 2]),
        DerefValue(FProcStack[FStackTop - 1]))
    );
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperIs;
var
  obj: TObject;
begin
  obj := VarToObject(DerefValue(FProcStack[FStackTop - 2]));
  if Assigned(obj) then
    FProcStack[FStackTop - 2] :=
      BoolToScriptValue(
        obj.InheritsFrom(TranslateClass(DerefValue(FProcStack[FStackTop - 1])))
      )
  else
    { nil object always returns False }
    FProcStack[FStackTop - 2] := BoolToScriptValue(false);
  dec(FStackTop);
end;

procedure TatVirtualMachine._OperNeg;
begin
  { realiza a operação de troca de sinal no topo do FStack }
  FProcStack[FStackTop - 1] :=
    ScriptValueNeg(DerefValue(FProcStack[FStackTop - 1]));
end;

procedure TatVirtualMachine._OperNot;
begin
  { realiza a operação lógica NOT no topo do FStack }
  FProcStack[FStackTop - 1] :=
    BoolToScriptValue(ScriptValueNot(DerefValue(FProcStack[FStackTop - 1])));

  { Code below commented by wagner on 20-Jan-2003 }
  // FProcStack[FStackTop-1]:=integer(not Round(FProcStack[FStackTop-1]));
end;

procedure TatVirtualMachine._JumpIfFalse;
begin
  if not ScriptValueAsBool(DerefValue(FProcStack[FStackTop - 1])) then
    {$IFDEF NEWSTACK}
    FNextInstruction := FCurrentInstruction^.vInst;
    {$ELSE}
    FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
    {$ENDIF}
  dec(FStackTop);
end;

procedure TatVirtualMachine._JumpIfTrue;
begin
  if ScriptValueAsBool(DerefValue(FProcStack[FStackTop - 1])) then
    {$IFDEF NEWSTACK}
    FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vInst);
    {$ELSE}
    FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
    {$ENDIF}
  dec(FStackTop);
end;

procedure TatVirtualMachine._LoadStackValue;
var
  Count: integer;
  I: integer;
begin
  Count := FCurrentInstruction^.vInteger;
  for I := 0 to Count - 1 do
  begin
  FProcStack[FStackTop] := FTempStack[FTempStackTop - 1];
  Inc(FStackTop);
  dec(FTempStackTop);
  end;
end;

procedure TatVirtualMachine._Jump;
begin
  {$IFDEF NEWSTACK}
  FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vInst);
  {$ELSE}
  FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
  {$ENDIF}
end;

procedure TatVirtualMachine._StoreVar;
begin
  { armazena o valor do topo do FStack na variável }
  FProcStack[FStackBase + FCurrentInstruction^.vInteger] := FProcStack[FStackTop - 1];

  // para gravar dados em uma variável que é por referência
  // with TVarData(FProcStack[FStackBase+FCurrentInstruction^.vInteger]) do
  // if VType and varByRef=0 then
  // FProcStack[FStackBase+FCurrentInstruction^.vInteger]:=FProcStack[FStackTop-1]
  // else
  // PVariant(VPointer)^:=FProcStack[FStackTop-1];

  dec(FStackTop);
end;

procedure TatVirtualMachine._StoreVarRef;
begin
  if IsReference(FProcStack[FStackBase + FCurrentInstruction^.vInteger]) then
    SetRefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger], DerefValue(FProcStack[FStackTop - 1]))
  else
    FProcStack[FStackBase + FCurrentInstruction^.vInteger] := DerefValue(FProcStack[FStackTop - 1]);
  dec(FStackTop);
end;

function TatVirtualMachine.SetVariantArrayElement(v: Variant; ADim: integer; AValue: Variant): Variant;

  function _IndexValue(Idx: integer): integer;
  begin
    {$IFDEF NEWSTACK}
    Result := DerefValue(FProcStack[FStackTop + ADim + Idx]).AsInteger;
    {$ELSE}
    Result := FProcStack[FStackTop + ADim + Idx];
    {$ENDIF}
  end;

var
  s: string;
  i, vardim: integer;
  varClass: TatClass;
  Error: boolean;
  Indices: array of integer;
  vSub: Variant;
begin
  with FCurrentInstruction^ do
    { allow changing string chars by index }
    if not VarIsArray(v) and ((VarType(v) = varString)
      {$IFDEF DELPHI2009_LVL}
      or (VarType(v) = varUString)
      {$ENDIF}
      or (VarType(v) = varOleStr)) then
      if ADim = vByte then
      begin
        i := _IndexValue(0);
        s := v;
        Delete(s, i, 1);
        Insert(AValue, s, i);
        v := s;
      end
      else
        RuntimeError('String variable has only one dimension')
    else
      { arrays podem ser acessados multi-dimensionalmente }
      if VarIsArray(v) then
      begin
        vardim := VarArrayDimCount(v);
        SetLength(Indices, vardim);
        for I := 0 to vardim - 1 do
          Indices[I] := _IndexValue(I);
        if ADim + vardim - 1 = vByte then
          VarArrayPut(v, AValue, Indices)
        else
        begin
          VSub := VarArrayGet(V, Indices);
          VarArrayPut(v, SetVariantArrayElement(VSub, ADim + vardim, AValue), Indices);
        end;
      end
      else
      begin
        // check if the variable is an object with default indexed property
        Error := True;
        if VarIsType(v, [varInteger]) then
        begin
          // warning: this cast to TObject is a workaround to try to determine if a variable is a valid instance of
          // a class with default property, but it may cause unexpected behaviors depending on the variable content
          varClass := Scripter.ClassByName(TObject(VarToIntObject(v)).ClassName);
          if Assigned(varClass) and (varClass.DefaultProperty <> nil) then
          begin
            if Assigned(varClass.DefaultProperty.Setter) then
            begin
              FCurrentInputArgBase := FStackTop;
              FCurrentArrayIndexBase := FCurrentInputArgBase + 1;
              for I := 0 to varClass.DefaultProperty.IndexCount - 1 do
                FProcStack[FCurrentArrayIndexBase + I] := FProcStack[FStackTop + ADim + I];
              FCurrentObject := TObject(VarToIntObject(v));
              TMachineProc(varClass.DefaultProperty.Setter)(self);
              Error := false;
            end;
          end;
        end;
        if Error then
          RuntimeError('Variable is not an array');
      end;
  Result := v;
end;

{$IFDEF NEWSTACK}
function TatVirtualMachine.SetValueArrayElement(v: TValue; ADim: integer; AValue: TValue): TValue;

  function _IndexValue(Idx: integer): integer;
  begin
    Result := DerefValue(FProcStack[FStackTop + ADim + Idx]).AsInteger;
  end;

var
  s: string;
  i: integer;
  varClass: TatClass;
  Error: boolean;
  vSub: TValue;
begin
  with FCurrentInstruction^ do
    if v.IsType<string> then
    begin
      if ADim = vByte then
      begin
        i := _IndexValue(0);
        s := v.AsString;
        Delete(s, i, 1);
        Insert(AValue.AsString, s, i);
        v := s;
      end
      else
        RuntimeError('String variable has only one dimension')
    end
    else
    if v.Kind = TTypeKind.tkVariant then
    begin
      v := TValue.From<Variant>(SetVariantArrayElement(v.AsVariant, ADim, AValue.AsVariant));
    end
    else
    if v.IsArray then
    begin
      if ADim = vByte then
        v.SetArrayElement(_IndexValue(0), AValue)
      else
      begin
        VSub := ScriptArrayValue(v, _IndexValue(0));
        v.SetArrayElement(_IndexValue(0), SetValueArrayElement(VSub, ADim + 1, AValue));
      end;
    end
    else
    if v.IsObject then
    begin
      // check if the variable is an object with default indexed property
      Error := True;
      varClass := Scripter.ClassByName(v.AsObject.ClassName);
      if Assigned(varClass) and (varClass.DefaultProperty <> nil) then
      begin
        if Assigned(varClass.DefaultProperty.Setter) then
        begin
          FCurrentInputArgBase := FStackTop;
          FCurrentArrayIndexBase := FCurrentInputArgBase + 1;
          for I := 0 to varClass.DefaultProperty.IndexCount - 1 do
            FProcStack[FCurrentArrayIndexBase + I] := FProcStack[FStackTop + ADim + I];
          FCurrentObject := v.AsObject;
          TMachineProc(varClass.DefaultProperty.Setter)(self);
          Error := false;
        end;
      end;
      if Error then
        RuntimeError('Object does not have a default property');
    end
    else
      RuntimeError('Cannot retrieve indexed value. Variable is not array or cannot be indexed.');
  Result := v;
end;
{$ENDIF}

function TatVirtualMachine.SetScriptArrayElement(v: TScriptValue;
  ADim: integer; AValue: TScriptValue): TScriptValue;
begin
  {$IFDEF NEWSTACK}
  Result := SetValueArrayElement(v, ADim, AValue);
  {$ELSE}
  Result := SetVariantArrayElement(v, ADim, AValue);
  {$ENDIF}
end;

function TatVirtualMachine.GetVariantArrayElement(v: Variant; ADim: integer): Variant;

  function _IndexValue(Idx: integer): integer;
  begin
    {$IFDEF NEWSTACK}
    Result := DerefValue(FProcStack[FStackTop + ADim - 1 + Idx]).AsInteger;
    {$ELSE}
    Result := FProcStack[FStackTop + ADim - 1 + Idx];
    {$ENDIF}
  end;

var
  vardim: integer;
  varClass: TatClass;
  Error: boolean;
  Indices: array of integer;
  I: integer;
begin
  with FCurrentInstruction^ do
  begin
    if not VarIsArray(v) and (VarIsType(v, [varString,
      {$IFDEF DELPHI2009_LVL}
      varUString,
      {$ENDIF}
      varOleStr])) then
      if ADim = vByte then // só aceita acesso aos caracteres da string no último indice
        Result := Copy(VarToStr(v), _IndexValue(0), 1)
      else
        RuntimeError('String variable has only one dimension')
    else
      { arrays podem ser acessados com multiplos indices quando
        tvartype  forem matrizes multidimensionais, strings ou combinações destes }
      if VarIsArray(v) then
      begin
        vardim := VarArrayDimCount(v);
        SetLength(Indices, vardim);
        for I := 0 to vardim - 1 do
          Indices[I] := _IndexValue(I);
        Result := VarArrayGet(V, Indices);

        if ADim + vardim - 1 <> vByte then
          Result := GetVariantArrayElement(Result, ADim + vardim);
      end
      else
      begin
        // check if the variable is an object with default indexed property
        Error := True;
        if VarIsType(v, [varInteger]) then
        begin
          // warning: this cast to TObject is a workaround to try to determine if a variable is a valid instance of
          // a class with default property, but it may cause unexpected behaviors depending on the variable content
          varClass := Scripter.ClassByName(TObject(VarToIntObject(v)).ClassName);
          if Assigned(varClass) and (varClass.DefaultProperty <> nil) then
          begin
            if Assigned(varClass.DefaultProperty.Getter) then
            begin
              FCurrentObject := TObject(VarToIntObject(v));
              TMachineProc(varClass.DefaultProperty.Getter)(self);
              Result := ToVariant(DerefValue(FProcStack[FOutputBase]));
              Error := false;
            end;
          end;
        end;
        if Error then
          RuntimeError('Variable is not an array');
      end;
  end;
end;

{$IFDEF NEWSTACK}
function TatVirtualMachine.GetValueArrayElement(v: TValue; ADim: integer): TValue;

  function _IndexValue(Idx: integer): integer;
  begin
    Result := DerefValue(FProcStack[FStackTop + ADim - 1 + Idx]).AsInteger;
  end;

var
  varClass: TatClass;
  Error: boolean;
  I: integer;
begin
  with FCurrentInstruction^ do
  begin
    if v.IsType<string> then
    begin
      if ADim = vByte then
        Result := Copy(v.AsString, _IndexValue(0), 1)
      else
        RuntimeError('String variable has only one dimension')
    end
    else
    if v.IsArray then
    begin
      Result := ScriptArrayValue(v, _IndexValue(0));
      if ADim <> vByte then
        Result := GetValueArrayElement(Result, ADim + 1);
    end
    else
    if v.Kind = TTypeKind.tkVariant then
    begin
      Result := TValue.From<Variant>(GetVariantArrayElement(v.AsVariant, ADim));
    end
    else
    if v.IsObject then
    begin
      // check if the variable is an object with default indexed property
      Error := True;
      varClass := Scripter.ClassByName(v.AsObject.ClassName);
      if Assigned(varClass) and (varClass.DefaultProperty <> nil) then
      begin
        if Assigned(varClass.DefaultProperty.Getter) then
        begin
          FCurrentObject := v.AsObject;
          TMachineProc(varClass.DefaultProperty.Getter)(self);
          Result := DerefValue(FProcStack[FOutputBase]);
          Error := false;
        end;
      end;
      if Error then
        RuntimeError('Object does not have a default property');
    end
    else
      RuntimeError('Cannot retrieve indexed value. Variable is not array or cannot be indexed.');
  end;
end;
{$ENDIF}

function TatVirtualMachine.GetScriptArrayElement(v: TScriptValue; ADim: integer): TScriptValue;
begin
  {$IFDEF NEWSTACK}
  Result := GetValueArrayElement(v, ADim);
  {$ELSE}
  Result := GetVariantArrayElement(v, ADim);
  {$ENDIF}
end;

procedure TatVirtualMachine._StoreIdxVar;
begin
  dec(FStackTop, FCurrentInstruction^.vByte + 1);
  FProcStack[FStackBase + FCurrentInstruction^.vInteger] :=
    SetScriptArrayElement(
      DerefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger]),
      1, DerefValue(FProcStack[FStackTop]));
end;

procedure TatVirtualMachine._StoreIdxVarRef;
var
  VarStackValue: TStackValue;
  ChangedArray: TScriptValue;
begin
  dec(FStackTop, FCurrentInstruction^.vByte + 1);
  VarStackValue := FProcStack[FStackBase + FCurrentInstruction^.vInteger];
  ChangedArray :=
    SetScriptArrayElement(DerefValue(VarStackValue), 1, DerefValue(FProcStack[FStackTop]));
  if IsReference(VarStackValue) then
    SetRefValue(VarStackValue, ChangedArray)
  else
    FProcStack[FStackBase + FCurrentInstruction^.vInteger] := ChangedArray;
end;

procedure TatVirtualMachine._StoreVarDouble;
begin
  { armazena o parâmetro vDouble na variável indexada por vInteger }
  FProcStack[FStackBase + FCurrentInstruction^.vInteger] :=
    DoubleToScriptValue(FCurrentInstruction^.vDouble);
end;

procedure TatVirtualMachine._StoreVarRefDouble;
begin
  if IsReference(FProcStack[FStackBase + FCurrentInstruction^.vInteger]) then
    SetRefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger], FCurrentInstruction^.vDouble)
  else
    FProcStack[FStackBase + FCurrentInstruction^.vInteger] :=
      DoubleToScriptValue(FCurrentInstruction^.vDouble);
end;

procedure TatVirtualMachine._StoreVarInteger;
begin
  { armazena o parâmetro vInteger2 na variável indexada por vInteger }
  FProcStack[FStackBase + FCurrentInstruction^.vInteger] :=
    Int64ToScriptValue(FCurrentInstruction^.vInt64);
end;

procedure TatVirtualMachine._StoreVarRefInteger;
begin
  if IsReference(FProcStack[FStackBase + FCurrentInstruction^.vInteger]) then
    SetRefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger], FCurrentInstruction^.vInt64)
  else
    FProcStack[FStackBase + FCurrentInstruction^.vInteger] :=
      Int64ToScriptValue(FCurrentInstruction^.vInt64);
end;

procedure TatVirtualMachine._StoreVarString;
begin
  FProcStack[FStackBase + FCurrentInstruction^.vInteger] :=
    StringToScriptValue(Copy(FCurrentInstruction^.vString, 1, FCurrentInstruction^.vInteger3));
end;

procedure TatVirtualMachine._StoreVarRefString;
var
  S: string;
begin
  S := Copy(FCurrentInstruction^.vString, 1, FCurrentInstruction^.vInteger3);
  if IsReference(FProcStack[FStackBase + FCurrentInstruction^.vInteger]) then
    SetRefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger], S)
  else
    FProcStack[FStackBase + FCurrentInstruction^.vInteger] := StringToScriptValue(S);
end;

procedure TatVirtualMachine._StoreVarConst;
begin
  with FCurrentInstruction^ do
    FProcStack[FStackBase + vInteger] := CoreConst[CORE_CONST(vByte)];
end;

procedure TatVirtualMachine._StoreVarRefConst;
var
  TargetValue: TScriptValue;
begin
  TargetValue := CoreConst[CORE_CONST(FCurrentInstruction^.vByte)];
  if IsReference(FProcStack[FStackBase + FCurrentInstruction^.vInteger]) then
    SetRefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger], TargetValue)
  else
    FProcStack[FStackBase + FCurrentInstruction^.vInteger] := TargetValue;
end;

procedure TatVirtualMachine._CopyVar;
begin
  FProcStack[FStackBase + FCurrentInstruction^.vInteger2] := DerefValue(
    FProcStack[FStackBase + FCurrentInstruction^.vInteger]);

//  with TVarData(FProcStack[FStackBase + FCurrentInstruction^.vInteger]) do
//    if VType and varByRef = 0 then
//      FProcStack[FStackBase + FCurrentInstruction^.vInteger2] :=
//        FProcStack[FStackBase + FCurrentInstruction^.vInteger]
//    else
//      FProcStack[FStackBase + FCurrentInstruction^.vInteger2] := PVariant(vPointer)^;
end;

procedure TatVirtualMachine._CopyVarRef;
var
  OriginValue: TScriptValue;
begin
  OriginValue := DerefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger]);
  if IsReference(FProcStack[FStackBase + FCurrentInstruction^.vInteger2]) then
    SetRefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger2], OriginValue)
  else
    FProcStack[FStackBase + FCurrentInstruction^.vInteger2] := OriginValue;
end;

procedure TatVirtualMachine._Call;
begin
  with FCurrentInstruction^ do
  begin
    // Change execution flow to routine
    {$IFDEF NEWSTACK}
    FCurrentInstruction := vInst;
    {$ELSE}
    FCurrentInstruction := pSimplifiedCode(vPointer);
    {$ENDIF}
    // Set the base for output parameters
    FOutputBase := FStackTop + FCurrentInstruction^.vInteger; { prepare }
    // Create a new process
    ExecProcess(vByte);
    // Discard input parameters of called function
    dec(FStackTop, vByte);
  end;
end;

procedure TatVirtualMachine._Ret;
begin
  { encerra o processo corrente }
  FNextInstruction := nil;
end;

procedure TatVirtualMachine._StoreInput;
begin
  FProcStack[FStackBase + FCurrentInstruction^.vInteger] :=
    DerefValue(FProcStack[FInputBase + FInputOffset]);

//  { store input parameter value in variable }
//  { returns variant content, even if it's varByRef }
//  with TVarData(FProcStack[FInputBase + FInputOffset]) do
//    if VType and varByRef = 0 then
//      FProcStack[FStackBase + FCurrentInstruction^.vInteger] :=
//        FProcStack[FInputBase + FInputOffset]
//    else
//      FProcStack[FStackBase + FCurrentInstruction^.vInteger] := Variant(vPointer^);

  Inc(FInputOffset);
end;

procedure TatVirtualMachine._ExecFun; // obsolete
begin
  RuntimeError('Use methods instead of obsolete user functions');
end;

procedure TatVirtualMachine._PushInteger;
begin
  { empilha a instância representada pelo seu ponteiro vInt64 }
  FProcStack[FStackTop] := Int64ToScriptValue(FCurrentInstruction^.vInt64);
  Inc(FStackTop);
end;

procedure TatVirtualMachine._TryFinally;
var
  try_end, finally_end: pSimplifiedCode;
  OriginalStackTop: integer;
  Exiting: boolean;
begin
  Exiting := false;
  OriginalStackTop := FStackTop;
  { obtém o endereço das instruções de conclusão do bloco TRY e do bloco FINALLY }
  with FCurrentInstruction^ do
  begin
    {$IFDEF NEWSTACK}
    try_end := pSimplifiedCode(vInst);
    finally_end := pSimplifiedCode(vInst2);
    {$ELSE}
    try_end := pSimplifiedCode(vPointer);
    finally_end := pSimplifiedCode(vPointer2);
    {$ENDIF}
  end;
  try
    try
      { executa o bloco de instruções do TRY }
      FCurrentInstruction := FNextInstruction;
      FStopInstruction := try_end;
      try
        while (FNextInstruction <> try_end) and (FNextInstruction <> nil) do
        begin
          FNextInstruction := FCurrentInstruction^.Next;
          FCurrentInstruction.Compute;
          if FAutoPause then
            CheckAutoPause;
          if FPaused then
            DoDebugHook;
          if FCallExecHookEvent then
            DoExecHook;
          FCurrentInstruction := FNextInstruction;
        end;
      finally
        FStopInstruction := nil;
      end;
      { Atualiza o contexto da exceção para uso em runtime }
      FLastExceptionMessage := '';
      FLastExceptionHelpContext := 0;
      FLastExceptionClassName := '';
      FLastExceptionLine := 0;
      FLastExceptionCol := 0;
      { se saiu com exit então propaga o exit para fora do bloco try }
      if FCurrentInstruction = nil then
        Exiting := True;
    except
      on ex: Exception do
      begin
        { Atualiza o contexto da exceção para uso em runtime }
        FLastExceptionMessage := ex.Message;
        FLastExceptionHelpContext := ex.HelpContext;
        FLastExceptionClassName := ex.ClassName;
        if Assigned(FCurrentInstruction) then
          Script.GetRowColFromInst(FCurrentInstruction, FLastExceptionLine, FLastExceptionCol);

        { em caso de exceção num bloco try..finally o stack retornará a situação
          em que se encontrava antes do bloco try..finally. Portanto deve-se tomar
          cuidado quando estiver retornando resultados dentro deste bloco }
        FStackTop := OriginalStackTop;
        raise;
      end;
    end;
  finally
    { garante que a execução do boclo FINALLY seja iniciada corretamente }
    FNextInstruction := try_end;
    FCurrentInstruction := try_end;
    FStopInstruction := finally_end;
    { executa o bloco de instruções do FINALLY }
    try
      while (FNextInstruction <> finally_end) and (FNextInstruction <> nil) do
      begin
        FNextInstruction := FCurrentInstruction^.Next;
        FCurrentInstruction.Compute;
        if FAutoPause then
          CheckAutoPause;
        if FPaused then
          DoDebugHook;
        if FCallExecHookEvent then
          DoExecHook;
        FCurrentInstruction := FNextInstruction;
      end;
    finally
      FStopInstruction := nil;
    end;
  end;
  if Exiting then
    FNextInstruction := nil;
end;

procedure TatVirtualMachine._TryExcept;
var
  try_end, except_end: pSimplifiedCode;
  OriginalStackTop: integer;
  Exiting: boolean;
begin
  Exiting := false;
  OriginalStackTop := FStackTop;
  { obtém o endereço das instruções de conclusão do bloco TRY e do bloco EXCEPT }
  with FCurrentInstruction^ do
  begin
    {$IFDEF NEWSTACK}
    try_end := pSimplifiedCode(vInst);
    except_end := pSimplifiedCode(vInst2);
    {$ELSE}
    try_end := pSimplifiedCode(vPointer);
    except_end := pSimplifiedCode(vPointer2);
    {$ENDIF}
  end;
  try
    Inc(FInTryExcept);
    { executa o bloco de instruções do TRY }
    FCurrentInstruction := FNextInstruction;
    FStopInstruction := try_end;
    try
      while (FNextInstruction <> try_end) and (FNextInstruction <> except_end) and
        (FNextInstruction <> nil) do
      begin
        FNextInstruction := FCurrentInstruction^.Next;
        FCurrentInstruction.Compute;
        if FAutoPause then
          CheckAutoPause;
        if FPaused then
          DoDebugHook;
        if FCallExecHookEvent then
          DoExecHook;
        FCurrentInstruction := FNextInstruction;
      end;
    finally
      FStopInstruction := nil;
    end;
    { evita que o bloco EXCEPT seja executado, já que não ocorreu nenhuma exceção }
    FNextInstruction := except_end;
    { se saiu com exit então propaga o exit para fora do bloco try }

    if FCurrentInstruction = nil then
      Exiting := True;
  except
    on ex: Exception do
    begin
      dec(FInTryExcept);
      { Atualiza o contexto da exceção para uso em runtime }
      FLastExceptionMessage := ex.Message;
      FLastExceptionHelpContext := ex.HelpContext;
      FLastExceptionClassName := ex.ClassName;
      if Assigned(FCurrentInstruction) then
        Script.GetRowColFromInst(FCurrentInstruction, FLastExceptionLine, FLastExceptionCol);
      { em caso de exceção num bloco try..except o stack retornará a situação
        em que se encontrava antes do bloco try..except. Portanto deve-se tomar
        cuidado quando estiver retornando resultados dentro deste bloco }
      FStackTop := OriginalStackTop;
      { garante que a execução do boclo EXCEPT seja iniciada corretamente }
      FNextInstruction := try_end;
      FCurrentInstruction := try_end;
      FStopInstruction := except_end;
      { executa o bloco de instruções do EXCEPT }
      try
        while (FNextInstruction <> except_end) and (FNextInstruction <> nil) do
        begin
          FNextInstruction := FCurrentInstruction^.Next;
          FCurrentInstruction.Compute;
          if FAutoPause then
            CheckAutoPause;
          if FPaused then
            DoDebugHook;
          if FCallExecHookEvent then
            DoExecHook;
          FCurrentInstruction := FNextInstruction;
        end;
      finally
        FStopInstruction := nil;
      end;
    end;
  end;
  if Exiting then
    FNextInstruction := nil;
end;

procedure TatVirtualMachine._WithObject;
begin
  // Set the object which will be used by the next CallProc call after this instruction.
  // The value used to set the object is the value of variable specified }
  {$IFDEF NEWSTACK}
  FCurrentInstruction^.Next^.vObj :=
    VarToObject(DerefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger]));
  {$ELSE}
  FCurrentInstruction^.Next^.vPointer :=
    DerefValue(FProcStack[FStackBase + FCurrentInstruction^.vInteger]);
  {$ENDIF}
//  with TVarData(FProcStack[FStackBase + FCurrentInstruction^.vInteger]) do
//    if VType and varByRef = 0 then
//      FCurrentInstruction^.Next^.vPointer := FProcStack[FStackBase + FCurrentInstruction^.vInteger]
//    else
//      FCurrentInstruction^.Next^.vPointer := PVariant(vPointer)^;
end;

procedure TatVirtualMachine._CallProc;

  procedure GetCurrentObjectFromStack;
  begin
    // if current instruction (inCallProc) doesn't provide the current instance
    // as an implicit parameter, then get the instance as the last input value in stack
    {$IFDEF NEWSTACK}
    FCurrentObject := TObject(FCurrentInstruction^.vObj);
    {$ELSE}
    FCurrentObject := TObject(FCurrentInstruction^.vPointer);
    {$ENDIF}
    if not Assigned(FCurrentObject) then
    begin
      dec(FStackTop);
      try
        {$IFDEF MSWINDOWS}
        FCurrentOleObject := FProcStack[FStackTop];
        {$ENDIF}
        FCurrentObject := VarToObject(DerefValue(FProcStack[FStackTop]));
      except
        FCurrentObject := nil;
      end;
    end;
  end;

begin
  with FCurrentInstruction^ do
  begin
    { inicializa o apontador dos argumentos de saída }
    FCurrentOutputArgIndex := FStackTop;
    FOutputBase := FStackTop;
    { Elimina os argumentos de indices em chamadas indexadas,
      para trata-los como argumentos simples na pilha }
    dec(FStackTop, vInteger1);
    { prepara o apontador de base dos indices matriciais de entrada }
    FCurrentArrayIndexBase := FStackTop;
    { Verifica se o proc se refere a um setter, porque a passagem de argumetos
      para um setter proc é especial e sinalizado com argcount=255 }
    if vByte = 255 then { ! Setter Proc ! }
    begin
      { AQUI A INSTÂNCIA ASSOCIADA AO PROC É PASSADA POR ÚLTIMO NA PILHA }
      GetCurrentObjectFromStack;
      { elimina o argumento "Setter Value" passado para o processo ) }
      dec(FStackTop);
      { prepara o apontador do argumento de entrada }
      FCurrentInputArgBase := FStackTop;
    end
    else
    begin
      { AQUI A INSTÂNCIA ASSOCIADA AO PROC É PASSADA POR PRIMEIRO NA PILHA }
      { elimina todos os argumentos passados para o processo }
      dec(FStackTop, vByte);
      { prepara o apontador dos argumentos de entrada para o início }
      FCurrentInputArgBase := FStackTop;
      GetCurrentObjectFromStack;
    end;
    FCurrentClass := nil;
    { chama a rotina associada a instrução,
      passando esta instância de máquina virtual como argumento }
    TMachineProc(vProc)(self);
  end;
end;

procedure TatVirtualMachine._CallClassProc;
begin
  with FCurrentInstruction^ do
  begin
    { inicializa o apontador dos argumentos de saída }
    FCurrentOutputArgIndex := FStackTop;
    FOutputBase := FStackTop;
    { elimina os argumentos de indices em chamadas indexadas }
    dec(FStackTop, vInteger1);
    { prepara o apontador de base dos indices matriciais de entrada }
    FCurrentArrayIndexBase := FStackTop;
    { membros de classe sempre tem o CurrentObject nulo }
    FCurrentObject := nil;
    {$IFDEF MSWINDOWS}
    FCurrentOleObject := null;
    {$ENDIF}
    {$IFDEF NEWSTACK}
    FCurrentClass := TatClass(vObj);
    {$ELSE}
    FCurrentClass := TatClass(vPointer);
    {$ENDIF}
    { elimina todos os argumentos passados para o processo }
    dec(FStackTop, vByte);
    { prepara o apontador dos argumentos de entrada para o início }
    FCurrentInputArgBase := FStackTop;
    { chama a rotina associada a instrução }
    TMachineProc(vProc)(self);
  end;
end;

procedure TatVirtualMachine._BreakPoint;
begin
  { executa a rotina de tratamento específico deste break point }
  TMachineProc(FCurrentInstruction^.vProc)(self);
end;

procedure TatVirtualMachine._VarTest;
begin
  // jumps if the expression at stack top is different from the variable value
  // removes value from stack
//  with FCurrentInstruction^ do
//    if byte(FProcStack[FStackBase + FCurrentInstruction^.vInteger2] = FProcStack[FStackTop - 1]) = vByte
//    then
//      FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);

  if byte(ScriptValueEqual(
    Derefvalue(FProcStack[FStackBase + FCurrentInstruction^.vInteger2]),
    Derefvalue(FProcStack[FStackTop - 1]))) = FCurrentInstruction^.vByte then
      {$IFDEF NEWSTACK}
      FNextInstruction := FCurrentInstruction^.vInst;
      {$ELSE}
      FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
      {$ENDIF}
  dec(FStackTop);
end;

procedure TatVirtualMachine._VarTestDouble;
begin
//  with FCurrentInstruction^ do
//    if byte(FProcStack[FStackBase + vInteger1] = vDouble) = vByte then
//      FNextInstruction := pSimplifiedCode(vPointer);

  if byte(ScriptValueEqual(
    Derefvalue(FProcStack[FStackBase + FCurrentInstruction^.vInteger1]),
    FCurrentInstruction^.vDouble)) = FCurrentInstruction^.vByte then
      {$IFDEF NEWSTACK}
      FNextInstruction := FCurrentInstruction^.vInst;
      {$ELSE}
      FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
      {$ENDIF}
end;

procedure TatVirtualMachine._VarTestInteger;
begin
//  with FCurrentInstruction^ do
//    if byte(FProcStack[FStackBase + vInteger2] = vInteger3) = vByte then
//      FNextInstruction := pSimplifiedCode(vPointer);

  if byte(ScriptValueEqual(
    Derefvalue(FProcStack[FStackBase + FCurrentInstruction^.vInteger2]),
    FCurrentInstruction^.vInteger3)) = FCurrentInstruction^.vByte then
      {$IFDEF NEWSTACK}
      FNextInstruction := FCurrentInstruction^.vInst;
      {$ELSE}
      FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
      {$ENDIF}
end;

procedure TatVirtualMachine._VarTestString;
begin
//  with FCurrentInstruction^ do
//    if byte(FProcStack[FStackBase + vInteger2] = Copy(vString, 1, vInteger3)) = vByte then
//      FNextInstruction := pSimplifiedCode(vPointer);

  if byte(ScriptValueEqual(
    Derefvalue(FProcStack[FStackBase + FCurrentInstruction^.vInteger2]),
    Copy(FCurrentInstruction^.vString, 1, FCurrentInstruction^.vInteger3))) = FCurrentInstruction^.vByte then
      {$IFDEF NEWSTACK}
      FNextInstruction := FCurrentInstruction^.vInst;
      {$ELSE}
      FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
      {$ENDIF}
end;

procedure TatVirtualMachine._VarTestVar;
begin
//  with FCurrentInstruction^ do
//    if byte(FProcStack[FStackBase + vInteger2] = FProcStack[FStackBase + vInteger3]) = vByte then
//      FNextInstruction := pSimplifiedCode(vPointer);

  if byte(ScriptValueEqual(
    Derefvalue(FProcStack[FStackBase + FCurrentInstruction^.vInteger2]),
    Derefvalue(FProcStack[FStackBase + FCurrentInstruction^.vInteger3]))) = FCurrentInstruction^.vByte then
      {$IFDEF NEWSTACK}
      FNextInstruction := FCurrentInstruction^.vInst;
      {$ELSE}
      FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
      {$ENDIF}
end;

procedure TatVirtualMachine._StoreGlobalVar;
begin
  { armazena o valor do topo do FStack na variável global }
  FProcStack[FCurrentInstruction^.vInteger] := FProcStack[FStackTop - 1];
  dec(FStackTop);
end;

procedure TatVirtualMachine._SaveStackValue;
var
  Count: integer;
  I: integer;
begin
  Count := FCurrentInstruction^.vInteger;
  for I := 0 to Count - 1 do
  begin
  FTempStack[FTempStackTop] := FProcStack[FStackTop - 1];
  dec(FStackTop);
  Inc(FTempStackTop);
  end;
end;

procedure TatVirtualMachine._StoreGlobalIdxVar;
begin
  // push the indexed element of global variable
  dec(FStackTop, FCurrentInstruction^.vByte + 1);
  FProcStack[FCurrentInstruction^.vInteger] :=
    SetScriptArrayElement(
      Derefvalue(FProcStack[FCurrentInstruction^.vInteger]),
      1, Derefvalue(FProcStack[FStackTop]));
end;

procedure TatVirtualMachine._PushGlobalVar;
begin
//  with TVarData(FProcStack[FCurrentInstruction^.vInteger]) do
//    if VType and varByRef = 0 then
//      FProcStack[FStackTop] := FProcStack[FCurrentInstruction^.vInteger]
//    else
//      FProcStack[FStackTop] := PVariant(vPointer)^;

  FProcStack[FStackTop] := DerefValue(FProcStack[FCurrentInstruction^.vInteger]);
  Inc(FStackTop);
end;

procedure TatVirtualMachine._PushGlobalVarByRef;
begin
  // push a reference to a global variable in local FStack
  FProcStack[FStackTop] := CreateReferenceValue(
    {$IFDEF NEWSTACK}
    @(FProcStack[FCurrentInstruction^.vInteger].RawValue));
    {$ELSE}
    @(FProcStack[FCurrentInstruction^.vInteger]));
    {$ENDIF}

//  TVarData(FProcStack[FStackTop]).VType := varVariant or varByRef;
//  with TVarData(FProcStack[FCurrentInstruction^.vInteger]) do
//    if VType and varByRef = 0 then
//      TVarData(FProcStack[FStackTop]).vPointer := @FProcStack[FCurrentInstruction^.vInteger]
//    else
//      TVarData(FProcStack[FStackTop]).vPointer := vPointer;

  Inc(FStackTop);
end;

procedure TatVirtualMachine._PushGlobalIdxVar;
begin
  { empilha o elemento indexado da variável global }
  with FCurrentInstruction^ do
  begin
    dec(FStackTop, vByte);
    FProcStack[FStackTop] := GetScriptArrayElement(Derefvalue(FProcStack[vInteger]), 1);
    Inc(FStackTop);
  end;
end;

procedure TatVirtualMachine._Abort;
begin
  Abort;
end;

{ takes n stack values and makes an array of them }
procedure TatVirtualMachine._ArrayOf;
var
  c, n: integer;
  v: TScriptValue;
  {$IFDEF NEWSTACK}
  vArray: TArray<TValue>;
  {$ENDIF}
begin
  with FCurrentInstruction^ do
  begin
    n := FCurrentInstruction^.vInteger - 1;
    {$IFDEF NEWSTACK}
    SetLength(vArray, n + 1);
    for c := 0 to n do
      vArray[c] := Derefvalue(FProcStack[FStackTop - 1 - n + c]);
    v := TValue.FromArray(TypeInfo(TArray<TValue>), vArray);
    {$ELSE}
    v := VarArrayCreate([0, n], varVariant);
    for c := 0 to n do
      v[c] := FProcStack[FStackTop - 1 - n + c];
    {$ENDIF}
    dec(FStackTop, vInteger);
    FProcStack[FStackTop] := v;
    Inc(FStackTop);
  end;
end;

procedure TatVirtualMachine._TestIfFalse;
begin
  if not ScriptValueAsBool(DerefValue(FProcStack[FStackTop - 1])) then
    {$IFDEF NEWSTACK}
    FNextInstruction := FCurrentInstruction^.vInst;
    {$ELSE}
    FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
    {$ENDIF}
end;

procedure TatVirtualMachine._TestIfTrue;
begin
  if ScriptValueAsBool(DerefValue(FProcStack[FStackTop - 1])) then
    {$IFDEF NEWSTACK}
    FNextInstruction := FCurrentInstruction^.vInst;
    {$ELSE}
    FNextInstruction := pSimplifiedCode(FCurrentInstruction^.vPointer);
    {$ENDIF}
end;

{ --- }

procedure TatVirtualMachine._CastClass;
var
  obj: TObject;
  RefClass: TClass;
begin
  // check if object in top of stack inherits from class specified in instruction
  with Script, FCurrentInstruction^ do
  begin
    {$IFDEF NEWSTACK}
    if vObj = nil then
    begin
      vObj := Scripter.Classes.ClassByName(vString);
      if vObj = nil then
        RuntimeError(Format('Invalid type cast. Class ''%s'' is not valid' +
          ErrorComplement(vDebugInfo), [vString]));
    end;
    RefClass := TranslateClass(vObj);
    {$ELSE}
    if vPointer = 0 then
    begin
      vPointer := ObjectToVar(Scripter.Classes.ClassByName(vString));
      if vPointer > 0 then
        vPointer := IntObject(TatClass(vPointer).FClassRef)
      else
        RuntimeError(Format('Invalid type cast. Class ''%s'' is not valid' +
          ErrorComplement(vDebugInfo), [vString]));
    end;
    RefClass := TranslateClass(vPointer);
    {$ENDIF}

    { assumes value in top of stack in an object }
    obj := VarToObject(DerefValue(FProcStack[FStackTop - 1]));
    if not Assigned(obj) then
      RuntimeError(Format('Invalid object to type cast (nil)' + ErrorComplement(vDebugInfo),
        [vString]));
    { tests if object inherits from specified class }
    if not obj.InheritsFrom(RefClass) then
      RuntimeError(Format('Object is not of expected class ''%s''' + ErrorComplement(vDebugInfo),
        [vString]));
  end;
end;

{ _CallProc to unresolved Getter }
procedure TatVirtualMachine.UndefinedGetterProc;
var
  property_obj: TatProperty;
  method_obj: TatMethod;
  calling: boolean;
  IsCOM: boolean;
  loadClass: TatClass;
  {$IFDEF MSWINDOWS}
  params: OleVariant;
  i: integer;
  s: Variant;
  {$ENDIF}
begin
  IsCOM := false;
  with FCurrentInstruction^ do
  begin
    calling := (vSmallInt = 1);
    { se o objeto corrente não estiver definido tenta encontrá-lo no topo da pilha }
    if not Assigned(CurrentObject) then
    begin
      {$IFDEF MSWINDOWS}
      case VarType(FCurrentOleObject) of
        varDispatch:
          IsCOM := True;
        varUnknown:
          if IUnknown(FCurrentOleObject).QueryInterface(IatInterfacedObject, FCurrentObject) = S_OK
          then
          begin
            FCurrentObject := IatInterfacedObject(pointer(FCurrentObject)).GetObjectReference;
            FCurrentClass := nil;
            IUnknown(FCurrentOleObject)._Release;
          end
          else
            RuntimeError(Format('Object or Record required to access property: ''%s''' +
              Script.ErrorComplement(vDebugInfo), [vString]));
      else
        RuntimeError(Format('Object or Record required to access property: ''%s''' +
          Script.ErrorComplement(vDebugInfo), [vString]));
      end;
      {$ELSE}
      RuntimeError(Format('Object or Record required to access property: ''%s''' +
        Script.ErrorComplement(vDebugInfo), [vString]))
      {$ENDIF}
    end;

    { localiza a propriedade através de seu nome, na classe da instância
      que está no topo da pilha. Se a classe ainda não havia sido carregada,
      então também carrega suas informações através do RTTI }
    { verifica se a propriedade realmente existe na classe }
    if not IsCOM then
    begin
      {$IFDEF DELPHI2010_LVL}
      if CurrentObject is TGenericRecordWrapper then
        loadClass := Scripter.FClasses.CheckLoaded(CurrentObject.ClassType,
          TGenericRecordWrapper(CurrentObject).RecordName)
      else
        {$ENDIF}
        loadClass := Scripter.FClasses.CheckLoaded(CurrentObject.ClassType,
          GetScriptObjectClassName(CurrentObject));

      with loadClass do
      begin
        property_obj := Properties.PropertyByName(vString);
        if Assigned(property_obj) then
          if calling then
            RuntimeError(Format('Property ''%s'' cannot be called as a method' +
              Script.ErrorComplement(vDebugInfo), [vString]))
          else if Assigned(property_obj.Getter) then
            { se a propriedade puder ser lida, então troca o conteúdo do topo da pilha
              pelo conteúdo da propriedade }
            TMachineProc(property_obj.Getter)(self)
          else
            RuntimeError(Format('Property ''%s'' cannot be readed' +
              Script.ErrorComplement(vDebugInfo), [vString]))
        else
        begin
          { faz a pesquisa também nos métodos sem argumentos, porque, em runtime,
            eles são tratados como propriedades readonly }
          method_obj := Methods.MethodByName(vString);
          if Assigned(method_obj) then
            TMachineProc(method_obj.Proc)(self)
          else
            RuntimeError(Format('Unknown property or method: ''%s''' +
              Script.ErrorComplement(vDebugInfo), [vString]));
        end;
      end;
    end
    else
    begin
      {$IFDEF MSWINDOWS}
      if vInteger1 > 0 then
      begin
        params := VarArrayCreate([0, vInteger1 - 1], varVariant);
        for i := 0 to vInteger1 - 1 do
        begin
          s := GetArrayIndex(i);
          params[i] := s;
        end;
        s := params[0];
      end
      else
        params := null;
      ReturnOutputArg(DispatchInvoke(IDispatch(FCurrentOleObject), vString, DISPATCH_PROPERTYGET or
        DISPATCH_METHOD, vInteger1, params));
      {$ENDIF}
    end;
  end;
end;

{ _CallProc to unresolved Setter }
procedure TatVirtualMachine.UndefinedSetterProc;
var
  property_obj: TatProperty;
  IsCOM: boolean;
  loadClass: TatClass;
  {$IFDEF MSWINDOWS}
  params: OleVariant;
  i: integer;
  s: Variant;
  {$ENDIF}
begin
  IsCOM := false;
  with FCurrentInstruction^ do
  begin
    { se o objeto corrente não estiver definido tenta encontrá-lo no topo da pilha }
    if not Assigned(CurrentObject) then
    begin
      {$IFDEF MSWINDOWS}
      case VarType(FCurrentOleObject) of
        varDispatch:
          IsCOM := True;
        varUnknown:
          if IUnknown(FCurrentOleObject).QueryInterface(IatInterfacedObject, FCurrentObject) = S_OK
          then
          begin
            FCurrentObject := IatInterfacedObject(pointer(FCurrentObject)).GetObjectReference;
            FCurrentClass := nil;
            IUnknown(FCurrentOleObject)._Release;
          end
          else
            RuntimeError(Format('Object or Record required to access property: ''%s''' +
              Script.ErrorComplement(vDebugInfo), [vString]));
      else
        RuntimeError(Format('Object or Record required to access property: ''%s''' +
          Script.ErrorComplement(vDebugInfo), [vString]));
      end;
      {$ELSE}
      RuntimeError(Format('Object or Record required to access property: ''%s''' +
        Script.ErrorComplement(vDebugInfo), [vString]))
      {$ENDIF}
    end;
    { verifica se a propriedade realmente existe na classe }
    { faz a pesquisa também nos métodos, porque, em runtime,
      eles são tratados como propriedades readonly, neste caso será
      provocado um erro notificando que o método não pode sofrer atribuição }
    if not IsCOM then
    begin
      {$IFDEF DELPHI2010_LVL}
      if CurrentObject is TGenericRecordWrapper then
        loadClass := Scripter.FClasses.CheckLoaded(CurrentObject.ClassType,
          TGenericRecordWrapper(CurrentObject).RecordName)
      else
        {$ENDIF}
        loadClass := Scripter.FClasses.CheckLoaded(CurrentObject.ClassType,
          GetScriptObjectClassName(CurrentObject));

      with loadClass do
      begin
        { localiza a propriedade através de seu nome, na classe da instância
          que está no topo da pilha. Se a classe ainda não havia sido carregada,
          então também carrega suas informações através do RTTI }
        property_obj := Properties.PropertyByName(vString);
        if Assigned(property_obj) then
          { se a propriedade puder ser escrita, então escreve o
            conteúdo do nível 2 da pilha na propriedade correspondente à
            instância que está no topo da pilha e desempilha dois níveis }
          if Assigned(property_obj.Setter) then
            TMachineProc(property_obj.Setter)(self)
          else
            RuntimeError(Format('Property ''%s'' cannot be written' +
              Script.ErrorComplement(vDebugInfo), [vString]))
        else if Assigned(Methods.MethodByName(vString)) then
          RuntimeError(Format('Assign to method ''%s'' is not allowed' +
            Script.ErrorComplement(vDebugInfo), [vString]))
        else
          RuntimeError(Format('Unknown property: ''%s''' + Script.ErrorComplement(vDebugInfo),
            [vString]));
      end;
    end
    else
    begin
      {$IFDEF MSWINDOWS}
      { Set the array with the indexed values, then the last value in array must
        be the value of the property to be set. The DispatchInvoke function will
        invert the order of the array by default }
      params := VarArrayCreate([0, vInteger1], varVariant);
      for i := 0 to vInteger1 - 1 do
      begin
        s := GetArrayIndex(i);
        params[i] := s;
      end;
      params[vInteger1] := GetInputArg(0);
      s := params[0];

      DispatchInvoke(IDispatch(FCurrentOleObject), vString, DISPATCH_PROPERTYPUT,
        vInteger1 + 1, params);
      {$ENDIF}
    end;
  end;
end;

{ _CallProc to unresolved Method }
procedure TatVirtualMachine.UndefinedMethodProc;
var
  method_obj: TatMethod;
  IsCOM: boolean;
  {$IFDEF MSWINDOWS}
  params: OleVariant;
  i: integer;
  s: Variant;
  {$ENDIF}
begin
  IsCOM := false;
  with FCurrentInstruction^ do
  begin
    { se o objeto corrente não estiver definido tenta encontrá-lo no topo da pilha }
    if not Assigned(CurrentObject) then
    begin
      {$IFDEF MSWINDOWS}
      case VarType(FCurrentOleObject) of
        varDispatch:
          IsCOM := True;
        varUnknown:
          if IUnknown(FCurrentOleObject).QueryInterface(IatInterfacedObject, FCurrentObject) = S_OK
          then
          begin
            FCurrentObject := IatInterfacedObject(pointer(FCurrentObject)).GetObjectReference;
            FCurrentClass := nil;
            IUnknown(FCurrentOleObject)._Release;
          end
          else
            RuntimeError(Format('Object or Record required to access method: ''%s''' +
              Script.ErrorComplement(vDebugInfo), [vString]));
      else
        RuntimeError(Format('Object or Record required to access method: ''%s''' +
          Script.ErrorComplement(vDebugInfo), [vString]));
      end;
      {$ELSE}
        RuntimeError(Format('Object required to access method: ''%s''' +
          Script.ErrorComplement(vDebugInfo), [vString]))
      {$ENDIF}
    end;
    if not IsCOM then
    begin
      { localiza o método através de seu nome, na classe da instância
        que está no topo da pilha. Se a classe ainda não havia sido carregada,
        então também carrega suas informações através do RTTI }
      method_obj := Scripter.FClasses.CheckLoaded(CurrentObject.ClassType,
        GetScriptObjectClassName(CurrentObject)).Methods.MethodByName(vString);
      { verifica se o método realmente existe na classe }
      if Assigned(method_obj) then
        { se o método foi definido então executa-o, eliminando a
          instância correspondente, que está no top da pilha }
        if Assigned(method_obj.Proc) then
        begin
          { verifica se o número de parâmetros reais está correto }
          if vByte < method_obj.FArgCount - method_obj.FDefArgCount then
          begin
            if method_obj.FDefArgCount = 0 then
              RuntimeError
                (Format('Not enough actual parameters for method ''%s''. Expected %d parameters' +
                Script.ErrorComplement(vDebugInfo), [vString, method_obj.FArgCount]))
            else
              RuntimeError
                (Format('Not enough actual parameters for method ''%s''. Expected %d to %d parameters'
                + Script.ErrorComplement(vDebugInfo),
                [vString, method_obj.FArgCount - method_obj.FDefArgCount, vString,
                method_obj.FArgCount]))
          end
          else if vByte > method_obj.FArgCount then
            RuntimeError(Format('Too many parameters for method ''%s''. Expected %d parameters' +
              Script.ErrorComplement(vDebugInfo), [vString, method_obj.FArgCount]))
          else
            TMachineProc(method_obj.Proc)(self)
        end
        else
          RuntimeError(Format('Method ''%s'' was not defined' + Script.ErrorComplement(vDebugInfo),
            [vString]))
      else
        RuntimeError(Format('Unknown method: ''%s''' + Script.ErrorComplement(vDebugInfo),
          [vString]));
    end
    else
    begin
      {$IFDEF MSWINDOWS}
      params := VarArrayCreate([0, vByte - 1], varVariant);
      for i := 0 to vByte - 1 do
      begin
        s := GetInputArg(i);
        params[i] := s;
      end;
      s := params[0];
      ReturnOutputArg(DispatchInvoke(IDispatch(FCurrentOleObject), vString, DISPATCH_PROPERTYGET or
        DISPATCH_METHOD, vByte, params));
      {$ENDIF}
    end;
  end;
end;

procedure TatVirtualMachine.SolveAbsoluteAddressing;
var
  Cur: pSimplifiedCode;
  c: integer;
  AddressTable: pAddrVector;
  space: integer;
  classidx: integer;
  itemidx: integer;
  AClass: TatClass;
  AObject: TObject;
  TempFastSolve: boolean;
begin
  if Script.FSolvedAddressing then
    Exit;

  { this procedure executes the following adjustments:
    a) fix relative addresses in instructions
    b) adjust address of methods in instructions, based on OpCode
    c) fix address of methods related to getters, setters and calls for objects or classes }
  with Scripter, Script do
  begin
    { verifica se o método compile já foi chamado, senão chama-o automaticamente }
    if not FCompiled then
      Compile;
    space := (FCodeLine + 1);
    GetMem(AddressTable, sizeof(pSimplifiedCode) * space);
    try
      { armazena todos os endereços das intruções em um vetor dinâmico }
      Cur := FFirstInstruction;
      c := 0;
      while Cur <> nil do
      begin
        AddressTable^[c] := Cur;
        Cur := Cur^.Next;
        Inc(c);
      end;
      { redefine todos os desvios relativos usando o vetor de endereços montado }
      Cur := FFirstInstruction;
      while Cur <> nil do
      begin
        with Cur^ do
        begin
          // also set address of semantic routines from all existing instructions
          Compute := FComputeProcs[OpCode];

          {$IFDEF NEWSTACK}
          vObj := nil;
          vInst := nil;
          vInst2 := nil;
          {$ELSE}
          vPointer := 0;
          {$ENDIF}

          { ajusta endereços absolutos em instruções de desvio }
          case OpCode of
            inJump, inCall, inJumpIfFalse, inJumpIfTrue, inVarTest, inVarTestInteger,
              inVarTestDouble, inVarTestString, inVarTestVar, inTestIfFalse, inTestIfTrue:
              if vInteger < space then
                {$IFDEF NEWSTACK}
                vInst := AddressTable^[vInteger];
                {$ELSE}
                vPointer := IntObject(AddressTable^[vInteger]);
                {$ENDIF}
            inTryFinally, inTryExcept:
              begin
                if vInteger < space then
                  {$IFDEF NEWSTACK}
                  vInst := AddressTable^[vInteger];
                  {$ELSE}
                  vPointer := IntObject(AddressTable^[vInteger]);
                  {$ENDIF}

                if vInteger2 < space then
                  {$IFDEF NEWSTACK}
                  vInst2 := AddressTable^[vInteger2];
                  {$ELSE}
                  vPointer2 := IntObject(AddressTable^[vInteger2]);
                  {$ENDIF}

              end;
            inCallProc:
              begin
                { solve default instance reference }
                TempFastSolve := false;
                if vInteger = -1 then
                  AObject := nil
                else
                begin
                  { if vInteger is positive, then it's an index of scripter.FDefaultInstances.
                    if vInteger is negative, then it's an index of script.FDefInstance. But the index is shifted by 2
                    to avoid -0 indexes. So, after changing the signal, we must subtract 2 so that we find the original index.
                    This sum + 2 is needed to avoid 0 and -1, which are special codes (0 is the 0-index for FDefaultinstances }
                  if vInteger >= 0 then
                    AObject := FDefaultInstances[vInteger].Instance
                  else
                    AObject := FDefInstances[(-vInteger) - 2].Instance;
                end;
                {$IFDEF NEWSTACK}
                vObj := AObject;
                {$ELSE}
                vPointer := IntObject(AObject);
                {$ENDIF}

                classidx := integer(TMethod(vProc).Data) shr 17;
                itemidx := (integer(TMethod(vProc).Data) shr 2) and $7FFF;

                { Special case for classidx: if the class to be solved is TatInternalObjectXXXX class,
                  then we must do something special. First, the class name is not guaranteed to be the same.
                  Second, if we're using that class, it means that it's the internal class of this script
                  default instance (FIntInstance), so we can force it to that class.
                  Even if the class name didn't change, we should force the class to be the default instance
                  in the script, because for forms and classes, we don't want to use the class of original
                  script, but instead, we want to use the one of the copied script }
                if (pos('TATINTERNALOBJECT', UpperCase(vString2)) = 1) and
                  (Length(vString2) > 17 { Length('TatInternalObject') } ) then
                begin
                  classidx := FIntInstance.atClass.Index;
                  TempFastSolve := True;
                end;

                { solve vProc relative reference }
                case TClassReference(integer(TMethod(vProc).Data) and 3) of
                  crGetter:
                    if TMethod(vProc).Data = pointer(crGetter) then
                      vProc := UndefinedGetterProc
                    else if FFastSolving or TempFastSolve then
                      vProc := FClasses[classidx].Properties[itemidx].Getter
                    else
                      vProc := _FindProperty(_FindClass(classidx, vString2), itemidx,
                        vString).Getter;
                  crSetter:
                    if TMethod(vProc).Data = pointer(crSetter) then
                      vProc := UndefinedSetterProc
                    else if FFastSolving or TempFastSolve then
                      vProc := FClasses[classidx].Properties[itemidx].Setter
                    else
                      vProc := _FindProperty(_FindClass(classidx, vString2), itemidx,
                        vString).Setter;
                  crMethod:
                    if TMethod(vProc).Data = pointer(crMethod) then
                      vProc := UndefinedMethodProc
                    else if FFastSolving or TempFastSolve then
                      vProc := FClasses[classidx].Methods[itemidx].Proc
                    else
                      vProc := _FindMethod(_FindClass(classidx, vString2), itemidx, vString).Proc;
                end;
              end;
            inCallClassProc:
              begin
                { solve class reference }
                if vInteger = -1 then
                  AClass := nil
                else if FFastSolving then
                  AClass := FClasses[vInteger]
                else
                  AClass := _FindClass(vInteger, vString2);
                {$IFDEF NEWSTACK}
                vObj := AClass;
                {$ELSE}
                vPointer := IntObject(AClass);
                {$ENDIF}

                classidx := integer(TMethod(vProc).Data) shr 17;
                itemidx := (integer(TMethod(vProc).Data) shr 2) and $7FFF;

                { solve vProc relative reference }
                if FFastSolving then
                  case TClassReference(integer(TMethod(vProc).Data) and 3) of
                    crGetter:
                      vProc := FClasses[classidx].Properties[itemidx].Getter;
                    crSetter:
                      vProc := FClasses[classidx].Properties[itemidx].Setter;
                    crMethod:
                      vProc := FClasses[classidx].Methods[itemidx].Proc;
                  end
                else
                  case TClassReference(integer(TMethod(vProc).Data) and 3) of
                    crGetter:
                      vProc := _FindProperty(_FindClass(classidx, vString2), itemidx,
                        vString).Getter;
                    crSetter:
                      vProc := _FindProperty(_FindClass(classidx, vString2), itemidx,
                        vString).Setter;
                    crMethod:
                      vProc := _FindMethod(_FindClass(classidx, vString2), itemidx, vString).Proc;
                  end;
              end;
            inCastClass, inPushClass:
              begin
                { solve class reference }
                if vInteger = -1 then
                  AClass := nil
                else
                if FFastSolving then
                  AClass := FClasses[vInteger]
                else
                  AClass := _FindClass(vInteger, vString);
                {$IFDEF NEWSTACK}
                vObj := AClass;
                {$ELSE}
                vPointer := IntObject(AClass);
                {$ENDIF}
              end;
          end;
        end;
        Cur := Cur^.Next;
      end;
    finally
      FreeMem(AddressTable);
    end;
    FSolvedAddressing := True;
    FFastSolving := True;
  end;
end;

function TatVirtualMachine.Execute: TScriptValue;
begin
  {$IFDEF NEWSTACK}
  Result := Execute([]);
  {$ELSE}
  Result := Execute(null);
  {$ENDIF}
end;

function TatVirtualMachine.ExecuteSubroutine(ALabel: string): TScriptValue;
begin
  {$IFDEF NEWSTACK}
  Result := ExecuteSubroutine(ALabel, []);
  {$ELSE}
  Result := ExecuteSubroutine(ALabel, null);
  {$ENDIF}
end;

function TatVirtualMachine.CurrentMethodName: string;
begin
  { return the current method name when running, current instruction
    is a CallProc and refer to a Method call }
  if Running and Assigned(FCurrentInstruction) then
    with FCurrentInstruction^ do
      if (OpCode in [inCallProc, inCallClassProc]) and (vSmallInt = 1) then
        Result := vString
      else
        Result := ''
  else
    Result := '';
end;

function TatVirtualMachine.CurrentPropertyName: string;
begin
  { return the current property name when running, current instruction
    is a CallProc and refer to a Property getter or setter }
  if Running and Assigned(FCurrentInstruction) then
    with FCurrentInstruction^ do
      if (OpCode in [inCallProc, inCallClassProc]) and (vSmallInt <> 1) then
        Result := vString
      else
        Result := ''
  else
    Result := '';
end;

procedure TatVirtualMachine.InProcessExecute(AScriptStr: string);
var
  debug_script: TatScript;
begin
  if Running then
  begin
    { cria um novo script }
    debug_script := Scripter.FScripts.Add;
    try
      debug_script.FIsDebugScript := True;
      debug_script.SourceCode.Text := AScriptStr;
      CompileDebugScript(debug_script);
      ExecuteDebugScript(debug_script);
    finally
      debug_script.Free;
    end;
  end
  else
    InternalError('Script is not running for debug');
end;

procedure TatVirtualMachine.CompileDebugScript(AScript: TatScript);
var
  c: integer;
  savedInstances: TatObjects;
begin
  { compila um script de depuração dentro do processo em execução }
  with AScript do
  begin
    if FPrepareInstruction = nil then
      Abort;

    { copy information from executing script to the new script }
    ScriptInfo.FRoutines.Assign(Script.FScriptInfo.Routines);
    ScriptInfo.FGlobals.Assign(Script.FScriptInfo.Globals);

    savedInstances := TatObjects.Create(AScript.Scripter.FClasses);
    try
      savedInstances.Assign(AScript.FDefInstances);
      try
        AScript.FDefInstances.Assign(Script.FDefInstances);
        Assert(AScript.FDefInstances.Count > 0,
          'CompileDebugScript error: FDefInstances.Count must be > 0');
        AScript.FIntInstance := AScript.FDefInstances[0];

        FDebugScriptMainRoutine := ScriptInfo.RoutineByName(FPrepareInstruction^.vString);
        CounterInit := 100000; { para não duplicar nomes de variáveis internas }
        { cria espaço na área de alocação de variáveis para corresponder a eventuais
          elementos ocupados temporariamente na pilha, além das variáveis locais do
          processo corrente (para evitar que o novo trecho compilado possa estragar
          o conteúdo da pilha do processo corrente) }
        for c := 1 to FStackTop - (FStackBase + FPrepareInstruction^.vInteger) do
          FDebugScriptMainRoutine.DeclareVariable('#stack' + inttostr(c), -1);
        { compila o novo script e o prepara para execução }
        Compile;
        { corrige a intrução de preparação da subrotina porque ela
          redeclarou todas as variáveis já existentes e mais as novas do script }
        FDebugScriptMainRoutine.DeclarationInstruction^.vInteger :=
          FDebugScriptMainRoutine.DeclarationInstruction^.vInteger - FPrepareInstruction^.vInteger;
        // CodeView(AScript); for debug
        VirtualMachine.SolveAbsoluteAddressing;
        ExpandDebugInfo;

        { Run through the compiled instructions and change any reference to the
          virtual machine to a reference to the original virtual machine (Self) }
        FCurrentInstruction := FFirstInstruction;
        while FCurrentInstruction <> nil do
        begin
          { All compute methods are in the virtual machine, so change all of then }
          TMethod(FCurrentInstruction.Compute).Data := self;
          { The vProc method can be in any object, so first check if it is a method
            of the virtual machine }
          if TMethod(FCurrentInstruction.vProc).Data = VirtualMachine then
            TMethod(FCurrentInstruction.vProc).Data := self;
          FCurrentInstruction := FCurrentInstruction^.Next;
        end;
      finally
        AScript.FDefInstances.Assign(savedInstances);
        Assert(AScript.FDefInstances.Count > 0,
          'CompileDebugScript error: FDefInstances.Count must be > 0');
        AScript.FIntInstance := AScript.FDefInstances[0];
      end;
    finally
      savedInstances.Free;
    end;
  end;
end;

procedure TatVirtualMachine.ExecuteDebugScript(AScript: TatScript;
  AScripterWatch: TatScripterWatch = nil; ADebugWatch: TatDebugWatch = nil);
var
  _paused: boolean;
  _CallExecHookEvent: boolean;
  _CurrentInstruction: pSimplifiedCode;
  _NextInstruction: pSimplifiedCode;
  _PrepareInstruction: pSimplifiedCode;
  _StackTop: integer;
  _StackBase: integer;
  _InputBase: integer;
  _OutputBase: integer;
  _InputOffset: integer;
  _OutputOffset: integer;
  _CurrentInputArgBase: integer;
  _CurrentArrayIndexBase: integer;
  _CurrentOutputArgIndex: integer;
  _OutputStackValue: TStackValue;

  AVar: TatVariableInfo;
  AStackPos: integer;
begin
  { executa um script de depuração dentro do processo em execução }
  with AScript do
    if Assigned(FFirstInstruction) then
    begin
      { preserva o estado da máquina virtual }
      _paused := FPaused;
      _CallExecHookEvent := FCallExecHookEvent;
      _CurrentInstruction := FCurrentInstruction;
      _NextInstruction := FNextInstruction;
      _PrepareInstruction := FPrepareInstruction;
      _StackTop := FStackTop;
      _StackBase := FStackBase;
      _InputBase := FInputBase;
      _OutputBase := FOutputBase;
      _InputOffset := FInputOffset;
      _OutputOffset := FOutputOffset;
      _CurrentInputArgBase := FCurrentInputArgBase;
      _CurrentArrayIndexBase := FCurrentArrayIndexBase;
      _CurrentOutputArgIndex := FCurrentOutputArgIndex;
      _OutputStackValue := FProcStack[FOutputBase];
      try
        { executa o trecho de código compilado, mas dentro da máquina virtual corrente }
        FCurrentInstruction := FFirstInstruction;
        FPaused := false;
        while FCurrentInstruction <> nil do
        begin
          FNextInstruction := FCurrentInstruction^.Next;
          FCurrentInstruction.Compute;
          FCurrentInstruction := FNextInstruction;
        end;
        { remove as novas variáveis eventualmente alocadas da pilha (Unprepare) }
        dec(FStackTop, FDebugScriptMainRoutine.DeclarationInstruction^.vInteger);

        // Get the value of debug variable, if this debug script is being executed
        // for a script debug
        if (AScripterWatch <> nil) or (ADebugWatch <> nil) then
        begin
          { Get the value of temporary variable which was allocated in the debug script }
          AStackPos := -1;
          AVar := AScript.ScriptInfo.Globals.FindByName('_TatDebugWatch_expression_');
          if AVar <> nil then
            AStackPos := AVar.VarIndex
          else
          begin
            AVar := AScript.FDebugScriptMainRoutine.VariableByName('_TatDebugWatch_expression_');
            if AVar <> nil then
              AStackPos := self.FStackBase + AVar.VarIndex;
          end;

          if AScripterWatch <> nil then
          begin
            if AStackPos <> -1 then
            begin
              AScripterWatch.FLastResult := DerefValue(self.FProcStack[AStackPos]);
              AScripterWatch.FWatchStatus := wsEvaluated;
            end
            else
              AScripterWatch.FWatchStatus := wsRuntimeError;
          end;

          if ADebugWatch <> nil then
          begin
            if AStackPos <> -1 then
            begin
              ADebugWatch.LastResult := DerefValue(self.FProcStack[AStackPos]);
              ADebugWatch.WatchStatus := wsEvaluated;
            end
            else
              ADebugWatch.WatchStatus := wsRuntimeError;
          end;
        end;
      finally
        { restaura o estado anterior da máquina virtual }
        FPaused := _paused;
        FCallExecHookEvent := _CallExecHookEvent;
        FCurrentInstruction := _CurrentInstruction;
        FNextInstruction := _NextInstruction;
        FPrepareInstruction := _PrepareInstruction;
        FStackTop := _StackTop;
        FStackBase := _StackBase;
        FInputBase := _InputBase;
        FOutputBase := _OutputBase;
        FInputOffset := _InputOffset;
        FOutputOffset := _OutputOffset;
        FCurrentInputArgBase := _CurrentInputArgBase;
        FCurrentArrayIndexBase := _CurrentArrayIndexBase;
        FCurrentOutputArgIndex := _CurrentOutputArgIndex;
        FProcStack[FOutputBase] := _OutputStackValue;
      end;
    end
    else
      InternalError('Debugger script not compiled');
end;

procedure TatVirtualMachine.RuntimeError(msg: string);
begin
  if FScript <> nil then
    FScript.RuntimeError(msg);
end;

procedure TatVirtualMachine.DoRunningChanged;
begin
  if Assigned(FOnRunningChanged) then
    FOnRunningChanged(self);
  if not Script.IsDebugScript then
    Script.Scripter.CheckRunningChanged(self);
end;

function TatVirtualMachine.GetOnDebugHook: TNotifyEvent;
begin
  if (Script <> nil) and (Script.Scripter <> nil) then
    Result := Script.Scripter.FOnDebugHook
  else
    Result := nil;
end;

procedure TatVirtualMachine.SetOnDebugHook(const Value: TNotifyEvent);
begin
  if (Script <> nil) and (Script.Scripter <> nil) then
    Script.Scripter.FOnDebugHook := Value;
end;

{ TatScripterEventBroker }

constructor TatScripterEventBroker.Create(AOwner: TComponent);
begin
  inherited;
  FScripter := TatCustomScripter(AOwner);
  FDispatchers := TatEventDispatchers.Create(self, TatEventDispatcher);
end;

destructor TatScripterEventBroker.Destroy;
begin
  inherited;
  { unset all events setted by current event broker }
  UnsetAllEvents;
  if Assigned(FDispatchers) then
    FDispatchers.Free;
end;

procedure TatScripterEventBroker.UnsetAllEvents;
var
  c: integer;
begin
  with FDispatchers do
    for c := Count - 1 downto 0 do
      if Items[c].FIsComponent or not(csDestroying in ComponentState) then
        Items[c].Unset;
end;

function TatScripterEventBroker.InternalSetEvent(AInstance: TObject; APropInfo: PPropInfo;
  ARoutineName: string; AScripter: TatCustomScripter; APlacement: TatEventPlacement;
  AScript: TatScript): TatEventDispatcher;
var
  m: TMethod;
  adap: TatEventAdapter;
begin
  { find compatible event adapter }
  adap := FEventAdapters.AdapterByPropInfo(APropInfo);

  { instance a new event dispatcher (specialized FDispatchers.Add) }
  Result := adap.FDispatcherClass.Create(FDispatchers);
  with Result do
  begin
    FAdapter := adap;
    SetInstance(AInstance);
    FPropInfo := APropInfo;
    FScripter := AScripter;
    if Assigned(AScript) then
      FScript := AScript
    else
      FScript := AScripter.CurrentScript;
    { For easy backward compatibility, puts a reference to FScript object inside the RoutineName string }
    FRoutineName := Format('[%s]%s', [inttostr(IntObject(FScript)), ARoutineName]);

    FOldCall := GetMethodPropEx(AInstance, APropInfo);
    case APlacement of
      epTopCall:
        FAfterCall := FOldCall;
      epBottomCall:
        FBeforeCall := FOldCall;
    end;

    { replace original event by event adapter dispatcher }
    m.Data := Result;
    m.Code := adap.FMethodCode;
    SetMethodPropEx(AInstance, APropInfo, m);
  end;

  { event set opportunity }
  if Assigned(FOnSetEvent) then
    FOnSetEvent(Result);
end;

function TatScripterEventBroker.GetOldMethod(m: TMethod): TMethod;
begin
  if TObject(m.Data) is TatEventDispatcher then
    with TatEventDispatcher(m.Data) do
      Result := OldCall
  else
    Result := NilMethod;

  (* this implementation avoid unset method that cannot be reached at runtime
    by natural method sequence. I guess this would not be the better behaviour

    if TObject(m.Data) is TatEventDispatcher then
    with TatEventDispatcher(m.Data) do
    if SameMethod(OldCall,BeforeCall) then
    result := BeforeCall
    else
    if SameMethod(OldCall,AfterCall) then
    result := AfterCall
    else
    result := NilMethod
    else
    result := NilMethod; *)
end;

function TatScripterEventBroker.MethodIsDesiredDispatcher(m: TMethod; ARoutineName: string;
  AScripter: TatCustomScripter): boolean;
begin
  { criteria: m should correspond to an event dispatcher,
    event disptacher should be owned by current event broker,
    (routine name should be null or match dispatcher routine name) and
    (scripter should be nil or match dispatcher scripter) }
  if (TObject(m.Data) is TatEventDispatcher) then
    with TatEventDispatcher(m.Data) do
      if EventBroker = self then
        Result := ((AScripter = nil) or (AScripter = Scripter)) and
          ((ARoutineName = '') or SameText(ARoutineName, RoutineName))
      else
        Result := false
  else
    Result := false;
end;

function TatScripterEventBroker.GetDispatcherFromMethod(m: TMethod): TatEventDispatcher;
begin
  Result := TObject(m.Data) as TatEventDispatcher;
end;

function TatScripterEventBroker.GetMethodPropEx(AInstance: TObject; APropInfo: PPropInfo): TMethod;
{$IFDEF DELPHI2010_LVL}
var
  Context: TRttiContext;
  prop: TRttiProperty;
  PropName: string;
  {$ENDIF}
begin
  {$IFDEF DELPHI2010_LVL}
  PropName := PropInfoName(APropInfo);
  if IsPublishedProp(AInstance, PropName) then
    {$ENDIF}
    Result := GetMethodProp(AInstance, APropInfo)
    {$IFDEF DELPHI2010_LVL}
  else
  begin
    Result := NilMethod;
    Context := TRttiContext.Create;
    try
      prop := Context.GetType(AInstance.ClassType).GetProperty(PropName);
      if prop <> nil then
        prop.GetValue(AInstance).TryAsType<TMethod>(Result);
    finally
      Context.Free;
    end;
  end;
  {$ENDIF}
end;

function TatScripterEventBroker.GetAssignedRoutineName(AInstance: TObject; APropName: string;
  AScripter: TatCustomScripter): string;
var
  currentMethod, prevMethod, auxMethod: TMethod;
  dispatcher: TatEventDispatcher;
  APropInfo: PPropInfo;
  AMachine: TatVirtualMachine;
begin
  APropInfo := GetPropInfo(AInstance, APropName);

  Result := '';

  if Assigned(APropInfo) then
    currentMethod := GetMethodPropEx(AInstance, APropInfo)
  else
    FatalError('Invalid property (event) information or property is not published');

  prevMethod := NilMethod;

  { explore event stream to find the desired dispatcher }
  auxMethod := currentMethod;
  while AssignedMethod(auxMethod) and not MethodIsDesiredDispatcher(auxMethod, '', AScripter) do
  begin
    prevMethod := auxMethod;
    auxMethod := GetOldMethod(auxMethod);
  end;

  if AssignedMethod(auxMethod) then
  begin
    dispatcher := GetDispatcherFromMethod(auxMethod);
    if dispatcher <> nil then
    begin
      Result := dispatcher.RoutineName;
      if (Length(Result) > 0) and (Result[1] = '[') then
        dispatcher.Scripter.GetInfoFromRoutineName(Result, AMachine);
    end;
  end;
end;

function TatScripterEventBroker.InternalUnsetEvent(AInstance: TObject; APropInfo: PPropInfo;
  ARoutineName: string; AScripter: TatCustomScripter): boolean;
var
  currentMethod, prevMethod, auxMethod, oldMethod: TMethod;
  dispatcher: TatEventDispatcher;
begin
  { get current method attached to instance property }
  if Assigned(APropInfo) then
    currentMethod := GetMethodPropEx(AInstance, APropInfo)
  else
    FatalError('Invalid property (event) information or property is not published');

  prevMethod := NilMethod;

  { explore event stream to find the desired dispatcher }
  auxMethod := currentMethod;
  while AssignedMethod(auxMethod) and not MethodIsDesiredDispatcher(auxMethod, ARoutineName,
    AScripter) do
  begin
    prevMethod := auxMethod;
    auxMethod := GetOldMethod(auxMethod);
  end;

  { if found then should redirect instance property (event) and remove the dispatcher }
  if AssignedMethod(auxMethod) then
  begin
    Result := True;
    dispatcher := GetDispatcherFromMethod(auxMethod);

    { event unset opportunity }
    if Assigned(FOnUnsettingEvent) then
      FOnUnsettingEvent(dispatcher, Result);

    if Result then
      with dispatcher do
      begin
        { previous method attached }
        oldMethod := OldCall;

        { if the method have a dispatcher linked to him,
          then should redirect the event stream (like a linked list) }
        if AssignedMethod(prevMethod) then // equivalent to currentMethod <> auxMethod
          with GetDispatcherFromMethod(prevMethod) do
          begin
            if SameMethod(OldCall, BeforeCall) then
            begin
              { redirect top call dispatcher }
              BeforeCall := oldMethod;
              OldCall := oldMethod;
            end;
            if SameMethod(OldCall, AfterCall) then
            begin
              { redirect bottom call dispatcher }
              AfterCall := oldMethod;
              OldCall := oldMethod;
            end;
          end;

        if SameMethod(currentMethod, auxMethod) then // equivalent to not AssignedMethod(prevMethod)
          { redirect the instance property (event) to original method }
          SetMethodPropEx(AInstance, APropInfo, oldMethod);

        { remove dispatcher found }
        Free;
      end;
  end
  else
    Result := false;
end;

function TatScripterEventBroker.SetEvent(AInstance: TObject; APropName: string;
  ARoutineName: string; AScripter: TatCustomScripter; APlacement: TatEventPlacement;
  AScript: TatScript = nil): TatEventDispatcher;
var
  procede: boolean;
begin
  Result := nil;
  if Assigned(AInstance) and (AInstance.ClassInfo <> nil) and (APropName > '') then
  begin
    procede := True;

    { event setting opportunity }
    if Assigned(FOnSettingEvent) then
      FOnSettingEvent(self, AInstance, APropName, ARoutineName, AScripter, APlacement, procede);

    if procede then
      Result := InternalSetEvent(AInstance, GetPropInfo(AInstance, APropName), ARoutineName,
        AScripter, APlacement, AScript)
    else
      Result := nil;
  end
  else
    FatalError('Cannot set event without an instance and a published property name');
end;

procedure TatScripterEventBroker.SetMethodPropEx(AInstance: TObject; APropInfo: PPropInfo;
  AMethod: TMethod);
{$IFDEF DELPHI2010_LVL}
var
  Context: TRttiContext;
  prop: TRttiProperty;
  mvalue: TValue;
  PropName: string;
  {$ENDIF}
begin
  {$IFDEF DELPHI2010_LVL}
  PropName := PropInfoName(APropInfo);
  if IsPublishedProp(AInstance, PropName) then
    {$ENDIF}
    SetMethodProp(AInstance, APropInfo, AMethod)
    {$IFDEF DELPHI2010_LVL}
  else
  begin
    Context := TRttiContext.Create;
    try
      prop := Context.GetType(AInstance.ClassType).GetProperty(PropName);
      if prop <> nil then
      begin
        TValue.Make(@AMethod, prop.PropertyType.Handle, mvalue);
        prop.SetValue(AInstance, mvalue);
      end;
    finally
      Context.Free;
    end;
  end;
  {$ENDIF}
end;

function TatScripterEventBroker.UnsetEvent(AInstance: TObject; APropName: string;
  ARoutineName: string = ''; AScripter: TatCustomScripter = nil): boolean;
begin
  Result := false;
  if Assigned(AInstance) and (AInstance.ClassInfo <> nil) and (APropName > '') then
    Result := InternalUnsetEvent(AInstance, GetPropInfo(AInstance, APropName), ARoutineName,
      AScripter)
  else
    FatalError('Cannot unset event without an instance and a published property name');
end;

procedure TatScripterEventBroker.SetDispatchers(const Value: TatEventDispatchers);
begin
  FDispatchers.Assign(Value);
end;

procedure TatScripterEventBroker.SetOnExecuteEvent(const Value: TExecuteEventProc);
begin
  FOnExecuteEvent := Value;
end;

procedure TatScripterEventBroker.SetOnSetEvent(const Value: TSetEventProc);
begin
  FOnSetEvent := Value;
end;

procedure TatScripterEventBroker.SetOnUnsettingEvent(const Value: TUnsetEventProc);
begin
  FOnUnsettingEvent := Value;
end;

procedure TatScripterEventBroker.SetOnSettingEvent(const Value: TSettingEventProc);
begin
  FOnSettingEvent := Value;
end;

function TatScripterEventBroker.UnsetEvents(AInstance: TObject; APropName: string): boolean;
begin
  Result := false;
  if Assigned(AInstance) and (AInstance.ClassInfo <> nil) and (APropName > '') then
    Result := InternalUnsetEvents(AInstance, GetPropInfo(AInstance, APropName))
  else
    FatalError('Cannot unset events without an instance and a published property name');
end;

function TatScripterEventBroker.InternalUnsetEvents(AInstance: TObject;
  APropInfo: PPropInfo): boolean;
var
  found: boolean;
begin
  { unset all event dispatchers attached to AInstance -> APropName
    since all of them are owned by current event broker }
  Result := false;
  repeat
    found := InternalUnsetEvent(AInstance, APropInfo, '', nil);
    if found then
      Result := True;
  until not found;
end;

{ TatEventAdapters }

function TatEventAdapters.FindAdapter(ARttiInfo: PTypeInfo): TatEventAdapter;
var
  c: integer;
begin
  for c := 0 to Count - 1 do
    if Items[c].FRttiInfo = ARttiInfo then
    begin
      Result := Items[c];
      exit;
    end;
  Result := nil;
end;

function TatEventAdapters.DefineEventAdapter(ARttiInfo: PTypeInfo;
  ADispatcherClass: TDispatcherClass; AMethodCode: pointer; ACheck: boolean): TatEventAdapter;
begin
  Result := nil;
  if Assigned(ARttiInfo) and (ARttiInfo.Kind = TTypeKind(tkMethod)) then
    if Assigned(ADispatcherClass) then
      if Assigned(AMethodCode) then
      begin
        { find event by RttiInfo,
          if found then replace definition,
          otherwise add a new definition }
        if ACheck then
        begin
          Result := FindAdapter(ARttiInfo);
          if not Assigned(Result) then
            Result := Add;
        end
        else
          Result := Add;

        with Result do
        begin
          FRttiInfo := ARttiInfo;
          FMethodCode := AMethodCode;
          FDispatcherClass := ADispatcherClass;
        end;
      end
      else
        FatalError('Invalid method pointer on DefineEventAdapter')
    else
      FatalError('Invalid class reference on DefineEventAdapter')
  else
    FatalError('Invalid procedure type information on DefineEventAdapter');
end;

function TatEventAdapters.AdapterByPropInfo(APropInfo: PPropInfo): TatEventAdapter;
var
  c: integer;
  typinf: PTypeInfo;
begin
  Result := nil;
  { get type information from property information }
  if Assigned(APropInfo) then
  begin
    typinf := APropInfo^.PropType^;
    if typinf.Kind = TTypeKind(tkMethod) then
      { find and return an adapter based on Rtti property info }
      { use reverse scannig to prior last registered adapters }
      for c := Count - 1 downto 0 do
        if Items[c].FRttiInfo = typinf then
        begin
          Result := Items[c];
          exit;
        end;
    { event adapter not found }
    FatalError(Format('Event adapter not defined for ''%s'' property (%s)',
      [APropInfo.Name, typinf.Name]));
  end
  else
    FatalError('Invalid property (event) information or property is not published');
end;

function TatEventAdapters.Add: TatEventAdapter;
begin
  Result := TatEventAdapter(inherited Add);
end;

function TatEventAdapters.GetItem(i: integer): TatEventAdapter;
begin
  Result := TatEventAdapter(inherited Items[i]);
end;

{ TatEventDispatchers }

function TatEventDispatchers.Add: TatEventDispatcher;
begin
  Result := TatEventDispatcher(inherited Add);
end;

function TatEventDispatchers.GetItem(i: integer): TatEventDispatcher;
begin
  Result := TatEventDispatcher(inherited Items[i]);
end;

{ TatEventDispatcher }

constructor TatEventDispatcher.Create(ACollection: TCollection);
begin
  inherited;
  FNotificator := TatDispatcherRemoveNotificator.Create(nil);
  FNotificator.FDispatcher := self;
end;

destructor TatEventDispatcher.Destroy;
begin
  FNotificator.Free;
  inherited;
end;

function TatEventDispatcher.DoOnExecuteEvent: boolean;
begin
  Result := True;
  with TatScripterEventBroker(TatEventDispatchers(Collection).GetOwner) do
    if Assigned(FOnExecuteEvent) then
      FOnExecuteEvent(self, Result);
end;

function TatEventDispatcher.EventBroker: TatScripterEventBroker;
begin
  Result := TatScripterEventBroker(TatEventDispatchers(Collection).GetOwner);
end;

procedure TatEventDispatcher.SetAdapter(const Value: TatEventAdapter);
begin
  FAdapter := Value;
end;

procedure TatEventDispatcher.SetAfterCall(const Value: TMethod);
begin
  FAfterCall := Value;
end;

procedure TatEventDispatcher.SetBeforeCall(const Value: TMethod);
begin
  FBeforeCall := Value;
end;

procedure TatEventDispatcher.SetInstance(const Value: TObject);
begin
  if FInstance <> Value then
  begin
    { disallow EventBroker to receive notifications from FInstance (when FInstance is a component) }
    FIsComponent := Assigned(FInstance) and (FInstance is TComponent);
    if FIsComponent then
      TComponent(FInstance).RemoveFreeNotification(FNotificator);

    FInstance := Value;

    { allow EventBroker to know receive notifications from FInstance (when FInstance is a component) }
    FIsComponent := Assigned(FInstance) and (FInstance is TComponent);
    if FIsComponent then
      TComponent(FInstance).FreeNotification(FNotificator);
  end;
end;

procedure TatEventDispatcher.SetOldCall(const Value: TMethod);
begin
  FOldCall := Value;
end;

procedure TatEventDispatcher.SetPropInfo(const Value: PPropInfo);
begin
  FPropInfo := Value;
end;

procedure TatEventDispatcher.SetScripter(const Value: TatCustomScripter);
begin
  FScripter := Value;
end;

procedure TatEventDispatcher.Unset;
begin
  { remove this dispatcher from EventBroker }
  EventBroker.InternalUnsetEvent(FInstance, FPropInfo, FRoutineName, FScripter);
end;

{ TatEventAdapter }

procedure TatEventAdapter.Assign(ASource: TPersistent);
begin
  if ASource is TatEventAdapter then
  begin
    FRttiInfo := TatEventAdapter(ASource).FRttiInfo;
    FMethodCode := TatEventAdapter(ASource).FMethodCode;
    FDispatcherClass := TatEventAdapter(ASource).FDispatcherClass;
  end
  else
    inherited;
end;

{ TatDispatcherRemoveNotificator }

procedure TatDispatcherRemoveNotificator.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  { unset event dispatcher when component,
    that owns event property attached to this dispatcher,
    has been destroyed }
  if (FDispatcher.FInstance = AComponent) and (Operation = opRemove) then
    FDispatcher.Unset;
end;

{ TatCustomScripter - Event support }

procedure TatCustomScripter.TranslateMethodGetter(AMachine: TatVirtualMachine; AInstance: TObject;
  APropInfo: PPropInfo; var AValue: TScriptValue);
var
  m: TMethod;
begin
  m := FEventBroker.GetMethodPropEx(AInstance, APropInfo);
  { if event is setted to this scripter and to an event dispatcher
    then RoutineName may be returned,
    otherwise return a generic method representation }
  if (TObject(m.Data) is TatEventDispatcher) and (TatEventDispatcher(m.Data).Scripter = self) then
    AValue := TatEventDispatcher(m.Data).RoutineName
  else
    AValue := Format('@%.4X-%.4X', [IntObject(m.Data), IntObject(m.Code)]);
end;

procedure TatCustomScripter.TranslateMethodSetter(AMachine: TatVirtualMachine; AInstance: TObject;
  APropInfo: PPropInfo; AValue: TScriptValue);
const
  NilMethod: TMethod = (Code: nil; Data: nil);
var
  StrValue: string;
begin
  {$IFDEF NEWSTACK}
  if AValue.IsEmpty or AValue.IsOrdinal or (AValue.AsString = '') then
  {$ELSE}
  if VarIsEmpty(AValue) or VarIsNull(AValue) or (VarToStr(AValue) = '') or
    (((VarType(AValue) = varInteger) or (VarType(AValue) = varByte)
    {$IFDEF DELPHI6_LVL} or (VarType(AValue) = varWord){$ENDIF}
    or (VarType(AValue) = varSmallint)) and (AValue = 0 { CoreConst[Nil] } )) then
  {$ENDIF}

    { Unsetting event }
    case FEventUnsetMode of
      euReplaceNil:
        { replace the event to NIL throuh event broker }
        FEventBroker.InternalSetEvent(AInstance, APropInfo, '', self, epReplaceCall, nil);
      euOriginalEvent:
        { restore the method to the original state
          (equal to state before pushing the first event dispatcher
          owned by this scripter) }
        FEventBroker.InternalUnsetEvents(AInstance, APropInfo);
      euClearEvent:
        { set the method to NIL }
        FEventBroker.SetMethodPropEx(AInstance, APropInfo, NilMethod);
      euPreviousEvent:
        { remove only the last setted event dispatcher
          (if any, owned by this scripter) }
        FEventBroker.InternalUnsetEvent(AInstance, APropInfo, '', self);
    end
  else
  begin
    {$IFDEF NEWSTACK}
    StrValue := AValue.AsString;
    {$ELSE}
    StrValue := VarToStr(AValue);
    {$ENDIF}
    case FEventSetMode of
      esReplaceEvent:
        { replace the event, through the event broker }
        FEventBroker.InternalSetEvent(AInstance, APropInfo, StrValue, self,
          epReplaceCall, nil);
      esAddEventOnTop:
        { insert a new event handler before the previous event handler,
          through the event broker }
        FEventBroker.InternalSetEvent(AInstance, APropInfo, StrValue, self, epTopCall, nil);
      esAddEventOnBottom:
        { append a new event handler after the previous event handler,
          through the event broker }
        FEventBroker.InternalSetEvent(AInstance, APropInfo, StrValue, self,
          epBottomCall, nil);
    end;
  end;
end;

{ global event adapter registration }
{ use ACheck=True to avoid redefinition for adapter of same PTypeInfo }
function DefineEventAdapter(ARttiInfo: PTypeInfo; ADispatcherClass: TDispatcherClass;
  AMethodCode: pointer; ACheck: boolean = True): TatEventAdapter;
begin
  Result := EventAdapters.DefineEventAdapter(ARttiInfo, ADispatcherClass, AMethodCode, ACheck);
end;

{ TatVirtualMachines }

function TatVirtualMachines.Add: TatVirtualMachine;
begin
  Result := TatVirtualMachine(inherited Add);
end;

function TatVirtualMachines.GetItems(i: integer): TatVirtualMachine;
begin
  Result := TatVirtualMachine(inherited Items[i]);
end;

{ TatUsedUnits }

function TatUsedUnits.Add: TatUsedUnit;
begin
  Result := TatUsedUnit(inherited Add);
end;

constructor TatUsedUnits.Create(AScripter: TatCustomScripter);
begin
  FScripter := AScripter;
  inherited Create(TatUsedUnit);
end;

function TatUsedUnits.FindByName(AUnitName: string): TatUsedUnit;
var
  c: integer;
begin
  Result := nil;
  for c := 0 to Count - 1 do
    if SameText(AUnitName, Items[c].UnitName) then
    begin
      Result := Items[c];
      Break;
    end;
end;

function TatUsedUnits.GetItem(i: integer): TatUsedUnit;
begin
  Result := TatUsedUnit(inherited Items[i]);
end;

{ TatDebugWatches }

function TatDebugWatches.Add: TatDebugWatch;
begin
  Result := TatDebugWatch(inherited Add);
end;

function TatDebugWatches.GetItem(i: integer): TatDebugWatch;
begin
  Result := TatDebugWatch(inherited Items[i]);
end;

procedure TatDebugWatches.CompileAndEvaluateAll;
var
  c: integer;
begin
  { recompila e executa todas as watches }
  for c := 0 to Count - 1 do
    CompileAndEvaluate(Items[c]);
end;

procedure TatDebugWatches.CompileAndEvaluate(AWatch: TatDebugWatch);
begin
  with AWatch do
    if Enabled and (Expression > '') then
      CompileAndEvaluate;
end;

procedure TatDebugWatches.EvaluateAll;
var
  c: integer;
begin
  { executa todas as watches (recompila apenas as que têm o flag de recompilação forçada) }
  for c := 0 to Count - 1 do
    Evaluate(Items[c]);
end;

procedure TatDebugWatches.Evaluate(AWatch: TatDebugWatch);
begin
  with AWatch do
    if Enabled and (Expression > '') then
      if AlwaysCompile or (WatchStatus = wsNotEvaluated) then
      begin
        // when the IDE is running an Exception can be triggered here
        // when debugging options "stop on exception" is enabled.
        // This exception is handled correct when run not from the IDE
        CompileAndEvaluate;
      end
      else
        Evaluate;
end;

{ TatDebugWatch }

procedure TatDebugWatches.Reset;
var
  c: integer;
begin
  for c := 0 to Count - 1 do
    Items[c].Reset;
end;

constructor TatDebugWatch.Create(ACollection: TCollection);
begin
  inherited;
  { cria um novo script para compilação e execução da expressão do watch }
  FDebugScript := Machine.FScript.FScripter.FScripts.Add;
  FDebugScript.FIsDebugScript := True;
  FDebugScript.FOnDestroy := ScriptDestroyed;
  FAlwaysCompile := True;
  FEnabled := True;
end;

destructor TatDebugWatch.Destroy;
begin
  if Assigned(FDebugScript) then
    FDebugScript.Free;
  inherited;
end;

procedure TatDebugWatch.ScriptDestroyed(Sender: TObject);
begin
  { remove a referência ao script que está sendo destruído }
  FDebugScript := nil;
end;

function TatDebugWatch.Machine: TatVirtualMachine;
begin
  Result := TatDebugWatches(Collection).GetOwner as TatVirtualMachine;
end;

procedure TatDebugWatch.CompileAndEvaluate;
begin
  WatchStatus := wsNotEvaluated;
  try
    if Machine.Running then
      Machine.CompileDebugScript(DebugScript)
    else
      Abort;
    { executa o script que acaba de ser compilado com sucesso }
    Evaluate;
  except
    on ex: Exception do
    begin
      { em caso de falha de compilação apenas sinaliza no watch que é inválido }
      WatchStatus := wsCompileError;
    end;
  end;
end;

procedure TatDebugWatch.Evaluate;
begin
  WatchStatus := wsNotEvaluated;
  try
    if Machine.Running then
      Machine.ExecuteDebugScript(DebugScript, nil, self)
    else
      Abort;
  except
    on ex: Exception do
    begin
      { em caso de falha de execução apenas sinaliza no watch que é inválido }
      WatchStatus := wsRuntimeError;
    end;
  end;
end;

procedure TatDebugWatch.SetExpression(const Value: string);
begin
  if FExpression <> Value then
  begin
    FExpression := Value;
    FDebugScript.SourceCode.Text := FDebugScript.EncodeSingleAssign('_TatDebugWatch_expression_',
      FExpression);
    WatchStatus := wsNotEvaluated;
  end;
end;

{ TatDebugWatch }

procedure TatDebugWatch.SetLastResult(const Value: TScriptValue);
begin
  {$IFDEF NEWSTACK}
  if (FLastResult.TypeInfo <>  Value.TypeInfo) or
    not ScriptValueEqual(FLastResult, Value) then
  {$ELSE}
  if (VarType(FLastResult) <> VarType(Value)) or (Value <> FLastResult) then
  {$ENDIF}
  begin
    FLastResult := Value;
    FResultChanged := True;
  end
  else
    FResultChanged := false;
end;

procedure TatDebugWatch.Reset;
begin
  DebugScript.Clear;
  LastResult := NullValue;
  WatchStatus := wsNotEvaluated;
end;

procedure TatDebugWatch.FullEvaluate;
begin
  if (Collection is TatDebugWatches) then
    TatDebugWatches(Collection).Evaluate(self);
end;

{ TatScriptBasedLibrary }

procedure TatScriptBasedLibrary.GetScriptVarProc(AMachine: TatVirtualMachine);
var
  AGlobalVar: TatVariableInfo;
begin
  AGlobalVar := GetRunScript(AMachine).ScriptInfo.Globals.FindByName(AMachine.CurrentPropertyName);
  if AGlobalVar <> nil then
    AMachine.ReturnOutputArg(AGlobalVar.Value)
  else
    AMachine.ReturnOutputArg(NullValue);
end;

procedure TatScriptBasedLibrary.SetScriptVarProc(AMachine: TatVirtualMachine);
var
  AGlobalVar: TatVariableInfo;
begin
  AGlobalVar := GetRunScript(AMachine).ScriptInfo.Globals.FindByName(AMachine.CurrentPropertyName);
  if AGlobalVar <> nil then
    AGlobalVar.Value := AMachine.GetInputArg(0);
end;

procedure TatScriptBasedLibrary.ExecSubRoutineProc(AMachine: TatVirtualMachine);
var
  params: array of TScriptValue;
//  args: array of TVarRec;
  i: integer;
  oldCur: pSimplifiedCode;
  methName: string;
begin
  SetLength(params, AMachine.InputArgCount);

  for i := 0 to AMachine.InputArgCount - 1 do
    params[i] := AMachine.GetInputArg(i);

  oldCur := AMachine.FCurrentInstruction;

  methName := AMachine.CurrentMethodName;
  if methName = '' then
    methName := AMachine.CurrentPropertyName;
  if methName = '' then
    AMachine.RuntimeError(
      'Could not execute script-based method. Property/method not specified.');

  AMachine.ReturnOutputArg(GetRunScript(AMachine).VirtualMachine.IntExecuteSubroutine
    (methName, params));
  AMachine.FCurrentInstruction := oldCur;

  if not AMachine.Halted then
    for i := 0 to AMachine.InputArgCount - 1 do
      AMachine.SetInputArgIfByRef(i, params[i]);
end;

procedure TatScriptBasedLibrary.Init;
var
  c: integer;
  d: integer;
  i: integer;
  met: TatMethod;
  rout: TatRoutineInfo;
begin
  if FRegClass = nil then
    FRegClass := ClassType;
  if FRegClassName = '' then
    FRegClassName := FRegClass.ClassName;

  if FRegClass <> ClassType then
  begin
    i := Scripter.Classes.IndexOf(FRegClassName);
    if i >= 0 then
    begin
      (* **************if Scripter.Classes[i].FBaseScript <> FInternalScript then
        FInternalScript.RuntimeError(Format('Class "%s" already registered by another script.', [FRegClassName]));************ *)
    end;
  end;

  FNewClass := Scripter.DefineClass(FRegClass, FRegClassName);
  FNewClass.FBaseScript := FInternalScript;

  With FInternalScript.ScriptInfo do
  begin
    for c := 0 to Routines.Count - 1 do
      if Routines[c].Name <> '___MAIN___' then
      begin
        if Routines[c].Visibility <> rvPrivate then
        begin
          rout := Routines[c];
          met := FNewClass.DefineNewMethod(Routines[c].Name, rout.ArgCount, tkVariant, nil,
            ExecSubRoutineProc);
          FMethodList.Add(met);
          for d := 0 to rout.Variables.Count - 1 do
          begin
            if (rout.Variables[d].Modifier = moVar) and (rout.FByRefArgMask > 0) then
              met.SetVarArgs([d]);

            // if it's parameter, the copy the param name to method
            if (d < rout.ArgCount) then
              if d < met.ArgDefs.Count then
              begin
                met.ArgDefs[d].FName := rout.Variables[d].VarName;
                met.ArgDefs[d].FDataTypeName := rout.Variables[d].TypeDecl;
              end;
          end;
        end;
      end;
    for c := 0 to Globals.Count - 1 do
      Case Globals[c].Visibility of
        vvPublic:
          FPropList.Add(FNewClass.DefineNewProp(Globals[c].VarName, tkVariant, GetScriptVarProc,
            SetScriptVarProc));
        vvPrivate:
          ; // do not register private variables
      end;
  end;
end;

constructor TatScriptBasedLibrary.Create(AScripter: TatCustomScripter);
begin
  inherited Create(AScripter);
  FMethodList := TList.Create;
  FPropList := TList.Create;
end;

destructor TatScriptBasedLibrary.Destroy;
begin
  FMethodList.Free;
  FPropList.Free;
  inherited;
end;

procedure TatScriptBasedLibrary.Finalize;
var
  c: integer;
begin
  for c := 0 to FMethodList.Count - 1 do
    TatMethod(FMethodList[c]).Free;
  FMethodList.Clear;
  for c := 0 to FPropList.Count - 1 do
    TatProperty(FPropList[c]).Free;
  FPropList.Clear;

  { if FRegClass <> ClassType then
    FNewClass.Free; }
end;

function TatScriptBasedLibrary.GetRunScript(AMachine: TatVirtualMachine): TatScript;
var
  FormIntf: IScriptBasedForm;
begin
  if AMachine.CurrentObject is TatScriptBasedLibrary then
    Result := TatScriptBasedLibrary(AMachine.CurrentObject).FInternalScript
  else if AMachine.CurrentObject is TScriptBaseObject then
    Result := TScriptBaseObject(AMachine.CurrentObject).FRunScript
  else
    if (AMachine.Scripter.ScriptFormClass <> nil) and (AMachine.CurrentObject is AMachine.Scripter.ScriptFormClass) then
    begin
      if not Supports(AMachine.CurrentObject, IScriptBasedForm, FormIntf) then
        Self.FInternalScript.RuntimeError('IScriptBasedForm not found in ScriptFormClass');
      Result := FormIntf.GetRunScript;
    end
    else
    begin
      Result := FInternalScript;
      if (Result <> nil) and (Result.ScriptInfo <> nil) then
      begin
        if (Result.ScriptInfo.Behavior in [sbForm, sbClass]) then
          raise EAccessViolation.Create('Access Violation: Object reference in null');
      end;
    end;
end;

{ TScripterLibraryOptions }

procedure TScripterLibraryOptions.Assign(Source: TPersistent);
begin
  if Source is TScripterLibraryOptions then
  begin
    FSearchPath.Assign(TScripterLibraryOptions(Source));
    FSourceFileExt := TScripterLibraryOptions(Source).FSourceFileExt;
    FCompiledFileExt := TScripterLibraryOptions(Source).FCompiledFileExt;
    FFormFileExt := TScripterLibraryOptions(Source).FFormFileExt;
    FUseScriptFiles := TScripterLibraryOptions(Source).FUseScriptFiles;
  end
  else
    inherited Assign(Source);
end;

constructor TScripterLibraryOptions.Create;
begin
  FSearchPath := TStringList.Create;
end;

destructor TScripterLibraryOptions.Destroy;
begin
  FSearchPath.Free;
  inherited;
end;

procedure TScripterLibraryOptions.SetSearchPath(const Value: TStrings);
begin
  FSearchPath.Assign(Value);
end;

{ TatDLL }

procedure TatDLL.Finalize;
var
  c: integer;
begin
  { remove os métodos criados especificamente para o script que declarou esta DLL }
  { varre as rotinas do scripter, procurando naquelas que são externas (dll) }
  with FScript.FScriptInfo do
    for c := Routines.Count - 1 downto 0 do
      with Routines[c] do
        if SameText(FExternalDll, FFileName) then
          { exclui o método correspondente ao nome da rotina }
          FatClass.MethodByName(Copy(FName, 2, 999)).Free;
  inherited;
end;

procedure TatDLL.Init;
begin
  { apenas define uma classe para encapsular os métodos externos }
  FatClass := Scripter.DefineClass(ClassType);
end;

class function TatDLL.LibraryName: string;
begin
  Result := '_DLL_';
end;

{ TatScriptRefactor }

constructor TatScriptRefactor.Create(AScript: TatScript);
begin
  FScript := AScript;
  FDirtySource := True;
end;

function TatScriptRefactor.SourcePos(SubStr: string; FromPos: integer = 1): integer;
var
  PtrStart, PtrFound: PChar;
  Str: string;
begin
  Str := UpcaseSource;
  if (FromPos <= 0) or (FromPos > (Length(Str) - Length(SubStr) + 1)) then
  begin
    Result := 0;
    exit;
  end;
  PtrStart := PChar(Str);
  Inc(PtrStart, FromPos - 1);
  PtrFound := StrPos(PtrStart, PChar(SubStr));
  if PtrFound <> nil then
    Result := PtrFound - PChar(Str) + 1
  else
    Result := 0;
end;

function TatScriptRefactor.GetSource: TStrings;
begin
  if (Script <> nil) then
    Result := Script.SourceCode
  else
    Result := nil;
end;

function TatScriptRefactor.GetUpcaseSource: string;
begin
  if FDirtySource then
  begin
    FUpcaseSource := UpperCase(Source.Text);
    FDirtySource := false;
  end;
  Result := FUpcaseSource;
end;

function TatScriptRefactor.IsQualifiedIdentifierChar(ch: char): boolean;
begin
  Result := ((ch >= 'A') and (ch <= 'Z')) or ((ch >= 'a') and (ch <= 'z')) or
    ((ch >= '0') and (ch <= '9')) or (ch = '.') or (ch = '_');
end;

procedure TatScriptRefactor.UpdateFormHeader(AFormClass, AFileName: string);
begin
end;

function TatScriptRefactor.DeclareRoutine(ProcName: string): integer;
var
  AInfo: TatRoutineInfo;
begin
  AInfo := TatRoutineInfo.Create(nil);
  try
    AInfo.Name := ProcName;
    Result := DeclareRoutine(AInfo);
  finally
    AInfo.Free;
  end;
end;

function TatScriptRefactor.DeclareRoutine(AInfo: TatRoutineInfo): integer;
begin
  Result := 0;
end;

procedure TatScriptRefactor.AddUsedUnit(AUnitName: string);
begin
end;

procedure TatScriptRefactor.BeginRefactor;
begin
  if Script <> nil then
    Inc(Script.FRefactoring);
end;

function TatScriptRefactor.BuildMethodArgs(meth: TatMethod): string;
begin
  Result := BuildMethodHint(meth);
end;

function TatScriptRefactor.BuildMethodHint(meth: TatMethod): string;
begin
  Result := '';
end;

function TatScriptRefactor.BuildPropertyArgs(prop: TatProperty): string;
begin
  Result := BuildPropertyHint(prop);
end;

function TatScriptRefactor.BuildPropertyHint(prop: TatProperty): string;
var
  c: integer;
begin
  Result := '';
  if prop.IndexCount = 1 then
    Result := 'Index'
  else
    for c := 0 to prop.IndexCount - 1 do
    begin
      if c > 0 then
        Result := Result + ';';
      Result := Result + Format('Index%d', [c]);
    end;
end;

function TatScriptRefactor.BuildRoutineHint(routine: TatRoutineInfo): string;
begin
  Result := '';
end;

function TatScriptRefactor.BuildVariableHint(AVar: TatVariableInfo): string;
begin
  Result := '';
end;

procedure TatScriptRefactor.EndRefactor;
begin
  if Script <> nil then
  begin
    dec(Script.FRefactoring);
    if Script.FRefactoring = 0 then
    begin
      // Operations to remove attached events that do not work anymore?
    end;
  end;
end;

{ TatScriptBreaks }

function TatScriptBreaks.Add: TatScriptBreak;
begin
  Result := TatScriptBreak(inherited Add);
end;

function TatScriptBreaks.FindByLine(ALine: integer): TatScriptBreak;
var
  c: integer;
begin
  Result := nil;
  for c := 0 to Count - 1 do
    if Items[c].Line = ALine then
    begin
      Result := Items[c];
      Break;
    end;
end;

function TatScriptBreaks.GetItem(Index: integer): TatScriptBreak;
begin
  Result := TatScriptBreak(inherited Items[Index]);
end;

function TatScriptBreaks.Script: TatScript;
begin
  if GetOwner is TatScript then
    Result := TatScript(GetOwner)
  else
    Result := nil;
end;

procedure TatScriptBreaks.ToggleBreak(ALine: integer);
var
  ABreak: TatScriptBreak;
begin
  ABreak := FindByLine(ALine);
  if ABreak <> nil then
    ABreak.Free
  else
  begin
    ABreak := Add;
    ABreak.Line := ALine;
  end;
end;

procedure TatScriptBreaks.UpdateAll;
var
  c: integer;
begin
  if Script.FOriginalScript <> nil then
    Script.FOriginalScript.Breaks.UpdateAll;
  for c := 0 to Count - 1 do
    Items[c].UpdateBreakPoints;
end;

{ TatScriptBreak }

procedure TatScriptBreak.BreakpointDestroyed(ABreakPoint: TatScriptBreakPoint);
begin
  FBreakList.Remove(ABreakPoint);
end;

constructor TatScriptBreak.Create(Collection: TCollection);
begin
  inherited;
  FBreakList := TBreakPointList.Create(false);
  FLine := -1;
end;

destructor TatScriptBreak.Destroy;
begin
  RemoveBreakPoints;
  FBreakList.Free;
  inherited;
end;

function TatScriptBreak.Script: TatScript;
begin
  if Collection is TatScriptBreaks then
    Result := TatScriptBreaks(Collection).Script
  else
    Result := nil;
end;

procedure TatScriptBreak.SetLine(const Value: integer);
begin
  if FLine <> Value then
  begin
    FLine := Value;
    UpdateBreakPoints;
  end;
end;

procedure TatScriptBreak.RemoveBreakPoints;
begin
  { When destroying a list object, it will be automatically
    removed from FBreakList because the callback method BreakPointDestroyed is called
    and removed the object from list. So we can safely rely that this loop will not be infinite }
  while FBreakList.Count > 0 do
    TatScriptBreakPoint(FBreakList[0]).Free;
end;

procedure TatScriptBreak.UpdateBreakPoints;

  procedure UpdateBreakInScript(ATargetScript: TatScript);
  var
    ATargetInst: pSimplifiedCode;
    ANewBreak: TatScriptBreakPoint;
  begin
    if ATargetScript.ExpandedDebugInfo and ATargetScript.Compiled
      and ATargetScript.FSolvedAddressing then
    begin
      ATargetInst := ATargetScript.VirtualMachine.InstructionByLine(FLine);
      if ATargetInst <> nil then
      begin
        ANewBreak := ATargetScript.VirtualMachine.BreakPoints.InsertNormalBreak(ATargetInst);
        if ANewBreak <> nil then
        begin
          ANewBreak.FNotifyBreak := self;
          FBreakList.Add(ANewBreak);
          if FAutoDestroy then
            ANewBreak.FBreakInst^.vProc := TemporaryBreakProc;
        end;
      end;
    end;
  end;

var
  c: integer;
begin
  { Remove existing breakpoints }
  RemoveBreakPoints;

  { Now insert the breakpoints in the script itself, and all derived scripts (forms) }
  UpdateBreakInScript(Script);
  for c := 0 to Script.FDerivedScripts.Count - 1 do
    UpdateBreakInScript(TatScript(Script.FDerivedScripts[c]));
end;

procedure TatScriptBreak.TemporaryBreakProc;
begin
  { Stop script execution }
  Script.Scripter.Paused := True;

  { Now remove all breakpoints related to the script }
  RemoveBreakPoints;

  Free;
end;

{ TatScripterWatches }

function TatScripterWatches.Add: TatScripterWatch;
begin
  Result := TatScripterWatch(inherited Add);
end;

procedure TatScripterWatches.EvaluateAll;
var
  c: integer;
begin
  for c := 0 to Count - 1 do
    Items[c].Evaluate;
end;

function TatScripterWatches.GetItem(i: integer): TatScripterWatch;
begin
  Result := TatScripterWatch(inherited Items[i]);
end;

function TatScripterWatches.Scripter: TatCustomScripter;
begin
  if GetOwner is TatCustomScripter then
    Result := TatCustomScripter(GetOwner)
  else
    Result := nil;
end;

{ TatScripterWatch }

constructor TatScripterWatch.Create(ACollection: TCollection);
begin
  inherited;
  FDebugScript := Scripter.Scripts.Add;
  FDebugScript.FIsDebugScript := True;
  FDebugScript.FOnDestroy := ScriptDestroyed;
  FEnabled := True;
  Reset;
end;

destructor TatScripterWatch.Destroy;
begin
  if Assigned(FDebugScript) then
    FDebugScript.Free;
  inherited;
end;

procedure TatScripterWatch.Evaluate;
begin
  Reset;
  if (Scripter <> nil) and (Scripter.CurrentScript <> nil) and
    (Scripter.CurrentScript.VirtualMachine <> nil) then
    InternalEvaluate(Scripter.CurrentScript.VirtualMachine);
end;

procedure TatScripterWatch.InternalEvaluate(AMachine: TatVirtualMachine);
begin
  Reset;

  if not Enabled then
    exit;

  { Do the checks. First, machine must be running, and the debug script must be compiled and executed }
  if not AMachine.Running then
  begin
    FWatchStatus := wsProcessNotAvailable;
    exit;
  end;

  { Now compile the debug script }
  try
    AMachine.CompileDebugScript(FDebugScript);
  except
    FWatchStatus := wsCompileError;
    exit;
  end;

  { Now execute the script }
  try
    AMachine.ExecuteDebugScript(FDebugScript, self);
  except
    on ex: Exception do
    begin
      { em caso de falha de execução apenas sinaliza no watch que é inválido }
      FWatchStatus := wsRuntimeError;
    end;
  end;
end;

procedure TatScripterWatch.Reset;
begin
  FDebugScript.Clear;
  FLastResult := NullValue;
  FWatchStatus := wsNotEvaluated;
end;

procedure TatScripterWatch.ScriptDestroyed(Sender: TObject);
begin
  { remove a referência ao script que está sendo destruído }
  FDebugScript := nil;
end;

function TatScripterWatch.Scripter: TatCustomScripter;
begin
  if Watches <> nil then
    Result := Watches.Scripter
  else
    Result := nil;
end;

procedure TatScripterWatch.SetExpression(const Value: string);
begin
  if FExpression <> Value then
  begin
    Reset;
    FExpression := Value;
    FDebugScript.SourceCode.Text := FDebugScript.EncodeSingleAssign('_TatDebugWatch_expression_',
      FExpression);
  end;
end;

function TatScripterWatch.Watches: TatScripterWatches;
begin
  if Collection is TatScripterWatches then
    Result := TatScripterWatches(Collection)
  else
    Result := nil;
end;

{ TGenericEventDispatcher }
{$IFDEF DELPHI2010_LVL}

procedure TGenericEventDispatcher.RaiseEvent;
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TGenericProc(BeforeCall);

    if Assigned(Scripter) and (RoutineName > '') then
      // Scripter.ExecuteSubroutine(RoutineName, GetMethodArgs);
      Scripter.ExecuteSubroutine(RoutineName);

    if AssignedMethod(AfterCall) then
      TGenericProc(AfterCall);
  end;
end;
{$ENDIF}
{ TGenericRecordWrapper }

{$IFDEF DELPHI2010_LVL}

constructor TGenericRecordWrapper.Create(const AValue: TValue);
begin
  FContext := TRttiContext.Create;
  FRecordType := FContext.GetType(AValue.TypeInfo);
  FRecordValue := AValue;
end;

function TGenericRecordWrapper.GetFieldValue(AFieldName: string): TValue;
var
  field: TRttiField;
begin
  field := FRecordType.GetField(AFieldName);
  Result := field.GetValue(FRecordValue.GetReferenceToRawData);
end;

function TGenericRecordWrapper.RecordName: string;
begin
  Result := TypeInfoName(FRecordType.Handle);
end;

function TGenericRecordWrapper.Rec: Pointer;
begin
  Result := FRecordValue.GetReferenceToRawData;
end;

procedure TGenericRecordWrapper.SetFieldValue(AFieldName: string; AValue: TValue);
var
  field: TRttiField;
begin
  field := FRecordType.GetField(AFieldName);
  field.SetValue(FRecordValue.GetReferenceToRawData, AValue);
end;
{$ENDIF}

{ TScriptBaseObject }

procedure TScriptBaseObject.BeforeDestruction;
begin
  FDestroying := True;
  inherited;
end;

constructor TScriptBaseObject.CreateFromScript(AMachine: TatVirtualMachine);
begin
  NewObjectInstance(AMachine);
end;

destructor TScriptBaseObject.Destroy;
begin
  if FRunScript <> nil then
  begin
    FRunScript.Free;
    FRunScript := nil;
  end;
  inherited;
end;

function TScriptBaseObject.GetRunScript: TatScript;
begin
  Result := FRunScript;
end;

procedure TScriptBaseObject.NewObjectInstance(AMachine: TatVirtualMachine);
var
  ABaseScript: TatScript;
  MS: TMemoryStream;
begin
  ABaseScript := nil;

  { Retrieve initial information from the AMachine }
  if AMachine.Script.Scripter = nil then
    AMachine.RuntimeError
      ('Cannot creat script-based object: Scripter property of machine is not specified.');
  if AMachine.CurrentClass <> nil then
    ABaseScript := AMachine.CurrentClass.FBaseScript
  else
    AMachine.RuntimeError('Cannot create script-based object: CurrentClass not specified.');
  if ABaseScript = nil then
    AMachine.RuntimeError('Cannot create script-based object: BaseScript not assigned.');

  { Add a new script in the scripter component }
  FRunScript := AMachine.Script.Scripter.Scripts.Add;

  { We must copy source code from base script to FRunScript, because we need debug information
    for breakpoints, etc. }
  FRunScript.SourceCode.Text := ABaseScript.SourceCode.Text;

  { Uses the newly created object to be default instance so that methods and properties and objects
    are accessible just like in Delphi: "MyMethod(something)" or "MyVariable := 2".
    OBS.: This script preparation must be done before the savecode/loadcode below, because
    when LoadCodeFromStream is caled, it automatically solves absolute addressing, and all default instances
    of new script must be the same as the base script }
  FRunScript.UsesObject(self, '', ABaseScript.ScriptInfo.ScriptClassName);

  { Declared as tkVariant. See RegisterScriptClass method for more info. }
  FRunScript.DefineProp('Self', tkVariant, FRunScript.GetSelfBaseObjectProc, nil, nil);

  { Copy compiled script code from base script to newly created script }
  MS := TMemoryStream.Create;
  try
    { Load the saved compiled code of script into the new script }
    ABaseScript.FCodeStream.Position := 0;
    FRunScript.InternalLoadCodeFromStream(ABaseScript.FCodeStream, false);
    FRunScript.ScriptInfo.Behavior := sbClass;

    { Adds the newly created FRunScript to the script list in basescript, and also set basescript as
      "owner" of runscript. This is to keep references between the base and generated script, for breaks purpose,
      and also of course to keep pointers correct }
    FRunScript.SetOriginalScript(ABaseScript);
    FRunScript.FOriginalObject := self;
  finally
    MS.Free;
  end;
  FRunScript.VirtualMachine.Execute();
end;

function TScriptBaseObject.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := 0 else Result := E_NOINTERFACE;
end;

function TScriptBaseObject._AddRef: Integer;
begin
  Result := -1;
end;

function TScriptBaseObject._Release: Integer;
begin
  Result := -1;
end;

{ TScripterCodeInsight }

{ --- code completion utilities --- }

function TScripterCodeInsight.IgnoreCount: integer;
begin
  Result := High(FIgnorePairs) + 1;
end;

function TScripterCodeInsight.IgnoringIndex: integer;
var
  i: integer;
begin
  Result := -1;
  for i := 0 to IgnoreCount - 1 do
    if FIgnoreLevel[i] > 0 then
    begin
      Result := i;
      Break;
    end;
end;

function TScripterCodeInsight.PreviousChar(s: string; var pos: integer): char;
var
  c: char;
  i: integer;
begin
  for i := 0 to IgnoreCount - 1 do
    FIgnoreLevel[i] := 0;
  dec(pos);
  while pos > 0 do
  begin
    c := s[pos];

    { If it's ignoring (inside brackets, parentesis, etc.) then
      we will ignore the char. But we also need to
      check if the char is not finishing the ignore level (for example,
      if we're inside a parenthesis, we will ignore the char, but we need
      to check if the char is not an open parenthesis }
    if (IgnoringIndex >= 0) then
    begin
      { ignoring the char, but let's check if it's not closing the ignore level }
      if (c = FIgnorePairs[IgnoringIndex].Open) then
        dec(FIgnoreLevel[IgnoringIndex]);

      { also let's check if it's not increasing the ignore level.
        Note that if we are already ignoring (this case), then we will only add levels
        for the current pair (brackets inside brackets) all other ignoring pairs will be ignored
        (brackets inside parenthesis will be totally ignored) }
      if (c = FIgnorePairs[IgnoringIndex].Close) then
        Inc(FIgnoreLevel[IgnoringIndex]);
    end
    else
    begin
      { Check if the char is a close char for any ignore pair }
      for i := 0 to IgnoreCount - 1 do
        if (c = FIgnorePairs[i].Close) then
        begin
          Inc(FIgnoreLevel[i]);
          Break;
        end;

      { Now if we are not ignoring at all, then this is the char we want }
      if (IgnoringIndex < 0) then
      begin
        Result := c;
        exit;
      end;
    end;
    dec(pos);
  end;
  Result := Chr(0);
end;

function TScripterCodeInsight.NextChar(s: string; var pos: integer): char;
var
  c: char;
  i: integer;
  Len: integer;
begin
  for i := 0 to IgnoreCount - 1 do
    FIgnoreLevel[i] := 0;

  { See comments about algorith in PreviousChar. Idea is the same }
  Inc(pos);
  Len := Length(s);
  while pos <= Len do
  begin
    c := s[pos];
    if (IgnoringIndex >= 0) then
    begin
      if (c = FIgnorePairs[IgnoringIndex].Close) then
        dec(FIgnoreLevel[IgnoringIndex]);

      if (c = FIgnorePairs[IgnoringIndex].Open) then
        Inc(FIgnoreLevel[IgnoringIndex]);
    end
    else
    begin
      for i := 0 to IgnoreCount - 1 do
        if (c = FIgnorePairs[i].Open) then
        begin
          Inc(FIgnoreLevel[i]);
          Break;
        end;
      if (IgnoringIndex < 0) then
      begin
        Result := c;
        exit;
      end;
    end;
    Inc(pos);
  end;
  Result := Chr(0);
end;

function TScripterCodeInsight.ExtractExpression(s: string; pos: integer): string;
var
  cont: boolean;
  c: char;
begin
  SetIgnorePairs([DoPair('[', ']'), DoPair('(', ')'), DoPair('{', '}')]);
  Result := '';
  if (pos <= Length(s)) and (pos > 0) then
  begin
    { search from pos until the beginning of expression }
    cont := True;
    while (cont) do
    begin
      c := PreviousChar(s, pos);
      if not FScript.Refactor.IsQualifiedIdentifierChar(c) then
        cont := false;
    end;

    { search from pos until end of expression }
    cont := True;
    while (cont) do
    begin
      c := NextChar(s, pos);
      if FScript.Refactor.IsQualifiedIdentifierChar(c) then
        Result := Result + c
      else
        cont := false;
    end;
  end;
end;

procedure TScripterCodeInsight.SetIgnorePairs(const APairs: array of TIgnorePair);
var
  c: integer;
begin
  SetLength(FIgnoreLevel, 0);
  SetLength(FIgnoreLevel, High(APairs) + 1);
  SetLength(FIgnorePairs, 0);
  SetLength(FIgnorePairs, High(APairs) + 1);
  for c := Low(APairs) to High(APairs) do
    FIgnorePairs[c] := APairs[c];
end;

function TScripterCodeInsight.SplitList(s: string; const sep: string): TStringList;
var
  c, i: integer;
begin
  Result := TStringList.Create; // deve ser destruída externamente
  c := 1;
  i := 1;
  while c <= Length(s) do
  begin
    if CompareText(Copy(s, c, Length(sep)), sep) = 0 then
    begin
      Result.Add(Trim(Copy(s, i, c - i)));
      Inc(c, Length(sep));
      i := c;
    end
    else
      Inc(c);
  end;
  if (c > i) then
    Result.Add(Trim(Copy(s, i, c - i)));
end;

procedure TScripterCodeInsight.AddItemToList(AList: TStrings; AClassName, AName: string;
  AValue: TObject);
var
  i: integer;
begin
  if Assigned(OnGlobalAddCodeCompletionItem) then
    OnGlobalAddCodeCompletionItem(AClassName, AName);

  { Avoid duplicated items }
  for i := 0 to AList.Count - 1 do
    if (AnsiCompareText(AList[i], AName) = 0) and (AList.Objects[i] = AValue) then
      exit;

  AList.AddObject(AName, AValue);
end;

function TScripterCodeInsight.FindAnyResultClass(AClass: TatClass; AName: string;
  Scope: TatRoutineInfo): TatClass;
var
  c: integer;
  AVar: TatVariableInfo;
  aroutine: TatRoutineInfo;
begin
  if AClass <> nil then
    Result := FindResultClass(AClass, AName)
  else
  { if class is nil, then check local things in scripter, in other words, it's not a member of any object.
    Global variables and regular procedures and functions declared in script itself, and also the default
    instances. }
  begin
    Result := nil;

    { check variables local to the procedure }
    if Scope <> nil then
    begin
      AVar := Scope.Variables.FindByName(AName);
      if AVar <> nil then
      begin
        if (AVar.DeclaredClass <> nil) and (AVar.DeclaredClass.ClassRef <> nil) then
          FScript.Scripter.Classes.TestCheckLoaded(AVar.DeclaredClass.ClassRef, Result,
            AVar.DeclaredClassName);
        Exit;
      end;
    end;

    { First check in default instances }
    for c := FScript.DefInstances.Count - 1 downto 0 do
    begin
      Result := FindResultClass(FScript.DefInstances[c].atClass, AName);
      if Result <> nil then
        exit;
    end;

    for c := FScript.Scripter.DefaultInstances.Count - 1 downto 0 do
    begin
      Result := FindResultClass(FScript.Scripter.DefaultInstances[c].atClass, AName);
      if Result <> nil then
        exit;
    end;

    { Check global variables }
    AVar := FScript.ScriptInfo.Globals.FindByName(AName);
    if Assigned(AVar) then
    begin
      if (AVar.DeclaredClass <> nil) and (AVar.DeclaredClass.ClassRef <> nil) then
        FScript.Scripter.Classes.TestCheckLoaded(AVar.DeclaredClass.ClassRef, Result,
          AVar.DeclaredClassName);
      exit;
    end;

    { Check local functions (don't need to check for procedures, because they don't return an object }
    aroutine := FScript.ScriptInfo.RoutineByName(AName);
    if Assigned(aroutine) then
    begin
      if (aroutine.IsFunction) and (aroutine.ResultClass <> nil) and
        (aroutine.ResultClass.ClassRef <> nil) then
      begin
        FScript.Scripter.Classes.TestCheckLoaded(aroutine.ResultClass.ClassRef, Result,
          aroutine.ResultClassName);
      end;
      exit;
    end;
  end;
end;

function TScripterCodeInsight.FindResultClass(AClass: TatClass; AName: string): TatClass;
var
  prop: TatProperty;
  meth: TatMethod;
begin
  { try go into the class based on the name passed }
  Result := nil;
  if (AClass = nil) then
    exit;

  { não está no final então tenta determinar a classe do objeto corrente }
  prop := AClass.PropertyByName(AName);
  if Assigned(prop) then
  begin
    { é uma propriedade }
    if prop.PropertyClass <> nil then
      FScript.Scripter.Classes.TestCheckLoaded(prop.PropertyClass, Result, prop.FPropertyClassName);
    exit;
  end;

  meth := AClass.MethodByName(AName);
  if Assigned(meth) then
  begin
    { it's a method }
    if meth.ResultClass <> nil then
      FScript.Scripter.Classes.TestCheckLoaded(meth.ResultClass, Result, meth.FResultClassName);
    exit;
  end;
end;

function TScripterCodeInsight.FindScopeRoutine(
  AInputPos: integer): TatRoutineInfo;
var
  Routine: TatRoutineInfo;
  I: integer;
  Row, Col: integer;
  RoutineRow, RoutineCol: integer;
  Dist: integer;
begin
  Result := nil;
  if not Assigned(FScript) then Exit;

  FScript.GetRowColFromSource(AInputPos, Row, Col);
  Dist := MaxInt;
  for I := 0 to FScript.ScriptInfo.Routines.Count - 1 do
  begin
    Routine := FScript.ScriptInfo.Routines[I];
    if Routine.FDeclarationInstruction <> nil then
    begin
      FScript.GetRowColFromInst(Routine.FDeclarationInstruction, RoutineRow, RoutineCol);

      // small workaround to see the routine which starts at the closest position to the current cursor
      // later we could improve this by adding a "final instruction" in routine info so we know exaclty where
      // the routine ends
      if (Row > RoutineRow) and (Row - RoutineRow < Dist) then
      begin
        Result := Routine;
        Dist := Row - RoutineRow;
      end;
    end;
  end;
end;

function TScripterCodeInsight.CreateCodeCompletionList(AInputText: string; AInputPos: integer;
  var DefaultIndex: integer): TStringList;
begin
  Result := GetCodeCompletion(AInputText, AInputPos, DefaultIndex);
  ConvertListToOldStyle(Result);
end;

function TScripterCodeInsight.GetParameterHint(AToken: string; AInputPos: integer): string;
var
  SL: TStringList;
  P1, P2: integer;
begin
  Result := '';
  SL := GetCompletionListFromToken(AToken, True, AInputPos, P1 { dummy } );
  try
    if SL.Count = 1 then
    begin
      P1 := pos('(', SL[0]);
      if P1 > 0 then
      begin
        P2 := pos(')', SL[0]);
        Result := Copy(SL[0], P1 + 1, P2 - P1 - 1);
      end
      else
      begin
        P1 := pos('[', SL[0]);
        if P1 > 0 then
        begin
          P2 := pos(']', SL[0]);
          Result := Copy(SL[0], P1 + 1, P2 - P1 - 1);
        end;
      end;

      if Result = '' then
        Result := '<no parameters expected>';
    end;
  finally
    SL.Free;
  end;
end;

function TScripterCodeInsight.GetParameterHintFromObject(obj: TObject): string;
begin
  Result := '';
  if obj is TatProperty then
    Result := FScript.Refactor.BuildPropertyHint(TatProperty(obj));
  if obj is TatMethod then
    Result := FScript.Refactor.BuildMethodHint(TatMethod(obj));
  if obj is TatVariableInfo then
    Result := FScript.Refactor.BuildVariableHint(TatVariableInfo(obj));
  if obj is TatRoutineInfo then
    Result := FScript.Refactor.BuildRoutineHint(TatRoutineInfo(obj));
end;

type
  THintParsingInfo = record
    p: integer;
    ParIdx: integer;
    ch: char;
  end;

function TScripterCodeInsight.GetParameterHintInfo(AInputText: string; AInputPos: integer;
  var AToken: string; var AParIndex: integer): boolean;
var
  StackIdx: integer;
  Stack: array of THintParsingInfo;

  procedure DoPush(Info: THintParsingInfo);
  begin
    { increase array size if needed }
    if StackIdx > High(Stack) then
      SetLength(Stack, StackIdx + 50);

    Stack[StackIdx] := Info;
    Inc(StackIdx);
  end;

  function DoPop(var Info: THintParsingInfo): boolean;
  begin
    dec(StackIdx);
    Result := (StackIdx >= 0) and (High(Stack) >= 0);
    if Result then
      Info := Stack[StackIdx];
  end;

  procedure ClearStack;
  begin
    SetLength(Stack, 0);
    StackIdx := 0;
  end;

var
  ch: char;
  TempIdx: integer;
  Info: THintParsingInfo;
  p: integer;
  CalcToken: string;
begin
  SetIgnorePairs([DoPair('{', '}'), DoPair('''', ''''), DoPair('"', '"')]);

  Result := false;

  { Iterate through source code ignoring comments and literals. }
  p := 0;
  Info.ParIdx := 0;
  repeat
    ch := NextChar(AInputText, p);
    { Every time we find an open parenthesis or bracket, we save (push) that position. }
    if (ch = '(') or (ch = '[') then
    begin
      Info.p := p;
      Info.ch := ch;
      DoPush(Info);

      { start counting the number of parameters for this parenthesis }
      Info.ParIdx := 0;
    end;

    { Every time we find a close parenthesis or bracket, we pop the position back.
      We will discard parenthesis position and char, but we will continue counting the
      number of parameters }
    if (ch = ')') or (ch = ']') then
    begin
      if not DoPop(Info) then
        exit;

      { Only accept matching parenthesis/brackets. If there is *any* mismatch in whole source code,
        then leave }
      if (ch = ')') and (Info.ch <> '(') then
        exit;
      if (ch = ')') and (Info.ch <> '(') then
        exit;
    end;

    { Increate the parameter count if we find a comma }
    if (ch = ',') then
      Inc(Info.ParIdx);

    { if we find a command separator, forget about all the stack and start counting again }
    if FScript.Refactor.IsStatementEndChar(ch) then
      ClearStack;
  until (p >= AInputPos - 1) or (ch = #0);

  { Now we will check the last open parenthesis/bracket with a valid expression.
    We must always save the ParIdx because it relates to the previous value in stack }
  TempIdx := Info.ParIdx;
  while DoPop(Info) do
  begin
    CalcToken := Trim(ExtractExpression(AInputText, Info.p));
    if CalcToken > '' then
    begin
      Result := True;
      AToken := CalcToken;
      AParIndex := TempIdx;
      exit;
    end;
    TempIdx := Info.ParIdx;
  end;
end;

procedure TScripterCodeInsight.FillAllMatchingItems(AClass: TatClass; AName: string;
  AList: TStrings; Scope: TatRoutineInfo);
var
  c: integer;
begin
  if AClass <> nil then
    FillMatchingItems(AClass, AName, AList)
  else
  begin
    for c := FScript.DefInstances.Count - 1 downto 0 do
      FillMatchingItems(FScript.DefInstances[c].atClass, AName, AList);

    for c := FScript.Scripter.DefaultInstances.Count - 1 downto 0 do
      FillMatchingItems(FScript.Scripter.DefaultInstances[c].atClass, AName, AList);

    With FScript.ScriptInfo do
    begin
      { Check local routines }
      for c := 0 to Routines.Count - 1 do
        if (AnsiCompareText(Copy(Routines[c].Name, 1, Length(AName)), AName) = 0) and
          (Routines[c].Name <> '___MAIN___') then
          AddItemToList(AList, '', Routines[c].Name, Routines[c]);

      { Check global variables }
      for c := 0 to Globals.Count - 1 do
        if (AnsiCompareText(Copy(Globals[c].VarName, 1, Length(AName)), AName) = 0) then
          AddItemToList(AList, '', Globals[c].VarName, Globals[c]);

    end;

    { Check local variables }
    if Scope <> nil then
      for c := 0 to Scope.Variables.Count - 1 do
        if (AnsiCompareText(Copy(Scope.Variables[c].VarName, 1, Length(AName)), AName) = 0) then
          AddItemToList(AList, '', Scope.Variables[c].VarName, Scope.Variables[c]);
  end;
end;

procedure TScripterCodeInsight.FillMatchingItems(AClass: TatClass; AName: string; AList: TStrings);
var
  c: integer;
begin
  if AClass = nil then
    exit;

  { try go into the class based on the name passed }
  with AClass do
  begin
    { Since it's final node, search for a partial name }
    for c := 0 to AClass.Properties.Count - 1 do
      if Copy(UpperCase(AClass.Properties[c].Name), 1, Length(AName)) = UpperCase(AName) then
        AddItemToList(AList, AClass.FName, AClass.Properties[c].Name, AClass.Properties[c]);

    for c := 0 to AClass.Methods.Count - 1 do
      if Copy(UpperCase(AClass.Methods[c].Name), 1, Length(AName)) = UpperCase(AName) then
        AddItemToList(AList, AClass.FName, AClass.Methods[c].Name, AClass.Methods[c]);
  end;
end;

class procedure TScripterCodeInsight.ConvertListToOldStyle(AList: TStrings);
var
  c: integer;
  obj: TObject;
  Value: integer;
begin
  for c := 0 to AList.Count - 1 do
  begin
    obj := AList.Objects[c];
    Value := 0;

    if obj is TatRoutineInfo then
    begin
      if TatRoutineInfo(obj).IsFunction then
        Value := 2 + 16
      else
        Value := 1 + 16;
    end;

    if obj is TatVariableInfo then
      Value := 0 + 16;

    if obj is TatProperty then
    begin
      if TatProperty(obj).DataType <> tkMethod then
        Value := 0
      else
        Value := 3; // event
      if TatProperty(obj).atClass.IsDefaultInstance then
        Value := Value + 16;
    end;

    if obj is TatMethod then
    begin
      if TatMethod(obj).ResultDataType = tkNone then
        Value := 1
      else
        Value := 2;
      if TatMethod(obj).atClass.IsDefaultInstance then
        Value := Value + 16;
    end;

    AList.Objects[c] := TObject(Value);
  end;
end;

constructor TScripterCodeInsight.Create(AScript: TatScript);
begin
  FScript := AScript;
  SetLength(FIgnoreLevel, 0);
  SetLength(FIgnorePairs, 0);
end;

function TScripterCodeInsight.GetCodeCompletion(AInputText: string; AInputPos: integer;
  var DefaultIndex: integer): TStringList;
var
  expr: string;
begin
  { extract expression from memo }
  expr := ExtractExpression(AInputText, AInputPos);
  Result := GetCompletionListFromToken(expr, false, AInputPos, DefaultIndex);
end;

function TScripterCodeInsight.GetCompletionListFromToken(AToken: string; AExactMatch: boolean;
  AInputPos: integer; var DefaultIndex: integer): TStringList;

  procedure RemoveNotExactMatches(AList: TStrings; AName: string);
  var
    i: integer;
  begin
    AName := UpperCase(AName);
    i := 0;
    while i < AList.Count do
    begin
      if UpperCase(AList[i]) <> AName then
        AList.Delete(i)
      else
        Inc(i);
    end;
  end;

  procedure AddParameterHints(AList: TStrings);
  var
    AHint: string;
    c: integer;
    obj: TObject;
  begin
    for c := 0 to AList.Count - 1 do
    begin
      obj := AList.Objects[c];
      AHint := GetParameterHintFromObject(obj);
      if AHint <> '' then
      begin
        if (obj is TatVariableInfo) or (obj is TatProperty) then
          AList[c] := Format('%s[%s]', [AList[c], AHint])
        else
          AList[c] := Format('%s(%s)', [AList[c], AHint]);
      end;
    end;
  end;

  function CalculateDefaultIndex(AList: TStrings; AToken: string; AFilter: string): integer;
  var
    c: integer;
    SL: TStringList;
  begin
    Result := -1;
    if Context <> nil then
    begin
      { Get only the context items associated with the token }
      SL := TStringList.Create;
      AToken := UpperCase(AToken);
      AFilter := UpperCase(AFilter);
      try
        for c := Context.LastEntries.Count - 1 downto 0 do
          { First let's only use values of same token }
          if UpperCase(Context.LastEntries[c].Token) = UpperCase(AToken) then
            { Now we will only get items that matches the search filter, unless it's empty }
            if (AFilter = '') or (pos(AFilter, UpperCase(Context.LastEntries[c].Value)) = 1) then
              SL.Add(UpperCase(Context.LastEntries[c].Value));

        { now find the item in list which matches the value }
        for c := 0 to SL.Count - 1 do
        begin
          Result := AList.IndexOf(SL[c]);
          if Result >= 0 then
            Break;
        end;
      finally
        SL.Free;
      end;
      Context.LastUsedToken := AToken;
    end;
  end;

var
  c: integer;
  cls: TatClass;
  slist: TStringList;
  EntryToken: string;
  Scope: TatRoutineInfo;
begin
  DefaultIndex := -1;
  EntryToken := '';

  { Perform silent compilation to get more information about the script }
  if not FScript.SilentCompiled and not FScript.Scripter.Running then
    FScript.SilentCompile;

  Scope := FindScopeRoutine(AInputPos);

  slist := TStringList.Create;
  Result := slist;
  try
    { Split the expression members separated by dot (.) }
    with SplitList(AToken, '.') do
      try
        cls := nil;

        if (Count = 0) or (pos('.*', AToken + '*') > 0) then
          Add('');

        { Iterating through the expression (Format: 'Name1.Name2.' or 'Name1.Name2.Na' }
        for c := 0 to Count - 1 do
        begin
          { do not continue if a class was not found at some point (Except the first node, of course) }
          if (c > 0) and (cls = nil) then
            exit;

          { Check if it's initial node }
          if c = Count - 1 then
          begin
            FillAllMatchingItems(cls, Strings[c], slist, Scope);
            if AExactMatch then
              RemoveNotExactMatches(Result, Strings[c]);
            slist.Sort;
            DefaultIndex := CalculateDefaultIndex(slist, EntryToken, Strings[c]);
            AddParameterHints(Result);
          end
          else
          begin
            { There are sub nodes, then find initial class }
            cls := FindAnyResultClass(cls, Strings[c], Scope);

            { Calculate token for code insight context. There are several ways to do this.
              We could use:
              a) Only the last class name (not compount entry token). In this case, any member chosen
              for a specified class will be always used no matter where that class is used
              (ex., Fld.AsString affects Table1.FieldByName().AsString and vice-versa)
              b) Use first node as class and also remaining nodes as classes. In this case,
              Fld.AsString will not affect Table1.FieldByName().<>, but properties of the same class will
              be affected (for example,
              Table1.FieldByName().AsString will affect Table1.Fields[0].AsString
              c) Use first node as class and remaining nodes as member names.
              In this case the context will be saved individually for each property/member name, except
              for the first class. So Table1.FieldByName().<> will have a context, and Table1.Fields[].<>
              will have another context.

              For now we are using option (c) }
            if cls <> nil then
            begin
              if c = 0 then
                EntryToken := EntryToken + cls.Name
              else
                EntryToken := EntryToken + '.' + Strings[c];
            end;
          end;
        end;
      finally
        Free;
      end;
  except
    slist.Free;
    raise;
  end;
end;

destructor TScripterCodeInsight.Destroy;
begin
  SetLength(FIgnoreLevel, 0);
  inherited;
end;

function TScripterCodeInsight.DoPair(Open, Close: char): TIgnorePair;
begin
  Result.Open := Open;
  Result.Close := Close;
end;

{ TCodeInsightContext }

constructor TCodeInsightContext.Create;
begin
  FLastEntries := TCodeCompletionEntries.Create;
end;

destructor TCodeInsightContext.Destroy;
begin
  FLastEntries.Free;
  inherited;
end;

{ TCodeCompletionEntries }

function TCodeCompletionEntries.Add(AToken, AValue: string): TCodeCOmpletionEntry;
begin
  Result := TCodeCOmpletionEntry(inherited Add);
  Result.Token := AToken;
  Result.Value := AValue;
end;

constructor TCodeCompletionEntries.Create;
begin
  inherited Create(TCodeCOmpletionEntry);
end;

function TCodeCompletionEntries.GetItem(Index: integer): TCodeCOmpletionEntry;
begin
  Result := TCodeCOmpletionEntry(inherited Items[Index]);
end;

{ TScriptFormLoader }

{ TScriptFormLoader }

constructor TScriptFormLoader.Create(AForm: IScriptBasedForm);
begin
  FForm := AForm;
  FForm.SetOnReadState(ReadStateEvent);
end;

procedure TScriptFormLoader.LoadFormResource(AFormRes: string;
  ALoadEvents: boolean);
var
  SS: TStringStream;
  MS: TMemoryStream;
  Reader: TReader;
begin
  SS := TStringStream.Create(AFormRes);
  try
    SS.Position := 0;
    MS := TMemoryStream.Create;
    ObjectTextToBinary(SS, MS);
    MS.Position := 0;

    Reader := TReader.Create(MS, 4096);
    try
      FLastSearchedMethod := '';
      if ALoadEvents then
      begin
        Reader.OnFindMethod := ReaderFindMethod;
        Reader.OnError := ReaderError;
      end;
      Reader.ReadRootComponent(FForm.GetForm);
      RestoreSavedProps(true);
    finally
      Reader.Free;
    end;

    MS.Free;
  finally
    SS.Free;
  end;
end;

procedure TScriptFormLoader.ReaderError(Reader: TReader; const Message: string;
  var Handled: boolean);

  function _IsValidChar(c: char): boolean;
  const
    Alpha = ['A' .. 'Z', 'a' .. 'z', '_'];
    AlphaNumeric = Alpha + ['0' .. '9'];
  begin
    {$IFDEF DELPHI2009_LVL}
      {$IFDEF DELPHIXE4_LVL}
      Result := c.IsLetterOrDigit or (c = '_');
      {$ELSE}
      Result := TCharacter.IsLetterOrDigit(c) or (c = '_');
      {$ENDIF}
    {$ELSE}
    Result := c in AlphaNumeric;
    {$ENDIF}
  end;

var
  Comp: string;
  Event: string;
  P1: integer;
  p: integer;
begin
  { workaround to retrieve events in forms. Find Comp.Event text in message }
  P1 := pos('.', Message);
  Comp := '';
  p := P1 - 1;
  while (p > 0) and (_IsValidChar(Message[p])) do
  begin
    Comp := Copy(Message, p, P1 - p);
    dec(p);
  end;

  Event := '';
  p := P1 + 1;
  while (p <= Length(Message)) and (IsValidIdent(Copy(Message, P1 + 1, p - P1))) do
  begin
    Event := Copy(Message, P1 + 1, p - P1);
    Inc(p);
  end;

  { if last searched method is not nil, it means that the reader executed FindMethod to find
    the event handler name, and then raised this error. So we can try to ignore the error and add
    the event to method names }
  if FLastSearchedMethod <> '' then
  begin
    FForm.GetSaveEvents.Add(Format('%s.%s=%s', [Comp, Event, FLastSearchedMethod]));
    FLastSearchedMethod := '';
    Handled := True;
  end;
end;

procedure TScriptFormLoader.ReaderFindMethod(Reader: TReader;
  const MethodName: string; var Address: pointer; var Error: boolean);
begin
  FLastSearchedMethod := MethodName;
end;

procedure TScriptFormLoader.ReadStateEvent(Sender: TObject);
begin
  RestoreSavedEvents;
  RestoreSavedProps(false);
end;

procedure TScriptFormLoader.RestoreSavedEvents;

  procedure SetEventFromString(CompName, PropName, RoutineName: string);
  var
    Comp: TComponent;
    RunScript: TatScript;
  begin
    if UpperCase(CompName) = 'SELF' then
      Comp := FForm.GetForm
    else
      Comp := FForm.GetForm.FindComponent(CompName);

    RunScript := FForm.GetRunScript;
    if Assigned(Comp) and Assigned(RunScript) and Assigned(RunScript.Scripter) then
    begin
      RunScript.Scripter.EventBroker.SetEvent(Comp, PropName, RoutineName, RunScript.Scripter,
        epReplaceCall, RunScript);
    end;
  end;

var
  c: integer;
  CompName: string;
  EventName: string;
  StrName: string;
  p: integer;
  TheSaveEvents: TStrings;
begin
  TheSaveEvents := FForm.GetSaveEvents;
  for c := 0 to TheSaveEvents.Count - 1 do
  begin
    { Retrieve component and event name }
    StrName := TheSaveEvents.Names[c];
    p := pos('.', StrName);
    CompName := Copy(StrName, 1, p - 1);
    EventName := Copy(StrName, p + 1, MaxInt);
    SetEventFromString(CompName, EventName, TheSaveEvents.Values[StrName]);
  end;
end;

procedure TScriptFormLoader.RestoreSavedProps(AfterReading: boolean);

  function StrToIntSet(APropType: PTypeInfo; Value: string): integer;
  var
    val, Enum: string;
    p, v: integer;
  begin
    Result := 0;
    if Length(Value) > 2 then
    begin
      val := Value;
      if val[1] = '[' then
        Delete(val, 1, 1);
      if val[Length(val)] = ']' then
        Delete(val, Length(val), 1);
      repeat
        p := pos(',', val);
        if (p = 0) and (val <> '') then
          Enum := val
        else
          Enum := Copy(val, 1, Pred(p));
        Delete(val, 1, p);
        v := GetEnumValue(GetTypeData(APropType).CompType^, Enum);
        if v = 0 then
          v := 1
        else
          v := 1 shl v;
        Result := Result or v;
      until p = 0;
    end;
  end;

  function StrToObject(Value: string): TObject;
  begin
    Result := FForm.GetForm.FindComponent(Value);
  end;

  procedure SetPropFromString(APropInfo: PPropInfo; Value: string);
  var
    APropType: PTypeInfo;
    TheForm: TComponent;
  begin
    TheForm := FForm.GetForm;
    APropType := APropInfo.PropType^;
    case APropType.Kind of
      TypInfo.tkString, TypInfo.tkLString, TypInfo.tkWString:
        SetStrProp(TheForm, APropInfo, Value);
      {$IFDEF DELPHI2009_LVL}
      TypInfo.tkUString:
        {$IFDEF NEXTGEN}
        SetStrProp(TheForm, APropInfo, Value);
        {$ELSE}
        SetUnicodeStrProp(TheForm, APropInfo, Value);
        {$ENDIF}
      {$ENDIF}
      TypInfo.tkInteger:
        SetOrdProp(TheForm, APropInfo, StrToInt(Value));

      TypInfo.tkVariant:
        SetVariantProp(TheForm, APropInfo, Value);

      TypInfo.tkEnumeration:
        SetOrdProp(TheForm, APropInfo, VarToEnumInteger(Value, APropType));

      TypInfo.tkSet:
        SetOrdProp(TheForm, APropInfo, StrToIntSet(APropType, Value));

      TypInfo.tkFloat:
        SetFloatProp(TheForm, APropInfo, StrToFloat(Value));

      TypInfo.tkClass:
        SetOrdProp(TheForm, APropInfo, IntObject(StrToObject(Value)));
    end;
  end;

var
  c: integer;
  PropName: string;
  TheSaveProps: TStrings;
begin
  TheSaveProps := FForm.GetSaveProps;
  for c := 0 to TheSaveProps.Count - 1 do
  begin
    PropName := TheSaveProps.Names[c];
    if AfterReading then
    begin
      if SameText(PropName, 'Position') or SameText(PropName, 'BorderStyle') then
        SetPropFromString(GetPropInfo(FForm.GetForm, PropName), TheSaveProps.Values[PropName]);
    end
    else
    begin
      if not SameText(PropName, 'Position') and not SameText(PropName, 'BorderStyle') then
        SetPropFromString(GetPropInfo(FForm.GetForm, PropName), TheSaveProps.Values[PropName]);
    end;
  end;
end;


{ TDefineClassOptions }

{$IFDEF DELPHI2010_LVL}

constructor TDefineClassOptions.Create;
begin
  inherited;
  FVisibilityFilter := [mvPublic, mvPublished];
  FRecursive := false;
  FRedefine := roNone;
end;

{$ENDIF}

initialization
  { inicializa a tabela de constantes variant do scripter }
  CoreConst[coNull] := NullValue;
  CoreConst[coTrue] := True;
  CoreConst[coFalse] := false;
  {$IFDEF NEWSTACK}
  CoreConst[coUnassigned] := NullValue;
  {$ELSE}
  CoreConst[coUnassigned] := Unassigned;
  {$ENDIF}
  CoreConst[coNil] := 0;

  { global event adapter collection }
  EventAdapters := TatEventAdapters.Create(TatEventAdapter);

  { registra a System Library como biblioteca default do Scripter }
  atLibraryList := TatLibraryList.Create(TatLibraryListItem);
  RegisterScripterLibrary(TatSystemLibrary, false);
  RegisterScripterLibrary(TatDLL, True);

  { Create global event OnScripterCreate }
  OnGlobalScripterCreate := nil;
  OnGlobalScripterLoaded := nil;

  UndefinedClass := TatClass.Create(nil);

  {$IFDEF NEWSTACK}
  NullValue := TValue.Empty;
  {$ELSE}
  NullValue := Variants.Null;
  {$ENDIF}

finalization
  UndefinedClass.Free;
  EventAdapters.Free;
  atLibraryList.Free;

end.
