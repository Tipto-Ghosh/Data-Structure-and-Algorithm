from typing import List
from collections import deque
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        n = len(status)  # Total number of boxes

        # can_open[i] is True if we can open box i (either it's already open or we get a key)
        can_open = [status[i] == 1 for i in range(n)]

        # has_box[i] is True if we possess box i
        has_box = [False] * n

        # used[i] is True if we have already opened and processed box i
        used = [False] * n

        q = deque()  # Queue for BFS
        ans = 0  # Total number of candies collected

        # Initialize with initial boxes
        for box in initialBoxes:
            has_box[box] = True  # Mark that we have this box

            # If the box is open, we can process it immediately
            if can_open[box]:
                q.append(box)
                used[box] = True
                ans += candies[box]  # Collect candies

        # BFS to open more boxes using keys and find more boxes inside
        while len(q) > 0:
            big_box = q.popleft()  # Take out a box to process

            # Process all keys found in this box
            for key in keys[big_box]:
                can_open[key] = True  # Now we can open the box 'key'

                # If we already have that box and haven't used it yet
                if not used[key] and has_box[key]:
                    q.append(key)
                    used[key] = True
                    ans += candies[key]  # Collect candies from that box

            # Process all boxes contained in this box
            for box in containedBoxes[big_box]:
                has_box[box] = True  # We now have this new box

                # If it’s open and not used yet, we can use it now
                if not used[box] and can_open[box]:
                    q.append(box)
                    used[box] = True
                    ans += candies[box]  # Collect candies

        return ans  # Total candies collected from all accessible boxes