//Cracked by Roath
// Room: /d/beijing/east/chongwendajie.c

inherit ROOM;

void create()
{
	set("short", "崇文门外大街");
	set("long", @LONG
这是繁华热闹的崇文门外大街，大街街面宽阔，车水马龙
，川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百
货小吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"guangqudajie",
	"north" : __DIR__"chongwenmen",
	"east" : __DIR__"wushengbiaoju",
	"southwest" : "/d/beijing/west/xiaohutong1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
