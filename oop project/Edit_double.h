#pragma once
#include"Editor_variable.h"
class Edit_double : public Editor_variable
{
public:
	Edit_double(void);
	Edit_double(int,int,EDit_blocks*);
	Edit_double(Edit_word* word);
protected:
};
