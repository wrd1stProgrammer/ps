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

int d[305][4]; //
int s[305];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        int score;
        s[i] = score; // stair score
    }
    if (n == 1){
        cout << s[1];
        return 0;
    }
    //initial
    d[1][1]=s[1];
    d[1][2]=0;
    d[2][1]=s[2];
    d[2][2]=s[1]+s[2];

    for(int i=3;i<=n;i++){
        d[i][1] = max(d[i-2][2],d[i-2][1]) + s[i];
        d[i][2] = d[i-1][1] + s[i];
    }
    int maxD = max(d[n][1],d[n][2]);
    cout << maxD;

    return 0;
}