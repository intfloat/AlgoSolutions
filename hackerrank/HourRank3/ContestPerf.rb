arr, res = [], 0
for i in 0..4
    arr.push(gets.chomp.to_i)
    arr[i] -= i
    val = 100 - (arr[i] - 1) * 10
    if val < 0
        val = 0
    end
    res += val
end
print res
