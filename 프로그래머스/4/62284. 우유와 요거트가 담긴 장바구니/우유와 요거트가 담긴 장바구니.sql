-- 코드를 입력하세요
SELECT a.CART_ID
FROM (SELECT CART_ID 
     FROM CART_PRODUCTS
     WHERE NAME='Milk') a
join (select cart_id
     from cart_products
     where name='Yogurt') b
on a.cart_id=b.cart_id
order by 1