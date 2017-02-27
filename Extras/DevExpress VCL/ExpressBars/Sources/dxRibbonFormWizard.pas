{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       ExpressBars components                                      }
{                                                                   }
{       Copyright (c) 1998-2014 Developer Express Inc.              }
{       ALL RIGHTS RESERVED                                         }
{                                                                   }
{   The entire contents of this file is protected by U.S. and       }
{   International Copyright Laws. Unauthorized reproduction,        }
{   reverse-engineering, and distribution of all or any portion of  }
{   the code contained in this file is strictly prohibited and may  }
{   result in severe civil and criminal penalties and will be       }
{   prosecuted to the maximum extent possible under the law.        }
{                                                                   }
{   RESTRICTIONS                                                    }
{                                                                   }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES           }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE    }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS   }
{   LICENSED TO DISTRIBUTE THE EXPRESSBARS AND ALL ACCOMPANYING VCL }
{   CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.                 }
{                                                                   }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED      }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE        }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE       }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT  }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                      }
{                                                                   }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON       }
{   ADDITIONAL RESTRICTIONS.                                        }
{                                                                   }
{*******************************************************************}

unit dxRibbonFormWizard;

{$I cxVer.inc}

interface

uses
  Classes, Windows, DesignIntf, ToolsApi, DesignEditors,
  dxRibbonReg, dxCoreReg, dxRibbonForm, dxDesignHelpers, dxRibbonSkins;

const
  sdxRibbonApplicationWizardComment = 'Create a Ribbon Office %style% style VCL application';
  sdxRibbonApplicationWizardName = 'DevExpress VCL %version% Ribbon %style% Application';
  sdxRibbonFormWizardComment = 'Create a Ribbon Office %style% style VCL form';
  sdxRibbonFormWizardName = 'DevExpress VCL %version% Ribbon %style% Form';

type

  { TdxOTACustomRibbonWizard }

  TdxOTACustomRibbonWizard = class(TdxOTACustomRepositoryWizard, IOTAFormWizard)
  private
    FPersonality: TdxOTAPersonality;
    FRibbonStyle: TdxRibbonStyle;
  protected
    function ExpandRibbonStyleName(const AFormat: string): string;
    function GetGlyph: Cardinal; override;
    function GetIDString: string; override;
    function GetPersonality: TdxOTAPersonality; override;
  public
    constructor Create(ARibbonStyle: TdxRibbonStyle; APersonality: TdxOTAPersonality); virtual;
    //
    property Personality: TdxOTAPersonality read GetPersonality;
    property RibbonStyle: TdxRibbonStyle read FRibbonStyle;
  end;

  { TdxOTARibbonApplicationCreator }

  TdxOTARibbonApplicationCreator = class(TdxOTACustomProjectCreator)
  private
    FPersonality: TdxOTAPersonality;
  protected
    function GetCreatorType: string; override;
    function GetPersonality: TdxOTAPersonality; override;
  public
    constructor Create(APersonality: TdxOTAPersonality); virtual;
  end;

  { TdxOTARibbonApplicationWizard }

  TdxOTARibbonApplicationWizard = class(TdxOTACustomRibbonWizard, IOTAProjectWizard)
  protected
    procedure Execute; override;
    function GetCategory: TdxOTARepositoryCategory; override;
    function GetComment: string; override;
    function GetName: string; override;
  end;

  { TdxOTARibbonFormCreator }

  TdxOTARibbonFormCreator = class(TdxOTAFormCreator)
  private
    FRibbonStyle: TdxRibbonStyle;
    function LoadTemplate(const AName: string): string;
    procedure LoadTemplates(APersonality: TdxOTAPersonality; out AFormTemplate, AImplTemplate, AIntfTemplate: string);
  protected
    function ExpandTemplate(const ATemplate, AModuleIdent, AFormIdent, AAncestorIdent: string): string; override;
  public
    constructor Create(ARibbonStyle: TdxRibbonStyle; APersonality: TdxOTAPersonality);
    //
    property RibbonStyle: TdxRibbonStyle read FRibbonStyle;
  end;

  { TdxOTARibbonFormWizard }

  TdxOTARibbonFormWizard = class(TdxOTACustomRibbonWizard
    {$IFDEF DELPHI8}, IOTAProjectWizard{$ENDIF}
  )
  protected
    procedure Execute; override;
    function GetComment: string; override;
    function GetName: string; override;
  end;

implementation

uses
  SysUtils, dxCore;

{$R dxRibbonFormWizard.res}

const
  dxRibbonStyleNamePrefixMap: array[TdxRibbonStyle] of string = ('2007', '2010', '2013');

{ TdxOTACustomRibbonWizard }

constructor TdxOTACustomRibbonWizard.Create(ARibbonStyle: TdxRibbonStyle; APersonality: TdxOTAPersonality);
begin
  inherited Create;
  FRibbonStyle := ARibbonStyle;
  FPersonality := APersonality;
end;

function TdxOTACustomRibbonWizard.ExpandRibbonStyleName(const AFormat: string): string;
begin
  Result := StringReplace(AFormat, '%version%', dxGetShortBuildNumberAsString, [rfReplaceAll]);
  Result := StringReplace(Result, '%style%', dxRibbonStyleNamePrefixMap[RibbonStyle], [rfReplaceAll]);
