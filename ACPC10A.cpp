// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a1,a2,a3;
    while(cin>> a1 >> a2 >> a3){  
        if(a1 == 0 && a2 == 0 && a3 ==0){
            return 0;
        }
            int next1 = a2 - a1;
            int next2 = a2/a1;
            if(a3 == a2 + next1){
                cout << "AP" << " " << a3+next1 << endl;
            }else{
                cout << "GP" << " " << a3*next2 << endl;
            }
            
    }
    return 0;
    
}
