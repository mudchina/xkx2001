//Cracked by Roath
// liantai.c 十二莲台 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "十二莲台");
	set("long", @LONG
	这里是武当绝顶的十二莲台，台与台之间以曲栏相连，雕刻精美，是远眺
的最佳所在。站立此台四眺，宛如身在千叶宝莲之上，千峰万壑都在脚下。往西可
望到七百里外的华山，东望则汉水如练，襄、樊一带尽收眼底。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"jinding",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

