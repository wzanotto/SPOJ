// Example program
#include <iostream>
#include <string>

#include <stdio.h>
 using namespace std;
int gcd(int a, int b)
{
    // Everything divides 0 
    if (a == 0 || b == 0)
       return 0;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main()
{
  int a,b,c;
  cin >> a >> b >>c;
  cout << gcd(gcd(a,b),gcd(b,c));
}

