//Cracked by Roath
// Room: /d/beijing/west/shizilukou.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
这是一个极其热闹的十字路口，路上行人熙来攘往，周围有不少
小贩，兜售各种零碎百货。东面可以看到天坛祈年殿的殿顶，西面是
山川坛，南面是永安门，北面是正阳门外大街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"xitianmen",
  	"north" : __DIR__"zhengyangdajie",
	"south" : __DIR__"yonganmen",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
