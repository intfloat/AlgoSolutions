class Solution(object):

    def checkIPV4(self, ip):
        fs = ip.split('.')
        if len(fs) != 4:
            return False
        for num in fs:
            if len(num) == 0:
                return False
            for c in num:
                if not (c >= '0' and c <= '9'):
                    return False
            n = int(num)
            if not (n >= 0 and n <= 255):
                return False
            if num[0] == '0' and len(num) > 1:
                return False
        return True

    def checkIPV6(self, ip):
        fs = ip.split(':')
        if len(fs) != 8:
            return False
        for num in fs:
            if len(num) == 0 or len(num) > 4:
                return False
            for c in num:
                valid = (c >= '0' and c <= '9') or (c >= 'a' and c <= 'f') or (c >= 'A' and c <= 'F')
                if not valid:
                    return False
        return True

    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if self.checkIPV4(IP):
            return "IPv4"
        elif self.checkIPV6(IP):
            return "IPv6"
        else:
            return "Neither"

sol = Solution()
print(sol.validIPAddress('172.16.254.1'))
print(sol.validIPAddress('172.16.254.01'))
print(sol.validIPAddress('2001:0db8:85a3:0000:0000:8a2e:0370:7334'))
print(sol.validIPAddress('2001:db8:85a3:0:0:8A2E:0370:7334'))
print(sol.validIPAddress('2001:0db8:85a3::8A2E:0370:7334'))
