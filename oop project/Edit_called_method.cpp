#include "StdAfx.h"
#include "Edit_called_method.h"

Edit_called_method::Edit_called_method(void)
{
	this->function=NULL;
}



bool Edit_called_method::Is_int(string val)
{
	int len = val.length();
	for(int i = 0; i < len; i++)
	{
		if(!System::Char::IsDigit(val[i]))
			return false;
	}
	return true;
}

bool Edit_called_method::Is_float(std::string val)
{
	int len = val.length();
	bool fp = false;

	for(int i = 0; i < len; i++)
	{
		if(!System::Char::IsDigit(val[i]) && val[i] != '.')
			return false;

		if(val[i] == '.' && !fp)
		{
			fp = true;
		}
		else if(val[i] == '.' && fp)
		{
			return false;
		}
	}

	return true;
}

bool Edit_called_method::Is_char(std::string val)
{
	int len = val.length();
	
	if(len != 3)
		return false;
	
	if(val[0] != val[2] || val[2] != '\'')
		return false;

	return true;
}

string Edit_called_method::Type_name(string val)
{
	if(Is_int(val))
		return "int";
	else if(Is_float(val))
		return "double";
	else if(Is_char(val))
		return "char";
	else
		return "unknown";
}



Edit_called_method::Edit_called_method(int start, int end,vector<Edit_word*>  &words,vector<Editor_variable*>  &variable,vector<Edit_function*> &functions){
	this->function=NULL;
	this->parantes=new Edit_parantes();
	//this->generated=0;
	this->word= words[start-1];
	myreturn="void";
	Editor_variable* variable1;
	string s;
	for(int i=start;i<end+1;i++){
		if( words[i]->name==","|| words[i]->name==")"){
			s=Type_name( words[i-1]->name);
			if(s=="int"){
				variable1=new Edit_int( words[i-1]);
				this->parantes->variables.push_back(variable1);
				continue;
			}
			if(s=="double"){
				variable1=new Edit_double( words[i-1]);
				this->parantes-> variables.push_back(variable1);
				continue;
			}
			if(s=="char"){
				variable1=new Edit_char( words[i-1]);
				this->parantes-> variables.push_back(variable1);
				continue;
			}
			if(s=="unknown"){
				for(int j=0;j< variable.size();j++){
					if(( words[i-1]->block== variable[j]->block|| variable[j]->block==NULL)&& words[i-1]->name== variable[j]->name){
						variable1= variable[j];
						this->parantes-> variables.push_back(variable1);
						break;
					}
				}
			}
		}
	}
	int point=start-1;
	int count;
	int count2;
	int point2;
	while(point>-1&&point< words.size()&&( words[point]->name!=";"&& words[point]->name!="="&& words[point]->name!="<"&& words[point]->name!=","&&words[point]->name!="(")){
		point--;
	}
	if(point>0&& words[point]->name=="="){
		point--;
		if(words[point]->name=="+"||words[point]->name=="/"||words[point]->name=="-"||words[point]->name=="*") point--;
		for(int i=0;i< variable.size();i++){
			if( words[point]->name== variable[i]->name&&( words[point]->block== variable[i]->block|| variable[i]->block==NULL)){
				myreturn= variable[i]->type;
				break;
			}
		}
	}
	else if(point>0&& words[point]->name=="<"){
		myreturn="int";
	}
	else if(point>0&& words[point]->name==";"){
		myreturn="void";
	}
	//else if(point>0&&(words[point]->name==","||words[point]->name=="(")){
	//	count=0;
	//	count2=0;
	//	point2=point;
	//	int amirmaz_count=0;
	//	while(amirmaz_count<100&&point>-1&& words[point]->name!="("){////khatar khatar khatar
	//		amirmaz_count++;
	//		if( point+1<words.size()&&(words[point]->name==","||words[point+1]->name==")")){////////////khatar khatar khatar
	//			count++;
	//			point--;
	//		}
	//	}
	//	point--;
	//	while(point2<words.size()&&words[point2]->name!=")"){
	//	//	if(words[point2]->name==","/*||words[point2+1]->name==")"*/){////////////////////ezafe shod khatar
	//			count2++;
	//			point2++;
	//	//	}
	//	}
	//	for(int i=0;i<functions.size();i++){
	//		if(functions[i]->word->name==words[point]->name&&functions[i]->parantes->variables.size()==count+count2+1){
	//			myreturn=functions[i]->parantes->variables[count]->type;
	//			break;
	//		}
	//	}
	//}
	/*else if(point>0&& words[point]->name=="("){
		count=0;
		count2=0;
		point2=point;
		point--;
		while(point2<words.size()&&words[point2]->name!=")"){
			if(words[point2]->name==","){
				count2++;
				point2++;
			}
		}
		for(int i=0;i<functions.size();i++){
			if(functions[i]->word->name==words[point]->name&&functions[i]->parantes->variables.size()==count+count2+1){
				myreturn=functions[i]->parantes->variables[count]->type;
				break;
			}
		}
	}*/
	else myreturn="void";
	bool found=0;
	for(int i=0;i<functions.size();i++){
		found=0;
		if(words[start-1]->name==functions[i]->word->name){
			if(this->parantes->variables.size()==functions[i]->parantes->variables.size()){
				found=1;
				for(int j=0;j<functions[i]->parantes->variables.size();j++){
					if(functions[i]->parantes->variables[j]->type!=this->parantes->variables[j]->type){
						found=0;
						break;
					}
				}
				if(found==1){
					this->function=functions[i];
					break;
				}
				else continue;
			}
		}
	}
return;
}

