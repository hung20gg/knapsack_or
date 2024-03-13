#pragma once
#include <iostream>
#include <vector>
#include <ilcplex/ilocplex.h>
#include <fstream>

#include "knapsack.hpp"

class MultiKnapsack: public Knapsack
{
    private:

        std::vector<std::vector<double>>W;
        std::vector<double>MW;
        double target;

    public:
        void read(std::ifstream &input);
        void solve(int thread);

};
