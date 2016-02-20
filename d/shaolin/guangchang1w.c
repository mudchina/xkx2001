//Cracked by Roath
// Room: /d/shaolin/guangchang1w.c
// Date: CSWORD 96/02/28
// Added a back door for shaolin hh
// Apache 11/99
// modified by xiaojian Aug.23,2000: add a side door for tiaoshui job

#include <ansi.h>
inherit ROOM;
void init();
int do_jump(string);
int do_yong(string);

void create(){
        set("short", "广场");
        set("long", @LONG
这里是少林寺前的广场，整个广场由大块的青石铺成，极为平坦。但因年代
久远，都有些破损。丛丛小草从石板的缝隙中长了出来。广场周围都是密密的松
树林，四角上各放了几块石碑，字迹都甚为模糊。边上立了块木牌(mupai)，寺前
三三两两的站着几个僧人。
LONG
        );

        set("exits", ([
                "west" : __DIR__"shulin1",
                "southdown" : __DIR__"shijie11",
                "east" : __DIR__"guangchang1",
        ]));

        set("item_desc",([
                "mupai" :   "少林寺护法松林，违令擅入者杀无赦！\n",
        ]));

        set("outdoors", "shaolin");

        set("objects",([
                CLASS_D("shaolin") + "/qing-wei" : 1,
        ]));
        set("cost", 1);
        setup();

}

void init() {
        add_action("do_jump", "jump");
                add_action("do_yong", "yong");
}

int valid_leave(object me, string dir) {
        if (!wizardp(me) && dir == "west" && me->query_skill("dodge",1) <= 20 
                && (present("qingwei biqiu", environment(me))))

        return notify_fail("清为拦住劝你: 西边是本寺护法松林，向来有进无出，\n"
                    + RANK_D->query_respect(me) + "轻功不佳，最好先看看木牌，不要随便进去！\n");

        return ::valid_leave(me, dir);
}

int do_jump(string arg) {
        object me = this_player();
        string event = NATURE_D->outdoor_room_event();
        
        if( !arg || arg == "" ) return 0;
        if( arg == "tree" ) {
                if (me->query("family/family_name") != "少林派" )
                        return 0;
                
                if (me->query("family/generation") > 37)
                        return 0;

        if (event != "event_night" && event != "event_midnight")
                        return notify_fail("大白天的，这么做不好吧？\n");
                                         
                if (me->query_skill("dodge") < 200)
                        return notify_fail("你“嗖”的一下跳了起来，只摸到了一片松叶。\n");
                        
                if (me->query("jingli") < 500 || me->query("neili") < 100)
                        return notify_fail("你现在心浮气虚，还是歇一会儿吧。\n");

                message("vision", 
                        me->name() + "一式「孤骛落日」，拔地而起，再在松枝上一借力，人影消失在茫茫夜色中。\n",
                        environment(me), ({me}) );
                write("你一式「孤骛落日」，拔地而起，再在松枝上一借力，已翻过了松林。\n");

                me->move("/d/shaolin/beilin2");

                message("vision", "忽然“嚓”的一声轻响，" + me->name() + 
                        "从半空中跳了下来。\n", environment(me), ({me}) );
                write("你再一式「鸿雁双飞」，轻轻地飞落了下来。\n");
                
                me->start_busy(1);
                return 1;
        }

}
   
int do_yong(string arg)
{
    
                object me,obj;
        string event = NATURE_D->outdoor_room_event();
        me= this_player();
                obj = present("shui tong", me);
        if( !arg || arg == "" ) return 0;
                if (arg != "一切世界佛，悉发菩提心")
                        return notify_fail("你在这里乱叫什么？\n");
                if (me->query("family/family_name") != "少林派" )
                        return 0;
                if (event != "event_night" && event != "event_midnight")
                        return notify_fail("白天请走正门！\n");
                if (!me->query("shaolin/job_asked")) 
                        return notify_fail("你没有领任务，不能从这里进去。\n");
                if (!obj)
                        return notify_fail("你的水桶呢？\n");
        message_vision(HIC"$N听到里面传来慈和的声音道“慈悲若此,善哉善哉”。\n"NOR,me);
        message_vision(CYN"一位师兄把侧门打开:“啊,师弟回来晚了,大门不开,请随我走这边”。\n"NOR,me);
                message_vision("说完,他拉着$N的手,从小门转了进去。\n",me);
                message("vision","小门随即关上了。\n",environment(me),({me}) );
                me->move("/d/shaolin/houyuan");
                message("vision", me->name()+"从侧门直接来到厨房的后院。\n",environment(me),({me}) );
                write("你来到厨房的后院。\n");
                me->start_busy(1);
                return 1;
}
