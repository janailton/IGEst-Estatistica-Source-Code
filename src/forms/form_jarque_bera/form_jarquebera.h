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

#ifndef form_jarqueberaH
#define form_jarqueberaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Tabs.hpp>
#include <TabNotBk.hpp>
#include <Graphics.hpp>


#include <Buttons.hpp>
#include <Dialogs.hpp>

//#include "../../lib/libeylan/Regressao_Correlacao.h"
#include <Grids.hpp>
#include <ValEdit.hpp>

#include <vector>

//---------------------------------------------------------------------------
class Tfrm_jarque_bera : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditX;
	TButton *btnAdicionar;
	TButton *btnExcluir;
	TButton *btnCalcular;
	TButton *btnExcluirTudo;
	TGroupBox *GroupBox2;
	TMemo *Memo1;
	TListBox *ListBox1;
	TGroupBox *GroupBox3;
	TLabel *Label3;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TMemo *Memo2;
	TLabel *Label4;
	TButton *btnSalvarDados;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog1;
	TButton *btnCarregarDados;
    void __fastcall FormShow(TObject *Sender);
	void __fastcall btnExcluirClick(TObject *Sender);
    void __fastcall btnExcluirTudoClick(TObject *Sender);
	void __fastcall btnAdicionarClick(TObject *Sender);
	void __fastcall btnCalcularClick(TObject *Sender);
	void __fastcall EditXKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall btnSalvarDadosClick(TObject *Sender);
	void __fastcall btnCarregarDadosClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:

public:		// User declarations
	__fastcall Tfrm_jarque_bera(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_jarque_bera *frm_jarque_bera;
//---------------------------------------------------------------------------

Tfrm_jarque_bera *frm_jarque_bera;

void __fastcall ShowFormJarqueBera()
{
	Tfrm_jarque_bera *Frmjarque_bera = new Tfrm_jarque_bera(Application);
	Frmjarque_bera->Visible = false;
	Frmjarque_bera->ShowModal();
    Frmjarque_bera->Free();
}


#endif
