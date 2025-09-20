from typing import List
from collections import deque , defaultdict
import bisect

class Router:

    def __init__(self, memoryLimit: int):
        self.memoryLimit = memoryLimit # max memory limit 
        self.queue = deque() # store the data's
        self.allDataPacks = set() # to track data packets
        # destination -> sorted list of timestamps
        self.dest_map = defaultdict(list) # key is destination and value will be all the pack's time that has time destination 
         
    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        if (source , destination , timestamp) in self.allDataPacks:
            return False # duplicate's 
        
        # if maxMemory exceed, remove oldest pack
        if len(self.queue) == self.memoryLimit:
           src , dest , time = self.queue.popleft()
           self.allDataPacks.remove((src , dest , time))
           
           index = bisect.bisect_left(self.dest_map[dest] , time)
           if index < len(self.dest_map[dest]) and self.dest_map[dest][index] == time:
               self.dest_map[dest].pop(index)
                
        # no dublicate, so add it
        self.allDataPacks.add((source , destination , timestamp))
        self.queue.append([source , destination , timestamp])
        self.dest_map[destination].append(timestamp)
        
        return True

    def forwardPacket(self) -> List[int]:
        if len(self.queue) == 0:
            return []
        
        src , dest , time = self.queue.popleft()
        self.allDataPacks.remove((src , dest , time))
        # remove from destination map
        idx = bisect.bisect_left(self.dest_map[dest], time)
        if idx < len(self.dest_map[dest]) and self.dest_map[dest][idx] == time:
            self.dest_map[dest].pop(idx)
            
        return [src, dest, time]
    
    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        # get all the times for this destination
        times = self.dest_map[destination]
        
        # binary search for range
        left = bisect.bisect_left(times, startTime)
        right = bisect.bisect_right(times, endTime)
        return right - left


router = Router(3)

print(router.addPacket(1, 4, 90) )
print(router.addPacket(2, 5, 90))
print(router.addPacket(1, 4, 90))
print(router.addPacket(3, 5, 95))
print(router.addPacket(4, 5, 105))

print(router.forwardPacket())

print(router.addPacket(5, 2, 110))
print(router.getCount(5, 100, 110))