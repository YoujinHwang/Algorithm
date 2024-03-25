-- 코드를 입력하세요
SELECT concat("/home/grep/src/",a.board_id,"/",file_id,file_name,file_ext) FILE_PATH
from used_goods_board a,used_goods_file b
where a.board_id=b.board_id
and a.board_id=(select board_id from used_goods_board order by views desc limit 1)
order by file_id desc