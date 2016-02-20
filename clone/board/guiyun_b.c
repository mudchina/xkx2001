//Cracked by Roath
// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("归云庄记事板",({"board"}));
	set("location", "/d/taihu/qianyuan");
	set("board_id", "guiyun_b");
	set("long", "这是供归云庄门人留言的板子.\n");
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

