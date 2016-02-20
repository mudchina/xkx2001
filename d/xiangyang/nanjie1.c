//Cracked by Roath
// Room: /d/xiangyang/nanjie1.c

inherit ROOM;

void create()
{
	set("short", "南街");
	set("long", @LONG
这是襄阳的南街，此处戒备森严，四周有不少卫兵在巡逻。西处可见到一
座大府，却是节度荆襄兵戎所在的元帅府。路上的行人大都匆匆而过，不敢就近
停留。北去不远有一个较大的广场，那是襄阳的中心。
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"nanjie2",
  "north" : __DIR__"guangc",
  "west" : __DIR__"ysfdamen",
]));
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
