-- 코드를 입력하세요
SELECT USER_ID, NICKNAME, CONCAT(CITY," ",STREET_ADDRESS1," ",STREET_ADDRESS2) 전체주소, CONCAT(LEFT(TLNO,3),"-",MID(TLNO,4,4),"-",RIGHT(TLNO,4)) 전화번호
from USED_GOODS_BOARD a
join USED_GOODS_USER b
on a.writer_id=b.user_id
group by writer_id
having count(*)>=3
ORDER BY 1 DESC;