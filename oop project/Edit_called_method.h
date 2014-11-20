#pragma once
#include "Edit_word.h"
#include"Edit_function.h"
#include <vector>
using namespace std;
class Edit_called_method : public Edit_function
{
public:
	Edit_called_method(void);
	Edit_called_method(int start,int end,vector<Edit_word*> &words,vector<Editor_variable*> &variable,vector<Edit_function*> &functions);
	//bool generated;
	Edit_function* function;
	string myreturn;///in string ra man hads mizanam va agar tabe define shode bood ghablan aslan kari be in nadarim.....
	string Type_name(string val);
	bool Is_int(string val);
	bool Is_float(string val);
	bool Is_char(string val);
};
