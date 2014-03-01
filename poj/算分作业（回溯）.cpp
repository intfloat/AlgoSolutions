sort the task in decreasing order;
void dfs(int taskNumber){
	//到达一种任务分配方案的边界 
	if(taskNumber==N+1){
		//判断最小时间是否需要进行更新 
		if(currentTime<minimumTime)
			minimumTime=currentTime;
		return;
	}
	for(int i=0;i<machineNumber;i++){
		assign task taskNumber to machine i;
		update current time;
		//如果当前任务完成所需要的时间已经超过了当前的最优解
		//则进行回溯 
		if(currentTime is larger than minimumTime)
			return;
		//如果#i机器的第一个任务比之前的机器要短，则进行回溯 
		if(machine i's first task is longer than machine (i-1)'s first task)
			return;
		//继续进行搜索 
		dfs(taskNumber+1);
		recover the original information;
	}
	return;
}
