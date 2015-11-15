
import java.util.regex.Pattern;

// java is very convenient to do this job
// but I need to implement by myself later.
public class Solution {
    public boolean isMatch(String s, String p) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return Pattern.matches(p, s);
    }
}
