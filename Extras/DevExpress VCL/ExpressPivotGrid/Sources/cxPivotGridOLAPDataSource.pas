{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{                   ExpressPivotGrid                                 }
{                                                                    }
{       Copyright (c) 2005-2014 Developer Express Inc.               }
{       ALL RIGHTS RESERVED                                          }
{                                                                    }
{   The entire contents of this file is protected by U.S. and        }
{   International Copyright Laws. Unauthorized reproduction,         }
{   reverse-engineering, and distribution of all or any portion of   }
{   the code contained in this file is strictly prohibited and may   }
{   result in severe civil and criminal penalties and will be        }
{   prosecuted to the maximum extent possible under the law.         }
{                                                                    }
{   RESTRICTIONS                                                     }
{                                                                    }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES            }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE     }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS    }
{   LICENSED TO DISTRIBUTE THE EXPRESSPIVOTGRID AND ALL ACCOMPANYING }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.              }
{                                                                    }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED       }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE         }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE        }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT   }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                       }
{                                                                    }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON        }
{   ADDITIONAL RESTRICTIONS.                                         }
{                                                                    }
{********************************************************************}

unit cxPivotGridOLAPDataSource;

{$I cxVer.inc}

interface

uses
  Types, Classes, SysUtils, cxClasses, Forms, cxCustomPivotGrid, Math, ADODB,
  ActiveX, cxPivotGridOLAPQueryBuilder, Windows, Contnrs, cxCustomData, cxPivotGridStrs;

type
  { TcxPivotGridOLAPDrillDownDataSource }

  TcxPivotGridOLAPDrillDownDataSource = class(TcxPivotGridCrossCellDataSource)
  private
    function IsUniqueNamesEqual(APivotFieldName, ADrillDownName: string;
      var ACoincidenceCount: Integer): Boolean;
  protected
    FDataSet: TADODataSet;
    FDataSetFields: TList;
    FPivotGridFields: TList;
    function GetFieldCount: Integer; override;
    function GetPivotGridField(AIndex: Integer): TcxPivotGridField; override;
    function GetRecordCount: Integer; override;
    function GetValue(ARecordHandle: TcxDataRecordHandle;
      AItemHandle: TcxDataItemHandle): Variant; override;
  public
    destructor Destroy; override;
  end;

  TcxPivotGridAddOLAPStructureItemProc = function(AParent: Pointer; const ACaption: string;
    const ANameIndex, AImageIndex: Integer): Pointer of object;

  { TcxPivotGridOLAPDataSource }

  TcxPivotGridOLAPDataSource = class(TcxPivotGridCustomOLAPDataSource)
  private
    FCachedFileName: string;
    FCacheLocalCubes: Boolean;
    FConnection: TADOConnection;
    FConnectionString: WideString;
    FCube: string;
    FCubes: TStringList;
    FIsCubeNameAssigned: Boolean;
    FTerminated: Boolean;
    FVersion: Integer;
    FQueryBuilder: TcxOLAPDataQueryBuilder;
    procedure CreateQueryBuilder;
    procedure ExpandedItemWithParentsToList(AnItems: TList; AList: TList; AWithParents: Boolean = True); overload;
    procedure ExpandedItemWithParentsToList(AnItem: TcxPivotGridGroupItem; AList: TList; AWithParents: Boolean = True); overload;
    function ExtractMemberName(AFullName: string): string;
    function GetActive: Boolean;
    function GetDrillDownCommandText(ACell: TcxPivotGridCrossCell;
      AFieldList: TcxObjectList; ASummaryIndex: Integer): string;
    function GetConnectionString: WideString;
    function GetDataFieldCount(ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType): Integer;
    function IsDataValid: Boolean;
    function IsOLAPVersion8: Boolean;
    procedure SetActive(AValue: Boolean);
    procedure SetConnectionString(const AValue: WideString);
    procedure SetCube(const AValue: string);
  protected
    FADODataSet: TADODataSet;
    FIsLocalCube: Boolean;

    procedure AddDimensions;
    procedure AddLevels(ALevels: TStringList);
    procedure AddMeasures;
    procedure AddKPIs;
    procedure AddSETs;
    function CheckCubeName: Boolean;
    function CreateNode(AParent: TcxPivotGridOLAPStructureNode;
      const ACaption: string; ANodeType: TcxOLAPStructureNodeType): TcxPivotGridOLAPStructureNode;
    procedure CreateStructure; override;
    procedure CreateTemporaryCube;
    procedure DeleteCachedFile;
    function GetLastNameFromPath(const APath: string): string;
    function GetPathItem(var APath: string): string;

    function CreateDrillDownDataSet(ACells: TList; AFieldList: TcxObjectList; ASummaryIndex: Integer): TADODataSet;
    function CreateDrillDownDataSource(ACells: TList;
      AFieldList: TcxObjectList; ASummaryIndex: Integer): TcxPivotGridCrossCellDataSource; override;
    procedure CreateMembers(AField: TcxPivotGridField; AParent: TcxPivotGridGroupItem;
      AHasChildren: Boolean; ADataFields: TcxPivotGridFields); override;
    function ExecuteQuery(AQuery: WideString): Boolean;
    procedure ExtractProviderVersion(const AVersion: string);

    function OpenSchema(const ASchemaType: string): Boolean;
    function GetIsActive: Boolean; override;
    function GetIsTerminated: Boolean; override;
    function GetMeasureName(AFullName: string): string;
    function GetNonExpandedFields(ADataBuilder: TcxPivotGridDataBuilder;
      AnExpandingItem, AnItem: TcxPivotGridGroupItem; ACrossGroupItems: TList; AddHierarchyField: Boolean): TcxPivotGridFields;
    function GetFieldIndex(AField: TcxPivotGridField; AStartIndex: Integer): Integer; overload;
    function GetFieldIndex(AField: TcxPivotGridField; AStartIndex: Integer; out ALevelUniqueName: string): Integer; overload;
    function GetRowID(var AExpandingFieldIndex: Integer; ARowField: TcxPivotGridField): string;
    procedure Initialize; override;
    procedure InitializeCrossCells(ARowsGroup, AColumnsGroup: TcxPivotGridGroupItem;
      ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType); override;
    procedure InitializeCrossCellsKPI(ARowsGroup, AColumnsGroup: TcxPivotGridGroupItem; ARowField: TcxPivotGridField;
      ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex, AExpandingFieldIndex: Integer);
    procedure InitializeKPITotal(AColumnsGroup, ARowsGroup: TcxPivotGridGroupItem;
      ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex: Integer);
    procedure InitializeKPITotals(AColumnsGroup, ARowsGroup: TcxPivotGridGroupItem;
      ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex: Integer);
    procedure InitializeExpanding(ADataBuilder: TcxPivotGridDataBuilder; AField: TcxPivotGridField;
      AnExpandingItem, ACrossGroup: TcxPivotGridGroupItem; ADataFields: TcxPivotGridFields); override;
    procedure InitializeLayoutKPI(ARowFields, AColumnFields, ADataFields,
      AFilterFields: TcxPivotGridFields; ARowsGroup, AColumnsGroup: TcxPivotGridGroupItem); override;
    procedure InitializeTotal(ADataFields, AFilterFields: TcxPivotGridFields; AColumns, ARows: TcxPivotGridGroupItem); override;
    procedure CreateLayoutTotals(AColumns, ARows: TcxPivotGridGroupItem; ASummaryFields: TcxPivotGridFields; AnExpandedMembers: TList); override;
    function IsValueVisible(AFilter: TcxPivotGridFieldFilter; const AValue: WideString): Boolean;
    procedure InitializeStructureMembers(AField: TcxPivotGridOLAPField; AList: TcxPivotGridVariantList); override;
    procedure Loaded; override;
    procedure PopulateFilteredUniqueNames(AField: TcxPivotGridOLAPField;
      AFilter: TcxPivotGridFieldFilter; var AUniqueValues: TStringList); override;
    procedure PopulateFilteredValues(AField: TcxPivotGridOLAPField; AFilter: TcxPivotGridFieldFilter;
      AValues: TStrings; AUniqueValues: TStringList); override;
    procedure ProcessColumns(AColumnsGroup: TcxPivotGridGroupItem;
      ARow: TcxPivotGridGroupItem; AFieldIndex: Integer);
    procedure ProcessDataField(AColumn, ARow: TcxPivotGridGroupItem; AFieldIndex, ASummaryFieldIndex: Integer);
    procedure ProcessDataFields(AColumn, ARow: TcxPivotGridGroupItem; ADataFields: TcxPivotGridFields;
      AFieldIndex: Integer; const AFieldDimension: string; AOLAPType: TcxPivotGridOLAPFieldType; out AProcessedFieldCount: Integer);
    procedure ProcessDataFieldsEx(AColumn, ARow: TcxPivotGridGroupItem; ADataFields: TcxPivotGridFields;
      ARecordIndex, AStartColumnIndex: Integer; AOLAPType: TcxPivotGridOLAPFieldType);
    procedure QueryLayout(ARowFields, AColumnFields, ADataFields, AFilterFields: TcxPivotGridFields); override;
    procedure QueryLayoutTotals(AColumnFields, ARowFields, ADataFields, AFilterFields: TcxPivotGridFields; AnExpandedMembers: TList); override;
    procedure QueryKPIExpandCrossCells(ADataBuilder: TcxPivotGridDataBuilder; AMembers: TList; AFields: TcxPivotGridFields; ADataFields: TcxPivotGridFields; ADataFieldIndex: Integer);
    function QueryKPILayout(AColumnFields, ARowFields, AFilterFields: TcxPivotGridFields;
      ADataField: TcxPivotGridOLAPField; AOLAPType: TcxOLAPKPIType): Boolean;
    function QueryKPITotal(AFilterFields: TcxPivotGridFields; AColumnFields, ARowFields: TcxPivotGridFields;
      ADataField: TcxPivotGridOLAPField; AKPIType: TcxOLAPKPIType): Boolean;
    function QueryKPITotals(AColumnFields, AFilterFields: TcxPivotGridFields;
      ADataField: TcxPivotGridOLAPField; AKPIType: TcxOLAPKPIType; AnExpandedMembers: TList): Boolean;
    procedure QueryRootMembers(AField: TcxPivotGridField; AParentMembers: TList;
      AFilters: TcxPivotGridFields; ADataFields: TcxPivotGridFields); override;
    function SeparateDimensionAndMeasure(AValue: string; out ADimension, AMeasure: string): Boolean;
    procedure TerminateConnection;

    property IsCubeNameAssigned: Boolean read FIsCubeNameAssigned write FIsCubeNameAssigned;
    property QueryBuilder: TcxOLAPDataQueryBuilder read FQueryBuilder write FQueryBuilder;
    property Version: Integer read FVersion;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    property Connection: TADOConnection read FConnection;
    property ADODataSet: TADODataSet read FADODataSet;
    property Cubes: TStringList read FCubes;
  published
    property CacheLocalCubes: Boolean read FCacheLocalCubes write FCacheLocalCubes;
    property ConnectionString: WideString read GetConnectionString write SetConnectionString;
    property Cube: string read FCube write SetCube stored FIsCubeNameAssigned;
    property Active: Boolean read GetActive write SetActive;
    property OnInitializeField;
  end;

implementation

uses
  Variants, DB, dxCore, StrUtils, ComObj, dxCustomTree;

