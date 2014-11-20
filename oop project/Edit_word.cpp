#include "StdAfx.h"
#include "Edit_word.h"

Edit_word::Edit_word(void)
{
	this->block==NULL;
	this->name="";
	this->comment=0;
	this->startindex=0;
	this->endindex=0;
}

Edit_word::Edit_word(int start,int end){
	this->block=NULL;
	this->comment=0;
	this->startindex=start;
	this->endindex=end;
	this->lenght=end-start+1;
	this->name="";	
}
bool Edit_word::getcomment(void){
	return this->comment;
}
int Edit_word::getendindex(void){
	return this->endindex;
}
int Edit_word::getstartindex(void){
	return this->startindex;
}
int Edit_word::getlenght(void){
	return this->lenght;
}
