//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "敬思殿");
	set("long",  @LONG
这是御林军总教头的寝殿。墙上挂着一把宝剑，一张弓，在墙脚
斜靠者一杆长枪。地上散落着几个蒲团，看来是主人修练内功时用的。
LONG
	);

	set("exits", ([
		"north" : __DIR__"gzxd2",
		"south" : __DIR__"wuyingdian",
	]));

	setup();
	replace_program(ROOM);
}