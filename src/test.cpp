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
    vector<int> grid(81,0);
    for (int i=0;i<81;++i){
        grid.at(i) = i+1;
    }

    printVecSQ(grid);  


    return 0;
}