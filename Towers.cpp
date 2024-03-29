// <--------------------Jai Shree Babosa-------------------->

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    multiset<int> st;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto it = st.upper_bound(x);
        if (it == st.end())
            st.insert(x);
        else
        {
            st.erase(it);
            st.insert(x);
        }
    }
    cout << st.size();
}
int main()
{
    solve();
    return 0;
}