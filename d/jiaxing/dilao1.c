//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "地牢");
        set("long", @LONG
这里漆黑一团，唯一的一线光亮是从门上一个尺许见方的孔洞中
射出来的。四壁青油油地发出闪光，原来四周墙壁均是钢铁所铸。
LONG
        );

        set("exits", ([
		"out" : __DIR__"didao3",
	]));

	set("objects", ([
		__DIR__"obj/tiechuang1" : 1,
		__DIR__"npc/ren1" : 1,
	]));
        set("no_clean_up", 0);

	set("cost", 2);
	setup();
        replace_program(ROOM);

}


