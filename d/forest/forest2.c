//Cracked by Roath
// Jay 7/11/96

inherit ROOM;

void create()
{
    int i;
        set("short", "树林");
        set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从
茂密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传
来野兽的啸声使人不觉犹豫了前进的脚步。
LONG
        );

/*        set("objects", ([
            "/d/city/obj/branch" : 1,
	    "/d/quanzhou/npc/wuya" : 1,
	]));
 */
        set("exits", ([
		"north" : __DIR__"forest4",
                "east" : __DIR__"forest1",
        ]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

