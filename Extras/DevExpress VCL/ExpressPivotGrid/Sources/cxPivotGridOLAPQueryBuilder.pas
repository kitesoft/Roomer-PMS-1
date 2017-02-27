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

unit cxPivotGridOLAPQueryBuilder;

{$I cxVer.inc}

interface

uses
  Classes, SysUtils, dxCore, cxClasses, cxCustomPivotGrid;

type

  TcxOLAPStructureMembersType = (smtAll, smtItem, smtChildren);

  { TdxOLAPDataQueryBuilder }

  TcxOLAPDataQueryBuilder = class
  protected
    FAxisIndex: Integer;
    FFilters: TcxPivotGridFields;
    FVersion: Integer;

    procedure ClearAxisIndex;
    function CreateFilterAggregates(AFilters: TcxPivotGridFields): string;
    function CreateFilterAggregate(AField: TcxPivotGridOLAPField): string;
    function CreateFilterWhereClause(AFilters: TcxPivotGridFields; AAdditionalCondition: string): string;
    procedure ExcludeExpandingMembersFormFilters(AnExpandedMembers: TList; AFilters: TcxPivotGridFields);
    procedure ExcludeField(AFilters: TcxPivotGridFields; AField: TcxPivotGridOLAPField);
    function GetAxis: string;
    function GetCountInArea(AFields: TcxPivotGridFields; AArea: TcxPivotGridFieldArea): Integer;
    function GetExpandedMembers(AnExpandedMembers: TList; AClearMember: Boolean = False): string;
    function GetFilterSetupString(AFilters: TcxPivotGridFields): string;
    function GetFilterString(AFilter: TcxPivotGridOLAPField): string;
    function GetMeasures(AMeasures: TcxPivotGridFields; const AAdditionalString: string = ''): string;
    function GetMember(AField: TcxPivotGridOLAPField; const AType: string): string;
    function GetMemberName(AField: TcxPivotGridOLAPField; const AType: string): string;
    function GetMembers(AFilter: TStrings): string;
    function GetNamedSetName(AField: TcxPivotGridOLAPField): string;
    function GetNamedSets(AnExpandedMembers: TList): TList;
    function GetNamedSetsQuery(ANamedSets: TList): string;
    function GetSortOrder(AField: TcxPivotGridOLAPField): string;
    function GetTuple(ATuple: TcxPivotGridGroupItem;
      IncludeLastMember: Boolean = True; MembersCount: Integer = 0): string;
    function IsHierarchy(AField: TcxPivotGridOLAPField;
      AParentField: TcxPivotGridOLAPField): Boolean;
    function IsFiltered(AField: TcxPivotGridOLAPField): Boolean;
    function IsOLAPVersion8: Boolean;
    function IsStrongRelationshipBetweenFilterAndDimensions(AFilters: TcxPivotGridFields): Boolean;
    function IsMultipleFilteredValues(AField: TcxPivotGridOLAPField): Boolean;
    function WriteAllMembers(AField: TcxPivotGridOLAPField;
      IncludeCalculatedMembers: Boolean): string;
    function WriteAllMembersWithSorting(AField: TcxPivotGridOLAPField;
      IncludeCalculatedMembers, IncludeTotal: Boolean): string;
    function WriteAllMembersCore(AField: TcxPivotGridOLAPField;
      IncludeCalculatedMembers, ExcludeTotal: Boolean; AFilter: Boolean = True): string;
    function WriteSortedMembers(AField: TcxPivotGridOLAPField;
      const AContent: string): string;

    //query parts
    function FilterPart(AColumns: TcxPivotGridFields; ARows: TcxPivotGridFields; AFilters, AGlobalFilters: TcxPivotGridFields): string;
    function FilterPartForTotals(AColumns: TcxPivotGridFields; AnExpandedMembers: TList; AFilters, AGlobalFilters: TcxPivotGridFields): string;
    function ColumnPartVersion8(const ACubeName: string; AColumns: TcxPivotGridFields;
      AMeasures: TcxPivotGridFields; IncludeCalculatedMembers, IncludeTotals: Boolean; const AAdditionalString: string = ''): string;
    function ColumnPart(const ACubeName: string; AColumns: TcxPivotGridFields;
      AMeasures: TcxPivotGridFields; IncludeCalculatedMembers, IncludeTotals, AddWith: Boolean; const AAdditionalString: string = ''): string;
    function SourcePart(const ACubeName: string; AFilters: TcxPivotGridFields; ANamedSets: TList; const AAdditionalCondition: string = ''): string;
    function SourcePartWithWhereCondition(const ACubeName: string; AFilters: TcxPivotGridFields; ANamedSets: TList; const AAdditionalCondition: string = ''): string;
    function SourcePartWithSubSelect(const ACubeName: string; AFilters: TcxPivotGridFields;
      ANamedSets: TList; const AAdditionalCondition: string = ''): string;

    procedure TrimTrailingComma(var AStr: string);
    procedure TrimTrailingSequence(var AStr: string; const ASequence: string);

    function GetSortBy(AField: TcxPivotGridOLAPField): string;
  public
    constructor Create(AVersion: Integer);
    function GetDrillDownQueryString(const ACubeName: string;
      ACrossCell: TcxPivotGridCrossCell; AFieldList: TcxObjectList;
      ASummaryIndex: Integer; ReturnDefaultFields: Boolean): string;
    function GetExpandQueryString(const ACubeName: string;
      AnExpandedMembers: TList; AFields, AMeasures: TcxPivotGridFields;
      AFilters: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType;
      AKPIType: TcxOLAPKPIType = oktValue; const AKPIName: string = ''; AFilterMembers: TList = nil): string;
    function GetKPIQueryString(const ACubeName: string; AColumns: TcxPivotGridFields;
      ARows: TcxPivotGridFields; AFilters: TcxPivotGridFields; AKPIType: TcxOLAPKPIType; const AKPIName: string): string;
    function GetKPITotalQueryString(const ACubeName: string; AColumns, ARows: TcxPivotGridFields;
      AFilters: TcxPivotGridFields; AKPIType: TcxOLAPKPIType; const AKPIName: string): string;
    function GetKPITotalsQueryString(const ACubeName: string; AColumns, AFilters: TcxPivotGridFields;
      AnExpandedMembers: TList; AKPIType: TcxOLAPKPIType; const AKPIName: string): string;
    function GetMeasuresCount(AMeasures: TcxPivotGridFields; AFieldType: TcxPivotGridOLAPFieldType): Integer;
    function GetMembersQueryString(const ACubeName: string;
      AField: TcxPivotGridOLAPField; AnExpandedMembers: TList; AFilters: TcxPivotGridFields; AMeasures: TcxPivotGridFields): string;
    function GetParentQueryString(const ACubeName: string; AField: TcxPivotGridOLAPField; const AMemberUniqueName: string): string;
    function GetQueryString(const ACubeName: string; AColumns: TcxPivotGridFields;
      ARows: TcxPivotGridFields; AMeasures: TcxPivotGridFields; AFilters: TcxPivotGridFields): string;
    function GetTotalQueryString(const ACubeName: string; AFilters: TcxPivotGridFields; AMeasures: TcxPivotGridFields): string;
    function GetTotalsQueryString(const ACubeName: string; AColumns, ARowFilters: TcxPivotGridFields;
      AnExpandedMembers: TList; AMeasures: TcxPivotGridFields; AFilters: TcxPivotGridFields): string;

    property Version: Integer read FVersion write FVersion;
  end;

