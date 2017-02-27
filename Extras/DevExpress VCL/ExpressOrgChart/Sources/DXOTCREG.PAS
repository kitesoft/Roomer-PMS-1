{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       Express OrgChart                                            }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSORGCHART AND ALL ACCOMPANYING }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.             }
{                                                                   }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED      }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE        }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE       }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT  }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                      }
{                                                                   }
{   CONSULT THE end USER LICENSE AGREEMENT FOR INFORMATION ON       }
{   ADDITIONAL RESTRICTIONS.                                        }
{                                                                   }
{*******************************************************************}

unit dxotcreg;

interface

{$I cxVer.inc}

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  DesignIntf, DesignEditors, dxCoreReg, dxorgchr, dxorgced;

const
  dxOCProductName = 'ExpressOrgChart';
  dxOCProductPage = 'ExpressOrgChart';

type
  TdxOCCustomEditor = class(TdxComponentEditor)
  protected
    function GetProductName: string; override;
  end;

  TdxOCEditor = class(TdxOCCustomEditor)
  protected
    function InternalGetVerb(AIndex: Integer): string; override;
    function InternalGetVerbCount: Integer; override;
    procedure InternalExecuteVerb(AIndex: Integer); override;
  end;

procedure Register;

implementation

function TdxOCCustomEditor.GetProductName: string;
begin
  Result := dxOCProductName;
end;

function TdxOCEditor.InternalGetVerb(AIndex: Integer): string;
begin
  Result := 'Items Editor...';
end;

function TdxOCEditor.InternalGetVerbCount: Integer;
begin
  Result := 1;
end;

procedure TdxOCEditor.InternalExecuteVerb(AIndex: Integer);
begin
  if ShowOrgChartEditor(TdxOrgChart(Component)) then
    Designer.Modified;
end;

procedure Register;
begin
{$IFDEF DELPHI9}
  ForceDemandLoadState(dlDisable);
{$ENDIF}  
  RegisterComponents(dxOCProductPage, [TdxOrgChart]);
  RegisterComponentEditor(TdxOrgChart, TdxOCEditor);
end;

end.
