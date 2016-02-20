//Cracked by Roath
// Room: /d/mingjiao/shijie51.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
半天然的石阶偶能看到釜凿的印记。两边植满了翠竹，密而有序，杂
而不乱。有一条小蹊镶入西边的竹中，探首过去，似并不很长。晨光撒过，
气息清然，碧竹亭亭而立，几只山雀小啼，五分幽逸，半成素爽。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"qiankun",
  "west" : __DIR__"liangong",
  "down" : __DIR__"moluo",
  "east" : __DIR__"shuyuan",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
