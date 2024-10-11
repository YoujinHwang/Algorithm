-- 코드를 작성해주세요
with Total as (
select emp_no, sum(score) total
from hr_grade
group by emp_no),

Maxi as (
select max(total) maxTotal
from Total)


select total SCORE, a.emp_no EMP_NO, a.emp_name EMP_NAME, a.position POSITION, a.email EMAIL
FROM hr_employees a
join Total b
on a.emp_no=b.emp_no
join Maxi c
on b.total=c.maxTotal
where maxTotal is not null

    
    