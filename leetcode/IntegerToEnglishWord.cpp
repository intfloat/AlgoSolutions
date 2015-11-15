const string arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                      "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                      "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string tens[] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const int billion = 1000000000;
const int million = 1000000;
const int thousand = 1000;
class Solution {
private:
    string aux(int num) {
        assert(num < 1000);
        string ret;
        if (num >= 100) {
            ret += arr[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            ret += tens[num / 10] + " ";
            num %= 10;
            if (num) ret += arr[num] + " ";
        }
        else {
            if (num) ret += arr[num] + " ";
        }
        return ret;
    }
public:
    string numberToWords(int num) {
        if (num == 0) return arr[0];
        string res;
        if (num >= billion) {
            res += aux(num / billion) + "Billion ";
            num %= billion;
        }
        if (num >= million) {
            res += aux(num / million) + "Million ";
            num %= million;
        }
        if (num >= thousand) {
            res += aux(num / thousand) + "Thousand ";
            num %= thousand;
        }
        if (num != 0) {
            res += aux(num);
            num = 0;
        }
        while (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};
