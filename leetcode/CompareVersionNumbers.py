class Solution:

    # @param a, a string
    # @param b, a string
    # @return a boolean
    def compareVersion(self, version1, version2):        
        if version1 == version2:
            return 0
        elif version1 == '':
            version1 = '0'
        elif version2 == '':
            version2 = '0'
        p1, p2 = version1.find('.'), version2.find('.')
        if p1 < 0 and p2 < 0:
            if int(version1) < int(version2):
                return -1;
            elif int(version1) == int(version2):
                return 0;
            else:
                return 1
        if p1 < 0 and p2 > 0:
            if int(version1) > int(version2[:p2]):
                return 1
            elif int(version1) < int(version2[:p2]):
                return -1
            else:
                return self.compareVersion('', version2[p2 + 1:])
        if p1 > 0 and p2 < 0:
            if int(version2) > int(version1[:p1]):
                return -1
            elif int(version1[:p1]) > int(version2):
                return 1
            else:
                return self.compareVersion(version1[p1 + 1:], '')
        if p1 > 0 and p2 > 0:
            if int(version1[:p1]) > int(version2[:p2]):
                return 1
            elif int(version1[:p1]) < int(version2[:p2]):
                return -1
            else:
                return self.compareVersion(version1[p1 + 1:], version2[p2 + 1:])


# so many special cases...
if __name__ == '__main__':
    s = Solution()
    print s.compareVersion('1.2', '3.5')
    print s.compareVersion('0.1', '0.0.1')
    print s.compareVersion('1', '1.0')
    print s.compareVersion('1', '0')
    print s.compareVersion('1.0', '1.10')
    print s.compareVersion('0.1', '1.0')