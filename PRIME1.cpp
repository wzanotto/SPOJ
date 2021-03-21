#include <iostream>
#include<math.h>
using namespace std;

bool is_prime(int n){
    if(n == 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
void generate(int a, int b){
    for(int i = a; i <= b; i++){
        if(is_prime(i)){
            cout<<i<<endl;
        }
    }
}

int main() {
    int t,a,b;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        generate(a,b);
        //cout<<endl;
    }
    return 0;
}
