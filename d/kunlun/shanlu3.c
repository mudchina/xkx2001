//Cracked by Roath
// room: /mingjiao/shanlu3.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
山间的道路崎岖不平，走来煞是费力。这里仍然是明教的地盘。偶尔
可以看见巡视的明教人众。向西望去，是一片半黄半绿的树林。
LONG );

        set("exits", ([
                "west"        : __DIR__"shulin1",
                "eastdown"    : __DIR__"shanlu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
