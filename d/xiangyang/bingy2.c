//Cracked by Roath
// Room: /d/xiangyang/bingying2.c

inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
你正处在兵营中，四周密密麻麻到处都是官兵。为了应付随时而来的蒙古大
军，都在带头武将的指挥下列队加紧操练。南墙下坐着主将，不动声色来回寻视
着四周。几名士兵见到你进来，向你围了过来，形势看来不太妙。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bydamen",
  "south" : __DIR__"lianwuc",
]));

	setup();
	replace_program(ROOM);
}
