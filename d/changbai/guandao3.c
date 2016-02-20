//Cracked by Roath
// Room: /guandao3.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这里是通往关外的官道，几米宽的大道，全部由黄土铺成，可并行三四
辆马车而不显拥挤。这里是进出关口的必经之路，路上三俩成群的行人都是
往来贩运皮货，药材的生意人。偶尔有身着官兵骑马飞驰而过。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"guandao2",
		"northeast" : __DIR__"ningyuan",
	]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

