//Cracked by Roath
// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
        set("short", "白驼山");
        set("long", @LONG
这是传说中神秘的白驼山。远远望去，两座白沙堆积形成的山峰好像
一只骆驼的脊背。一座山门立在你的眼前。山门后一条小路通向一座山腰
上的山庄。这里是「西毒」欧阳锋的秘宅，一般人闯进去非死既伤。
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"shamo4",
            "west" : __DIR__"btshan1",
        ]));
        set("objects", ([ 
            __DIR__"npc/ke" : 1,
            __DIR__"npc/snake" : 3,
         ]) );

        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="west" ) {
        if (objectp(present("snake", environment(me))))
                return notify_fail("蛇阵不过，如何上山?\n");

        if (objectp(present("ouyang ke", environment(me))))
                return notify_fail(
"欧阳克抖开折扇，一伸手挡住了你的去路：叔父正在练功，请改日再来。\n");
        
       
        me->move(__DIR__"btshan1");
        write("欧阳锋弓身伏拳，口内发出「咕咕」的叫声，双目圆睁。\n");
        write("猛然间欧阳锋双腿一蹬，两掌平伸向你打来。\n");
        write("这一掌正中你的前胸，你感觉五脏六腑都像被震碎了一样。\n");
        write("你平飞出了白驼山庄。\n");
        me->move(__DIR__"btshan");
        me->set("qi",10);
        me->unconcious();
        return 1;
   }
   return ::valid_leave(me, dir);
}

