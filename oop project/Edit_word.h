#pragma once
#include"string"
#include "EDit_blocks.h"
using namespace std;
class Edit_word
{
public:
	Edit_word(void);
	Edit_word(int,int);
	//void setcomment(bool);
	bool getcomment(void);
	//void setstartindex(int);
	int  getstartindex(void);
	//void setendindex(int);
	int getendindex(void);
	//void setlenght(int);
	int getlenght(void);
	string name;
	EDit_blocks* block;
protected:
	bool comment;
	int startindex;
	int endindex;
	int lenght;
};
