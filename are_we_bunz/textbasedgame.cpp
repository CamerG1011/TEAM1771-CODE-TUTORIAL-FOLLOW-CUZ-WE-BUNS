#include <iostream>
#include <string>
#include <list>
#include <random>

using namespace std;

int money = 0;
string temp;

list<string> gameIntros = {"brandon is so cool he is such a peak forehead guy", "BOY", "i love money i love foraging money", "i love brandon brand is so cool", "did you help menu exist by asking for help", "made by the glorious king ethanol", "brandon's gay", "arjun needs to stop eating", "team1771", "67", "6741"};

int game() {
    system("clear");
    string brandon;
    string temp = "";

    mt19937 gen(random_device{}());
    uniform_int_distibution<> dist(0, gameIntros.size() - 1);
    int randomIndex = dist(gen);
    string intro = gameIntros[randomIndex];

    cout << "the ultimate enter game" << endl;
    cout << "by ethan jang the king guy" << endl;
    cout << "type help for commands\n" << endl;

    cout << "Enters: " << money << endl;  

    std::getline(cin, brandon);

    transform(brandon.begin(), brandon.end(), brandon.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    if (brandon.empty()) {
        money++;
        game();
    } else if (brandon == "help") {
        cout << "1. say <upgrade> to buy" << endl;
        cout << "(press enter to continue)" << endl;
        std::getline(std::cin, temp);
        if (temp.empty()) {
            game();
        }
    } else {
        game();
    }
};

int main() {
    game();
    return 0;
};
