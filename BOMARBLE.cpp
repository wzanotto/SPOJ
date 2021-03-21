// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    int sum1,sum2;

    while(cin>>n){  
        if(n ==0){
            return 0;
        }
       sum1 = 5;
       sum2 = 0;
       int r1 = 5;
        int r2 = 3;
       for(int i = 1; i < n; i++){
            r1 += 5;
            sum1 += r1;
            sum2 += r2;
            r2 += 2;
       }
       cout << sum1 - sum2 << endl;
            
    }
    return 0;
    
}
