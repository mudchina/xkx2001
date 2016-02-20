//Cracked by Roath
// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("神龟驮玉碑", ({ "board" }) );
	set("location", "/d/wudang/sanqingdian");
	set("board_id", "wudang_b");
	set("long", "这是一块造型极大的石碑，俗称“龟驮碑”。\n"
	            "碑文中记录了许多武当过往的大小事件。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

