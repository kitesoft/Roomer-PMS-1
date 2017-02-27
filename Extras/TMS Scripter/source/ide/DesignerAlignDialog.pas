{***************************************************************************}
{ Scripter Studio Pro Components for Delphi & C++Builder                    }
{                                                                           }
{ written by TMS Software                                                   }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{                                                                           }
{ For information about version history, check the section "What's New"     }
{ at Scripter Studio manual.                                                }                                                                         
{                                                                           }
{ The source code is given as is. The author is not responsible             }
{ for any possible damage done due to the use of this code.                 }
{ The component can be freely used in any application. The complete         }
{ source code remains property of the author and may not be distributed,    }
{ published, given or sold in any form as such. No parts of the source      }
{ code can be included in any other component or application without        }
{ written authorization of the author.                                      }
{***************************************************************************}

unit DesignerAlignDialog;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls;

  {$I ASCRIPT.INC}

type
  TfrmAlign = class(TForm)
    rgrHorizontal: TRadioGroup;
    rgrVertical: TRadioGroup;
    btnOk: TButton;
    btnCancel: TButton;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

{BJF} {$IFNDEF UseGreatisUnits} {$R *.DFM} {$ENDIF}

end.
