//Cracked by Roath
// 大厅 /d/shenlong/dating
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

string look_jia();

void create()
{
	set("short", "大厅");
	set("long", @LONG
你来到了一个大厅之中，这厅硕大无朋，足可容得下千人之众，一群群少
男少女分五色站好，每个队列之前都站着一个头目。大厅四周有很多出口。
四周竖着一排兵器架(jia)。
LONG
	);

	set("exits", ([
                "east" : __DIR__"shibanlu",
		"out" : __DIR__"tingkou",
	]));

        set("cost", 1);

        set("objects", ([
         //        "kungfu/class/shenlong/qinglong" : 1,
                 "/d/shenlong/npc/qing" : 1,
                 "/d/shenlong/npc/bai" : 1,
	]));

        set("item_desc", ([
                "jia": (: look_jia :),
        ]));

	setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        object weapon, me = this_player();
        string type;

        if(!arg) return 0;

        if( me->is_fighting() || me->is_busy() ) return 0;

        if( sscanf(arg, "%s from jia", type) != 1) return 0;

        if( time() < me->query("sg/weapontime") + 300 ) {
                tell_object(me, "你太贪心了，还是等一下再来吧。\n");
                return 1;
        }

        if( type != "armor" ) {
                if( (int)me->query_skill(type, 1) < 1 ) {
                        tell_object(me, "你不会用这种武器。\n");
                        return 1;
                }
        }

        switch(type) {
        case "sword":   if(me->query("gender") == "无性") 
                                weapon = new("/clone/test/xiuhua");
                        else    weapon = new("/clone/weapon/gangjian");
                        break;
        case "blade":   weapon = new("/clone/weapon/gangdao");
                        break;
        case "stick":   weapon = new("/clone/weapon/zhubang");
                        break;
        case "staff":   weapon = new("/clone/weapon/gangzhang");
                        break;
        case "hammer":   weapon = new("/clone/test/falun");
                        break;
        case "whip" :   weapon = new("/clone/weapon/changbian");
                        break;
        case "armor":   weapon = new("/clone/armor/tiejia");
                        break;

        default:        tell_object(me, "找不到" + type + "\n");
                        return 1;
        }

        if( weapon->move(me) ) {
                message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
                me->set("sg/weapontime", time());
        }  else {
                destruct(weapon);
        }
        return 1;
}

string look_jia() 
{
        string msg;

        msg = "这是一个兵器架，十八般武器是应有尽有。\n";
        msg+= "目前存放有剑(sword)，刀(blade)，棒(stick)，杖(staff)，轮(hammer)，\n鞭(whip)。还有一些铁甲(armor)。\n";
        msg+= "请用指令“get 种类 from jia”拿取你称手的兵器或甲胄。\n";
        return msg;
}






