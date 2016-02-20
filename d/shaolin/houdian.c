//Cracked by Roath
// Room: /d/shaolin/houdian.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "后殿");
	set("long", @LONG
后殿规模不大。两边都是水磨石壁，镂刻着十八罗汉的肖像
及佛谒，正中有一口水井，水面净如明镜，纯若菩提，名曰佛心
乃寺内有名的清水井。东西面各有个门洞，通向两侧长长的走廊。
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang2",
		"east" : __DIR__"zoulang3",
		"southdown" : __DIR__"guangchang4",
		"north" : __DIR__"wuchang",
	]));

	set("valid_startroom",1);
	set("resource/water",1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-ru" : 1,
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}



