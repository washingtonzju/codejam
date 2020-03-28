import math

def run(N, L, votes):
    '''
    Bottom up DP solution
    '''
    budget = N
    for vote in votes:
        budget -= vote
        
    for i in range(budget):
        votes.append(0)
    
    sz = len(votes)
    dp = [None] * (sz + 1)

    for i in range(0, sz+1):
        dp[i] = [-1000000000] * (N + 1)
    
    dp[0][0] = 0
    cache = [0] * (N + 1)
    for i in range(1, N+1):
        cache[i] = math.floor(i*100.0/N + 0.5)
    # print(cache)
    sum = 0
    for i in range(1, sz+1):
        sum += votes[i-1]
        for j in range(sum, sum+ budget + 1):
            mx = 0
            for k in range(votes[i-1], votes[i-1] + budget + 1):
                val = cache[k]
                if j>=k and val + dp[i-1][j-k] > mx:
                    mx = val + dp[i-1][j-k]
            # print(i, j, mx, sz)
            dp[i][j] = mx
            
    '''
    for i in range(0, sz + 1):
        for j in range(0, N + 1):
            print(dp[i][j], '', end='')
        print()
    
    print(dp[sz][N])
    '''
    return dp[sz][N]

if __name__ == "__main__":

    T = int(input())
    
    for i in range(T):
        N, L = input().split(' ')
        N = int(N)
        L = int(L)

        votes = []
        raws = input().split(' ')
        for raw in raws:
            votes.append(int(raw))
        
        ans = run(N, L, votes)
        print("Case #{}: {}".format(i+1, ans))
