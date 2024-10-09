-- 코드를 작성해주세요
select a.ID, a.GENOTYPE,b.genotype PARENT_GENOTYPE
from ecoli_data a
join ecoli_data b on a.parent_id=b.id
where a.genotype&b.genotype=b.genotype
order by a.id