N, M = map(int, input().split())

dp = [[0 for j in range(M + 1)] for i in range(N + 1)]
arr = [0 for i in range(N + 1)]

for i in range(1, N + 1):
    arr[i] = int(input())

for i in range(1, N + 1):
    for j in range(0, M + 1):
        if j == 0:
            dp[j][i] = max(dp[j][i], max(dp[j][i - 1], dp[j + 1][i - 1]))
        elif 1 <= j < M:
            dp[j][i] = max(dp[j][i], dp[j - 1][i - 1] + arr[i])
            if i + j <= N:
                dp[0][i + j] = max(dp[0][i + j], dp[j][i])
        elif j == M:
            if j <= i <= N:
                dp[0][i + j] = max(dp[0][i + j], dp[j][i])

print(dp[0][N])
