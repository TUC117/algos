#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1e9; // Infinity value for initialization
int minPeakMemory(const vector<vector<int>>& dependencies, const vector<int>& memory) {
    int n = dependencies.size();
    vector<int> dp(1 << n, INF); // dp[mask] represents the minimum peak memory requirement for processes in the subset represented by the bitmask mask
    dp[0] = 0; // Base case: No processes, no memory required

    for (int mask = 1; mask < (1 << n); ++mask) {
        // Iterate through all processes in the current subset represented by mask
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) {
                // Calculate the peak memory requirement for including process j in the subset
                int peakMemory = memory[j];
                for (int k = 0; k < n; ++k) {
                    if ((mask & (1 << k)) && dependencies[k][j]) {
                        peakMemory += dependencies[k][j];
                    }
                }
                // Update dp[mask] with the minimum peak memory requirement
                dp[mask] = min(dp[mask], peakMemory);
            }
        }
    }

    return dp[(1 << n) - 1]; // Return the minimum peak memory requirement for all processes
}
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<vector<int>> dependencies(n, vector<int>(n, 0));
    vector<int> memory(n);

    cout << "Enter the dependency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dependencies[i][j];
        }
    }

    cout << "Enter the memory requirement for each process: ";
    for (int i = 0; i < n; ++i) {
        cin >> memory[i];
    }

    int minPeakMemoryReq = minPeakMemory(dependencies, memory);
    cout << "Minimum peak memory requirement: " << minPeakMemoryReq << endl;

    return 0;
}
