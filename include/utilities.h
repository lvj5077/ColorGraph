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

typedef adjacency_list<vecS, vecS, undirectedS> UndirectedGraph;
typedef boost::erdos_renyi_iterator<boost::minstd_rand, UndirectedGraph> ERGen;
typedef pair<int, int> Edge;
typedef graph_traits<UndirectedGraph>::edge_iterator edge_iterator;

void printMat(vector< vector<int> > mat);
void printVec(vector<int> vec);

bool graphFromFile(string filename, UndirectedGraph &g,vector<int> &pre_color, int &nodes_num);
bool graphFromNode(int nodes_num, UndirectedGraph &g,vector<int> &pre_color);