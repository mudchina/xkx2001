//Cracked by Roath
// Room: /d/xixia/dongdajie.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是灵州东大街，同样的宽阔与干净，相比西大街的冷清要热闹多
了，街上人来人往，熙熙攘攘，几个小孩正在胡同口玩耍，南面有不少
人围在一起，北面是衙门，路边有条狗正在追一只猫。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jiangjunfu",
  "west" : __DIR__"center",
  "north" : __DIR__"yamen",
  "east" : __DIR__"dongmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
