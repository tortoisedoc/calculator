
#include "stdafx.h"
#include "Parser.h"
#include "utils.h"
#include <istream>
#include <cmath>

Parser::Parser(std::string _id, t_token_list &_error_list):ErrorClass(_id, _error_list){
}


Parser::~Parser(void){
}

void Parser::Parse(t_token_list* list){
    while (list->size() > 0){
       std::cout << this->ParseExpression(list) << "\n";
    }
}


t_token Parser::PopList(t_token_list *_token_list){
    t_token token = _token_list->front();
    _token_list->pop_front();
    return token;
}

int Parser::ParseNumber(t_token_list * _token_list){
    t_token number_token = this->PopList(_token_list);
    std::istringstream convertor(number_token);
    int conv_nr;
    if (convertor >> conv_nr)
        return conv_nr;
    else{
        log(t_token("Error : Value ") + number_token + t_token(" is not a valid number"));
        return 0;
    }
}

int Parser::ParseExpression(t_token_list * _token_list){
    if (_token_list->size() > 0){
        int first_nr = this->ParseTerm(_token_list);
        t_token operation = "";
        if (_token_list->size() > 0){
            if (Utils::IsInSet("+-", _token_list->front())){ //Check for + / -
                operation = this->PopList(_token_list);
                if (!operation.compare("+")){
                    return first_nr + this->ParseTerm(_token_list);;
                }else if (!operation.compare("-")){
                    return first_nr - this->ParseTerm(_token_list);;
                }
            }
        }
        return first_nr; //Only one Term
    }else{
        log(t_token ("Error : Empty expression"));
        return 0;
    }
}

int Parser::ParseTerm(t_token_list * _token_list){
    if (_token_list->size() > 0){
        int first_factor = this->ParseFactor(_token_list);
        if (_token_list->size() > 0){
            if (Utils::IsInSet("/*%", _token_list->front())){ //Check if correct multiplication operation is present
                t_token operation = this->PopList(_token_list);
                if (!operation.compare("/")){
                    int dividend = this->ParseFactor(_token_list);
                    if (dividend != 0){
                        float div_result = (float)first_factor / (float)dividend;
                        return floor(div_result);
                    }
                    else{
                        log(t_token ("Error : Division by 0"));
                        return 0;
                    }
                }else if (!operation.compare("%")){
                    return first_factor % this->ParseFactor(_token_list);;
                }else if (!operation.compare("*")){
                    return first_factor * this->ParseFactor(_token_list);;
                }
            }else{
                return first_factor; //This is not a MUL operation
            }
        }else{
            return first_factor; //Only one factor
        }
    }
    log(t_token ("Error : Syntax error, Empty Term"));
    return 0;
}

int Parser::ParseFactor(t_token_list * _token_list){
    if (_token_list->size() > 0){
        if (!_token_list->front().compare("(")){ //look-ahead rulez
            _token_list->pop_front();
            int result = this->ParseExpression(_token_list);
            if (_token_list->size() > 0){
                t_token last_token = this->PopList(_token_list);
                if (last_token.compare(")")){
                    log(t_token ("Error : Missing Closing Bracket! Found instead ") + last_token);
                    return 0;
                }
                return result;
            }else{
                log(t_token ("Error : Missing Closing Bracket!"));
                return 0;
            }
        }else if (!_token_list->front().compare("-")){
            this->PopList(_token_list);
            if (_token_list->size() > 0)
                return -1*this->ParseFactor(_token_list);
            else{
                log(t_token ("Error : Syntax of negative number is wrong, missing number"));
                return 0;
            }
        }else return this->ParseNumber(_token_list);
    }else{
        log(t_token ("Error : Empty Factor"));
        return 0;
    }
}

