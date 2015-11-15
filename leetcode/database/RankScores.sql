# Write your MySQL query statement below
select s1.Score, (select COUNT(DISTINCT(s2.Score)) + 1 
                  from Scores s2 
                  where s2.Score > s1.Score) as Rank 
from Scores s1 order by s1.Score DESC;
