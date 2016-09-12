import java.util.*;

public class Solution {

    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        Map<String, List<Edge>> graph = new HashMap<>();
        for (int i = 0; i < equations.length; ++i) {
            String u = equations[i][0];
            String v = equations[i][1];
            if (!graph.containsKey(u)) {
                graph.put(u, new ArrayList<>());
            }
            if (!graph.containsKey(v)) {
                graph.put(v, new ArrayList<>());
            }
            graph.get(u).add(new Edge(v, values[i]));
            graph.get(v).add(new Edge(u, 1.0 / values[i]));
        }
        double[] res = new double[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            String from = queries[i][0];
            String to = queries[i][1];
            if (!graph.containsKey(from) || !graph.containsKey(to)) {
                res[i] = -1.0;
            } else if (from.equals(to)) {
                res[i] = 1.0;
            } else {
                Map<String, Double> map = new HashMap<>();
                Queue<String> queue = new LinkedList<>();
                map.put(from, 1.0);
                queue.add(from);
                boolean ok = false;
                while (!queue.isEmpty()) {
                    String top = queue.poll();
                    double cur = map.get(top);
                    for (Edge edge : graph.get(top)) {
                        if (map.containsKey(edge.to)) {
                            continue;
                        } else {
                            map.put(edge.to, cur * edge.value);
                            queue.add(edge.to);
                        }
                    }
                    if (map.containsKey(to)) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) res[i] = -1.0;
                else res[i] = map.get(to);
            }
        }
        return res;
    }

    private static class Edge {
        String to;
        double value;
        public Edge(String to, double value) {
            this.to = to;
            this.value = value;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        for (double db : solution.calcEquation(
                new String[][]{{"a", "b"}, {"b", "c"}},
                new double[]{2.0, 3.0},
                new String[][]{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}})) {
            System.out.println(db);
        }
    }
}