// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxLength(string s)
    {
        int n = s.length();
        int left = 0, right = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
                left++;
            else
            {
                right++;
                if(right > left)
                {
                    left = 0;
                    right = 0;
                }
            }
            if(left==right)
                ans = max(ans, 2*left);
        }
        
        left = 0;
        right = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == '(')
            {
                left++;
                if(left > right)
                {
                    left = 0;
                    right = 0;
                }
            }
            else
                right++;
            if(left==right)
                ans = max(ans, 2*left);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
