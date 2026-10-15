#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
#include <string>

int main(){
    while(true){
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
        char* args[] = {command.data(), nullptr};

        execvp(args[0], args);
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