const
  SCHEMA_CUBES         = '{C8B522D8-5CF3-11CE-ADE5-00AA0044773D}';
  SCHEMA_DIMENSIONS    = '{C8B522D9-5CF3-11CE-ADE5-00AA0044773D}';
  SCHEMA_LEVELS        = '{C8B522DB-5CF3-11CE-ADE5-00AA0044773D}';
  SCHEMA_MEASURES      = '{C8B522DC-5CF3-11CE-ADE5-00AA0044773D}';
  SCHEMA_KPI           = '{2AE44109-ED3D-4842-B16F-B694D1CB0E3F}';
  SCHEMA_SETS          = '{A07CCD0B-8148-11D0-87BB-00C04FC33942}';
  SCHEMA_HIERARCHIES   = '{C8B522DA-5CF3-11CE-ADE5-00AA0044773D}';
  SCHEMA_MEASUREGROUPS = '{E1625EBF-FA96-42fd-BEA6-DB90ADAFD96B}';
  SCHEMA_MEMBERS       = '{C8B522DE-5CF3-11CE-ADE5-00AA0044773D}';

  OLAPMemberNameColumnName = '[Measures].[MemberName]';
  OLAPMemberUniqueNameColumnName = '[Measures].[MemberUniqueName]';
  OLAPPArentUniqueNameColumnName = '[Measures].[ParentUniqueName]';

function CompareStructureNodes(ANode1, ANode2: TcxPivotGridOLAPStructureNode): Integer;
const
  NodeType2Compare: array[TcxOLAPStructureNodeType] of Integer =
    (0, 1, 2, 3, 4, 5, 7, 6);
begin
  Result := 0;
  if ANode1 = ANode2 then Exit;
  Result := NodeType2Compare[ANode1.NodeType] - NodeType2Compare[ANode2.NodeType];
  if Result = 0 then
  begin
    Result := ANode1.LevelNumber - ANode2.LevelNumber;
    if Result = 0 then
      Result := AnsiCompareText(ANode1.DisplayText, ANode2.DisplayText);
  end;
end;

{ TcxPivotGridOLAPDrillDownDataSource }

destructor TcxPivotGridOLAPDrillDownDataSource.Destroy;
begin
  FreeAndNil(FDataSet);
  FreeAndNil(FDataSetFields);
  FreeAndNil(FPivotGridFields);
  inherited Destroy;
end;

function TcxPivotGridOLAPDrillDownDataSource.GetFieldCount: Integer;
var
  ACoincidenceCount, ACurrentCoincidenceCount, I, J: Integer;
  IsFound: Boolean;
  ADataSetField, APivotGridField: Pointer;
begin

  if FDataSetFields = nil then
  begin
    FDataSetFields := TList.Create;
    FPivotGridFields := TList.Create;
  end
  else
  begin
    FDataSetFields.Clear;
    FPivotGridFields.Clear;
  end;

  Result := 0;
  if HasData and (FDataSet <> nil) and FDataSet.Active then
  begin
    for I := 0 to FDataSet.FieldCount - 1 do
    begin
      IsFound := False;
      ADataSetField := nil;
      APivotGridField := nil;
      ACoincidenceCount := 0;
      J := 0;
      while J < PivotGrid.FieldCount do
      begin
        if IsUniqueNamesEqual(PivotGrid.Fields[J].UniqueName,
          FDataSet.Fields[I].FullName, ACurrentCoincidenceCount) and
          (ACoincidenceCount < ACurrentCoincidenceCount) then
        begin
          IsFound := True;
          ADataSetField := FDataSet.Fields[I];
          APivotGridField := PivotGrid.Fields[J];
        end;
        Inc(J);
      end;
      if IsFound then
      begin
        Inc(Result);
        FDataSetFields.Add(ADataSetField);
        FPivotGridFields.Add(APivotGridField);
      end;
    end;
  end;
end;

function TcxPivotGridOLAPDrillDownDataSource.GetPivotGridField(
  AIndex: Integer): TcxPivotGridField;
begin
  Result := TcxPivotGridField(FPivotGridFields.Items[AIndex]);
end;

function TcxPivotGridOLAPDrillDownDataSource.GetRecordCount: Integer;
begin
  if HasData and (FDataSet <> nil) and FDataSet.Active then
    Result := FDataSet.RecordCount
  else
    Result := 0;
end;

function TcxPivotGridOLAPDrillDownDataSource.GetValue(
  ARecordHandle: TcxDataRecordHandle; AItemHandle: TcxDataItemHandle): Variant;
begin
  if Integer(AItemHandle) < FDataSet.FieldCount then
  begin
    FDataSet.RecNo := Integer(ARecordHandle) + 1;
    Result := TField(FDataSetFields[Integer(AItemHandle)]).AsVariant;
  end;
end;

function TcxPivotGridOLAPDrillDownDataSource.IsUniqueNamesEqual(
  APivotFieldName, ADrillDownName: string;
  var ACoincidenceCount: Integer): Boolean;

  procedure TrimBrackets(var AName: string);
  var
    ALength: Integer;
  begin
    if dxCharInSet(AName[1], ['{', '[', '(']) then
      Delete(AName, 1, 1);
    ALength := Length(AName);
    if dxCharInSet(AName[ALength], ['}', ']', ')']) then
      Delete(AName, ALength, 1);
  end;

var
  APivotPart, ADrillDownPart: string;
  APos: Integer;
begin
  ACoincidenceCount := 0;
  while (APivotFieldName <> '') and (ADrillDownName <> '') do
  begin
    APos := Pos('.', APivotFieldName);
    if APos <> 0 then
    begin
      APivotPart := Copy(APivotFieldName, 0, APos - 1);
      Delete(APivotFieldName, 1, APos);
      TrimBrackets(APivotPart);
      APos := Pos('.', ADrillDownName);
      if APos <> 0 then
      begin
        ADrillDownPart := Copy(ADrillDownName, 0, APos - 1);
        Delete(ADrillDownName, 1, APos);
        if (Pos(APivotPart, ADrillDownPart) <> 0) or
          (Pos('Measures', APivotPart) <> 0) then
          Inc(ACoincidenceCount)
        else
          Dec(ACoincidenceCount);
      end
      else
        Dec(ACoincidenceCount);
    end
    else
    begin
      APivotPart := APivotFieldName;
      APivotFieldName := '';
      TrimBrackets(APivotPart);
      APos := Pos('.', ADrillDownName);
      if (APos = 0) and (Pos(APivotPart, ADrillDownName) <> 0) then
        Inc(ACoincidenceCount)
      else
        Dec(ACoincidenceCount);
    end;
  end;
  Result := ACoincidenceCount > 0;
end;

{ TcxPivotGridOLAPDataSource }

constructor TcxPivotGridOLAPDataSource.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCacheLocalCubes := True; 
  FConnection := TADOConnection.Create(Self);
  FConnection.LoginPrompt := False;
  FConnection.KeepConnection := False;
  FConnection.CommandTimeout := 1000000;
  FADODataSet := TADODataSet.Create(Self);
  FCubes := TStringList.Create;
end;

destructor TcxPivotGridOLAPDataSource.Destroy;
begin
  Active := False;
  FreeAndNil(FQueryBuilder);
  FCubes.Free;
  FADODataSet.Free;
  FConnection.Free;
  inherited Destroy;
end;

procedure TcxPivotGridOLAPDataSource.AddDimensions;
var
  ADName: string;
  ALevels: TStringList;
  AParent, AFolderNode, ANode: TcxPivotGridOLAPStructureNode;
  ACardinality, AStructure, AFolder, ACaption, ADimensionName, AHierarchyName: TField;
begin
  if not OpenSchema(SCHEMA_HIERARCHIES) then Exit;
  AFolder := ADODataSet.FindField('HIERARCHY_DISPLAY_FOLDER');
  ACaption := ADODataSet.FieldByName('HIERARCHY_CAPTION');
  ADimensionName := ADODataSet.FieldByName('DIMENSION_UNIQUE_NAME');
  AHierarchyName := ADODataSet.FieldByName('HIERARCHY_UNIQUE_NAME');
  AStructure := ADODataSet.FieldByName('STRUCTURE');
  ACardinality := ADODataSet.FieldByName('HIERARCHY_CARDINALITY');
  ALevels := TStringList.Create;
  ADODataSet.DisableControls;
  try
    while not ADODataSet.Eof do
    begin
      if ADimensionName.AsString = '[Measures]' then
      begin
        ADODataSet.Next;
        Continue;
      end;
      ADName := ADimensionName.AsString;
      ADName := Copy(ADName, 2, Length(ADName) - 2);
      // find dimension
      AParent := Structure.ItemByDisplayText(ADName);
      if AParent = nil then
      begin
        AParent := CreateNode(Structure, ADName, ntDimension);
        AParent.DimensionUniqueName := ADName;
      end;
      // find folder
      if (AFolder <> nil) and (AFolder.AsString <> '') then
      begin
        AFolderNode := AParent.ItemByDisplayText(AFolder.AsString);
        if AFolderNode = nil then
          AFolderNode := CreateNode(AParent, AFolder.AsString, ntFolder);
      end
      else
        AFolderNode := AParent;
      // add member
      ANode := CreateNode(AFolderNode, ACaption.AsString, ntField);
      AFolderNode.Expanded := False;
      ANode.HierarchyUniqueName := AHierarchyName.AsString;
      ANode.DimensionUniqueName := ADimensionName.AsString;
      ANode.UniqueName := ANode.DimensionUniqueName;
      ANode.StructureType := AStructure.AsInteger;
      ANode.Cardinality := ACardinality.Value;
      ANode.NodeType := ntGroup;
      ALevels.AddObject(ANode.HierarchyUniqueName, ANode);
      ANode.LevelUniqueName := ANode.HierarchyUniqueName + '.[' + GetLastNameFromPath(ANode.HierarchyUniqueName) + ']';
      ADODataSet.Next;
    end;
    AddLevels(ALevels);
  finally
    ADODataSet.EnableControls;
    ALevels.Free;
  end;
end;

procedure TcxPivotGridOLAPDataSource.AddLevels(ALevels: TStringList);
var
  AIndex: Integer;
  AParent, ANode: TcxPivotGridOLAPStructureNode;
  ADName, AUName, AHName, AName, ACount, ADBType, ANumber, ALType: TField;
begin
  if not OpenSchema(SCHEMA_LEVELS) then Exit;
  AHName := ADODataSet.FieldByName('HIERARCHY_UNIQUE_NAME');
  AUName := ADODataSet.FieldByName('LEVEL_UNIQUE_NAME');
  ADName := ADODataSet.FieldByName('DIMENSION_UNIQUE_NAME');
  AName := ADODataSet.FieldByName('LEVEL_NAME');
  ANumber := ADODataSet.FieldByName('LEVEL_NUMBER');
  ACount := ADODataSet.FieldByName('LEVEL_CARDINALITY');
  ADBType := ADODataSet.FieldByName('LEVEL_DBTYPE');
  ALType := ADODataSet.FieldByName('LEVEL_TYPE');
  ADODataSet.DisableControls;
  try
    while not ADODataSet.Eof do
    begin
      AIndex := ALevels.IndexOf(AHName.AsString);
      if (ALType.Value <> 1) and (AIndex >= 0) then
      begin
        AParent := TcxPivotGridOLAPStructureNode(ALevels.Objects[AIndex]);
        ANode := CreateNode(AParent, AName.AsString, ntField);
        ANode.HierarchyUniqueName := AHName.AsString;
        ANode.DimensionUniqueName := ADName.AsString;
        ANode.Cardinality := ACount.AsInteger;
        ANode.DBType := ADBType.AsInteger;
        ANode.LevelNumber := ANumber.AsInteger;
        ANode.LevelUniqueName := AUName.AsString;
        ANode.UniqueName := ANode.LevelUniqueName;
      end;
      ADODataSet.Next;
    end;
  finally
    ADODataSet.EnableControls;
  end;
end;

procedure TcxPivotGridOLAPDataSource.AddMeasures;

  function GetParentNode(AFolder: TField; AParentNode: TcxPivotGridOLAPStructureNode): TcxPivotGridOLAPStructureNode;
  begin
    Result := AParentNode;
    if (AFolder <> nil) and (AFolder.AsString <> '') then
    begin
      Result := AParentNode.ItemByDisplayText(AFolder.AsString);
      if Result = nil then
        Result := CreateNode(AParentNode, AFolder.AsString, ntFolder);
    end;
  end;

