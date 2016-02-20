//Cracked by Roath
// Room: /d/mingjiao/longw.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "龙王殿");
	set("long", @LONG
此间是明教龙王殿。此殿虽乃后设，但比鹰狮蝠三殿均为豪华。殿中
桌椅均乃红木所制，上有精细雕刻图案。摆设整齐。殿上红烛交相辉映，
金壁辉煌。殿墙上还画着一条紫龙，翻云吐雾，张牙舞爪，令人敬畏。
LONG
	);
	set("objects",([
		__DIR__"npc/daiqisi" : 1,
	]));

	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"daguangchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
