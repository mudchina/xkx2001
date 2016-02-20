//Cracked by Roath
// Room: /d/dali/tower3.c

inherit ROOM;

void create()
{
	set("short", "第三层");
	set("long", @LONG
雕绕绫坐像四座，坐像间之四面各雕佛及菩萨一组。识者谓北面多臂观音，
南面为地藏菩萨。合神佛面目和蔼，雕刻精细，造形优美。
LONG);
	set("exits", ([
		"up" : __DIR__"tower4",
		"down" : __DIR__"tower2",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
