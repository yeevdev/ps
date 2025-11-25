N, M = map(int, input().split())
r, c, d = map(int, input().split())
room = []
for _ in range(N):
    room.append(list(map(int, input().split())))

# 0:북 1:동 2:남 3:서
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

count = 0

while True:
    # 1. 현재 칸 청소
    if room[r][c] == 0:
        room[r][c] = 2
        count += 1
    
    # 2. 주편 4칸에 청소할 칸 있는지 확인
    should_clean = False
    for _ in range(4):
        d = (d + 3) % 4
        new_r = r + dr[d]
        new_c = c + dc[d]
        
        if 0 <= new_r < N and 0 <= new_c < M and room[new_r][new_c] == 0:
            r, c = new_r, new_c
            should_clean = True
            break
    if not should_clean:
        back_r, back_c = r - dr[d], c - dc[d]
        
        if not (0 <= back_r < N and 0 <= back_c < M) or room[back_r][back_c] == 1:
            break
            
        r, c = back_r, back_c
print(count)
