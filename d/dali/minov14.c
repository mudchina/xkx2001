//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov14.c

inherit ROOM;

void create()
{
	set("short", "沿池堤岸");
	set("long", @LONG
滇池风景怡人，沿堤岸漫步，遵堤行湖中，堤南北皆碧水。盖其碧波即草海
之余，南连于滇池，北抵黄土坡，西濒与赤鼻山之簏。东行湖中，遥顾四周山色，
掩映重波间，青蒲偃水，高柳潆堤，天然绝胜。
LONG);
	set("exits", ([
		"westdown" : __DIR__"minov13",
		"north" : __DIR__"minov15",
		"east" : __DIR__"minov16",
		]));
	set("area", "罗伽甸");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
