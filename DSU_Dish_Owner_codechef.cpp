// link to the problem: https://www.codechef.com/problems/DISHOWN

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void make_set(vector<ll>& parent, vector<ll>& size, ll i) {
    parent[i] = i;
    size[i] = 1;
}

ll find_set(vector<ll>& parent, vector<ll>& size, ll i) {
    if (i == parent[i]) {
        return i;
    }
    return parent[i] = find_set(parent, size, parent[i]);
}

void union_set(vector<ll>& parent, vector<ll>& size, vector<ll>& scores, ll a, ll b) {
    a = find_set(parent, size, a);
    b = find_set(parent, size, b);
    // if (a != b) {
    //     if (size[a] < size[b]) {
    //         swap(a, b);
    //     }
    //     parent[b] = a; // joining smaller tree to the larger tree
    //     size[a] += size[b];
    // }
    if (scores[a] > scores[b]) {
        parent[b] = a;
        size[a] += size[b];
    }
    else if (scores[b] > scores[a]) {
        parent[a] = b;
        size[b] += size[a];
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> scores(n + 1);
    for (ll i = 1; i < n + 1; i++) {
        cin >> scores[i];
    }

    //build the DSU
    vector<ll> parent(n + 10), size(n + 10);
    for (ll i = 1; i < n + 1; i++) {
        make_set(parent, size, i);
    }

    //queries
    ll q, type, x, y;
    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 0) {
            cin >> x >> y;
            if (find_set(parent, size, x) == find_set(parent, size, y)) {
                cout << "Invalid query!" << "\n";
            }
            else 
                union_set(parent, size, scores, x, y);            
        }
        else {
            cin >> x;
            cout << find_set(parent, size, x) << "\n";
        }
    }
}

void FIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    FIO();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
