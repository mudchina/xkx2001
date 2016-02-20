//Cracked by Roath
// Room: /d/xixia/dangpu.c

inherit ROOM;

void create()
{
	set("short", "铁面当铺");
	set("long", @LONG
这是家远近闻名的当铺，三开间的门面，一块写着『铁面当铺』
四个金字的黑匾，足足七尺高的紫檀木的柜台被磨得光可照人，柜台
后的老朝奉头也不抬的只顾拨拉着算盘，柜台上方挂着一块牌子，上
书："你情我愿，概不赊欠"。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"nandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