implementation

uses
  cxCustomData, cxPivotGridStrs;

type
  TcxPivotGridOLAPFieldOptionsAccess = class(TcxPivotGridOLAPFieldOptions);

const
  Comma = ', ';
  CrossJoinOperator = ' * ';

  KPITypeMap: array[TcxOLAPKPIType] of string = ('KPIValue', 'KPIGoal', 'KPIStatus', 'KPITrend', 'KPIWeight');

{ TdxOLAPDataQueryBuilder }

constructor TcxOLAPDataQueryBuilder.Create(AVersion: Integer);
begin
  inherited Create;
  FVersion := AVersion;
end;

function TcxOLAPDataQueryBuilder.GetDrillDownQueryString(const ACubeName: string;
  ACrossCell: TcxPivotGridCrossCell; AFieldList: TcxObjectList; ASummaryIndex: Integer;
  ReturnDefaultFields: Boolean): string;

  {function GetDimensionList(AFieldList: TcxObjectList): string;
  var
    AField: TcxPivotGridOLAPField;
    AFieldDimension: string;
    I: Integer;
  begin
    Result := '';
    for I := 0 to AFieldList.Count - 1 do
    begin
      AField := TcxPivotGridOLAPField(AFieldList.List[I]);
      AFieldDimension := AField.DimensionUniqueName;
      Insert('$', AFieldDimension, 2);
      Result := Result + AFieldDimension + '.[' + AField.Caption + '], ';
    end;
    TrimTrailingComma(Result);
  end;}

var
  AMeasure: TcxPivotGridOLAPField;
  ATempColumnTuple, ATempRowTuple, AColumnTuple, ARowTuple: string;
begin
  ClearAxisIndex;

  Result := '';
  if ACrossCell = nil then
    Exit;
  AMeasure := ACrossCell.SummaryCells[ASummaryIndex].DataField as TcxPivotGridOLAPField;
  if (AMeasure = nil) or (ACubeName = '') then
    Exit;
  Result := 'drillthrough select non empty ';

  AColumnTuple := GetTuple(ACrossCell.Column);
  ARowTuple := GetTuple(ACrossCell.Row);

  case FVersion of
  7, 8:
    begin
      ATempColumnTuple := AColumnTuple;
      ATempRowTuple := ARowTuple;
      if (ATempColumnTuple = '') and (ATempRowTuple <> '') then
      begin
        ATempColumnTuple := ATempRowTuple;
        ATempRowTuple := '';
      end;
      Result := Result + '{ ' + ATempColumnTuple + ' }' + GetAxis;
      if ATempRowTuple <> '' then
        Result := Result + ', { ' + ATempRowTuple + ' }' + GetAxis;
      Result := Result + 'from [' + ACubeName + '] ';
    end;
  else
    begin
      if AColumnTuple <> '' then
        Result := Result + '{ { ' + AColumnTuple + ' } } * ';
      Result := Result + '{ ' + AMeasure.UniqueName + ' }' + GetAxis;
      if ARowTuple <> '' then
        Result := Result + ', { { ' + ARowTuple + ' } }' + GetAxis;
      Result := Result + 'from [' + ACubeName + '] ';
    end;
  end;
  {if not ReturnDefaultFields then
    Result := Result + 'return ' + GetDimensionList(AFieldList);}
end;

