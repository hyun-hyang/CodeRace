import sys
from collections import deque

cnt = 0

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

visited = [False] * (n+1)
graph = [[] for _ in range(n+1)]

# 그래프 만들기
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)
    
for i in range(n):
    graph[i].sort()
    
# dfs로 풀기
def dfs(start):
    global cnt
    visited[start] = True
    # print(start, end = ' ')
    for i in graph[start]:
        if not visited[i]:
            dfs(i)
            visited[i] = True
            cnt+=1

# bfs로 풀기
def bfs(start):
    global cnt
    visited[start] = True
    q = deque([start])
    while q:
        now = q.popleft()
        #print(now, end= ' ')
        for i in graph[now]:
            if not visited[i]:
                q.append(i)
                visited[i] = True
    
    

dfs(1)
print(cnt)
            

    