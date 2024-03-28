-- 코드를 입력하세요
SELECT MONTH(START_DATE) MONTH, CAR_ID,COUNT(*) RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where month(start_date) between 8 and 10
and car_id in (select car_id 
               from CAR_RENTAL_COMPANY_RENTAL_HISTORY
                where month(start_date) between 8 and 10
               group by car_id
               having COUNT(*)>=5)

group by month(start_date), car_id
ORDER BY 1,2 DESC