N = int(input())
confs = []
for _ in range(N):
    start, end = map(int, input().split())
    confs.append([end, start])

confs = sorted(confs)

ans = []
for i in range(len(confs)):
    if i == 0:
        ans.append(confs[i])
        continue
    else:
        if confs[i][1] >= ans[-1][0]:
            ans.append(confs[i])

print(len(ans))

