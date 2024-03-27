-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
FROM (select a.animal_id,A.NAME, datediff(a.datetime,b.datetime) DIFF 
    from animal_outs a
    join animal_ins b
    on a.animal_id=b.animal_id
    order by DIFF desc
    limit 2 ) ANIMAL
order by DIFF DESC;