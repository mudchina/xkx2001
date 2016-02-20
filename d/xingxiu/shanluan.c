//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "山峦");
	set("long", @LONG
冰山下的山峦上，成片的塔松，墨绿茂密，亭亭玉立，宛若巨伞，
遮天蔽日。密林深处，野草如茵，山花绚丽，鸟声啁鸣。巨石穿空的
湖畔，凉亭、绿顶黄墙，赫然而立。一泓清冽的湖水，绿盈盈的如碧
玉一般。不时一只水鸟掠过湖面，掀起白色的浪花，搅碎了倒映的天
光云影、青山塔松。
LONG
	);
	set("exits", ([
                "eastdown" : __DIR__"tianchi",
        ]));
	set("bing_can", 7);
	set("cost", 4);
	set("resource/water",1);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
