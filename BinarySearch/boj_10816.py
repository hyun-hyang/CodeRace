import sys

n = int(sys.stdin.readline())
n_list = list(map(int, sys.stdin.readline().split(' ')))
n_list.sort()

m = int(sys.stdin.readline())
targets = list(map(int, sys.stdin.readline().split(' ')))

# def binary(target):
#     left = 0
#     right = n - 1
    
#     while left <= right:
#         mid = (left + right) // 2
#         if n_list[mid] == target:
#             return True
        
#         if target < n_list[mid]:
#             right = mid-1
#         elif target > n_list[mid]:
#             left = mid + 1
            
# for i in range(m):
#     if binary(targets[i]):
#         print(n_list.count(targets[i]), end='')
#     else:
#         print(0)
        
cnt = {}
for n in n_list:
    if n in cnt:
        cnt[n]+=1
    else:
        cnt[n]=1

for target in targets:
    result = cnt.get(target)
    if result == None:
        print(0, end=' ')
    else:
        print(result, end=' ')
