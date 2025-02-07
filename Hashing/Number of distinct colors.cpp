#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> distinctColors(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> ballToColor;  // Map to store ball -> color
    unordered_map<int, int> colorCount;   // Map to store color frequency
    vector<int> result;
    int distinctColorCount = 0;           // Number of distinct colors

    for (auto& query : queries) {
        int ball = query[0], newColor = query[1];

        // If the ball was already colored, remove its previous color count
        if (ballToColor.find(ball) != ballToColor.end()) {
            int oldColor = ballToColor[ball];
            colorCount[oldColor]--; // Reduce count of old color
            if (colorCount[oldColor] == 0) {
                distinctColorCount--; // Remove color if it becomes 0
            }
        }

        // Assign new color
        ballToColor[ball] = newColor;
        if (colorCount[newColor] == 0) {
            distinctColorCount++; // A new color is added
        }
        colorCount[newColor]++;

        // Store current number of distinct colors
        result.push_back(distinctColorCount);
    }

    return result;
}

int main() {
    vector<vector<int>> queries = {{1,4}, {2,5}, {1,3}, {3,4}};
    int limit = 4;
    vector<int> result = distinctColors(limit, queries);

    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
