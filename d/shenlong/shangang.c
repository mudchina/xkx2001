//Cracked by Roath
// 山岗 /d/shenlong/shangang
// ywz 09/18/96

inherit ROOM;

void create()
{
	set("short", "山岗");
	set("long", @LONG
这是一个乱石岗，野草丛生，乱石成堆，显得很荒凉，石缝中有许多小洞，
四周是许多乱石。
LONG
        );
        set("outdoors", "shenlong");
	set("exits", ([
		"northdown" : __DIR__"shulin1",
		"westdown" : __DIR__"tiandi4",
		"southwest" : __DIR__"shanqiu",
        ]));
      set("objects", ([
	    "/d/shenlong/npc/mangshe" : 1,
	]));
	set("cost", 3);

        setup();
        replace_program(ROOM);
}

