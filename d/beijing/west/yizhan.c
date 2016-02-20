//Cracked by Roath
// Room: /d/beijing/west/yizhan.c

inherit ROOM;

void create()
{
	set("short", "驿站");
	set("long", @LONG
这是北京城里的一间寻常驿站，专为朝廷接送官员，传递公文
之用；如果没有公务，偶而也会出租驿马或为过往客商提供食宿。
外面就是广安门大街了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"guangandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
