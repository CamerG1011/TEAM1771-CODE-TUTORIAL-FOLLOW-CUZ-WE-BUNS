#include <iostream>
#include <string>

using namespace std;

int main() {
    int brandon_private_size;
    const int brandon_actual_private_size = -30;
    int yutaka_size;
    int size_fix;
    string brandonname = "brandon";

    brandon_private_size = -5;
    yutaka_size = 1000;

    cout << 7/2 << endl << "BRANDON'S GAY" << endl << endl;
    cout << "Fix Size?\n";
    cout << ">";
    cin >> size_fix;
    cout << "\n";
    cout << "Cannot change variable.  Maybe remove const?  Or not maybe it's meant to be there";

    cout << brandonname;

    cout << endl;
    cout << endl;

    auto brandoniq = 200;
    int& brandoniq_binary = brandoniq;

    cout << &brandoniq_binary;
    return 0;
}