function TcxOLAPDataQueryBuilder.GetExpandQueryString(const ACubeName: string;
  AnExpandedMembers: TList; AFields, AMeasures: TcxPivotGridFields;
  AFilters: TcxPivotGridFields; AOLAPType: TcxPivotGridOLAPFieldType;
  AKPIType: TcxOLAPKPIType = oktValue; const AKPIName: string = ''; AFilterMembers: TList = nil): string;

  function GetField(AIndex: Integer): string;
  var
    ALevelUniqueName: string;
  begin
    ALevelUniqueName := TcxPivotGridOLAPField(AFields[AIndex]).LevelUniqueName;
    if TcxPivotGridOLAPField(AFields[AIndex]).IsHierarchy and (TcxPivotGridOLAPField(AFields[AIndex]).LevelNumber > 1) then
      ALevelUniqueName := GetOLAPHierarchyLevelUniqueName(TcxPivotGridOLAPField(AFields[AIndex]));
    Result := '{' + WriteSortedMembers(TcxPivotGridOLAPField(AFields[AIndex]),
      ALevelUniqueName + '.allmembers') + '}';
  end;

  function GetFilterAggregate(AMember: TcxPivotGridGroupItem; out AName: string): string;
  begin
    AName := GetMemberName(TcxPivotGridOLAPField(AMember.Field), scxOLAPFilterCaption);
    Result := GetMember(TcxPivotGridOLAPField(AMember.Field), scxOLAPFilterCaption) + '''aggregate(existing{' + AMember.UniqueName + '})'' ';
  end;

  function GetFilterAggregates(out ANames: string): string;
  var
    I: Integer;
    AName: string;
  begin
    Result := '';
    if AFilterMembers.Count > 0 then
      Result := 'with ';
    ANames := '';
    for I := 0 to AFilterMembers.Count - 1 do
    begin
      Result := Result + GetFilterAggregate(TcxPivotGridGroupItem(AFilterMembers[I]), AName);
      ANames := ANames + AName + ', ';
    end;
    TrimTrailingComma(ANames);
  end;

  function GetFields: string;
  var
    I: Integer;
  begin
    Result := '';
    if (AFields <> nil) and (AFields.Count > 0) then
    begin
      for I := 0 to AFields.Count - 1 do
        Result := Result + GetField(I) + '*';
      Delete(Result, Length(Result), 1);
    end;
  end;

  function GetFieldsOLAP8: string;
  var
    I: Integer;
  begin
    Result := '';
    if (AFields <> nil) and (AFields.Count > 0) then
    begin
      I := 0;
      Result := Result + '{' + WriteSortedMembers(TcxPivotGridOLAPField(AFields[I]),
        TcxPivotGridOLAPField(AFields[I]).LevelUniqueName + '.allmembers') + '}*';
      Delete(Result, Length(Result), 1);
    end;
  end;

  function GetCrossJoin: string;
  const
    ARows = 'Rows, ';
    AColumns = 'Columns ';
  var
    AIsHierarchyExpanding: Boolean;
    AColumnPart, ATempPart: string;
  begin
    AIsHierarchyExpanding := IsNotLastVisibleOLAPHierarchyItem(TcxPivotGridGroupItem(AnExpandedMembers[0]));
    if IsOLAPVersion8 then
      Result := GetFieldsOLAP8 + ' on Rows, crossjoin(' + GetExpandedMembers(AnExpandedMembers) + ', ' + GetMeasures(AMeasures) + ') on Columns '
    else
    begin
      AColumnPart := '';
      if AIsHierarchyExpanding then
      begin
        if AOLAPType = oftKPI then
        begin
          Result := GetExpandedMembers(AnExpandedMembers) + 'dimension properties member_unique_name on ' + ARows;
          AColumnPart := GetField(0);
        end
        else
        begin
          Result := GetExpandedMembers(AnExpandedMembers);
          ATempPart := GetFields;
          if ATempPart <> '' then
            Result := Result + CrossJoinOperator + ATempPart;
          Result := Result + 'dimension properties member_unique_name on ' + ARows;
        end;
      end
      else
      begin
        if AOLAPType = oftKPI then
        begin
          Result := GetField(1) + 'dimension properties member_unique_name on ' + ARows;
          AColumnPart := GetField(0) + CrossJoinOperator + GetExpandedMembers(AnExpandedMembers, True);
        end
        else
        begin
          Result := GetFields + 'dimension properties member_unique_name on ' + ARows;
          AColumnPart := GetExpandedMembers(AnExpandedMembers, True);
        end;
      end;
      if (AOLAPType = oftMeasure) and (GetMeasuresCount(AMeasures, oftMeasure) > 0) then
      begin
        if not AIsHierarchyExpanding then
          AColumnPart := AColumnPart + CrossJoinOperator;
        AColumnPart := AColumnPart + GetMeasures(AMeasures);
      end;
      if AColumnPart <> '' then
        Result := Result + AColumnPart + ' on ' + AColumns
      else
      begin
        TrimTrailingSequence(Result, ARows);
        Result := Result + AColumns;
      end;
    end;
  end;

  function GetKPICondition: string;
  begin
    Result := '';
    if (AOLAPType <> oftKPI ) or (AKPIName = '') then
      Exit;
    Result := KPITypeMap[AKPIType] + '("' + AKPIName + '")';
  end;

  procedure AddNamedSets(ANamedSets: TList; AFields: TcxPivotGridFields);
  var
    I: Integer;
  begin
    for I := 0 to AFields.Count - 1 do
      if TcxPivotGridOLAPField(AFields[I]).FieldType = oftSet then
        ANamedSets.Add(AFields[I]);
  end;

var
  ANamedSets: TList;
  ACondition, AKPICondition: string;
begin
  Result := '';
  ClearAxisIndex;

  ANamedSets := GetNamedSets(AnExpandedMembers);
  try
    AddNamedSets(ANamedSets, AFields);
    ACondition := '';
    if (AFilterMembers <> nil) and (AFilterMembers.Count > 0) then
      Result := GetFilterAggregates(ACondition) + ' ';
    AKPICondition := GetKPICondition;
    if AKPICondition <> '' then
    begin
      if ACondition <> '' then
        ACondition := AKPICondition  + ', ' + ACondition
      else
        ACondition := AKPICondition;
    end;
    Result := Result + 'select non empty ' + GetCrossJoin + SourcePartWithSubSelect(ACubeName, AFilters, ANamedSets, ACondition);
  finally
    ANamedSets.Free;
  end;
end;

function TcxOLAPDataQueryBuilder.GetKPIQueryString(const ACubeName: string; AColumns: TcxPivotGridFields;
  ARows: TcxPivotGridFields; AFilters: TcxPivotGridFields; AKPIType: TcxOLAPKPIType; const AKPIName: string): string;
var
  AKPICondition: string;
begin
  ClearAxisIndex;

  Result := '';
  if (AKPIName = '') or (AColumns.Count = 0) then
    Exit;
  AKPICondition := KPITypeMap[AKPIType] + '("' + AKPIName + '")';

  if AFilters <> nil then
    FFilters := TcxPivotGridFields.Create
  else
    FFilters := nil;
  try
    Result := FilterPart(AColumns, ARows, AFilters, FFilters);
    Result := Result + ColumnPart(ACubeName, AColumns, nil, True, False, Result = '');
    if ARows.Count > 0 then
      Result := Result + ', non empty ' + WriteAllMembersWithSorting(TcxPivotGridOLAPField(ARows[0]), True, False) +
        'dimension properties member_unique_name' + GetAxis;
    Result := Result + SourcePart(ACubeName, FFilters, nil, AKPICondition);
  finally
    FreeAndNil(FFilters);
  end;
end;

function TcxOLAPDataQueryBuilder.GetKPITotalQueryString(const ACubeName: string; AColumns, ARows: TcxPivotGridFields;
  AFilters: TcxPivotGridFields; AKPIType: TcxOLAPKPIType; const AKPIName: string): string;

  function GetDimension(AField: TcxPivotGridOLAPField; AFilters: TcxPivotGridFields): string;
  begin
    if AField.IsFiltered then
    begin
      Result := GetFilterString(AField);
      ExcludeField(AFilters, AField);
    end
    else
      Result := AField.HierarchyUniqueName;
  end;

var
  AKPICondition: string;
  AColumnExists: Boolean;
begin
  ClearAxisIndex;

  Result := '';
  if AKPIName = '' then
    Exit;
  AKPICondition := KPITypeMap[AKPIType] + '("' + AKPIName + '")';
  if AFilters <> nil then
    FFilters := TcxPivotGridFields.Create
  else
    FFilters := nil;
  try
    if FFilters <> nil then
      FFilters.Assign(AFilters);

    if (AColumns.Count = 0) or (ARows.Count = 0) then
    begin
      Result := 'select {' + AKPICondition + '}' + GetAxis;
      AKPICondition := '';
    end
    else
    begin
      Result := CreateFilterAggregates(FFilters);
      if Result <> '' then
        Result := 'with ' + Result;

      Result := Result + 'select ';
      AColumnExists := False;
      if AColumns.Count > 0 then
      begin
        Result := Result + 'non empty {' +
          GetDimension(TcxPivotGridOLAPField(AColumns[0]), FFilters) + '}' + GetAxis;
        AColumnExists := True;
      end;
      if ARows.Count > 0 then
      begin
        if AColumnExists then
          Result := Result + ', ';
        Result := Result + 'non empty {' +
          GetDimension(TcxPivotGridOLAPField(ARows[0]), FFilters) + '} dimension properties member_unique_name' + GetAxis;
      end;
    end;
    Result := Result + ' ' + SourcePartWithWhereCondition(ACubeName, FFilters, nil, AKPICondition);
  finally
    FreeAndNil(FFilters);
  end;
end;

function TcxOLAPDataQueryBuilder.GetKPITotalsQueryString(const ACubeName: string; AColumns, AFilters: TcxPivotGridFields;
  AnExpandedMembers: TList; AKPIType: TcxOLAPKPIType; const AKPIName: string): string;
var
  AKPICondition: string;
begin
  ClearAxisIndex;

  Result := '';
  if AKPIName = '' then
    Exit;
  AKPICondition := KPITypeMap[AKPIType] + '("' + AKPIName + '")';
  if AFilters <> nil then
    FFilters := TcxPivotGridFields.Create
  else
    FFilters := nil;
  try
    Result := FilterPartForTotals(AColumns, AnExpandedMembers, AFilters, FFilters);
    if (AnExpandedMembers <> nil) and IsNotLastVisibleOLAPHierarchyItem(TcxPivotGridGroupItem(AnExpandedMembers[0])) then
      Result := Result + ColumnPart(ACubeName, AColumns, nil, True, False, Result = '', GetExpandedMembers(AnExpandedMembers) + CrossJoinOperator)
    else
    begin
      Result := Result + ColumnPart(ACubeName, AColumns, nil, True, False, Result = '');
      if AnExpandedMembers <> nil then
        Result := Result + ', ' + GetExpandedMembers(AnExpandedMembers) + GetAxis;
    end;
    if Result <> '' then
      Result := Result + SourcePart(ACubeName, FFilters, nil, AKPICondition);
  finally
    FreeAndNil(FFilters);
  end;
end;

function TcxOLAPDataQueryBuilder.GetMeasuresCount(AMeasures: TcxPivotGridFields;
  AFieldType: TcxPivotGridOLAPFieldType): Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to AMeasures.Count - 1 do
    if TcxPivotGridOLAPField(AMeasures[I]).FieldType = AFieldType then
      Inc(Result);
end;

function TcxOLAPDataQueryBuilder.GetMembersQueryString(const ACubeName: string;
  AField: TcxPivotGridOLAPField; AnExpandedMembers: TList; AFilters: TcxPivotGridFields; AMeasures: TcxPivotGridFields): string;

  function IsFieldInExpandingHierarchy(AField: TcxPivotGridOLAPField; AnExpandedMembers: TList): Boolean;
  var
    I: Integer;
    AExpandedField: TcxPivotGridOLAPField;
  begin
    Result := False;
    if (AField <> nil) and (AnExpandedMembers <> nil) and AField.IsHierarchy then
      for I := 0 to AnExpandedMembers.Count - 1 do
      begin
        AExpandedField := TcxPivotGridOLAPField(TcxPivotGridGroupItem(AnExpandedMembers[I]).Field);
        if AExpandedField.IsHierarchy and (AExpandedField.Group = AField.Group) then
        begin
          Result := True;
          Break;
        end;
      end;
  end;

var
  AColumnQuery: string;
  ANamedSets: TList;
begin
  ClearAxisIndex;

  Result := '';
  if AField <> nil then
    case FVersion of
      7, 8:
        begin
          Result := Result + 'select non empty { ';
          Result := Result + WriteSortedMembers(AField,
            WriteAllMembersCore(AField, True, False)) + '}' + GetAxis;
          Result := Result + SourcePartWithWhereCondition(ACubeName, AFilters, nil);
        end
    else
    begin
      if AFilters <> nil then
        FFilters := TcxPivotGridFields.Create
      else
        FFilters := nil;
      try
        if FFilters <> nil then
        begin
          FFilters.Assign(AFilters);
          ExcludeField(FFilters, AField);
          ExcludeExpandingMembersFormFilters(AnExpandedMembers, FFilters);
        end;

        Result := 'with member Measures.MemberName as ' + AField.HierarchyUniqueName + '.MEMBER_NAME ' +
          'member Measures.MemberUniqueName as ' + AField.HierarchyUniqueName + '.MEMBER_UNIQUE_NAME ';
        AColumnQuery := GetMeasures(AMeasures, 'Measures.MemberName, Measures.MemberUniqueName');

        Result := Result + CreateFilterAggregates(FFilters);

        Result := Result + 'select non empty ';
        Result := Result + AColumnQuery + GetAxis + ', ';
        Result := Result + 'non empty {';
        if not IsFieldInExpandingHierarchy(AField, AnExpandedMembers) then
        begin
          if AField.FieldType = oftSet then
            Result := Result + '{';
          Result := Result + WriteSortedMembers(AField, WriteAllMembersCore(AField, True, False, FFilters <> nil));
          if AField.FieldType = oftSet then
            Result := Result + ' - {' + AField.LevelUniqueName + '.[All]}}';
          Result := Result + CrossJoinOperator;
        end;
        if AnExpandedMembers <> nil then
          Result := Result + GetExpandedMembers(AnExpandedMembers)
        else
          TrimTrailingSequence(Result, CrossJoinOperator);
        Result := Result + '}' + GetAxis;

        ANamedSets := TList.Create;
        try
          if AField.FieldType = oftSet then
            ANamedSets.Add(AField);
          Result := Result + SourcePart(ACubeName, FFilters, ANamedSets);
        finally
          ANamedSets.Free;
        end;
      finally
        FreeAndNil(FFilters);
      end;
    end;
  end;
end;

function TcxOLAPDataQueryBuilder.GetParentQueryString(const ACubeName: string; AField: TcxPivotGridOLAPField; const AMemberUniqueName: string): string;
begin
  ClearAxisIndex;

  Result := '';
  if AField <> nil then
  begin
    Result := 'with member Measures.ParentUniqueName as ' + AField.HierarchyUniqueName + '.PARENT_UNIQUE_NAME ';
    Result := Result + 'select non empty ';
    Result := Result + '{Measures.ParentUniqueName}' + GetAxis + ', ';
    Result := Result + AMemberUniqueName + GetAxis;
    Result := Result + SourcePartWithWhereCondition(ACubeName, nil, nil);
  end;
end;

function TcxOLAPDataQueryBuilder.GetQueryString(const ACubeName: string;
  AColumns: TcxPivotGridFields; ARows: TcxPivotGridFields;
  AMeasures: TcxPivotGridFields; AFilters: TcxPivotGridFields): string;

  function MeasuresAndColumnsPart(const ACubeName: string; AColumns: TcxPivotGridFields;
      AMeasures: TcxPivotGridFields; IncludeCalculatedMembers, IncludeTotals: Boolean; const AAdditionalString: string = ''): string;
  begin
    Result := '';
    if ((AMeasures <> nil) and (AMeasures.Count = 0) or
      (AMeasures = nil) and (AColumns.Count = 0)) and (AAdditionalString = '') then
      Exit;

    Result := 'select';

    if AMeasures <> nil then
      Result := Result + ' non empty' + GetMeasures(AMeasures, '') + GetAxis + ', ';

    if (AAdditionalString = '') and (AColumns.Count = 0) then
      TrimTrailingComma(Result)
    else
    begin
      Result := Result + ' non empty{ ' + AAdditionalString;
      if AColumns.Count > 0 then
        Result := Result + WriteAllMembersWithSorting(TcxPivotGridOLAPField(AColumns[0]), IncludeCalculatedMembers, IncludeTotals);
      Result := Result  + '} dimension properties member_unique_name ' + GetAxis;
    end;
  end;

begin
  ClearAxisIndex;

  Result := '';
  if GetMeasuresCount(AMeasures, oftMeasure) = 0 then
    Exit;

  if AFilters <> nil then
    FFilters := TcxPivotGridFields.Create
  else
    FFilters := nil;
  try
    Result := FilterPart(AColumns, ARows, AFilters, FFilters);
    Result := Result + MeasuresAndColumnsPart(ACubeName, AColumns, AMeasures, True, True);
    if ARows.Count > 0 then
      Result := Result + ', non empty ' + WriteAllMembersWithSorting(TcxPivotGridOLAPField(ARows[0]), True, True) +
        'dimension properties member_unique_name' + GetAxis;
    Result := Result + SourcePart(ACubeName, FFilters, nil);
  finally
    FreeAndNil(FFilters);
  end;
end;

function TcxOLAPDataQueryBuilder.GetTotalQueryString(const ACubeName: string; AFilters: TcxPivotGridFields; AMeasures: TcxPivotGridFields): string;
begin
  ClearAxisIndex;

  if GetMeasuresCount(AMeasures, oftMeasure) > 0 then
  begin
    FFilters := AFilters;
    try
      Result := CreateFilterAggregates(AFilters);
      if Result <> '' then
        Result := 'with ' + Result;
      Result := Result + 'select {'+ GetMeasures(AMeasures) + '}' + GetAxis + SourcePartWithWhereCondition(ACubeName, AFilters, nil);
    finally
      FFilters := nil;
    end;
  end;
end;

function TcxOLAPDataQueryBuilder.GetTotalsQueryString(const ACubeName: string; AColumns, ARowFilters: TcxPivotGridFields;
  AnExpandedMembers: TList; AMeasures: TcxPivotGridFields; AFilters: TcxPivotGridFields): string;
begin
  ClearAxisIndex;

  Result := '';
  if GetMeasuresCount(AMeasures, oftMeasure) = 0 then
    Exit;

  if AFilters <> nil then
    FFilters := TcxPivotGridFields.Create
  else
    FFilters := nil;
  try
    Result := FilterPartForTotals(AColumns, AnExpandedMembers, AFilters, FFilters);
    if (AnExpandedMembers <> nil) and IsNotLastVisibleOLAPHierarchyItem(TcxPivotGridGroupItem(AnExpandedMembers[0])) then
      Result := Result + ColumnPart(ACubeName, AColumns, AMeasures, True, True, Result = '', GetExpandedMembers(AnExpandedMembers) + CrossJoinOperator)
    else
    begin
      if IsOLAPVersion8 then
        Result := Result + ColumnPartVersion8(ACubeName, AColumns, AMeasures, True, True)
      else
        Result := Result + ColumnPart(ACubeName, AColumns, AMeasures, True, True, Result = '');
      if AnExpandedMembers <> nil then
        Result := Result + ', ' + GetExpandedMembers(AnExpandedMembers) + GetAxis;
    end;
    Result := Result + SourcePart(ACubeName, FFilters, nil);
  finally
    FreeAndNil(FFilters);
  end;
end;

procedure TcxOLAPDataQueryBuilder.ClearAxisIndex;
begin
  FAxisIndex := 0;
end;

function TcxOLAPDataQueryBuilder.CreateFilterAggregates(AFilters: TcxPivotGridFields): string;
var
  I: Integer;
begin
  Result := '';
  if (AFilters <> nil) and not IsStrongRelationshipBetweenFilterAndDimensions(AFilters) then
  begin
    for I := AFilters.Count - 1 downto 0 do
      if (I = AFilters.Count - 1) or not IsHierarchy(TcxPivotGridOLAPField(AFilters[I]), TcxPivotGridOLAPField(AFilters[I + 1])) then
        Result := Result + CreateFilterAggregate(TcxPivotGridOLAPField(AFilters[I]));
  end;
end;

function TcxOLAPDataQueryBuilder.CreateFilterAggregate(AField: TcxPivotGridOLAPField): string;
begin
  Result := '';
  if IsMultipleFilteredValues(AField) then
  begin
    Result := GetMember(AField, scxOLAPFilterCaption);
    Result := Result + '''aggregate(existing{' + WriteAllMembers(AField, False) + '})'' '
  end;
