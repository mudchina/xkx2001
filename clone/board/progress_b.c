//Cracked by Roath
// /clone/board/progress_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("侠客行进度表", ({ "board" }) );
	set("location", "/d/wizard/meeting_room");
	set("board_id", "progress_b");
	set("long", "这是一个供侠客行巫师们汇报工作计划以及进度的留言板。\n" );
	set("wizard_only", 1);
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

