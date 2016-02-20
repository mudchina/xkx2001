//Cracked by Roath
// Room: /d/beijing/zijincheng/jingyunmen.c

inherit ROOM;

void create()
{
	set("short", "景运门");
	set("long", @LONG
为五开间单檐歇山顶.与西端的隆宗门对峙而立.是进入内廷的
禁门.清朝规定,除值班大臣或皇地召见的人员外,即使王公大臣也不
许私自出入,只准在景运门,隆宗门外的台阶下二十步外侍立候旨.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaohuayuan",
  "east" : __DIR__"guang4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
