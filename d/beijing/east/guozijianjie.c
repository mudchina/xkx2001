//Cracked by Roath
// Room: /d/beijing/east/guozijianjie.c

inherit ROOM;

void create()
{
	set("short", "国子监大街");
	set("long", @LONG
这是国子监外的国子监大街，比起京城其它繁华热闹
的大街来略显冷清了些，路上行人大多文质彬彬，不象一
般贩夫走卒之辈。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"guozidamen",
	"west" : __DIR__"zhongtianlou",
	"east" : __DIR__"yonghegong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
