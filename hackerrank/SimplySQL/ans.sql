-- Q1
select CEIL(AVG(Salary - REPLACE(Salary, '0', ''))) from Employees;

-- Q2
select case
when A + B <= C then 'Not A Triangle'
when A + C <= B then 'Not A Triangle'
when B + C <= A then 'Not A Triangle'
when A = B and B = C then 'Equilateral'
when A = B or B = C or A = C then 'Isosceles'
else 'Scalene' END from Triangles;

-- Q3
select Name from Students where Marks > 75 order by SUBSTR(Name, LENGTH(Name) - 2, 3) ASC, ID ASC;

-- Q4
select CONCAT(Name, '(', SUBSTR(Occupation, 1, 1), ')') from Occupations order by Name ASC;

select CONCAT('There are total ', COUNT(Name), ' ', LOWER(Occupation), 's.')
from Occupations
group by Occupation
order by COUNT(Name);

-- Q5
set @did = 0;
set @pid = 0;
set @sid = 0;
set @aid = 0;
set @tot = 0;
select doctor.Name, professor.Name, singer.Name, actor.Name
from (
    (select @tot := @tot + 1 as ID, Name from Occupations) as original
    LEFT JOIN (select @did := @did + 1 as ID, Name from Occupations where Occupation = 'Doctor' order by Name ASC) as doctor on (original.ID = doctor.ID)
    LEFT JOIN (select @pid := @pid + 1 as ID, Name from Occupations where Occupation = 'Professor' order by Name ASC) as professor on (original.ID = professor.ID)
    LEFT JOIN (select @sid := @sid + 1 as ID, Name from Occupations where Occupation = 'Singer' order by Name ASC) as singer on (original.ID = singer.ID)
    LEFT JOIN (select @aid := @aid + 1 as ID, Name from Occupations where Occupation = 'Actor' order by Name ASC) as actor on (original.ID = actor.ID)
    )
where (doctor.Name <> 'NULL') or (professor.name <> 'NULL') or (singer.Name <> 'NULL') or (actor.name <> 'NULL');

-- Q6
select Name, Grade, Marks
from (
    select Name, (select Grade from Grades where Marks >= Min_Mark and Marks <= Max_Mark) as Grade, Marks
    from Students
) as t
where Grade >= 8
order by Grade DESC, Name ASC;

select 'NULL', Grade, Marks
from (
    select Name, (select Grade from Grades where Marks >= Min_Mark and Marks <= Max_Mark) as Grade, Marks
    from Students
) as t
where Grade < 8
order by Grade DESC, Marks ASC;

-- Q7
select distinct case
when P IS NULL then CONCAT(N, ' Root')
when N2 IS NULL then CONCAT(N, ' Leaf')
else CONCAT(N, ' Inner') end
from (select t1.N as N, t1.P as P, t2.N as N2
    from BST t1 left join BST t2 on t2.P = t1.N) as t
order by N ASC;

-- Q8
select distinct f1.X as X1, f1.Y as Y1
from Functions f1
where f1.X <= f1.Y and ((f1.X <> f1.Y and EXISTS(select * from Functions f where f.X = f1.Y and f.Y = f1.X))
    or (f1.X = f1.Y and (select COUNT(*) from Functions f where f.X = f1.X and f.Y = f1.Y) >= 2))
order by X1;

-- Q9
set @sid = 0;
set @eid = 0;
select T1.dt, T2.dt
from (
    (select (@sid := @sid + 1) as ID, p1.Start_Date as dt from Projects p1 where (select COUNT(*) from Projects p2 where p2.End_Date = p1.Start_Date) = 0) as T1
    JOIN
    (select (@eid := @eid + 1) as ID, p1.End_Date as dt from Projects p1 where (select COUNT(*) from Projects p2 where p2.Start_Date = p1.End_Date) = 0) as T2 on (T1.ID = T2.ID)
    )
order by (T2.dt - T1.dt) ASC, T1.dt ASC;

-- Q10
select distinct s.Name
from Students s, Friends f, Packages p1, Packages p2
where (f.ID = s.ID and f.Friend_ID = p1.ID and s.ID = p2.ID and p2.Salary < p1.Salary)
order by p1.Salary ASC;
