class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int n = image.size();
        int m = image[0].size();
        int visited[n*m];
        memset(visited, 0, sizeof(visited));
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            visited[x*m + y] = 1;
            if (x-1 >= 0 && !visited[m*(x-1) + y] && image[sr][sc] == image[x-1][y]) {
                q.push({x-1, y});
                image[x-1][y] = color;
            }
            if (x+1 < n && !visited[(x+1) * m + y] && image[sr][sc] == image[x+1][y] ) {
                q.push({x+1, y});
                image[x+1][y] = color;
            }
            if (y-1 >= 0 && !visited[x*m + y - 1] && image[sr][sc] == image[x][y-1]) {
                q.push({x, y-1});
                image[x][y-1] = color;
            }
            if (y+1 < m  && !visited[x*m + y + 1] && image[sr][sc] == image[x][y+1]) {
                q.push({x, y+1});
                image[x][y+1] = color;
            }
        }
        image[sr][sc] = color;
        return image;
    }
};