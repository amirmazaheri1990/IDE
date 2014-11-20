#include "stdafx.h"
#include "Editor_core.h"

Editor_core::Editor_core(void)
{
	EDit_blocks* myblock;
	myblock=new EDit_blocks(0,0,-1,-1);
	blocks.push_back(myblock);////////////in tikke baraie blocke parantes haie prototype ha mibashad
}
Editor_core::Editor_core(string str1){
	this->blocks.clear();
	this->variable.clear();
	this->paranteses.clear();
	this->words.clear();
	EDit_blocks* myblock;
	myblock=new EDit_blocks(0,0,-1,-1);
	blocks.push_back(myblock);////////////in tikke baraie blocke parantes haie prototype ha mibashad
	for(int i=0;i<str1.size();i++){ 
		if(i<str1.size()&&str1[i]=='"'){
			while(i>1&&i+1<str1.size()&&str1[i-1]!='"'){
				i++;
			}
		}  
		else if(i+1<str1.size()&&str1[i]=='/'&&str1[i+1]=='/'){ 
			i+=2; 
			while(i-1<str1.size()&&str1[i]!='\n') { 
				i++; 
			} 
		} 
		else if(i+1<str1.size()&&str1[i]=='/'&&str1[i+1]=='*'){ 
			i+=2; 
			while(i-2<str1.size()&&str1[i-2]!='*'&&str1[i-1]!='/') {
				i++; 
			} 
		} 

		else str.push_back(str1[i]); 
		while(str.size()<i+1) str.push_back(' ');
	}
	int mys1=str1.size();
	int mys2=str.size();
	int point=0;
	int point2=0;
	char baz='{';
	char baste='}';
	EDit_blocks* block;
	int size=str.length();
	int block_count=0;
	while(point<str.length()&&point2<str.length()){
		block_count=0;
		while(point<str.length()&&str[point]!=baz){
			point++;
		}
		block_count=1;
		point2=point+1;
		if (point<str.length()-1){
			while(point<str.length()&&point2<str.length()&&block_count!=0){
				if(str[point2]=='{') block_count++;
				if(str[point2]=='}') block_count--;
				point2++;
			}
			//delete block;
			block=new EDit_blocks(point,point2-1);
			blocks.push_back(block);
			point=point+1;

		}
	}
	//////////block haro shenasayi kardim///////////////////////////////////////////////////
	/////////////kalame haro she na she na sayi khahim kard/////////////////////////////////
	point=0;
	point2=0;
	Edit_word* word;
	while(point<str.length()&&point2<str.length()){
		while(point<str.length()&&(str[point]==' '||str[point]=='	'||str[point]=='\n'||str[point]=='\r')){
			point++;
		}
		point2=point;
		if(str[point]==NULL)break;
		while(point2<str.length()&&str.at(point2)!='('&&str.at(point2)!=')'&&str.at(point2)!='*'&&str.at(point2)!='&'
			&&str.at(point2)!='%'&&str.at(point2)!='!'&&str.at(point2)!='{'&&str.at(point2)!='}'
			&&str.at(point2)!='['&&str.at(point2)!=']'&&str.at(point2)!='"'&&str.at(point2)!=';'
			&&str.at(point2)!=':'&&str.at(point2)!='/'&&str.at(point2)!='?'//&&str.at(point2)!='.'
			&&str.at(point2)!='>'&&str.at(point2)!=','&&str.at(point2)!='<'&&str.at(point2)!='`'
			&&str.at(point2)!='~'&&str.at(point2)!=' '&&str.at(point2)!='\n'&&str.at(point2)!='\r'
			&&str.at(point2)!='|'&&str.at(point2)!='+'&&str.at(point2)!='='&&str.at(point2)!='	'){
				point2++;

		}
		//delete word;
		if(point2!=point){
			word=new Edit_word(point,point2-1);
			for(int i=point;i<point2;i++){
				word->name+=str[i];
			}
			this->words.push_back(word);
		}
		if(point2<str.length()&&(str.at(point2)=='('||str.at(point2)==')'||str.at(point2)=='*'||str.at(point2)=='&'
			||str.at(point2)=='%'||str.at(point2)=='!'||str.at(point2)=='{'||str.at(point2)=='}'
			||str.at(point2)=='['||str.at(point2)==']'||str.at(point2)=='"'||str.at(point2)==';'
			||str.at(point2)==':'||str.at(point2)=='/'||str.at(point2)=='?'//||str.at(point2)=='.'
			||str.at(point2)=='>'||str.at(point2)==','||str.at(point2)=='<'||str.at(point2)=='`'
			||str.at(point2)=='~'||str.at(point2)=='|'||str.at(point2)=='+'||str.at(point2)=='=')){
				word=new Edit_word(point2,point2);
				word->name+=str[point2];
				this->words.push_back(word);
		}
		point2++;
		point=point2;
	}
	///paiane iaftane kalameha///////////////////////////////////////////////////////////////////
	//////////////////iaftane blocke kalameha////////////////////////////
	for(int i=0;i<words.size();i++){
		for(int j=blocks.size()-1;j>-1;j--){
			if(blocks[j]->getstart_b()<words[i]->getstartindex()&&blocks[j]->getend_b()>words[i]->getendindex()){
				words[i]->block=blocks[j];
				break; 
			}
			//else words[i]->block==NULL;
		}
	}
	//////////////iaftane blocke kalameha////////////////////////////////
	//////iaftane moteghaierha///////////////////////////////////////////////////////////////////
	this->set_paranteses(this->words);
	this->set_varaibles_func(str);
	this->set_called_methods(words);
}
void Editor_core::set_paranteses(vector <Edit_word*> A){
	int counter = 0, point1, point2;
	Edit_parantes* parantes;
	EDit_blocks* block;
	for( unsigned int i = 0; i < A.size(); i++ )
	{
		if( i<A.size()&&A[i]->name == "(" )
		{
			point1 = i;
			do{
				//words.push_back(A[i]);
				if( A[i]->name == "(" )
					counter++;
				if( A[i]->name == ")" )
					counter--;
				i++;
			}while(i < A.size() && counter != 0 );
			if( i < A.size() && ((A[i]->name == "{") || (A[i]->name == ";" && point1 > 1 
				&& (A[point1-2]->name == "int" || A[point1-2]->name == "double" 
				|| A[point1-2]->name == "float" || A[point1-2]->name == "char" 
				|| A[point1-2]->name == "void" ))))
			{
				point2 = i;
				if( A[point2]->name == "{" )
				{
					for( unsigned int j = 0; j < blocks.size(); j++ )
						if( blocks[j]->getstart_b() > point2 )
						{
							block = blocks[j];
							//delete parantes;
							parantes = new Edit_parantes(A, point1, point2, block);
							this->paranteses.push_back(parantes);
						}
				}
				else
				{
					//delete parantes;
					parantes = new Edit_parantes(A, point1, point2);
					parantes->block=this->blocks[0];//blocke in goone prototype hara blocke shomare sefr gharar midahim
					this->paranteses.push_back(parantes);
				}
			}
			i--;
		}
	}
}
int Editor_core::Comment_line(int line, string& str)
{
	int line4=line;
	int k = 0;
	int index= -1;
	int len = str.length();

	for(int i = 0; i < len; i++)
	{
		if(str[i] == '\n')
			k++;

		if(k == line)
		{
			index = i;
			break;
		}
	}

	if(index == -1)
		return 0;
	if(index == 0)
		index = -1;

	str.insert(index+1, "//");

	return 2;
}

