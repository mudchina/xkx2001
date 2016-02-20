//Cracked by Roath
// Room: /shaolin/jiulou2.c
// YZC 1995/12/04 

inherit ROOM;
inherit F_DEALER;

void create()
{
	set("name", "迎宾楼");
	set("short", "迎宾楼二楼");
	set("long", @LONG
这里楼上的是雅座，文人学士经常在这里吟诗作画，富商土豪也在
这里边吃喝边作交易。这里经常举办百鱼全席，边上也正开着两桌，
伙计们吆喝着来回穿梭，一盆盆大菜搬上桌面，鱼香阵阵飘来，令你也
不禁食指大动，。你站在楼上眺望，可以远远看到南面的汉江。墙上挂
着个牌子(paizi)。
LONG
	);

	set("item_desc", ([
		"paizi" : "本店专办上等百鱼宴。\n",
	]));

	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));

	set("objects",([
		CLASS_D("gaibang") + "/qiu-wanjia" : 1,
//		"/d/shenlong/npc/qing" : 1,
	]));

	set("cost", 2);
	setup();
}
