//Cracked by Roath
// jindian.c 金殿 
// by Fang 8/20/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"金殿"NOR);
	set("long", @LONG
金殿中间供着真武大帝铜像，披发跣足，体态丰满；左右有金童玉女侍立，
虔诚恭敬；水、火二将，威武庄严。殿前供器皆为铜铸。殿宇和殿内铜像、供
桌铆焊一体，构件精确，技巧高超。
LONG
	);
//        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"zijin",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

