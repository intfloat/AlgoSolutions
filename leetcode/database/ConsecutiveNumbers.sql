# Write your MySQL query statement below
select DISTINCT(g1.Num)
from Logs g1, Logs g2, Logs g3
where g1.Id + 1 = g2.Id and g2.Id + 1 = g3.Id and g1.Num = g2.Num and g2.Num = g3.Num;
