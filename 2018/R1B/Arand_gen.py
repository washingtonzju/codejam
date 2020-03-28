import random

if __name__ == "__main__":
    T =  20
    print(T)
    for t in range(T):
        N = random.randrange(1, 250)
        L = random.randrange(1, N)
        buffer = random.randrange(0, N - L + 1)
        
        sum = N - buffer
        
        line = ''
        cnt = 0
        for i in range(L):
            val = random.randrange(0, sum+1)
            line += (str(val) + ' ')
            sum -= val
            cnt += 1
            if sum < 1:
                break
        print(N, cnt)
        print(line[:-1])
