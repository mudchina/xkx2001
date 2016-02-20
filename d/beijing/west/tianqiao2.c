//Cracked by Roath
// Room: /d/beijing/west/tianqiao2.c

inherit ROOM;

void create()
{
	set("short", "天桥");
	set("long", @LONG
这里已经是天桥中心地带，周围人潮如同潮水一般从四面八方涌
来，你被人群一挤，不由自主的象前走去。四下里杂耍百艺，无所不
有，你不由得暗暗叹服天子脚下果然气象非凡。南面是一家珠宝店，
北面是一家拍卖行。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"paimaihang",
	"south" : __DIR__"zhubaodian",
	"west" : __DIR__"tianqiao1",
	"east" : __DIR__"zhengyangdajie",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
