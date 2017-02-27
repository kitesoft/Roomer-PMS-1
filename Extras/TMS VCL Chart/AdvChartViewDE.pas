{***************************************************************************}
{ TAdvChart design time support                                             }
{ for Delphi & C++Builder                                                   }
{                                                                           }
{ written by TMS Software                                                   }
{            copyright © 2013                                               }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{                                                                           }
{ The source code is given as is. The author is not responsible             }
{ for any possible damage done due to the use of this code.                 }
{ The component can be freely used in any application. The complete         }
{ source code remains property of the author and may not be distributed,    }
{ published, given or sold in any form as such. No parts of the source      }
{ code can be included in any other component or application without        }
{ written authorization of the author.                                      }
{***************************************************************************}

unit AdvChartViewDE;

interface

{$I TMSDEFS.INC}

uses
  AdvChart, AdvChartView, AdvChartGDIP, AdvChartViewGDIP, Classes, Dialogs, AdvChartSerieEditor, AdvChartPaneEditor,
  AdvChartAnnotationEditor, AdvChartSerieEditorGDIP, AdvChartPaneEditorGDIP, AdvChartAnnotationEditorGDIP,
  {$IFDEF DELPHI6_LVL}
  DesignIntf, DesignEditors
  {$ELSE}
  DsgnIntf
  {$ENDIF}
  ;

type

  TChartPanesProperty = class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TChartSeriesProperty = class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TChartAnnotationsProperty = class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TChartPanesGDIPProperty = class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TChartSeriesGDIPProperty = class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TChartAnnotationsGDIPProperty = class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;


  procedure Register;

implementation

uses
  Forms;

type
  TCrackedChartView = class(TAdvChartView)
  
  end;  

procedure Register;
begin
  RegisterPropertyEditor(TypeInfo(TChartPanes),TAdvChartView,'Panes',TChartPanesProperty);
  RegisterPropertyEditor(TypeInfo(TChartSeries),TChartPane,'Series',TChartSeriesProperty);
  RegisterPropertyEditor(TypeInfo(TChartAnnotations),TChartSerie,'Annotations',TChartAnnotationsProperty);
  RegisterPropertyEditor(TypeInfo(TAdvGDIPChartPanes),TAdvGDIPChartView,'Panes',TChartPanesGDIPProperty);
  RegisterPropertyEditor(TypeInfo(TAdvGDIPChartSeries),TAdvGDIPChartPane,'Series',TChartSeriesGDIPProperty);
  RegisterPropertyEditor(TypeInfo(TChartGDIPAnnotations),TAdvGDIPChartSerie,'Annotations',TChartAnnotationsGDIPProperty);
end;


{ TChartSerieProperty }

procedure TChartPanesProperty.Edit;
var
  PaneEditor: TAdvChartPanesEditorForm;
  ChartView: TAdvChartView;
begin
  PaneEditor := TAdvChartPanesEditorForm.Create(Application);
  ChartView := TAdvChartView(GetComponent(0));
  PaneEditor.ChartView := ChartView; 
  PaneEditor.ChartPanes := ChartView.Panes;
  PaneEditor.Init;
  try
    PaneEditor.ShowModal;
    TCrackedChartView(ChartView).LoadData;
  finally
    Modified;
    PaneEditor.Free;
  end;
end;

function TChartPanesProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

{ TChartSeriesProperty }

procedure TChartSeriesProperty.Edit;
var
  SerieEditor: TAdvChartSeriesEditorForm;
  Pane: TChartPane;
begin
  SerieEditor := TAdvChartSeriesEditorForm.Create(Application);
  Pane := TChartPane(GetComponent(0));
  SerieEditor.ChartSeries := Pane.Series;
  SerieEditor.ChartView := Pane.ChartView;
  SerieEditor.Init;
  SerieEditor.ShowModal;
  Modified;
  (Pane.Collection.Owner as TAdvChartView).Invalidate;
  SerieEditor.Free;
end;

function TChartSeriesProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

{ TChartAnnotationsProperty }

procedure TChartAnnotationsProperty.Edit;
var
  AnnotationsEditor: TAdvChartAnnotationsEditorForm;
  Serie: TChartSerie;
begin
  AnnotationsEditor := TAdvChartAnnotationsEditorForm.Create(Application);
  Serie := TChartSerie(GetComponent(0));
  AnnotationsEditor.ChartAnnotations := Serie.Annotations;
  AnnotationsEditor.Chartview := (Serie.Chart.Series.Owner as TChartPane).ChartView;
  AnnotationsEditor.Init;
  try
    AnnotationsEditor.ShowModal;
  finally
    Modified;
    (((Serie.Collection.Owner as TChartSeries).Owner as TAdvChart).Owner as TAdvChartView).Invalidate;
    AnnotationsEditor.Free;
  end;
end;

function TChartAnnotationsProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

{ TChartPanesGDIPProperty }

procedure TChartPanesGDIPProperty.Edit;
var
  PaneEditor: TAdvChartPanesEditorFormGDIP;
  ChartView: TAdvGDIPChartView;
begin
  PaneEditor := TAdvChartPanesEditorFormGDIP.Create(Application);
  ChartView := TAdvGDIPChartView(GetComponent(0));
  PaneEditor.ChartPanes := ChartView.Panes;
  PaneEditor.ChartView := ChartView;
  PaneEditor.Init;
  try
    PaneEditor.ShowModal;

    TCrackedChartView(ChartView).LoadData;
  finally
    Modified;
    PaneEditor.Free;
  end;
end;

function TChartPanesGDIPProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

{ TChartSeriesGDIPProperty }

procedure TChartSeriesGDIPProperty.Edit;
var
  SerieEditor: TAdvChartSeriesEditorFormGDIP;
  Pane: TAdvGDIPChartPane;
begin
  SerieEditor := TAdvChartSeriesEditorFormGDIP.Create(Application);
  Pane := TAdvGDIPChartPane(GetComponent(0));
  SerieEditor.ChartSeries := Pane.Series;
  SerieEditor.ChartView := Pane.ChartView;
  SerieEditor.Init;
  SerieEditor.ShowModal;
  Modified;
  (Pane.Collection.Owner as TAdvGDIPChartView).Invalidate;
  SerieEditor.Free;
end;

function TChartSeriesGDIPProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

{ TChartAnnotationsGDIPProperty }

procedure TChartAnnotationsGDIPProperty.Edit;
var
  AnnotationsEditor: TAdvChartAnnotationsEditorFormGDIP;
  Serie: TAdvGDIPChartSerie;
begin
  AnnotationsEditor := TAdvChartAnnotationsEditorFormGDIP.Create(Application);
  Serie := TAdvGDIPChartSerie(GetComponent(0));
  AnnotationsEditor.chartAnnotations := Serie.Annotations;
  AnnotationsEditor.ChartView := (Serie.Chart.Series.Owner as TChartPane).ChartView;
  AnnotationsEditor.Init;
  try
    AnnotationsEditor.ShowModal;
  finally
    Modified;
    (((Serie.Collection.Owner as TChartSeries).Owner as TAdvGDIPChart).Owner as TAdvGDIPChartView).Invalidate;
    AnnotationsEditor.Free;
  end;
end;

function TChartAnnotationsGDIPProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

end.
