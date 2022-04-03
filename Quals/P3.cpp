#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int soln(vector<int> &arr) {
    int ans = 1;

    //Sort the array
    sort(arr.begin(), arr.end());

    int pt = 0;
    while(pt<arr.size()) {
        if(arr[pt]>=ans) {
            ans+=1;
        }
        pt+=1;
    }

    return ans-1;
}

int main() {
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        vector<int> arr;
        int N;
        cin>>N;
        for(int i=0; i<N; i++) {
            int c;
            cin >> c;
            arr.push_back(c);
        }
        cout<<"Case #"<<t+1<<": ";
        cout<<soln(arr)<<"\n";
    }
}