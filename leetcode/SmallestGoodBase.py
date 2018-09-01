
def toInt(numberOfOnes, base):
    return (base**numberOfOnes - 1) // (base - 1)

class Solution:
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        n = int(n)
        res = n - 1
        for i in range(3, 65):
            left, right = 2, n
            while left <= right:
                mid = (left + right) // 2
                val = toInt(i, mid)
                if val == n:
                    res = min(res, mid)
                    break
                elif val < n:
                    left = mid + 1
                else:
                    right = mid - 1
        return str(res)


if __name__ == '__main__':
    sol = Solution()
    print(sol.smallestGoodBase("13"))
    print(sol.smallestGoodBase("4681"))
    print(sol.smallestGoodBase("1000000000000000000"))