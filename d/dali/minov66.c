//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov66.c

inherit ROOM;

void create()
{
	set("short", "武定镇");
	set("long", @LONG
这里是台夷分支卢鹿族罗蝥部的治府，罗蝥部除了这武定州外还辖元谋、禄
定两镇。此镇不大，正处山中竹林深处，显得格外清幽。卢鹿族人的竹楼四散分
布在竹林中。
LONG);
	set("objects", ([
		__DIR__"npc/tygirl" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov65",
		"north" : __DIR__"minov67",
		"south" : __DIR__"minov70",
		"west" : __DIR__"minov68",
		]));
	set("area", "武定镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
