#include <iostream>
#include "mathematical.h"
#include "graphicshandler.h"
#include <algorithm>

int main(){
    display_ASCII();
    string choice;

while (1==1)
{
    choice.empty();
    cout << "\n" "\nType:\n - (q)uit to exit\n - (h)elp for help\n - (e) for entering the equation\n - (x) or 'cls' to clear screen.\n" "" << endl;    
    getline(cin, choice);
    choice.erase(remove_if(choice.begin(), choice.end(), [](unsigned char x) { return std::isspace(x); }), choice.end());
    if (tolower(choice[0]) == 'e')
    {   
        string x;
        cout<<"Enter an equation: ";
        getline(cin,x); //this will read spaces
        double result= the_main_stuff(x);
        if (result == 505){cout<<"Error occured, please try again. Check (h)elp for reference";continue;}
        else{cout << "RESULT: "<< result<<endl;}
        x.empty();
        continue;
    }
    else if(tolower(choice[0]) == 'q' || choice == "quit") 
    {
        break;
    }
    else if ((tolower(choice[0]) == 'h' || choice == "help") ) 
    {   int exitpls=help();
        if (exitpls==505)
        {   
            clear();
            display_ASCII();
            continue;}
    }
    else if ((tolower(choice[0]))== 'x' || choice == "cls")
    {
        clear();
        display_ASCII();
    }
} //end of loop

    return 0;
}