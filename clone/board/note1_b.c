//Cracked by Roath
// /clone/board/note1_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("玩家犯罪记录簿", ({ "board"}) );
	set("location", "/d/death/noteroom");
	set("board_id", "note1_b");
	set("long", "这是一块给巫师记录玩家犯规原因的留言板。\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}

