#ifndef ERRORCLASS_H
#define ERRORCLASS_H

#include "stdafx.h"

class ErrorClass
{
protected:
    std::string m_title;
    t_token_list* m_errors;
public:
    ErrorClass(std::string _title, t_token_list &_error_list);
    void log (std::string _msg);
};

#endif // ERRORCLASS_H
