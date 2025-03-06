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
int a[2][26];
string s1,s2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int res=0;

    cin >> s1;
    cin >> s2;

    for (char c : s1){
        a[0][c-'a']++;
    }
    for (char c : s2){
        a[1][c-'a']++;
    }

    for(int i=0;i<26;i++){
        res+= abs(a[0][i] - a[1][i]);
    }


    cout << res;


    return 0;
}