//Cracked by Roath
// Room: /d/mingjiao/yingw.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "鹰王殿");
	set("long", @LONG
此间是明教鹰王殿堂。地面的青瓷砖上铺着一席红毯，殿内桌椅错落
摆放，很是考究。两旁置有兵器架，上摆十八种武器。对门墙壁上绘着一
只雄鹰，双眉坚挺，雄展双翅，似在空中翱翔，显得威风凛凛。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"daguangchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