end;

function TcxOLAPDataQueryBuilder.CreateFilterWhereClause(AFilters: TcxPivotGridFields; AAdditionalCondition: string): string;

  function AddCondition(var ACount: integer): string;
  begin
    Result := '';
    if AAdditionalCondition <> '' then
    begin
      Result := AAdditionalCondition + ', ';
      Inc(ACount);
    end;
  end;

var
  I, ACount: Integer;
begin
  Result := '';
  if AFilters = nil then
    Exit;
  ACount := 0;
  Result := ' where (' + AddCondition(ACount);
  for I := AFilters.Count - 1 downto 0 do
    if ((I = AFilters.Count - 1) or not IsHierarchy(TcxPivotGridOLAPField(AFilters[I]), TcxPivotGridOLAPField(AFilters[I + 1]))) then
    begin
      Result := Result + GetFilterString(TcxPivotGridOLAPField(AFilters[I])) + Comma;
      Inc(ACount);
    end;
  if ACount <> 0 then
  begin
    TrimTrailingComma(Result);
    Result := Result + ')';
  end
  else
    Result := '';
end;

procedure TcxOLAPDataQueryBuilder.ExcludeExpandingMembersFormFilters(AnExpandedMembers: TList; AFilters: TcxPivotGridFields);
var
  I: Integer;
