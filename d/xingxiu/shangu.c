//Cracked by Roath
// Room: /d/xingxiu/shangu.c
// Date: June 30, 96   Jay

inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
山谷四周都是陡峭的绝壁，谷内稀疏地长着些矮小的灌木。西
面的地上有几行足迹，东边石壁上一道裂缝通进一个山洞。
LONG
	);

	set("exits", ([
                "northup" : __DIR__"tianroad6",
		"northwest" : __DIR__"gcdoor",
	]));
	set("objects", ([
                "/d/qilian/npc/tuying": 2,
        ]));
	set("outdoors", "xingxiu");
	set("cost", 3);
	set("bing_can", 5);
	setup();
	replace_program(ROOM);
}

