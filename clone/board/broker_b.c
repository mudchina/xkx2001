//Cracked by Roath
// /clone/board/broker_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("招亲看台的柱子", ({"board" }) );
	set("location", "/d/city/kantai");
	set("board_id", "broker_b");
	set("long", "这是比武招亲看台的柱子，上面贴满了各种征婚，寻人,比武启示。\n" );
	setup();
	set("capacity", 120);
	replace_program(BULLETIN_BOARD);
}

