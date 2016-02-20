//Cracked by Roath
// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("桃花岛弟子留言板",({"board"}));
	set("location", "/d/taohua/jingshe");
	set("board_id", "taohua_b");
	set("long", "这是供桃花岛门人交留的记事板.\n");
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

