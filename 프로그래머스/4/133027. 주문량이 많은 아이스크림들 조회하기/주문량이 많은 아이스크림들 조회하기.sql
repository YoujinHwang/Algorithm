-- 코드를 입력하세요
SELECT A.FLAVOR
FROM FIRST_HALF AS A
JOIN (select flavor, sum(total_order) total
     from july
     group by flavor) B
ON A.flavor=B.flavor
ORDER BY B.total+A.total_order DESC
LIMIT 3