//Cracked by Roath
// Room: /d/mingjiao/shiw.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "狮王殿");
	set("long", @LONG
此间乃明教狮王殿。殿中摆设并不奢侈，但干净利落，令人肃静。两
旁置有兵器架，上摆十八种武器。正墙壁上绘着一只金色雄狮，狮口大张，
像是正在吼叫，甚是气势磅礴。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"daguangchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
