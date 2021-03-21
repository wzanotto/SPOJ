#include <iostream>
#include <vector>

using namespace std;

bool is_ok(int x,int n,int k,int a){
    int res= 1;
    for(int i = 0; i < k; i++){
        res *= x;
        res %= n;
    }
    if(res % n == a){
        return true;
    }else{
        return false;
    }
}
int main() {
	vector <int> res;
	int n,k,a;
	cin >> n >> k >> a;
	for(int x = 1; x < n; x++){
	    if(is_ok(x,n,k,a)){
	        res.push_back(x);
	    }
	}
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++){
	    cout << res[i];
	}

	return 0;
}


