//Cracked by Roath
// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96
// Ryu 5/10/97

inherit ROOM;

void create()
{
        set("short", "绿洲");
        set("long", @long
这里是沙漠中的一处绿洲，从此西上就可以到达星宿海。        	
此处看起来起向平和，实际上星宿弟子常常在此坐地分赃，来此
不得不防。  	
long);
        set("exits", ([
            "westup" : __DIR__"shankou",
            "east" : __DIR__"shanjiao",
	]));
        set("objects", ([
                __DIR__"npc/boshou" : 1,
        ]));
        set("resource/grass", 1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 3);
        setup();
        replace_program(ROOM);
}
