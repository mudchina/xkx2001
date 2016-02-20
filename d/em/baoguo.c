//Cracked by Roath
// baoguo.c 保国寺
// Shan: 96/09/22

inherit ROOM;

int do_study(string);

void create()
{
        set("short", "报国寺");
        set("long", @LONG
报国寺是峨眉山最大寺院之一。寺庙倚山建造，弥勒殿、大雄殿、七佛殿
逐级升高，规模宏大。殿内佛像金光闪闪，气宇轩昂。寺内芳草迷径，花开不
绝。这里有一座华严塔(ta)。这里向西，约二里可达伏虎寺。
LONG
        );
        set("exits", ([
                "enter" : __DIR__"baoguo1",
		"southwest" : __DIR__"fuhuroad",
                "east" : __DIR__"baoguomen",
		"west" : __DIR__"baoguoxi",
        ]));

        set("objects", ([
                __DIR__"npc/xiang-ke.c": 1,
        ]));

	set("outdoors", "emei");
        set("item_desc",([
            "ta"        :
"    这是一座十五层的紫铜铸华严塔。塔高七米，塔身周匝共有小佛四千七百\n"
"尊之多，并铸有《华严经》全文两万多字，其冶炼工艺与雕工技巧，已造至极\n"
"至美之境。\n"
        ]));

	set("cost", 1);
        setup();
}

void init()
{
        add_action("do_study", "study");
        add_action("do_study", "du");
}


int do_study(string arg)
{
        object me;
	int ml, pl;

        me = this_player();

        if ( !arg || ( arg != "ta" ) )
                return notify_fail("什么？\n");

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你不识字，先学点文化(literate)吧。\n");

	ml = me->query_skill("mahayana", 1);
	pl = me->query_skill("persuading", 1);

	if ( (ml >= 60 && pl <= ml) || ml >= 2*pl ) {
		write("你须多多渡世济人才能继续提高大乘涅磐法修为。\n");
		return 1;
	}

	if (me->query("jing")<40) {
		write("你现在头晕眼花，看不清塔上的字。\n");
                return 1;
        }

        me->receive_damage("jing", 30, "精力衰竭而死");

        message_vision("$N正专心研读华严塔上的《华严经》。\n", me);

        if ( ml < 100 )
        {
                me->improve_skill("mahayana", me->query_int());
                write("你对着华严塔上的华严经琢磨了一阵，似乎对大乘涅磐法略有心得。\n");
                return 1;
        }

        write("你对着华严塔瞧了一会儿，发现上面所说的佛理太过浅显，对你来说已无甚意义了。\n");

        return 1;
}

