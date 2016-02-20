//Cracked by Roath
// changle/zoulang1.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
宽敞的走廊人来人往，再向内便是总舵的内宅了。西面是间干杂
活的柴房，向东有个小小的亭子。一些日常守卫的帮众警惕地注视着
每个人。
LONG );

        set("exits", ([
		"south" : __DIR__"cldating",
		"north" : __DIR__"clzoulang2",
		"west" :  __DIR__"clchaifang",
		"east" :  __DIR__"clbajiaoting",
        ]));

        set("cost", 0);

        setup();

        replace_program(ROOM);
}

