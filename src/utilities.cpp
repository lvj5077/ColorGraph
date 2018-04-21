#include "utilities.h"

using namespace boost;
using namespace std;

void printMat(vector< vector<int> > mat){
    for(int i=0; i<mat.size(); ++i)                 
    {                                        
        for(int j=0; j<mat[i].size(); ++j)             
        {    
            cout << setw( 4 )<< mat.at(i).at(j) << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

void printVec( vector<int> vec){
    for(int i=0; i<vec.size(); ++i)                 
    {                                        
        cout << setw( 4 )<< vec.at(i) << " ";
    }
    cout << endl;
}

void printVecSQ( vector<int> vec){

    int sqroot = sqrt(vec.size()) ;
    for(int i=0; i<vec.size(); ++i)                 
    {                                        
        cout << setw( 4 )<< vec.at(i) << " ";
        if (sqroot*sqroot == vec.size()){
            if (  (i+1) %sqroot == 0  )
                cout << endl;
        }
	}
	cout << endl;
}


bool graphFromFile(string filename, UndirectedGraph &g, vector<int> &pre_color, int &nodes_num){
    vector<Edge> edgeVec;   
    ifstream myfile(filename);
    string line;
    int lineNum = -1;
    int edges_num = 0;
    stringstream ss;
    while (getline(myfile, line))
    {
        lineNum++;  
        ss<<line;
        int a, b;
        if (lineNum == 0){
            ss>> a >> b;
            nodes_num = a;
            edges_num = b;  
        }
        else{
            if (lineNum > edges_num){
                pre_color = vector<int> (nodes_num,0);
		        for (int i=0;i<nodes_num;++i){
		            ss >> pre_color.at(i) ;
		        }
                break;
            }
            else{
                ss>> a >> b;
                edgeVec.push_back(Edge(a-1,b-1)); 
            }
        }
        ss.clear();
    }
    g = UndirectedGraph (edgeVec.begin(), edgeVec.end(), nodes_num);
    if (num_edges(g) == edges_num && num_edges(g) != 0){
        cout << "\nGraph from file: \n";
        // cout << "\nNode number: "<< nodes_num ;
        // cout << "\nEdge number: "<< num_edges(g) << "\n";  
    	return true;
    }
    else{
    	return false;
    }
}

bool graphFromNode(int nodes_num, UndirectedGraph &g, vector<int> &pre_color){
    minstd_rand gen;
    g = UndirectedGraph (ERGen(gen, nodes_num, 0.5), ERGen(),nodes_num);
    pre_color = vector<int>  (nodes_num,0);
    if (num_edges(g) != 0){
        cout << "\nRandom graph from nodes: \n";
        // cout << "\nNode number: "<< nodes_num ;
        // cout << "\nEdge number: "<< num_edges(g) << "\n";  
    	return true;
    }
    else{
    	return false;
    }
}