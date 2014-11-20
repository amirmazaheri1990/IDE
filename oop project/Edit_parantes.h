#pragma once
#include <vector>
#include "Editor_variable.h"
#include "EDit_blocks.h"
#include"Edit_char.h"
#include"Edit_double.h"
#include"Edit_float.h"
#include"Edit_int.h"
#include"Edit_void.h"
using namespace std;
class Edit_parantes
{
public:
	int point1, point2;
	Edit_parantes(vector <Edit_word*>, int, int, EDit_blocks* block );
	Edit_parantes(vector <Edit_word*>, int, int );
	Edit_parantes(void);
	Edit_parantes(string str,EDit_blocks* block,int start,int end);
	vector<Editor_variable*> variables;
	EDit_blocks* block;	
};
