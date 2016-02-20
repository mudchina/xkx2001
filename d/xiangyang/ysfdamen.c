//Cracked by Roath
// Room: /d/xiangyang/ysfdamen.c

inherit ROOM;

void create()
{
	set("short", "元帅府");
	set("long", @LONG
你面前一座大屋，屋前两面大旗迎风招展。两头大石狮分别镇在大门左右，
张牙舞爪，显得十分威武。门额上写着三字，那自是“元帅府”了。但见官兵在
门外来去巡逻，戒备森严之极。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"nanjie1",
  "enter" : __DIR__"bingyi",
]));

	setup();
	replace_program(ROOM);
}
