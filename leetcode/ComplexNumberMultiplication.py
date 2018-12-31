class Solution:

    def _parse(self, s):
        real, image = s.split('+')
        return int(real), int(image[:-1])

    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        real_a, image_a = self._parse(a)
        real_b, image_b = self._parse(b)
        real_res = real_a * real_b - image_a * image_b
        image_res = real_a * image_b + real_b * image_a
        return '{}+{}i'.format(real_res, image_res)


solution = Solution()
print(solution.complexNumberMultiply('1+1i', '1+1i'))
print(solution.complexNumberMultiply('1+-1i', '1+-1i'))
