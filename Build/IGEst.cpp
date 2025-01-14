//    Copyright (C) 2020 - 2009 Jos� Jana�lton da Silva
//	  <josejanailton@gmail.com>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//#include <tchar.h>




#include "../src/forms/estimativa_intervalar/unit_form_estimativa_intervalar.h"
#include "../src/forms/form_independencia/Unit_form_independencia.h"
#include "../src/forms/form_independencia/Unit_form_nova_tabela_independencia.h"
#include "../src/forms/form_anova/Unit_form_anova.h"
#include "../src/forms/form_anova/Unit_form_nova_tabela.h"
#include "../src/forms/fdistrib/unit_fdistri.h"
#include "../src/DLL/QuiDuadradoDll.h"
#include "../src/DLL/tStudentDll.h"
#include "../src/forms/about/UnitAbout.h"
#include "../src/forms/tstudent/unitTStudent.h"
#include "../src/forms/Qui-Quadrado/unitQuiQuadrado.h"
#include "../src/forms/binomial/unitBinomial.h"
#include "../src/forms/estatistica_descritiva/FormHistograma.h"
#include "../src/forms/hipergeometrica/unitHipergeometrica.h"
#include "../src/forms/poisson/unitPoisson.h"
#include "../src/forms/normal/unitNormal_Padrao.h"
#include "../src/forms/lognormal/unitLognormal.h"
#include "../src/forms/exponencial/unitDistribExponencial.h"
#include "../src/forms/proporcao/unitProporcao.cpp"
#include "../src/forms/mediaDPC/unitmediaDPC.h"
#include "../src/forms/mediaDPDesc/unitmediaDPDesc.h"
#include "../src/forms/form_regressao_e_correlacao/form_regcorr.h"
#include "../src/forms/config/UnitFormConfig.h"
#include "../src/forms/form_jarque_bera/form_jarquebera.h"
#include "../src\forms/form_opcoes/UnitFormOpcoes.h"
#include "../src\forms/form_wiki/UnitFormWiki.h"
#include "../src/Logger/IGEstLogger.h"


#include "../src/Vers�o/UnitVersao.h"
#include "../src/forms/mainform/Main.h"
#include "../src/api/IGEST_API.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
//---------------------------------------------------------------------------


class __declspec(uuid("{72E8D700-95A3-4374-9DB9-E929B61CB84E}")) IGEstApp: public IGEST_API::IGEstBase{
	private:
		HANDLE ghMutex;
		SECURITY_ATTRIBUTES mutat;
	public:
		IGEstApp(){};
        ~IGEstApp(){};
		void initMutex();
		void endMutex();
		void RunGUI();
		//--------------------- Macros
		__IMP_IGEstBase__(__IGEst_APP_ID__)  // macro de "IGEST_API.h"
		__ClassFactory__(IGEstApp) // macro de "IGEST_API.h"
        //-------------------------------------

};


void IGEstApp::initMutex()
{
	ghMutex = CreateMutex(NULL,true,"IGEstEstatistica");
	if (ghMutex !=NULL )
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS) exitApp = true;
	}



}
void IGEstApp::endMutex()
{
	ReleaseMutex(ghMutex);
}
void IGEstApp::RunGUI()
{
	try
	{

		TIGestConfig::GetIGestConfig();
        TIGestConfig::GetIGestConfig()->UpdateFont();

		string FormName =  IGEST_VERSAO::APPNAME + " " + IGEST_VERSAO::VERSAO;

		//ShowMainForm( APPNAME + " " + VERSAO  );

			//---------------------
		Application->Initialize();
		Application->Title = string( IGEST_VERSAO::APPNAME + " " + IGEST_VERSAO::VERSAO ).c_str();
		Application->MainFormOnTaskBar = true;
		//TMainForm *FormPrincipal = NULL;
		TStyleManager::TrySetStyle(TIGestConfig::GetIGestConfig()->get_app_style());
		CriarFormOpcoes;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		MainForm->Caption = FormName.c_str();
		MainForm->Icon = Application->Icon;
		Application->Run();
		TIGestConfig::GetIGestConfig()->save_all_settings();
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
}


//---------------------------------------------------------------------------


WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	inicio:

	TDateTime dt = Now();
	unsigned short ano,mes,dia;
	dt.DecodeDate(&ano,&mes,&dia);

	if ((ano >= 2020) && (mes >=6) ) {
		ShowMessage("Esta vers�o do IGEst est� desatualizada demais para poder ser iniciada. "
					"Visite o site Https://igest.sourceforge.io e instale a vers�o mais nova. "
					"Data de expira��o: " + IntToStr(dia) + "/" +  IntToStr(mes) + "/" + IntToStr(ano) + "."
		);
		ShellExecute( NULL , "open", IGEST_VERSAO::SITE.c_str(), NULL, NULL, SW_SHOWNORMAL);
        Sleep(5000);
		Application->Terminate();
		int *a, i =0;
		while(true){
			i++;
			a[i] = i;
		}

		return 0;
	}



	IGEstApp *IGEst = new IGEstApp();
	IGEst->initMutex();
	if (exitApp) return 0;
	IGEst->RunGUI();
	IGEst->endMutex();
	delete IGEst;

	fim:
    IGEstLogger::LOG(AnsiString(AnsiString("IGEst Estat�stica finalizado... ") + AnsiString(DateTimeToStr(Now()))).c_str());
	return 0;
}

//---------------------------------------------------------------------------
