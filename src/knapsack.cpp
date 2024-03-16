#include <iostream>
#include <vector>
#include <ilcplex/ilocplex.h>
#include <fstream>
#include <chrono>

#include "../header/basic_knapsack.hpp"

void Knapsack::out(std::ofstream &output){

        output<<ans<<",";
    };

void Knapsack::get_ans(double re){
        
        ans = re;
    };