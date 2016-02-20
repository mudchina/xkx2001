//Cracked by Roath
// 树林 /d/shenlong/shulin1
// ywz 10/10/96

inherit ROOM;

void create()
{
    int i;
        set("short", "树林");
        set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂密的叶
间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来蛇虫爬行的声音
使人不觉犹豫了前进的脚步。
LONG
        );
	i = random (3);
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
	    "/d/shenlong/npc/snake" : 1,
        ]));
        break;
        }

	set("exits", ([
		"north" : __DIR__"shulin2",
		"west" : __DIR__"tiandi2",
		"southup" : __DIR__"shangang",
        ]));
	set("cost", 1);

        setup();
        replace_program(ROOM);
}

