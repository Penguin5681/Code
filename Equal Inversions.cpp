#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

#define int long long
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// member functions :
// 1. order_of_key(k) : number of elements strictly lesser than k (int)
// 2. find_by_order(k) : k-th element in the set (pointer)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define per(i, l, r) for (ll i = (l); i >= (r); i--)
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define NO cout << "NO" \
                << "\n"
#define YES cout << "YES" \
                 << "\n"
#define clr(x, y) memset(x, y, sizeof(x))
#define setbits(x) __builtin_popcountll(x)
#define mod 1000000007

const ll inf = 1e9;
const ll llinf = 2e18;
ll MULL(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll POWER(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = MULL(res, a);
        a = MULL(a, a);
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int same = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            same++;
        }
    }
    if (same >= (n + 1) / 2)
    {
        cout << n - same << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                cout << 1 << " " << i + 1 << endl;
            }
        }
        return;
    }
    same = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '0')
        {
            b[i] = '1';
        }
        else
        {
            b[i] = '0';
        }
        if (b[i] == a[i])
        {
            same++;
        }
    }
    cout << n - same + 1 << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << 1 << " " << i + 1 << endl;
        }
    }
    cout << 2 << endl;
    return;
}

signed main()
{
    godspeed;
    //    #ifndef ONLINE_JUDGE
    //       freopen("input.txt", "r", stdin);
    //       freopen("output.txt", "w", stdout);
    //    #endif
    tc
    {
        solve();
    }
    return 0;
}
