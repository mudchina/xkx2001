//Cracked by Kafei
// /clone/board/gumu_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("古墓弟子留言板", ({ "board" }) );
	set("location", "/d/zhongnan/dating");
	set("board_id", "gumu_b");
	set("long", "这是一个供古墓派弟子交留的留言板。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

