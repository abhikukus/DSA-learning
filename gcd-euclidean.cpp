#include <bits/stdc++.h>
using namespace std;
 
//Euclidean algorithm
//https://en.wikipedia.org/wiki/Greatest_common_divisor


// Driver Code
int GCD(int a, int b)
{ 
  int temp;
  // (a,b) -> (b, a%b)
  while(b != 0)
  { 
    temp = a;
    a = b;
    b = temp % b;
  }

  return a;
}

int main()
{   
    int T;
    cin >> T;
    while(T--){
      int L, B;
      cin >> L >> B;
      int ans = GCD(L, B);
      cout << ans << endl;
    }
    return 0;
}
