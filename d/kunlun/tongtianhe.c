//Cracked by Roath
// room: /mingjiao/tongtianhe.c

inherit ROOM;

void create()
{
        set("short", "通天河");
        set("long", @LONG
此处是一条宽阔无比的大河，那绿玉河也从南来汇入。只见河水湍急
地向东奔涌而去，中间有无数漩涡打转，倘若失足落水，端的是十分凶险。
向对岸眺望时，渺渺茫茫地什么也看不清。正是：茫然深似海，一望更无
边。
LONG );

        set("exits", ([
                "westup" : __DIR__"monan",
                "south" : __DIR__"yanrandu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/water", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}