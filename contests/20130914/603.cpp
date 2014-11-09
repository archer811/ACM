#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
 #include <math.h>
 #include <stdlib.h>
 #include <time.h>
 using namespace std;

const int MAXN = 100010;
 const int MOD = 1e9+7;
 char str1[MAXN], str2[MAXN];
 int dp[MAXN][2];
 int flag[MAXN][2];

 char sss1[MAXN],sss2[MAXN];

 int main()
 {

     int T;
      int iCase = 0;
      scanf("%d",&T);
      while(T--)
    {
          iCase++;

          scanf("%s%s",str1,str2);
          printf("Case #%d:\n",iCase);
          int n = strlen(str1);
          dp[0][0] = 1;
          dp[0][1] = 0;
          flag[0][0] = 1;
          flag[0][1] = 0;
          for(int i = 1;i <= n;i++)
          {
              if(str1[i-1] == '?' && str2[i-1] == '?')
              {
                  dp[i][1] = dp[i-1][0] + dp[i-1][1];
                  dp[i][0] = dp[i-1][0] + dp[i-1][1];
                  int tmp = flag[i-1][0] + flag[i-1][1];
                  if(tmp == 0)
                      flag[i][0] = flag[i][1] = 0;
                  else if(tmp == 1)
                      flag[i][0] = flag[i][1] = 1;
                  else flag[i][0] = flag[i][1] = 2;
              }
              else if(str1[i-1] == '?' || str2[i-1] == '?')
              {
                  if(str1[i-1] == '0' || str2[i-1] =='0')
                  {
                      dp[i][1] = dp[i-1][1];
                      dp[i][0] = dp[i-1][0];
                      flag[i][0] = flag[i-1][0];
                      flag[i][1] = flag[i-1][1];
                  }
                  else if(str1[i-1] == '1' || str2[i-1] =='1')
                  {
                      dp[i][1] = dp[i-1][0];
                      dp[i][0] = dp[i-1][1];
                    flag[i][1] = flag[i-1][0];
                      flag[i][0] = flag[i-1][1];
                  }
              }
              else if(str1[i-1] != str2[i-1])
              {
                  dp[i][0] = dp[i][1] = 0;
                  flag[i][0] = flag[i][1] = 0;
              }
              else
              {
                  if(str1[i-1] =='0')
                  {
                      dp[i][0] = dp[i-1][0];
                      dp[i][1] = dp[i-1][1];
                      flag[i][0] = flag[i-1][0];
                      flag[i][1] = flag[i-1][1];

                  }
                  else
                  {
                      dp[i][0] = dp[i-1][1];
                      dp[i][1] = dp[i-1][0];
                      flag[i][1] = flag[i-1][0];
                      flag[i][0] = flag[i-1][1];
                  }
              }
             if(dp[i][0] >= MOD)dp[i][0] -= MOD;
             if(dp[i][1] >= MOD)dp[i][1] -= MOD;
         }
         int ans = 0;
         int flag_num  = 0;
         int ss_id = -1;
         for(int i = n;i > 0;i--)
         {
             if(i+2 <= n)
             {
                if(str1[i+1] == '1' || str2[i+1] == '1')
                     break;
             }
             if(i+1 <= n)
             {
                 if(str1[i] == '0' || str2[i] == '0')
                     continue;
             }
             if(i-1 >= 0)
             {
                 if(str1[i-1] == str2[i-1] && str1[i-1] != '?')
                     continue;
             }
             char ch;
             if(str1[i-1] == str2[i-1] && str1[i-1] == '?')
             {
                 ans += dp[i-1][0];
                 ans %= MOD;
                 ans += dp[i-1][1];
                 ans %= MOD;
                 flag_num += flag[i-1][0] + flag[i-1][1];
                 if(flag_num > 2)flag_num = 2;
             }
             else
             {
             if(str1[i-1] != '?')ch = str1[i-1];
             else
             {
                 if(str2[i-1] == '0')ch = '1';
                 else ch = '0';
             }
             if(ch == '0')
             {
                 ans += dp[i-1][0];
                 ans %= MOD;
                 flag_num += flag[i-1][0];
                 if(flag_num > 2)flag_num = 2;
             }
             else
             {
                 ans += dp[i-1][1];
                 ans %= MOD;
                 flag_num += flag[i-1][1];
                 if(flag_num > 2)flag_num = 2;
             }
             }
             if(flag_num == 1 && ss_id == -1)ss_id = i;
         }
         if(flag_num == 0)
         {
             printf("Impossible\n");
             continue;
         }
         if(flag_num > 1)
         {
             printf("Ambiguous %d\n",ans);
             continue;
         }
         if(flag_num == 1)
         {
             sss1[n] = sss2[n] = 0;
             sss1[ss_id-1] = '0';
             sss2[ss_id-1] = '1';
             for(int i = ss_id;i < n;i++)
               sss1[i] = '1', sss2[i] = '0';
             int last = 0;
            for(int i = ss_id-2;i >= 0;i--)
             {
                 int now;
                 if(flag[i+1][0] > 0)now = 0;
                 else now = 1;
                 sss1[i] = sss2[i] = '0' + now;

             }
             for(int i = n-1; i > 0;i--)
             {
                 if(sss1[i-1] ==sss1[i])sss1[i] = '0';
                 else sss1[i] = '1';
                 if(sss2[i-1] == sss2[i])sss2[i] = '0';
                 else sss2[i] = '1';
             }

             printf("%s\n%s\n",sss1,sss2);
             continue;
         }
         cout<<ans<<endl;


     }
     return 0;
 }
