//Cracked by Roath
// Room: /city/dongdajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这里是东大街的尽头，向东便可到扬州城的东大门了。远处传来官兵的吆喝
声，不言而知官兵正在那里盘问来来往往的行人。北边是一家钱庄，可以听到叮
叮当当的金银声音。南边是座月老亭，每天都有不少人进出。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongmen",
		"west" : __DIR__"dongdajie2",
		"north" : __DIR__"qianzhuang",
		"south" : __DIR__"yuelao",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

