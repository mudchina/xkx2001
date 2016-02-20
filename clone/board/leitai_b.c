//Cracked by Roath
// /clone/board/leitai_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("擂台布告墙", ({ "wall" }) );
	set("location", "/d/quanzhou/leitai2");
	set("board_id", "leitai_b");
	set("long", "这是擂台旁一面贴满各种告示和字贴的大墙。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

