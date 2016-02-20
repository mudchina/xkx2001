//Cracked by Roath
// Room: /d/xixia/mszhou.c

inherit ROOM;

void create()
{
	set("short", "鸣沙洲");
	set("long", @LONG
鸣沙洲就在青铜峡的上游，附近就是连天的沙丘，这里正好处在风口，强劲
的西北风吹的黄沙漫天横飞、嗡嗡作响，鸣沙洲由此得名，一走到这里你就觉得
透体冰凉，飞沙打在你脸上生疼生疼，让你睁不开眼睛。
LONG
	);
	set("cost", 4);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qtxia",
  "southwest" : __DIR__"xhbao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
