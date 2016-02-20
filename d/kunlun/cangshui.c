//Cracked by Roath
// Room: /d/mingjiao/cangshui.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "藏水室");
	set("long", @LONG
此处乃明教洪水旗储藏毒水之地。室内寒气逼人。里面横摆着数百个
装满毒水的大铁桶。此毒水非比一般，乃用天下致寒的碧水寒潭潭水配制
而成，奇毒无比。无论人畜，一但粘上，片刻之间，皮肤溃烂，化成血水。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang",
	]));
	set("objects",([
		__DIR__"obj/gang" : 1,
	]));

	set("no_clean_up", 1);
	set("cost", 1);

	setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}