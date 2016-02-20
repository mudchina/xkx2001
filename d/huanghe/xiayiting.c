//Cracked by Roath
// xiayiting.c 黄河帮「侠义厅」
// qfy Sept 7, 96

inherit ROOM;

void create()
{
        set("short", "侠义厅");
        set("long", @LONG
这是黄河帮议事的大厅，厅上挂着「侠义厅」三字匾额。厅里靠
北朝南放着一张虎皮交椅，两边摆设着几副红木桌椅，非常有气派。
墙上附庸风雅地挂了几幅丹青书法。
LONG
        );

        set("objects", ([
	    __DIR__"npc/sha-tongtian" : 1,
	    __DIR__"npc/peng-lianhu" : 1,
	    __DIR__"npc/liang-ziweng" : 1,
	]));

        set("exits", ([
                "east" : __DIR__"huanghebang2",
        ]));

	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

