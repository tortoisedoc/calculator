#ifndef ERRORCLASS_H
#define ERRORCLASS_H

#include "stdafx.h"

class ErrorClass
{
protected:
    t_token_list* m_errors;
public:
    ErrorClass(t_token_list &_error_list);
};

#endif // ERRORCLASS_H
