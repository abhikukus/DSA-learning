#include <bits/stdc++.h>
using namespace std;
 
//PRIME NUMBERS till N
//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes



std::vector<int> primeNum(int N)
{ 
  std::vector<int> v;
  int composite[N+5] = {0};
  for (int i = 2; i <= N; ++i)
  {
    if(composite[i] == 0)
    { 
      v.push_back(i);
      for(int j = i*i; j <= N; j += i)
      {
        composite[j] = 1;
      }
    }
  }

  return v;
}

int main()
{   
    int T;
    cin >> T;
    while(T--){
      int N;
      cin >> N;
      std::vector<int> ans;
      ans = primeNum(N);
      for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
      cout << "\n";
    }
    return 0;
}

//for multiple test cases it can be further optimised 
//in a way that it doesnt need to calculate Primes
// that was previously calculated
