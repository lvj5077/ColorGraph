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

// A C++ program to implement greedy algorithm for graph coloring
#include <iostream>
#include <list>
using namespace std;
 
// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints greedy coloring of the vertices
    void greedyColoring();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring()
{
    int result[V];
 
    // Assign the first color to first vertex
    result[0]  = 0;
 
    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
        result[u] = -1;  // no color is assigned to u
 
    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
 
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;
 
        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;
 
        result[u] = cr; // Assign the found color
 
        // Reset the values back to false for the next iteration
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
 
    // print the result
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;
}
 
// Driver program to test above function
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
    Graph g1(nodes_num);

    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
    // note: vector index from 0 but we index node from 1 conventionally
        // cout << "(" << setw( 4 )<< source(*edge_iter, g) +1  << ", " << setw( 4 )<< target(*edge_iter, g) +1 << ")\n";
        adj_mat.at(source(*edge_iter, g)  ).at(target(*edge_iter, g)  ) = 1;
        adj_mat.at(target(*edge_iter, g)  ).at(source(*edge_iter, g)  ) = 1;
        g1.addEdge(source(*edge_iter, g), target(*edge_iter, g));
    }
    cout << "\n";

    cout << "Coloring of graph 1 \n";
    g1.greedyColoring();
 
    return 0;
}