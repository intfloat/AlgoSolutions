
class Complex:
    """
    Implementation of complex number by myself
    """

    def __init__(self, real, img):
        self.real = real
        self.img = img
        pass

    def __str__(self):
        if abs(self.img) < 1e-6:
            return '%.2f' % self.real
        elif abs(self.real) < 1e-6:
            return '%.2fi' % self.img
        elif self.img > 0:
            return '%.2f + %.2fi' % (self.real, self.img)
        else:
            return '%.2f - %.2fi' % (self.real, -self.img)

    def __add__(self, other):
        return Complex(self.real + other.real, self.img + other.img)

    def __sub__(self, other):
        return Complex(self.real - other.real, self.img - other.img)

    def __mul__(self, other):
        """
        (a+bi)(c+di) = ac-bd + (ad+bc)i
        """
        return Complex(self.real * other.real - self.img * other.img,
                        self.real * other.img + self.img * other.real)

    def __div__(self, other):
        """
        (a+bi)/(c+di) = (a+bi)(c-di)/(c^2+d^2)
        """
        res = self * Complex(other.real, -other.img)
        res.real /= other.real**2 + other.img**2
        res.img /= other.real**2 + other.img**2
        return res

    def mod(self):
        from math import sqrt
        return '%.2f' % sqrt(self.real**2 + self.img**2)

if __name__ == '__main__':
    from sys import stdin
    real, img = map(float, stdin.readline().strip().split())
    number1 = Complex(real, img)
    real, img = map(float, stdin.readline().strip().split())
    number2 = Complex(real, img)
    print number1 + number2
    print number1 - number2
    print number1 * number2
    print number1 / number2
    print number1.mod()
    print number2.mod()
