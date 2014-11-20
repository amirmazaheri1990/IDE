#include "StdAfx.h"
#include "Edit_float.h"
Edit_float::Edit_float(void)
{
	this->type="float";
}
Edit_float::Edit_float(int start,int end,EDit_blocks* block){
	this->type="float";
	this->startindex=start;
	this->endindex=end;
	this->lenght=end-start+1;
	this->block=block;
}
Edit_float::Edit_float(Edit_word *word){
	this->type="float";
	this->startindex=word->getstartindex();
	this->endindex=word->getendindex();
	this->name=word->name;
	this->lenght=word->getlenght();
	this->block=word->block;
}