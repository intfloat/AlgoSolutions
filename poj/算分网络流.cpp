//网络流中求最小割切的广搜算法 
bfs (residualNetWork G){
	q.push(source);
	visited[source]=true;
	//利用队列实现广度搜索 
	while(q.empty()==false){
		vertex=q.front();
		q.pop();
		//检查与该顶点相连的所有边 
		for(each edge connected to vertex){
			if(the other vertex connected to the edge is not selected){
				q.push(other vertex);
				visited[other vertex]=true;
			}
		}
	}
	//判断顶点属于哪一个集合 
	for(each vertex){
		if(visited[vertex]==true)
			then vertex is belong to S;
		else then vertex is belong to V;
	}
	print the final result; 
	return;
}
