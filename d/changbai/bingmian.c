//Cracked by Roath
// Room: bingmian.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "冰面");
	set("long", @LONG
这里是松花江的江面，现已冻成了几尺厚的坚冰。行人或马匹，车辆均
可横逾江面而绝无危险。冰面上留有厚厚的积雪，与两岸连成一片，只有中
间经常行走之出，露出一条青色的冰路。
LONG	);
	set("exits", ([ 
              "west" : __DIR__"chuanc",
              "east" : __DIR__"damk",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 6);

	setup();
}

void init()
{
        object me = this_player();
        object weapon, *inv;
        int power;

        power = (int)me->query("dex") * (int)me->query_skill("dodge", 1);
        if( weapon = me->query_temp("weapon") ) power *= 2;

        if( random(power) < 300 ) {
                if( weapon ) {
                        weapon->unequip();
                        weapon->move(environment(me));
                        if( weapon->query("value") < 2000 ) {
                                weapon->set("name", "断掉的" + weapon->name());
                                weapon->set("value", 0);
                                weapon->set("weapon_prop", 0);
                        }
                        
                        message_vision(HIR"$N手中的" + weapon->name() + "脱手而出。\n"NOR, me);
                }
/*
                inv = all_inventory(me);
                for(int i = 0; i < sizeof(inv); i++ )
                        if( !inv[i]->query("armor_prop") )
                                inv[i]->move(this_object());
*/
                message_vision(HIR"\n$N只觉得脚下一滑，全身腾空而起，结结实实的摔在了冰面上！\n"NOR, me);

                me->receive_damage("qi", 50);
                me->receive_wound("qi", 3 + random(10));
        }
}          
