{***************************************************************************}
{ TScrMemo component                                                        }
{ for Delphi & C++Builder                                                   }
{                                                                           }
{ written by TMS Software                                                   }
{            copyright © 2001 - 2012                                        }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{                                                                           }
{ The source code is given as is. The author is not responsible             }
{ for any possible damage done due to the use of this code.                 }
{ The component can be freely used in any application. The complete         }
{ source code remains property of the author and may not be distributed,    }
{ published, given or sold in any form as such. No parts of the source      }
{ code can be included in any other component or application without        }
{ written authorization of TMS software.                                    }
{***************************************************************************}

unit ScrMemoReg;

interface

{$I TMSDEFS.INC}

uses
  Classes,
  ScrMemo,
  ScrmPS,
  ScrmBS,
  ScrCodeList,
  ScrMemoStylerManager
  ;




procedure Register;

implementation

uses
  ActnList;                                            

procedure Register;
begin
  RegisterComponents('TMS Scripter', [TScrMemo,TScrMemoSource,
                                  TScrPascalMemoStyler,
                                  TScrBasicMemoStyler,
                                  TScrMemoFindDialog,
                                  TScrMemoFindReplaceDialog,
                                  TScrCodeList,
                                  TScrMemoStylerManager,
                                  TScrMemoCapitalChecker]);


  {$IFNDEF DELPHIXE3_LVL}
  RegisterActions('ScrMemo', [TScrMemoCut, TScrMemoCopy, TScrMemoPaste,
    TScrMemoDelete, TScrMemoUndo, TScrMemoRedo, TScrMemoSelectAll], nil);
  {$ENDIF}
end;

end.
