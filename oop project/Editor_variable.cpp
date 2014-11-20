#include "StdAfx.h"
#include "Editor_variable.h"

Editor_variable::Editor_variable(void){
	//this->block==NULL;
}
Editor_variable::Editor_variable(int start, int end,EDit_blocks* Block){
	this->startindex=start;
	this->endindex=end;
	this->lenght=end-start+1;
	this->block=Block;
}
Editor_variable::Editor_variable(Edit_word* word){
	//this->block==NULL:
	this->startindex=word->getstartindex();
	this->endindex=word->getendindex();
	this->name=word->name;
	this->lenght=word->getlenght();
	this->block=word->block;
}
string Editor_variable::gettype(void){
	return this->type;
}
EDit_blocks* Editor_variable::getblock(void){
	return this->block;
}