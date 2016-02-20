//Cracked by Roath
// Room: /d/xiangyang/anfushifu.c

inherit ROOM;

void create()
{
	set("short", "安抚使府");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头雄伟高大的石狮子镇住了大门
两侧。门额上悬挂着一方横匾，写着“安抚使府”四个大字。门外有不少官兵把
守着，戒备森严。门上挂着两盏灯笼，赫然写着“吕”字。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
        set("coordinates", ([ "x" : 1, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"xiansi",
  "north" : __DIR__"dongjie1",
]));

	setup();
	replace_program(ROOM);
}
