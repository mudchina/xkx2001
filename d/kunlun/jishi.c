//Cracked by Roath
// room: /mingjiao/jishi.c

inherit ROOM;

void create()
{
        set("short", "积石山");
        set("long", @LONG
这里道路难辨，崎岖难行。山间乱石堆积，或高或矮，大块有两三人
高，小块也如鸡卵。据山民所告，强风常将石块掀起，砸伤行人，故此不
要停留过久。
LONG );

        set("exits", ([
                "northup" : __DIR__"daqing",
                "southdown" : __DIR__"lingjia",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}