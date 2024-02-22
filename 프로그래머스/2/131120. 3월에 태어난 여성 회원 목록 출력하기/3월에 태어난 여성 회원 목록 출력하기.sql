-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(date_of_birth, "%Y-%m-%d") as DATE_OF_BIRTH 
from member_profile
where gender='W'
and month(date_of_birth)=3
and tlno is not null
order by member_id;