int Editor_core::Uncomment_line(int line, string& str)
{
	int counter = 0;
	int k = 0;
	int index = -1;
	int len = str.length();

	for(int i = 0; i < len; i++)
	{
		if(str[i] == '\n')
			k++;

		if(k == line)
		{
			index = i;
			break;
		}
	}

	//index = (index == 0) ? -1 : index;
	if( index != 0 )
		index++;
	while( str[index] == ' ' || str[index] == '	' )
		index++;
	/*if( str[index] == '/' )
	{
	while( index+1 < str.size() && str[index] == '/' && str[index+1] == '/' )
	{
	str.erase(str.begin() + index);
	counter--;
	if( index+1 < str.size() && str[index] == '/' && str[index+1] != '/' && str[index+1] !='*' )
	{
	str.erase(str.begin() + index);
	counter--;
	break;
	}
	}
	break;
	}*/
	if( str[index] == '/' && str[index+1] == '/' )
	{
		str.erase( index, 2 );
	}
	else if( str[index] == '/' && str[index+1] == '/' && str[index+2] == '/' )
	{
		str.erase( index, 3 );
	}

	/*while(str[++index] != '\n')
	{
	if(str[index] != ' ' && str[index] != '/')
	break;
	str.erase(str.begin() + index);
	index--;
	}*/

	return counter;
}

