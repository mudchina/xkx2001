//Cracked by Roath
// chaoan1.c 山谷
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山谷");
	set("long", @LONG
在壑幽林美，山清气爽的山谷中，座落着一座寺院。门前的对联写着：

　　　　　　　　神灵体正胜佛国，地寂境幽似西天

这是一座石砌庙宇，建筑小巧玲珑。周围苍松翠柏，又增几分静穆。此乃是摩
尼教的所在。摩尼教是波斯人摩尼创立的宗教，又称为「明教」。摩尼教徒主
要食素，被世人传为「食菜事魔」，称之为「魔教」。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"enter" : __DIR__"caoan2",
		"north" : __DIR__"shisun",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 4);
        setup();
	replace_program(ROOM);
}
