
reader = file('bteams.in', 'r')
writer = file('bteams.out', 'w')
teams = []
skill = []
result = 0

# just enumerate every possible cases
def dfs(pos):
    global result, teams, skill
    # check if it is a better solution
    if pos == 12:
        acc = []
        for team in teams:
            acc.append(sum(team))
        cur = max(acc)-min(acc)
        result = min([cur, result])
        return
    # use recursion technique to search
    for i in range(4):
        if len(teams[i]) < 3:            
            #print 'here: '+str(i)
            teams[i].append(skill[pos])
            dfs(pos+1)
            teams[i].pop()
    return

for i in range(4):
    teams.append([])
print len(teams)
for i in range(12):
    skill.append(int(reader.readline()))
skill.sort()
#print len(skill)
teams[0].append(skill[0])
result = sum(skill)
dfs(1)
writer.write(str(result))
