//Cracked by Roath
// room: /d/city/seforest1.c
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
            "/d/city/obj/branch3" : 1,
	    "/d/quanzhou/npc/wuya" : 1,
	]));
        break;
	case 1:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/wudang/npc/yetu" : 1,
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
                "southeast" : "/d/forest/clforest1",
                "west" : __DIR__"seforest",
        ]));
//	set("outdoors","city");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

