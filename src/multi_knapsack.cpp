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

//     IloIntVarArray X = IloIntVarArray(env, item, 0, 1);

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
//     double obj;
//     if (!cplex.solve()) {
// 		env.error() << "Failed to optimize the Master Problem!!!" << endl;
// 		obj = 0;
// 	}else{
//         obj = cplex.getObjValue();
//     }

  	
//     if(obj == result){
//         output<<"Passed \t"<<obj<<"/"<<result<<endl;
//     }
//     else{
//         output<<"Failed \t"<<obj<<"/"<<result<<endl;
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

//     auto end = chrono::high_resolution_clock::now();
// 	auto Elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
//     output<<"Running time(ms): "<<Elapsed.count() << endl;
    
// }

