//Cracked by Roath
// wsky, 5/7/00
inherit ROOM;

void create()
{
        set("short", "崖底");
        set("long", @LONG
这里是悬崖底，除了乱石之外似乎什么也没有。
LONG
        );

        set("exits", ([
             "up" : __DIR__"gcliff",
        ]));

        set("objects", ([
                __DIR__"npc/sangtu"  : 1,
        ]) );

	set("item_desc",([
                "cliff"         :       "一处并不十分陡峭的悬崖，似乎可以爬上去。\n",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        

}



void init()
{
        add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}	

int do_climb(string arg) {
	if (arg && arg!="up") {
		say("你想往哪儿爬？？？\n");
		return 1;
	} else {
		say("你手脚并用往上爬了一段，终于出谷了。\n");
		this_player()->move(__DIR__"gcliff");
		return 1;
	}
}
