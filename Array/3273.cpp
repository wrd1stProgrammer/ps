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

int a[1000002];
bool b[2000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,x;
    int cnt = 0; // pair 

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cin >> x;

    for(int i=0;i<n;i++){
        if(x-a[i]>0 && b[x-a[i]]) cnt++;
        b[a[i]] = true;
    }

    cout << cnt;


    return 0;
}