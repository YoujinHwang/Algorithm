-- 코드를 입력하세요
SELECT BOARD_ID, WRITER_ID,TITLE,PRICE,
case 
    when status='DONE' THEN '거래완료'
    when status='SALE' THEN '판매중'
    when status='reserved' then '예약중'
    end STATUS
FROM USED_GOODS_BOARD
WHERE created_date='2022-10-05'
order by 1 desc;