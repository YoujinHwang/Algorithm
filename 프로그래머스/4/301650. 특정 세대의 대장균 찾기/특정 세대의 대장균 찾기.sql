-- 코드를 작성해주세요
with recursive CTE as (
select id, parent_id, 1 as level
from ecoli_data
where parent_id is null
union all
select a.id, a.parent_id, b.level+1
from ecoli_data a
join CTE b on a.parent_id=b.id
)
select ID 
from CTE
where level=3
order by id