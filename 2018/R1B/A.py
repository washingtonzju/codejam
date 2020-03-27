from heapq import heappop, heappush
import math

def create_table(N):
    nei = [0] * (N + N)
    current = N + N
    for i in range(N+N-1, -1, -1):
        rd = math.floor(i*100.0/N + 0.5)
        if rd > (i*100.0/N):
            current = i
        nei[i] = current
    return nei

def run(N, L, votes, nei):
    if 100 % N == 0:
        return 100
    
    budget = N
    for val in votes:
        budget -= val
    
    for i in range(budget):
        votes.append(0)
    
    sz = len(votes)
    hp = []
    for i in range(sz):
        val = votes[i]
        heappush(hp, ((nei[val] - val), i))
    
    v = [False] * sz
    while budget > 0 and len(hp) > 0:
        cost, idx = heappop(hp)
        if cost > budget:
            break
        budget -= cost
        votes[idx] += cost
        v[idx] = True

    if budget > 0:
        idx = 0
        while idx < sz and v[idx]:
            idx += 1
        if idx < sz:
            votes[idx] += budget
        else:
            votes[0] += budget
    
    ans = 0
    for val in votes:
        ans += math.floor(val * 100.0 / N + 0.5)
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
        nei = create_table(N)
        # print(N, L)
        # print(nei)
        ans = run(N, L, votes, nei)
        print("Case #{}: {}".format(i+1, ans))
