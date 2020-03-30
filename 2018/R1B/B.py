def binsearch(val, arr, sz):
    s = 0
    e = sz-1
    m = 0
    while s <= e:
        m = (s + e) // 2
        if arr[m][-1][0] > val:
            e = m - 1
        elif arr[m][-1][0] < val:
            s = m + 1
        else:
            break
    return m

def generic_validate(st, ed, sq, id1, id2):
    M = sq[st][id1]
    N = None
    md = 0
    i = st + 1
    while i <= ed:
        if md % 2 == 0:
            if sq[i][id1] != M:
                md += 1
                N = sq[i][id2]
        else:
            if sq[i][id2] != N and sq[i][id1] != M:
                md += 1
        if md > 1:
            break
        i+=1
    # print("i={},ed={}".format(i, ed))
    if i > ed:
        return True
    else:
        return False

def validate(st, ed, sq):
    # Test with M first
    m_try = generic_validate(st, ed, sq, 2, 3)
    if m_try:
        return True
    # Test with N first
    n_try = generic_validate(st, ed, sq, 3, 2)
    return n_try

def brute_force(S, sq):
    # Brute force solution
    ans = {
        1: S,
    }
    for j in range(S):
        for k in range(j+1, S):
            res = validate(j, k, sq)
            l = k - j + 1
            if res == True:
                if l not in ans:
                    ans[l] = 0
                ans[l] += 1
    final_ans = 0
    final_cnt = 0
    for k, v in ans.items():
        if k > final_ans:
            final_ans = k
            final_cnt = v
    return final_ans, final_cnt

if __name__ == "__main__":
    T = int(input())
    for i in range(1, T+1):
        S = int(input())
        sq = []
        for j in range(S):
            D, A, B = input().split(' ')
            D = int(D)
            A = int(A)
            B = int(B)
            M = D + A
            N = D - B
            sq.append((A, B, M, N))

        ans, cnt = brute_force(S, sq)
        print("Case #{}: {} {}".format(i, ans, cnt))
    
