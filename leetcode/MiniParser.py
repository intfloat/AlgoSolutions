# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution(object):
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        if s == '[]':
            return NestedInteger()
        elif not s[0] == '[':
            return NestedInteger(value = int(s))
        else:
            ret = NestedInteger()
            lparen, last = 0, 0
            for i in range(1, len(s) - 1):
                if s[i] == ',' and lparen == 0:
                    ret.add(self.deserialize(s[(last + 1):i]))
                    last = i
                elif s[i] == '[':
                    lparen += 1
                elif s[i] == ']':
                    lparen -= 1
            if last != len(s) - 2:
                ret.add(self.deserialize(s[(last + 1):(len(s) - 1)]))
            return ret