begin
  if AnExpandedMembers <> nil then
    for I := 0 to AnExpandedMembers.Count - 1 do
      ExcludeField(AFilters, TcxPivotGridOLAPField(TcxPivotGridGroupItem(AnExpandedMembers[I]).Field));
end;

procedure TcxOLAPDataQueryBuilder.ExcludeField(AFilters: TcxPivotGridFields; AField: TcxPivotGridOLAPField);
var
  I: Integer;
begin
  if (AFilters <> nil) and (AField <> nil) then
    for I := AFilters.Count - 1 downto 0 do
      if TcxPivotGridOLAPField(AFilters[I]).HierarchyUniqueName = AField.HierarchyUniqueName then
        AFilters.Delete(I);
end;

function TcxOLAPDataQueryBuilder.GetAxis: string;
begin
  Result := ' on ' + IntToStr(FAxisIndex);
  Inc(FAxisIndex);
end;

function TcxOLAPDataQueryBuilder.GetCountInArea(AFields: TcxPivotGridFields;
  AArea: TcxPivotGridFieldArea): Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to AFields.Count - 1 do
    if AFields[I].Area = AArea then
      Inc(Result);
end;

function TcxOLAPDataQueryBuilder.GetExpandedMembers(AnExpandedMembers: TList; AClearMember: Boolean = False): string;

  function GetMemberString(Index: Integer): string;
  var
    AnItemName: string;
  begin
    AnItemName := TcxPivotGridGroupItem(AnExpandedMembers[Index]).UniqueName;
    if IsNotLastVisibleOLAPHierarchyItem(TcxPivotGridGroupItem(AnExpandedMembers[Index])) and not AClearMember then
      Result := WriteSortedMembers(TcxPivotGridOLAPField(TcxPivotGridGroupItem(
         AnExpandedMembers[Index]).Field), 'addcalculatedmembers(' + AnItemName + '.children)')
    else
      Result := AnItemName;
  end;

