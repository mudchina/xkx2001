//Cracked by Roath
//GU MU FROM SANTA
//fenglin1.C

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
眼前的景象令你大吃一斤，但见铺天盖地都是蜜蜂，个头比
寻常蜜蜂足足大出一倍，而且晶莹透明，宛偌玉石。更令你惊讶
的是，这些玉蜂在举止进退之间，似乎颇有章法。看来主人定是
一位高手。

LONG
	);

	set("exits", ([
		"south" : __DIR__"fenglin2",
		"north" : __DIR__"shulin2",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}