end;

function TdxOTACustomRibbonWizard.GetGlyph: Cardinal;
begin
  Result := LoadIcon(HInstance, 'DXRIBBONFORMWIZARD');
end;

function TdxOTACustomRibbonWizard.GetIDString: string;
const
  PersonalitiesMap: array[TdxOTAPersonality] of string = ('Delphi', 'CBuilder');
begin
  Result := inherited GetIDString + dxRibbonStyleNamePrefixMap[RibbonStyle] + '.' + PersonalitiesMap[Personality];
end;

function TdxOTACustomRibbonWizard.GetPersonality: TdxOTAPersonality;
begin
  Result := FPersonality;
end;

{ TdxOTARibbonApplicationCreator }

constructor TdxOTARibbonApplicationCreator.Create(APersonality: TdxOTAPersonality);
begin
  inherited Create;
  FPersonality := APersonality;
end;

function TdxOTARibbonApplicationCreator.GetCreatorType: string;
begin
  Result := sApplication;
end;

function TdxOTARibbonApplicationCreator.GetPersonality: TdxOTAPersonality;
begin
  Result := FPersonality;
end;

{ TdxOTARibbonApplicationWizard }

procedure TdxOTARibbonApplicationWizard.Execute;
var
  AModuleServices: IOTAModuleServices;
begin
  if Supports(BorlandIDEServices, IOTAModuleServices, AModuleServices) then
  begin
    AModuleServices.CreateModule(TdxOTARibbonApplicationCreator.Create(Personality));
    AModuleServices.CreateModule(TdxOTARibbonFormCreator.Create(RibbonStyle, Personality));
  end;
end;

function TdxOTARibbonApplicationWizard.GetCategory: TdxOTARepositoryCategory;
begin
  Result := dxcNewProject;
end;

function TdxOTARibbonApplicationWizard.GetComment: string;
begin
  Result := ExpandRibbonStyleName(sdxRibbonApplicationWizardComment);
end;

function TdxOTARibbonApplicationWizard.GetName: string;
begin
  Result := ExpandRibbonStyleName(sdxRibbonApplicationWizardName);
end;

{ TdxOTARibbonFormCreator }

constructor TdxOTARibbonFormCreator.Create(
  ARibbonStyle: TdxRibbonStyle; APersonality: TdxOTAPersonality);
var
  AFormTemplate, AImplTemplate, AIntfTemplate: string;
begin
  FRibbonStyle := ARibbonStyle;
  LoadTemplates(APersonality, AFormTemplate, AImplTemplate, AIntfTemplate);
  inherited Create(AFormTemplate, AImplTemplate, AIntfTemplate);
end;

function TdxOTARibbonFormCreator.ExpandTemplate(const ATemplate, AModuleIdent, AFormIdent, AAncestorIdent: string): string;
const
  SkinNameMap: array[TdxRibbonStyle] of string = ('Office2007Blue', 'Office2010Blue', 'Office2013White');
begin
  Result := inherited ExpandTemplate(ATemplate, AModuleIdent, AFormIdent, AAncestorIdent);
  Result := StringReplace(Result, '%SkinName%', '''' + SkinNameMap[RibbonStyle] + '''', [rfReplaceAll]);
end;

function TdxOTARibbonFormCreator.LoadTemplate(const AName: string): string;
var
  AList: TStringList;
  AStream: TResourceStream;
begin
  AStream := TResourceStream.Create(HInstance, AName, 'DXWIZARDTEMPLATES');
  try
    AList := TStringList.Create;
    try
      AList.LoadFromStream(AStream);
      Result := AList.Text;
    finally
      AList.Free;
    end;
  finally
    AStream.Free;
  end;
end;

procedure TdxOTARibbonFormCreator.LoadTemplates(
  APersonality: TdxOTAPersonality; out AFormTemplate, AImplTemplate, AIntfTemplate: string);
begin
  AFormTemplate := LoadTemplate('RIBBON' + dxRibbonStyleNamePrefixMap[RibbonStyle] + 'FORM');
  if APersonality = dxopCBuilder then
  begin
    AIntfTemplate := LoadTemplate('RIBBON' + dxRibbonStyleNamePrefixMap[RibbonStyle] + 'CBUILDERHEADER');
    AImplTemplate := LoadTemplate('RIBBON' + dxRibbonStyleNamePrefixMap[RibbonStyle] + 'CBUILDERUNIT');
  end
  else
  begin
    AImplTemplate := LoadTemplate('RIBBON' + dxRibbonStyleNamePrefixMap[RibbonStyle] + 'DELPHIUNIT');
    AIntfTemplate := '';
  end;
end;

{ TdxOTARibbonFormWizard }

procedure TdxOTARibbonFormWizard.Execute;
var
  AModuleServices: IOTAModuleServices;
begin
  if Supports(BorlandIDEServices, IOTAModuleServices, AModuleServices) then
    AModuleServices.CreateModule(TdxOTARibbonFormCreator.Create(RibbonStyle, Personality));
end;

function TdxOTARibbonFormWizard.GetComment: string;
begin
  Result := ExpandRibbonStyleName(sdxRibbonFormWizardComment);
end;

function TdxOTARibbonFormWizard.GetName: string;
begin
  Result := ExpandRibbonStyleName(sdxRibbonFormWizardName);
end;

end.
