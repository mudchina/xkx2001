//Cracked by Roath
// Room: muqiao.c
 
inherit ROOM;

void create()
{
	set("short", "木桥");
	set("long", @LONG
这是一座年久失修的破木桥，由几根树干捆扎而成。下面的河水早以结
成坚冰。这里本是赫图阿拉城的护城河，现已废弃不用了。河岸北面是用黄
土堆成的城墙，很多处都已坍塌。由此向北就是赫图阿拉城了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"lyddao5",
		"north" : __DIR__"nancheng",
	]));

        set("objects", ([
                __DIR__"npc/yu" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}

