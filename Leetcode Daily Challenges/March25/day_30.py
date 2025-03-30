from typing import List

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # Find all the letter's start to end interval
        # Sort based on starting position
        # Merge all the overlapping intervals
        n = len(s)
        letters_track = {}
        
        for i in range(n):
            curr_letter = s[i] 
            
            # If we never seen this letter before
            if curr_letter not in letters_track:
                # assume letter start and end here
                letters_track[curr_letter] = [i , i]
            else: # If we see this letter before
                # Update the ending position
                letters_track[curr_letter][1] = i 
        
        # Now make the list of intervals
        intervals = []
        for interval in letters_track.values():
            intervals.append(interval)
        # Now we have all the intervals
        # Sort all the intervals based on start index in ascending
        intervals.sort(key = lambda x: x[0])
        
        prev_start , prev_end = intervals[0][0] , intervals[0][1]
        ans = []
        
        for i in range(1 , len(intervals)):
            curr_start , curr_end = intervals[i][0] , intervals[i][1]
            
            # If overlap or touch then just merge two
            if  prev_end >= curr_start: # No change that prev_end and curr_start are equal
                # Means overlap so merge
                prev_start = min(prev_start , curr_start)
                prev_end = max(prev_end , curr_end)
            else: # if do not overlap
                # we got a valid a partion
                partion_length = prev_end - prev_start + 1
                ans.append(partion_length)
                # Update the previous interval
                prev_start = curr_start
                prev_end = curr_end
        
        # We have the last partion in our hand
        last_partition_length = prev_end - prev_start + 1
        ans.append(last_partition_length)
        return ans            
        
        
sol = Solution()

print(sol.partitionLabels('ababcc'))        
print(sol.partitionLabels("ababcbacadefegdehijhklij"))
print(sol.partitionLabels("eccbbbbdec"))