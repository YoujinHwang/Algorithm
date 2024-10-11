-- 코드를 작성해주세요
select count(*) FISH_COUNT, max(length) as MAX_LENGTH, FISH_TYPE
from (select FISH_TYPE, case when length is null then 10 ELSE length end length 
     from fish_info) a
group by fish_type
having avg(length)>=33
order by 3