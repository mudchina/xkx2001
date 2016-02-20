//Cracked by Roath
// wuyun.c 复真观五云楼
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "复真观五云楼");
	set("long", @LONG
复真观五云楼构造奇特，其间有十二根梁枋交叉重叠，下面仅用一柱支
撑，即有名的“一柱十二梁”。传说玄帝幼时在此读书，苦修四十二年得其
大道，寓矢志不渝，终成栋梁之才。在这里俯瞰群山，烟云迷离，被誉为中
国古建筑的奇迹。
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

