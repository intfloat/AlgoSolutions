class Solution:

    def gcd(self, n1, n2):
        if n2 == 0:
            return n1
        return self.gcd(n2, n1 % n2)

    # @return a string
    def fractionToDecimal(self, numerator, denominator):
        if numerator == 0:
            return '0'
        res = ''
        if numerator * denominator < 0:
            res = '-'
        numerator, denominator = abs(numerator), abs(denominator)
        g = self.gcd(numerator, denominator)
        numerator /= g
        denominator /= g
        res += str(numerator / denominator)
        rem = numerator % denominator
        if rem == 0:
            return res
        res += '.'
        h = {}

        while True:
            if h.has_key(rem):
                return res[:h[rem]] + '(' + res[h[rem]:] + ')'
            else:
                h[rem] = len(res)
                rem *= 10
                if rem % denominator == 0:
                    res += str(rem / denominator)
                    return res
                else:
                    res += str(rem / denominator)
                    rem = rem % denominator

if __name__ == '__main__':
    s = Solution()
    print s.fractionToDecimal(1, 2)
    print s.fractionToDecimal(2, 1)
    print s.fractionToDecimal(2, 3)
