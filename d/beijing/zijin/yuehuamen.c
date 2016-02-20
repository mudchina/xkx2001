//Cracked by Roath
// Room: /d/beijing/zijincheng/yuehuamen.c

inherit ROOM;

void create()
{
	set("short", "月化门");
	set("long", @LONG
这是一扇月形宫门，每到月圆之时，月光洒在宫门之上，显得那
麽肃穆与威杀。这是连接后三殿和西六宫的一个偏门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"neiyoumen",
  "south" : __DIR__"nzsfang",
  "north" : __DIR__"pibenchu",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
