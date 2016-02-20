//Cracked by Roath
// mantian may/2001
inherit ROOM;

void create()
{
	set("short","空房间");
	set("long","自首吧...\n");
	set("exits", ([
		"east" :   __DIR__"noteroom" ]));

	set("valid_startroom",1);
	set("no_fight", 1);
	set("cost", 0);
	setup();
	"/clone/board/emptyroom_b"->foo();
}

void reset()//make this room no refresh
{
	::reset();
	set("no_clean_up", 1);
}
void init()
{
	object ob = this_player();
	add_action("do_practice", "practice");
	add_action("do_practice", "lian");
	add_action("do_practice", "dazuo");
	add_action("do_practice", "exercise");
	add_action("do_practice", "tuna");
	add_action("do_practice", "du");
	add_action("do_practice", "study");
	add_action("do_practice", "sleep");
	add_action("do_practice", "respirate");
	add_action("do_practice", "xuelian");
	add_action("do_practice", "lianneili");
	add_action("do_practice", "lianqi");
	add_action("do_practice", "quit");

	if (!wizardp(ob)) {
		ob->set("startroom", "/d/death/blkbot");
	}
}

int do_practice()
{
	write("歇会儿吧．．\n");
	return 1;
}
int valid_leave(object me, string dir)
{
        if( dir=="east" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}
