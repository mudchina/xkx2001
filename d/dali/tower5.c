//Cracked by Roath
// Room: /d/dali/tower5.c

inherit ROOM;

void create()
{
	set("short", "第五层");
	set("long", @LONG
球状，无人像，四角挂有黄铜铸灵鹫。四只灵鹫，口角噙有一枚两头有孔的
铜管，管内有金属簧片，鹫口、鹫颈、鹫腹皆是空心。每当劲风吹来，经鹫嘴内
铜管，在鹫腹内空气回旋荡扬，便发出悦耳的鸣叫。不但平增灵鹫的神密气氛，
亦可想见能工巧匠们的精湛技艺。
LONG);
	set("exits", ([
		"up" : __DIR__"tower6",
		"down" : __DIR__"tower4",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
