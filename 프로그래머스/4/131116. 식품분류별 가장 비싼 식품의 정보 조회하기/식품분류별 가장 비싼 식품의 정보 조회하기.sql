-- 코드를 입력하세요
# SELECT CATEGORY,price MAX_PRICE, PRODUCT_NAME
# from FOOD_PRODUCT
# where category in ('과자','국','김치','식용유')
# and (category, price) in (select category, max(price) price
#                          from FOOD_PRODUCT
#                          group by category)


# order by 2 desc

SELECT CATEGORY,price MAX_PRICE, PRODUCT_NAME
from FOOD_PRODUCT
where (CATEGORY='과자'
or CATEGORY='국'
or CATEGORY='김치'
or CATEGORY='식용유')
and (category, price) in (select category, max(price) price
                         from FOOD_PRODUCT
                         group by category)


order by 2 desc