var
  I: Integer;
begin
  Result := '';
  if (AnExpandedMembers <> nil) and (AnExpandedMembers.Count > 0) then
  begin
    for I := 0 to AnExpandedMembers.Count - 1 do
      Result := Result + '{' + GetMemberString(I) + '}*';
    Delete(Result, Length(Result), 1);
  end;
end;

function TcxOLAPDataQueryBuilder.GetFilterSetupString(AFilters: TcxPivotGridFields): string;
begin
  Result := CreateFilterAggregates(AFilters);
  if Result <> '' then
    Result := 'with ' + Result;
end;

function TcxOLAPDataQueryBuilder.GetFilterString(AFilter: TcxPivotGridOLAPField): string;
begin
  if IsMultipleFilteredValues(AFilter) then
    Result := GetMemberName(AFilter, scxOLAPFilterCaption)
  else
    Result := WriteAllMembersCore(AFilter, False, False);
end;

function TcxOLAPDataQueryBuilder.GetMemberName(AField: TcxPivotGridOLAPField;
  const AType: string): string;
begin
  Result := AField.HierarchyUniqueName + '.[' + AField.Name + ' ' + AType + ']';
end;

function TcxOLAPDataQueryBuilder.GetMembers(AFilter: TStrings): string;
var
  I: Integer;
begin
  Result := '';
  for I := 0 to AFilter.Count - 1 do
    Result := Result + AFilter[I] + Comma;
  TrimTrailingComma(Result);
end;

function TcxOLAPDataQueryBuilder.GetMeasures(AMeasures: TcxPivotGridFields; const AAdditionalString: string = ''): string;
var
  I: Integer;
begin
  Result := '{ ';
  if AAdditionalString <> '' then
    Result := Result + AAdditionalString + ', ';
  if AMeasures <> nil then
  begin
    for I := 0 to AMeasures.Count - 1 do
      if TcxPivotGridOLAPField(AMeasures[I]).FieldType = oftMeasure then
        Result := Result + TcxPivotGridOLAPField(AMeasures[I]).UniqueName + Comma;
  end;
  TrimTrailingComma(Result);
  Result := Result + ' } ';
end;

function TcxOLAPDataQueryBuilder.GetMember(AField: TcxPivotGridOLAPField; const AType: string): string;
begin
  Result := 'member ' + GetMemberName(AField, AType) + ' as ';
end;

function TcxOLAPDataQueryBuilder.GetNamedSetName(AField: TcxPivotGridOLAPField): string;
begin
  Result := '{[' + AField.UniqueName + ']}';
end;

function TcxOLAPDataQueryBuilder.GetNamedSets(AnExpandedMembers: TList): TList;
var
  I: Integer;
begin
  Result := TList.Create;
  for I := 0 to AnExpandedMembers.Count - 1 do
    if TcxPivotGridOLAPField(TcxPivotGridGroupItem(AnExpandedMembers[I]).Field).FieldType = oftSet then
      Result.Add(TcxPivotGridGroupItem(AnExpandedMembers[I]).Field);
end;

function TcxOLAPDataQueryBuilder.GetNamedSetsQuery(ANamedSets: TList): string;
var
  I: Integer;
begin
  Result := 'select ';
  for I := 0 to ANamedSets.Count - 1 do
    Result := Result +  GetNamedSetName(TcxPivotGridOLAPField(ANamedSets[I])) +
      ' ON ' + IntToStr(I) + ', ';
  TrimTrailingComma(Result);
end;

function TcxOLAPDataQueryBuilder.IsHierarchy(AField: TcxPivotGridOLAPField;
  AParentField: TcxPivotGridOLAPField): Boolean;
