//Cracked by Roath
// taoci.c 陶瓷铺
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "陶瓷铺");
	set("long", @LONG
这里烧制各式各样的陶瓷制品。柜台上摆着花色各异的碗碟瓶罐，白皙透
明，巧夺天工。动物瓷器，细腻圆润，栩栩如生。由于它的特殊地位，因此生
意和技术从来都是传子不传女。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"xmqiao",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
