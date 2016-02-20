//Cracked by Roath
// Room: /d/xixia/hytan.c

inherit ROOM;

void create()
{
	set("short", "黄羊滩");
	set("long", @LONG
这里就是灵州西南著名的黄羊滩，本来是黄河边的一大片水泽盐碱地，黄河
水泛滥后退去形成了一大片低洼水滩，上面水草丰盛，春秋两季吸引了大批塞北
的野生黄羊到这里来饮水嬉戏，休养生息，成为塞上一大景观。
LONG
	);
	set("resource/grass", 1);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nanmen",
  "southwest" : __DIR__"xiaoba",
]));
	set("objects", ([
		__DIR__"npc/lamb" : 2,
	]));
	setup();
	replace_program(ROOM);
}
