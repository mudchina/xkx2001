//Cracked by Roath
// Room: /d/dali/senlin1.c

inherit ROOM;

int do_enter(string);

void create()
{
	set("short", "黑森林");
	set("long", @LONG
迎面一大片黑压压的森林，高大的古松参天而立。左首一排九株大松树，看
起来有些特别。
LONG);
	set("exits", ([
		"south" : __DIR__"senlin.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
void init()
{
	add_action("do_enter","enter");
}
int do_enter(string arg)
{
	object me;
	me=this_player();

	if (arg=="第四株")
	{
		tell_object(me, "你绕到第四株大松树背后，拨开长草，发现一个大洞，钻了进去。\n");
		tell_object(me, "你沿着石级忽上忽下走了好几十步，来到了一片大草坪。\n");
		me->move("/d/dali/wjg1.c");
		return 1;
	}
	return 0;
}
