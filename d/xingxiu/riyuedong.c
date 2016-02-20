//Cracked by Roath
// Room: /d/xingxiu/riyuedong.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "日月洞");
        set("long", @LONG
这里是星宿派总舵所在地日月洞。洞内灯火通明，正中一把虎皮椅上端坐着
星宿派掌门人丁春秋。洞壁上装饰着虎皮、鹿头、雕羽，及一些字画(zihua)。
洞两侧竖立兵器架，上面排列的大多是各种棍棒。
LONG
        );
        set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zihua" : "都是些吹捧星宿老仙的诗词和他的画像。\n

※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　※※※※
※※※※　古　威　德　星　※※※※
※※※※　今　震　配　宿　※※※※
※※※※　无　寰　天　老　※※※※
※※※※　比　宇　地　仙　※※※※
※※※※　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※
"
        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/ding" : 1,
                __DIR__"npc/obj/tiezhang" : 1,
        ]) );

        set("no_clean_up", 0);

	set("cost", 1);
        setup();

}
void init()
{
	add_action("do_kill","kill");
}
int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" || arg == "ding") return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "星宿派" && me->query("family/fa
mily_name") != "星宿派" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活。\n", ob, me);

           if ( ob1=present("ding chunqiu", environment(me)) ) {
                message_vision("$N一声冷笑：大胆狂徒！竟敢当着我的面行凶杀人，当我星宿派好欺负么？\n", ob1);
                ob1->kill_ob(me);
           }

           if ( !ob1 ) return 0;

           return 1;
} 
}
