// https://www.spoj.pl/problems/PALIN/
// Concept: http://www.algorithmist.com/index.php/SPOJ_PALIN
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool lessThan(vector<int> obj1, vector<int> obj2);
void helper(const vector<int> &input, vector<int> &output, int stage=0);

int main(){
	int count;
	cin >> count;

	// Get Rid of new line
	string temp;
	getline(cin, temp);

	while (count--){
		// Get input
		string input;
		getline(cin, input);

		// Now split string into individual integers
		vector<int> inputVector;
		bool nine = true;
		for (string::iterator it = input.begin(); it < input.end(); it++){
			nine &= (*it) == '9';	// Check for all nines
			inputVector.push_back( ((*it) - 48) );	// ASCII
		}

		// Now get length
		int length = inputVector.size();

		// If all nine - Edge Case
		if (nine){
			cout << 1;
			for (int i = 0; i < length-1; i++)
				cout << 0;
			cout << 1 << endl;
			continue;
		}

		// Now let's see if we have odd or even
		bool isOdd = length % 2 == 1;

		vector<int> result = vector<int>(inputVector);


		// Mirror the number
		int begin = length/2;
		int j = begin - 1;
		if (isOdd){
			begin++;
		}
		for (int i = begin; i < length; i++, j--){
			result[i] = result[j];
		}

		if (!lessThan(inputVector, result))
			// Recursive helper
			helper(inputVector, result);

		for (int i = 0; i < result.size(); i++){
			cout << result[i];
		}
		cout << endl;
	}
}

// Helper function.
// This is strictly less than
bool lessThan(vector<int> obj1, vector<int> obj2){
	if (obj1.size() != obj2.size()){
		return obj1.size() < obj2.size();
	}

	for (int i = 0; i < obj1.size(); i++){
		if (obj1[i] != obj2[i])
			return obj1[i] < obj2[i];
	}

	return false;
}
// Recursive helper
void helper(const vector<int> &input, vector<int> &output, int stage){
	// Time to terminate
	if (stage > input.size()/2)
		return;

	if (stage == 0){
		// Okay, let's see if this is an odd thing
		if (output.size() % 2){
			int centerIndex = output.size()/2;
			if (output[centerIndex] == 9){
				output[centerIndex] = 0;
				helper(input, output, 1);
			}
			else{
				output[centerIndex]++;
				return;	// Done
			}
		}
		else{
			// Just do stage 1;
			stage = 1;
		}
	}
	if (stage > 0){
		// Indices
		int left, right;
		left = output.size()/2 - stage;
		if (output.size() % 2){
			right = output.size()/2 + stage;
		}
		else{
			right = output.size()/2 + stage - 1;
		}

		if (output[left] == 9){
			output[left] = 0;
			output[right] = 0;
			helper(input, output, stage+1);
		}
		else{
			output[left]++;
			output[right]++;
		}
	}
}
