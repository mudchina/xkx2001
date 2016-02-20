//Cracked by Roath
// huazang.c 华藏庵
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "华藏庵");
	set("long", @LONG
华藏庵是金顶的主要建筑，规模宏大，中祀普贤菩萨，旁列万佛。
　　华藏庵后边是睹光台，旁边是卧云庵。
LONG
	);
	set("exits", ([
		"south" : __DIR__"duguang1",
		"enter" : __DIR__"hz_front",
		"north" : __DIR__"jinding",
		"northwest" : __DIR__"woyun",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
