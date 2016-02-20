//Cracked by Roath
// /d/shenlong/luanshi.c
// ALN   Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ÂÒÊ¯");
        set("long", @LONG
Õâ¶ùÊÇÂÒÊ¯¶Ñ£¬ËÆºõ²»ÊÇÌìÈ»¶ø³É¡£Ò»Õóº£·ç´µÀ´£¬Äã´òÁËÒ»
¸ö¶ßàÂ£¬²»½ûº¦ÅÂÆðÀ´£¬µ«Ï¸ÏëÒ»ÏÂ²»ÖªÆäËùÒÔÈ»¡£
LONG
        );

        set("exits", ([
              "northeast" : __DIR__"jushi",
 //           "northwest" : __DIR__"shulin3",
              "southup" : __DIR__"houshan",
        ]));
        set("cost", 2);

        setup();
}

void init()
{
        object me = this_player();
        int damage;

        if( interactive(me = this_player()) 
        && !(me->query("sg/spy") || me->query("family/family_name") == "ÉñÁú½Ì")
        &&  random((int)me->query_skill("dodge")) < 80 ) {
                message_vision( HIR "$NµÄÑÛÇ°Í»È»³öÏÖÒ»¸öÎÞµ×µÄÉîÔ¨...$NµôÈëÁËÏÝÚåÖ®ÖÐ¡£\n" NOR, me);
                message_vision( HIR "ÏÝÚåÖÐµÄ¸Ö°åÍ»È»Ã°³öÐí¶à·æÀûµÄ¸ÖÕë£¬ÉîÉîµØúÈëÁË$NµÄÉíÌåÖÐ...\n" NOR, me);

                damage = 100000 / ( 100 + (int)me->query_skill("force"));
                me->receive_wound("qi", damage + random(damage), "±»ÔúËÀÁË");
                me->receive_damage("qi", damage + random(damage), "±»ÔúËÀÁË");

                me->apply_condition("snake_poison", 50 + random(50) +
                        me->query_condition("snake_poison"));
        }
}

