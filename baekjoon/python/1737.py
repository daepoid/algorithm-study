import math

MOD = 1000000000000000000

N = int(input())

dp = [[-1 for i in range(N + 1)] for j in range(N + 1)]


def pib(a, b):
    if dp[a][b] != -1:
        return dp[a][b]

    if a - b * math.pi <= math.pi:
        dp[a][b] = 1
        return dp[a][b]

    dp[a][b] = (pib(a - 1, b) + pib(a, b + 1)) % MOD
    return dp[a][b]


pib(N, 0)
print(dp[N][0])
