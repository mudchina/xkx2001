//Cracked by Roath
// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("扬威武馆留言板", ({ "board" }) );
	set("location", "/d/quanzhou/qianting");
	set("board_id", "wuguan_b");
	set("long", "这是一个供武馆子弟交留的留言板。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

