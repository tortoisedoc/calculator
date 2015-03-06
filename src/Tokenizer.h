#pragma once
#include "stdafx.h"
#include "Errorclass.h"

class Tokenizer: public ErrorClass
{
public:
    Tokenizer(std::string _id, t_token_list &_error_list);
    void Tokenize(std::string &_in_str, t_token_list * _tokens);
};

