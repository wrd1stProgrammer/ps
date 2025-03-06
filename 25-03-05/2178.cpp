#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <bitset>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <numeric>
#include <utility>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
#include <complex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>

using namespace std;
#define X first
#define Y second 

int n;
int m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int a[105][105];
int vis[105][105]; // 발자국 수

void bfs(int x,int y){
    queue <pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1; // 첫번재 발자국

    while (!q.empty())
    {
        pair <int,int> cur = q.front();
        q.pop();

        for(int d=0;d<4;d++){
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];

            if(nx>n || ny >m || nx <1 || ny <1) continue;
            if(vis[nx][ny] != 0 || a[nx][ny]==0) continue; // 방문 된 거면 무시
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }


    }
    


}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        string line;
        cin >> line;

        for(int j=0;j<m;j++){
            a[i][j+1] = line[j] - '0';
        }
    }

    bfs(1,1);

    cout << vis[n][m];



    return 0;
}