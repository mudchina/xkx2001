//Cracked by Roath
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"夏荷居"NOR);
	set("long", @LONG
这是一间地方颇为宽大的厢房，梁上悬了几盏荷花灯，红莲白藕，荷
叶田田，视之凉意顿生。灯上裹以白纱，上有文人墨客的咏莲之作(poem)，
其中倒不乏佳作。
LONG
	);

/*
	set("objects", ([
	]));

*/
	set("item_desc", ([
		"poem" : "<<莲舟唱和集>>\n"
			"\n
临江仙				临江仙（和）
今夜魂飞千里外			回首清波人已去
灯前浅笑盈盈			远山珠泪虚盈
芳樽频进索山盟			此生不解千年盟
呢喃千万语			笙歌寻梦影
梦醒不闻声			岁月载风声

多少相思无写处			何事空题肠断句
缠绵遥寄荧屏			香笺彩袖云屏
人生最苦是多情			多情更苦是痴情
新愁听旧曲			拈花相对望
独坐望天明			亦醉亦澄明

\n"

	]));

	set("exits", ([
		"east" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
 

