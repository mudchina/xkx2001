//Cracked by Roath
// /clone/board/gaibang_r.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("扬州城人物侦测报告", ({ "report" }) );
	set("location", "/d/gaibang/gbxiaowu");
	set("board_id", "gaibang_r");
	set("long", "这是一个供丐帮弟子交流信息的留言板。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

