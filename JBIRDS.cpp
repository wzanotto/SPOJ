#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> parrots;
	int p,parrot;
	int sum = 0;
	cin >> p;
	for(int p_0 = 0; p_0 < p; p_0++){
		cin>>parrot;
		sum += parrot;
		parrots.push_back(parrot);
	}
	sort(parrots.begin(),parrots.end());
	int left = sum;
	int barrier = sum/2;
	int counter = parrots.size()-1;
	while(counter >=0){
		if(left - parrots[counter] >= barrier){
			left -= parrots[counter];
		}
		counter--;
	}
	cout << abs(left - (sum - left));

	return 0;
}
