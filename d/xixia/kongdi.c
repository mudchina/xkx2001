//Cracked by Roath
// Room: /d/xixia/kongdi.c

inherit ROOM;

void create()
{
	set("short", "林中空地");
	set("long", @LONG
这是山谷中的一大块空地，错落有致的分布着数十幢木屋，炊烟袅袅的飘荡
在上空，几个小孩正在追逐嬉闹，两条大狗没精打采的趴在屋檐下晒太阳，周围
山坡上同样是巨木参天，看上去这里就像一个气氛祥和的小村。靠北的空地上有
座大木屋看上去有点引人注目。西北和东北各有一条山路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"dawu",
  "northwest" : __DIR__"spring",
  "southwest" : __DIR__"tulu",
]));
	set("objects", ([
		"/d/city/npc/wolfdog" : 2,
		"/d/city/npc/boy" : 1,
	]));
	set("cost", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
