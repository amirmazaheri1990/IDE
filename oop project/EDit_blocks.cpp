#include "StdAfx.h"
#include "EDit_blocks.h"

EDit_blocks::EDit_blocks(void)
{

}
EDit_blocks::EDit_blocks(int s_p, int e_p, int s_b, int e_b ){
	this->start_b=s_b;
	this->end_b=e_b;
	this->end_p=e_p;
	this->start_p=s_p;
}
EDit_blocks::EDit_blocks(int s_b, int e_b){
	this->start_b=s_b;
	this->end_b=e_b;
	this->end_p=0;
	this->start_p=0;
}
EDit_blocks* EDit_blocks::getrefrence(void){
	return this;
}
int EDit_blocks::getend_b(void){
	return this->end_b;
}
int EDit_blocks::getend_p(void){
	return this->end_p;
}
int EDit_blocks::getstart_b(void){
	return this->start_b;
}
int EDit_blocks::getstart_p(void){
	return this->start_p;
}