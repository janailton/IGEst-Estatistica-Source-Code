//    Copyright (C) 2009 Jos� Jana�lton da Silva <josejanailton@gmail.com>
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

#ifndef unitPoissonH
#define unitPoissonH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormPoisson : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TEdit *EditX;
    TLabel *Label2;
    TEdit *EditLambda;
	TGroupBox *GroupBox2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton5;
	TGroupBox *GroupBox3;
	TButton *Button1;
	TLabel *Label4;
	TEdit *EditResultado;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormPoisson(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPoisson *FormPoisson;
//---------------------------------------------------------------------------

TFormPoisson *FormPoisson;

void __fastcall ShowFormPoisson()
{
    TFormPoisson *FormPoisson = new TFormPoisson(Application);
    FormPoisson->Visible = false;
    FormPoisson->ShowModal();
    FormPoisson->Free();
}

#endif
