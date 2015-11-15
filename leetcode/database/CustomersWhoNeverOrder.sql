# Write your MySQL query statement below
select Name from Customers where Customers.Id not in (select CustomerId from Orders);
