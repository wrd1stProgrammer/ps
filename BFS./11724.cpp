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

int n,m; // j,g
int a[1002][1002];
int vis[1002];
queue<int> q;

int cnt;

void dfs(int x){
    vis[x]=1;

    for(int i=1;i<=n;i++){
        if(a[x][i]==1 && !vis[i]){
            dfs(i);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int u,v; // u != v 
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}