from collections import deque

def solution(n, edge):
    adj = [[] for _ in range(n+1)]  # adj_list[n][n] 까지 할당가능
    
    for e in edge:
        adj[e[0]].append(e[1])
        adj[e[1]].append(e[0])  # 양방향 연결..
    
    visited = [False] * (n+1)
    def bfs(start):
        distance = [0] * (n+1)
        current_time = 0
        
        q = deque()
        
        visited[start] = True
        q.append(start)
        
        while q:
            current_node = q.popleft()
            current_time += 1
            
            for next in adj[current_node]:
                if not visited[next]:
                    visited[next] = True
                    distance[next] = distance[current_node] + 1
                    q.append(next)
        return distance
    ans_arr = bfs(1)
    answer = ans_arr.count(max(ans_arr))
    
    
    return answer