begin
  Result := (AField.Group <> nil) and (AParentField.Group = AField.Group);
end;

function TcxOLAPDataQueryBuilder.IsStrongRelationshipBetweenFilterAndDimensions(AFilters: TcxPivotGridFields): Boolean;
begin
  Result := (AFilters <> nil) and (GetCountInArea(AFilters, faFilter) > 0);
end;

function TcxOLAPDataQueryBuilder.GetSortOrder(AField: TcxPivotGridOLAPField): string;
begin
  if AField.SortOrder = soDescending then
    Result := 'desc'
  else
    Result := 'asc';
end;

function TcxOLAPDataQueryBuilder.GetTuple(ATuple: TcxPivotGridGroupItem;
  IncludeLastMember: Boolean = True; MembersCount: Integer = 0): string;
var
  I: Integer;
begin
  if ATuple.Parent <> nil then
  begin
    Result := ' )';
    I := 0;
    while (ATuple.Parent <> nil) and ((MembersCount = 0) or (I < MembersCount)) do
    begin
      if IncludeLastMember or (I > 0) then
        Result := Comma + ATuple.UniqueName + Result;
      ATuple := ATuple.Parent;
      Inc(I);
    end;
    Delete(Result, 1, 2);
    Result := '( ' + Result;
  end
  else
    Result := '';
end;

function TcxOLAPDataQueryBuilder.IsFiltered(AField: TcxPivotGridOLAPField): Boolean;
var
  I: Integer;
begin
  Result := AField.Filter.HasFilter;
  I := 0;
  while (FFilters <> nil) and (I < FFilters.Count) and not Result do
  begin
    Result := (AField.Group <> nil) and (FFilters[I].Group = AField.Group) and
      FFilters[I].Filter.HasFilter;
    Inc(I);
  end;
end;

function TcxOLAPDataQueryBuilder.IsOLAPVersion8: Boolean;
begin
  Result := FVersion <= 8;
end;

function TcxOLAPDataQueryBuilder.IsMultipleFilteredValues(AField: TcxPivotGridOLAPField): Boolean;
var
  AFilterCount: Integer;
begin
  AFilterCount := AField.FilteredValueCount(AField);
  Result := (AFilterCount > 1) or
    (AField.Filter.FilterType = ftExcluded) and (AFilterCount > 0);
end;

function TcxOLAPDataQueryBuilder.WriteAllMembers(AField: TcxPivotGridOLAPField;
  IncludeCalculatedMembers: Boolean): string;
begin
  Result := '{ ' +
    WriteAllMembersCore(AField, IncludeCalculatedMembers, False) + '} ';
end;

function TcxOLAPDataQueryBuilder.WriteAllMembersWithSorting(AField: TcxPivotGridOLAPField;
  IncludeCalculatedMembers, IncludeTotal: Boolean): string;
begin
  Result := '{ ';
  Result := Result + WriteSortedMembers(AField,
    WriteAllMembersCore(AField, IncludeCalculatedMembers, IncludeTotal)) + '} ';
end;

function TcxOLAPDataQueryBuilder.WriteAllMembersCore(AField: TcxPivotGridOLAPField;
  IncludeCalculatedMembers, ExcludeTotal: Boolean; AFilter: Boolean = True): string;
var
  AList: TStrings;
begin
  Result := '';
  if IsFiltered(AField) and AFilter then
  begin
    AList := TcxPivotGridOLAPField.PopulateFilteredValues(AField);
    try
      Result := Result + GetMembers(AList);
    finally
      AList.Free;
    end;
  end
  else
  begin
    if IncludeCalculatedMembers then
      Result := Result + 'addcalculatedmembers({';
    if AField.FieldType <> oftSet then
      Result := Result + AField.LevelUniqueName + '.members'
    else
      Result := Result + GetNamedSetName(AField);
    if IncludeCalculatedMembers then
      Result := Result + '})';
  end;
end;

function TcxOLAPDataQueryBuilder.WriteSortedMembers(AField: TcxPivotGridOLAPField;
  const AContent: string): string;
begin
  if not TcxPivotGridOLAPFieldOptionsAccess(AField.Options).CanSorting then
    Result := AContent
  else
    Result := 'order({' + AContent + '}, ' + GetSortBy(AField) + Comma +
      GetSortOrder(AField) + ')';
end;

function TcxOLAPDataQueryBuilder.FilterPart(AColumns: TcxPivotGridFields; ARows: TcxPivotGridFields;
  AFilters, AGlobalFilters: TcxPivotGridFields): string;
begin
  if AGlobalFilters <> nil then
  begin
    AGlobalFilters.Assign(AFilters);
    if ARows.Count > 0 then
      ExcludeField(AGlobalFilters, TcxPivotGridOLAPField(ARows[0]));
    if AColumns.Count > 0 then
      ExcludeField(AGlobalFilters, TcxPivotGridOLAPField(AColumns[0]));
  end;
  Result := GetFilterSetupString(AGlobalFilters);
end;

function TcxOLAPDataQueryBuilder.FilterPartForTotals(AColumns: TcxPivotGridFields; AnExpandedMembers: TList;
  AFilters, AGlobalFilters: TcxPivotGridFields): string;
begin
  if AGlobalFilters <> nil then
  begin
    AGlobalFilters.Assign(AFilters);
    if AColumns.Count > 0 then
      ExcludeField(AGlobalFilters, TcxPivotGridOLAPField(AColumns[0]));
    ExcludeExpandingMembersFormFilters(AnExpandedMembers, AGlobalFilters);
  end;
  Result := GetFilterSetupString(AGlobalFilters);
end;

function TcxOLAPDataQueryBuilder.ColumnPartVersion8(const ACubeName: string; AColumns: TcxPivotGridFields;
  AMeasures: TcxPivotGridFields; IncludeCalculatedMembers, IncludeTotals: Boolean; const AAdditionalString: string = ''): string;
begin
  Result := '';
  if ((AMeasures <> nil) and (AMeasures.Count = 0) or
    (AMeasures = nil) and (AColumns.Count = 0)) and (AAdditionalString = '') then
    Exit;

  Result := Result + 'select non empty { ' + AAdditionalString;
  if AColumns.Count > 0 then
    Result := Result + WriteAllMembersWithSorting(TcxPivotGridOLAPField(AColumns[0]), IncludeCalculatedMembers, IncludeTotals) + CrossJoinOperator;
  if AMeasures = nil then
    TrimTrailingComma(Result)
  else
    Result := Result + GetMeasures(AMeasures);
  Result := Result + '}' + GetAxis;
