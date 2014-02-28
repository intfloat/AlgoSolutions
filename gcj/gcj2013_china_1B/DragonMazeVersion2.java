import java.awt.Point;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class DragonMazeVersion2 {

	public static int[][] maze = new int[105][105];
	public static int[][] curMin = new int[105][105];
	public static int[][] curMax = new int[105][105];
	public static boolean[][] visited = new boolean[105][105];
	public static int ex, ey, row, col;
	public static final int[] dir_x = {0, 0, 1, -1};
	public static final int[] dir_y = {1, -1, 0, 0};
	/**
	 * @param args
	 * 
	 * @see https://code.google.com/codejam/contest/2933486/dashboard
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		
		for(int i=1; i<=t; i++){
			row = cin.nextInt(); col = cin.nextInt();
			int sx = cin.nextInt(); int sy = cin.nextInt();
			ex = cin.nextInt(); ey = cin.nextInt();
			for(int j=0; j<row; j++){
				for(int k=0; k<col; k++){
					maze[j][k] = cin.nextInt();
					curMin[j][k] = Integer.MAX_VALUE;
					curMax[j][k] = Integer.MIN_VALUE;
				}
			}
			for(int j=0; j<visited.length; j++)
				Arrays.fill(visited[j], false);

//			add code here
			Queue<Point> q = new LinkedList<Point>();
			q.clear();
			q.add(new Point(sx, sy));
			curMin[sx][sy] = 0; 
			curMax[sx][sy] = maze[sx][sy];
			visited[sx][sy] = true;
			ArrayList<Integer> arr = new ArrayList<Integer>();
			Collections.sort(arr);
			
			while(q.isEmpty() == false){
				Point p = q.remove();
				
				int curx = p.x; int cury = p.y;
				for(int j=0; j<dir_x.length; j++){
					int x = curx+dir_x[j];
					int y = cury+dir_y[j];
					if(x>=row || x<0 || y>=col || y<0 || maze[x][y]==-1)
						continue;
					if(curMin[curx][cury]+1 > curMin[x][y])
						continue;
//					first step will be minimal step, however, 
//					power can be updated several times, a very clever idea.
					if(visited[x][y] == false){
						visited[x][y] = true;
						curMin[x][y] = curMin[curx][cury]+1;
						curMax[x][y] = curMax[curx][cury]+maze[x][y];
						q.add(new Point(x, y));
					}
					curMax[x][y] = Math.max(curMax[curx][cury]+maze[x][y], curMax[x][y]);
				}
			}// end while loop
			
			if(curMin[ex][ey] == Integer.MAX_VALUE)
				System.out.println("Case #"+i+": Mission Impossible.");			
			else
				System.out.println("Case #"+i+": "+curMax[ex][ey]);
		}
		return;
	}

}
