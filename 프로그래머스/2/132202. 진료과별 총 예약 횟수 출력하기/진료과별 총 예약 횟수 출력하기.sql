-- 코드를 입력하세요
SELECT MCDP_CD as 진료과코드, count(*) 5월예약건수
FROM appointment
where year(apnt_ymd)=2022 and month(apnt_ymd)=5
group by MCDP_CD
order by 2,1