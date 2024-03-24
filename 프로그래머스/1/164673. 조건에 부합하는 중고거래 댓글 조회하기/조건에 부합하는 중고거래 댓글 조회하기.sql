-- 코드를 입력하세요
SELECT a.TITLE, a.BOARD_ID,b.REPLY_ID, b.WRITER_ID,b.CONTENTS, date_format(b.created_date,'%Y-%m-%d') as CREATED_DATE
from USED_GOODS_BOARD as a
INNER JOIN USED_GOODS_REPLY as b
ON a.board_id=b.board_id
where year(a.created_date)="2022" 
and month(a.created_date)="10"
order by b.created_date,a.title