// calc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "Tokenizer.h"
#include "Parser.h"


bool is_eof(wchar_t _in_char){
    return _in_char == '\x04';
}

int main(int argc, char* argv[]){

	bool stop = false;
    t_token_list token_list;
    std::list<std::string> error_list;
	std::string temp_input("");
    Tokenizer * tokenizer = new Tokenizer("Tokenizer", error_list);
    Parser * parser = new Parser("Parser", error_list);

	while (!stop){
        char temp[200] = { 0 };

        do{
            int readed = read(0, temp, 200);
            temp_input = temp;            
            stop = (temp_input.rfind("\n") == std::string::npos) || (readed == 0);
            if (!stop){
                error_list.clear(); //Clear error list
                tokenizer->Tokenize(temp_input, &token_list);
                if (!stop){
                    parser->Parse(&token_list);
                    if (error_list.size() > 0){
                        std::cout << "Errors :\n";
                        while (error_list.size() > 0){
                            std::cout << "\t->" << error_list.front() << "\n";
                            error_list.pop_front();
                        }
                    }
                }
            }
        }while (!stop);
	}
	return 0;
}

