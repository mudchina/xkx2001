//Cracked by Roath
// /clone/board/emei2_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("峨嵋弟子留言板", ({ "board" }) );
	set("location", "/d/emei/hz_guangchang");
	set("board_id", "emei2_b");
	set("long", "这是一个供峨嵋弟子交流的留言板。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

