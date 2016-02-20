//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "伊犁城门");
	set("long", @LONG
伊犁城墙在伊犁河北岸度地而筑，城高一丈四，扼中西交通要道，
地势险要。伊犁将军掌管天山南北和巴尔喀什湖以东以南的军政大权。
城墙上满布着炮台、枪眼，戒备森严。
LONG
	);
	set("exits", ([
                "north" : __DIR__"yili",
                "south" : __DIR__"shanjiao",
        ]));
	set("objects", ([
                __DIR__"npc/bing" : 4,
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
