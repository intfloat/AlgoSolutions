# Write your MySQL query statement below
select d1.Name as Department, e1.Name as Employee, e1.Salary from Employee e1, Department d1
where e1.DepartmentId = d1.Id and 3 > (select COUNT(DISTINCT(e2.Salary)) 
                                       from Department d2, Employee e2 
                                       where e2.Salary > e1.Salary and e2.DepartmentId = d2.Id and d1.Id = d2.Id);
