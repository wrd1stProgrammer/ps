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

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응 입력 칸 임시 원래는 입력
bool vis[502][502]; // 방문 여부
int n=7;
int m=10;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,-1,0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue <pair<int,int> > q;
    vis[0][0] = 1;//첫 방문
    q.push({0,0}); // q push

    while (!q.empty())
    {
        pair<int,int> cur = q.front(); 
        q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // 순회하는 조ㅓ표임.

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue; // range over
            if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = 1; // visted mark
            q.push( {nx,ny} );

        }
    }
    
    return 0;

}