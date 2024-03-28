#pragma once
#include <iostream>
#include <vector>
#include <ilcplex/ilocplex.h>
#include <fstream>

class Knapsack {
    
    public:
        // virtual void read(ifstream &input) const=0;
        // virtual void solve() const=0;
        // void output(ofstream &output);
        
        // void read(std::ifstream &input);
        // void solve(int thread);

        void out(std::ofstream &output);
        void get_ans(double re);

    protected:
        int item;
        int mw;

        std::vector<double>V;
        std::vector<double>W;
        std::vector<int>Solution;
        
        double result;
        double ans;
        std::string status;

    
};
