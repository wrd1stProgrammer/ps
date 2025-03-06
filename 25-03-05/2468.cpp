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
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int a[102][102];
int chk[102][102];
int res=0;

void bfs(int x,int y,int h){
    queue<pair<int,int>> q;
    q.push({x,y});

    while (!q.empty())
    {
        pair <int,int> cur = q.front();
        q.pop();

        for(int dir = 0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx > n || ny > n || nx<0 || ny<0 ) continue;
            if(chk[nx][ny] == 1 || a[nx][ny] <=h) continue;

            chk[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    } // 10^4

    for(int h=0;h<100;h++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j] <= h) chk[i][j] = 1; // ex vis=1
                else {
                    chk[i][j] = 0; // possible
                }
            }   
        }
        int cnt = 0; 
        
        // 위는 h가 0~100 돌며 chk 값이 바뀜.
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(chk[i][j] == 0){
                    bfs(i,j,h);
                    cnt++;
                }
            }
        }
        res = max(cnt, res);
    }

    cout << res;

    return 0;
}