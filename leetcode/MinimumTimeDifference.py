def parse(t):
    hour, minute = map(int, t.split(':'))
    return hour * 60 + minute

class Solution:
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        points = [parse(t) for t in timePoints]
        points = sorted(points)
        min_diff = 24 * 60
        for i in range(1, len(points)):
            min_diff = min(min_diff, points[i] - points[i - 1])
        min_diff = min(min_diff, points[0] + 24 * 60 - points[-1])
        return min_diff

solution = Solution()
print(solution.findMinDifference(["23:59","00:00"]))