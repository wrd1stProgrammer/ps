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

#define MAX 101


int a[MAX][MAX]; // node
bool vis[MAX]; // visited
int n,c;
int cnt = 0;

queue<int> q;

void bfs(int s){
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int m = q.front();
        q.pop();

        for(int i=1;i<=n;i++){
            if(a[m][i] && !vis[i]){
                cnt++;
                q.push(i);
                vis[i] = true;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for (int i=0;i<c;i++){
        int st,ed;
        cin >> st >> ed;
        a[st][ed]=1;
        a[ed][st]=1;
    }
    bfs(1); // 1 start

    cout << cnt; 


    return 0;
}