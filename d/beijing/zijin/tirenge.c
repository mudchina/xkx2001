//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "体仁阁");
	set("long",  @LONG
 面阔九间,进深三间,院殿式屋顶,是三大殿的陪衬建筑,清康熙时,
 荐举博学鸿儒召试于此.后为宫廷库房.
LONG
	);

	set("exits",  ([
        "westdown" : __DIR__"guang1",
	]));
	
	setup();
	replace_program(ROOM);
}