var
  AFolder, ACaption, AUniqueName, AMeasureDisplayFolder, ADefaultFormatString: TField;
  AMeasures, AParent, ANode: TcxPivotGridOLAPStructureNode;
begin
  if not OpenSchema(SCHEMA_MEASURES) then Exit;
  AMeasures := CreateNode(Structure, cxGetResourceString(@scxMeasures), ntMeasure);
  ACaption := ADODataset.FieldByName('MEASURE_CAPTION');
  AUniqueName := ADODataset.FieldByName('MEASURE_UNIQUE_NAME');
  AFolder := ADODataset.FindField('MEASUREGROUP_NAME');
  AMeasureDisplayFolder := ADODataset.FindField('MEASURE_DISPLAY_FOLDER');
  ADefaultFormatString := ADODataset.FindField('DEFAULT_FORMAT_STRING');
  ADODataSet.DisableControls;
  try
    while not ADODataSet.Eof do
    begin
      AParent := GetParentNode(AFolder, AMeasures);
      if AMeasureDisplayFolder <> nil then
        AParent := GetParentNode(AMeasureDisplayFolder, AParent);
      ANode := CreateNode(AParent, ACaption.AsString, ntField);
      ANode.UniqueName := AUniqueName.AsString;
      if ADefaultFormatString <> nil then
        ANode.Currency := ADefaultFormatString.AsString = 'Currency';
      ADODataSet.Next;
    end;
  finally
    ADODataSet.EnableControls;
  end;
end;

procedure TcxPivotGridOLAPDataSource.AddKPIs;
var
  APath: string;
  I: TcxOLAPKPIType;
  AName, ACaption, AValue: TField;
  AKPI, AParent: TcxPivotGridOLAPStructureNode;
  AGraphicFields: array[TcxOLAPKPIType] of TField;
  AGraphicTypes: TStringList;
const
  KPI_Names: array[TcxOLAPKPIType] of string =
    ('KPI_VALUE', 'KPI_GOAL', 'KPI_STATUS', 'KPI_TREND', 'KPI_WEIGHT');

  function GetGraphicType(AField: TField): TcxPivotGridOLAPKPIGraphicType;
  var
    APos: Integer;
  begin
    Result := gtNone;
    if AField = nil then Exit;
    APos := AGraphicTypes.IndexOf(AField.AsString);
    if APos >= 0 then
      Result := TcxPivotGridOLAPKPIGraphicType(AGraphicTypes.Objects[APos])
  end;

begin
  if IsOLAPVersion8 or not OpenSchema(SCHEMA_KPI) then Exit;
  AKPI := CreateNode(Structure, cxGetResourceString(@scxKPIs), ntKPI);
  ACaption := ADODataSet.FieldByName('KPI_CAPTION');
  AName := ADODataSet.FieldByName('KPI_NAME');
  AValue := ADODataSet.FieldByName('KPI_VALUE');
  FillChar(AGraphicFields, SizeOf(AGraphicFields), 0);
  AGraphicFields[oktStatus] := ADODataSet.FieldByName('KPI_STATUS_GRAPHIC');
  AGraphicFields[oktTrend] := ADODataSet.FieldByName('KPI_TREND_GRAPHIC');
  AGraphicTypes := TStringList.Create;
  ADODataSet.DisableControls;
  try
    try
      AGraphicTypes.AddObject('Shapes', TObject(gtShapes));
      AGraphicTypes.AddObject('Traffic Light', TObject(gtTrafficLights));
      AGraphicTypes.AddObject('Traffic Light - Single', TObject(gtTrafficLights));
      AGraphicTypes.AddObject('Traffic Light - Multiple', TObject(gtTrafficLights));
      AGraphicTypes.AddObject('Road Signs', TObject(gtRoadSigns));
      AGraphicTypes.AddObject('Gauge - Ascending', TObject(gtGauge));
      AGraphicTypes.AddObject('Gauge - Descending', TObject(gtReversedGauge));
      AGraphicTypes.AddObject('Thermometer', TObject(gtThermometer));
      AGraphicTypes.AddObject('Cylinder', TObject(gtCylinder));
      AGraphicTypes.AddObject('Smiley Face', TObject(gtFaces));
      AGraphicTypes.AddObject('Variance Arrow', TObject(gtVarianceArrow));
      AGraphicTypes.AddObject('Standard Arrow', TObject(gtStandardArrow));
      AGraphicTypes.AddObject('Status Arrow - Ascending', TObject(gtStatusArrow));
      AGraphicTypes.AddObject('Status Arrow - Descending', TObject(gtReversedStatusArrow));
      while not ADODataSet.Eof do
      begin
        AParent := CreateNode(AKPI, AName.AsString, ntFolder);
        with CreateNode(AParent, ACaption.AsString, ntField) do
        begin
          UniqueName := AValue.AsString;
          KPIName := AName.AsString;
        end;
        for I := oktGoal to oktWeight do
        begin
          APath := ADODataSet.FieldByName(KPI_NAMES[I]).AsString;
          if APath <> '' then
          begin
            with CreateNode(AParent, GetLastNameFromPath(APath), ntField) do
            begin
              UniqueName := APath;
              KPIName := AName.AsString;
              KPIType := I;
              KPIGraphicType := GetGraphicType(AGraphicFields[I]);
            end;
          end;
        end;
        ADODataSet.Next;
      end;
    finally
      AGraphicTypes.Free;
    end;
  finally
    ADODataSet.EnableControls;
  end;
end;

procedure TcxPivotGridOLAPDataSource.AddSETs;
var
  AItem, APath: string;
  ADimensions, ACaption, AFolder, AName: TField;
  AParent, AFolderNode, ANode: TcxPivotGridOLAPStructureNode;
begin
  try
    if not OpenSchema(SCHEMA_SETS) then Exit;
  except
  end;
  ADimensions := ADODataSet.FieldByName('DIMENSIONS');
  ACaption := ADODataSet.FieldByName('SET_CAPTION');
  AFolder := ADODataSet.FieldByName('SET_DISPLAY_FOLDER');
  AName := ADODataSet.FieldByName('SET_NAME');
  ADODataSet.DisableControls;
  try
    while not ADODataSet.Eof do
    begin
      APath := ADimensions.AsString;
      AParent := Structure;
      while APath <> '' do
      begin
        AItem := GetPathItem(APath);
        if APath <> '' then
          AParent := AParent.ItemByDisplayText(AItem);
        if AParent = nil then
          Break;
      end;
      if AParent <> nil then
      begin
        AFolderNode := AParent.ItemByDisplayText(AFolder.AsString);
        if AFolderNode = nil then
          AFolderNode := CreateNode(AParent, AFolder.AsString, ntSet);
        ANode := CreateNode(AFolderNode, ACaption.AsString, ntSet);
        ANode.DimensionUniqueName := ADimensions.AsString;
        ANode.UniqueName := AName.AsString;
        ANode.LevelUniqueName := ADimensions.AsString;
        ANode.HierarchyUniqueName := ADimensions.AsString;
      end;
      ADODataSet.Next;
    end;
  finally
    ADODataSet.EnableControls;
  end;
end;

function TcxPivotGridOLAPDataSource.CheckCubeName: Boolean;
begin
  Result := ADODataSet.FieldByName('CUBE_NAME').AsString = Cube;
end;

function TcxPivotGridOLAPDataSource.CreateNode(AParent: TcxPivotGridOLAPStructureNode;
  const ACaption: string; ANodeType: TcxOLAPStructureNodeType): TcxPivotGridOLAPStructureNode;
begin
  Result := TcxPivotGridOLAPStructureNode(AParent.AddChild);
  Result.DisplayText := ACaption;
  Result.NodeType := ANodeType;
end;

procedure TcxPivotGridOLAPDataSource.CreateStructure;

  procedure CheckSingleNodes(ANode: TcxPivotGridOLAPStructureNode);
  var
    I: Integer;
  begin           
    if not ANode.HasChildren then Exit;
    if ANode.NodeType = ntGroup then
    begin
      if ANode.Count = 1 then
      begin
        ANode.First.MoveTo(ANode.Parent, namAddChild);
        ANode.Free;
      end; 
    end
    else
      for I := ANode.Count - 1 downto 0 do
        CheckSingleNodes(TcxPivotGridOLAPStructureNode(ANode.Items[I]));
  end;

begin
  Structure.Clear;
  Structure.DisplayText := Cube;
  AddMeasures;
  AddDimensions;
  AddKPIs;
  AddSETs;
  CheckSingleNodes(Structure);
  Structure.CustomSort(@CompareStructureNodes, True);
end;

function GetTempFile(const AExt: string): string;
var
  Buffer: array[0..MAX_PATH] of char;
begin
  repeat
    GetTempPath(MAX_PATH, Buffer);
    GetTempFileName(Buffer, '~', 0, Buffer);
    Result := ChangeFileExt(Buffer, AExt);
  until not FileExists(Result);
end;

procedure TcxPivotGridOLAPDataSource.CreateTemporaryCube;
var
  APos, AEndPos: Integer;
  AName, ASource: string;
const
  ADataSource: AnsiString = 'Data Source=';
begin
  APos := Pos(dxAnsiStringToString(ADataSource), dxWideStringToString(ConnectionString));
  DeleteCachedFile;
  if APos = 0 then Exit;
  Inc(APos, Length(ADataSource));
  AEndPos := APos;
  while (AEndPos < Length(ConnectionString)) and (ConnectionString[AEndPos] <> ';') do Inc(AEndPos);
  ASource := Copy(ConnectionString, APos, AEndPos - APos + 1);
  if FileExists(ASource) then
  try
    AName := GetTempFile('.cub');
    with TMemoryStream.Create do
    try
      LoadFromFile(ASource);
      SaveToFile(AName);
    finally
      Free;
    end;
    FConnectionString := ConnectionString;
    FCachedFileName := AName;
    Connection.ConnectionString := StringReplace(Connection.ConnectionString, ASource, AName, [rfReplaceAll]);
  except
    on EStreamError do
      begin
        DeleteCachedFile;
        ASource := '';
      end
    else
      raise;
  end;
end;

procedure TcxPivotGridOLAPDataSource.DeleteCachedFile;
begin
  if FileExists(FCachedFileName) then
    DeleteFile(PChar(FCachedFileName));
  if FConnectionString <> '' then
  begin
    Connection.ConnectionString := FConnectionString;
    FConnectionString := '';
  end;
  FCachedFileName := '';
end;


function TcxPivotGridOLAPDataSource.GetLastNameFromPath(const APath: string): string;
var
  I: Integer;
begin
  I := Length(APath) - 1;
  while (I > 0) and (APath[I] <> '[') do
    Dec(I);
  Result := Copy(APath, I + 1, Length(APath) - I - 1);
end;

function TcxPivotGridOLAPDataSource.GetPathItem(var APath: string): string;
var
  APos: Integer;
begin
  Result := '';
  APos := Pos(']', APath);
  if APos = 0 then Exit;
  Result := Copy(APath, 2, APos - 2);
  Delete(APath, 1, APos + 1);
end;

function TcxPivotGridOLAPDataSource.CreateDrillDownDataSet(
  ACells: TList; AFieldList: TcxObjectList; ASummaryIndex: Integer): TADODataSet;
var
  AQuery: string;
begin
  Result := TADODataSet.Create(Self);
  if not TcxPivotGridCrossCell(ACells[0]).IsEmpty then
  begin
    AQuery := GetDrillDownCommandText(TcxPivotGridCrossCell(ACells[0]), AFieldList, ASummaryIndex);
    if AQuery = '' then Exit;
    try
      Result.Recordset := Connection.Execute(AQuery);
    except
    end;
  end;
end;

