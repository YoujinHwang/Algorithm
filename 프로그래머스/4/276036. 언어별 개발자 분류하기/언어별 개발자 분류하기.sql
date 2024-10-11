-- 코드를 작성해주세요
with CTE as (
select CATEGORY, SUM(CODE) IND
     FROM skillcodes
     GROUP BY CATEGORY
) 

select *
from 
(select case 
when (skill_code & (select IND
                       from CTE
                       where category='Front End'))!=0 
and (skill_code & (select CODE from skillcodes where name='Python')) !=0 then 'A'
when (skill_code & (select code 
                    from skillcodes 
                    where name='c#'))!=0 then 'B'
when (skill_code & (select IND
                       from CTE
                       where category='Front End')) !=0 then 'C'
end GRADE, ID, EMAIL
from developers ) a
where grade is not null
order by 1,2