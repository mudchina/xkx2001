//Cracked by Roath
// xiakedao/liangong.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

int do_tuna(string arg);
int do_dazuo(string arg);

void create()
{
        set("short", "练功室");
        set("long", @LONG
山洞四周墙上点满了火把。这里极为安静，仅能听到或悠长，或
粗重的呼吸声。洞里零零落落地摆着几个蒲团，并无其他陈设。几个
人正坐在上面打坐(dazuo)，吐纳(tuna)。
LONG );

        set("exits", ([
      	        "north" : __DIR__"yongdao5",
        ]));
	set("objects", ([ 
		__DIR__ +"npc/shaonian" : 1, 
        ]));

	set("cost", 0);
	setup();
}
void init()
{
        ::init();

	add_action("do_dazuo", "dazuo");
	add_action("do_tuna", "tuna");
}

int do_dazuo(string arg)
{	if (!arg)
	{	write("打坐(dazuo)是用气提高你的内力。每次打坐最少要花十点气。\n");
		write("如果你打坐把你的内力提高到你永久内力的一倍，你永久内\n");
		write("力就会加一点。你和人比拼功夫时可以增加内力(jiali)伤\n");
		write("人，但你只能加到你内功有效等级的一半。\n");
	}
	return 0;
}
int do_tuna(string arg)
{	if (!arg)
	{	write("吐纳(tuna)化精为精力。每次吐纳最少要花十点精。\n");
		write("如果你吐纳把你的精力提高到你永久精力的一倍，你永久精\n");
		write("力就会加一点。\n");
	}
	return 0;
}
