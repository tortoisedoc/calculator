#pragma once
#include "stdafx.h"
#include <list>

class Parser
{
private:
	int m_return_value;
public:
	Parser(void);
	~Parser(void);
	bool Parse(t_string_list * list);
};

