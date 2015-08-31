s=input()
t=input()
ans=""
for i in range(len(s)):
    if s[i]==t[i]:
        ans += '0'
    else: ans += '1'
print(ans)

