class Solution:
    def longestCommonSubstr(self, S1, S2, n, m):
        # code here
        temp=[0]*(m+1)
        dp=[temp]*(n+1)
        dp = [[0 for k in range(m+1)] for l in range(n+1)]
        maxer=0
        for i in range(1,n+1):
            for j in range(1,m+1):
                if S1[i-1]==S2[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                    maxer=max(dp[i][j],maxer)
        
        return maxer
