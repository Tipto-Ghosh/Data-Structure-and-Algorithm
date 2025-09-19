from typing import List 
import heapq

class TaskManager:
    def __init__(self, tasks: List[List[int]]):
        self.task_map = {} # taskId -> (userId , priority)
        self.task_heap = [] # (- priority , - taskId , userId)
        
        for userId , taskId , priority in tasks:
            self.task_map[taskId] = (userId , priority)
            heapq.heappush(self.task_heap , (-1 * priority , -1 * taskId , userId))
        
    def add(self, userId: int, taskId: int, priority: int) -> None:
        heapq.heappush(self.task_heap , (-1 * priority , -1 * taskId , userId))
        self.task_map[taskId] = (userId , priority)

    def edit(self, taskId: int, newPriority: int) -> None:
        userId , _ = self.task_map[taskId]
        self.task_map[taskId] = (userId , newPriority)
        heapq.heappush(self.task_heap , (-1 * newPriority , -1 * taskId , userId))
        
    def rmv(self, taskId: int) -> None:
        if taskId in self.task_map:
            del self.task_map[taskId]

    def execTop(self) -> int:
        while self.task_heap:
            priority , taskId , userId = heapq.heappop(self.task_heap)
            
            priority *= -1
            taskId *= -1
            
            if taskId in self.task_map:
                user , p = self.task_map[taskId]
                
                if priority == p:
                   del self.task_map[taskId]
                   return user
        return -1 

