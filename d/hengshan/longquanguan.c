//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "龙泉观");
        set("long", 
"龙泉观为恒山十八景之一，观中有两眼泉水，相隔不到半
丈，泉水一苦一甜，便是所谓的“龙泉甘苦”。唐玄宗李隆基
曾出游到此，御笔亲书“龙泉观”的匾额。\n"
        );
        set("exits", ([
                "westdown"  : __DIR__"zizhiyu",
                "eastup"  : __DIR__"chuyundong",
]));
        set("no_clean_up", 0);
        set("resource/water", 1);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        //replace_program(ROOM);
}
void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{	
        if(arg !="ganquan") 
	        return notify_fail("你要喝什么? \n");
        else{

        int current_water,current_food;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
	current_food = me->query("food");
        max_water = me->query("str")*10 + 100;
        if (current_water<me->max_water_capacity()) {
            me->set("water", current_water+30+random(20));
	    me->set("food", current_food+20+ random(10));
            message("vision", me->name()+"弯下腰，捧了一把甘泉水喝了下去。\n"
            , environment(me), ({me}) );
            write("你捧了一把甘泉喝了下去。泉水一入胸腹，便犹如甘露洒心，爽透清凉。\n");
	 if ((int)me->query("eff_qi") != 
            (int)me->query("max_qi"))
            me->receive_curing("qi", 10+random(10));

        }
        else write("你已经喝了好多泉水，已经再也喝不下了。\n");

        return 1;
	}
}
