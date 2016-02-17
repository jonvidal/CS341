//
//  p1_15f_jkv5.cpp
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
using namespace std;

enum state //enum to defined each state
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
    Q11,
    Q12,
    Q13,
    Q14,
    Q15,
    Q16,
    Q17,
    Q18,
    Q19,
    Q20,
    Q21,
    Q22
};

void display(state currstat);
state rd_state(char lett, state currstat);

void rd_letter(string in_str)
{
    cout << endl;
    state currstat = Q1; //starting state
    for (unsigned int i = 0; i<in_str.length(); i++)
    {
        char c = in_str[i]; //string to char array
        cout << c; // printing every character

        currstat=rd_state(c,currstat);

        // printing current state
        switch (currstat){
            case Q2:
                cout << " : currently on state Q2" << endl;
                break;
            case Q3:
                cout << " : currently on state Q3" << endl;
                break;
            case Q4:
                cout << " : currently on state Q4" << endl;
                break;
            case Q5:
                cout << " : currently on state Q5" << endl;
                break;
            case Q6:
                cout << " : currently on state Q6" << endl;
                break;
            case Q7:
                cout << " : currently on state Q7" << endl;
                break;
            case Q8:
                cout << " : currently on state Q8" << endl;     //Acceptance State
                break;
            case Q9:
                cout << " : currently on state Q9" << endl;
                break;
            case Q10:
                cout << " : currently on state Q10" << endl;
                break;
            case Q11:
                cout << " : currently on state Q11" << endl;    //Acceptance State
                break;
            case Q12:
                cout << " : currently on state Q12" << endl;
                break;
            case Q13:
                cout << " : currently on state Q13" << endl;    //Trap State
                break;
            case Q14:
                cout << " : currently on state Q14" << endl;
                break;
            case Q15:
                cout << " : currently on state Q15" << endl;
                break;
            case Q16:
                cout << " : currently on state Q16" << endl;    //Trap State
                break;
            case Q17:
                cout << " : currently on state Q17" << endl;
                break;
            case Q18:
                cout << " : currently on state Q18" << endl;
                break;
            case Q19:
                cout << " : currently on state Q19" << endl;    //Acceptance State
                break;
            case Q20:
                cout << " : currently on state Q20" << endl;
                break;
            case Q21:
                cout << " : currently on state Q21" << endl;
                break;
            case Q22:
                cout << " : currently on state Q22" << endl;    //Acceptance State
                break;
            default:
                cout << "error" << endl;
                break;
        }

    }
    display(currstat);
}

// Display if the string is accepted or rejected

 void display(state currstat){
     if (currstat==7||currstat==10||currstat==18||currstat==21) {  // accept when the current state is in Q8, Q11, Q19, and Q22
         cout << "\nThe Website String is Accepted" << endl <<endl;
     }
     else cout << "\nThe Website String is Rejected" <<endl <<endl;
    cout << "--------------------------------------------------------------" <<endl;
 }

//DFA
state rd_state(char lett, state currstat){
    if (currstat==Q1)                   //Start state to Q2
    {
        if (lett=='w') {
            return Q2;
        }
        else return Q12;
    }
    else if (currstat==Q2){             //State Q2
        if (lett=='w') {
            return Q3;
        }
        else if (lett=='.'){
            return Q14;
        }
        else return Q2;
    }
    else if (currstat==Q3){             //State Q3
        if (lett=='w') {
            return Q4;
        }
        else if (lett=='.'){
            return Q14;
        }
        else return Q3;
    }
    else if (currstat==Q4){             //State Q4
        if (lett=='.'){
            return Q5;
        }
        else if (lett!='.'){
            return Q15;
        }
        else return Q4;
    }
    else if (currstat==Q5){             //State Q5
        if (lett=='.'){
            return Q13
            ;
        }
        else if (lett=='c'){
            return Q6;
        }
        else if (lett!='c'&&lett!='.'){
            return Q12;
        }
        else return Q5;
    }
    else if (currstat==Q6){             //State Q6
        if (lett=='o'){
            return Q7;
        }
        else return Q6;
    }
    else if (currstat==Q7){             //State Q7
        if (lett=='.'){
            return Q9;
        }
        else if (lett=='m'){
            return Q8;
        }
        else return Q7;
            }
    else if (currstat==Q8){             //State Q8
        if (lett=='.'){
            return Q5;
        }
        else if (lett>='a'&&lett<='z'){
            return Q12;
        }
        else return Q8;

    }
    else if (currstat==Q9){             //State Q9
        if (lett=='u'){
            return Q10;
        }
        else if (lett=='c'){
            return Q6;
        }
        else return Q9;
            }
    else if (currstat==Q10){             //State Q10
        if (lett=='k'){
            return Q11;
        }
        else return Q10;
    }

    //else if (currstat==Q11)             State Q11

    else if (currstat==Q12){             //State Q12
        if (lett=='.'){
            return Q14;
        }
        else return Q12;
    }
    else if (currstat==Q13){ // State 13: TRAP STATE
        return Q13;
    }
    else if (currstat==Q14){             //State Q14
        if (lett=='c'){
            return Q17;
        }
        else if (lett!='c'){
            return Q16;
        }
        else return Q14;
    }
    else if (currstat==Q15){             //State Q15
        if (lett=='.'){
            return Q14;
        }
        else return Q15;
    }
    else if (currstat==Q16){// State 16: TRAPS STATE
        return Q16;
    }
    else if (currstat==Q17){             //State Q17
        if (lett=='o'){
            return Q18;
        }
        else if (lett!='o'){
            return Q16;
        }
        else return Q17;
    }
    else if (currstat==Q18){             //State Q18
        if (lett=='m'){
            return Q19;
        }
        else if (lett=='.'){
            return Q20;
        }
        else if (lett!='m'&&lett!='.'){
            return Q20;
        }
        else return Q18;
    }
    else if (currstat==Q19){             //State Q19
        if (lett>='a'||lett<='z'){
            return Q16;
        }
        else if (lett=='.'){
            return Q16;
        }
        else return Q19;
    }
    else if (currstat==Q20){             //State Q20
        if (lett=='u'){
            return Q21;
        }
        else return Q20;
            }
    else if (currstat==Q21){             //State Q21
        if (lett=='k'){
            return Q22;
        }
        else return Q22;
    }
    //else if (currstat==Q22)             State Q22

    else
        return currstat;

}//end of the dfa

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


