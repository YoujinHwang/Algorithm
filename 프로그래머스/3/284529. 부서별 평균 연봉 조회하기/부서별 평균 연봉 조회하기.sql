-- 코드를 작성해주세요
select a.DEPT_ID,DEPT_NAME_EN, round(AVG(SAL)) AVG_SAL
FROM HR_DEPARTMENT a
join hr_employees b
on a.dept_id=b.dept_id
group by dept_id
order by 3 desc