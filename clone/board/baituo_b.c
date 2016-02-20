//Cracked by Roath
// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("白驼碑", ({ "board" }) );
	set("location", "/d/xingxiu/btyard");
	set("board_id", "baituo_b");
	set("long", "这是一块白驼山庄子弟留言用的石碑。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

