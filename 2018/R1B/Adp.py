import math

def bottom_up(N, sz, budget, dp, votes, cache):

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
    return dp[sz][N]

def top_down(N, sz, budget, dp, votes, cache):
    if dp[sz][N] >= 0:
        return dp[sz][N]
    mx = 0
    tmp = 0
    for i in range(votes[sz-1], votes[sz-1] + budget + 1):
        if N >= i and sz >= 1:
            tmp = top_down(N - i, sz - 1, budget - (i - votes[sz-1]), dp, votes, cache) + cache[i]
            if tmp > mx:
                mx = tmp
    dp[sz][N] = mx
    # print(sz, N, dp[sz][N])
    return dp[sz][N]
    
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

    # ans = bottom_up(N, sz, budget, dp, votes, cache)
    dp[1][votes[0]] = cache[votes[0]]
    ans = top_down(N, sz, budget, dp, votes, cache)
    '''
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
            
    for i in range(0, sz + 1):
        for j in range(0, N + 1):
            print(dp[i][j], '', end='')
        print()
    
    print(dp[sz][N])
    '''
    return ans

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
