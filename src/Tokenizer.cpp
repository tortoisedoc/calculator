#include "stdafx.h"
#include "Tokenizer.h"
#include "utils.h"

Tokenizer::Tokenizer(std::string _id, t_token_list &_error_list):ErrorClass(_id, _error_list){}

void Tokenizer::Tokenize(std::string &_in_str, t_token_list* _tokens){
    std::string::iterator in_str_runner = _in_str.begin();
    std::string temp_token = "";

    while (in_str_runner != _in_str.end()){
        const std::string op_set = "()+-/*%";
        const std::string numbers_set = "0123456789";
        std::string value;
        value = (*in_str_runner);

        if (Utils::IsInSet(numbers_set, value)){
            temp_token+=(*in_str_runner);
        }
        else if (Utils::IsInSet(op_set, value)){
            if (temp_token.length() > 0){
                _tokens->push_back(temp_token); //Save nr on stack
                temp_token = "";
            }
            temp_token += *in_str_runner;
            _tokens->push_back(temp_token);
            temp_token = "";
        }else if (*in_str_runner != '\n'){
            log (std::string(" --> ERROR; Token not recognized :'") + (*in_str_runner) + "'\n");
		}
		in_str_runner++;
	}	
    if (temp_token != "")
        _tokens->push_back(temp_token);
}
