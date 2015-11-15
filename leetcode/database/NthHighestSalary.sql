CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      select DISTINCT(Salary) from Employee order by Salary DESC LIMIT M, 1
  );
END
