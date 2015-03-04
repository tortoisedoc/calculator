#pragma once
#include "stdafx.h"

class Tokenizer
{
private:
	std::string m_tokens;
public:
	Tokenizer(void);
	void Tokenize(std::string &_in_str, t_string_list * _tokens);
	~Tokenizer(void);
};

