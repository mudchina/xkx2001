//Cracked by Roath
// wuceng.c 五层楼
// by Fang 8/26/96

inherit ROOM;

void create()
{
	set("short", "复真观五层楼");
	set("long", @LONG
复真观五层楼构造奇特，其间有十二根梁枋交叉重叠，下面仅用
一柱支撑，即有名的“一柱十二梁”。在这里俯瞰群山，烟云迷离，
为观景胜地。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"taizipo",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

