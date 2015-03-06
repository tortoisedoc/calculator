#include "Errorclass.h"

ErrorClass::ErrorClass(std::string _title, t_token_list &_error_list)
    :m_title(_title),m_errors(&_error_list){
}


void ErrorClass::log(std::string _msg){
    m_errors->push_back(m_title + std::string(" --- ") + _msg);
}
