dp=[[0 for x in range(600 + 1)] for x in range(600*10+1)]
dp[0][0]=1
for i in range(1,501):
  for j in range(0,7):
    for k in range(0,10):
      if(k!=7):
        dp[i][(k+10*j)%7]+=dp[i-1][j]
t = int(input())
for i in range(0, t):
    n = int(input())
    cnt=0
    for i in range(1,7):
      cnt+=dp[n][i]
    print (10**n - 1 - cnt)