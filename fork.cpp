#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

int main(){
    while(true){
    std::cout << "myshell> " << std::flush;
    std::string command;
    if(!std::getline(std::cin, command)){
        return 0;
    }
    if (command == "exit" || command == "quit") {
    break;
}
    //create child process
    pid_t pid = fork();
    if(pid == -1){
        std::cerr<< "fork failed\n";
        return 1;
    }
    else if(pid == 0){
    
        std::istringstream iss(command);
        std::string token;
        std::vector<std::string> tokens;
        while(iss >> token){
            tokens.push_back(token);
        }
        std::vector<char*> args;
        for (std::string& t : tokens){
        args.push_back(t.data());
        }

        args.push_back(nullptr);
        execvp(args[0], args.data());
        //if execution reaches this line, that means execvp failed.
        perror("execvp");
        _exit(1);
    }
    
    else{
        waitpid(pid,nullptr,0);
    }
    std::cout << "forked return " << pid << "\n";
}
    return 0;

}