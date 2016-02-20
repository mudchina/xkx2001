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
来野兽的啸声使人不觉犹豫了前进的脚步。西面一条大河(river)
大浪涛天。
LONG
        );

        set("objects", ([
	    __DIR__"npc/xiaoyaozi" : 1,
            __DIR__"npc/chang" : 1,
            __DIR__"npc/hua" : 1,
            __DIR__"npc/gaiyiming" : 1,
	]));

        set("exits", ([
                "east" : __DIR__"forest5",
        ]));

	set("item_desc", ([
		"river" : "河流湍急，渡船难过。河流两岸长满参天大树，枝杈相连。\n",
	]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

