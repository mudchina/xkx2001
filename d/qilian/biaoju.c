//Cracked by Roath
// Room: /d/qilian/biaoju.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
	set("short", "神鹰镖局");
	set("long", @LONG
这里是神鹰镖局的正厅，几只虎皮太师椅一字排开，正中央坐着总镖头。
墙上挂着几幅毛毯，正中的毛毯上绣着一只巨大的雪山白头鹰，在雪山上翱翔，
气势宏大，让人望而生畏。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"lanzhou",
	]));

	set("objects", ([
		"/clone/npc/xibei" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

