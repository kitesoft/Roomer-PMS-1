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

unit cxPivotGridOLAPDataSourceReg;

{$I cxVer.inc}

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, ComCtrls, CommCtrl, ImgList,
  Types, DesignIntf, DesignEditors, VCLEditors, ADOReg,
  cxGraphics, cxControls, cxClasses, cxGeometry, cxCustomPivotGrid, cxPivotGridOLAPDataSource, cxButtons,
  cxPivotGrid, dxCoreReg, cxPivotGridReg;

procedure Register;

implementation

procedure Register;
begin
{$IFDEF DELPHI9}
  ForceDemandLoadState(dlDisable);
{$ENDIF}
  RegisterComponents(dxCoreLibraryProductPage, [TcxPivotGridOLAPDataSource]);
  RegisterClasses([TcxPivotGridOLAPDataSource]);
  RegisterComponentEditor(TcxPivotGridOLAPDataSource, cxPivotGridCustomComponentEditor);
  RegisterPropertyEditor(TypeInfo(WideString), TcxPivotGridOLAPDataSource,
    'ConnectionString', TConnectionStringProperty);
end;

end.



