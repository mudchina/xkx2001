//Cracked by Roath
// baoguo1.c 保国寺大雄殿
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "大雄殿");
        set("long", @LONG
这里是报国寺大雄殿。报国寺是峨嵋山最大寺院之一。大雄殿内供着金光
灿灿的佛像，气宇轩昂。
LONG
        );
        set("exits", ([
                "out" : __DIR__"baoguo",
		"west": __DIR__"baoguo3",
		"north" : __DIR__"baoguo2",
        ]));

        set("objects", ([
                __DIR__"npc/xiang-ke.c": 2,
        ]));

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("family/family_name") != "峨嵋派" && dir == "west" ) 
		return notify_fail("保国寺禅房只接待峨嵋弟子，你要是诚心礼佛，在此多进几注香吧。\n");

	if ( me->query("gender") == "女性" && dir == "west" )
		return notify_fail("这位" + RANK_D->query_respect(me) +
				"，西面乃是男弟子休息的禅房，你一女子不太方便吧？！\n");

	return ::valid_leave(me, dir);
}
