N, M, V = map(int, input().split())
adj = [[] for _ in range(N+1)]  # adj[N] 이런식으로 접근하기 위해 N+1로 정의

for _ in range(M):
    v1, v2 = map(int, input().split())
    adj[v1].append(v2)
    adj[v2].append(v1)

for i in range(len(adj)):
    adj[i] = sorted(adj[i])  # 정점 번호가 작은 것을 먼저 방문해야 하므로 인접리스트 정렬

# DFS
visited = [False] * (N + 1)
path = []  # 방문 순서를 기억하기 위한 리스트

def dfs(node):
    visited[node] = True
    path.append(node)
    
    for next_node in adj[node]:
        if not visited[next_node]:
            dfs(next_node)

dfs(V)
print(*path)


# BFS
from collections import deque

visited = [False] * (N + 1)
path = []

def bfs(node):
    q = deque()
    
    current_node = node
    
    visited[current_node] = True
    q.append(current_node)
    path.append(current_node)
    
    while q:
        current_node = q.popleft()
        
        for next_node in adj[current_node]:
            if not visited[next_node]:
                visited[next_node] = True
                q.append(next_node)
                path.append(next_node)

bfs(V)
print(*path)
