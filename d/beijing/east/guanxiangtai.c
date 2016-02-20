//Cracked by Roath
// Room: /d/beijing/east/guanxiangtai.c

inherit ROOM;

void create()
{
	set("short", "观象台");
	set("long", @LONG
观象台属钦天监所辖，其中藏有不少极其珍贵的天文学仪
器，如浑天仪、地动仪之类。钦天监官员如要制订新历法、观
察天象、预测吉凶莫不要借助观象台中的种种设备。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dongchangan2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
