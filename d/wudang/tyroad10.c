//Cracked by Roath
// tyroad10.c 桃园小路
// by Marz 
// xQin 04/01

inherit ROOM;

void create()
{
	set("short", "桃园小路");
	set("long", @LONG
眼前豁然开朗，你轻松地走在桃园边的小路上。两边是桃树林，树上盛
开着粉红的桃花，红云一片，望不到边。不时有蜜蜂「嗡嗡」地飞过，消失
在在花丛中；几只猴子在树上互相追逐着，叽叽喳喳地争抢桃子。南北方向
是通向两个桃园的入口。
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"tyroad11",
		"west" : __DIR__"tyroad9",
		"north" : __DIR__"tygate1",
		"south" : __DIR__"tygate2",
	]));

	set("cost", 1);
	setup();
}
