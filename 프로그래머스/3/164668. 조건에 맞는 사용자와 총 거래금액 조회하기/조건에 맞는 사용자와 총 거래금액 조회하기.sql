-- 코드를 입력하세요
SELECT USER_ID, NICKNAME, sum(price) TOTAL_SALES
from used_goods_board a
join used_goods_user b
on a.writer_id=b.user_id
where status='done'
group by a.writer_id
having total_sales>=700000
order by total_sales