end;

function TcxOLAPDataQueryBuilder.ColumnPart(const ACubeName: string; AColumns: TcxPivotGridFields;
  AMeasures: TcxPivotGridFields; IncludeCalculatedMembers, IncludeTotals, AddWith: Boolean; const AAdditionalString: string = ''): string;

  function GetMember(AField: TcxPivotGridOLAPField): string;
  begin
    Result := ' member Measures.MemberUniqueName as ' + AField.HierarchyUniqueName + '.MEMBER_UNIQUE_NAME ';
  end;

var
  AMember: string;
begin
  Result := '';
  if ((AMeasures <> nil) and (AMeasures.Count = 0) or
    (AMeasures = nil) and (AColumns.Count = 0)) and (AAdditionalString = '') then
    Exit;

  if AColumns.Count > 0 then
  begin
    if AddWith then
      Result := 'with';
    Result := Result + GetMember(TcxPivotGridOLAPField(AColumns[0]));
  end;

  Result := Result + ' select';

  if AMeasures <> nil then
  begin
    if AColumns.Count > 0 then
      AMember := 'Measures.MemberUniqueName'
    else
      AMember := '';
    Result := Result + ' non empty' + GetMeasures(AMeasures, AMember) + GetAxis + ', ';
  end;

  if (AAdditionalString = '') and (AColumns.Count = 0) then
    TrimTrailingComma(Result)
  else
  begin
    Result := Result + ' non empty{ ' + AAdditionalString;
    if AColumns.Count > 0 then
      Result := Result + WriteAllMembersWithSorting(TcxPivotGridOLAPField(AColumns[0]), IncludeCalculatedMembers, IncludeTotals)
    else
      TrimTrailingComma(Result);
    Result := Result + '}';
    if AAdditionalString <> '' then
      Result := Result + 'dimension properties member_unique_name';
    Result := Result + GetAxis;
  end;
end;

function TcxOLAPDataQueryBuilder.SourcePart(const ACubeName: string;
  AFilters: TcxPivotGridFields; ANamedSets: TList; const AAdditionalCondition: string = ''): string;
begin
  if not IsStrongRelationshipBetweenFilterAndDimensions(AFilters) then
    Result := Result + SourcePartWithWhereCondition(ACubeName, AFilters, ANamedSets, AAdditionalCondition)
  else
    Result := Result + SourcePartWithSubSelect(ACubeName, AFilters, ANamedSets);
end;

function TcxOLAPDataQueryBuilder.SourcePartWithWhereCondition(const ACubeName: string; AFilters: TcxPivotGridFields;
  ANamedSets: TList; const AAdditionalCondition: string = ''): string;
var
  ACloseParenthesis: Boolean;
begin
  ACloseParenthesis := False;
  Result := ' ';
  if (ANamedSets <> nil) and (ANamedSets.Count > 0) then
  begin
    Result := Result + 'from (' + GetNamedSetsQuery(ANamedSets);
    ACloseParenthesis := True;
  end;

  Result := Result + ' from [' + ACubeName + ']' + CreateFilterWhereClause(AFilters, AAdditionalCondition);

  if ACloseParenthesis then
    Result := Result + ')';
end;

function TcxOLAPDataQueryBuilder.SourcePartWithSubSelect(const ACubeName: string;
  AFilters: TcxPivotGridFields; ANamedSets: TList; const AAdditionalCondition: string = ''): string;

  function GetCubeName: string;
  begin
    Result := 'from [' + ACubeName + ']';
  end;

var
  I, AxisIndex, AParenthesisCount: Integer;
  AList: TStrings;
  ASubSelect: string;
  ASubSelectIsCorrect: Boolean;
begin
  Result := ' ';
  ASubSelectIsCorrect := False;
  AParenthesisCount := 0;
  if (AFilters <> nil) and (AFilters.Count > 0) then
  begin
    ASubSelect := 'from (select ';
    AxisIndex := 0;
    for I := 0 to AFilters.Count - 1 do
    begin
      if (AFilters[I].Group <> nil) and (I + 1 < AFilters.Count) and
        (AFilters[I].Group = AFilters[I + 1].Group) then
        Continue;
      AList := TcxPivotGridOLAPField.PopulateFilteredValues(AFilters[I], True);
      if AList.Count > 0 then
        ASubSelectIsCorrect := True;
      try
        ASubSelect := ASubSelect + '{' + GetMembers(AList) + '} on ' + IntToStr(AxisIndex) + Comma;
        Inc(AxisIndex);
      finally
        AList.Free;
      end;
    end;
    TrimTrailingComma(ASubSelect);
    ASubSelect := ASubSelect + ' ';
    if ASubSelectIsCorrect then
    begin
      Result := Result + ASubSelect;
      Inc(AParenthesisCount);
    end;
  end;
  if (ANamedSets <> nil) and (ANamedSets.Count > 0) then
  begin
    Result := Result + 'from (' + GetNamedSetsQuery(ANamedSets);
    Inc(AParenthesisCount);
  end;
  Result := Result + ' ' + GetCubeName;
  for I := 0 to AParenthesisCount - 1 do
    Result := Result + ')';
  if AAdditionalCondition <> '' then
    Result := Result + ' where(' + AAdditionalCondition + ')';
end;

procedure TcxOLAPDataQueryBuilder.TrimTrailingComma(var AStr: string);
begin
  TrimTrailingSequence(AStr, Comma);
end;

procedure TcxOLAPDataQueryBuilder.TrimTrailingSequence(var AStr: string; const ASequence: string);
var
  ASequenceLength: Integer;
begin
  ASequenceLength := Length(ASequence);
  Delete(AStr, Length(AStr) - ASequenceLength + 1, ASequenceLength);
end;

function TcxOLAPDataQueryBuilder.GetSortBy(AField: TcxPivotGridOLAPField): string;
begin
  Result := AField.HierarchyUniqueName;
  case FVersion of
    7, 8:
      begin
        Result := Result + '.currentmember.properties("';
        case AField.SortMode of
          osmValue, osmDisplayText: Result := Result + 'caption")';
          osmKey: Result := Result + 'key")';
        else
          Result := Result + 'id")';
        end;
      end;
  else
    Result := Result + '.currentmember.';
    case AField.SortMode of
      osmValue: Result := Result + 'member_value';
      osmDisplayText: Result := Result + 'member_caption';
      osmKey: Result := Result + 'member_key';
    else
      Result := Result + 'properties(''id'', typed)';
    end;
  end;
end;

end.
