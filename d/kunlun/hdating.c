//Cracked by Roath
// Room: /d/mingjiao/hdating.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "洪水旗大厅");
	set("long", @LONG
此间不甚宏大，步入之中渐感一种阴寒之意。厅中站有两排明教弟子，
每人左手衣袖上都锈有一红色火焰。厅中陈设并不豪华，但却有一种说不
出的威严。四下角落里各摆放着一三人合抱粗细的黑铁缸，缸口外隐隐发
白，仔细一瞧，却是一层薄薄的冰璃。一股股凉气便从此溢出。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoulang",
  "out" : __DIR__"xiaochang",
]));
	set("objects",([
		__DIR__"npc/tangyang" : 1,
	]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
