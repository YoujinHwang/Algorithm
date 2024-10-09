-- 코드를 작성해주세요
with recursive CTE as (
select *, 1 as GENERATION
FROM ecoli_data
where parent_id is null
union all
select a.*, b.GENERATION+1 as GENERATION
FROM ecoli_data a
join CTE b on a.parent_id=b.id)

select count(a.id) COUNT, GENERATION
from CTE a
left join ecoli_data b on a.id=b.parent_id
where b.parent_id is null
group by generation
order by 2

