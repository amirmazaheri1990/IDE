#pragma once
#include "Editor_variable.h"
class Edit_int : public Editor_variable
{
public:
	Edit_int(void);
	Edit_int(int,int,EDit_blocks*);
	Edit_int(Edit_word* word);
protected:
};
