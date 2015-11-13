object Solution {

    // calculate factorial of n
        def factorial(n: Int): Int = {
            if (n == 1 || n == 0) return 1
            else return n * factorial(n - 1)
        }                                 //> factorial: (n: Int)Int
        
        def helper(cur: Int, N: Int): List[Int] = {
            if (cur > N) return List()
            else return List(factorial(N) / (factorial(cur) * factorial(N - cur))) ++ helper(cur + 1, N)
        }                                 //> helper: (cur: Int, N: Int)List[Int]

        def solve(cur: Int, K: Int) {
            if (cur >= K) return
            println(helper(0, cur) mkString " ")
            solve(cur + 1, K)
            return
        }                                 //> solve: (cur: Int, K: Int)Unit

    def main(args: Array[String]) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution
*/
                solve(0, readInt())
    }                                             //> main: (args: Array[String])Unit
//    println(List(1, 2, 3, 4, 5) mkString "_")
//    solve(0, 5)
}
