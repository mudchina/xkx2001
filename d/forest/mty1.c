//Cracked by Roath
// Jay 7/11/96
inherit ROOM;


void create()
{
    int i;
        set("short", "崖顶");
        set("long", @LONG
摩天崖崖顶上有一块大青石。青石之上一个青袍老者正在打坐。
东面有一个山洞。摩天崖顶枣林茂密，时值枣子成熟季节，枣树的
绿叶丛中红色的枣子星星点点，煞是可人。
LONG
        );

        set("exits", ([
                "east" : __DIR__"mtcave",
		"south" : __DIR__"mty",
		"up" : __DIR__"zaoshu",
        ]));
	set("objects", ([
                "/clone/npc/xie" : 1
        ]));

	set("cost", 1);
	set("outdoors", "city");
        setup();
        replace_program(ROOM);
}


