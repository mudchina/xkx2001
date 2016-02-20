//Cracked by Roath
// Room: /d/dali/yuxuguan.c

inherit ROOM;

void create()
{
	set("short", "玉虚观");
	set("long", @LONG
玉虚观内十分清检，正中供着张果老、吕洞宾、何香姑等八仙的塑像，香火
缭绕，供桌上摆着些蟠桃。正中放了几个蒲团。旁边一个小间里摆着桌椅，是玉
虚散人休息和授徒的地方。
LONG);
	set("objects", ([
		"/kungfu/class/dali/daobaifeng.c" : 1,
		]));
	set("exits", ([
		"out" : __DIR__"yuxuguan1.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
