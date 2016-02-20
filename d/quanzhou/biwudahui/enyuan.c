//Cracked by Roath
// enyuan 恩怨巷
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "恩怨巷");
	set("long", @LONG
走进巷中，就感到一股肃杀之气弥漫四周。巷旁一碑耸立，上书「恩
怨分明」四个大字，仔细一看，乃用指力刻划而成！北面就是闻名天下的
擂台了。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"leitai_gate",
		"south" : __DIR__"citong_e2",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
