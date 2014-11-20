#pragma once
#include"EDit_blocks.h"
#include"Edit_word.h"
//#include <vector>
#include "Editor_variable.h"
#include "Edit_int.h"
#include"Edit_char.h"
#include "Edit_double.h"
#include"Edit_float.h"
#include"Edit_void.h"
#include"Edit_parantes.h"
#include<string>
#include "Edit_function.h"
#include "Edit_called_method.h"

using namespace std;


class Editor_core
{
public:
	Editor_core(void);
	Editor_core(string);
	void set_varaibles_func(string);
	void set_paranteses(vector <Edit_word*>);
	void set_called_methods(vector<Edit_word* >word);
	int Comment_line(int line,string&);
	int Comment_multiline(int from, int to,string&);
	int Uncomment_line(int,string&);
	int Uncomment_multiline(int, int,string&);
	int tabular(string&);
	string str;
	vector<EDit_blocks*> blocks;
	vector<Edit_word*> words;
	vector<Editor_variable*> variable;
	vector<Edit_parantes*> paranteses;
	vector<Edit_function*> functions;
	vector<Edit_called_method*> called_methods;
};
