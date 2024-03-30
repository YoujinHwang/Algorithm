-- 코드를 입력하세요
WITH RECURSIVE CTE as (
    select 0 as num
    union all
    select num+1
    from cte
    where num<23
),animal_out_re as (
    select hour(datetime) as hour,
    count(animal_id) as cnts
    from animal_outs
    group by 1
    order by 1
    )
select cte.num, ifnull(cnts,0) 
from cte
left join animal_out_re o
on cte.num=o.hour

