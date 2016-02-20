//Cracked by Roath
// emroad3.c 小路
// Xbc: 96/10/02

inherit ROOM;

void create()
{
        set("short", "三不管");
        set("long", @LONG
这里是四川、湖北与陕西的交界，俗称三不管。小土路的两旁有疏疏落落
的农舍耕田，几只牛羊正在吃草。路上行人很少，都匆匆赶路。
LONG
        );
        set("exits", ([
		"east" : __DIR__"emroad4",
                "southwest" : __DIR__"emroad2",
		"southeast" : "/d/wudang/wdroad6",
        ]));

        set("objects", ([
                __DIR__"npc/cow": 1,
	]) );

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

