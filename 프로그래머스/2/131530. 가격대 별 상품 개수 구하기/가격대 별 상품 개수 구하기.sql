# -- 코드를 입력하세요
SELECT a.IND*10000 PRICE_GROUP, count(*) PRODUCTS
FROM (select *, truncate(price/10000,0) IND
     from product) a
group by ind
order by 1

