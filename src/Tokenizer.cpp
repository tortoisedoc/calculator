#include "stdafx.h"
#include "Tokenizer.h"


Tokenizer::Tokenizer(std::string _id, t_token_list &_error_list):ErrorClass(_id, _error_list){}

void Tokenizer::Tokenize(std::string &_in_str, t_token_list* _tokens){
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
            case '%':
                if (temp_token.length() > 0){
                    _tokens->push_back(temp_token); //Save nr on stack
                    temp_token = "";
                }
                temp_token += *in_str_runner;
                _tokens->push_back(temp_token);
                temp_token = "";
                break;
            case'\n': //Skip newline
                break;
			default:
                log (std::string(" --> ERROR; Token not recognized ") + (*in_str_runner) + "\n");
		}
		in_str_runner++;
	}	
    if (temp_token != "")
        _tokens->push_back(temp_token);
}
