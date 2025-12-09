#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

string userinput;
string temp;
int shopstage = 0;


string sixrow6 = " #### ";
string sixrow5 = "#    #";
string sixrow4 = "#     ";
string sixrow3 = "# ### ";
string sixrow2 = "#    #";
string sixrow1 = " #### ";
string sixrow0 = "      ";

string sevenrow6 = "######";
string sevenrow5 = "    # ";
string sevenrow4 = "   #  ";
string sevenrow3 = "  #   ";
string sevenrow2 = " #    ";
string sevenrow1 = "#     ";
string sevenrow0 = "      ";

int sixvalue = 0;
int sevenvalue = 0;

int money = 0;
int increase = 1;
int multiplier = 1;

int increaseprice = 50;
int sixsevenprice = 67;

double increasepricemultiplier = 1.75;
double sixsevenpricemultiplier = 1.75;

void printStructure(int six, int seven) {
    if (six >= 6) {
        cout << "[   " << sixrow6;
    } else {
        cout << "[   " << sixrow0;
    }
    if (seven >= 6) {
        cout << "  " << sevenrow6 << "   ]" << endl;
    } else {
        cout << "  " << sevenrow0 << "   ]" << endl;
    }

    if (six >= 5) {
        cout << "[   " << sixrow5;
    } else {
        cout << "[   " << sixrow0;
    }
    if (seven >= 5) {
        cout << "  " << sevenrow5 << "   ]" << endl;
    } else {
        cout << "  " << sevenrow0 << "   ]" << endl;
    }

    if (six >= 4) {
        cout << "[   " << sixrow4;
    } else {
        cout << "[   " << sixrow0;
    }
    if (seven >= 4) {
        cout << "  " << sevenrow4 << "   ]" << endl;
    } else {
        cout << "  " << sevenrow0 << "   ]" << endl;
    }

    if (six >= 3) {
        cout << "[   " << sixrow3;
    } else {
        cout << "[   " << sixrow0;
    }
    if (seven >= 3) {
        cout << "  " << sevenrow3 << "   ]" << endl;
    } else {
        cout << "  " << sevenrow0 << "   ]" << endl;
    }

    if (six >= 2) {
        cout << "[   " << sixrow2;
    } else {
        cout << "[   " << sixrow0;
    }
    if (seven >= 2) {
        cout << "  " << sevenrow2 << "   ]" << endl;
    } else {
        cout << "  " << sevenrow0 << "   ]" << endl;
    }

    if (six >= 1) {
        cout << "[   " << sixrow1;
    } else {
        cout << "[   " << sixrow0;
    }
    if (seven >= 1) {
        cout << "  " << sevenrow1 << "   ]" << endl;
    } else {
        cout << "  " << sevenrow0 << "   ]" << endl;
    }
}

void stats(bool passthrough) {

    if (!passthrough) {
        system("cls");
    }

    cout << "SixSeven Dollars: " << money << endl;
    cout << "Dollars per Key: " << increase << endl;
    cout << "Multiplier: " << multiplier << endl;
    cout << "Sixes: " << sixvalue << endl;
    cout << "Sevens: " << sevenvalue << endl;

    cout << "DPK Increase Price: " << increaseprice << endl;
    cout << "67 Price: " << sixsevenprice << endl;

    if (!passthrough) {
        cout << endl;
        cout << "Press Enter To Go Back" << endl;
        getline(cin, temp);
    }
}

void help() {
    system("cls");
    cout << "HELP" << endl;
    cout << "-------------" << endl;
    cout << "Help - Shows this menu" << endl;
    cout << "Shop - Opens Shop" << endl;
    cout << "Stats - Show Player Stats" << endl;

    cout << endl;

    cout << "Press Enter To Go Back" << endl; 
    getline(cin, temp);
}

