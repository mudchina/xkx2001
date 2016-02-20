//Cracked by Roath
// Room: /d/mingjiao/dashidian.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "大食殿");
	set("long", @LONG
圣火总坛，弟子众多，故食饮之处宽大，可容千人共餐，因名为大食
殿。明教历代相传，不茹荤酒，后因为驱除鞑子，废除了这条教规。因此
大殿中常常可闻喝酒猜拳之声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qiankun",

]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
