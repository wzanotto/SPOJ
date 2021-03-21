#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	int l,w,h,level;
	int s,stone;
	cin >> t;
for(int t_0 = 0; t_0 < t; t_0++){
    	vector <int> stones;
	cin >> l >> w >> h >> level;
	
	cin >> s;
	
	for(int i = 0; i < s; i++){
	    cin>>stone;
		stones.push_back(stone);
	}
	int result = 0;
	int count = stones.size()-1;
	int sum = h - level;
	sort(stones.begin(),stones.end());
	while(sum >= 0){
		sum -= stones[count];
		result++;
		count--;
	}
	cout <<result<<endl;
}

	return 0;
}
