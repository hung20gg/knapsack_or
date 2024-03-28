#include "../header/multi_knapsack.hpp"  

// Custom read function

void MultiKnapsack::read(std::ifstream &input){

    input>>item>>mw>>target;

    // Resize the vectors

    V.resize(item);

    W.resize(mw);
    for (int i=0;i<mw;i++){
        W[i].resize(item);
    }

    MW.resize(mw);
    Solution.resize(item);

    // Get the input object

    for (int i=0;i<item;i++){
        input>>V[i];
    }

    for (int i=0;i<mw;i++){
        for (int j=0;j<item;j++){
            input>>W[i][j];
        }
    }

    for (int i=0;i<mw;i++){
        input>>MW[i];
    }
}

// Solve the problem

void MultiKnapsack::solve(int thread){

    IloEnv env;
    IloModel Model(env);

    IloIntVarArray X = IloIntVarArray(env, item, 0, 1);

    IloExpr exp0(env);

    for(int i=0;i<item;i++){
        exp0 += X[i]*V[i];
    }

    Model.add(IloMaximize(env, exp0));

    for (int i = 0; i<mw; i++){
        IloExpr exp1(env);

        for(int j = 0; j<item; j++){
            exp1 += X[j]*W[i][j];
        }
        Model.add(exp1 <= MW[i]);
    }

    

    IloCplex cplex(Model);

    // Set the parameters
    cplex.setParam(IloCplex::Param::Threads, thread);
    cplex.setParam(IloCplex::Param::TimeLimit, 240);

    cplex.solve();

   for (int i=0;i<item;i++){
        Solution[i] = cplex.getValue(X[i]);
    }

    // Output the result

    env.out() << "Solution status = " << cplex.getStatus() << std::endl;
    env.out() << "Solution value  = " << cplex.getObjValue() << std::endl;
    std::cout<<"Solved by Multi Knapsack"<<std::endl;
    get_ans(cplex.getObjValue());
    status = cplex.getStatus();

    env.end();
}
