#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

struct Node_
{
    ull value;
    int index;
    vector<int> in_nodes;
    vector<int> out_nodes;
    ull max_val;
};

typedef struct Node_ Node;

/*

Get level order traversal of the tree

*/
vector<int> get_level_order(vector<Node> &nodes)
{
    vector<int> ans;
    vector<int> curr_level;
    vector<int> next_level;
    curr_level.push_back(0);
    while (curr_level.size() > 0)
    {
        for (int i = 0; i < curr_level.size(); i++)
        {
            ans.push_back(curr_level[i]);
            for (int j = 0; j < nodes[curr_level[i]].in_nodes.size(); j++)
            {
                next_level.push_back(nodes[curr_level[i]].in_nodes[j]);
            }
        }
        curr_level = next_level;
        next_level.clear();
    }
    return ans;
}

ull soln(vector<Node> &nodes)
{

    // Do level-order traversal
    vector<int> level_order = get_level_order(nodes);

    // Debug print level order
    //  for(int i=0; i<level_order.size(); i++) {
    //      cout<<level_order[i]<<" ";
    //  }
    //  cout<<"\n";

    ull ans = 0;
    for(int i=level_order.size()-1; i>=0; i--) {
        if(nodes[level_order[i]].in_nodes.size() == 0) {
            nodes[level_order[i]].max_val = nodes[level_order[i]].value;
        }
        else {
            ull min_child = nodes[nodes[level_order[i]].in_nodes[0]].max_val;
            int min_idx = nodes[level_order[i]].in_nodes[0];
            for(int j=1; j<nodes[level_order[i]].in_nodes.size(); j++) {
                if(min_child > nodes[nodes[level_order[i]].in_nodes[j]].max_val) {
                    min_child = nodes[nodes[level_order[i]].in_nodes[j]].max_val;
                    min_idx = nodes[level_order[i]].in_nodes[j];
                }
            }
            for(int j=0; j<nodes[level_order[i]].in_nodes.size(); j++) {
                    if(nodes[level_order[i]].in_nodes[j] != min_idx) {
                        ans += nodes[nodes[level_order[i]].in_nodes[j]].max_val;
                    }
                }
            if(min_child <= nodes[level_order[i]].value) {
                nodes[level_order[i]].max_val = nodes[level_order[i]].value;
            }
            else {
                nodes[level_order[i]].max_val = min_child;
            }
        }
        if(i == 0) {
            ans += nodes[level_order[i]].max_val;
        }
    }

    return ans;
}

int main()
{
    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector<Node> nodes(N + 1);
        for (int i = 1; i <= N; i++)
        {
            int c;
            cin >> c;
            nodes[i].value = c;
            nodes[i].index = i;
        }
        nodes[0].value = 0;
        nodes[0].index = 0;
        for (int i = 0; i < N; i++)
        {
            int p;
            cin >> p;
            nodes[p].in_nodes.push_back(i + 1);
            nodes[i + 1].out_nodes.push_back(p);
        }
        ull ans = soln(nodes);
        cout << "Case #" << t + 1 << ": " << ans << "\n";
    }
}