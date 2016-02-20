//Cracked by Roath
// Room: /d/xiangyang/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是郭府的大厅，宽敞宏伟，摆设典雅，两座铜鼎分置左右
，极富古风。厅上一面紫檀木雕屏，刻工精细，的是精品。南边一
条长廊走道直通往内堂。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -3 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"neitang",
  "out" : __DIR__"guofu",
]));

	setup();
	replace_program(ROOM);
}