function TcxPivotGridOLAPDataSource.CreateDrillDownDataSource(
  ACells: TList; AFieldList: TcxObjectList; ASummaryIndex: Integer): TcxPivotGridCrossCellDataSource;
begin
  Result := TcxPivotGridOLAPDrillDownDataSource.CreateEx(ACells);
  (Result as TcxPivotGridOLAPDrillDownDataSource).FDataSet :=
    CreateDrillDownDataSet(ACells, AFieldList, ASummaryIndex);
end;

procedure TcxPivotGridOLAPDataSource.CreateMembers(AField: TcxPivotGridField;
  AParent: TcxPivotGridGroupItem; AHasChildren: Boolean; ADataFields: TcxPivotGridFields);

  function DataIsNotNull: Boolean;
  var
    I, ACounter: Integer;
  begin
    Result := False;
    ACounter := 0;
    for I := ADODataSet.FieldByName(OLAPMemberUniqueNameColumnName).Index + 1 to ADODataSet.FieldCount - 1 do
    begin
      Inc(ACounter);
      if ADODataSet.Fields[I].Value <> Null then
      begin
        Result := True;
        Break;
      end;
    end;
    if (ACounter = 0) and (QueryBuilder.GetMeasuresCount(ADataFields, oftMeasure) = 0) then
      Result := True;
  end;

  function UniqueNameCorrection(AValue: string): string;
  const
    ValueMark = '.&[';
  var
    APos: Integer;
  begin
    Result := AValue;

    APos := Pos(ValueMark, AValue);
    APos := PosEx(ValueMark, AValue, APos + 1);
    if APos > 0 then
    begin
      Result := Copy(AValue, 1, APos - 1);
    end;
  end;

  procedure AddGroupItem(AIndex: Integer);
  var
    AGroupItem: TcxPivotGridGroupItem;
    AFullName: string;
    AMemberFieldCaption, AMemberName: TField;
    AUniqueName: string;
  begin
    AUniqueName := UniqueNameCorrection(ADODataSet.FieldByName(OLAPMemberUniqueNameColumnName).AsString);
    if (Pos(TcxPivotGridOLAPField(AField).HierarchyUniqueName + '.[All]', AUniqueName) = 0) and
      DataIsNotNull then
    begin
      AGroupItem := AParent.AddChild(AParent.ItemCount, AIndex - 1, AField);
      AMemberName := ADODataSet.FieldByName(OLAPMemberNameColumnName);
      AMemberFieldCaption := ADODataSet.Fields[0];
      if VarIsNull(AMemberName.Value) then
        AFullName := AMemberFieldCaption.AsString
      else
        AFullName := AMemberName.AsString;
      AGroupItem.InitializeValue(AFullName, AUniqueName);
      AGroupItem.HasChildren := AHasChildren;
    end;
  end;

  procedure AddGroupItemOLAP8(AIndex: Integer);
  var
    AGroupItem: TcxPivotGridGroupItem;
    AFullName: string;
  begin
     AGroupItem := AParent.AddChild(AParent.ItemCount, AIndex - 1, AField);
     AFullName := ADODataSet.Fields[AIndex].DisplayName;
     AGroupItem.InitializeValue(ExtractMemberName(AFullName), AFullName);
     AGroupItem.HasChildren := AHasChildren;
  end;


var
  I: Integer;
begin
  if (AField = nil) or not ADODataSet.Active then Exit;
  ADODataSet.First;
  if Version > 8 then
  begin
    I := 0;
    while not ADODataSet.Eof do
    begin
      AddGroupItem(I);
      ADODataSet.Next;
      Inc(I);
    end;
  end
  else
  begin
    for I := 0 to ADODataSet.FieldCount - 1 do
      AddGroupItemOLAP8(I);
  end;
end;

function TcxPivotGridOLAPDataSource.ExecuteQuery(AQuery: WideString): Boolean;
begin
  Result := False;
  if (AQuery = '') or (ADODataSet = nil) then Exit;
  try
    ADODataSet.Recordset := Connection.Execute(AQuery);
    ADODataSet.First;
    Result := True;
  except
  end;
end;

procedure TcxPivotGridOLAPDataSource.ExtractProviderVersion(
  const AVersion: string);
var
  ACode: Integer;
begin
  FVersion := 0;
  if Pos('.', AVersion) > 0 then
  begin
    Val(Copy(AVersion, 1, Pos('.', AVersion) - 1), FVersion, ACode);
    if ACode <> 0 then
      FVersion := 0;
  end;
  if FVersion > 10 then
    EcxPivotGrid.CreateFmt(scxUnsupportedProviderVersion, [FVersion]);
end;

function TcxPivotGridOLAPDataSource.OpenSchema(const ASchemaType: string): Boolean;
var
  ARestriction: OLEVariant;
begin
  ARestriction := EmptyParam;
  if (Cube <> '') and not FIsLocalCube then
    ARestriction := VarArrayOf([Null, Null, Cube, Null]);
  try
    Connection.OpenSchema(siProviderSpecific, ARestriction, ASchemaType, ADODataSet);
    ADODataSet.Active := True;
  except
    ADODataSet.Active := False;
  end;
  Result := ADODataSet.Active and (ADODataSet.RecordCount > 0);
  if Result then
    ADODataSet.First;
end;

function TcxPivotGridOLAPDataSource.GetIsActive: Boolean;
begin
  Result := (FConnection.Connected or FTerminated) and inherited GetIsActive;
  Result := Result and ([csLoading, csDestroying] * ComponentState = []);
end;

function TcxPivotGridOLAPDataSource.GetIsTerminated: Boolean;
begin
  Result := FTerminated;
end;

function TcxPivotGridOLAPDataSource.GetMeasureName(AFullName: string): string;
var
  I, L: Integer;
begin
  L := Length(AFullName);
  I := L;
  while I > 0 do
  begin
    if AFullName[I] = '[' then
      Break;
    Dec(I);
  end;
  Result := Copy(AFullName, I + 1, L - I - 1);
end;

function TcxPivotGridOLAPDataSource.GetNonExpandedFields(ADataBuilder: TcxPivotGridDataBuilder;
  AnExpandingItem, AnItem: TcxPivotGridGroupItem; ACrossGroupItems: TList; AddHierarchyField: Boolean): TcxPivotGridFields;

  function HierarchyFieldDublicationAvoidance(AFields: TcxPivotGridFields; ACrossGroupItems: TList; AnExpandingItem: TcxPivotGridGroupItem): Boolean;
  var
    I: Integer;
  begin
    Result := True;
    for I := 0 to AFields.Count - 1 do
    begin
      if (AFields[I].Group <> nil) and (AFields[I].Group = AnExpandingItem.Field.Group) then
        Result := False;
    end;

    if Result and (ACrossGroupItems <> nil) then
      for I := ACrossGroupItems.Count - 1 downto 0 do
      begin
        if TcxPivotGridGroupItem(ACrossGroupItems[I]).Field.Group = AnExpandingItem.Field.Group then
          ACrossGroupItems.Delete(I);
      end;
  end;

  function IsFieldExist(AField: TcxPivotGridField): Boolean;
  begin
    Result := AField.GroupIndex + 1 < AField.Group.VisibleCount;
  end;

var
  AFieldList: TcxPivotGridFields;
begin
  Result := TcxPivotGridFields.Create;
  if AnExpandingItem <> nil then
  begin
    if not IsNotLastVisibleOLAPHierarchyItem(AnExpandingItem) then
    begin
      AFieldList := ADataBuilder.GetFieldsListByArea(AnExpandingItem.Field.Area);
      Result.Add(AFieldList.Fields[AFieldList.IndexOf(AnExpandingItem.Field) + 1]);
    end
    else
      if AddHierarchyField and IsOLAPHierarchy(AnExpandingItem) and
        HierarchyFieldDublicationAvoidance(Result, ACrossGroupItems, AnExpandingItem) and
        IsFieldExist(AnExpandingItem.Field) then
          Result.Add(AnExpandingItem.Field.Group.Fields[AnExpandingItem.Field.GroupIndex + 1]);
  end;
  if (AnItem <> nil) and not IsNotLastVisibleOLAPHierarchyItem(AnItem) and AnItem.HasChildren then
    Result.Add(AnItem.Items[0].Field)
  else
    if AddHierarchyField and (AnItem <> nil) and IsOLAPHierarchy(AnItem) and IsFieldExist(AnItem.Field) then
      Result.Add(AnItem.Field.Group.Fields[AnItem.Field.GroupIndex + 1]);
end;

function TcxPivotGridOLAPDataSource.GetFieldIndex(AField: TcxPivotGridField; AStartIndex: Integer): Integer;
var
  ALevelUniqueName: string;
begin
  Result := GetFieldIndex(AField, AStartIndex, ALevelUniqueName);
end;

function TcxPivotGridOLAPDataSource.GetFieldIndex(AField: TcxPivotGridField; AStartIndex: Integer; out ALevelUniqueName: string): Integer;

  function GetLevelUniqueName(AConsiderHierarchy: Boolean): string;
  begin
    if TcxPivotGridOLAPField(AField).IsMeasure then
      Result := AField.UniqueName
    else
      if AConsiderHierarchy and TcxPivotGridOLAPField(AField).IsHierarchy and (TcxPivotGridOLAPField(AField).LevelNumber > 1) then
        Result := GetOLAPHierarchyLevelUniqueName(TcxPivotGridOLAPField(AField))
      else
        Result := TcxPivotGridOLAPField(AField).HierarchyUniqueName;
  end;

var
  AIterationIndex: Integer;
begin
  if IsOLAPVersion8 then
    Result := AStartIndex
  else
  begin
    ALevelUniqueName := GetLevelUniqueName(True);
    if ALevelUniqueName = '' then
      raise Exception.Create('Field not found');
    AIterationIndex := 1;
    Result := AStartIndex;
    with ADODataSet do
      while Pos(ALevelUniqueName, Fields[Result].DisplayName) = 0 do
      begin
        Inc(Result);
        if Result = FieldCount then
        begin
          if AIterationIndex < 3 then
          begin
            if AIterationIndex = 2 then
              ALevelUniqueName := GetLevelUniqueName(False);
            Result := 0;
            Inc(AIterationIndex);
          end
          else
            raise Exception.Create('Field not found');
        end;
      end;
  end;
end;

function TcxPivotGridOLAPDataSource.GetRowID(var AExpandingFieldIndex: Integer; ARowField: TcxPivotGridField): string;
var
  I, AFieldIndex: Integer;
  ALevelUniqueName: string;
begin
  AFieldIndex := GetFieldIndex(ARowField, AExpandingFieldIndex, ALevelUniqueName);
  if IsOLAPVersion8 then
    ALevelUniqueName := TcxPivotGridOLAPField(ARowField).HierarchyUniqueName;
  AExpandingFieldIndex := AFieldIndex;
  if ALevelUniqueName = '' then
    raise Exception.Create('Field not found');
  with ADODataSet do
  begin
    if Pos(ALevelUniqueName, Fields[AFieldIndex].DisplayName) = 0 then
      raise Exception.Create('Field name mismatch');
    I := AFieldIndex + 1;
    while (I < Fields.Count) and
      (Pos(ALevelUniqueName, Fields[I].DisplayName) > 0) and (Fields[I].AsString <> '') do
      Inc(I);
    Dec(I);
    Result := Fields[I].AsString;
  end;
end;

