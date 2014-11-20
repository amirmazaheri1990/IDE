#include "StdAfx.h"
#include "Edit_function.h"

Edit_function::Edit_function(void)
{
}
Edit_function::Edit_function(Edit_word* w,Editor_variable* v, Edit_parantes * p){
	this->parantes=p;
	this->returntype=v;
	this->word=w;
}
