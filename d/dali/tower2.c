//Cracked by Roath
// Room: /d/dali/tower2.c

inherit ROOM;

void create()
{
	set("short", "第二层");
	set("long", @LONG
为四神坐像，各有表情，衣褶隆起，筋节毕现，肌肉暴起，极富立体感。
LONG);
	set("exits", ([
		"up" : __DIR__"tower3",
		"down" : __DIR__"tower1",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
