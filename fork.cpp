#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
int main(){
    //create child process
    pid_t pid = fork();

    if(pid == -1){
        std::cerr<< "fork failed\n";
        return 1;
    }
    else if(pid == 0){
        std::cout<< "I am the child!\n";
        //String - Automatically adds null terminating character
        char command[] = "ls";
        //&command, nullptr
        char* args[] = {command, nullptr};

        execvp(command, args);
        perror("execvp");
        _exit(1);
    }
    else{
        waitpid(pid,nullptr,0);
        std::cout << "I am the parent\n";
    }
    std::cout << "forked return " << pid << "\n";
    return 0;
}