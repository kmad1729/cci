//solution to https://community.topcoder.com/stat?c=problem_statement&pm=1110
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

class Node {
    public:
        int posA_X, posA_Y, posB_X, posB_Y;
        int steps;
};

class PathFinding {
    public:
        bool visited[20][20][20][20];
        queue<Node> q;

        void push_to_queue(queue<Node>& q, Node n) {
            if(visited[n.posA_X][n.posA_Y][n.posB_X][n.posB_Y]) return;
            q.push(n);
            visited[n.posA_X][n.posA_Y][n.posB_X][n.posB_Y] = true;
        }

        int minTurns(vector<string> board) 
        {
            int width = board[0].size();
            int height = board.size();


            //initialize visited array
            memset(visited, false, sizeof(visited));

            //initialize start node
            Node start;
            start.steps = 0;
            for(int r = 0; r < height; r++) {
                for(int c = 0; c < width; c++) {
                    if(board[r][c] == 'A') {
                        start.posA_X = r;
                        start.posA_Y = c;
                    } else if (board[r][c] == 'B'){
                        start.posB_X = r;
                        start.posB_X = c;
                    }
                }
            }

            push_to_queue(q, start);

            while(!q.empty()) {
                Node top = q.front();
                q.pop();
                
                //check if A and B are out of bounds
                if((top.posA_X < 0) || (top.posA_X >= height) ||
                    (top.posB_X < 0) || (top.posB_X >= height) ||
                    (top.posA_Y < 0) || (top.posA_Y >= width) ||
                    (top.posB_Y < 0) || (top.posB_Y >= width))
                    continue;

                //check if A and B are on top of one another
                if( (top.posA_X == top.posB_X) &&
                        (top.posA_Y == top.posB_Y))
                    continue;

                if( (top.posA_X == start.posB_X) &&
                        (top.posB_X == start.posA_X) &&
                        (top.posA_Y == start.posB_Y) &&
                        (top.posB_Y == start.posA_Y))
                    return top.steps;

                for (int A_X_delta = -1; A_X_delta <= 1; A_X_delta++) {
                    for (int A_Y_delta = -1; A_Y_delta <= 1; A_Y_delta++) {
                        for (int B_X_delta = -1; B_X_delta <= 1; B_X_delta++) {
                            for (int B_Y_delta = -1; B_Y_delta <= 1; B_Y_delta++) {
                                if((top.posA_X == top.posB_X + B_X_delta) &&
                                    (top.posB_X == top.posA_X + A_X_delta) &&
                                    (top.posA_Y == top.posB_Y + B_Y_delta) &&
                                    (top.posB_Y == top.posA_Y + A_Y_delta) )
                                    continue;

                                Node new_node;
                                new_node.posA_X =  top.posA_X + A_X_delta,
                                new_node.posA_Y = top.posA_Y + A_Y_delta,
                                new_node.posB_X = top.posB_X + B_X_delta,
                                new_node.posB_Y = top.posB_Y + B_Y_delta;
                                
                                if((new_node.posA_X < 0) || (new_node.posA_X >= height) ||
                                    (new_node.posB_X < 0) || (new_node.posB_X >= height) ||
                                    (new_node.posA_Y < 0) || (new_node.posA_Y >= width) ||
                                    (new_node.posB_Y < 0) || (new_node.posB_Y >= width))
                                    continue;
                                new_node.steps = top.steps + 1;
                                push_to_queue(q, new_node);
                            }
                        }
                    }
                }


            }

            return -1;
        }
};


int main()
{
    string brd[] = {
        "....",
        ".A..",
        "..B.",
        "...."};

    vector<string> inp_brd;
    inp_brd.push_back("....");
    inp_brd.push_back(".A..");
    inp_brd.push_back("..B.");
    inp_brd.push_back("....");
    PathFinding pf;
    cout << pf.minTurns(inp_brd) << endl;

}
