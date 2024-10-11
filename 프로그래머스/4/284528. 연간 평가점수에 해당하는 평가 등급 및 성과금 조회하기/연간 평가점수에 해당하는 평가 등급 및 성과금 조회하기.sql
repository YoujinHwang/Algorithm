-- 코드를 작성해주세요
with CTE as (
select emp_no, case 
    when sum(score)/2>=96 then 'S'
when sum(score)/2>=90 then 'A'
when sum(score)/2 >=80 then'B'
else 'C' 
end GRADE
FROM hr_grade
group by emp_no
)

select a.emp_no, a.emp_name, GRADE, case 
when GRADE='S' then sal*0.2 
when GRADE ='A' then sal*0.15
when GRADE ='B' then sal*0.1
else 0
end BONUS
from hr_employees a
join CTE b
on a.emp_no=b.emp_no
order by 1