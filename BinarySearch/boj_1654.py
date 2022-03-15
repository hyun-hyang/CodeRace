import sys

def solution():
    K, N = map(int, input().split())
    lan = [int(sys.stdin.readline()) for _ in range(K)] 
    
    min_value = 1 
    max_value = max(lan) 

    while min_value <= max_value: 
        mid = (min_value + max_value) // 2 
        cnt = 0 
        for i in lan:
            cnt += i // mid 

        if cnt >= N:  
            min_value = mid + 1
        else:  
            max_value = mid - 1 

    return max_value 

print(solution())