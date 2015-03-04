#include "stdafx.h"
#include "Tokenizer.h"


Tokenizer::Tokenizer(void):m_tokens("()0123456789+-/*\x04"){
}


Tokenizer::~Tokenizer(void){
}

void Tokenizer::Tokenize(std::string &_in_str, t_string_list* _tokens){	
	std::string::iterator in_str_runner = _in_str.begin();
	std::string temp_token = "";
	while (in_str_runner != _in_str.end()){
		switch(*in_str_runner){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				temp_token+=(*in_str_runner);
				break;
			case '(':
			case ')':
			case '+':
			case '-':
			case '/':
			case '*':
			case '\x04':
			case ' ':
				if (temp_token != ""){
					_tokens->push_back(temp_token);				
				}
				if ((*in_str_runner) != ' '){
					temp_token = (*in_str_runner);
					_tokens->push_back(temp_token);
					temp_token = "";
				}
				break;
			default:
				std::cout << " ERROR; Token not recognized " << (*in_str_runner);
		}
		//_tokens->push_back(
		in_str_runner++;
	}	
}