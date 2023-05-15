#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    ll n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    ordered_multiset s;
    for(int i=0; i<k; i++){
        s.insert(arr[i]);
    }
 
    int index = k/2;
    if(k%2==0){
        index--;
    }
 
    for(int i=k; i<n; i++){
        int a = *s.find_by_order(index);
        cout << a << " ";
        s.erase(s.find_by_order(s.order_of_key(arr[i-k])));
        s.insert(arr[i]);
    }
    int a = *s.find_by_order(index);
    cout << a << "\n";
 
 
    return 0;
}
