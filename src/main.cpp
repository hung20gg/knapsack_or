// #include<bits/stdc++.h>
// #include<ilcplex/ilocplex.h>
// #include<chrono>

// #define long long ll;

// using namespace std;

// void solve(ifstream &input, ofstream &output){
//     int item ; //try-catch later
//     int mw ;
//     double result; 

//     input>>item>>mw>>result;

//     vector<double>V(item);
//     vector<vector<double>>W(mw, vector<double>(item));
//     vector<double>MW(mw);

//     for (int i=0;i<item;i++){
//         input>>V[i];

//     }

//     for (int i = 0;i<mw;i++){
//         for (int j = 0;j<item;j++){
//             input>>W[i][j];
//         }
//     }


//     for (int i=0; i<mw;i++){
//         input>>MW[i];
//     }

//     IloEnv env;
//     IloModel Model(env);


//     //for (int i=0;i<item;i++){
//     IloIntVarArray X = IloIntVarArray(env, item, 0, 1);
//     //}

//     IloExpr exp0(env);

//     for(int i=0;i<item;i++){
//         exp0 += X[i]*V[i];
//     }


//     Model.add(IloMaximize(env,exp0));

//     for (int i = 0; i<mw;i++){
//         IloExpr exp1(env);
//         for (int j=0;j<item;j++){
//             exp1 += X[j] * W[i][j];
//         }
//         Model.add(exp1 <= MW[i]);


//     }

//     IloCplex cplex(Model);

//     if (!cplex.solve()) {
// 		env.error() << "Failed to optimize the Master Problem!!!" << endl;
// 		throw(-1);
// 	}

//     int obj = cplex.getObjValue();
//     // output<<"Solved"<<endl;
//     // output<<obj<<endl;


  	
//     if(obj == result){
//         output<<"Passed"<<endl;
//     }
//     else{
//         output<<"Failed"<<endl;
//     }

    
// }

// int main(int argc, char* argv[]){

//     auto start = chrono::high_resolution_clock::now();

//     string instance_folder = "/home/quanghung20gg/Documents/orlab/tanthu/src";
//     string instance_name = "";

//     int seed = 0;
//     while (--argc){
//             argv++;
//             string s(argv[0]);
//             if (s == "-n"){
//                 instance_name = string(argv[1]);
//             }
//             break;
//     }




//     string dir = "/home/quanghung20gg/Documents/orlab/tanthu/src/multi/"+instance_name;
//     string dirout = "/home/quanghung20gg/Documents/orlab/tanthu/src/multi-optimal/"+instance_name;
//     ifstream input(dir);
//     ofstream output(dirout+"_out.txt");

//     int k;
//     input>>k;

//     while(--k){
//         solve(input, output);
//     }

//     // freopen("/home/quanghung20gg/Documents/orlab/tanthu/src/low-dimensional/f2_l-d_kp_10_269","r",stdin);
//     // freopen("/home/quanghung20gg/Documents/orlab/tanthu/src/low-dimensional/f_l-d_kp_20_269_out.txt","w",stdout);
//     auto end = chrono::high_resolution_clock::now();
// 	auto Elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
//     output<<"Running time(ms): "<<Elapsed.count() << endl;
    
// }


#include<bits/stdc++.h>
#include<ilcplex/ilocplex.h>
#include<chrono>

#define long long ll;

using namespace std;

void solve(ifstream &input, ofstream &output){
    int item ; //try-catch later
    int mw ;
    double result; 

    input>>item>>mw>>result;

    vector<double>V(item);
    vector<vector<double>>W(mw, vector<double>(item));
    vector<double>MW(mw);

    for (int i=0;i<item;i++){
        input>>V[i];

    }

    for (int i = 0;i<mw;i++){
        for (int j = 0;j<item;j++){
            input>>W[i][j];
        }
    }

    // for (int i = 0;i<mw;i++){
    //     for (int j = 0;j<item;j++){
    //         output<<W[i][j]<<" ";
    //     }
    //     output<<endl;
    // }

    for (int i=0; i<mw;i++){
        input>>MW[i];
    }

    IloEnv env;
    IloModel Model(env);


    //for (int i=0;i<item;i++){
    IloIntVarArray X = IloIntVarArray(env, item, 0, 1);
    //}

    IloExpr exp0(env);

    for(int i=0;i<item;i++){
        exp0 += X[i]*V[i];
    }


    Model.add(IloMaximize(env,exp0));

    for (int i = 0; i<mw;i++){
        IloExpr exp1(env);
        for (int j=0;j<item;j++){
            exp1 += X[j] * W[i][j];
        }
        Model.add(exp1 <= MW[i]);


    }

    // IloExpr exp1(env);

    // for (int i=0;i<item;i++){
    //     exp1 += X[i]*W[i];
    // }
    // Model.add(exp1 <= mw);

    IloCplex cplex(Model);
    double obj;
    if (!cplex.solve()) {
		env.error() << "Failed to optimize the Master Problem!!!" << endl;
		obj = 0;
	}else{
        obj = cplex.getObjValue();
    }

    // output<<"Solved"<<endl;
    // output<<obj<<endl;


  	
    if(obj == result){
        output<<"Passed \t"<<obj<<"/"<<result<<endl;
    }
    else{
        output<<"Failed \t"<<obj<<"/"<<result<<endl;
    }

    
}
int main(int argc, char* argv[]){

    auto start = chrono::high_resolution_clock::now();

    string instance_folder = "/home/quanghung20gg/Documents/orlab/tanthu/src";
    string instance_name = "";

    int seed = 0;
    while (--argc){
            argv++;
            string s(argv[0]);
            if (s == "-n"){
                instance_name = string(argv[1]);
            }
            break;
    }




    string dir = "/home/quanghung20gg/Documents/orlab/tanthu/src/multi/"+instance_name;
    string dirout = "/home/quanghung20gg/Documents/orlab/tanthu/src/multi-optimal/"+instance_name;
    ifstream input(dir);
    ofstream output(dirout+"_out.txt");

    int k;
    input>>k;

    while(--k){
        solve(input, output);
    }

    // freopen("/home/quanghung20gg/Documents/orlab/tanthu/src/low-dimensional/f2_l-d_kp_10_269","r",stdin);
    // freopen("/home/quanghung20gg/Documents/orlab/tanthu/src/low-dimensional/f_l-d_kp_20_269_out.txt","w",stdout);
    auto end = chrono::high_resolution_clock::now();
	auto Elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    output<<"Running time(ms): "<<Elapsed.count() << endl;
    
}
