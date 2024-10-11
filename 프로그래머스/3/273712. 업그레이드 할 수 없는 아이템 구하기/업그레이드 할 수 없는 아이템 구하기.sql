-- 코드를 작성해주세요
select a.ITEM_ID, ITEM_NAME, RARITY
FROM item_info a
left join item_tree b
on a.item_id=b.parent_item_id
where parent_item_id is null
order by 1 desc