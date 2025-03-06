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

int m[26][26]; // apt
int vis[26][26]; // vis
int n;

vector<int> apt;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,-1,0};

int bfs(int x, int y){
    queue <pair<int,int>> q; // start Q
    int cnt = 1;
    q.push({x,y});
    vis[x][y] = 1;

    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();

        for(int dir =0;dir<4;dir++){
            int nx = cur.X +dx[dir];
            int ny = cur.Y +dy[dir];

            if(nx>=n || ny >=n || nx <0 || ny<0) continue;
            if(vis[nx][ny]==1 || m[nx][ny]!=1) continue;
            vis[nx][ny] = 1; //visted p
            q.push({nx,ny});
            cnt++;
        }
    }
    return cnt;
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

// 입력 처리 공백 없이 연속된 문자열이기에 문자로 받고 이걸 숫자로 변환 이때 -'0' 등을 수행함.
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            m[i][j] = line[j] - '0'; // '0' 또는 '1'을 숫자로 변환
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j] == 1 && vis[i][j] == 1 ){
                
                int res = bfs(i,j);
                apt.push_back(res);
            }
        }
    }
    sort(apt.begin(),apt.end());
    int tot = apt.size();

    cout << tot;

    for (int i=0;i<tot;i++){
        cout << apt[i] << '\n';
    }
    

    


    return 0;
}