procedure TcxPivotGridOLAPDataSource.Initialize;
begin
  inherited Initialize;
  FCubes.Clear;
  ExtractProviderVersion(VarToStr(Connection.Properties.Item['Provider Version'].Value));
  CreateQueryBuilder;
  if not IsCubeNameAssigned then
    FCube := '';
  FIsLocalCube := Pos('.CUB', UpperCase(ConnectionString)) <> 0;
  if not OpenSchema(SCHEMA_CUBES) then
  begin
    Active := False;
    raise EcxPivotGrid.Create(scxInvalidProviderVersion);
  end
  else
  begin
    while not ADODataSet.Eof do
    begin
      FCubes.Add(ADODataSet.FieldByName('CUBE_NAME').AsString);
      ADODataSet.Next;
    end;
    if (FCube = '') and (FCubes.Count > 0) then
      FCube := FCubes[0];
    if FCubes.IndexOf(FCube) < 0 then
    begin
      Active := False;
      raise EcxPivotGrid.CreateFmt(scxInvalidCubeName, [FCube]);
    end;
  end;
  if csDesigning in ComponentState then
    TerminateConnection
end;

procedure TcxPivotGridOLAPDataSource.InitializeCrossCells(ARowsGroup,
  AColumnsGroup: TcxPivotGridGroupItem; ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType);
var
  AColumn, ARow: TcxPivotGridGroupItem;
  I, J: Integer;
  AColumnFieldIndexInDataSet, ARowFieldIndexInDataSet, AFirstDataFieldIndexInDataSet: Integer;
begin
  if not IsDataValid or (ADataFields.Count = 0) or (ARowsGroup.ItemCount = 0) or
    (AColumnsGroup.ItemCount = 0) then
    Exit;

  if GetDataFieldCount(ADataFields, AOLAPType) > 0 then
  begin
    AColumnFieldIndexInDataSet := GetFieldIndex(AColumnsGroup.Items[0].Field, 0);
    ARowFieldIndexInDataSet := GetFieldIndex(ARowsGroup.Items[0].Field, 0);
    AFirstDataFieldIndexInDataSet := GetFieldIndex(TcxPivotGridField(ADataFields.Items[0]), 0);

    ADODataSet.First;
    for I := 0 to ARowsGroup.ItemCount - 1 do
    begin
      ARow := ARowsGroup.Items[I];
      for J := 0 to AColumnsGroup.ItemCount - 1 do
      begin
        AColumn := AColumnsGroup.Items[J];
        while not ADODataSet.Eof and (ADODataSet.Fields[ARowFieldIndexInDataSet].Value <> ARow.UniqueName) do
          ADODataSet.Next;
        if not ADODataSet.Eof then
        begin
          while not ADODataSet.Eof and (ADODataSet.Fields[AColumnFieldIndexInDataSet].Value <> AColumn.UniqueName) do
            ADODataSet.Next;
          if not ADODataSet.Eof then
          begin
            ProcessDataFieldsEx(AColumn, ARow, ADataFields, ADODataSet.RecNo, AFirstDataFieldIndexInDataSet, oftMeasure);
            ADODataSet.Next;
          end;
        end
        else
          Break;
      end;
    end;
  end;
end;

procedure TcxPivotGridOLAPDataSource.InitializeCrossCellsKPI(ARowsGroup, AColumnsGroup: TcxPivotGridGroupItem;
  ARowField: TcxPivotGridField; ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex, AExpandingFieldIndex: Integer);

  function GetRow(var Index: Integer): TcxPivotGridGroupItem;
  begin
    if Index = ARowsGroup.ItemCount then
      Index := 0;
    Result := ARowsGroup.Items[Index];
  end;

var
  ARow: TcxPivotGridGroupItem;
  J, AStartRow: Integer;
  ARowID: string;
begin
  if not IsDataValid or (ADataFields.Count = 0) or (ARowsGroup.ItemCount = 0) or
    (AColumnsGroup.ItemCount = 0) then
    Exit;

  if GetDataFieldCount(ADataFields, AOLAPType) > 0 then
    with ADODataSet do
    begin
      First;
      J := 0;
      while not Eof do
      begin
        ARowID := GetRowID(AExpandingFieldIndex, ARowField);
        if ARowID <> '' then
        begin
          ARow := GetRow(J);
          AStartRow := J;
          while ARowID <> ARow.UniqueName do
          begin
            Inc(J);
            ARow := GetRow(J);
            if J = AStartRow then
              Break;
          end;

          if ARowID = ARow.UniqueName then
            ProcessColumns(AColumnsGroup, ARow, AFieldIndex);

          Inc(J);
        end;
        Next;
      end;
      Close;
    end;
end;

procedure TcxPivotGridOLAPDataSource.InitializeKPITotal(AColumnsGroup, ARowsGroup: TcxPivotGridGroupItem;
  ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex: Integer);
begin
  if not IsDataValid or (ADataFields.Count = 0) then
    Exit;

  if GetDataFieldCount(ADataFields, AOLAPType) > 0 then
    with ADODataSet do
    begin
      First;
      ProcessDataField(AColumnsGroup, ARowsGroup, ADODataSet.FieldCount - 1, AFieldIndex);
      Close;
    end;
end;

procedure TcxPivotGridOLAPDataSource.InitializeKPITotals(AColumnsGroup, ARowsGroup: TcxPivotGridGroupItem;
  ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex: Integer);
var
  ARow: TcxPivotGridGroupItem;
begin
  if not IsDataValid or (ADataFields.Count = 0) or (AColumnsGroup.ItemCount = 0) then
    Exit;

  if GetDataFieldCount(ADataFields, AOLAPType) > 0 then
    with ADODataSet do
    begin
      First;
      ARow := ARowsGroup;
      ProcessColumns(AColumnsGroup, ARow, AFieldIndex);
      Close;
    end;
end;

