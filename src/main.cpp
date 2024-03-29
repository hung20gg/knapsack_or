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

#include "../header/basic_knapsack.hpp"
#include "../header/multi_knapsack.hpp"
#include "../header/multidemand_knapsack.hpp"

#include<chrono>

#define ll long long;



int main(int argc, char* argv[]){

    std::string instance_folder = "/home/quanghung20gg/Documents/hung20gg/tanthu/instances/";
    std::string instance_name = "";
    std::string type = "";
    int thread = 1;

    // Get the input from command line

    while (--argc){
            argv++;
            std::string s(argv[0]);
            if (s == "-n"){
                instance_name = std::string(argv[1]);
            }
            if (s == "-t"){
                type = std::string(argv[1]);
            }
            if (s == "-c"){
                thread = std::stoi(argv[1]);
            }
    }

    std::string dir = instance_folder + type + "/" + instance_name;
    std::string dirout = instance_folder + type + "-optimal/" + instance_name;

    // Open file
    std::ifstream input(dir);
    std::ofstream output(dirout+"_out.txt");

    int k;
    if (type == "low-dimensional"){
        k = 1;
    }
    else{
        input>>k;
    }

    int count=1;

    // Knapsack new solver;
    std::cout<<type<<std::endl;
    while(k--){

        auto start = std::chrono::high_resolution_clock::now();
        output<<type<<","<<instance_name<<",Problem "<<count<<",";

        // Choose the solver depend on problem type

        
        if (type == "multi"){

            // MultiKnapsack solver;

            MultiKnapsack solver;
            solver.read(input);
            solver.solve(thread);
            solver.out(output);
            count++;
        }
        if (type == "multi-demand"){

            // MultidemandKnapsack solver;

            MultidemandKnapsack solver;
            solver.read(input);
            solver.solve(thread);
            solver.out(output);
            count++;
            
        }
        if (type == "low-dimensional"){

            // BasicKnapsack solver;

            BasicKnapsack solver;
            solver.read(input);
            solver.solve(thread);
            solver.out(output);
            count++;
        }
        
        // Measure the time

        auto end = std::chrono::high_resolution_clock::now();
        auto Elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        if (type =="multi-demand"){
            output<<Elapsed.count()/std::max(5,k) << std::endl;
            if (count==6){
                break;
            }
        }
        else{
            output<<Elapsed.count() << std::endl;
        }
        
    }

    input.close();
    output.close();

}
