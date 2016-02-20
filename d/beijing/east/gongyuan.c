//Cracked by Roath
// Room: /d/beijing/east/gongyuan.c

inherit ROOM;

void create()
{
	set("short", "贡院");
	set("long", @LONG
京城贡院是全国会试及顺天府乡试的考场，里面有几十排既
矮又窄的房子，共九千多间，便是考棚，又名“号舍”。当时谚
曰：“苦苦苦苦苦，明远楼上鼓”，“一二三四五，明远楼上鼓，
姊在家中乐，弟在场中苦。”
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfudajie3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
