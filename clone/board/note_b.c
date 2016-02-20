//Cracked by Roath
// /clone/board/note_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("巫师留言板", ({ "board"}) );
	set("location", "/d/death/noteroom");
	set("board_id", "note_b");
	set("long", "这是一块给巫师记录玩家犯规原因的留言板。\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}

