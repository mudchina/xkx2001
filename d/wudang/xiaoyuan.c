//Cracked by Roath
// xiaoyuan.c 后山小院
// by Xiang
// Modified by xQin 11/00

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "后山小院");
	set("long", @LONG
这是后山的一座小院，布置简简单单，除了一床、一桌、一椅、一蒲团
，再也没有别的什物。比较引人注目的是墙上挂着一把剑。这里就是武当开
山祖师张三丰的练功所在。
LONG
	);

	set("exits", ([
		"north" : __DIR__"hs_xiaolu",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhang" : 1 ]));
	create_door("north", "竹门", "south", DOOR_CLOSED);
	set("cost", 1);
	setup();
}
void init()
{
        add_action("do_kill","kill");
}
int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( !ob1=present("zhang sanfeng", environment(me)) ) return 0;
	if ( ob1 == ob ) return 0;
        if ( ob->query("family/family_name") == "武当派" ) {
                message_vision("$N一声冷笑：大胆狂徒！你也太小看老头子我了吧！\n ", ob1);
                ob1->kill_ob(me);
	}
	return 0;
}
