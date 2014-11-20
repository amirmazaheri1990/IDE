#include "StdAfx.h"
#include "Edit_parantes.h"

Edit_parantes::Edit_parantes(void)
{
}
Edit_parantes::Edit_parantes(vector<Edit_word*> words, int index1, int index2, EDit_blocks* block)
{
	point1 = index1;
	point2 = index2;
	Editor_variable* variable;
	for( int i = index1; i < index2; i++ )
	{
		if(i+1<words.size() && words[i]->name == "int" )
		{
			//delete variable;
			variable = new Edit_int(words[i+1]);
			this->variables.push_back(variable);
		}
		if( i+1<words.size() &&words[i]->name == "double" )
		{
			variable = new Edit_double(words[i+1]);
			this->variables.push_back(variable);
		}
		if(i+1<words.size() && words[i]->name == "char" )
		{
			variable = new Edit_char(words[i+1]);
			this->variables.push_back(variable);
		}
		if(i+1<words.size() && words[i]->name == "float" )
		{
			variable = new Edit_float(words[i+1]);
			this->variables.push_back(variable);
		}
	}
	for( int j = 0; j < this->variables.size(); j++ )
	{
		variables[j]->block = block;
	}
}
Edit_parantes::Edit_parantes(vector<Edit_word*> words, int index1, int index2)
{
	point1 = index1;
	point2 = index2;
	Editor_variable* variable;
	for( int i = index1; i < index2; i++ )
	{
		if(i+1<words.size() && words[i]->name == "int" )
		{
			//delete variable;
			variable = new Edit_int(words[i+1]);
			if(words[i+1]->name==","||words[i+1]->name==")"||words[i+1]->name==";"||words[i+1]->name=="|") variable->name="";
			this->variables.push_back(variable);
		}
		if( i+1<words.size() &&words[i]->name == "double" )
		{
			variable = new Edit_double(words[i+1]);
			if(words[i+1]->name==","||words[i+1]->name==")"||words[i+1]->name==";"||words[i+1]->name=="|") variable->name="";
			this->variables.push_back(variable);
		}
		if(i+1<words.size() && words[i]->name == "char" )
		{
			variable = new Edit_char(words[i+1]);
			if(words[i+1]->name==","||words[i+1]->name==")"||words[i+1]->name==";"||words[i+1]->name=="|") variable->name="";
			this->variables.push_back(variable);
		}
		if(i+1<words.size() && words[i]->name == "float" )
		{
			variable = new Edit_float(words[i+1]);
			if(words[i+1]->name==","||words[i+1]->name==")"||words[i+1]->name==";"||words[i+1]->name=="|") variable->name="";
			this->variables.push_back(variable);
		}
	}

}
Edit_parantes::Edit_parantes(string str,EDit_blocks* block,int start=0,int end=0){
	int point;
	Editor_variable* variable;
	this->block=block;
	for(int i=0;i<str.size();i++){
		if((str[i]==' '||str[i]=='	'||str[i]=='('||str[i]==',')&&str[i+1]=='i'&&str[i+2]=='n'&&str[i+3]=='t'&&(str[i+4]==' '||str[i+4]=='	')){///////////inja
			i+=4;
			while((str[i]==' '||str[i]=='	')&&i<str.size()){
				i++;
			}
			point=i;
			while(i<str.size()&&str[i]!=' '&&str[i]!='	'&&str[i]!=')'&&str[i]!=';'&&str[i]!='/n'){
				i++;
			}
			delete variable;
			variable=new Edit_int(start+point,end+i-1,block);////////////////inja
			this->variables.push_back(variable);
		}
		if((str[i]==' '||str[i]=='	'||str[i]=='('||str[i]==',')&&str[i+1]=='d'&&str[i+2]=='o'&&str[i+3]=='u'&&str[i+4]=='b'&&str[i+5]=='l'&&str[i+6]=='e'&&(str[i+7]==' '||str[i+7]=='	')){///////////inja
			i+=4;
			while((str[i]==' '||str[i]=='	')&&i<str.size()){
				i++;
			}
			point=i;
			while(i<str.size()&&str[i]!=' '&&str[i]!='	'&&str[i]!=')'&&str[i]!=';'&&str[i]!='/n'){
				i++;
			}
			delete variable;
			variable=new Edit_double(start+point,end+i-1,block);////////////////inja
			this->variables.push_back(variable);
		}
		if((str[i]==' '||str[i]=='	'||str[i]=='('||str[i]==',')&&str[i+1]=='c'&&str[i+2]=='h'&&str[i+3]=='a'&&str[i+4]=='r'&&(str[i+5]==' '||str[i+5]=='	')){///////////inja
			i+=4;
			while((str[i]==' '||str[i]=='	')&&i<str.size()){
				i++;
			}
			point=i;
			while(i<str.size()&&str[i]!=' '&&str[i]!='	'&&str[i]!=')'&&str[i]!=';'&&str[i]!='/n'){
				i++;
			}
			delete variable;
			variable=new Edit_char(start+point,end+i-1,block);////////////////inja
			this->variables.push_back(variable);
		}
		if((str[i]==' '||str[i]=='	'||str[i]=='('||str[i]==',')&&str[i+1]=='f'&&str[i+2]=='l'&&str[i+3]=='o'&&str[i+4]=='a'&&str[i+5]=='t'&&(str[i+6]==' '||str[i+6]=='	')){///////////inja
			i+=4;
			while((str[i]==' '||str[i]=='	')&&i<str.size()){
				i++;
			}
			point=i;
			while(i<str.size()&&str[i]!=' '&&str[i]!='	'&&str[i]!=')'&&str[i]!=';'&&str[i]!='/n'){
				i++;
			}
			delete variable;
			variable=new Edit_float(start+point,end+i-1,block);////////////////inja
			this->variables.push_back(variable);
		}

	}
}
