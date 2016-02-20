//Cracked by Roath
// Room: /d/mingjiao/tdating.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "厚土旗大厅");
	set("long", @LONG
此间不甚宏大，步入之中渐感一种压抑之意。厅中站有两排厚土旗弟
子，身着黄衣黄巾。厅中陈设并不豪华，但却有一种说不出的威严。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"txiaochang",
  "north" : __DIR__"tneitang",
]));
	set("objects",([
		__DIR__"npc/yanyuan" : 1,
	]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
