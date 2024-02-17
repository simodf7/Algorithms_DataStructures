#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_COINS 52

int wt[MAX_COINS];

int max_sum[MAX_COINS][MAX_COINS*500];
 
int knapSack(int total_coins, int weigth_limit)
{
  int i,j;

  for(i=0; i <= weigth_limit; i++)
    max_sum[0][i] = 0;
 
  for(i=1; i<=total_coins; i++)
    for(j=0; j <= weigth_limit; j++)
    {
      if(wt[i] <= j)
         max_sum[i][j] = max(max_sum[i-1][j], max_sum[i-1][j-wt[i]] + wt[i]);
      else
         max_sum[i][j] = max_sum[i-1][j];
    }
  return max_sum[total_coins][weigth_limit];
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int i = 1;

    int test, sum, n;
    cin>>test;
    while(test--){+
        cin>>n;
        sum = 0;
        for(int i = 1; i<=n; i++){
            cin>>wt[i];
            sum +=wt[i];
            }

    cout<<"Test Case #"<<i<<": "<<sum - 2*knapSack(n, sum/2)<<"\n";
    i++;
    }
    return 0;
}


/*
input:
3 
4 
4 8 7 9 
6 
4 6 7 8 2 3 
3 
12 54 26

output
2
0
16

*/


//complessità pseudo-polinomiale: O(nS)  (si usa algoritmo knapSack per risolvere il problema)