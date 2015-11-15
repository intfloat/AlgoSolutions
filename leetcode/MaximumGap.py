class Solution:
    # @param num, a list of integer
    # @return an integer
    def maximumGap(self, num):
        if not num or len(num) < 2:
            return 0
        if len(num) == 2:
            return abs(num[0] - num[1])
        mn, mx = min(num), max(num)
        gap = 1.0 * (mx - mn) / (len(num) - 1)
        bucket = []
        for _ in xrange(len(num) - 1):
            # [maxVal, minVal]
            bucket.append([-1e12, 1e12])
        bucket[0] = [mn, mn]
        bucket[-1] = [mx, mx]
        for number in num:
            if number == mn or number == mx:
                continue
            pos = int((number - mn) / gap)
            bucket[pos][0] = max(bucket[pos][0], number)
            bucket[pos][1] = min(bucket[pos][1], number)
        res, prev = 0, bucket[0][0]
        # print 'debug:', bucket
        for i in xrange(1, len(bucket)):
            if bucket[i][0] == -1e12:
                continue
            res = max(res, bucket[i][1] - prev)
            prev = bucket[i][0]
        # assert(res > 0)
        return res

if __name__ == '__main__':
    s = Solution()
    print s.maximumGap([2, 5, 1, 6])
    print s.maximumGap([100, 1, 3, 2])
    print s.maximumGap([1, 1000000])