//Cracked by Roath
//GU MU FROM SANTA
//chongyangC.C

inherit ROOM;

void create()
{
	set("short", "重阳练功室");
	set("long", @LONG
这是王重阳钻研武学的所在，四面各有一间小石室，石室形状甚
是奇特，前窄後宽，成为梯形，东边半圆，西边却作三角形状，室顶
石板（stone)上刻满了诸般花纹符号，均是以利器刻成，或深或浅，
殊无规则。
LONG
	);
	 set("exits", ([
		"north" : __DIR__"cyn",
		"south" : __DIR__"cys",
		"east"  : __DIR__"cye",
		"west"  : __DIR__"cyw",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
