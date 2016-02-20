//Cracked by Roath
// Room: /city/nandajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "南集市");
	set("long", @LONG
南大街乃是城里的繁华地段，一到晚上，一片灯红酒绿，非常热闹。笑声、
歌声、琴声、箫声，汇成一片送入了你的耳朵，你不禁心猿意马，很想就此停步
享受一番。北边是一个热闹的广场。东边是一家店铺，墙上写着一个大大的“当”
字，仔细倾听，可以隐约地听到讨价还价的声音。西边则是一片喧嚣，夹杂着“
一五一十”的数钱声，原来那是方圆千里之内最大的一家赌场。南面有一家豪华
的阁楼，乃是扬州新建的聚金阁。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		"west" : __DIR__"duchang",
		"north" : __DIR__"guangchang",
	]));
        set("objects", ([
                __DIR__"npc/xunbu" : 1,
        ]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