procedure TcxPivotGridOLAPDataSource.InitializeExpanding(ADataBuilder: TcxPivotGridDataBuilder; AField: TcxPivotGridField;
  AnExpandingItem, ACrossGroup: TcxPivotGridGroupItem; ADataFields: TcxPivotGridFields);

  procedure PopulateCrossCellsForExpandedItem(AnExpandingItem, ACrossGroup: TcxPivotGridGroupItem);
  var
    ANativeValues: Variant;
    ADataFieldIndex: Integer;

    procedure ResetNativeValues;
    var
      I: Integer;
    begin
      for I := 0 to ADataFields.Count - 1 do
        ANativeValues[I] := Null;
    end;

    procedure SecondLevelProcessing(AFirstItem, ASecondItem: TcxPivotGridGroupItem;
      AFieldIndex, AFirstItemChildIndex: Integer; ARowField: TcxPivotGridField);
    var
      ASecondItemChildIndex, AProcessedFieldCount: Integer;
      ASecondLevelName: string;
    begin
      if IsOLAPVersion8 then
        ASecondLevelName := ADODataSet.Fields[AFieldIndex].Value
      else
        ASecondLevelName := GetRowID(AFieldIndex, ARowField);

      if ADataFieldIndex > AFieldIndex + 1 then //Because there is field removing in HierarchyFieldDublicationAvoidance method
        ADataFieldIndex := AFieldIndex + 1;
        
      ASecondItemChildIndex := 0;
      while ASecondItemChildIndex < ASecondItem.ItemCount do
      begin
        if Pos(ASecondLevelName, ASecondItem.Items[ASecondItemChildIndex].UniqueName) > 0 then
          ProcessDataFields(AFirstItem.Items[AFirstItemChildIndex], ASecondItem.Items[ASecondItemChildIndex],
            ADataFields, ADataFieldIndex, '', oftMeasure, AProcessedFieldCount);
        Inc(ASecondItemChildIndex);
      end;
    end;

    function CompareWithFirstMember(const AFirstLevelName: string; ACrossGroup: TcxPivotGridGroupItem): Boolean;
    begin
      Result := Pos(AFirstLevelName, ACrossGroup.UniqueName) > 0;
    end;

  var
    AFirstItemChildIndex, ARowIndex, I, AFieldIndex, ASecondLevelFieldIndex, AExpandingFieldIndex: Integer;
    AFirstItem, ASecondItem: TcxPivotGridGroupItem;
    AFirstLevelName: string;
    ASecondRowField: TcxPivotGridField;
  begin
    if not IsDataValid then
      Exit;

    ANativeValues := VarArrayCreate([0, ADataFields.Count - 1], varVariant);
    ResetNativeValues;

    try
      if IsNotLastVisibleOLAPHierarchyItem(AnExpandingItem) and not
        IsNotLastVisibleOLAPHierarchyItem(ACrossGroup) then
      begin
        AExpandingFieldIndex := AnExpandingItem.Field.Group.IndexOf(AnExpandingItem.Field);
        AFieldIndex := 1 + AExpandingFieldIndex;
        ASecondLevelFieldIndex := 2 + AExpandingFieldIndex;
        ADataFieldIndex := 3 + AExpandingFieldIndex; //TODO: Use GetFieldIndex
      end
      else
      begin
        AFieldIndex := 0;
        ASecondLevelFieldIndex := 1;
        if IsOLAPVersion8 then
          ADataFieldIndex := 2
        else
          ADataFieldIndex := GetFieldIndex(AnExpandingItem.Field, 2);
      end;
      AFirstItem := AnExpandingItem;
      ASecondItem := ACrossGroup;

      ASecondRowField := ACrossGroup.Items[0].Field;

      AFirstItemChildIndex := 0;
      FADODataSet.First;
      for ARowIndex := 0 to FADODataSet.RecordCount - 1 do
      begin
        AFirstLevelName := GetRowID(AFieldIndex, AnExpandingItem.Items[0].Field);
        if CompareWithFirstMember(AFirstLevelName, AFirstItem.Items[AFirstItemChildIndex]) then
          SecondLevelProcessing(AFirstItem, ASecondItem, ASecondLevelFieldIndex, AFirstItemChildIndex, ASecondRowField)
        else
        begin
          Inc(AFirstItemChildIndex);
          if (AFirstItemChildIndex < AFirstItem.ItemCount) and
            CompareWithFirstMember(AFirstLevelName, AFirstItem.Items[AFirstItemChildIndex]) then
            SecondLevelProcessing(AFirstItem, ASecondItem, ASecondLevelFieldIndex, AFirstItemChildIndex, ASecondRowField)
          else
            for I := 0 to AFirstItem.ItemCount - 1 do
            begin
              AFirstItemChildIndex := I;
              if CompareWithFirstMember(AFirstLevelName, AFirstItem.Items[AFirstItemChildIndex]) then
              begin
                SecondLevelProcessing(AFirstItem, ASecondItem, ASecondLevelFieldIndex, AFirstItemChildIndex, ASecondRowField);
                Break;
              end;
            end;
        end;
        FADODataSet.Next;
      end;
    finally
      FADODataSet.Close;
    end;
  end;

  procedure InitializeCrossCellsForExpandedItem(AnExpandingItems: TList; ACrossGroup: TcxPivotGridGroupItem; ACrossGroupLevel: Integer); forward;

  procedure InitializeCrossCellsForCrossGroupItem(AnExpandingItems: TList; ACrossGroup: TcxPivotGridGroupItem; ACrossGroupLevel: Integer);
  var
    AMembers: TList;
    AFields: TcxPivotGridFields;
    AnExpandingItem: TcxPivotGridGroupItem;
  begin
    AnExpandingItem := TcxPivotGridGroupItem(AnExpandingItems[0]);
    AMembers := TList.Create;
    try
      ExpandedItemWithParentsToList(AnExpandingItems, AMembers, ACrossGroupLevel < 3);
      AFields := GetNonExpandedFields(ADataBuilder, AnExpandingItem, ACrossGroup, AMembers, True);
      try
        ExecuteQuery(QueryBuilder.GetExpandQueryString(Cube,
          AMembers, AFields, ADataFields, ADataBuilder.FilteredFields, oftMeasure));
      finally
        AFields.Free;
      end;
    finally
      AMembers.Free;
    end;
    if (AnExpandingItem.ItemCount > 0) and (ACrossGroup.ItemCount > 0) then
      InitializeCrossCellsForExpandedItem(AnExpandingItems, ACrossGroup, ACrossGroupLevel);
  end;

  procedure InitializeCrossCellsForExpandedItem(AnExpandingItems: TList; ACrossGroup: TcxPivotGridGroupItem; ACrossGroupLevel: Integer);
  var
    I: Integer;
    AnExpandingItem, AnExpandedCrossItem: TcxPivotGridGroupItem;
  begin
    if QueryBuilder.GetMeasuresCount(ADataFields, oftMeasure) = 0 then
      Exit;

    AnExpandingItem := TcxPivotGridGroupItem(AnExpandingItems[0]);
    PopulateCrossCellsForExpandedItem(AnExpandingItem, ACrossGroup);

    if ACrossGroupLevel = 1 then
      AnExpandedCrossItem := ACrossGroup
    else
    begin
      AnExpandedCrossItem := TcxPivotGridGroupItem(AnExpandingItems[0]);
      AnExpandingItem := TcxPivotGridGroupItem(AnExpandingItems[1]);
      AnExpandingItems.Delete(0);
    end;
    for I := 0 to AnExpandedCrossItem.ItemCount - 1 do
    begin
      AnExpandedCrossItem.Items[I].CheckExpanding;
      if AnExpandedCrossItem.Items[I].Expanded then
      begin
        AnExpandingItems.Insert(0, AnExpandedCrossItem.Items[I]);
        Inc(ACrossGroupLevel);
        InitializeCrossCellsForCrossGroupItem(AnExpandingItems, AnExpandingItem, ACrossGroupLevel);
        AnExpandingItems.Remove(AnExpandedCrossItem.Items[I]);
      end;
    end;
  end;

  procedure InitializeKPICrossCellsForExpandedItem(ACrossGroup: TcxPivotGridGroupItem; AnExpandingItems: TList;
    ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex: Integer); forward;

  procedure InitializeKPICrossCellsForCrossGroupItem(AnExpandingItems: TList; ACrossGroup: TcxPivotGridGroupItem;
    ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex: Integer);
  var
    AMembers: TList;
    AFields: TcxPivotGridFields;
  begin
    AMembers := TList.Create;
    try
      ExpandedItemWithParentsToList(AnExpandingItems, AMembers);
      AFields := GetNonExpandedFields(ADataBuilder, TcxPivotGridGroupItem(AnExpandingItems[0]), ACrossGroup, nil, True);
      try
        QueryKPIExpandCrossCells(ADataBuilder, AMembers, AFields, ADataFields, AFieldIndex);
      finally
        AFields.Free;
      end;
    finally
      AMembers.Free;
    end;
    if (TcxPivotGridGroupItem(AnExpandingItems[0]).ItemCount > 0) and (ACrossGroup.ItemCount > 0) then
      InitializeKPICrossCellsForExpandedItem(ACrossGroup, AnExpandingItems, ADataFields, AOLAPType, AFieldIndex);
  end;

  procedure InitializeKPICrossCellsForExpandedItem(ACrossGroup: TcxPivotGridGroupItem; AnExpandingItems: TList;
    ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType; AFieldIndex: Integer);
  var
    I, AExpandingFieldIndex: Integer;
    AnExpandingItem, ATempItem: TcxPivotGridGroupItem;
    ARowField: TcxPivotGridField;
  begin
    AExpandingFieldIndex := 0;
    AnExpandingItem := TcxPivotGridGroupItem(AnExpandingItems[0]);
    if IsNotLastVisibleOLAPHierarchyItem(AnExpandingItem) and not
      IsNotLastVisibleOLAPHierarchyItem(ACrossGroup) then
    begin
      AExpandingFieldIndex := AnExpandingItem.Field.Group.IndexOf(AnExpandingItem.Field) + 1;
      ATempItem := ACrossGroup;
      ACrossGroup := AnExpandingItem;
      AnExpandingItem := ATempItem;
    end;

    if (AnExpandingItem.Field <> nil) and (AnExpandingItem.Field.Area = faRow) then
      ARowField := ACrossGroup.Items[0].Field
    else
      if AField.Area = faRow then
        ARowField := AField
      else
        ARowField := ACrossGroup.Items[0].Field;
    InitializeCrossCellsKPI(ACrossGroup, AnExpandingItem, ARowField, ADataFields, oftKPI, AFieldIndex, AExpandingFieldIndex);

    for I := 0 to ACrossGroup.ItemCount - 1 do
    begin
      ACrossGroup.Items[I].CheckExpanding;
      if ACrossGroup.Items[I].Expanded then
      begin
        AnExpandingItems.Insert(0, ACrossGroup.Items[I]);
        InitializeKPICrossCellsForCrossGroupItem(AnExpandingItems, AnExpandingItem, ADataFields, AOLAPType, AFieldIndex);
        AnExpandingItems.Remove(ACrossGroup.Items[I]);
      end;
    end;
  end;

  procedure InitializeKPIsCrossCells(AMembers: TList; AFields: TcxPivotGridFields;
    AnExpandingItem, ACrossGroup: TcxPivotGridGroupItem);
  var
    I: Integer;
    AnExpandingItems: TList;
  begin
    for I := 0 to ADataFields.Count - 1 do
      if TcxPivotGridOLAPField(ADataFields[I]).FieldType = oftKPI then
      begin
        QueryKPIExpandCrossCells(ADataBuilder, AMembers, AFields, ADataFields, I);
        AnExpandingItems := TList.Create;
        try
          AnExpandingItems.Add(AnExpandingItem);
          InitializeKPICrossCellsForExpandedItem(ACrossGroup, AnExpandingItems, ADataFields, oftKPI, I);
        finally
          AnExpandingItems.Free;
        end;
      end;
  end;

  function SmartExecuteQuery(AMembers: TList; AFields, ADataFields, AFilteredFields: TcxPivotGridFields; AType: TcxPivotGridOLAPFieldType): Boolean;
  var
    ALastMemberIndex: Integer;
    AFilterMembers, ANewMembers: TList;
    I, ATryNumber: Integer;
  begin
    Result := ExecuteQuery(QueryBuilder.GetExpandQueryString(Cube, AMembers, AFields, ADataFields, AFilteredFields, AType));
    if not Result then
    begin
      ALastMemberIndex := AMembers.Count - 1;
      ANewMembers := TList.Create;
      AFilterMembers := TList.Create;
      try
        ATryNumber := 0;
        repeat
          AFilterMembers.Clear;
          for I := ALastMemberIndex downto ALastMemberIndex - ATryNumber do
            AFilterMembers.Add(AMembers[I]);
          ANewMembers.Clear;
          for I := 0 to AMembers.Count - 2 - ATryNumber do
            ANewMembers.Add(AMembers[I]);
          Result := ExecuteQuery(QueryBuilder.GetExpandQueryString(Cube, ANewMembers, AFields, ADataFields, AFilteredFields, AType, oktValue, '', AFilterMembers));
          Inc(ATryNumber);
        until Result or (ATryNumber >= AMembers.Count - 1);
      finally
        AFilterMembers.Free;
        ANewMembers.Free;
      end;
    end;
  end;

var
  AHasChildren: Boolean;
  AMembers: TList;
  AFields, AExpandedFields: TcxPivotGridFields;
  I: Integer;
  AnExpandingItems: TList;
begin
  if AnExpandingItem.UniqueName = '' then Exit;
  AMembers := TList.Create;
  try
    ExpandedItemWithParentsToList(AnExpandingItem, AMembers);
    AFields := GetNonExpandedFields(ADataBuilder, AnExpandingItem, ACrossGroup, nil, False);
    try
      QueryRootMembers(AField, AMembers, ADataBuilder.FilteredFields, ADataFields);

      AHasChildren := (AField.Area = faColumn) and (AField.VisibleIndex < (ADataBuilder.ColumnFields.Count - 1))
        or (AField.Area = faRow) and (AField.VisibleIndex < (ADataBuilder.RowFields.Count - 1));
      CreateMembers(AField, AnExpandingItem, AHasChildren, ADataFields);

      SmartExecuteQuery(AMembers, AFields, ADataFields, ADataBuilder.FilteredFields, oftMeasure);

      if (AnExpandingItem.ItemCount > 0) and (ACrossGroup.ItemCount > 0) then
      begin
        AnExpandingItems := TList.Create;
        try
          AnExpandingItems.Add(AnExpandingItem);
          InitializeCrossCellsForExpandedItem(AnExpandingItems, ACrossGroup, 1);
        finally
          AnExpandingItems.Free;
        end;
        InitializeKPIsCrossCells(AMembers, AFields, AnExpandingItem, ACrossGroup);
      end;

      AExpandedFields := GetNonExpandedFields(ADataBuilder, AnExpandingItem, nil, nil, False);
      try
        QueryLayoutTotals(AExpandedFields, AFields, ADataFields, ADataBuilder.FilteredFields, AMembers);
        if AnExpandingItem.Field.Area = faColumn then
          CreateLayoutTotals(AnExpandingItem, ADataBuilder.Rows, ADataFields, AMembers)
        else
          CreateLayoutTotals(AnExpandingItem, ADataBuilder.Columns, ADataFields, AMembers);

        for I := 0 to ADataFields.Count - 1 do
          if (TcxPivotGridOLAPField(ADataFields[I]).FieldType = oftKPI) and
            QueryKPITotals(AExpandedFields, ADataBuilder.FilteredFields,
            TcxPivotGridOLAPField(ADataFields[I]), TcxPivotGridOLAPField(ADataFields[I]).KPIType, AMembers) then
          begin
            if AnExpandingItem.Field.Area = faColumn then
              InitializeKPITotals(AnExpandingItem, ADataBuilder.Rows, ADataFields, oftKPI, I)
            else
              InitializeKPITotals(AnExpandingItem, ADataBuilder.Columns, ADataFields, oftKPI, I);
          end;
      finally
        AExpandedFields.Free;
      end;

    finally
      AFields.Free;
    end;
  finally
    AMembers.Free;
  end;
end;

procedure TcxPivotGridOLAPDataSource.InitializeLayoutKPI(ARowFields, AColumnFields, ADataFields,
  AFilterFields: TcxPivotGridFields; ARowsGroup, AColumnsGroup: TcxPivotGridGroupItem);
var
  I, APreviousGroupIndex: Integer;
  AField: TcxPivotGridOLAPField;
  AGroup: TcxPivotGridFieldGroup;
  ARowField: TcxPivotGridField;
begin
  AGroup := nil;
  APreviousGroupIndex := -1;
  for I := 0 to ADataFields.Count - 1 do
    if TcxPivotGridOLAPField(ADataFields[I]).FieldType = oftKPI then
    begin
      AField := TcxPivotGridOLAPField(ADataFields[I]);
      if AField.GroupIndex <> APreviousGroupIndex then
        if AField.Visible then
          AGroup := AField.Group
        else
          AGroup := nil;
      APreviousGroupIndex := AField.GroupIndex;
      if (AGroup <> nil) and (AField.Group = AGroup) then
      begin
        if QueryKPILayout(AColumnFields, ARowFields, AFilterFields, AField, AField.KPIType) then
        begin
          ARowField := nil;
          if (ARowFields <> nil) and (ARowFields.Count > 0) then
            ARowField := ARowFields[0];
          InitializeCrossCellsKPI(ARowsGroup, AColumnsGroup, ARowField, ADataFields, oftKPI, I, 0);
        end;
        if QueryKPITotals(AColumnFields, AFilterFields, AField, AField.KPIType, nil) then
          InitializeKPITotals(AColumnsGroup, ARowsGroup, ADataFields, oftKPI, I);
        if QueryKPITotals(ARowFields, AFilterFields, AField, AField.KPIType, nil) then
          InitializeKPITotals(ARowsGroup, AColumnsGroup, ADataFields, oftKPI, I);
        if QueryKPITotal(AFilterFields, AColumnFields, ARowFields, AField, AField.KPIType) then
          InitializeKPITotal(ARowsGroup, AColumnsGroup, ADataFields, oftKPI, I);
      end;
    end;
end;

