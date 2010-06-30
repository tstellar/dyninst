/*
 * Copyright (c) 1996-2009 Barton P. Miller
 * 
 * We provide the Paradyn Parallel Performance Tools (below
 * described as "Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <stdio.h>

#include <vector>
#include <string>

#include "symtabAPI/h/Symtab.h"
#include "addrtranslate.h"

using namespace std;

namespace Dyninst {
namespace SymtabAPI {

class AddressTranslateStatic : public AddressTranslate
{
public:
   virtual bool init();
   virtual bool refresh();
   AddressTranslateStatic(PID pid);
};

}
}

using namespace Dyninst;
using namespace SymtabAPI;

AddressTranslate *AddressTranslate::createAddressTranslator(PID pid_, ProcessReader *, PROC_HANDLE)
{
	AddressTranslateStatic *new_translate = new AddressTranslateStatic(pid_);
	return new_translate;
}

AddressTranslate *AddressTranslate::createAddressTranslator(ProcessReader *)
{
	return createAddressTranslator(0, NULL);
}

bool AddressTranslateStatic::init()
{
	return true;
}

bool AddressTranslateStatic::refresh()
{
	return true;
}

vector< pair<Address, unsigned long> > *LoadedLib::getMappedRegions()
{
   return &mapped_regions;
}

AddressTranslateStatic::AddressTranslateStatic(PID pid) :
	AddressTranslate(pid)
{
}

Symtab *LoadedLib::getSymtab()
{
   return NULL;
}

AddressTranslate *AddressTranslate::createAddressTranslator(const std::vector<LoadedLibrary> & /*name_addrs*/)
{
   return NULL;
}

ProcessReader::ProcessReader(int pid_, string exe) :
   pid(pid_), executable(exe)
{
}

ProcessReader::ProcessReader() :
   pid(0)
{
}