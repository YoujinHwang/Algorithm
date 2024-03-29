-- 코드를 입력하세요
SELECT CATEGORY,price MAX_PRICE, PRODUCT_NAME
from FOOD_PRODUCT
where category in ('과자','국','김치','식용유')
and (category, price) in (select category, max(price) price
                         from FOOD_PRODUCT
                         group by category)


order by 2 desc