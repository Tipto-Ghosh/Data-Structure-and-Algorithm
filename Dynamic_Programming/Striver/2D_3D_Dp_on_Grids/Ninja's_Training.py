from typing import List
def ninjaTraining(n: int, points: List[List[int]]) -> int:
    # I have 3 choice: Run , Fight , Learn
    # Each day I have 2 option [can't do same task consicuitive day]
    # changing paramenter: each day there can be 3 task's
    def solve(day: int , prev_task: int) -> int:
        if day < 0:
            return 0
        if dp[day][prev_task] != -1:
            return dp[day][prev_task]
        curr_max_points = 0
        for today_task in range(3): # 0 , 1 , 2
            if today_task == prev_task:
                continue
            else:
                today_point = points[day][today_task] + solve(day - 1 , today_task)
                curr_max_points = max(curr_max_points , today_point)
        dp[day][prev_task] = curr_max_points
        return curr_max_points
    
    dp = [[-1] * 3 for _ in range(n)]
    # today we have 3 task to start with
    run = solve(n-1 , 0)
    fight = solve(n - 1 , 1)
    learn = solve(n - 1 , 2)
    print(dp)
    return max(run , fight , learn)

n = 3
points = [[1,2,5] , [3,1,1] , [3,3,3]]


n2 = 3
points2 = [[10,40,70] , [20,50,80] , [30,60,90]]

ans = ninjaTraining(n , points2)
print(ans)