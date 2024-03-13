/*
    *********************************************************
    Multi-demand Multidimensional Knapsack problem
    *********************************************************

    Problem to be solved is:

    #########################################################
    (MDMKP) max  sum{j=1,...,n} c(j) x(j) 
        s.t. sum{j=1,...,n} a(i,j) x(j) <= b(i) i=1,...,m
             sum{j=1,...,n} a(i,j) x(j) >= b(i) i=m+1,...,m+q
             x(j) = 0 or 1                      j=1,...,n
    ##########################################################

    This code will solve the problem with 6 senario
        (the first 3 ones correspond to the positive cost case 
        for q=1, q=m/2 and q=m >= constraints respectively;
        the last 3 ones correspond to the mixed cost case 
        for q=1, q=m/2 and q=m >= constraints respectively).

    ----------------------------------------------------------
    Parameters:s
    - item: number of items
    - m:   number of contraints
    - V:   coefficients
    - W:   weight of item that <=b[i] (i = 1,..,m)
    - RW:  weight of item that >=b[i] (i = m,...,m+q)
    - MW:  b[i] (i = 1,..,m)
    - RMW: b[i] (i = m,...,m+q)
    ---------------------------------------------------------

*/
#include<bits/stdc++.h>
#include<ilcplex/ilocplex.h>

#include "../header/knapsack.hpp"
#include "../header/multi_knapsack.hpp"
#include "../header/multidemand_knapsack.hpp"

#include<chrono>

#define long long ll;

using namespace std;


int main(int argc, char* argv[]){

    string instance_folder = "/home/quanghung20gg/Documents/orlab/tanthu/instances/";
    string instance_name = "";
    string type = "";
    int thread = 1;

    while (--argc){
            argv++;
            string s(argv[0]);
            if (s == "-n"){
                instance_name = string(argv[1]);
            }
            if (s == "-t"){
                type = string(argv[1]);
            }
            if (s == "-c"){
                thread = stoi(argv[1]);
            }
    }

    string dir = instance_folder + type + "/" + instance_name;
    string dirout = instance_folder + type + "-optimal/" + instance_name;

    // Open file
    ifstream input(dir);
    ofstream output(dirout+"_out.txt");

    int k;
    if (type == "low-dimensional"){
        k = 1;
    }
    else{
        input>>k;
    }

    int count=1;

    // Knapsack new solver;

    while(k--){

        auto start = chrono::high_resolution_clock::now();
        output<<type<<","<<instance_name<<",Problem "<<count<<",";

        // Choose the solver depend on problem type
        Knapsack solver;
        
        if (type == "multi"){
            MultiKnapsack solver;
        }
        if (type == "multi-demand"){
            MultidemandKnapsack solver;
        }
        
        // Read and solve the problem
        solver.read(input);
        solver.solve(thread);
        solver.out(output);
        count++;

        auto end = chrono::high_resolution_clock::now();
        auto Elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
        output<<Elapsed.count() << endl;
    }

    
    
}
