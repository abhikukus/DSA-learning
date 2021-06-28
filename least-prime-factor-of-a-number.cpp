#include <bits/stdc++.h>
using namespace std;
 
//Least prime factor of numbers till N
//https://www.geeksforgeeks.org/least-prime-factor-of-numbers-till-n/

int composite[100000];

int *primeNum(int N)
{ 
  composite[1] = 1;
  
  for (int i = 2; i <= N; ++i)
  {
    if(composite[i] == 0)
    { 
      composite[i] = i;
      for(int j = i*i; j <= N; j += i)
      {
        composite[j] = i;
      }
    }
  }

  return composite;
}

int main()
{   
    int T;
    cin >> T;
    while(T--){

      memset(composite, 0, sizeof(composite));

      int N;
      cin >> N;
      
      int* ans;
      ans = primeNum(N);
      for (int i = 0; i <= N; i++)
        cout << ans[i] << " ";
      cout << "\n";
    }
    return 0;
}

