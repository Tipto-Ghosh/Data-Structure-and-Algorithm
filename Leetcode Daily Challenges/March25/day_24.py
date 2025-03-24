from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        # Sorted meetings based on starting value in ascending order
        # Take the first value and check do we have any free day before start meetings
        # Initialize the start and end of a meeting
        # Now go to every meeting from 1 to n-1 and check
        # If they overlap then no free day just update meeting time
        # If they dont overlap then their is free time take the time and update meeting time
        
        # Sorting meeting based on starting time
        meetings = sorted(meetings , key = lambda x : x[0])
        start1 , end1 = meetings[0]
        count_free_days = start1 - 1 # Count free days before starting meetings
        n = len(meetings)
        
        for i in range(1 , n):
            start2 , end2 = meetings[i]
            
            # If they don't overlap then take the free days
            if not (start2 <= end1):
                count_free_days += (abs(start2 - end1) - 1)
            
            # Otherwise always update the meeting time
            start1 = min(start1 , start2)
            end1 = max(end1 , end2)
        
        # If we have any day left over
        count_free_days += (days - end1)
        
        return count_free_days
        
        
sol = Solution()

print(sol.countDays(10 , [[5,7],[1,3],[9,10]]))
print(sol.countDays(5 , [[2,4],[1,3]]))
print(sol.countDays(6 , [[1,6]]))
                 