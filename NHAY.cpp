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

using namespace std;

int main(){
    int t;
    string s1,s2;
    while(cin >> t){
        cin.ignore();
        getline(cin,s1);
        getline(cin,s2);
        size_t idx = s2.find(s1);
        if(idx == string::npos) cout << endl;
        while(idx != string::npos){
        cout << idx << endl;
            idx = s2.find(s1,idx + 1);
        }
    }
    return 0;
}

