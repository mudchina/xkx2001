//Cracked by Roath
// Room: /city/xiaotulu.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条没铺石板的黄土小路，这里来往的人很少，只有几个赶集回来的老
乡从这经过。路旁几个小男孩正在和一只野狗玩耍。东边是座挺新的农家小屋，
好象是建好没多久，看起来小屋的主人还较富裕。东南是座破旧的小庙，西南便
是象南街了。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"minwu2",
		"southwest" : __DIR__"xiangnanjie",
		"southeast" : __DIR__ "xiaomiao",
	]));

        set("objects", ([
		__DIR__"npc/boy" : 2,
		__DIR__"npc/dog" : 1,
        ]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

