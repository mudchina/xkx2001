//Cracked by Roath
// Room: /d/mingjiao/tiehanshan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "铁汉山");
	set("long", @LONG
这是光明顶西侧的一个小山峰，此处山势低平，但因地处高位，冻土
广布，草木稀疏，人迹罕至。北边一条羊肠小路通往山下，向南隐约可见
乱石嶙峋。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"shanlu20",
  "southeast" : __DIR__"shanlu23",
]));
//	set("objects",([
//		__DIR__"npc/zhuyuanzhang" : 1,
//	]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
