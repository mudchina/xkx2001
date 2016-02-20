//Cracked by Roath
// /d/xingxiu/nanjiang.c
// Jay 3/17/96
// Modified by xQin 7/00

inherit ROOM;

void create()
{
        set("short", "南疆沙漠");
        set("long", @LONG
这就是浩瀚的塔克拉马干大沙漠，一走进来，你仿佛迷失了方向。
你感到口内十分焦渴，还是快些离开吧。
LONG
        );

        set("exits", ([
        "northeast" : __DIR__"nanjiang",
        "southeast" : __FILE__,
        "southwest" : __DIR__"nanjiang2",
        "northwest" : __FILE__,
        "north" : __FILE__,
        "west" : __FILE__,
        "south" : __FILE__,
        "east" : __FILE__,
        ]));
	set("cost", 5);
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_water;

        current_water = me->query("water");
        if (current_water==0) {
          write("你已经感到不行了，冥冥中你觉得有人把你抬到天山脚下。\n");
          me->move(__DIR__"shanjiao");
          me->unconcious();
	  return 0;
        }

        if (current_water>0 && current_water<=20) {
            write("你过于缺水，眼冒金星。\n");
            me->set("water",0);
        }

        if (current_water>20) {
            me->set("water",current_water-20);
        }
        if (dir=="east" || dir=="south" || dir=="west" || dir=="north") 
           write("你向那边走去，结果发现那是沙漠中的海市蜃楼。\n");
        return ::valid_leave(me, dir);
}

