//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("NotesMainForm.cpp", fmNotesMainForm);
USEFORM("..\Common\AboutDemoForm.cpp", formAboutDemo);
USEFORM("..\Common\EBarsDemoRating.cpp", EBarsDemoRatingForm);
USEFORM("..\Common\EBarsUtils.cpp", dmCommonData); /* TDataModule: File Type */
USEFORM("..\Common\NotepadChildForm.cpp", frmNotepadChild);
USEFORM("..\Common\NotepadMainForm.cpp", frmNotepadMain);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TdmCommonData), &dmCommonData);
		Application->CreateForm(__classid(TfmNotesMainForm), &fmNotesMainForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
