-- 코드를 입력하세요
SELECT a.AUTHOR_ID, AUTHOR_NAME, CATEGORY, sum(sales*price) TOTAL_SALES
FROM book a
join author b
on a.author_id=b.author_id
join book_sales c
on a.book_id=c.book_id
where year(c.sales_date)=2022
and month(c.sales_date)=1
group by a.author_id, category
order by a.author_id,category desc;