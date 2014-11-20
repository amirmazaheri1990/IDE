#pragma once
#include "Editor_variable.h"

class Edit_void : public Editor_variable
{
public:
	Edit_void(void);
	Edit_void(int,int);
	Edit_void(Edit_word* word);
protected:
};
