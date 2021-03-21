// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int x,y,num;
    for(int t_0 = 0; t_0 < t; t_0++){
            cin >> x >> y;
            if(x == y){
                num = 2*x;
                if(x % 2 != 0){
                    num--;
                }
            }else if(x == y + 2){
                num = (x*2) - 2;
                if(x%2 != 0){
                    num--;
                }
            }else{
                cout << "No Number" << endl;
                continue;
            }
            cout << num << endl;
    }
    return 0;
    
}
