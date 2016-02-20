//Cracked by Roath
// kane: 98/3/025
// modified by aln 4 / 98

inherit HARBOR;

void create()
{
        set("short", "冰火岛");
        set("long", @LONG
这是北极附近的一个大岛屿，周围一片青绿草地，岛屿西部都是尖石嶙峋
的山峰，奇形怪样，莫可名状。岛东却是一片望不到尽头的平野，岛上气候便
和长白山、黑龙江一带相似。
LONG
        );
        set("exits", ([
		"east" : __DIR__"icefire_land",
                "west" : __DIR__"icefire_hill",
		"north" : __DIR__"icefire2",
        ]));

/*
        set("objects", ([
                __DIR__"npc/cow": 1,
		__DIR__"npc/xiexun" : 1,
	]) );
*/
	set("outdoors", "island");

        set("island", "冰火岛");
        set("shape", "似乎有一条烟柱！");
        set("navigate/locx", 100);
        set("navigate/locy", 600);

	set("cost", 1);
        setup();
}

