//Cracked by Roath
// yanting.c
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "宴厅");
        set("long", @LONG
这里是晋阳大侠萧半和家的宴厅。厅内高朋满座，白道上的侠士、黑道
上的豪客、前辈名宿、少年新进……还有许多和萧半和本不认识、却是慕名
来致景仰之意的生客。
LONG
        );

        set("objects", ([
	    __DIR__"obj/yaohua" : 1,
	    __DIR__"obj/tipang" : 1,
	    __DIR__"obj/liji" : 1,
	    "/d/shaolin/obj/mala-doufu" : 1,
	    "/d/shaolin/obj/mizhi-tianou" : 1,
	    "/d/shaolin/obj/furong-huagu" : 1,
	]));

        set("exits", ([
                "east" : __DIR__"dating",
        ]));

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

