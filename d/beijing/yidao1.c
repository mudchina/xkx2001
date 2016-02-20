//Cracked by Roath
// wdroad1.c
// by Ywz yidao1.c

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。西南通向汝州城。
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
		"southwest" : "/d/shaolin/ruzhou",
		"northeast" : __DIR__"yidao2",
        ]));
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
