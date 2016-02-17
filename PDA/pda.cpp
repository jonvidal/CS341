//
//  p2_15f_jkv5.cpp
//
//
//  Created by Jonathan Vidal on 9/17/15.
//  Copyright (c) 2015 Jonathan Vidal. All rights reserved.
//
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <stack>
#include <stdlib.h>
using namespace std;

enum state //enum to defined each state and the status
{
    Q1,
    Q2,
    Q3,
    Q4,
    Q5,
    Q6,
    Q7,
    Q8,
    Q9,
    Q10,
    ERROR,
    TEMP_ERROR
};

void display(state currstat); //function to display
state pda(char c, state currstat); // function on PDA
state pda_stack(char x, state currstat); // fuction of stack

void rd_letter(string in_str) // function that read every character
{
    state currstat=Q1; // initial state
    state temp;
    cout << "\nIn start state Q1" <<endl; // must read $ to start
    for (unsigned int i = 0; i<in_str.length(); i++)
    {
        char lett = in_str[i]; //string to char array
        currstat = pda(lett, currstat);
        if (currstat!=ERROR){
            switch (currstat){
                case Q1: //ignore
                    break;
                case TEMP_ERROR: //ignore
                    break;
                case Q2:
                    cout << "Read: " << lett <<" | ";     // printing what is read
                    temp = pda_stack(lett, currstat);  // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){            // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes ";
                        i=in_str.length();            // exit the loop and function when the PDA crashes
                    }
                    cout << "In state Q2";
                    cout << endl;
                    break;
                case Q3:
                    cout << "Read: " << lett << " | "; // printing every character
                    temp = pda_stack(lett, currstat);       // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){                // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes ";
                        i=in_str.length();              // return the current state and display PUSHED or POPPED on the stack
                    }
                    cout << "In state Q3";
                    cout << endl;
                    break;
                case Q4:
                    cout << "Read: " << lett <<" | "; // printing every character
                    temp = pda_stack(lett, currstat);       // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){             // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes ";
                        i=in_str.length();          // return the current state and display PUSHED or POPPED on the stack
                    }
                    cout << "In state Q4";
                    cout << endl;
                    break;
                case Q5:
                    cout << "Read: " << lett <<" | "; // printing every character
                    temp = pda_stack(lett, currstat);       // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){                 // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes ";
                        i=in_str.length();          // return the current state and display PUSHED or POPPED on the stack
                    }
                    cout << "In state Q5";
                    cout << endl;
                    break;
                case Q6:
                    cout << "Read: " << lett <<" | "; // printing every character
                    temp = pda_stack(lett, currstat);       // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){                 // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes ";
                        i=in_str.length();          // return the current state and display PUSHED or POPPED on the stack
                    }
                    cout << "In state Q6";
                    cout << endl;
                    break;
                case Q7:
                    cout << "Read: " << lett <<" | "; // printing every character
                    temp = pda_stack(lett, currstat);       // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){             // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes ";
                        i=in_str.length();          // return the current state and display PUSHED or POPPED on the stack
                    }
                    cout << "In state Q7";
                    cout << endl;
                    break;
                case Q8: // acceptance state
                    cout << "Read: " << lett << " | "; // printing every character
                    temp = pda_stack(lett, currstat);       // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){                 // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes ";
                        i=in_str.length();         // return the current state and display PUSHED or POPPED on the stack
                    }
                    cout << "In state Q8";
                    cout << endl;
                    break;
                case Q9:
                    cout << "Read: " << lett <<" | "; // printing every character
                    temp = pda_stack(lett, currstat);       // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){                 // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes ";
                        i=in_str.length();      // return the current state and display PUSHED or POPPED on the stack
                    }
                    cout << "In state Q9";
                    cout << endl;
                    break;
                case Q10:
                    cout << "Read: " << lett <<" | "; // printing every character
                    temp = pda_stack(lett, currstat);       // return the current state and display PUSHED or POPPED on the stack
                    if (temp == TEMP_ERROR){                 // if the stack is empty and POPPED something the PDA should crash
                        cout << "\nPDA Crashes";
                        i=in_str.length();          // return the current state and display PUSHED or POPPED on the stack
                    }
                    cout << "In state Q10";
                    cout << endl;
                    break;
                case ERROR: // ignore
                    break;
            }
        }
            else {
                cout << "Read: " << lett << "\nPDA Crashes"; // crashes when read someting in state witout any edge
                break;
            }

    }

    display(currstat);
}

