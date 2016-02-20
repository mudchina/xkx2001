//Cracked by Roath
// xiaolu1.c 华山后山小路
// qfy 7/9/1996

inherit ROOM;

void create()
{
	set("short", "小山路");
	set("long", @LONG
这是一条通向华山后山的小路。沿途风景极之清幽，参天古树，拔地
而起，两旁百花争艳。令人留连忘返。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"yunu",
		"southdown" : __DIR__"xiaolu2",
	]));

	set("outdoors","huashan");

	set("cost", 2);
	setup();
}


