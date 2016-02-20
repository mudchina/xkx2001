//Cracked by Roath
// entrance1 for fighting ground

inherit ROOM;
#include <ansi.h>
#include "battlefield.h"

string look_jia();

int valid_leave(object who, string dir);

void create()
{
  set("short", HIG"试剑亭"NOR);
  set("long", @LONG
这里便是进试剑山庄的英雄们选择趁手兵刃的地方了。两边
架子 (jia) 上放满了各种刀剑棍棒，还有一些盔甲什么的。从此
往外就是比武场了。
LONG
  );

  set("no_fight", 1);
  set("invalid_startroom", 1);
  set("exits", ([
		 "enter" : __DIR__"test_room1",
		 ]));
        set("item_desc", ([
                "jia": (: look_jia :),
        ]));

  setup();
}

void init()
{
    add_action("do_get", "get");
    disableCmds();
}

int valid_leave(object who, string dir)
{
    who->set("eff_qi", who->query("max_qi"));
    who->set("qi", who->query("max_qi"));
    who->set("eff_jing", who->query("max_jing"));
    who->set("jing", who->query("max_jing"));
    who->set("jingli", who->query("max_jingli"));
    who->set("neili", who->query("max_neili"));
    who->delete("env/wimpy");
    return ::valid_leave(who, dir);
}

int do_get(string arg)
{
        object weapon, me=this_player();
        string type;
        if(!arg) return 0;
        if(me->is_busy()) return 0;
        if (sscanf(arg, "%s from jia", type) != 1) return 0;
        switch (type) {
        case "zhen":    weapon = new("/clone/weapon/xiuhua");
			break;
        case "sword":   weapon = new("/clone/weapon/gangjian");
                        break;
        case "blade":   weapon = new("/clone/weapon/gangdao");
                        break;
        case "club":    weapon = new("/clone/weapon/teigun");
                        break;
        case "stick":   weapon = new("/clone/weapon/zhubang");
                        break;
        case "shezhang":   weapon = new("/clone/weapon/shezhang");
                        break;
        case "staff":   weapon = new("/clone/weapon/gangzhang");
                        break;
        case "falun":   weapon = new("/clone/weapon/falun");
                        break;
        case "whip" :   weapon = new("/clone/weapon/changbian");
                        break;
        case "armor":   weapon = new("/clone/armor/tiejia");
                        break;
        default:        return notify_fail("找不到"+type+"\n");
        }
 	weapon->set_temp("xueling", 1);
        if(weapon->move(me)) {
                message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
        } else {
                destruct(weapon);
        }
        return 1;
}

string look_jia() 
{
        string msg;
        msg = "这是一个兵器架，十八般武器是应有尽有。\n";
        msg+= "目前存放有绣花针(zhen), 钢剑(sword)，钢刀(blade)，铁棍(club)\n";
	msg+= "竹棒(stick)，钢杖(staff)，蛇杖(shezhang), 法轮(falun)，长鞭(whip)。\n";
	msg+= "还有一些铁甲(armor)。\n";
        msg+= "请用指令“get 种类 from jia”拿取你称手的兵器或甲胄。\n";
        return msg;
}

