//Cracked by Roath
// /clone/board/nanyang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("客店留言板", ({ "board" }) );
	set("location", "/d/shaolin/kedian1");
	set("board_id", "nanyang_b");
	set("long", "有有用的话就往这里说，乱灌水杀无赦。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

