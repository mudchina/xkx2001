//Cracked by Roath

inherit BULLETIN_BOARD;

void create()
{
	set_name("黑板", ({ "board" }) );
	set("location", "/d/death/blkbot");
	set("board_id", "emptyroom_b");
	set("long", "这是一个供犯错误的玩家写检查的留言板。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

