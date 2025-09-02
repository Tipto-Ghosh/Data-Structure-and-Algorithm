from typing import List
import heapq

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        """ 
        I have assign the extra students where by adding a new student pass ratio will increase max.
        Always need to get the highest ratio changing class(Need a max-heap)
        """
        
        def gain(pass_students , total_students):
            curr_pass_ratio = pass_students / total_students
            # find the pass ratio after adding a new student
            next_pass_ratio = (pass_students + 1) / (total_students + 1)
            return next_pass_ratio - curr_pass_ratio # increase/gain
        
        
        max_heap = []
        # for each class find the gain
        for p , t in classes:
            g = gain(p , t)
            # we need max gain so maxHeap
            heapq.heappush(max_heap , (-g , p , t))
        
        # now add students 1 by 1 while we have extra students
        while extraStudents > 0:
            # find in which class adding a new student will give the max gain
            g , p , t = heapq.heappop(max_heap)
            # invert the -ve of gain
            g *= -1
            # add the new student
            p += 1
            t += 1
            # now find the new gain
            new_gain = gain(p , t)
            heapq.heappush(max_heap , (-new_gain , p , t))
            extraStudents -= 1
        
        # now find the total ratio
        total_ratio = 0
        while max_heap:
            g , p , t = heapq.heappop(max_heap)
            # find the ratio
            total_ratio += (p / t) 
        
        # return the avg ratio
        return total_ratio / len(classes)


sol = Solution()

print(sol.maxAverageRatio(classes = [[1,2],[3,5],[2,2]], extraStudents = 2))
print(sol.maxAverageRatio(classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4))