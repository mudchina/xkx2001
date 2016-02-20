//Cracked by Roath
// /clone/board/emei1_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("峨嵋留言处", ({ "board" }) );
	set("location", "/d/emei/baoguomen");
	set("board_id", "emei1_b");
	set("long", "这是一个峨嵋山游客题诗留言的地方。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

