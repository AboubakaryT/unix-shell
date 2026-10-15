#include <iostream>
#include <string>
#include <unistd.h>

int main(){
    bool run = true;
    while(run){
        std::cout << "mini-shell> ";
        std::string input = "";
        if (!std::getline(std::cin, input)){
            break;
        }

    if(input == "quit" || input == "exit" || input == "close"){
        run = false;
    }
    }
    return 0;
}