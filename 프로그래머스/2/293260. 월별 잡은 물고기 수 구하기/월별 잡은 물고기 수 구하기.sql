-- 코드를 작성해주세요
select count(*) FISH_COUNT, MONTH(time) MONTH
FROM FISH_INFO
GROUP BY 2
ORDER BY 2
