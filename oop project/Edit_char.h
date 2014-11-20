#pragma once
#include "Editor_variable.h"
class Edit_char : public Editor_variable
{
public:
	Edit_char(void);
	Edit_char(int,int,EDit_blocks*);
	Edit_char(Edit_word* word);
};
