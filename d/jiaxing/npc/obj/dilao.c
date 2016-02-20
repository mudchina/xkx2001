//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "地牢");
        set("long", @LONG
这里漆黑一团，唯一的一线光亮是从门上一个尺许见方的孔洞中
射出来的。四壁青油油地发出闪光，原来四周墙壁均是钢铁所铸。
LONG
        );

        set_light(0);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
		"out" : __DIR__"workroom",
	]));
        set("item_desc", ([
                "dianzi" : "一支脏臭的草垫子，伸手摸去，觉得下面是块铁板，\n",
        ]));

	set("objects", ([
		__DIR__"obj/tiechuang" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
    if ( (dir=="out") && present("liaokao",me))
		return notify_fail("你被手铐脚镣锁着动弹不得。\n");
        return ::valid_leave(me, dir);
}

