//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
树丛之后是一块光秃秃的石壁，四周无花无树，与其他地方形成强烈反差。石壁
上有一个岩洞，岩洞里黑黝黝的，看不清楚到底有什么，但似乎有人影晃动。
LONG
	);

         set("exits", ([
                "south" : __DIR__"shucong",
        ]));
        set("objects", ([
                __DIR__"npc/zhou" : 1,
        ]));

	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
