#include <iostream>
#include "euler.h"
using namespace std;

int main()
{
    //dy = 2 * (x ^ 2) * y + y
    vector<int> arg_y = {1, 1};
    vector<int> arg_x = {1, 0};
    vector<double> arg_const = {2, 1};
    double dy0 = 0.5;
    double x0 = 0;
    double y0 = 0;
    double y1 = 10;
    int steps = 20;
    auto euler = new Euler(
            arg_y,
            arg_x,
            arg_const,
            dy0,
            x0,
            y0,
            y1,
            steps
    );
    vector<vector<double>> cash = euler->solution();
    vector<double> dy = cash[0];
    vector<double> y = cash[1];
    vector<double> x = cash[2];
    cout << "dy " << "y " << "x " << endl;
    for (int q = 0; q < steps; q++) {
        cout << dy[q] << "; " << y[q] << "; " << x[q] << endl;
    }

    return 0;
}