//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov15.c

inherit ROOM;

void create()
{
	set("short", "滇池");
	set("long", @LONG
滇池四周的山脉均属昆仑山系，云岭山脉的东支逶迤南下，总称乌蒙山，有
大小数十个山峰。湖身紧靠西山脚下，山环水抱，天光云影，构成天然的图画。
滇池的“滇”在彝语中即是大坝子，兼司马迁的《史记·西南夷列传》记载，在
古代就是这一地区的最大的部族名称，是名滇池。
LONG);
	set("objects", ([
		__DIR__"npc/youke1.c" : 2,
		]));
	set("exits", ([
		"northup" : __DIR__"senlin",
		"south" : __DIR__"minov14",
		]));
	set("area", "罗伽甸");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
