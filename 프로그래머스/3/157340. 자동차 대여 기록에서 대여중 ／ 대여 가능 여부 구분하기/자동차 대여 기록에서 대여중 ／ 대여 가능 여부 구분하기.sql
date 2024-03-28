-- 코드를 입력하세요
SELECT CAR_ID, if
    (sum(if('2022-10-16' between start_date and end_date,1,0))=0,'대여 가능','대여중')  AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by car_id
order by 1 desc;