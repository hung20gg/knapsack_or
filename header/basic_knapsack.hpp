#pragma once
#include <iostream>
#include <vector>
#include <ilcplex/ilocplex.h>
#include <fstream>

#include "knapsack.hpp"

class BasicKnapsack: public Knapsack
{
    private:

        
        double target;

    public:
        BasicKnapsack() : Knapsack() {};
        void read(std::ifstream &input) ;
        void solve(int thread) ;


};
