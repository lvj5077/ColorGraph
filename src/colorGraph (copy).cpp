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

using namespace boost;
using namespace std;

bool pass(int k,vector< vector<int> > adj_mat, vector<int> color)
{
  for(int i=1;i<k;++i)
  {
    if(adj_mat.at(k).at(i) ==1&&color.at(i)==color.at(k))
		return false;
  }
  return true;
}

void printMat(vector< vector<int> > mat)
{
	cout << "\nAdjacency Matrix: \n";
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

void graphcolor(int nodes_num,int colors_num,vector< vector<int> > adj_mat,vector<int> pre_color)
{
	cout << "Start: \n";
	vector <int> color (nodes_num,1);
	int k=1;
	while(k>=1)
	{
		color.at(k)=color.at(k)+1;

	   	for (int i=0;i<nodes_num;++i){
	   		if (pre_color.at(i)>0)
				color.at(i) = pre_color.at(i);
		}

		while(color.at(k)<=colors_num)
			if(pass(k,adj_mat,color)) 
				break;
		   else 
				color.at(k)=color.at(k)+1;
		if(color.at(k)<=colors_num&& k==(nodes_num-1) )
		{
			cout << "Result(s):"<< endl;	
		   	for (int i=0;i<nodes_num;++i){
				cout << color.at(i)  <<" ";
			}
			cout << endl;
			break;
		}
		else if(color.at(k)<=colors_num&&k<nodes_num)
		   k=k+1;
		else
		{
		 color.at(k)=0;
		 k=k-1;
		}
	}
}


int main(int argc, char *argv[])
{   

    int nodes_num = 4;
    int readFromfile = true;

    if (argc >= 2) {
		nodes_num = atoi(argv[1]);
		
		readFromfile = false;
    }
    //create an -undirected- graph type, using vectors as the underlying containers
    //and an adjacency_list as the basic representation
    typedef adjacency_list<vecS, vecS, undirectedS> UndirectedGraph;
    typedef boost::erdos_renyi_iterator<boost::minstd_rand, UndirectedGraph> ERGen;
    typedef pair<int, int> Edge;
    //Ok, we want to see that all our edges are now contained in the graph
    typedef graph_traits<UndirectedGraph>::edge_iterator edge_iterator;

    boost::minstd_rand gen;

    UndirectedGraph *g = new UndirectedGraph (ERGen(gen, nodes_num, 0.5), ERGen(),nodes_num);
    
    stringstream ss;

    if (readFromfile){
    	vector<Edge> edgeVec;	
    	ifstream myfile("/home/jin/Desktop/testGraph/data/getin.txt");
		string line;
		int lineNum = -1;
		int edges_num = 0;
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
					break;
				}
				else{
					ss>> a >> b;
					edgeVec.push_back(Edge(a-1,b-1)); 
				}
			}
			ss.clear();

		}
		g = new UndirectedGraph (edgeVec.begin(), edgeVec.end(), nodes_num);
	}
	// Graph construction done!
	
    cout << "\nNode number: "<< nodes_num ;
    cout << "\nEdge number: "<< num_edges(*g) << "\n";

    vector< vector<int> > adj_mat( nodes_num , vector<int>(nodes_num,0) );

    cout << "\nEdges: \n";
    pair<edge_iterator, edge_iterator> ei = edges(*g);
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
    // note: vector index from 0 but we index node from 1 conventionally
        cout << "(" << setw( 4 )<< source(*edge_iter, *g) +1  << ", " << setw( 4 )<< target(*edge_iter, *g) +1 << ")\n";
        adj_mat.at(source(*edge_iter, *g)  ).at(target(*edge_iter, *g)  ) = 1;
        adj_mat.at(target(*edge_iter, *g)  ).at(source(*edge_iter, *g)  ) = 1;
    }
    cout << "\n";


    vector<int> pre_color (nodes_num,0);
    if (readFromfile){
		for (int i=0;i<nodes_num;++i){
			ss >> pre_color.at(i) ;
		}
    }


    cout << "Colors: \n";
   	for (int i=0;i<nodes_num;++i){
		cout << pre_color.at(i)  <<" ";
	}
	cout << "\n";

    printMat(adj_mat);

    int colors_num = 9;
    graphcolor(nodes_num,colors_num,adj_mat,pre_color);

    return 0;
}