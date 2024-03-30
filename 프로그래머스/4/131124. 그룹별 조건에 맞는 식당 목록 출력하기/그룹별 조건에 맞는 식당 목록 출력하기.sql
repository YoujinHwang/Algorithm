-- 코드를 입력하세요
SELECT MEMBER_NAME,	REVIEW_TEXT, date_format(REVIEW_DATE,"%Y-%m-%d")	
from MEMBER_PROFILE a
join REST_REVIEW b
on a.MEMBER_ID=b.member_id
join (select member_id, dense_rank() over(order by count(*) desc) as rnk
     from REST_REVIEW 
      group by member_id
     ) c
on a.MEMBER_ID=c.member_id
where rnk=1
# group by a.member_id
order by 3,2
