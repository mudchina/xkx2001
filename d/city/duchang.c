//Cracked by Roath
// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声，北边是赌「牌
九」的房间。不知为何，西边的气氛却文雅得多，十分安静，一条走廊通往内堂
，那就是扬州的象棋棋苑。
LONG
	);

//	set("item_desc", ([
//		"paizi" : "二楼的拱猪房正处于测试阶段。\n",
//	]));
	set("exits", ([
//                "west" : __DIR__"qiyuan1",
		"up" : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
//		"north" : "/u/ding/sp9room",
		"north" : __DIR__"sp9room",
	]));

        set("objects", ([
                "/kungfu/class/shenlong/shou" : 1,
        ]));

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么?!\n");

//	if (dir == "west")
//		return notify_fail("赌场暂时关闭!\n");
        return ::valid_leave(me, dir);
}

