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

int max_arrows(int N, int K, vector<int>& distances) {
    int left = 0, right = 0;
    long long current_sum = 0; // Using long long for larger sums.
    int max_length = 0;

    while (right < N) {
        current_sum += distances[right];

        while (current_sum > K) {
            current_sum -= distances[left];
            left++;
        }

        max_length = max(max_length, right - left + 1);
        right++;
    }

    return max_length;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> distances(N);

    for (int i = 0; i < N; i++) {
        cin >> distances[i];
    }

    cout << max_arrows(N, K, distances) << endl;
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

    return 0;
}