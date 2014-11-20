#pragma once
#include "Editor_variable.h"
class Edit_float : public Editor_variable
{
public:
	Edit_float(void);
	Edit_float(int,int,EDit_blocks*);
	Edit_float(Edit_word* word);
};
