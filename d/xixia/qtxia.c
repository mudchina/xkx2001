//Cracked by Roath
// Room: /d/xixia/qtxia.c

inherit ROOM;

void create()
{
	set("short", "青铜峡");
	set("long", @LONG
这里是黄河河西走廊段中最湍急的青铜峡，黄河一路流淌到这里，宽阔的河
面一下子变窄，两岸的峭壁像一对生死恋人紧紧不愿分开，黄河却像不懂事的孩
子从中硬挤而过，结果水流一下子变得咆哮起来，波浪滔天，水声隆隆。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xiaoba",
  "southwest" : __DIR__"mszhou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
