-- 코드를 입력하세요
SELECT year(sales_date) YEAR, month(sales_date) MONTH, GENDER, count(distinct a.user_id) USERS
from user_info a
join online_sale b 
on a.user_id=b.user_id
where gender is not null
group by year, month,gender
order by year, month, gender