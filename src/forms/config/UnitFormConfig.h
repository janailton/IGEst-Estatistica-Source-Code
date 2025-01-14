//    Copyright (C) 2019 Jos� Jana�lton da Silva <josejanailton@gmail.com>
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

//---------------------------------------------------------------------------

#ifndef UnitFormConfigH
#define UnitFormConfigH

#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mem.h>
#include <time.h>
#include <limits.h>
#include <vcl.h>
#include <tchar.h>

#include <System.hpp>
#include <System.Actions.hpp>
#include <System.Classes.hpp>
#include <System.ImageList.hpp>

#include <System.StrUtils.hpp>
#include <System.SyncObjs.hpp>
#include <System.SysUtils.hpp>
#include <System.Threading.hpp>

#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
#include <Vcl.OleCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Styles.hpp>
#include <Vcl.HtmlHelpViewer.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Registry.hpp>

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>

#include <windows.h>
#include <FileCtrl.hpp>
#include <IniFiles.hpp>
#include <SHDocVw.hpp>
#include <VersionHelpers.h>
#include <tlhelp32.h>
#include <map>
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>

#pragma hdrstop

// Exit app
bool __declspec(uuid("{2717E95F-4C43-4617-BF59-D66836AB47F4}")) exitApp = false;

#ifndef nullptr
    #define nullptr NULL
#endif

#ifdef USE_LOCKBOX
	#include <lbClass.hpp>
	#pragma comment(lib, "LockBoxCR.lib")
    #include <XMLDoc.hpp>
	#include <Xml.XMLDoc.hpp>
	#include <Xml.XMLIntf.hpp>
	#include <Vcl.ComCtrls.hpp>
	#pragma comment(lib, "xmlrtl.lib")
	#include "..\..\lib\eylan-hardware-api\HardwareUtils.h"
	#include "..\..\lib\eylan-hardware-api\MakeHash.h"
	using namespace Xmlintf;
#endif

namespace IGEST_CONFIG{
	const PATH_MAX = 255;
	const char GUID_01[40] = "{B446EA7F-6633-4278-8E88-4D58B1A9BDAD}\0";
	const UnicodeString TabCores[] = {"Azul", "Vermelho", "Amarelo"};
	const UnicodeString DEFAULT_STYLE = "Iceberg Classico";
	const UnicodeString NORMAL_STYLE = "Windows";

	const HKEY IGEST_REG_RootKey = HKEY_CURRENT_USER ;
	const UnicodeString IGEST_REG_SubKey = "Software\\IGEst\\Config\\";
	const UnicodeString IGEST_REG_SETTINGS_SubKey = "Software\\IGEst\\Settings\\";

    TFont *ConfigFont = NULL;
}


class TIGestConfig {
	protected:
		std::map<UnicodeString,UnicodeString> mapSettings;
		TIGestConfig();
		void save_mapSettings();
		void load_mapSettings();
		bool SetRegistrySettings(const UnicodeString pacName, const UnicodeString pacValue);
		UnicodeString GetRegistrySettings(const UnicodeString pacName);
		TStringList *_mConfigListNames;

#ifdef USE_LOCKBOX
		TLbBlowfish *bf;
		TLbRijndael *rjan;
		_hash ConfigHash;
        UnicodeString strHash;
		void save_to_xml();
#endif
	public:
		~TIGestConfig();
		// Usar essa fun��o no lugar do construtor da classe  TIGestConfig
		static TIGestConfig* GetIGestConfig();
		UnicodeString inipath();
		const UnicodeString AppIGESTHomePath;
		void save_form(TForm *FormToSave);
		void load_form(TForm *FormToLoad);
		void save_string(AnsiString file, AnsiString text);

		UnicodeString GetRegistryPath(void);
		UnicodeString GetRegistry(const UnicodeString pacName);
		bool SetRegistry(const UnicodeString pacName, const UnicodeString pacValue);

		void set_config(UnicodeString info, UnicodeString val);
		bool get_config(UnicodeString info, UnicodeString &val);
		const UnicodeString get_app_style();
		void set_app_style(UnicodeString app_style);
		void save_all_settings();
		TStringList *get_config_list_names();
        void UpdateFont();

};


//---------------------------------------------------------------------------
#endif
