//Cracked by Roath
// Room: /d/dali/dalicheng14.c

inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
大理国虽小，却重视精兵良将。然屈人必先屈志，兵戈乃下下之策，段氏大
理先与北邻宋朝修和，再以姻亲拉拢当地人，多年无战事。这是城里的铁骑营，
为皇族的嫡系，装备给养无不优于中原地方。军士们严缜以待，盔甲鲜明，刀剑
锋利。
LONG);
	set("objects", ([
		__DIR__"npc/weishi2" : 1,
		__DIR__"npc/dalishibing" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"dalicheng13",
		"west" : __DIR__"dalicheng15",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
