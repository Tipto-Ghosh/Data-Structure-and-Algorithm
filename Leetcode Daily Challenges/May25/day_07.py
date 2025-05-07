class State:
    def __init__(self, x, y, dis):
        self.x = x
        self.y = y
        self.dis = dis

    def __lt__(self, other):
        return self.dis < other.dis


class Solution:
    def minTimeToReach(self, moveTime):
        n = len(moveTime)
        m = len(moveTime[0])
        inf = float("inf")
        d = [[inf] * m for _ in range(n)]
        v = [[0] * m for _ in range(n)]

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        d[0][0] = 0
        q = []
        heapq.heappush(q, State(0, 0, 0))

        while q:
            s = heapq.heappop(q)
            if v[s.x][s.y]:
                continue
            v[s.x][s.y] = 1
            for dx, dy in dirs:
                nx, ny = s.x + dx, s.y + dy
                if not (0 <= nx < n and 0 <= ny < m):
                    continue
                dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1
                if d[nx][ny] > dist:
                    d[nx][ny] = dist
                    heapq.heappush(q, State(nx, ny, dist))

        return d[n - 1][m - 1]