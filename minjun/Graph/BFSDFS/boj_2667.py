# https://hei-jayden.tistory.com/99?category=528821

# n의 개수, graph, visited 정의
n = int(input())
graph = [[0]*n for _ in range(n)]
visited = [[False]*n for _ in range(n)]


# 입력값을 graph에 기입
for i in range(n):
    line = input()
    for j, b in enumerate(line):
        graph[i][j] = int(b)


# 상하좌우 이동 설정
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]


# dfs로 탐색
cnt = 0

def dfs(x,y):
    global cnt
    visited[x][y]=True
    if graph[x][y] == 1:
        cnt += 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n:
            if visited[nx][ny] == False and graph[nx][ny] == 1:
                dfs(nx, ny)

# 정의된 dfs로 graph탐색
housing = []

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1 and visited[i][j] == False: 
            dfs(i, j)
            housing.append(cnt)
            cnt = 0


# 답 출력
housing.sort()  
print(len(housing))
for i in housing:
    print(i)
        
