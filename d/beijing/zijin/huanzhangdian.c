//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "焕章殿");
	set("long",  @LONG
这是训练新兵的地方。地上散落着各种各样的兵器，两个教官在
认真的和士兵对打，从这儿出去的新兵基本功非常的扎实。
LONG
	);

	set("exits", ([
        "east" : __DIR__"guang3",
	]));

	setup();
	replace_program(ROOM);
}
