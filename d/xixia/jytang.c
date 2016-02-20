//Cracked by Roath
// Room: /d/xixia/jytang.c

inherit ROOM;

void create()
{
	set("short", "接引堂");
	set("long", @LONG
堂正中檀木香案，案上燃着几炷香，整间屋檀香袅袅。要加入一品
堂的人在经过堂主测试并通过后就在此堂宣誓，从此成为一品堂正式一
员，终生不得叛堂。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dayuan",
]));
	set("objects", ([
		__DIR__"npc/ypshi" : 3,
		__DIR__"npc/yun" : 1,
	]));
	setup();
	replace_program(ROOM);
}
