//������������С���еĹ����㷨 
bfs (residualNetWork G){
	q.push(source);
	visited[source]=true;
	//���ö���ʵ�ֹ������ 
	while(q.empty()==false){
		vertex=q.front();
		q.pop();
		//�����ö������������б� 
		for(each edge connected to vertex){
			if(the other vertex connected to the edge is not selected){
				q.push(other vertex);
				visited[other vertex]=true;
			}
		}
	}
	//�ж϶���������һ������ 
	for(each vertex){
		if(visited[vertex]==true)
			then vertex is belong to S;
		else then vertex is belong to V;
	}
	print the final result; 
	return;
}
