-- 코드를 작성해주세요
select year(differentiation_date) YEAR,Maximum-b.size_of_colony YEAR_DEV, b.ID
from (select year(differentiation_date) year, Max(size_of_colony) Maximum
     from ecoli_data
     group by year(differentiation_date)) a
join ecoli_data b on a.year=year(b.differentiation_date)
order by 1, 2