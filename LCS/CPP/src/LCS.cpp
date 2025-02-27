#include "../include/LCS.hpp"
#include <algorithm> 
#include <string> 

int LCS::lcs(std::string s1, std::string s2) {
    int x = s1.length();
    int y = s2.length();
    int dp[x+1][y+1];
        
    for(int i =0; i<=x;i++)
    dp[i][0] =0;
    
    for(int i =0; i<=y;i++)
    dp[0][i] =0;
    
    for(int i =1;i<=x;i++){
        for(int j =1; j<=y;j++){
            dp[i][j] = 0;
            if(s1[i-1]==s2[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
            
            else
            dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]); // Use std::max
        }
    }
    return dp[x][y];
}
