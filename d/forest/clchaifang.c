//Cracked by Roath
// changle/clchaifang.c

inherit ROOM;

void create()
{
        set("short", "柴房");
        set("long", @LONG
一间简单的柴房，普通的帮众可以在这里干点杂活。劈好的木柴
凌乱地堆在墙角，旁边是砍柴刀（chaidao）和笤帚（tiaozhou）。门
后还有个水缸，却已经空了。时而也有帮众过来打个盹。
LONG );
        set("exits", ([
		"east" : __DIR__"clzoulang1",
        ]));

	set("item_desc",([
	    "chaidao" : "一把锋利的砍柴刀。\n",
	    "tiaozhou" : "一把用来扫地的笤帚。\n",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_steal", 1);

        set("cost", 0);

        setup();

        // replace_program(ROOM);
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        object obj;

        if( arg
        && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
                write("你不能搬动玩家的身体。\n");
                return 1;
        }
        else
                return 0;
} 
