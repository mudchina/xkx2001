//Cracked by Roath
// /u/arthurgu/arthurgu_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("寻欢工作室留言板", ({ "board" }) );
	set("location", "/u/arthurgu/workroom");
	set("board_id", "arthurgu_b");
	set("long", "这是一块寻欢与巫师之间交流用的专用板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

