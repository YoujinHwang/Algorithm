-- 코드를 작성해주세요
select a.ID, b.FISH_NAME, a.LENGTH 
FROM FISH_INFO a
join fish_name_info b
on a.fish_type=b.fish_type
where length in (select Max(length)
                from fish_info 
                where fish_type=a.fish_type
                group by fish_type)
order by a.id