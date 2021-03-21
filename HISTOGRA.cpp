#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <list>
#include <cstring>
#include <algorithm>

#define ll long long int
using namespace std;

ll M;

class segTree {
    // O(n)
    ll *array, *tree;
    ll arrayLen, treeLen;
    
    // O(n)
    void initialize(ll node, ll b, ll e) {
        if (b == e)
            tree[node] = b;
        else {
            // recurse
            initialize(2 * node, b, (b + e) / 2);
            initialize(2 * node + 1, (b + e) / 2 + 1, e);
            // update value
            if (array[tree[2 * node]] <= array[tree[2 * node + 1]])
                tree[node] = tree[2 * node];
            else
                tree[node] = tree[2 * node + 1];
        }
    }
public:
    segTree(ll *array, ll arrayLen) {
        this->arrayLen = arrayLen;
        this->array = array;
        this->treeLen = 2 << (int)ceil(log2(arrayLen));
        this->tree = new ll[treeLen];
        memset(tree, -1, sizeof(int) * treeLen);
        initialize(1, 0, arrayLen - 1);
    }
    
    // O(log n)
    void update(ll i, ll v, ll node = 1, ll b = 0, ll e = 0) {
        e = arrayLen - 1 - e;
        if (b == e) {
            array[i] = v;
        } else {
            ll mid = (b + e) / 2;
            if (i <= mid)
                update(i, v, 2 * node, b, arrayLen - 1 - mid);
            else
                update(i, v, 2 * node + 1, mid + 1, arrayLen - 1 - e);
            if (array[tree[2 * node]] <= array[tree[2 * node + 1]])
                tree[node] = tree[2 * node];
            else
                tree[node] = tree[2 * node + 1];
        }
    }
    
    // O(log n)
    ll query(ll i, ll j, ll node = 1, ll b = 0, ll e = 0) {
        e = arrayLen - 1 - e;
        // bad interval
        if (i > e || j < b)
            return -1;
        // good interval
        if (b >= i && e <= j)
            return tree[node];
        // partial interval
        ll left = query(i, j, 2 * node, b, arrayLen - 1 - (b + e) / 2);
        ll right = query(i, j, 2 * node + 1, (b + e) / 2 + 1, arrayLen - 1 - e);
        if (left == -1)
            return tree[node] = right;
        if (right == -1)
            return tree[node] = left;
        if (array[left] <= array[right])
            return tree[node] = left;
        return tree[node] = right;
    }
};

void recursive_computation(segTree t, ll arr[], ll a, ll b){
    if(a > b) { return; }
    if(b == a) {M = M > arr[a] ? M : arr[a];return;}
    ll min_idx = t.query(a, b);
    ll val1 = arr[min_idx]*(b-a+1);
    M = M < val1 ? val1 : M;
    recursive_computation(t, arr, a, min_idx-1);
    recursive_computation(t, arr,min_idx+1,b);
}

int main() {
    int n=1;
    cin >> n;
    while(n!=0){
        ll A[n];
        M = 0;
        for(int i = 0;i < n; i++){
            cin >> A[i];
        }
        segTree t(A,n);
        recursive_computation(t, A, 0, n-1);
        cout << M << endl;
                cin >> n;
    }
    return 0;
}
