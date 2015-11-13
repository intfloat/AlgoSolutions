object Solution {

    def solve(P: String, Q: String, cur: StringBuilder): String = {
        if (P.length == 0) return cur.mkString
        else return solve(P.tail, Q.tail, cur.append(P(0)).append(Q(0)))
    }                                         //> solve: (P: String, Q: String, cur: StringBuilder)String

   def main(args: Array[String]) {
     /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
            println(solve(readLine().trim(), readLine().trim(), new StringBuilder))
   }                                              //> main: (args: Array[String])Unit

    // solve("abscd", "gwdcs", new StringBuilder)
}