stack<char> mystack; //global stack
state pda_stack(char x, state currstat){
    if (x=='$'&&currstat==Q2){
        cout << "Popped: (epsilon) | ";
        mystack.push(x);        // pushing the $ on the stack
        cout << "Pushed: " << mystack.top() << " | ";
        return currstat;
    }
    else if (x=='('&&currstat==Q4){
        cout << "Popped: (epsilon) | ";
        mystack.push(x);  // pushing the open parenthesis
        cout << "Pushed: " << mystack.top() << " | ";
        return currstat;
    }
    else if (x==')'&&currstat==Q5){     // if read close parenthesis then popped the open parenthesis on the stack
        cout << "Popped: " << mystack.top() << " | "; //print what is in the top of the stack
        mystack.pop();  // and pop it
        cout << "Pushed: (epsilon) | ";
        return currstat;
    }
    else if ((x=='+'||x=='-'||x=='*'||x=='/')&&currstat==Q6){
        cout << "Popped: (epsilon) | ";
        mystack.push(x);  // pushing the operator to avoid '+-' (two operator together)
        cout << "Pushed: " << mystack.top() << " | ";
        return currstat;
    }
    else if ((x!='+'&&x!='-'&&x!='*'&&x!='/'&&x!='('&&x!=')')&&currstat==Q9&&(mystack.size()>=1)){ // if read a string from Q6 must popped the operator
        cout << "Popped: " << mystack.top() <<" | ";
        mystack.pop();
        cout << "Pushed: (epsilon) | ";
        return currstat;
    }
    else if (x==')'&&currstat==Q7&&(mystack.size()>=1)&&mystack.top()=='('){ // if read close parenthesis then popped the open parenthesis on the stack
        cout << "Popped: " << mystack.top() << " | ";
        mystack.pop();
        cout << "Pushed: (epsilon) | ";
        return currstat;
    }
    else if (x==')'&&currstat==Q9&&(mystack.size()>=1)){ // if read close parenthesis then popped the open parenthesis on the stack
        cout << "Popped: " << mystack.top() << " | ";
        mystack.pop();
        cout << "Pushed: (epsilon) | ";
        return currstat;
    }
    else if (x=='$'&&currstat==Q8&&(mystack.size()>=1)&&mystack.top()=='$'){  // in order to accept the string it must end with the dollar sign
        cout << "Popped: " << mystack.top() << " | ";
        mystack.pop();
        cout << "Pushed: (epsilon) | ";
        return currstat;
    }
    else if ((x!='+'&&x!='-'&&x!='*'&&x!='/'&&x!='('&&x!=')'&&x!='$')){  //everthing else is episolon
        cout << "Popped: (epsilon) | ";
        cout << "Pushed: (epsilon) | ";
        return currstat;
    }
    else if (x=='('&&currstat==Q10){   // popped the operator if read the next string with open parenthesis. e.i. $a+(a+a)$
        cout << "Popped: " << mystack.top() << " | ";
        mystack.pop();
        cout << "Pushed: " << x << " | ";
        mystack.push(x);
        return currstat;
    }
    else
        return TEMP_ERROR;      //return error if the stack is empty when you trying to popped something. e.i. $(a+a))$
}

