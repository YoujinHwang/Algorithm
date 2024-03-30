-- 코드를 입력하세요
SELECT a.CATEGORY, sum(sales) TOTAL_SALES
from BOOK a
join BOOK_SALES b
on a.book_id=b.book_id
where sales_date like '2022-01%'
group by category
order by 1