//Cracked by Roath
// /clone/board/huashan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("华山弟子留言板", ({ "board" }) );
	set("location", "/d/huashan/pianting");
	set("board_id", "huashan_b");
	set("long", "这是一个供华山门下交留的留言板。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

