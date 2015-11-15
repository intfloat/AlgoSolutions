class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        cand, cnt = 0, 0
        for number in num:
            if cnt == 0:
                cand, cnt = number, 1
            elif number == cand:
                cnt += 1
            else:
                cnt -= 1
        return cand
