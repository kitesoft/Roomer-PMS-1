unit uResponsiveListDemo;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, AdvScrollControl, AdvResponsiveList,
  Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    AdvResponsiveList1: TAdvResponsiveList;
    Label1: TLabel;
    Label2: TLabel;
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
var
  sl,col: TStringList;
  i: integer;
begin
  AdvResponsiveList1.Items.Clear;

  sl := TStringList.Create;
  col := TStringList.Create;
  col.StrictDelimiter := true;
  col.Delimiter := ',';

  AdvResponsiveList1.BeginUpdate;

  try
    sl.LoadFromFile('.\carlist.txt');

    for i := 0 to sl.Count - 1 do
    begin
      col.CommaText := sl.Strings[i];
      AdvResponsiveList1.Items.Add.Content := '<B>'+col[0]+'</B>'+'<BR><IMG SRC="file://.\'+col[2]+'"><BR><BR>'+col[1];
    end;

  finally
    AdvResponsiveList1.EndUpdate;
    sl.Free;
  end;
end;

end.
