#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <typeinfo>

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"

using namespace boost;
using namespace std;

ofstream tsfile;
int main(int argc, char *argv[])
{
    //create an -undirected- graph type, using vectors as the underlying containers
    //and an adjacency_list as the basic representation
    typedef adjacency_list<vecS, vecS, undirectedS> UndirectedGraph;
    typedef std::pair<int, int> Edge;

    //Example uses an array, but we can easily use another container type
    //to hold our edges. 
    std::vector<Edge> edgeVec;
    // edgeVec.push_back(Edge(0,1));
    int row=9;
    int col=9;
    int max = row*col;

    for (int s =0;s<max;++s){
        int j = floor(s/col);
        int i = s-col*j;
        cout <<"s " << s  <<"; i " << i  <<"; j " << j <<endl;
        for (int t=0;t<max;++t){
                if (s>=t){
                    continue;
                }
                if (floor(s/col) != floor(t/col) && (s-col*floor(s/col)) != (t-col*floor(t/col))){
                    continue;
                }
                edgeVec.push_back(Edge(s,t));   
        }
    }

    std::vector<int> grid = {0,1,2,9,10,11,18,19,20};
    std::vector<int> add = {0,3,6,27,30,33,54,57,60};
    for (int i =0;i<9;++i){
        for (int x=0;x<9;++x){
            for (int y=0;y<9;++y){
                if (grid.at(x)!=grid.at(y))
                    edgeVec.push_back(Edge(grid.at(x)+add.at(i),grid.at(y)+add.at(i)));   
            }
        }
    }

    sort( edgeVec.begin(), edgeVec.end() );
    edgeVec.erase( unique( edgeVec.begin(), edgeVec.end() ), edgeVec.end() );

    //Now we can initialize our graph using iterators from our above vector
    UndirectedGraph g(edgeVec.begin(), edgeVec.end(), max+1);

    std::cout << "num_edges(g) " << num_edges(g) << "\n";

    //Ok, we want to see that all our edges are now contained in the graph
    typedef graph_traits<UndirectedGraph>::edge_iterator edge_iterator;

    //Tried to make this section more clear, instead of using tie, keeping all
    //the original types so it's more clear what is going on
    std::pair<edge_iterator, edge_iterator> ei = edges(g);

    tsfile.open("sudoku9.txt");

    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        std::cout << "" << source(*edge_iter, g)+1 << " " << target(*edge_iter, g)+1 << "\n";
        stringstream ss;
        ss << source(*edge_iter, g)+1 << " "<< target(*edge_iter, g)+1;
        string edge_info = ss.str();
        tsfile << edge_info <<"\n";
    }
    std::cout << "num_edges(g) " << num_edges(g) << "\n";

    return 0;
}