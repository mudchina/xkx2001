//Cracked by Roath
// Room: /d/dali/shanlu.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条的山路蜿蜒穿行在茂密的森林中，向东不远可达大理国的中心--大理城，
西去则进入深山。由于接近大理中心，这条路修整的相当平整，尽管山势崎岖，
行路并不困难。
LONG);
	set("exits", ([
		"westup" : __DIR__"minov41",
		"eastdown" : __DIR__"northgate",
		]));
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
