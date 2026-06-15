#include <iostream>
#include <map>
#include "Solutions.h"
using namespace std;
typedef void (*func)();

void get_int_between(int& d, int min, int max, std::string prompt, std::string fail);
void get_int(int& d, std::string prompt, std::string fail);
int main() {
   map<int, func> questions;
   questions[1] = question1;
    questions[2] = question2;
    questions[3] = question3;
    questions[4] = question4;
    questions[5] = question5;
    questions[6] = question6;
    questions[7] = question7;
    questions[8] = question8;
    questions[9] = question9;
    questions[10] = question10;
    questions[11] = question11;
    questions[12] = question12;
    questions[13] = question13;

    int choice = 0;
    string temp;
    do {
        get_int_between(choice, -1,13,"Please enter question number to run, -1 to end\n", "Invalid input.\n");

        if(questions.count(choice))
        {
           questions[choice]();
        }
        else
        {
            cout << "invalid input."<<endl;
        }
        cout << endl;
    }while(choice!=-1);




    return 0;
}

void get_int(int& d, string prompt, string fail)
{
    while(1) {

        cout << prompt;
        string str;
        getline(cin, str);

        istringstream ss(str);
        int val1;
        ss >> val1;

        if(!ss.eof()) {
           cout << fail;
            continue;
        } else {
            d = val1;
            break;
        }
    }
}

void get_int_between(int& d, int min, int max, string prompt, string fail)
{
    while(1) {
        get_int(d, prompt, fail);
        if(d > max || d < min) {
            std::cout << "Sorry, your choice is out of range.\n";
            continue;
        }
        break;
    }
}