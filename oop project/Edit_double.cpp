#include "StdAfx.h"
#include "Edit_double.h"
Edit_double::Edit_double(void)
{
	this->type="double";
}
Edit_double::Edit_double(int start,int end,EDit_blocks* block){
	this->type="double";
	this->startindex=start;
	this->endindex=end;
	this->lenght=end-start+1;
	this->block=block;
}
Edit_double::Edit_double(Edit_word *word){
	this->type="double";
	this->startindex=word->getstartindex();
	this->endindex=word->getendindex();
	this->name=word->name;
	this->lenght=word->getlenght();
	this->block=word->block;
}
