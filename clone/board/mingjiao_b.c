//Cracked by Roath
// /u/zhangchi/obj/mingjiao_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("明教留言板", ({ "board" }) );
	set("location", "/u/zhangchi/workroom");
	set("board_id", "mingjiao_b");
	set("long", "这是一块明教弟子的留言板。\n");
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

