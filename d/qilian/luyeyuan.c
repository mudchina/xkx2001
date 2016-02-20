//Cracked by Roath
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	object ob;

        set("short", "鹿野苑");
        set("long", @LONG
一团团雾气，从神秘莫测的路的深处涌出来。小路豁然开朗，你的
眼前出现一块长满吉祥草和缠枝什花的密林，几只鹿跳跃於其中。走进
密林，花叶及膝深。一株双娑罗树间，安有一莲座(lianzuo)，座上有
幡盖、璎珞。座下供着石钵，钵中盛着香花、香木。
LONG
        );

        set("exits", ([
                "east" : __DIR__"wangyou",
        ]));
        set("item_desc", ([
                "lianzuo" : "莲座上有吉祥草铺成座垫。\n",
        ]));
	set("cost", 2);
        set("outdoors","qilian-shan");
        setup();
	ob=new("/d/qilian/obj/lx-jing");
	if (ob)
	ob->move(__DIR__"luyeyuan");
}

void init()
{
        add_action("do_sit", "sit");
	add_action("do_stand", "stand");
}

int do_sit(string arg)
{
        mapping skl;
        object me=this_player();
        string *sname;
        int i,j;

        if( !arg || arg=="" ) return 0;

	if( me->query_temp("sitted"))
		return notify_fail("你已经坐着了！\n");

        skl = me->query_skills();
        sname  = keys(skl);

        if( arg == "lianzuo"){
	message_vision("$N踏上莲座，安住正念，面东而坐。\n", me);
        me->set_temp("sitted", 1);

/*        for(i=0; i<sizeof(skl); i++) {
                if (skl[sname[i]] < 100)
                me->unconcious();
        }
*/
	if ( me->query_skill("lamaism", 1) < 150){
                me->unconcious();
        }
	else if ( present("longxiang jing", me) && me->query("potential") > 0){
                message_vision(HIY"香木不点自燃，$N作明空想念，具正念正知，度化园满，入四禅定而般涅磐。\n"NOR, me);
                me->start_busy(10+random(10));
                me->improve_skill("longxiang-banruo", me->query_int()*7/10
                * me->query("potential"));
		me->set("jing", 0);
                me->set("potential", 0);
                tell_object(me, "你的龙象般若功进步了。\n");
		return 1;
        }
	return 1;
	}
}
int do_stand()
{
	if (this_player()->query_busy())
		return notify_fail("你还不能站起来！\n");

        message_vision("$N站了起来，走下莲座。\n", this_player());
        this_player()->delete_temp("sitted");
	return 1;
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("sitted"))
	return notify_fail("坐着走？\n");
	return ::valid_leave(me, dir);
}
