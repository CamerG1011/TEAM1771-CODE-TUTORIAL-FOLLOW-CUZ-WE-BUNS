#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

string temp;
int money_gambling;

int money = 100;


int RocketMan_Multiplier = 1;
int RocketMan_Amount;

void RocketMan_Game() {

}

void RocketMan_SetUp() {
    RocketMan_Amount = money_gambling;
    RocketMan_Game()
}

void RocketMan() {
    system("cls");
    cout << "Rocket Man\n" << endl;

    cout << "press enter to cash out" << endl;
    cout << "money to gamble: ";

    getline(cin, temp);
    
    money_gambling = stoi(temp);
}

void SelectGame() {
    system("cls");
    cout << "The Great Gambling Game" << endl;
    cout << "by ethanol\n" << endl;
    
    cout << "You have: $" << money << "\n" << endl; 

    cout << "Choose the game" << endl;
    cout << "---------------" << endl;
    cout << "1) Rocket Man" << endl;

    cout << ">";
    getline(cin,temp);
    if (temp == "1") {
        RocketMan();
    }
}

int main() {
    SelectGame();
}