void shop() {
    system("cls");
    cout << "SixSeven Dollars: " << money << "\n" << endl;
    if (shopstage == 0) {
        shopstage = 0;
        cout << "Merchant: Greetings my fellow 67er!" << endl;
        cout << endl;
        cout << "1) Increase money earn (+1)" << endl;
        cout << "2) Buy portion of 67" << endl;


        cout << endl;
        cout << "Press Enter To Go Back" << endl;

        cout << ">";
        getline(cin, temp);

        if (temp == "1") {
            shopstage = 1;
            shop();
        } else if (temp == "2") {
            shopstage = 2;
            shop();
        } else {
            shopstage = 0;
        }
    } else if (shopstage == 1) {
        shopstage = 1;
        cout << "Merchant: ah.. the classic!" << endl;
        cout << endl;
        cout << "Price: " << increaseprice << endl;
        cout << "1) Buy" << endl;
        cout << "2) Go back" << endl;
        cout << ">";

        getline(cin, temp);

        if (temp == "1") {
            shopstage = 1;
            if (money < increaseprice) {
                system("cls");
                cout << "SixSeven Dollars: " << money << "\n" << endl;
                cout << "Merchant: hah! you think you can buy THIS masterpiece for free?!" << endl;
                cout << endl;
                cout << "Press Enter To Go Back" << endl;
                cout << ">";
                getline(cin, temp);
                shopstage = 1;
                shop();
            } else if (money >= increaseprice) {
                money = money - increaseprice;
                increaseprice = std::round(increaseprice * increasepricemultiplier);
                increase = increase + 1;

                system("cls");
                cout << "Merchant: pleasure doing business" << endl;
                cout << endl;
                stats(true);
                cout << endl;
                cout << "Press Enter To Go Back" << endl;
                cout << ">";
                getline(cin, temp);
                shopstage = 1;
                shop();  
            } else {
                shopstage = 1;
                shop();
            }
        } else if (temp == "2") {
            shopstage = 0;
            shop();
        } else {
            shopstage = 1;
            shop();
        }
    } else if (shopstage == 2) {
        shopstage = 2;
        cout << "Merchant: The GRAND item!" << endl;
        cout << endl;
        cout << "Price: " << sixsevenprice << endl;
        cout << "1) Buy Six (" << sixvalue << "/6)" << endl;
        cout << "2) Buy Seven (" << sevenvalue << "/6)" << endl;
        cout << "3) Go Back" << endl;
        cout << ">";
        getline(cin, temp);

        if (temp == "1") {
            shopstage = 2;
            if (sixvalue >= 6) {
                system("cls");
                cout << "SixSeven Dollars: " << money << "\n" << endl;
                cout << "Merchant: looks like you bought my entire stock!" << endl;
                cout << endl;
                cout << "Press Enter To Go Back" << endl;
                cout << ">";
                getline(cin, temp);
                shopstage = 2;
                shop();
            }
            if (money < sixsevenprice) {
                system("cls");
                cout << "SixSeven Dollars: " << money << "\n" << endl;
                cout << "Merchant: hah! you think you can buy THIS masterpiece for free?!" << endl;
                cout << endl;
                cout << "Press Enter To Go Back" << endl;
                cout << ">";
                getline(cin, temp);
                shopstage = 2;
                shop();
            } else if (money >= sixsevenprice) {
                money = money - sixsevenprice;
                sixsevenprice = std::round(sixsevenprice * sixsevenpricemultiplier);
                sixvalue = sixvalue + 1;

                system("cls");
                cout << "Merchant: pleasure doing business" << endl;
                cout << endl;
                stats(true);
                cout << endl;
                cout << "Press Enter To Go Back" << endl;
                cout << ">";
                getline(cin, temp);
                shopstage = 2;
                shop();  
            }
        } else if (temp == "2") {
            shopstage = 2;
            if (sevenvalue >= 6) {
                system("cls");
                cout << "SixSeven Dollars: " << money << "\n" << endl;
                cout << "Merchant: looks like you bought my entire stock!" << endl;
                cout << endl;
                cout << "Press Enter To Go Back" << endl;
                cout << ">";
                getline(cin, temp);
                shopstage = 2;
                shop();
            }
            if (money < sixsevenprice) {
                system("cls");
                cout << "SixSeven Dollars: " << money << "\n" << endl;
                cout << "Merchant: hah! you think you can buy THIS masterpiece for free?!" << endl;
                cout << endl;
                cout << "Press Enter To Go Back" << endl;
                cout << ">";
                getline(cin, temp);
                shopstage = 2;
                shop();
            } else if (money >= sixsevenprice) {
                money = money - sixsevenprice;
                sixsevenprice = sixsevenprice * sixsevenpricemultiplier;
                sevenvalue = sevenvalue + 1;

                system("cls");
                cout << "Merchant: pleasure doing business" << endl;
                cout << endl;
                stats(true);
                cout << endl;
                cout << "Press Enter To Go Back" << endl;
                cout << ">";
                getline(cin, temp);
                shopstage = 2;
                shop();  
            }
        } else if (temp == "3") {
            shopstage = 0;
            shop();
        }else {
            shopstage == 2;
            shop();
        }
    }
}


