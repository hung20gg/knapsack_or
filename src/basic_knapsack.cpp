// #include<bits/stdc++.h>
// #include<ilcplex/ilocplex.h>
// #include<chrono>

// using namespace std;


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




//     string dir = "/home/quanghung20gg/Documents/orlab/tanthu/src/low-dimensional/"+instance_name;
//     string dirout = "/home/quanghung20gg/Documents/orlab/tanthu/src/low-dimensional-optimal/"+instance_name;
//     ifstream input(dir);
//     ofstream output(dirout+"_out.txt");

//     // freopen("/home/quanghung20gg/Documents/orlab/tanthu/src/low-dimensional/f2_l-d_kp_10_269","r",stdin);
//     // freopen("/home/quanghung20gg/Documents/orlab/tanthu/src/low-dimensional/f_l-d_kp_20_269_out.txt","w",stdout);

//     int item ; //try-catch later
//     int mw ;


//     input>>item>>mw;

//     vector<int>V(item);
//     vector<int>W(item);

//     for (int i=0;i<item;i++){
//         input>>V[i]>>W[i];


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


//     IloExpr exp1(env);

//     for (int i=0;i<item;i++){
//         exp1 += X[i]*W[i];
//     }
//     Model.add(exp1 <= mw);

//     IloCplex cplex(Model);

//     if (!cplex.solve()) {
// 		env.error() << "Failed to optimize the Master Problem!!!" << endl;
// 		throw(-1);
// 	}

//     int obj = cplex.getObjValue();
//     output<<"Solved"<<endl;
//     output<<obj<<endl;

//     for (int i = 0;i<item;i++){
//         output<<i<<" "<<cplex.getValue(X[i])<<endl;
//     }

//     	auto end = chrono::high_resolution_clock::now();
// 	auto Elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);

//     output<<"Running time(ms): "<<Elapsed.count() << endl;
// }
