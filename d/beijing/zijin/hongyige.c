//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "弘义阁");
	set("long",  @LONG
这里是宫廷库房，面阔九间，进深三间，院殿式屋顶，是三大殿
的陪衬建筑。
LONG
	);

	set("exits",  ([
        "southeast" : __DIR__"youyimen",
	]));
	
	setup();
	replace_program(ROOM);
}
