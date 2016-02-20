//Cracked by Roath

// kane: 98/3/025

inherit ROOM;

void create()
{
        set("short", "冰火岛");
        set("long", @LONG
这是岛上火山熔岩喷发自然形成的一个石峰，山脚处有一个石洞，看起来
像一个不错的栖身之所，只是空气中似乎有一股异味。
LONG
        );
        set("exits", ([
                "enter" : __DIR__"icefire_cave",
		"southeast" : __DIR__"icefire2",
        ]));

        set("objects", ([
		"/d/island/npc/bear" : 2,
	]) );

	set("outdoors", "island");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

