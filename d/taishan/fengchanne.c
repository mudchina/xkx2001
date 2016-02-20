//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "玄武坛");
	set("long", @LONG
这里是封禅台东北角的玄武坛。整个玄武坛是个方形的广场，
东南，西北端各镇守着一头巨大的石狮，高达丈余，数人难以合
抱。据传石狮座底各有“皇天”“后土”二字，乃人君替天行道，
执掌天下的大印。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"fengchan",
		"east" : __DIR__"xiayi",
	]));

	set("outdoors", "taishan");
	setup();

	replace_program(ROOM);
}
