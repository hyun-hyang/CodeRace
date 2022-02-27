# 기본 중에서 기본 중인 문제.
# 이해는 완료
# 구조 및 코드 외우기

import sys
from collections import deque

n,m,start=map(int,sys.stdin.readline().split())
visited=[False]*(n+1)

# 그래프 만들기
graph=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

# 그래프 정렬
for i in range(len(graph)):
    graph[i].sort()

# dfs: 재귀를 통해 구현
def dfs(start):
    print(start, end=' ')
    visited[start] = True
    for i in graph[start]:
        if not visited[i]:
            dfs(i)
            visited[i] = True

# bfs: queue를 통해 구현
def bfs(start):
    q = deque([start])
    visited[start] = True
    while q:
        now = q.popleft()
        print(now, end=' ')
        for i in graph[now]:
            if not visited[i]:
                q.append(i)
                visited[i] = True


dfs(start)
visited = [False] * (n+1)
print()
bfs(start)
        
