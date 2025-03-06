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
int mn = 100000;  // max;
int ed = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,s;

    cin >> n >> s;

    for (int i=0;i<n;i++){
        cin >> a[i]; 
    }
    int tot = a[0]; 
    
    for (int st=0;st<n;st++){
        while (st<n && tot< s){
            ed++;
            tot+=a[ed];
        }
        if(ed == n) break; // end point
        mn = min (mn, ed-st);
        tot-=a[st];
    }
    
    if(mn == 'max'){
        cout << 0;
    }else{
        cout << mn;
    }



    return 0;
}