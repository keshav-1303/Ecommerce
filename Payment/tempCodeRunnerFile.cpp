#include <iostream>
#include <vector>
using namespace std;

int trapWithPrefixSuffixArray(vector<int>& heights) {
    vector<int> prefix(heights.size(), 0), suffix(heights.size(), 0);

    for (int i = 1; i < heights.size(); i++)
        prefix[i] = max(prefix[i - 1], heights[i - 1]);

    for (int i = heights.size() - 2; i >= 0; i--)
        suffix[i] = max(suffix[i + 1], heights[i + 1]);

    int trappedWater = 0;
    for (int i = 0; i < heights.size(); i++)
        trappedWater += max(0, min(prefix[i], suffix[i]) - heights[i]);

    return trappedWater;
}

int trapWithTwoPointers(vector<int>& heights) {
    int left = 0, right = heights.size() - 1;
    int leftMax = 0, rightMax = 0;
    int trappedWater = 0;

    while (left <= right) {
        if (heights[left] <= heights[right]) {
            if (heights[left] >= leftMax)
                leftMax = heights[left];
            else
                trappedWater += leftMax - heights[left];
            left++;
        } else {
            if (heights[right] >= rightMax)
                rightMax = heights[right];
            else
                trappedWater += rightMax - heights[right];
            right--;
        }
    }
    return trappedWater;
}

int main() {
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trappedWaterPrefixSuffixArray = trapWithPrefixSuffixArray(heights);
    int trappedWaterTwoPointers = trapWithTwoPointers(heights);

    cout << "Trapped water using Prefix-Suffix array method: " << trappedWaterPrefixSuffixArray << endl;
    cout << "Trapped water using Two-pointer method: " << trappedWaterTwoPointers << endl;

    return 0;
}
