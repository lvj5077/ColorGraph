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


bool pass(int k,vector< vector<int> > adj_mat, vector<int> color);
bool graphcolor(int nodes_num,int colors_num,vector< vector<int> > adj_mat,vector<int> pre_color, vector<int> &post_color);

bool graphcolorOPT(int nodes_num,vector< vector<int> > adj_mat,vector<int> pre_color, vector<int> &post_color);
