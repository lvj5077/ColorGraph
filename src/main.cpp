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

int main(int argc, char *argv[])
{
    //create an -undirected- graph type, using vectors as the underlying containers
    //and an adjacency_list as the basic representation
    typedef adjacency_list<vecS, vecS, undirectedS> UndirectedGraph;
    typedef boost::erdos_renyi_iterator<boost::minstd_rand, UndirectedGraph> ERGen;
    typedef std::pair<int, int> Edge;
    //Ok, we want to see that all our edges are now contained in the graph
    typedef graph_traits<UndirectedGraph>::edge_iterator edge_iterator;

    std::cout << "_________________________________________\n";
    boost::minstd_rand gen;

    int nodes_num = 4;

    UndirectedGraph g(ERGen(gen, nodes_num, 0.5), ERGen(),nodes_num);
    std::cout << num_edges(g) << "\n";

    std::pair<edge_iterator, edge_iterator> ei = edges(g);
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        std::cout << "(" << source(*edge_iter, g) << ", " << target(*edge_iter, g) << ")\n";
    }
    return 0;
}