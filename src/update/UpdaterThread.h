//    Copyright (C) 2010, 2009 Jos� Jana�lton da Silva
//		<josejanailton@gmail.com>
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

#ifndef __Updater_Thread_H__
#define __Updater_Thread_H__

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "IGEST_API.h"
//---------------------------------------------------------------------------

class TUpdater : public TThread
{
private:
protected:
	virtual void __fastcall Execute();
public:
	__fastcall TUpdater(bool CreateSuspended);
};

//---------------------------------------------------------------------------

#endif
