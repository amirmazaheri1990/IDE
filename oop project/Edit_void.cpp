#include "StdAfx.h"
#include "Edit_void.h"
Edit_void::Edit_void(void)
{
	this->type="void";
}
Edit_void::Edit_void(int start,int end){
	this->type="void";
	this->startindex=start;
	this->endindex=end;
	this->lenght=end-start+1;
}
Edit_void::Edit_void(Edit_word *word){
	this->type="void";
	this->startindex=word->getstartindex();
	this->endindex=word->getendindex();
	this->name=word->name;
	this->lenght=word->getlenght();
	this->block=word->block;
}