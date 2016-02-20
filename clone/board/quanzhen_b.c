//Cracked by Roath
// /clone/board/quanzhen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("全真派留言板", ({ "board" }) );
	set("location", "/d/zhongnan/taijie2");
	set("board_id", "quanzhen_b");
	set("long", "这是一个留言板。\n" );
	setup();
	set("capacity", 120);
	replace_program(BULLETIN_BOARD);
}