int Editor_core::Comment_multiline(int from, int to, string& str)
{
	int counter = 0;
	for(int i = from; i <= to; i++)
	{
		counter += Editor_core::Comment_line(i, str);

	}
	return counter;
}
int Editor_core::Uncomment_multiline(int from, int to, string& str)
{
	int counter = 0;
	for(int i = from; i <= to; i++)
	{
		counter += Editor_core::Uncomment_line(i, str);
	}
	return counter;
}
int Editor_core::tabular(string& str)
{
	int count=0;
	int counter = 0, counter2 = 0;
	for( unsigned int i = 0; i < str.size(); i++ )
	{
		for(int j=0;j<i;j++){///////////
			if(str[j]=='(') ///////
				count++;//////////
			if(str[j]==')') //////////
				count--;///////
		}	///////////
		if( ((count==0&&str[i] == ';') || str[i] == '{' ) && i+1 < str.size() && str[i+1] != '\n')
			str.insert( i+1, "\r\n" );

	}
	for( unsigned int i = 0; i < str.size(); i++ )
	{
		if( str[i] == '}' )
			counter--;
		if( str[i] == '\n' && i+1 < str.size() )
		{
			while( str[i+1] == '	' || str[i+1] == ' ' )
			{
				str.erase( str.begin() + i+1 );
				counter2--;
			}
			if( str[i+1] == '}' )
				counter--;
			for( int k = 0; k < counter; k++, i++ )
			{
				str.insert(i+1, "\t");
				counter2++;
			}
			if( str[i+1] == '}' )
				counter++;
		}
		if( str[i] == '{' )
			counter++;
	}
	return counter2;
}
void Editor_core::set_varaibles_func(string str){
	int size=words.size();
	Editor_variable* variable1;
	Edit_function* func;
	for(int i=0;i<size;i++){
		if(words[i]->name=="("){
			while(i<size&&words[i]->name!=")"){
				i++;
			}
			continue;
		}
		else if(words[i]->name=="int"&&i+2<size){/////////1111111111111
			if(words[i+2]->name=="("){
				for(unsigned int j=0;j<this->paranteses.size();j++){
					if(i+2==paranteses[j]->point1){
						variable1=new Edit_int();
						func=new Edit_function(words[i+1],variable1,paranteses[j]);
						this->functions.push_back(func);
						break;
					}
				}
				i+=2;
				while(i<size&&words[i]->name!=")"){
					i++;
				}
				continue;
			}
			else if(i+2<size&&(words[i+2]->name==";"||words[i+2]->name=="["||words[i+2]->name=="="||words[i+2]->name==")")){
				variable1=new Edit_int(words[i+1]);//////222222222222222222222222222222222222222
				this->variable.push_back(variable1);
			}
			else if(i+2<size&&(words[i+2]->name==",")){
				while(i+2<size&&(words[i+2]->name!="="||words[i+2]->name!=";"||words[i+2]->name!="[")){
					if (words[i]->name=="="||words[i]->name=="["||words[i]->name==";") break;
					variable1=new Edit_int(words[i+1]);/////////////33333333333333333333333333
					this->variable.push_back(variable1);
					i+=2;
				}
			}
		}
		else if(words[i]->name=="char"&&i+2<size){/////////1111111111111
			if(words[i+2]->name=="("){
				for(unsigned int j=0;j<this->paranteses.size();j++){
					if(i+2==paranteses[j]->point1){
						variable1=new Edit_char();
						func=new Edit_function(words[i+1],variable1,paranteses[j]);
						this->functions.push_back(func);
						break;
					}
				}
				i+=2;
				while(i<size&&words[i]->name!=")"){
					i++;
				}
				continue;
			}
			else if(i+2<size&&(words[i+2]->name==";"||words[i+2]->name=="["||words[i+2]->name=="="||words[i+2]->name==")")){
				variable1=new Edit_char(words[i+1]);//////222222222222222222222222222222222222222
				this->variable.push_back(variable1);
			}
			else if(i+2<size&&(words[i+2]->name==",")){
				while(i+2<size&&(words[i+2]->name!="="||words[i+2]->name!=";"||words[i+2]->name!="[")){
					if (words[i]->name=="="||words[i]->name=="["||words[i]->name==";") break;
					variable1=new Edit_char(words[i+1]);/////////////33333333333333333333333333
					this->variable.push_back(variable1);
					i+=2;
				}
			}
		}
		else if(words[i]->name=="double"&&i+2<size){/////////1111111111111
			if(words[i+2]->name=="("){
				for(unsigned int j=0;j<this->paranteses.size();j++){
					if(i+2==paranteses[j]->point1){
						variable1=new Edit_double();
						func=new Edit_function(words[i+1],variable1,paranteses[j]);
						this->functions.push_back(func);
						break;
					}
				}
				i+=2;
				while(i<size&&words[i]->name!=")"){
					i++;
				}
				continue;
			}
			else if(i+2<size&&(words[i+2]->name==";"||words[i+2]->name=="["||words[i+2]->name=="="||words[i+2]->name==")")){
				variable1=new Edit_double(words[i+1]);//////222222222222222222222222222222222222222
				this->variable.push_back(variable1);
			}
			else if(i+2<size&&(words[i+2]->name==",")){
				while(i+2<size&&(words[i+2]->name!="="||words[i+2]->name!=";"||words[i+2]->name!="[")){
					if (words[i]->name=="="||words[i]->name=="["||words[i]->name==";") break;
					variable1=new Edit_double(words[i+1]);/////////////33333333333333333333333333
					this->variable.push_back(variable1);
					i+=2;
				}
			}
		}
		else if(words[i]->name=="float"&&i+2<size){/////////1111111111111
			if(words[i+2]->name=="("){
				for(unsigned int j=0;j<this->paranteses.size();j++){
					if(i+2==paranteses[j]->point1){
						variable1=new Edit_float();
						func=new Edit_function(words[i+1],variable1,paranteses[j]);

						this->functions.push_back(func);
						break;
					}
				}
				i+=2;
				while(i<size&&words[i]->name!=")"){
					i++;
				}
				continue;
			}
			else if(i+2<size&&(words[i+2]->name==";"||words[i+2]->name=="["||words[i+2]->name=="="||words[i+2]->name==")")){
				variable1=new Edit_float(words[i+1]);//////222222222222222222222222222222222222222
				this->variable.push_back(variable1);
			}
			else if(i+2<size&&(words[i+2]->name==",")){
				while(i+2<size&&(words[i+2]->name!="="||words[i+2]->name!=";"||words[i+2]->name!="[")){
					if (words[i]->name=="="||words[i]->name=="["||words[i]->name==";") break;
					variable1=new Edit_float(words[i+1]);/////////////33333333333333333333333333
					this->variable.push_back(variable1);
					i+=2;
				}
			}
		}

		else if(words[i]->name=="void"&&i+2<size){/////////1111111111111
			if(words[i+2]->name=="("){
				for(unsigned int j=0;j<this->paranteses.size();j++){
					if(i+2==paranteses[j]->point1){
						variable1=new Edit_void();
						func=new Edit_function(words[i+1],variable1,paranteses[j]);
						this->functions.push_back(func);
						break;
					}
				}
				i+=2;
				while(i<size&&words[i]->name!=")"){
					i++;
				}
				continue;
			}
		}

	}
	for(unsigned int i=0;i<this->paranteses.size();i++){
		for(unsigned int j=0;j<paranteses[i]->variables.size();j++){
			this->variable.push_back(this->paranteses[i]->variables[j]);
		}
	}

	return;
}
void Editor_core::set_called_methods(std::vector<Edit_word*> words){
	int point;
	int count=0;
	bool truth=1;
	Edit_called_method* method;
	for(int i=0;i<words.size();i++){
		count=0;
		if(words[i]->name=="("){
			if(i-2>-1&&(words[i-2]->name=="int"||words[i-2]->name=="char"||words[i-2]->name=="void"||words[i-2]->name=="double"||words[i-2]->name=="float"))
				continue;
			count=1;
			truth=1;
			point=i;
			i++;
			while(truth==1&&i<words.size()&&count!=0){
				if(i<words.size()&&(words[i]->name==";"||words[i]->name=="|"||words[i]->name=="&")){
					truth=0;
					break;
				}
				else if(words[i]->name=="("){
					count++;
					i++;//havaset bashe
				}
				else if(words[i]->name==")"){
					count--;
					i++;//havaset bashe
				}
				else  i++;
			}
			i--;//havaset bashe............
			if(i<words.size()&&words[i]->name==")"&&truth!=0){
				method=new Edit_called_method(point,i,words,variable,functions);
				this->called_methods.push_back(method);
			}
		}
	}
	for(int i=0;i<this->called_methods.size();i++){
		if(called_methods[i]->word->name=="do"||called_methods[i]->word->name=="if"||called_methods[i]->word->name=="while"
			||called_methods[i]->word->name=="for"){
				called_methods.erase(called_methods.begin()+i);
				i--;
		}
	}	
	return;
}