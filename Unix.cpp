#include <iostream>
#include <string>
#include <unistd.h>

int main(){
    bool run = true;
    while(run){
        std::cout << "mini-shell> ";
        std::string i = "";
        if (!std::getline(std::cin, i)){
            break;
        }

    if(i == "quit" || i == "exit" || i == "close"){
        run = false;
    }
    }
    return 0;
}