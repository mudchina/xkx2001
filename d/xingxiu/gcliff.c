//Cracked by Roath
// wsky 5/7/00

inherit ROOM;
inherit F_CLEAN_UP;

void create()
{
        set("short", "悬崖");
        set("long", @LONG
你向右一拐来到一处平地，前面稀稀的长着些青草，随风而动，显的无限凄凉，
右边已经到了路的尽头，是一处悬崖(cliff)，似乎并不非常的险。
LONG
        );
        
        set("exits", ([
             "westdown" : __DIR__"gudao2",
        ]));

	set("item_desc",([
                "cliff"         :       "一处并不十分陡峭的悬崖，似乎可以爬下去。\n",
        ]));


        set("no_clean_up", 0);

        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        
}

void init() {add_action("do_climb","climb");add_action("do_climb","pa");}

int do_climb(string arg) {
	if (arg && arg!="down") {
		say("你想往哪儿爬？？？\n");
		return 1;
	} else {
		say("你手脚并用往上爬了一段，终于出谷了。\n");
		this_player()->move(__DIR__"hide_place");
		return 1;
	}
}
