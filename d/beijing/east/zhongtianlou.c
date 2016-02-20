//Cracked by Roath
// Room: /d/beijing/east/zhongtianlou.c

inherit ROOM;

void create()
{
	set("short", "钟天徘楼");
	set("long", @LONG
这是一座高大的石砌徘楼，再往西走，就是北京城的钟楼
和繁华的鼓楼大街；南面的东直门大街人来人往，熙熙攘攘，
好不热闹。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/beijing/west/zhonglou",
  "north" : __DIR__"andingmen",
  "south" : __DIR__"dongzhidajie2",
  "east" : __DIR__"guozijianjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
