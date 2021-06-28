#include <bits/stdc++.h>
using namespace std;
 
//Prime Factorization using Sieve O(log n) for multiple queries
//https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/

int leastPrime[100000];

void leastPrimeNum(int N)
{ 
  leastPrime[1] = 1;
  
  for (int i = 2; i <= N; ++i)
  {
    if(leastPrime[i] == 0)
    { 
      leastPrime[i] = i;
      for(int j = i*i; j <= N; j += i)
      {
        leastPrime[j] = i;
      }
    }
  }

}

int main()
{   
    int T;
    cin >> T;
    while(T--){

      memset(leastPrime, 0, sizeof(leastPrime));
      std::vector<int> ans;

      int N;
      cin >> N;
      leastPrimeNum(N);
      while(N != 1)
      {
        ans.push_back(leastPrime[N]);
        N = N/leastPrime[N];
      }

      for (auto i = ans.begin(); i != ans.end(); i++)
        cout << *i << " ";
      cout << "\n";
    }
    return 0;
}

