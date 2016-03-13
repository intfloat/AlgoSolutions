class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        self.tokens = preorder.split(',')
        self.pos = 0
        if self.next() != '#':
            return self.check() and self.check() and (not self.hasNext())
        else:
            return not self.hasNext()
    def check(self):
        if not self.hasNext():
            return False
        token = self.next()
        if token == '#':
            return True
        else:
            return self.check() and self.check()

    def hasNext(self):
        return self.pos < len(self.tokens)
    def next(self):
        ret = self.tokens[self.pos]
        self.pos += 1
        return ret
