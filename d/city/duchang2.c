//Cracked by Roath
// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
        ≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌
            ≌≌                                ≌≌
            ≌≌　　　    拱　　猪　　房 　     ≌≌
            ≌≌                                ≌≌
            ≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌

　　这里有四条走廊通向不同的拱猪房间。房间里面灯火通明，永远准备
着为拱猪狂们服务。墙上贴着一张发黄的纸，上面写着拱猪门的级别。
LONG
	);

        set("item_desc", ([
                "paper" : 
"　　拱猪门的级别由低到高分为：\n\n"
"新手，学童，童生，书生，秀才，举人，解元，贡士，会元，进士，\n"
"庶吉士，传胪，探花，榜眼，状元，翰林，学士，大学士，首辅，\n"
"领袖，大宗师，掌门人\n"
        ]));

	set("exits", ([
		"east"  : __DIR__"eproom",
		"west"  : __DIR__"wproom",
		"south" : __DIR__"sproom",
		"north" : __DIR__"nproom",
		"down"  : __DIR__"duchang",
//		"up"    : "/u/ssy/card/cardtest",
	]));
        set("objects", ([
//		"/u/xbc/npc/qiao" : 1,
                "/u/ssy/npc/baixiao" : 1,
//	       "/inherit/room/qiao" : 1,
	]));

	set("cost", 0);
	set("no_fight", 1);
	set("pigging", 1);
	setup();
	"/clone/board/pigroom_b"->foo();
}

void init()
{
    add_action("do_pigroom", "room");
    add_action("do_pigroom", "pigroom");
}

int do_pigroom()
{
	object env1, env2, env3, env4;
    object *obj1, *obj2, *obj3, *obj4;
    object me = this_player();
    int i, i1, i2, i3, i4;

	env1 = load_object(__DIR__"eproom.c");
	obj1 = all_inventory(env1);

	env2 = load_object(__DIR__"nproom.c");
	obj2 = all_inventory(env2);

	env3 = load_object(__DIR__"sproom.c");
	obj3 = all_inventory(env3);

	env4 = load_object(__DIR__"wproom.c");
	obj4 = all_inventory(env4);


    for (i = 0; i < sizeof(obj1); i++) 
        if (userp(obj1[i]))
            i1++;

    for (i = 0; i < sizeof(obj2); i++) 
        if (userp(obj2[i]))
            i2++;

    for (i = 0; i < sizeof(obj3); i++) 
        if (userp(obj3[i]))
            i3++;

    for (i = 0; i < sizeof(obj4); i++) 
        if (userp(obj4[i]))
            i4++;

        tell_object(me, "现在各拱猪房里的人数有：\n" + 
        "　　　　北" + "\n" +
        "　　　　" + i2 + "\n" +
        "　西 " + i4 + "　　　" + i1 + " 东\n" + 
        "　　　　" + i3 + "\n" +
        "　　　　南 \n");
    return 1;
}

