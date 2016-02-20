//Cracked by Roath
// Room: /d/dali/dalicheng1.c

inherit ROOM;

void create()
{
	set("short", "太和街口");
	set("long", @LONG
太和街连贯阳苜咩城南北门，延伸三里，是城内主要街道。街面是由碗口大
的彩色石块铺成，青兰紫绿，煞是好看。城内居民族裔繁杂，习俗各异，饮食穿
着无不异于中原。太学生们的朗朗之声透室可闻。西面是平南王府，东面是定安
府。北面出城门有官道通中原。
LONG);
	set("exits", ([
		"north" : __DIR__"northgate",
		"south" : __DIR__"dalicheng2",
		"west" : __DIR__"wangfu1",
		"east" : __DIR__"dinganfu",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
