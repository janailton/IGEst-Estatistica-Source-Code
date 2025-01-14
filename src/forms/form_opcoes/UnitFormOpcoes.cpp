//    Copyright (C) 2020 - 2009 Jos� Jana�lton da Silva <josejanailton@gmail.com>
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

#include "UnitFormOpcoes.h"

//---------------------------------

#include "../config/UnitFormConfig.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOpcoes *FormOpcoes;
//---------------------------------------------------------------------------
__fastcall TFormOpcoes::TFormOpcoes(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormOpcoes::btnLayouClick(TObject *Sender)
{
    this->PageControlOpcoes->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormOpcoes::btnPastasClick(TObject *Sender)
{
    this->PageControlOpcoes->ActivePageIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormOpcoes::btnMaisOpcoesClick(TObject *Sender)
{
    this->PageControlOpcoes->ActivePageIndex = 2;
}
//---------------------------------------------------------------------------
void __fastcall TFormOpcoes::FormActivate(TObject *Sender)
{
	TIGestConfig::GetIGestConfig()->load_form(this);
	btnSalvar->Left = Panel2->Width - 180;
	this->ComboBoxStyle->Items->Add(TStyleManager::ActiveStyle->Name);
	this->ComboBoxStyle->Items->Add(IGEST_CONFIG::DEFAULT_STYLE);
	this->ComboBoxStyle->Items->Add(IGEST_CONFIG::NORMAL_STYLE);
	this->ComboBoxStyle->ItemIndex = 0;

	for (int i = 8; i <= 72; i++) {
		this->ComboBoxTamFont->Items->Add(IntToStr(i));
	}
	ComboBoxTamFont->ItemIndex = 0;

	//----------------------
	TStringList * list = TIGestConfig::GetIGestConfig()->get_config_list_names();
	for (int i =0; i < list->Count; i++) {
		UnicodeString valor;
		TIGestConfig::GetIGestConfig()->get_config(list->Strings[i], valor);
		ValueListEditor->Strings->AddPair(list->Strings[i], valor);

	}

	//-------------------------

	EditInstall->Text = ParamStr(0);
	EditPastaDeConfiguracao->Text = ExtractFilePath(TIGestConfig::GetIGestConfig()->inipath());
	EditPastaMateriaisDeEstudo->Text = ExtractFilePath(ParamStr(0)) + "\\pdf\\";
	btnLayouClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TFormOpcoes::ComboBoxStyleChange(TObject *Sender)
{
	TStyleManager::TrySetStyle(this->ComboBoxStyle->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormOpcoes::btnSelecFont(TObject *Sender)
{
	if (FontDialog1->Execute()) {
		this->EditFont->Text = FontDialog1->Font->Name;
		UnicodeString j = IntToStr(FontDialog1->Font->Size);

		ComboBoxTamFont->Items->Clear();
		ComboBoxTamFont->Items->Add(j);
		for (int i = 8; i <= 72; i++) {
			this->ComboBoxTamFont->Items->Add(IntToStr(i));
		}
	ComboBoxTamFont->ItemIndex = 0;

	ColorBoxFont->Selected = FontDialog1->Font->Color;

		
		if (IGEST_CONFIG::ConfigFont == NULL) {
			IGEST_CONFIG::ConfigFont = new TFont();
		}
		IGEST_CONFIG::ConfigFont->Assign(FontDialog1->Font);
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormOpcoes::ComboBoxTamFontChange(TObject *Sender)
{
	if (IGEST_CONFIG::ConfigFont == NULL) {
		IGEST_CONFIG::ConfigFont = new TFont();
	}

	IGEST_CONFIG::ConfigFont->Size = StrToInt(ComboBoxTamFont->Text);		
}
//---------------------------------------------------------------------------

void __fastcall TFormOpcoes::ColorBoxFontChange(TObject *Sender)
{
	if (IGEST_CONFIG::ConfigFont == NULL) {
		IGEST_CONFIG::ConfigFont = new TFont();
	}

	IGEST_CONFIG::ConfigFont->Color = ColorBoxFont->Selected;	
}
//---------------------------------------------------------------------------

void __fastcall TFormOpcoes::FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight,
          bool &Resize)
{
	Resize = ((NewWidth >1000) && (NewHeight >550));
}
//---------------------------------------------------------------------------

void __fastcall TFormOpcoes::FormResize(TObject *Sender)
{
    btnSalvar->Left = Panel2->Width - 180;
}
//---------------------------------------------------------------------------



void __fastcall TFormOpcoes::FormDeactivate(TObject *Sender)
{
    TIGestConfig::GetIGestConfig()->save_form(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormOpcoes::btnSalvarClick(TObject *Sender)
{
	try
	{
		TIGestConfig::GetIGestConfig()->set_app_style(ComboBoxStyle->Text);
		TIGestConfig::GetIGestConfig()->set_config("StatisticalFontName", EditFont->Text);
		TIGestConfig::GetIGestConfig()->set_config("StatisticalFontSize", ComboBoxTamFont->Text);
		TIGestConfig::GetIGestConfig()->set_config("StatisticalFontColor", IntToStr(ColorBoxFont->Selected));
        TIGestConfig::GetIGestConfig()->save_all_settings();
		ShowMessage("As cofigura��es foram salvas!");
	}
	catch (...)
	{
		ShowMessage("Erro ao salvar as configura��es!");
	}

}
//---------------------------------------------------------------------------


void __fastcall TFormOpcoes::FormShow(TObject *Sender)
{
    btnLayouClick(this);
}
//---------------------------------------------------------------------------

