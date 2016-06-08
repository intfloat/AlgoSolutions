import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {

    private ArrayList<Integer> numbers;
    private int ptr;

    public NestedIterator(List<NestedInteger> nestedList) {
        this.numbers = new ArrayList<Integer>();
        for (NestedInteger nestedInteger : nestedList) {
            this.numbers.addAll(makeFlat(nestedInteger));
        }
        this.ptr = 0;
    }

    @Override
    public Integer next() {
        return this.numbers.get(ptr++);
    }

    @Override
    public boolean hasNext() {
        return this.ptr < this.numbers.size();
    }

    private List<Integer> makeFlat(NestedInteger nestedInteger) {
        List<Integer> ret = new ArrayList<>();
        if (nestedInteger.isInteger()) {
            ret.add(nestedInteger.getInteger());
        }
        else {
            for (NestedInteger obj : nestedInteger.getList()) {
                ret.addAll(makeFlat(obj));
            }
        }
        return ret;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
