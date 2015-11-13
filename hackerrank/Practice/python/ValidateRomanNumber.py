import re
from sys import stdin

"""
reference:
http://stackoverflow.com/questions/267399/how-do-you-match-only-valid-roman-numerals-with-a-regular-expression
"""
pattern = re.compile('^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$')
s = stdin.readline().strip()
if pattern.match(s):
    print 'True'
else:
    print 'False'
