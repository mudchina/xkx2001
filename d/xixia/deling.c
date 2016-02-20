//Cracked by Roath
// Room: /d/xixia/deling.c

inherit ROOM;

void create()
{
	set("short", "德陵");
	set("long", @LONG
这就是李元昊的父亲赵德明的陵墓。宽十米高五米，为整个王陵中
最高大也是最完整的建筑。陵前左右各有两个石人武士护卫，陵前有
汉白玉栏杆围成的平台，上面石桌石凳一应俱全。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gongling",
  "south" : __DIR__"chiling",
]));
	set("objects", ([
		__DIR__"npc/lingshi" : 3,
	]));
	set("cost", 2);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