void end() {
    system("cls");
    cout << "67 Finished!" << endl;
    cout << "-------------" << endl;
    cout << endl;
    printStructure(sixvalue,sevenvalue);

    cout << endl;
    cout << "Made by the great ethanol jangalang" << endl;
    cout << "Inspired by the great words of yutaka" << endl;
    cout << endl;
    cout << "SixSeven Dollars: $" << money << endl;
    stats(true);
    cout << endl;

    cout << "Type SIXSEVEN to Finish" << endl;
    cout << ">";
    getline(cin,temp);
    if (temp == "SIXSEVEN") {
        exit(0);
    } else {
        end();
    }
}

void game() {

    if (sixvalue == 6) {
        if (sevenvalue == 6){
            end();
        }
    }

    userinput = "";
    system("cls");

    cout << "Build your 67" << endl;
    cout << "-------------" << endl;
    cout << endl;
    printStructure(sixvalue,sevenvalue);

    cout << endl;
    cout << "Press Enter To Earn" << endl;
    cout << "Type Help for Commands" << endl;
    cout << endl;
    cout << "SixSeven Dollars: $" << money << endl;
    cout << ">";
    getline(cin, userinput);

    std::transform(userinput.begin(), userinput.end(), userinput.begin(),
               [](unsigned char c){ return std::tolower(c); });

    if (userinput.empty()) {
        money = (money + increase)*multiplier;
        game();
    } else if (userinput == "help") {
        help();
        game();
    } else if (userinput == "shop") {
        shopstage = 0;
        shop();
        game();
    } else if (userinput == "stats") {
        stats(false);
        game();
    } else {
        game();
    }
}

int secretCount = 0;
string secretTemp;
void secret() {

    if (secretCount == 67) {
        money = 6741;
        game();
    }

    system("cls");
    cout << "TYPE 67, 67 TIMES!\n" << endl;

    cout << "Count: " << secretCount << endl;
    cout << ">";
    getline(cin,secretTemp);

    if (secretTemp == "67") {
        secretCount++;
        secret();
    } else {
        secret();
    }
}


void start(string text) {
    system("cls");
    cout << text << endl;
    cout << endl;
    cout << "build a 67" << endl;
    cout << "by ethan\n" << endl;

    cout << "1) start" << endl;
    cout << "2) cheat mode" << endl;
    cout << ">";
    getline(cin, userinput);

    if (userinput.empty()) {
        start("imagine not inputting anything");
    } else if (userinput == "1") {
        game();
    } else if (userinput == "2") {
        start("hell no");
    } else if (userinput == "67") {
        secret();
    } else {
        start("wrong move buddy");
    }
}


int main () {
    start("very amazing gaem");
    return 0;
}