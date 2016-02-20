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
	add_action("do_understand", "understand");
        add_action("do_understand", "lingwu");
}

int do_sit(string arg)
{
        mapping skl;
        object me=this_player();
        string *sname;
        int i,j;

        if( !arg || arg!="lianzuo" ) return 0;

	if( me->query_temp("sitted"))
		return notify_fail("你已经坐在上面了！\n");

	if( query("zuo")){
		write(query("zuo")->name()+"已经坐在上面了！\n");
		tell_object(query("zuo"), "看起来"+me->query("name")+"也想坐上来。\n");
		return 1;
	}
        skl = me->query_skills();
        sname  = keys(skl);

        if( arg == "lianzuo"){
	message_vision("$N踏上莲座，安住正念，面东而坐。\n", me);

	if ( me->query_skill("lamaism", 1) < 150){
                me->unconcious();
		return 1;
        }

                message_vision(HIY"香木不点自燃，$N作明空想念，具正念正知，度化园满，入四禅定而般涅磐。\n"NOR, me);
		me->set_temp("sitted", 1);
        	set("zuo", me);
		return 1;
        }
	return 1;
}
int do_stand()
{
	if (this_player()->query_busy())
		return notify_fail("你还不能站起来！\n");

        message_vision("$N站了起来，走下莲座。\n", this_player());
        this_player()->delete_temp("sitted");
	set("zuo", 0);
	return 1;
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("sitted"))
	return notify_fail("坐着走？\n");
	return ::valid_leave(me, dir);
}
int do_understand(string arg)
{
        object me;
        string skillname;
        int skill_special, skill_basic;

        me = this_player();

	if (!me->query_temp("sitted")) return 0;

	if( !arg )
                return notify_fail("你要研究何种基本武技？");

        if( arg == "force" )
                return notify_fail("你不能自行修炼基本内功！\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

        if( !stringp(skillname = me->query_skill_mapped(arg)) )
                return notify_fail("你必须有特殊武功方能与基本武技参照领悟！\n");

	skill_basic = me->query_skill(arg, 1);
        skill_special = me->query_skill(skillname, 1);

        if( skill_special < 1 )
                return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
        if( skill_basic > skill_special )
                return notify_fail("你" + to_chinese(skillname) + "功力不够，无法继续领悟" + to_chinese(arg) + "！\n");
        if( skill_basic < 1 )
                return notify_fail("你好像还没有学过这项基本技能吧？ 最好先去请教别人。\n");

        if ( me->query("jing") < 100 )
                return notify_fail("你现在精神不佳，无法定下心来思考！\n");

        if( (int)me->query("potential") <= 1 )
                return notify_fail("你的潜能不足，无法领悟基本武功！\n");

        me->receive_damage("jing", random(skill_basic));
        if( me->query("potential") < 0) me->set("potential", 0);

        if(random(20) == 0) {
	me->add("potential", -2);
                me->improve_skill(arg, skill_special + random(skill_special*2));
		write( "只觉脑中豁然开朗，你对" + to_chinese(arg) + "的领悟又进了一层！\n" );
	}
        else if(random(10) == 0) {
                me->add("potential", -1);
                me->improve_skill(arg, skill_special/2 + random(skill_special/1));
                write( "你冥思苦想，对" + to_chinese(arg) + "渐渐加深一层体会！\n" );
        }
        else if(random(5) == 0) {
                me->add("potential", 0);
                me->improve_skill(arg, skill_special/4 + random(skill_special/2));
		write( "你拿手比划着，似乎对" + to_chinese(arg) + "中的几个招数有所体会。\n" );
        }
        else if(random(2) == 0) {
                me->improve_skill(arg, skill_special/8 + random(skill_special/4));
		write( "你坐立不安，潜心苦思" + to_chinese(arg) + "上的难解之处。\n" );
        }
        else if(random(5) == 0) {
		write( "你心中说不出的烦燥，对" + to_chinese(arg) + "始终不得一解。\n" );
	}
        else if(random(10) == 0) {
                me->improve_skill(arg, - (skill_special/10 + random(skill_special/5)));
                write( "你只觉得体内真气乱窜，" + to_chinese(arg) + "中的招式象走马灯一般在面前显现！\n" );
        }
        else if(random(20) == 0) {
	me->improve_skill(arg, - (skill_special/6 + random(skill_special/3)));
		write( "你的大脑中一片空白。对" + to_chinese(arg) + "是越想越糊涂。\n" );
        }
        else {
		write( "你坐立不安，潜心苦思" + to_chinese(arg) + "上的难解之处。\n" );
        }

        return 1;

}
	
