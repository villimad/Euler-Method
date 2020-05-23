//
// Created by admin on 17.05.2020.
//

#ifndef EULER_EULER_H
#define EULER_EULER_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Euler {
    //y' = x1y + x2y^2 + x3

public:

    vector<int> arg_y;
    vector<int> arg_x;
    vector<double> arg_const;
    double dy0;
    double x0;
    double y0;
    double y1;
    int steps;

    Euler(
            vector<int> c_arg_y,
            vector<int> c_arg_x,
            vector<double> c_arg_const,
            double c_dy0,
            double c_x0,
            double c_y0,
            double c_y1,
            int c_steps
    ) {

        arg_y = c_arg_y;
        arg_x = c_arg_x;
        arg_const = c_arg_const;
        dy0 = c_dy0;
        x0 = c_x0;
        y0 = c_y0;
        y1 = c_y1;
        steps = c_steps;
    };

    vector<vector<double>> solution() {
        vector<double> y;
        vector<double> dy;
        vector<double> x;
        y.push_back(y0);
        dy.push_back(dy0);
        x.push_back(x0);
        double step_value = (y1 - y0) / steps;
        for (int step = 1; step < steps; step++) {
            y.push_back(y[step - 1] + step_value * dy[step - 1]);
            x.push_back(x[step - 1] + step_value);
            double dy_now = 0;
            for (int pointer = 0; pointer < arg_y.size(); pointer++) {
                dy_now += arg_const[pointer] * pow(y[step], arg_y[pointer]) * pow(x[step], arg_x[pointer]);
            }
            dy.push_back(dy_now);
        }
        vector<vector<double>> cash = {dy, y, x};
        return cash;
    }
};


#endif //SCIWORK_EULER_H
