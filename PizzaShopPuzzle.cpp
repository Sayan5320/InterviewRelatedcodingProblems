#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends

class Solution {
public:

        long long findMinCost(vector<long long>pizzas, vector<long long>toppings, long long x)
        {
                //code here
                sort(toppings.begin(), toppings.end());
                long long n = pizzas.size(), m = toppings.size();
                long long ans = 0, min_dif = 1e18 + 5;
                for (long long i = 0; i < n; ++i)
                {
                        //Considering 0 toppings
                        long long d = abs(pizzas[i] - x);
                        if (d < min_dif)
                        {
                                min_dif = d;
                                ans = pizzas[i];
                        }
                        else if (d == min_dif)
                        {
                                ans = min(ans, pizzas[i]);
                        }

                        //Considering 1 and 2 toppings
                        for (long long j = 0; j < m; ++j)
                        {
                                long long k = pizzas[i] + toppings[j];
                                d = abs(x - k);
                                if (d < min_dif)
                                {
                                        min_dif = d;
                                        ans = k;
                                }
                                else if (d == min_dif)
                                {
                                        ans = min(ans, k);
                                }

                                if (k >= x)
                                        break;
                                long long h = x - k;
                                auto it = lower_bound(toppings.begin() + j + 1, toppings.end(), h);
                                if (it != toppings.end())
                                {
                                        long long g = k + (*it);
                                        d = abs(x - g);
                                        if (d < min_dif)
                                        {
                                                min_dif = d;
                                                ans = g;
                                        }
                                        else if (d == min_dif)
                                        {
                                                ans = min(ans, g);
                                        }
                                }
                                if (it != (toppings.begin() + j + 1))
                                {
                                        it--;
                                        long long g = k + (*it);
                                        d = abs(x - g);
                                        if (d < min_dif)
                                        {
                                                min_dif = d;
                                                ans = g;
                                        }
                                        else if (d == min_dif)
                                        {
                                                ans = min(ans, g);
                                        }
                                }
                        }
                }
                return ans;
        }
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N, M, X;
        cin >> N >> M;
        vector<long long int>pizzas(N), toppings(M);
        for(int i =0;i<N;i++){
            cin>>pizzas[i];
        }
        for(int i =0;i<M;i++){
            cin>>toppings[i];
        }
        cin >> X;
        Solution ob;
        long long int ans= ob.findMinCost(pizzas, toppings, X);
        cout << ans;
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
