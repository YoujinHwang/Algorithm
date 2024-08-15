-- 코드를 작성해주세요
SELECT count(id) as count
from ECOLI_DATA
WHERE (2&GENOTYPE=0) and (5&genotype) in (1,4,5);