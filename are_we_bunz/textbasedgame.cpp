#include <iostream>
#include <string>
#include <list>
#include <random>

using namespace std;

int money = 0;
string userinput;

int sixes;
int sevens;

int game() {
    system("clear");

    cout << "sixes: " << sixes << endl;
    cout << "sevens: " << sevens << endl;
}

int start(bool clearterminal, string starttext) {
    if (clearterminal) {
        system("clear");
    };
    if (!starttext.empty()) {
        cout << starttext << "\n" << endl;
    };
    cout << "welcome to the great 67 enter game" << endl;
    cout << "inpired by king yutaka\n" << endl;
    cout << "1) start new game" << endl;
    cout << "2) load game" << endl;
    cout << "3) inspiration" << endl;
    
    cout << "";
    getline(cin, userinput);

    if (userinput.empty()) {
        start(true, "");
    } else if (userinput == "1") {
        game();
    } else if (userinput == "2") {
        start(true, "coming soon so be patient you son of a keoni");
    } else if (userinput == "3") {
        start(true, "made by the peak and the great inspiration 67 yutaka");
    };
};

int main() {
    start(true, "");
    return 0;
};
