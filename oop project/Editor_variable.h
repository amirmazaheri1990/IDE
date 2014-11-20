#pragma once
#include "Edit_word.h"
#include "Editor_variable.h"
#include "string"
using namespace std;
class Editor_variable : public Edit_word
{
public:
	Editor_variable(void);
	Editor_variable(Edit_word*);
	Editor_variable(int,int,EDit_blocks*);
	string gettype(void);
	EDit_blocks* getblock(void);
//protected:
	EDit_blocks* block;
	string type;
};