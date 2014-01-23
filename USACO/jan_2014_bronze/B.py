

reader = file('slowdown.in', 'r')
writer = file('slowdown.out', 'w')
N = int(reader.readline())
time = []
dis = []
cur_time = 0.0
cur_dis = 0.0
speed_inv = 1
res = 0.0
for i in range(N):
    tmp = reader.readline().split()
    if tmp[0]=='T':
        time.append(int(tmp[1]))
    else:
        dis.append(int(tmp[1]))
time.sort()
dis.sort()
time_len = len(time)
dis_len = len(dis)
ptr1 = 0
ptr2 = 0
while ptr1<time_len or ptr2<dis_len:
    if ptr1<time_len:
        time1 = time[ptr1]
    else: time1 = 99999999
    if ptr2<dis_len:
        time2 = cur_time+(dis[ptr2]-cur_dis)*speed_inv
    else: time2 = 99999999
    if time1<time2:
        cur_dis += ((time1-cur_time)*1.0)/speed_inv
        res = time[ptr1]
        cur_time = time[ptr1]
        ptr1 += 1
        speed_inv += 1
    else:
        cur_dis = dis[ptr2]
        res = time2
        cur_time = time2
        ptr2 += 1
        speed_inv += 1
if cur_dis<1000:
    cur_time += (1000-cur_dis)*speed_inv
writer.write(str(int(round(cur_time))))