// PushDown Automata
state pda(char c, state currstat){
    if (currstat==Q1){          // State Q1
        if(c=='$'){
            return Q2;
        }
        else
            return ERROR;       // return error if there no edge after reading a character
    }
    else if (currstat==Q2){     // State Q2
        if(c=='('){
            return Q4;
        }
        else if(c!='(' && c!='+' && c!='-' && c!='/' && c!='*'){

            return Q3;
        }
        else
            return ERROR;
    }
    else if (currstat==Q3){     // State Q3
        if (c=='('){
            return Q4;
        }
        else if(c!='+'&&c!='-'&&c!='/'&&c!='*'){

            return Q5;
        }
        else if (c=='+'||c=='-'||c=='/'||c=='*'){

            return Q6;
        }
        else
            return ERROR;
    }
    else if (currstat==Q4){     // State Q4
        if (c=='('){
            return Q4;
        }
        else if (c!='('&&c!='+'&&c!='-'&&c!='/'&&c!='*'){

            return Q5;
        }
        else
            return ERROR;

    }
    else if (currstat==Q5){         // State Q5
        if(c==')'){
            return Q5;
        }
        else if(c=='('){
            return Q4;
        }
        else if(c=='+'||c=='-'||c=='/'||c=='*'){
            return Q6;
        }
        else if(c=='$'){
            return Q8;
        }
        else if (c!='('&&c!='+'&&c!='-'&&c!='/'&&c!='*'&&c!='$'){

            return Q7;
        }
        else
            return ERROR;
    }
    else if (currstat==Q6){     // State Q6
        if(c!='+'&&c!='-'&&c!='/'&&c!='*'&&c!='('&&c!=')'&&c!='$'){
            return Q9;
        }
        else if (c=='('){
            return Q10;
        }
        else
            return ERROR;
    }
    else if (currstat==Q7){     // State Q7
        if(c==')'){
            return Q7;
        }
        else if(c=='$'){
            return Q8;
        }
        else if (c=='('){
            return Q7;
        }
        else if (c!=')' && c!='+' && c!='-' && c!='/' && c!='*'){
            return Q5;
        }
        else if (c=='+'||c=='-'||c=='/'||c=='*'){
            return Q6;
        }
        else
            return ERROR;
    }
    else if (currstat==Q8)      // State Q8
        return Q8;              // assume that after the last $ (dollar sign) there should be no more character
    else if(currstat==Q9){      // State Q9
        if (c!=')' && c!='+' && c!='-' && c!='/' && c!='*'&&c!='('&&c!='$'){
            return Q7;
        }
        else if(c=='('){
            return Q4;
        }
        else if(c=='+'||c=='-'||c=='/'||c=='*'){
            return Q6;
        }
        else if(c==')'){
            return Q9;
        }
        else
            return ERROR;
    }
    else if (currstat==Q10){    // State Q10
        if (c!=')' && c!='+' && c!='-' && c!='/' && c!='*'&&c!='('&&c!='$'){
            return Q7;
        }
        else if(c=='('){
            return Q4;
        }
        else
            return ERROR;
    }
    else
        return ERROR;
}
//end of PDA

// Display if the string is accepted or rejected

void display(state currstat){ //check if it is accepted or rejected
    if (currstat==7&&mystack.size()<=0) {  // Q8 is the acceptance state and the stack should be empty
        cout << "\nPDA Recognized - Accepted" << endl <<endl;
    }
    else cout << "\nRejected" <<endl <<endl;
    cout << "--------------------------------------------------------------" <<endl;
}


//main
int main(int argc, const char * argv[])
{
    char choice;
    string in_str;
    cout << "--------------------------------------------------------------" <<endl;
    cout << "Select: 'y' to enter a string / 'n' to terminate" << endl; //prompt the user to enter a string or terminate
    cin >> choice;
    while (choice=='y'||choice=='Y') {
        cout << "Enter a String: " << endl;
        cin >> in_str; // website string
        rd_letter(in_str);

        cout << "Select: 'y' to enter a string / 'n' to terminate" << endl;
        cin >> choice;

    }
    cout << "Good-bye: Exiting now..." <<endl;

    return 0;
}
