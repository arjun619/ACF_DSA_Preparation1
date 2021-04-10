#include <bits/stdc++.h>
#include<string.h>
#include<string>
using namespace std;
unordered_map<string,int>dp;
int wordbreak(vector<string>arr,string s)
{

    int n=s.length();
    int flag=0;
    if (n==0)return 1;
    else if (dp[s]!=0)
        return dp[s];
    else
    {
        for(int i=1;i<n;i++)
        {
            string subber=s.substr(0,i);
            for(int j=0;j<arr.size();j++)
            {
                if (subber==arr[j] && wordbreak(arr,s.substr(i,n-i)))
                {
                    return dp[s]=1;
                }
            }

        }
        return dp[s]=-1;
    }
}
int main()
{
    vector<string>arr={"i", "like", "sam", "sung", "samsung", "mobile","ice","cream", "icecream", "man", "go", "mango"};
    cout<<wordbreak(arr,"ilikesamsung");
   // cout<<ispar("");
}