procedure TcxPivotGridOLAPDataSource.InitializeTotal(ADataFields, AFilterFields: TcxPivotGridFields;
  AColumns, ARows: TcxPivotGridGroupItem);
var
  AProcessedFieldCount: Integer;
begin
  ExecuteQuery(QueryBuilder.GetTotalQueryString(Cube, AFilterFields, ADataFields));

  if not IsDataValid then
    Exit;

  if GetDataFieldCount(ADataFields, oftMeasure) > 0 then
    with ADODataSet do
    begin
      First;
      ProcessDataFields(AColumns, ARows, ADataFields, 0, '', oftMeasure, AProcessedFieldCount);
      Close;
    end;
end;

procedure TcxPivotGridOLAPDataSource.CreateLayoutTotals(AColumns, ARows: TcxPivotGridGroupItem;
  ASummaryFields: TcxPivotGridFields; AnExpandedMembers: TList);

  function GetDimensionColumnIndex: Integer;

    procedure ErrorMessage;
    begin
      raise Exception.Create('Field not found');
    end;

  var
    I: Integer;
    AHierarchyName, AMeasureName: string;
  begin
    if (AnExpandedMembers = nil) or not IsNotLastVisibleOLAPHierarchyItem(TcxPivotGridGroupItem(AnExpandedMembers[0])) then
    begin
      Result := 0;
      if IsOLAPVersion8 then
        AMeasureName := ASummaryFields[0].UniqueName
      else
        AMeasureName := OLAPMemberUniqueNameColumnName;
      while (Result < ADODataSet.FieldCount) and (Pos(AMeasureName, ADODataSet.Fields[Result].DisplayName) = 0) do
      begin
        Inc(Result);
        if Result = ADODataSet.FieldCount then
          ErrorMessage;
      end;
    end
    else
    begin
      Result := -1;
      AHierarchyName := TcxPivotGridOLAPField(TcxPivotGridGroupItem(AnExpandedMembers[0]).Field).HierarchyUniqueName;
      for I := 0 to ADODataSet.FieldCount - 1 do
        if Pos(AHierarchyName, ADODataSet.Fields[I].DisplayName) > 0 then
          Result := I;
      if Result = -1 then
        ErrorMessage;
    end;
  end;

var
  AColumn, ARow: TcxPivotGridGroupItem;
  AColumnIndex, AColumnFieldIndexInDataSet, AFirstDataFieldIndexInDataSet: Integer;
  ADimension: string;
begin
  if not IsDataValid or (ASummaryFields.Count = 0) or (AColumns.ItemCount = 0) then
    Exit;

  AColumn := nil;
  if GetDataFieldCount(ASummaryFields, oftMeasure) > 0 then
  begin
    AColumnFieldIndexInDataSet := GetDimensionColumnIndex;
    AFirstDataFieldIndexInDataSet := GetFieldIndex(TcxPivotGridField(ASummaryFields.Items[0]), 0);
    ARow := ARows;
    ADODataSet.First;
    AColumnIndex := -1;
    while not ADODataSet.Eof do
    begin
      ADimension := ADODataSet.Fields[AColumnFieldIndexInDataSet].Value;
      repeat
        Inc(AColumnIndex);
        if AColumnIndex < AColumns.ItemCount then
          AColumn := AColumns.Items[AColumnIndex];
      until (Pos(AColumn.UniqueName, ADimension) > 0) or (AColumnIndex >= AColumns.ItemCount);
      if AColumnIndex < AColumns.ItemCount then
        ProcessDataFieldsEx(AColumn, ARow, ASummaryFields, ADODataSet.RecNo, AFirstDataFieldIndexInDataSet, oftMeasure)
      else
        AColumnIndex := -1;
      ADODataSet.Next;
    end;
    ADODataSet.Close;
  end;
end;

function TcxPivotGridOLAPDataSource.IsValueVisible(
  AFilter: TcxPivotGridFieldFilter; const AValue: WideString): Boolean;
begin
  Result := not AFilter.HasFilter or AFilter.Contains(AValue);
end;

type
  TVariantListAccess = class(TcxPivotGridVariantList);

procedure TcxPivotGridOLAPDataSource.InitializeStructureMembers(
  AField: TcxPivotGridOLAPField; AList: TcxPivotGridVariantList);
var
  AValue: TcxPivotGridVariantValue;
  AMemberFieldCaption, AMemberField, AMemberUniqueName: TField;
  AQueryBuilder: TcxOLAPDataQueryBuilder;
begin
  TVariantListAccess(AList).FItems.Clear;
  AQueryBuilder := TcxOLAPDataQueryBuilder.Create(Version);
  try
    if not ExecuteQuery(AQueryBuilder.GetMembersQueryString(Cube, AField, nil, nil, nil)) then Exit;
  finally
    AQueryBuilder.Free;
  end;
  AMemberField := ADODataSet.FieldByName(OLAPMemberNameColumnName);
  AMemberFieldCaption := ADODataSet.Fields[0];
  AMemberUniqueName := ADODataSet.FieldByName(OLAPMemberUniqueNameColumnName);
  ADODataSet.DisableControls;
  try
    TVariantListAccess(AList).FItems.Capacity := AField.Structure.Cardinality;
    while (AMemberField <> nil) and not ADODataSet.Eof do
    begin
      if not VarIsNull(AMemberUniqueName.Value) then
      begin
        if VarIsNull(AMemberField.AsString) then
          AValue := TcxPivotGridVariantValue.Create(AMemberFieldCaption.AsString)
        else
          AValue := TcxPivotGridVariantValue.Create(AMemberField.AsString);
        AValue.UniqueName := AMemberUniqueName.Value;
        TVariantListAccess(AList).FItems.Add(AValue);
      end;
      ADODataSet.Next;
    end;
    TVariantListAccess(AList).Changed;
    TVariantListAccess(AList).FSorted := True;
  finally
    ADODataSet.EnableControls;
  end;
end;

procedure TcxPivotGridOLAPDataSource.Loaded;
begin
  inherited Loaded;
  NotifyListeners;
end;

procedure TcxPivotGridOLAPDataSource.PopulateFilteredUniqueNames(AField: TcxPivotGridOLAPField;
  AFilter: TcxPivotGridFieldFilter; var AUniqueValues: TStringList);

  function GetParentUniqueName(const AUniqueName: string): string;
  begin
    ExecuteQuery(QueryBuilder.GetParentQueryString(Cube, TcxPivotGridOLAPField(AField), AUniqueName));
    Result := ADODataSet.FieldByName(OLAPPArentUniqueNameColumnName).AsString;
  end;

var
  I: Integer;
  AValues: TStringList;
  AUniqueName: string;
begin
  if not AFilter.HasFilter and (AUniqueValues = nil) then Exit;

  if AUniqueValues <> nil then
    AUniqueValues.Sort;
  AValues := TStringList.Create;
  try
    for I := 0 to AField.GroupValueList.Count - 1 do
    begin
      AUniqueName := AField.GroupValueList.Items[I].UniqueName;
      if IsValueVisible(AFilter, AField.GroupValueList.Items[I].Value) and
        ((AUniqueValues = nil) or (AUniqueValues.IndexOf(AUniqueName) <> -1)) then
        AValues.Add(GetParentUniqueName(AUniqueName));
    end;
    FreeAndNil(AUniqueValues);
  finally
    AUniqueValues := AValues;
  end;
end;

procedure TcxPivotGridOLAPDataSource.PopulateFilteredValues(
  AField: TcxPivotGridOLAPField; AFilter: TcxPivotGridFieldFilter;
  AValues: TStrings; AUniqueValues: TStringList);
var
  I: Integer;
  AUniqueName: string;
begin
  if AUniqueValues <> nil then
    AUniqueValues.Sort;
  for I := 0 to AField.GroupValueList.Count - 1 do
  begin
    AUniqueName := AField.GroupValueList.Items[I].UniqueName;
    if IsValueVisible(AFilter, AField.GroupValueList.Items[I].Value) and
      ((AUniqueValues = nil) or (AUniqueValues.IndexOf(AUniqueName) <> -1)) then
      AValues.Add(AUniqueName);
  end;
end;

procedure TcxPivotGridOLAPDataSource.ProcessColumns(AColumnsGroup: TcxPivotGridGroupItem;
  ARow: TcxPivotGridGroupItem; AFieldIndex: Integer);
var
  I, AColumnIndex: Integer;
  ADimension: string;
  AColumn: TcxPivotGridGroupItem;
begin
  with ADODataSet do
  begin
    I := 0;
    while I < FieldCount do
    begin
      ADimension := Fields[I].DisplayName;
      AColumnIndex := -1;
      AColumn := nil;
      begin
        repeat
          Inc(AColumnIndex);
          if AColumnIndex < AColumnsGroup.ItemCount then
            AColumn := AColumnsGroup.Items[AColumnIndex];
        until (Pos(AColumn.UniqueName, ADimension) > 0) or (AColumnIndex >= AColumnsGroup.ItemCount);
        if AColumnIndex < AColumnsGroup.ItemCount then
          ProcessDataField(AColumn, ARow, I, AFieldIndex);
        Inc(I);
      end;
    end;
  end;
end;

procedure TcxPivotGridOLAPDataSource.ProcessDataField(AColumn, ARow: TcxPivotGridGroupItem;
  AFieldIndex, ASummaryFieldIndex: Integer);
var
  AValue, ANativeValue: Variant;
begin
  AValue := Null;
  ANativeValue := Null;
  AValue := ADODataset.Fields[AFieldIndex].Value;
  ANativeValue := AValue;
  if VarIsEmpty(AValue) then
    AValue := Null;

  InitializeCrossCellKPIValue(ARow.GetCellByCrossItem(AColumn), ASummaryFieldIndex, AValue, ANativeValue);
end;

procedure TcxPivotGridOLAPDataSource.ProcessDataFields(AColumn, ARow: TcxPivotGridGroupItem;
  ADataFields: TcxPivotGridFields; AFieldIndex: Integer; const AFieldDimension: string;
  AOLAPType: TcxPivotGridOLAPFieldType; out AProcessedFieldCount: Integer);
var
  ADataFieldIndex: Integer;
  AIsValuesInitialized: Boolean;
  AValues, ANativeValues: Variant;
  ADimension, AMeasure: string;
begin
  AValues := VarArrayCreate([0, ADataFields.Count - 1], varVariant);
  ANativeValues := VarArrayCreate([0, ADataFields.Count - 1], varVariant);
  AProcessedFieldCount := 0;
  AIsValuesInitialized := False;
  for ADataFieldIndex := 0 to ADataFields.Count - 1 do
    if TcxPivotGridOLAPField(ADataFields[ADataFieldIndex]).FieldType = AOLAPType then
    begin
      AValues[ADataFieldIndex] := Null;
      ANativeValues[ADataFieldIndex] := Null;
      if AFieldIndex + AProcessedFieldCount < ADODataset.FieldCount then //OLAP v.8 problem
        if SeparateDimensionAndMeasure(ADODataset.Fields[AFieldIndex + AProcessedFieldCount].DisplayName, ADimension, AMeasure) and
          ((AFieldDimension = '') or (AFieldDimension = ADimension)) and (ADataFields[ADataFieldIndex].UniqueName = AMeasure) then
        begin
          AValues[ADataFieldIndex] := ADODataset.Fields[AFieldIndex + AProcessedFieldCount].Value;
          Inc(AProcessedFieldCount);
        end
        else
          AValues[ADataFieldIndex] := Null;
      ANativeValues[ADataFieldIndex] := AValues[ADataFieldIndex];
      AIsValuesInitialized := False;
      if VarIsEmpty(AValues[ADataFieldIndex]) then
        AValues[ADataFieldIndex] := Null
      else
        AIsValuesInitialized := True;
    end;

  if AIsValuesInitialized then
    InitializeCrossCellValues(ARow.GetCellByCrossItem(AColumn), AValues, ANativeValues, AIsValuesInitialized)
  else
    InitializeCrossCellValues(ARow.GetCellByCrossItem(AColumn), Null, Null, AIsValuesInitialized);
