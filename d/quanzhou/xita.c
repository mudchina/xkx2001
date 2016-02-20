//Cracked by Roath
// xita.c 西塔
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西塔");
	set("long", @LONG
西塔又名仁寿塔，它与东塔除局部略有区别外，建筑规则基本相同，恰似
一对挛生姊妹。西塔须弥座束腰部分则雕刻着各种花、鸟、虫、兽和装饰图案，
也都线条清晰，形态逼真，给人一种欣悦、舒畅的美感。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"yuetai",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
