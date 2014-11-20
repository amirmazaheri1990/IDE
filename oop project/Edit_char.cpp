#include "StdAfx.h"
#include "Edit_char.h"

Edit_char::Edit_char(void)
{
	this->type="char";
}
Edit_char::Edit_char(int start, int end,EDit_blocks* block){
	this->type="char";
	this->startindex=start;
	this->endindex=end;
	this->lenght=end-start+1;
	this->block=block;
}
Edit_char::Edit_char(Edit_word *word){
	this->type="char";
	this->startindex=word->getstartindex();
	this->endindex=word->getendindex();
	this->name=word->name;
	this->lenght=word->getlenght();
	this->block=word->block;
}