//Cracked by Roath
// /clone/board/broker_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("月老亭的柱子", ({"board",  "zhuzi" }) );
	set("location", "/d/city/yuelao");
	set("board_id", "broker_b");
	set("long", "这是月老亭的柱子，上面贴满了各种征婚启示，寻人启示。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

