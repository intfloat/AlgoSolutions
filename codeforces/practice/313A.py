'''
Created on 2013-7-14

@author: Administrator
'''

# we will get a list after this step
R = lambda:map(int, raw_input().split())
money = R()[0]
if money>=0:
    print money
else:
    money = abs(money)
    choice1 = -(money/10)
    choice2 = -((money/100)*10 + money%10)
    print max(choice1, choice2)