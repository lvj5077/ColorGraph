#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include "boost/graph/graph_traits.hpp"


#include <fstream>
#include <sstream>
#include <string>

#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <iomanip>

#include "colorGraph.h"
#include "utilities.h"


using namespace boost;
using namespace std;


int main(int argc, char *argv[])
{   

    int nodes_num = 4;
    int readFromfile = true;
    string filename;

    if (argc >= 2) {
        nodes_num = atoi(argv[1]);
        if (nodes_num != 0 ){
            readFromfile = false;
        }
        else{
            filename = argv[1];
        }
    }
    else{
        cout << "Please define a node number to create a random graph or provide an input text file"<<endl;
        cout << "e.g.: ./colorGraph 9   or      ./colorGraph inputfile.txt"<<endl;
        return 0;
    }

    UndirectedGraph g;
    vector<int> pre_color;

    if (readFromfile){
        graphFromFile(filename, g, pre_color, nodes_num);
    }
    else{
        graphFromNode(nodes_num, g, pre_color);
    }
    // Graph construction done!
    
    cout << "\nNode number: "<< nodes_num ;
    cout << "\nEdge number: "<< num_edges(g) << "\n";

    vector< vector<int> > adj_mat( nodes_num , vector<int>(nodes_num,0) );

    // cout << "\nEdges: \n";
    pair<edge_iterator, edge_iterator> ei = edges(g);
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
    // note: vector index from 0 but we index node from 1 conventionally
        // cout << "(" << setw( 4 )<< source(*edge_iter, g) +1  << ", " << setw( 4 )<< target(*edge_iter, g) +1 << ")\n";
        adj_mat.at(source(*edge_iter, g)  ).at(target(*edge_iter, g)  ) = 1;
        adj_mat.at(target(*edge_iter, g)  ).at(source(*edge_iter, g)  ) = 1;
    }
    cout << "\n";


    // cout << "\nAdjacency Matrix: \n";
    // printMat (adj_mat);

    int colors_num = nodes_num; // wrost case, all nodes have different colors
    vector <int> post_color (nodes_num,0);

    clock_t tStart = clock();
    // bool findResult = graphcolor(nodes_num,colors_num,adj_mat,pre_color, post_color);
    bool findResult = graphcolorOPT(0,nodes_num,colors_num,adj_mat,pre_color,post_color);
    cout << "Solved in "<< (double)(clock() - tStart)/CLOCKS_PER_SEC << "s \n"<<endl;


    if (findResult){
        if (readFromfile){
            cout << "pre_color: "<<endl;
            printVecSQ(pre_color);
            cout << endl<< "post_color: "<<endl;
            printVecSQ(post_color);   
        }
        else{
            printVec(post_color);  
        }
    }

    return 0;
}