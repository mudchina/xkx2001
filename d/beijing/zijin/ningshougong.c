//Cracked by Roath
// Room: /d/beijing/zijincheng/ningshougong.c

inherit ROOM;

void create()
{
	set("short", "宁寿宫");
	set("long", @LONG
仿坤宁宫形式建，乾隆皇帝准备做太上皇时在此宫祭神。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huangjidian",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
