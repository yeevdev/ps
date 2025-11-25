import heapq

def solution(scoville, K):
    answer = 0
    
    heap = []
    for s in scoville:
        heapq.heappush(heap, s)
    
    while heap[0] < K:
        if len(heap) < 2:
            return -1
        
        top1 = heapq.heappop(heap)
        top2 = heapq.heappop(heap)
        
        new = top1 + (top2 * 2)
        
        heapq.heappush(heap, new)
        answer += 1
    
    return answer