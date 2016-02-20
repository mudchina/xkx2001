//Cracked by Roath
// lyqiao.c 洛阳桥
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洛阳桥");
	set("long", @LONG
这是洛阳江上的一座誉满天下的粱式石桥。桥长身宽，具桥墩四十六座。
桥上两旁翼以扶栏，栏杆石挂上头，雕镂精致雄俊的石狮；更兼七亭九塔，点
缀其间，武士石像，分立两端。桥之首尾，沿路植松七百株。松翠桥白，水碧
山青，胜状令人惊叹。相传它是泉州知府蔡襄命一吏名夏得海冒死下海送信，
得海神相助而建。它是粤闽北上的陆路交通要道，大部分南来北往的货物，都
由此经过。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"lingmu",
		"east" : __DIR__"tudi",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