end;

procedure TcxPivotGridOLAPDataSource.ProcessDataFieldsEx(AColumn, ARow: TcxPivotGridGroupItem; ADataFields: TcxPivotGridFields;
  ARecordIndex, AStartColumnIndex: Integer; AOLAPType: TcxPivotGridOLAPFieldType);
var
  ADataFieldIndex, ADatasetFieldIndex: Integer;
  AIsValuesInitialized, AFieldFound: Boolean;
  AValues, ANativeValues: Variant;
begin
  AValues := VarArrayCreate([0, ADataFields.Count - 1], varVariant);
  ANativeValues := VarArrayCreate([0, ADataFields.Count - 1], varVariant);
  AIsValuesInitialized := False;
  for ADataFieldIndex := 0 to ADataFields.Count - 1 do
    if TcxPivotGridOLAPField(ADataFields[ADataFieldIndex]).FieldType = AOLAPType then
    begin
      AValues[ADataFieldIndex] := Null;
      ANativeValues[ADataFieldIndex] := Null;
      ADatasetFieldIndex := AStartColumnIndex + ADataFieldIndex;
      AFieldFound := False;
      while (ADatasetFieldIndex < ADODataset.FieldCount) and not AFieldFound do
        if ADataFields[ADataFieldIndex].UniqueName = ADODataset.Fields[ADatasetFieldIndex].DisplayName then
        begin
          AFieldFound := True;
          AValues[ADataFieldIndex] := ADODataset.Fields[ADatasetFieldIndex].Value;
        end;
      ANativeValues[ADataFieldIndex] := AValues[ADataFieldIndex];
      AIsValuesInitialized := False;
      if VarIsEmpty(AValues[ADataFieldIndex]) then
        AValues[ADataFieldIndex] := Null
      else
        AIsValuesInitialized := True;
    end;

  if AIsValuesInitialized then
    InitializeCrossCellValues(ARow.GetCellByCrossItem(AColumn), AValues, ANativeValues, AIsValuesInitialized)
  else
    InitializeCrossCellValues(ARow.GetCellByCrossItem(AColumn), Null, Null, AIsValuesInitialized);
end;

procedure TcxPivotGridOLAPDataSource.QueryLayout(
  ARowFields, AColumnFields, ADataFields, AFilterFields: TcxPivotGridFields);
begin
  ExecuteQuery(QueryBuilder.GetQueryString(Cube, AColumnFields,
    ARowFields, ADataFields, AFilterFields));
end;

procedure TcxPivotGridOLAPDataSource.QueryLayoutTotals(AColumnFields, ARowFields,
  ADataFields, AFilterFields: TcxPivotGridFields; AnExpandedMembers: TList);
begin
  ExecuteQuery(QueryBuilder.GetTotalsQueryString(Cube, AColumnFields, ARowFields,
    AnExpandedMembers, ADataFields, AFilterFields));
end;

procedure TcxPivotGridOLAPDataSource.QueryKPIExpandCrossCells(ADataBuilder: TcxPivotGridDataBuilder; AMembers: TList;
  AFields: TcxPivotGridFields; ADataFields: TcxPivotGridFields; ADataFieldIndex: Integer);
var
  ADataField: TcxPivotGridOLAPField;
  ANewMembers: TList;
  I, ALastMember: Integer;
  AFilterMembers: TList;
  Result: Boolean;
begin
  ADataField := TcxPivotGridOLAPField(ADataFields[ADataFieldIndex]);
  Result := ExecuteQuery(QueryBuilder.GetExpandQueryString(Cube,
    AMembers, AFields, ADataFields, ADataBuilder.FilteredFields,
    oftKPI, ADataField.KPIType, ADataField.Structure.KPIName));
  if not Result then
  begin
    ALastMember := AMembers.Count - 1;
    ANewMembers := TList.Create;
    AFilterMembers := TList.Create;
    try
      AFilterMembers.Add(AMembers[ALastMember]);
      for I := 0 to AMembers.Count - 2 do
        ANewMembers.Add(AMembers[I]);
      ExecuteQuery(QueryBuilder.GetExpandQueryString(Cube, ANewMembers, AFields, ADataFields,
        ADataBuilder.FilteredFields, oftKPI, ADataField.KPIType, ADataField.Structure.KPIName, AFilterMembers));
    finally
      AFilterMembers.Free;
      ANewMembers.Free;
    end;
  end;
end;

function TcxPivotGridOLAPDataSource.QueryKPILayout(AColumnFields, ARowFields,
  AFilterFields: TcxPivotGridFields; ADataField: TcxPivotGridOLAPField; AOLAPType: TcxOLAPKPIType): Boolean;
begin
  Result := ExecuteQuery(QueryBuilder.GetKPIQueryString(Cube, AColumnFields, ARowFields,
    AFilterFields, AOLAPType, ADataField.Structure.KPIName));
end;

function TcxPivotGridOLAPDataSource.QueryKPITotal(AFilterFields: TcxPivotGridFields;
  AColumnFields, ARowFields: TcxPivotGridFields; ADataField: TcxPivotGridOLAPField; AKPIType: TcxOLAPKPIType): Boolean;
begin
  Result := ExecuteQuery(QueryBuilder.GetKPITotalQueryString(Cube, AColumnFields,
    ARowFields, AFilterFields, AKPIType, ADataField.Structure.KPIName));
end;

function TcxPivotGridOLAPDataSource.QueryKPITotals(AColumnFields, AFilterFields: TcxPivotGridFields;
  ADataField: TcxPivotGridOLAPField; AKPIType: TcxOLAPKPIType; AnExpandedMembers: TList): Boolean;
begin
  Result := ExecuteQuery(QueryBuilder.GetKPITotalsQueryString(Cube, AColumnFields,
    AFilterFields, AnExpandedMembers, AKPIType, ADataField.Structure.KPIName));
end;

procedure TcxPivotGridOLAPDataSource.QueryRootMembers(AField: TcxPivotGridField; AParentMembers: TList;
  AFilters: TcxPivotGridFields; ADataFields: TcxPivotGridFields);
begin
  ExecuteQuery(QueryBuilder.GetMembersQueryString(Cube, TcxPivotGridOLAPField(AField), AParentMembers, AFilters, ADataFields));
end;

function TcxPivotGridOLAPDataSource.SeparateDimensionAndMeasure(AValue: string; out ADimension, AMeasure: string): Boolean;
var
  APosition: Integer;
begin
  Result := False;
  APosition := Pos('[Measures]', AValue);
  if APosition > 0 then
  begin
    ADimension := Copy(AValue, 1, APosition - 2);
    AMeasure := Copy(AValue, APosition, Length(AValue) - APosition + 1);
    Result := True;
  end;
end;

procedure TcxPivotGridOLAPDataSource.TerminateConnection;
begin
  if Connection = nil then Exit;
  FTerminated := Connection.Connected;
  if FTerminated then
  begin
    Connection.Close;
    Connection.ConnectionObject := nil;
  end;
end;

procedure TcxPivotGridOLAPDataSource.CreateQueryBuilder;
begin
  if QueryBuilder = nil then
    QueryBuilder := TcxOLAPDataQueryBuilder.Create(Version)
  else
    QueryBuilder.Version := Version;
end;

procedure TcxPivotGridOLAPDataSource.ExpandedItemWithParentsToList(
  AnItems: TList; AList: TList; AWithParents: Boolean = True);
var
  I: Integer;
begin
  for I := 0 to AnItems.Count - 1 do
  begin
    ExpandedItemWithParentsToList(TcxPivotGridGroupItem(AnItems[I]), AList, AWithParents);
  end;
end;

procedure TcxPivotGridOLAPDataSource.ExpandedItemWithParentsToList(AnItem: TcxPivotGridGroupItem; AList: TList;
  AWithParents: Boolean = True);
var
  APreviousItem: TcxPivotGridGroupItem;
begin
  APreviousItem := nil;
  while AnItem.UniqueName <> '' do
  begin
    if (APreviousItem = nil) or (AnItem.Field.Group = nil) or
      (APreviousItem.Field.Group <> AnItem.Field.Group) then
      AList.Add(AnItem);
    APreviousItem := AnItem;
    AnItem := AnItem.Parent;
    if not AWithParents then
      Break;
  end;
end;

function TcxPivotGridOLAPDataSource.ExtractMemberName(AFullName: string): string;
const
  StartSign = '.[';
  EndSign = ']';
var
  AStart, AEnd: Integer;
begin
  Result := '';
  AStart := Pos(StartSign, AFullName);
  while PosEx(StartSign, AFullName, AStart + 1) > 0 do
    AStart := PosEx(StartSign, AFullName, AStart + 1);

  if AStart > 0 then
  begin
    AEnd := PosEx(EndSign, AFullName, AStart);
    Result := Copy(AFullName, AStart + 2, AEnd - AStart - 2);
  end;
end;

function TcxPivotGridOLAPDataSource.GetActive: Boolean;
begin
  Result := IsActive;
end;

function TcxPivotGridOLAPDataSource.GetDrillDownCommandText(ACell: TcxPivotGridCrossCell;
  AFieldList: TcxObjectList; ASummaryIndex: Integer): string;

  function ReturnDefaultFields: Boolean;
  const
    DataSourceStr = ';Data Source=';
  var
    AConnectionString: string;
    APos: Integer;
  begin
    Result := False;
    AConnectionString := ConnectionString;
    APos := Pos(DataSourceStr, AConnectionString);
    if APos <> 0 then
    begin
      Delete(AConnectionString, 1, APos + Length(DataSourceStr) - 1);
      APos := Pos(';', AConnectionString);
      if APos <> 0 then
        AConnectionString := Copy(AConnectionString, 1, APos);
      Result := (Pos(':\', AConnectionString) <> 0) or
        (Pos('\\', AConnectionString) <> 0);
    end;
  end;

begin
  Result := QueryBuilder.GetDrillDownQueryString(Cube, ACell, AFieldList, ASummaryIndex,
    ReturnDefaultFields);
end;

function TcxPivotGridOLAPDataSource.GetConnectionString: WideString;
begin
  Result := FConnectionString;
  if Result = '' then
    Result := FConnection.ConnectionString;
end;

function TcxPivotGridOLAPDataSource.GetDataFieldCount(ADataFields: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType): Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to ADataFields.Count - 1 do
    if TcxPivotGridOLAPField(ADataFields[I]).FieldType = AOLAPType then
      Inc(Result);
end;

function TcxPivotGridOLAPDataSource.IsDataValid: Boolean;
begin
  Result := ADODataSet.Active and (ADODataSet.RecordCount > 0) and
    (ADODataSet.FieldCount > 0);
end;

function TcxPivotGridOLAPDataSource.IsOLAPVersion8: Boolean;
begin
  Result := Version <= 8;
end;

procedure TcxPivotGridOLAPDataSource.SetActive(AValue: Boolean);
begin
  if ConnectionString = '' then Exit;
  try
    if AValue and CacheLocalCubes then
      CreateTemporaryCube; 
    try
      if not AValue then
      begin
        TerminateConnection;
        FTerminated := False;
      end;
      FConnection.Connected := AValue;
    except
      AValue := False;
      raise;
    end;
  finally
    inherited Active := AValue;
    if not Active then
      DeleteCachedFile;
  end;
end;

procedure TcxPivotGridOLAPDataSource.SetConnectionString(const AValue: WideString);
begin
  Active := False;
  FConnectionString := '';
  FConnection.ConnectionString := AValue;
end;

procedure TcxPivotGridOLAPDataSource.SetCube(const AValue: string);
begin
  FCube := AValue;
  if Active and not (csLoading in ComponentState) then
    Changed;
  FIsCubeNameAssigned := FCube <> '';
end;

end.

