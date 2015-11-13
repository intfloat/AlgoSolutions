
from sys import stdin
import xml.etree.ElementTree as etree

def solve(element):
    if element is None:
        return 0
    children = element.getchildren()
    res = 0
    for child in children:
        res = max(res, solve(child))
    return res + 1


N = int(stdin.readline().strip())
text = ''

for _ in xrange(N):
    text += stdin.readline().strip()

tree = etree.ElementTree(etree.fromstring(text))
root = tree.getroot()
print solve(root) - 1


