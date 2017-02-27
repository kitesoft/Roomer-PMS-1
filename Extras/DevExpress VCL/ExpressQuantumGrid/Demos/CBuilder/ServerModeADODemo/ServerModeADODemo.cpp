//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("ServerModeDemoData.cpp", ServerModeDemoDataDM); /* TDataModule: File Type */
USEFORM("..\AboutDemoForm.cpp", formAboutDemo);
USEFORM("..\BaseForm.cpp", fmBaseForm);
USEFORM("ServerModeDemoMain.cpp", ServerModeDemoMainForm);
USEFORM("ServerModeDemoConnection.cpp", ServerModeDemoConnectionForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		SetApplicationMainFormOnTaskBar(Application, true);
		Application->CreateForm(__classid(TServerModeDemoConnectionForm), &ServerModeDemoConnectionForm);
		Application->CreateForm(__classid(TServerModeDemoDataDM), &ServerModeDemoDataDM);
		Application->CreateForm(__classid(TServerModeDemoMainForm), &ServerModeDemoMainForm);
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
