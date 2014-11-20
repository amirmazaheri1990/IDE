#pragma once
#include "Edit_parantes.h"
#include "Editor_variable.h"
#include "Edit_word.h"
class Edit_function
{
public:
	Edit_function(void);
	Edit_function(Edit_word* w,Editor_variable* v,Edit_parantes* p);
	Edit_word* word;
	Editor_variable* returntype;
	Edit_parantes* parantes;
};
