//Cracked by Roath
// cien.c 赐恩岩
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "赐恩岩");
	set("long", @LONG
这里巨石绵绵，相连成片。寺宇成排，有佛殿、功德堂、许氏宗祠等。巨
石群中有两块大岩石昂然伸出，使底下形成一个天然石室，上刻「高山仰止」。
据称是唐中叶泉州的进士与韩愈、陆贽等同登「龙虎榜」的欧阳詹的读书的书
室。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"shanlu4",
		"southdown" : __DIR__"shanlu5",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
