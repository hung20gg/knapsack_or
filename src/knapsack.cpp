#include <iostream>
#include <vector>
#include <ilcplex/ilocplex.h>
#include <fstream>
#include <chrono>

#include "../header/knapsack.hpp"

void Knapsack::out(std::ofstream &output){

        output<<ans<<",";
    };

void Knapsack::get_ans(double re){
        ans = re;
    };

void Knapsack::read(std::ifstream &input){
    input>>item>>mw;

    V.resize(item);
    W.resize(item);

    for (int i=0;i<item;i++){
        input>>V[i]>>W[i];
    }
    Solution.resize(item);
}

void Knapsack::solve(int thread){
    IloEnv env;
    IloModel Model(env);

    IloIntVarArray X = IloIntVarArray(env, item, 0, 1);

    IloExpr exp0(env);

    for(int i=0;i<item;i++){
        exp0 += X[i]*V[i];
    }

    Model.add(IloMaximize(env, exp0));

    IloExpr exp1(env);

    for(int i=0;i<item;i++){
        exp1 += X[i]*W[i];
    }

    Model.add(exp1 <= mw);

    IloCplex cplex(Model);
    cplex.solve();
    cplex.setParam(IloCplex::Param::Threads, thread);
    cplex.setParam(IloCplex::Param::TimeLimit, 300);

    for (int i=0;i<item;i++){
        Solution[i] = cplex.getValue(X[i]);
    }

    env.out() << "Solution status = " << cplex.getStatus() << std::endl;
    env.out() << "Solution value  = " << cplex.getObjValue() << std::endl;
    
    get_ans(cplex.getObjValue());
    status = cplex.getStatus();
    
    env.end();

}