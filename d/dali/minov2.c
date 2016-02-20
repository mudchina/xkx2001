//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov2.c

inherit ROOM;

void create()
{
	set("short", "山区小径");
	set("long", @LONG
这是清源山区的碎石小径，曲折蜿蜒，两旁林木茂盛，遮天蔽日。满径落叶，
柔软稀松。虫鸟啾啾。凉风习习。
LONG);
	set("exits", ([
		"westdown" : __DIR__"minov1",
		"east" : __DIR__"minov4",
		]));
	set("area", "大叠水瀑布");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
