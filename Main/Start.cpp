#include "Control.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    NetworkController control({784, 400, 100, 10});

    cout << "Test Accuracy: " << control.Train(32, 10, 0.05f, 0.01f, 0.1f, 0.9f) << endl;

    /*NetworkController control2({784, 300, 10});
    control2.ImportData();
    control2.ImportNetwork();
    cout << "Test Accuracy: " << control2.Test() << endl;*/

    return 0;
}
