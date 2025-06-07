#include <iostream>
#include <unistd.h>
void display_ASCII()
{
    std::cout << R"(

__________               __ ___________.__         _________        .__               .__          __                
\______   \____  _______/  |\_   _____/|__|__  ___ \_   ___ \_____  |  |   ____  __ __|  | _____ _/  |_  ___________ 
 |     ___/  _ \/  ___/\   __\    __)  |  \  \/  / /    \  \/\__  \ |  | _/ ___\|  |  \  | \__  \\   __\/  _ \_  __ \
 |    |  (  <_> )___ \  |  | |     \   |  |>    <  \     \____/ __ \|  |_\  \___|  |  /  |__/ __ \|  | (  <_> )  | \/
 |____|   \____/____  > |__| \___  /   |__/__/\_ \  \______  (____  /____/\___  >____/|____(____  /__|  \____/|__|   
                    \/           \/             \/         \/     \/          \/                \/                   

)" << std::endl; //raw string literal
std::cout<<"AUTHOR: ADI TAUQIR"<<endl;
}
void display_ASCII_help()
{
    std::cout << R"(

 _   _      _       
| | | | ___| |_ __  
| |_| |/ _ \ | '_ \ 
|  _  |  __/ | |_) |
|_| |_|\___|_| .__/ 
             |_|    

)" <<"\n " << std::endl;
}
void version()
{
    std::cout<< "v1.0.0" << std::endl;
}

void clear()
{
    std::cout << "\x1B[2J\x1B[H";
}



int help()
{   
    clear();
    display_ASCII_help();
    version();
    std::cout<<"This is a postfix calculator.\nYou need to type an infix (normal) problem using ^, *, -, + or /.\nFor bugs and reports, create a pull request :3.\n" "\nType 'e' to exit.\n" "\n";
    char exit_code;
    std::cin>> exit_code;
    while (1==1)
    {
        if(tolower(exit_code)== 'e')
        {   
            std::cout<<"Returning back to main...."<<std::endl;
            usleep(1070900);
            std::cout<<"\x1b[1A"<<"\x1b[1A";
            std::cout << "\x1b[2K";
            std::cout<<"\r";
            return 505;
        }
        else
        {
            std::cout<<"Error: Please type 'e' to exit"<<std::endl;
        }
    }
    return 0;
}