//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "孔雀殿");
        set("long", @LONG
大轮寺的大殿孔雀殿，殿正中供奉的是黄教的护教法王--不动明王，又叫
常住金刚(statue)。周围尽是黄色围帐(curtain)。两侧立有二十一尊救渡佛
母，满是肃杀之气。
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"frontyard",
        ]));
	set("item_desc", ([
              "statue" : "一尊裸身胖罗汉，腰围虎皮裙，通体白色，右手高举降魔宝剑，左手持绳钩，
象征降服、爱敬、勾召之意。他右腿前竖，左腿后曲于莲花座上。\n",
              "curtain" : "一扇扇葛黄色的围帐，看上去已经非常的陈旧了，上面都是五色彩线所绣的明
王降魔故事。\n",
	]));
	set("objects", ([
                "/d/xueshan/npc/xiangke" : 1,
        ]));
	set("cost", 1);
        setup();
}
void init()
{
        add_action("do_study","study");
}
int do_study(string arg)
{
	object me = this_player();
        int level, check;

	level = (int)me->query_skill("mingwang-jian",1);
        check = level*level*level;

	if( !arg || arg!="curtain" ) return 0;

	if ( (int)me->query_skill("longxiang-banruo", 1) < 20
	|| (int)me->query("combat_exp") < 10000
	|| (int)me->query_skill("lamaism", 1) < 30 ){
		write ("你研读了一会儿围帐上绘的图案，结果发现它的内容对你来说太深奥了。\n");
	return 1;
	}	
	if ( (int)me->query_skill("mingwang-jian", 1) > 120){
		write("你研读了一会儿围帐上绘的图案，结果发现它的内容对你来说太浅了。\n");
	return 1;
	}	
	if ( check > (int)me->query("combat_exp")*10 ){
		write("你研读了一会儿围帐上绘的图案，但实战经验不足，怎麽读也没用。\n");
	return 1;
	} 
	if ( (int)me->query("jing") < 30 ){ 
		write("你的精神不能集中。\n");
	return 1;
	}
	else {
        me->receive_damage("jing", 25);
        me->improve_skill("mingwang-jian", me->query("int"));
	if (me->query_skill("mingwang-jian", 1) > 50)
	me->receive_damage("jing", 10);
        	write("你仔细研读围帐上的图案。\n");
	}
	return 1;
}	
