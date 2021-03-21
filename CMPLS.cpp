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

#define ll long long int
using namespace std;

int main(void)
{
    bool is_const;
    ll t,n,val,c;
    vector <ll> start;
    vector <ll> D;
    vector <ll> last_val;
    vector < vector<ll> > res;
    cin>>t;
    while(t--){
        start.clear();
        D.clear();
        res.clear();
        cin >> n >> c;
        is_const = true;
        // WARUNEK CIĄG TRYWIALNY
        if(n == 1){
            cin >> val;
            while(--c){ cout << val << " ";}
            cout << val << endl;
            continue;
        }
        //WCZYTYWANIE
        for(int i = 0; i < n; i++){
            cin >> val;
            start.push_back(val);
            if(is_const && i > 0 && start[i-1] != start[i]) is_const = false;
        }
        //WARUNEK CIĄG STAŁY
        if(is_const){
            while(--c){ cout << val << " ";}
            cout << val << endl;
            continue;
        }
        while(true){
            res.push_back(start);
            is_const = true;
            for(int i = 1; i < start.size(); i++){
                D.push_back(start[i] - start[i-1]);
                if(is_const && i > 0 && start[i-1] != start[i]) is_const = false;
            }
            if(D.size() == 0 || is_const) break;
            //for(int i = 0; i < D.size(); i++){ cout << D[i] << " ";}cout << endl;
            start = D;
            D.clear();
        }
        while( res[res.size()-1].size() < n + c){res[res.size()-1].push_back(res[res.size()-1][0]);}
        for(int i = res.size()-2; i >= 0; i--){
            int j = res[i].size()-1;
            int k = 0;
            while(j < n + c){
                res[i].push_back(res[i][j] + res[i+1][j]);
                j++;
            }
        }
        for(int i = n; i < n + c - 1; i++){ cout << res[0][i] << " ";}
        cout << res[0][n+c-1]<< endl;
    }
}
