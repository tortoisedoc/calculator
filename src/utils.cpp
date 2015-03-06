#include "stdafx.h"
#include "utils.h"

bool Utils::IsInSet(const std::string _set, t_token _token){
    return _set.find(_token) != std::string::npos;
}
