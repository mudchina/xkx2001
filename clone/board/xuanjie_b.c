//Cracked by Roath
// /clone/board/xuanjie_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("玄劫教留言板", ({ "board" }) );
	set("location", "/d/qilian/datang");
	set("board_id", "xuanjie_b");
	set("long", "这是一个供玄劫教教众交流的留言板。\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}

