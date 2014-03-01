void dfs(numberOfLeftRoom){
	if(numberOfLeftRoom==0){
		if(soilderNumber<minimum)
			minimum=soilderNumber;
		return for further search;
	}
	currentRoom=find the first unMonitored room;
	for (every empty position that is adjacent to currentRoom){
		put one soilder on this position;
		update the layout;
		//根据当前得到的最小值进行剪枝 
		if((soilderNumber+leftRoom/5)>=minimum)
			continue;
		soilderNumber++;
		dfs(updateNumberOfLeftRoom);
		soilderNumber--;
		recover the original layout;
	}
	return;
}
