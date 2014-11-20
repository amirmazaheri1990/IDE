#include "StdAfx.h"
#include "Edit_int.h"

Edit_int::Edit_int(void)
{
	this->type="int";
}
Edit_int::Edit_int(int start,int end,EDit_blocks* block){
	this->type="int";
	this->startindex=start;
	this->endindex=end;
	this->lenght=end-start+1;
	this->block=block;
}
Edit_int::Edit_int(Edit_word *word){
	this->type="int";
	this->startindex=word->getstartindex();
	this->endindex=word->getendindex();
	this->name=word->name;
	this->lenght=word->getlenght();
	this->block=word->block;
}