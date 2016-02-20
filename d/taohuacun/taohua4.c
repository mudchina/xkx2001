// Room: /d/taohuacun/taohua4.c

inherit ROOM;

void create()
{
	set("short", "桃花村");
	set("long", @LONG
进了桃花谷便是桃花村。世外的感受，让你陶醉这山野的风、
山间的春泥味、山村的直朴、村民的宽容、山里的桃花、桃花溪的
少女，让你不会再去想尘世的名利、江湖的血腥、人心的险恶。你
尽可忘了一切，来凝望桃花村碧蓝的瓦、彤红的墙。
LONG );
	set("outdoors", "city");
//	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/cunzhang" : 1,
	]));
	set("exits", ([
		"southdown" : __DIR__"taohua3",
		"north"     : __DIR__"taohua5",
	]));
	setup();
	replace_program(ROOM);
}
