//Inviational 02 Semifinal Room 2 – Div 1 500 – Escape
//http://community.topcoder.com/tc?module=ProblemDetail&rd=4371&pm=1170

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include <climits>
#include <queue>
#include <cstring>

#define GRAPH_SIZE 501

using namespace std;

class Escape {
    public:
        void mark_coords_in_graph(char graph[GRAPH_SIZE][GRAPH_SIZE],
                const string& bounds, char node_val) {
            istringstream iss(bounds);
            int X1, Y1, X2, Y2;
            iss >> X1 >> Y1 >> X2 >> Y2;

            if(X1 <= X2) {
                if(Y1 <= Y2) {
                    for(int r = X1; r <= X2; r++) {
                        for(int c = Y1; c <= Y2; c++) {
                            graph[r][c] = node_val;
                        }
                    }
                } else {
                    for(int r = X1; r <= X2; r++) {
                        for(int c = Y2; c >= Y1; c--) {
                            graph[r][c] = node_val;
                        }
                    }
                }
            } else {
                if(Y1 <= Y2) {
                    for(int r = X1; r >= X2; r--) {
                        for(int c = Y1; c <= Y2; c++) {
                            graph[r][c] = node_val;
                        }
                    }
                } else {
                    for(int r = X1; r >= X2; r--) {
                        for(int c = Y2; c >= Y1; c--) {
                            graph[r][c] = node_val;
                        }
                    }
                }
            }
        }
        int lowest(vector<string> harmful, vector<string> deadly) {
            char graph[GRAPH_SIZE][GRAPH_SIZE];
            memset(graph, 'N', sizeof(graph));
            for(size_t i = 0; i < harmful.size(); i++) {
                mark_coords_in_graph(graph, harmful[i], 'H');
            }
            for(size_t i = 0; i < deadly.size(); i++) {
                mark_coords_in_graph(graph, deadly[i], 'D');
            }

            typedef pair<int, int> node;
            int results[GRAPH_SIZE][GRAPH_SIZE];
            for(int r = 0; r < GRAPH_SIZE; r++) {
                for(int c = 0; c < GRAPH_SIZE; c++) {
                    results[r][c] = INT_MAX;
                }
            }
            results[0][0] = 0;
            queue<node> q;
            q.push(node(0, 0));

            //cout << results[1][0] << endl;

            while(!q.empty()) {
                node front = q.front();
                q.pop();


                node possible_nodes[] = {
                    node(front.first + 1, front.second),
                    node(front.first - 1, front.second),
                    node(front.first, front.second + 1),
                    node(front.first, front.second - 1)
                };

                for(size_t i = 0; i < 4; i++) {
                    node curr_node = possible_nodes[i];

                    if(curr_node.first < 0 || curr_node.first > GRAPH_SIZE - 1)
                        continue;
                    if(curr_node.second < 0 || curr_node.second > GRAPH_SIZE - 1)
                        continue;

                    char curr_node_val = 
                        graph[curr_node.first][curr_node.second];


                    //cout  << curr_node.first << " " << curr_node.second << endl;
                    if(curr_node_val != 'D') {
                        int curr_result = results[front.first][front.second];
                        if(curr_node_val == 'N') {
                            curr_result = curr_result;
                        } else if(curr_node_val == 'H') {
                            curr_result = curr_result + 1;
                        }

                        if(curr_result < results[curr_node.first][curr_node.second]) {
                            results[curr_node.first][curr_node.second] =
                                curr_result;
                            q.push(curr_node);
                        }
                    }
                }
            }

            if(results[GRAPH_SIZE - 1][GRAPH_SIZE - 1] == INT_MAX)
                return -1;
            else
                return results[GRAPH_SIZE - 1][GRAPH_SIZE - 1];
        }
};

int main()
{
    Escape e;
    vector<string> deadly;
    vector<string> harmful;

    harmful.push_back("500 0 0 500");
    deadly.push_back("0 0 0 0");

    cout << e.lowest(harmful, deadly) << endl;
}
