//Cracked by Roath
// Room: /d/dali/tower1.c

inherit ROOM;

void create()
{
	set("short", "第一层");
	set("long", @LONG
雕四大天王像，高约四尺，批甲戴胄，手持斧钺，威严庄重。三人足踏鬼奴。
一鬼奴肌肉暴起，右手挽蛇，蛇嘴正触鬼奴下腭；另俩鬼奴戴镣。一天神足下三
人，中间一人正以双手各托天王一足。天王之间遍刻梵文佛经。
LONG);
	set("exits", ([
		"up" : __DIR__"tower2",
		"out" : __DIR__"minov5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
