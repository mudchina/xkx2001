//Cracked by Roath
// Room: /d/beijing/east/qianju.c

inherit ROOM;

void create()
{
	set("short", "宝源钱局");
	set("long", @LONG
这是京城最大的一家钱庄，已有几百年的历史，是京城一家
名符其实的老字号钱局子。在全国各地都有分店。它发行的银票
信誉非常好，通行全国。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
