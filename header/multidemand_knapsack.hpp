#pragma once
#include <iostream>
#include <vector>
#include <ilcplex/ilocplex.h>
#include <fstream>

#include "knapsack.hpp"

class MultidemandKnapsack: public Knapsack
{
    private:

        std::vector<std::vector<double>>V;
        std::vector<std::vector<double>>W;
        std::vector<std::vector<double>>RW;
        std::vector<double>MW;

        double result;
        double ans;

    public:
        void read(std::ifstream &input);
        void solve(int thread);

};
