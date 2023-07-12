import time
import queue
import math
import sys
import matplotlib.pyplot as plt
import heapq

sys.setrecursionlimit(1000000) # this line is for fixing the recursion limit

class Median_Finder:
    
    def init(self):
        #initialize data structure
        self.max_heap = []
        self.min_heap = []
        

    def add_Number(self, num):
        #type num: int, rtype: void
        if not self.max_heap and not self.min_heap:
            heapq.heappush(self.min_heap, num)
            return 
        if not self.max_heap:
            if num > self.min_heap[0]:
                heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
                heapq.heappush(self.min_heap, num)
            else:
                heapq.heappush(self.max_heap, -num)
            return
        
        if len(self.max_heap) == len(self.min_heap):
            if num < -self.max_heap[0]:
                heapq.heappush(self.max_heap, -num)
            else:
                heapq.heappush(self.min_heap, num)
        elif len(self.max_heap) > len(self.min_heap):
            if num < -self.max_heap[0]:
                heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
                heapq.heappush(self.max_heap, -num)
            else:
                heapq.heappush(self.min_heap, num)
        else:
            if num > self.min_heap[0]:
                heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
                heapq.heappush(self.min_heap, num)
            else:
                heapq.heappush(self.max_heap, -num)
        

    def find_Median(self):
        #rtype: float
        if len(self.max_heap) == len(self.min_heap):
            return ( -self.max_heap[0]) 
        elif len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]
        else:
            return self.min_heap[0] 


def main():
            
    s = Median_Finder()
    # s.add_Number(1)
    # s.add_Number(2)
    # s.add_Number(3)
    # s.add_Number(4)
    # s.add_Number(5)
    n , k = [int (x) for x in input().split()]
    A = [int (x) for x in input().split()]
    for i in range (n):
        s.add_Number(A[i])

    for i in range(k):
        key = int(input())
        s.add_Number(key)
        print(s.find_Median())
    #print(s.find_Median())



if __name__ == '__main__':
    start = round(time.time() * 1000)
    main()
    finish = round(time.time() * 1000)
    print(finish - start)
    