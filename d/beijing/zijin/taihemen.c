//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "太和门 ");
	set("long",  @LONG
这是一个巨大的牌楼，红色的墙壁，黑色的匾，上书三个金色大字：
太和门。门前是两队金甲卫士，手持长矛，阳光照在他们身上，金光四射，
就象天神一般。往前看，就是威严肃穆的太和殿。从此往北，即故宫中心
建筑之一的太和殿。往南通午门。
LONG
	);

	set("exits",([
        "north" : __DIR__"guang1",
        "south" : __DIR__"guang2",
		]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
