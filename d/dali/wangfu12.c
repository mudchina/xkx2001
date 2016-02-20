//Cracked by Roath
// Room: /d/dali/wangfu12.c

inherit ROOM;

void create()
{
	set("short", "睡房");
	set("long", @LONG
进了房屋，雪洞一般，一色的玩器全无。案上只有一个土定瓶，瓶中供著数
枝菊，并两部书，茶奁、茶器而已；床上只吊著青纱帐幔，衾褥也十分青素。上
面左右两张榻，榻上都铺著锦茵蓉簟，每一榻前两张雕漆几，也有海棠式的，也
有梅花式的，也有荷叶式的，也有葵花式的，也有方的，也有圆的；其式不一。
一个上头放著一分炉瓶，一个攒盒。
LONG);
	set("exits", ([
		"south" : __DIR__"wangfu9",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
