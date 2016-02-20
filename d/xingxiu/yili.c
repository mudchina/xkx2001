//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "伊犁");
	set("long", @LONG
伊犁，又名惠远，西通波斯，南到天竺，东与阳关、玉门相连，
扼中西交通的要冲，是丝绸之路上重要的旅站之一。东来的骆驼商队
和他国使者，在翻过帕米尔高原之後，要在这儿修息和分发货物。西
去的商旅，在饱尝了玉门关外风沙之苦後，除了到这儿修整以外，还
要做好翻越帕米尔高原古道上无数山口的准备。
LONG
	);
	set("exits", ([
                "north" : __DIR__"beijiang",
                "south" : __DIR__"nanmen",
		"west" : __DIR__"majiu",
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
