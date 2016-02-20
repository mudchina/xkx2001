//Cracked by Roath
// Room: /d/mingjiao/tianmoling.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "天摩岭");
	set("long", @LONG
这里又是一座雄伟的高山。西来的强风终年不断，所以此山西侧甚是
贫瘠，乱石嶙峋中间只有稀稀落落的矮灌木和杂草。东侧倒是郁郁葱葱，
形成了鲜明的对比。据说此地毒虫甚多，不可停留太久。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"jxiaochang",
  "westup" : __DIR__"shangang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
