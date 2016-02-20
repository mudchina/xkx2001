//Cracked by Roath
// Room: /d/dali/shilin3.c

inherit ROOM;

void create()
{
	set("short", "和摩赛石林");
	set("long", @LONG
旧名石门峰或石门峭，石质黝黑古朴，气势磅礴，有如大海怒涛冲天而起，
境巧细致的东西较少，当你身临其境，踏石磴，入石门，拨野草，探幽林，但觉
山禽鸣岗，危石森森，其间原野开阔，山风阵阵，花香悠悠，一股强烈的山野味
迎面而来，不加修饰的粗犷的自然美，令人耳目一新。
LONG);
	set("objects", ([
		__DIR__"npc/tufei" : 1+random(3),
		]));
	set("exits", ([
		"southwest" : __DIR__"shilin5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
