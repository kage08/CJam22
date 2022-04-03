#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void soln(vector<int> &C, vector<int> &M, vector<int> &Y, vector<int> &K, int N) {
    vector<int> ans(4,0);
    ans[0] = *min_element(C.begin(), C.end());
    ans[1] = *min_element(M.begin(), M.end());
    ans[2] = *min_element(Y.begin(), Y.end());
    ans[3] = *min_element(K.begin(), K.end());

    // Check if sum is less than N
    int sum = ans[0] + ans[1] + ans[2] + ans[3];
    if(sum<N){
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }

    for(int i=0; i<4; i++) {
        if (sum-N<=ans[i]) {
            ans[i] -= sum-N;
            break;
        }
        else {
            sum -= ans[i];
            ans[i] = 0;
        }
    }
    for(int i=0; i<4; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}

int main() {
    int T, N;
    cin >> T;
    N = 1000000;
    for(int t=0; t<T; t++) {
        vector<int> C, M, Y, K;
        for(int i=0; i<3; i++) {
            int c, m, y, k;
            cin >> c >> m >> y >> k;
            C.push_back(c);
            M.push_back(m);
            Y.push_back(y);
            K.push_back(k);
        }
        cout<<"Case #"<<t+1<<": ";
        soln(C, M, Y, K, N);
    }
}