//Cracked by Roath
// emroad1.c 小路
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里已经是四川境内了。一条静悄悄的小土路，在这里分成三叉。路旁有
疏疏落落的农舍耕田，但路上行人很少，都匆匆赶路。
LONG
        );
        set("exits", ([
		"south" : __DIR__"shijie2",
		"westup" : __DIR__"chuanxi1",
                "east" : __DIR__"emroad2",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

