# Write your MySQL query statement below
select FirstName, LastName, City, State
from Person left outer join Address on Person.PersonId = Address.PersonId
