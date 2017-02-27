//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------




USEFORM("..\AboutDemoForm.cpp", formAboutDemo);
USEFORM("ServerModeDemoConnection.cpp", ServerModeDemoConnectionForm);
USEFORM("..\BaseForm.cpp", fmBaseForm);
USEFORM("ServerModeDemoData.cpp", ServerModeDemoDataDM);
USEFORM("ServerModeDemoMain.cpp", ServerModeDemoMainForm);
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
