-- 코드를 작성해주세요
select distinct ID, EMAIL, FIRST_NAME, LAST_NAME
from developers as a
join skillcodes as b
on skill_code&code<>0
where b.name='Python'
or b.name='C#'
order by ID