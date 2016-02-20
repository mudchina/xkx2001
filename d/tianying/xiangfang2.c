//Cracked by Roath
// room: xiangfang2.c

inherit ROOM;

void create()
{
        set("short", "女厢房");
        set("long", @LONG
这里是天鹰教女弟子睡觉的地方，一进门就闻到一阵悠悠的香气。
墙壁上挂着一幅工笔仕女图，西首一张几上供着一盆兰花。
LONG );

        set("exits", ([
                "north" : __DIR__"yuanzi",
        ]));

	set("sleep_room", 1);
	set("no_fight",1);
	set("no_steal",1);
        
	setup();
        replace_program(ROOM);
}
