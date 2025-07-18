class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    // Each land cell contributes 4 sides
                    perimeter += 4;

                    // Subtract 2 for each shared side with an adjacent land cell
                    if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2; // check top
                    if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2; // check left
                }
            }
        }

        return perimeter;
    }
};
