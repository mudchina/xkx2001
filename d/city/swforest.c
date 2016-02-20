//Cracked by Roath
// room: /d/city/swforest.c
// Jay 7/4/96

inherit ROOM;

void create()
{
    int i;
        set("short", "树林");
        set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂密的叶间
透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野兽的啸声使人不觉
犹豫了前进的脚步。
LONG
        );

	i = random (4);
	switch (i) {
	case 0:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/city/obj/branch4" : 1,
	    "/d/quanzhou/npc/wuya" : 1,
	]));
        break;
	case 1:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/city/npc/laohu" : 1,
        ]));
        break;
        case 2:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/xingxiu/npc/snake" : 1,
        ]));
        break;
        case 3:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/gaibang/npc/zhangzi" : 1,
        ]));
        break;
	}

        set("exits", ([
                "east" : __DIR__"nanjiao4",
                "north" : __DIR__"xijiao4",
        ]));
//	set("outdoors","city");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

