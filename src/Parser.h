#pragma once
#include "stdafx.h"
#include "Errorclass.h"

class Parser: public ErrorClass
{
private:
    t_token PopList(t_token_list * _token_list);
    bool isInSet(std::string _set, t_token _token);
    bool isAddOp(char _digit);
    int ParseNumber(t_token_list * _token_list);
    int ParseAddOp(t_token_list * _token_list);
    int ParseExpression(t_token_list * _token_list);
    int ParseTerm(t_token_list * _token_list);
    int ParseFactor(t_token_list * _token_list);
public:
    Parser(t_token_list &_error_list);
	~Parser(void);
    void Parse(t_token_list * list);
};

