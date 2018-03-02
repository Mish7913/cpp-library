/** Copyright 2018 Mish7913 <Mish7913@gmail.com> **/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */
 
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

#include <string.h>

namespace str {
	std::wstring str_to_wstr(const std::string& s) {
		std::string curLocale = setlocale(LC_ALL, ""); const char* ch_source = s.c_str();
		size_t     ch_dsize    =    mbstowcs    (NULL,     ch_source,     0)     +     1;
		wchar_t * ch_dest = new wchar_t  [ch_dsize];  wmemset ( ch_dest,  0,  ch_dsize );
		mbstowcs (ch_dest,  ch_source,  ch_dsize);   std::wstring   result   =   ch_dest;
		delete [] ch_dest;   setlocale  ( LC_ALL,   curLocale.c_str() );  return  result;
	}

	std::string wstr_to_str(const std::wstring& ws) {
		std::string curLocale = setlocale(LC_ALL, ""); const wchar_t* ch_source = ws.c_str();
		size_t   ch_dsize   =   wcstombs   (  NULL,    (wchar_t*)  ch_source, 0  )    +    1;
		char  *  ch_dest    =   new char [ch_dsize];   memset(  ch_dest,    0,    ch_dsize );
		wcstombs (ch_dest, (wchar_t*) ch_source,  ch_dsize);  std::string result  =  ch_dest;
		delete [] ch_dest;   setlocale(  LC_ALL,   curLocale.c_str()  );    return    result;
	}
}
