sort the task in decreasing order;
void dfs(int taskNumber){
	//����һ��������䷽���ı߽� 
	if(taskNumber==N+1){
		//�ж���Сʱ���Ƿ���Ҫ���и��� 
		if(currentTime<minimumTime)
			minimumTime=currentTime;
		return;
	}
	for(int i=0;i<machineNumber;i++){
		assign task taskNumber to machine i;
		update current time;
		//�����ǰ�����������Ҫ��ʱ���Ѿ������˵�ǰ�����Ž�
		//����л��� 
		if(currentTime is larger than minimumTime)
			return;
		//���#i�����ĵ�һ�������֮ǰ�Ļ���Ҫ�̣�����л��� 
		if(machine i's first task is longer than machine (i-1)'s first task)
			return;
		//������������ 
		dfs(taskNumber+1);
		recover the original information;
	}
	return;
}
