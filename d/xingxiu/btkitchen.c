//Cracked by Roath
// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这是白驼山庄的厨房，里面有一个大灶和一口水缸，白驼山庄的
弟子们可以在这儿喝水(drink)。几个婢女在忙着做饭。
LONG
        );
        set("exits", ([ 
	    "north" : __DIR__"btyard",
        ]));
        set("resource/water", 1);


        set("objects", ([ 
            CLASS_D("baituo")+"/binu" : 2,
	    __DIR__"obj/shegeng" : 2,
	    __DIR__"npc/snake" : 1,
         ]) );
//        replace_program(ROOM);
	set("cost", 0);
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在大水缸上咕嘟咕嘟灌了几口水。\n"
            , environment(me), ({me}) );
            write("你趴在大水缸上咕嘟咕嘟灌了几口水。\n");
        }
        else write("小婢女奇怪地瞪着你，慢慢地咧开嘴，捧腹大笑起来：肚子都大了还喝！\n");

        return 1;
}


