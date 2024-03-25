-- 코드를 입력하세요
select a.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS,round(avg(review_score),2) SCORE
from rest_review a
join rest_info b
on a.rest_id=b.rest_id
where address like "서울%"
group by a.rest_id
order by score desc, favorites desc