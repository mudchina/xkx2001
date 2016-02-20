//Cracked by Roath
// Room: /d/shaolin/hanshui1.c
// Date: YZC 96/01/19
// modified by aln 4 / 98

inherit FERRY;

void create()
{
        object room;

        set("short", "汉水南岸");
        set("long", @LONG
面前是一条波涛翻滚的大江(river)。浊流滚滚，万舟竞发。
两岸渡船来来往往，江边一长溜摆满了鱼摊，渔家就将船泊在岸
边，几个破萝支一块木板，板上摆满了活蹦乱跳的汉江鲤鱼。过
去不远，是有名的老河口，不少过江客都在这里等待渡船摆渡。
LONG
    );

        set("exits", ([
                "south" : __DIR__"yidao2",
        ]));

        set("item_desc", ([
                "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
        ]));

        set("objects",([
	        CLASS_D("gaibang") + "/jiang-shangyou" : 1,
        ]));

        set("resource/water", 1);
        set("outdoors", "shaolin");
	set("cost", 2);

        set("name", "江");
        set("boat", __DIR__"duchuan");
        set("opposite", __DIR__"hanshui2");
    
        setup();
}
