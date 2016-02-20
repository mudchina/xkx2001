//Cracked by Roath
// Room: /d/xiangyang/xiansi.c

inherit ROOM;

void create()
{
	set("short", "宪司堂");
	set("long", @LONG
这即是提刑案察，掌管一路司法事项，督治奸盗，申理冤狱的宪司。公
堂上一人正坐着专著批阅文稿，两旁衙司端持刑杖罗立，静候知府审事。东进
似乎令有厅堂，然而并非常人所能进去的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ysting",
  "out" : __DIR__"anfushi",
]));
        set("objects", ([
               __DIR__"npc/wenhuan" : 1, 
        ]));
	setup();
	replace_program(ROOM);
}
