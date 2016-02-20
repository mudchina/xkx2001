//Cracked by Roath
// /clone/board/shenlong_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("神龙教弟子留言板", ({ "board" }) );
set("location", "/d/shenlong/tingkou");
	set("board_id", "shenlong_b");
	set("long", "这是一个供神龙教教内交流的留言板。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

