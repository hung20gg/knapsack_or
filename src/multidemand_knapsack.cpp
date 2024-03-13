#include "../header/multidemand_knapsack.hpp"  


void MultidemandKnapsack::read(std::ifstream &input){

    input>>item>>mw;

    // Resize the vectors
    Solution.resize(item);

    V.resize(6);
    for (int i=0;i<6;i++){
        V[i].resize(item);
    }

    W.resize(mw);
    for (int i=0;i<mw;i++){
        W[i].resize(item);
    }

    RW.resize(mw);
    for (int i=0;i<mw;i++){
        RW[i].resize(item);
    }

    MW.resize(mw*2);

    // Input the object
    for (int i=0;i<mw;i++){
        for (int j=0;j<item;j++){
            input>>W[i][j];
        }
    }

    for (int i=0;i<mw;i++){
        input>>MW[i];
    }

    for (int i=0;i<mw;i++){
        for (int j=0;j<item;j++){
            input>>RW[i][j];
        }
    }

    for (int i=0;i<mw;i++){
        input>>MW[i+mw];
    }

    for (int i=0;i<6; i++)
        {for (int j=0;j<item;j++){
            input>>V[i][j];
        }}
}

void MultidemandKnapsack::solve(int thread){
    for (int t=0; t<6; t++){
       
        int q = 1;
        
        if (t%3 == 1){
            int q = mw/2;
        }
        if (t%3 == 0){
            int q = mw;
        }
    

        IloEnv env;
        IloModel Model(env);

        IloIntVarArray X = IloIntVarArray(env, item, 0, 1);

        IloExpr exp0(env);

        for(int i=0;i<item;i++){
            exp0 += X[i]*V[t][i];
        }

        Model.add(IloMaximize(env, exp0));

        for (int i = 0; i < mw; i++){
            IloExpr exp1(env);

            for(int j = 0; j<item; j++){
                exp1 += X[j]*W[i][j];
            }
            Model.add(exp1<=MW[i]);
        }

        for (int i = 0; i < q; i++){
            IloExpr exp1(env);

            for(int j = 0; j<item; j++){
                exp1 += X[j]*RW[i][j];
            }
            Model.add(exp1>=MW[mw+i]);
        }
        
        IloCplex cplex(Model);
        
        // Set the parameters
        cplex.setParam(IloCplex::Param::Threads, thread);
        cplex.setParam(IloCplex::Param::TimeLimit, 300);

        cplex.solve();

        for (int i=0;i<item;i++){
            Solution[i] = cplex.getValue(X[i]);
        }
            
        env.out() << "Solution status = " << cplex.getStatus() << std::endl;
        env.out() << "Solution value  = " << cplex.getObjValue() << std::endl;
        
        get_ans(cplex.getObjValue());
        status = cplex.getStatus();

        env.end();
    }
}



