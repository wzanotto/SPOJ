#include <iostream>
#include<math.h>
using namespace std;

int zeros(int n){
    int result = 0;
    int mul5 = 5;
    while(n / mul5 != 0){
        result += n/mul5;
        mul5*=5;
    }
    return result;
}
int main() {
    int t,n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin>>n;
        cout<<zeros(n)<<endl;
        //cout<<endl;
    }
    return 0;
}
