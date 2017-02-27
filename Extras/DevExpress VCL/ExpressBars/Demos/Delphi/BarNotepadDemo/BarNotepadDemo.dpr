program BarNotepadDemo;

uses
  Forms,
  NotepadMainForm in '..\Common\NotepadMainForm.pas' {frmNotepadMain},
  NotepadChildForm in '..\Common\NotepadChildForm.pas' {frmNotepadChild},
  BarNotepadMainForm in 'BarNotepadMainForm.pas' {frmBarsNotepadMain},
  EBarsDemoRating in '..\Common\EBarsDemoRating.pas' {EBarsDemoRatingForm},
  EBarsUtils in '..\Common\EBarsUtils.pas',
  AboutDemoForm in '..\Common\AboutDemoForm.pas' {formAboutDemo};

  {$R *.res}
  {$R WindowsXP.res}

begin
  Application.Initialize;
  Application.CreateForm(TdmCommonData, dmCommonData);
  Application.CreateForm(TfrmBarsNotepadMain, frmBarsNotepadMain);
  Application.Run;
end.
