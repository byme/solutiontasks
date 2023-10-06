#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> adj;  
vector<bool> visited;    
int N, M;

int dfs(int node) {
    if (visited[node]) return 0;
    visited[node] = true;

    int size = 1; 
    for (int neighbor : adj[node]) {
        size += dfs(neighbor);
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);


    cin >> N >> M;
    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }

    vector<int> clusters;  

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            clusters.push_back(dfs(i));
        }
    }

    sort(clusters.begin(), clusters.end());

    cout << clusters.size() << endl; 
    for (int size : clusters) {
        cout << size << endl;
    }
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

    return 0;
}
