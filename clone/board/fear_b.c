//Cracked by Roath
// /clone/board/fear_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIR"恐怖画板"NOR, ({ "board" }) );
	set("location", "/u/fear/workroom");
	set("board_id", "fear_b");
	set("long", "这是一个供大家谈论各种话题的留言板。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

