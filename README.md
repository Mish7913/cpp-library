# C++ library 7913.
**GNU General Public License** library for C++.

## str.h
```cpp
#include <iostream>
#include "str.h"

int main (){
  std::string text = "Hello";
  
  // convert string to wstring.
  std::wstring wstr = str::str_to_wstr(text);
  std::wcout << wstr << std::endl;
  
  // convert wstring to string.
  std::string str = str::wstr_to_str(wstr);
  std::cout << str << std::endl;
  
}
```
