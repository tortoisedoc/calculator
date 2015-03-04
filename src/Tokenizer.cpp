#include "stdafx.h"
#include "Tokenizer.h"


Tokenizer::Tokenizer(void):m_tokens("()0123456789+-/*"){
}


Tokenizer::~Tokenizer(void){
}

void Tokenizer::Tokenize(std::string &_in_str, t_string_list* _tokens){	
	std::string::iterator in_str_runner = _in_str.begin();
	while (in_str_runner != _in_str.end()){
		//if (!m_tokens.find((*in_str_runner)))
		//_tokens->push_back(
		in_str_runner++;
	}	
}