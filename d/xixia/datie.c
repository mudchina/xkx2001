//Cracked by Roath
// Room: /d/xixia/datie.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
这是一家颇具规模的打铁铺，中心摆着三个火炉，炉火把四周照
得一明一暗，你一走进去就热的满面通红。北边墙角堆满了未完工的
生铁粗胚，南边架子上整整齐齐的排列着锄头 钉耙 菜刀等农具和铁
锤、铁棍、匕首、短剑 钢刀 盔甲等兵器。六七位光着膀子穿着皮裙
的铁匠满头大汗挥舞着铁锤，专心致志地在打铁。三五个年纪很轻的
学徒费力的拉着老大的风箱，"叮叮当当"的打铁声和 "噗兹噗兹"的
拉风箱声传出老远。这里的老板听说姓梁，哪里人氏却没人清楚。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nandajie",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
