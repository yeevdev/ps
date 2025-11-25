def solution(n, lost, reserve):
    s_lost = set(lost)
    s_reserve = set(reserve)
    
    # reserve에서 도난당한 사람 삭제
    intersect = s_lost & s_reserve
    s_reserve -= intersect
    s_lost -= intersect
    
    answer = n - len(s_lost)
    
    for x in sorted(s_lost):
        if x-1 in s_reserve:
            s_reserve.remove(x-1)
            answer += 1
        elif x+1 in s_reserve:
            s_reserve.remove(x+1)
            answer += 1
    
    return answer