-- 코드를 입력하세요
SELECT INGREDIENT_TYPE, sum(total_order) TOTAL_ORDER
FROM first_half a
JOIN ICECREAM_INFO b
on a.flavor=b.flavor
group by ingredient_type
order by 2