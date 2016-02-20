//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "仙人洞");
	set("long", @LONG
路东的一座陡峭绝险的石峰(feng)腰间，有一石洞，距地数十尺。
峰脚是浪涛滚滚的塔勒奇河。洞口青松环列，洞顶刻有“财寿洞”三
个红漆大字。据传数百年前，一位来自中原的道人，在这险峰间凿出
此洞。
LONG
	);
	set("exits", ([
                "south" : __DIR__"ertai",
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;
        if( arg=="feng")
        {
	if (me->query_skill("dodge") < 30){
                    write("你试图攀上石峰，无奈身法不够敏捷，只好做罢。\n");
                return 1;
                }
                else {
                    write("你一纵身顺着石峰爬了上来。\n");
                    message("vision",
                             me->name() + "一纵身顺着石峰攀了上去。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"xrdong1");
                    message("vision",
                             me->name() + "从下面爬了上来。\n",
                             environment(me), ({me}) );
                return 1;
         }
     }
}

