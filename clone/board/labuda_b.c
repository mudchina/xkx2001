//Cracked by Roath
// /clone/board/labuda_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("辩经板", ({ "board" }) );
	set("location", "/d/xueshan/guangchang");
	set("board_id", "labuda_b");
	set("long", "这是一块大轮寺喇嘛辩论佛经用的留言板。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

