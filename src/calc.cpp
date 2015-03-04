// calc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tokenizer.h"
#include "Parser.h"

int _tmain(int argc, _TCHAR* argv[]){

	bool stop = false;
	t_string_list token_list;
	std::string temp_input("");
	Tokenizer * tokenizer = new Tokenizer();
	Parser * parser = new Parser();

	while (!stop){
		std::getline(std::cin, temp_input);
		tokenizer->Tokenize(temp_input, &token_list);
		stop = parser->Parse(&token_list);
	}
	return 0;
}

