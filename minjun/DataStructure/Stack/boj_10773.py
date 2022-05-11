N = int(input())

stack = []

for _ in range(N):
    key = int(input())
    
    if key == 0:
        stack.pop()
    else:
        stack.append(key)
        
print(sum(stack))