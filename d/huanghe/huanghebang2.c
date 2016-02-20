//Cracked by Roath
// huanghebang2.c 黄河帮广场
// qfy Sept 7, 96

inherit ROOM;

void create()
{
        set("short", "广场");
        set("long", @LONG
广场占地甚大，部置严谨。往西过去可达黄河帮的「侠义厅」。
周围则是些房舍，供帮众居住。
LONG
        );

        set("objects", ([
	    __DIR__"npc/wu-qinglie" : 1,
	    __DIR__"npc/qian-qingjian" : 1,	
	]));

        set("exits", ([
                "east" : __DIR__"huanghebang1",
		"west" : __DIR__"xiayiting",
        ]));

	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

