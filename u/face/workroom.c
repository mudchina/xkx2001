
inherit ROOM;

void create()
{
        set("short","玲珑闺房");
    	set("long", @LONG

    这里是玲珑姑娘的家，里面东西不多，但非常的干净整洁，在屋
子的左侧是玲珑姑娘的梳妆台，各种各样的化装用品放了一桌子，桌
子的最上面是一面大的镜子。屋子的最里面有一张大的红木床(bed)，
整间屋子里充满了女性特有的幽香。
LONG);
      set("item_desc", ([
        "bed"  :  "\n你向床上瞧去，你突然有一种想入非非的感觉 ，床上放着一双袜子(socks)。\n",
		"socks" : "\n这是一双女孩子喜欢穿的短袜，看样子是玲珑姑娘刚刚脱下来的.\n",
         ]) );

	set("exits", ([
                "kd" : "/d/city/kedian",
	]));
	set("valid_startroom", 1);
    set("no_fight", "1");

      setup();
}