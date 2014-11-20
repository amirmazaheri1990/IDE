#pragma once
//#include "Form1.h"
//class Form1;
class EDit_blocks
{
public:
	EDit_blocks(void);
	EDit_blocks(int s_p,int e_p,int s_b,int e_b);
	EDit_blocks(int s_b,int e_b);
	EDit_blocks* getrefrence(void);
	int getstart_p(void);
	int getend_p(void);
	int getstart_b(void);
	int getend_b(void);
	int start_b;//shoorooe block
	int end_b;//paiane block
private:
	int start_p;//shorooe parantes
	int end_p;//paiane parantes
	//int start_b;//shoorooe block
	//int end_b;//paiane block
};
