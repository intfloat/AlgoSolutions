# Write your MySQL query statement below
select d2.Name as Department, e1.Name as Employee, e1.Salary from Employee e1, Department d2
where e1.Salary = ( select MAX(e2.Salary) 
                    from Employee e2, Department d2 
                    where e2.DepartmentId = d2.Id and d2.Id = e1.DepartmentId ) and d2.Id = e1.DepartmentId;
