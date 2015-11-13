
from sys import stdin
import xml.etree.ElementTree as etree

def get_attr(tree):
    if tree is None:
        return 0
    # print dir(tree)
    root = tree.getchildren()
    res = len(tree.attrib)
    for child in root:
        # recursively calculate for each child node
        res += get_attr(child)
    return res

N = int(stdin.readline().strip())
result = 0
line = ''
for _ in xrange(N):
    line += stdin.readline().strip()

tree = etree.ElementTree(etree.fromstring(line))
result += len(tree.getroot().attrib)

print get_attr(tree.getroot())

