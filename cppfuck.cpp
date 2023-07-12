#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

typedef long long ll;

#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define db(x) cout << (x) << '\n';
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define all(x) x.begin(), x.end()
#define ins insert

// #pragma GCC target ("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (int i = 0; i < vec.size() - 1; i++)
        os << vec[i] << ' ';
    os << vec.back() << '\n';
    return os;
}

template <typename T>
istream &operator>>(istream &os, vector<T> &v) {
    for (T &i : v)
        os >> i;
    return os;
}





int main(void) {
    faster
#ifndef ONLINE_JUDGE
        clock_t start = clock();
#endif













#ifndef ONLINE_JUDGE
    clock_t finish = clock();
    auto time = (int)((1e3) * ((double)(finish - start) / (CLOCKS_PER_SEC)));
    int num = (time == 0) ? 1 : log10(time) + 1;
    string stars = "****";
    while (num--)
        stars += "*";
    cerr << stars << endl
         << "*" << time << "ms*" << endl
         << stars << endl;
#endif
}