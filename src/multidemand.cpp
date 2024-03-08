
// #include<bits/stdc++.h>
// #include<ilcplex/ilocplex.h>
// #include<chrono>

// #define long long ll;

// using namespace std;

// void solve(ifstream &input, ofstream &output){
//     int item ; //try-catch later
//     int mw ;

//     input>>item>>mw;

//     vector<vector<double>>V(6,vector<double>(item));
//     vector<vector<double>>W(mw, vector<double>(item));
//     vector<vector<double>>RW(mw, vector<double>(item));
//     vector<double>MW(mw);
//     vector<double>RMW(mw);

    

//     for (int i = 0;i<mw;i++){
//         for (int j = 0;j<item;j++){
//             input>>W[i][j];
//         }
//     }

//     for (int i=0; i<mw;i++){
//         input>>MW[i];
//     }

//     for (int i = 0;i<mw;i++){
//         for (int j = 0;j<item;j++){
//             input>>RW[i][j];
//         }
//     }

//     for (int i=0; i<mw;i++){
//         input>>RMW[i];
//     }

//     for (int i=0; i<6; i++)
//         {for (int j=0;j<item;j++){
//             input>>V[i][j];
//         }}

//     for (int t = 0; t < 6; t++){

//         IloEnv env;
//         IloModel Model(env);

//         IloIntVarArray X = IloIntVarArray(env, item, 0, 1);

//         IloExpr exp0(env);

//         for(int i=0;i<item;i++){
//             exp0 += X[i]*V[t][i];
//         }

//         Model.add(IloMaximize(env,exp0));

//         for (int i = 0; i<mw;i++){
//             IloExpr exp1(env);
//             for (int j=0;j<item;j++){
//                 exp1 += X[j] * W[i][j];
//             }
//             Model.add(exp1 <= MW[i]);

//         }

//         int reverse = 1;

//         if (t%3==1){
//             reverse = mw/2;
//         }
//         if (t%3==2){
//             reverse = mw;
//         }

//         for (int i = 0; i<reverse;i++){
//             IloExpr exp1(env);
//             for (int j=0;j<item;j++){
//                 exp1 += X[j] * RW[i][j];
//             }
//             Model.add(exp1 <= RMW[i]);

//         }

//         IloCplex cplex(Model);
//         double obj;
//         if (!cplex.solve()) {
//             env.error() << "Failed to optimize the Master Problem!!!" << endl;
//             obj = 0;
//         }else{
//             obj = cplex.getObjValue();
//         }

//         output<<"\t"<<obj<<endl;
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
//     int count=1;

//     while(--k){
//         output<<"Problem "<<count<<endl;
//         solve(input, output);
//         count++;
//     }

//     auto end = chrono::high_resolution_clock::now();
// 	auto Elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
//     output<<"Running time(ms): "<<Elapsed.count() << endl;
    
// }

