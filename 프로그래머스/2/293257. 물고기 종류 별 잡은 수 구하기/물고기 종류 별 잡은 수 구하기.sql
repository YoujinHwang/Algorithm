-- 코드를 작성해주세요
select count(*) FISH_COUNT, FISH_NAME 
FROM fish_info a
join fish_name_info b
on a.fish_type=b.fish_type
group by fish_name
ORDER BY 1 DESC