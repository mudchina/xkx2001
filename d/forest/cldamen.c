//Cracked by Roath
// /d/huanghe/changle/cldamen.c
// aln  2 / 98

inherit ROOM;

void create()
{
        set("short", "大门");
        set("long", @LONG
这里便是威镇江南的长乐帮总舵所在。那长乐帮在江湖上声势非同小      
可，近年来更是日渐兴旺。两扇红漆大门上钉着狰狞的虎头，几个满脸横    
肉的帮众站在两侧。门上有一个大匾(bian)，两盏气死风灯来回摇摆。旁  
边有一座碑(bei) ，上面刻着一些文字。
LONG );

        set("exits", ([
		"enter" : __DIR__"cldating",
		"south"  : __DIR__"clforest4",
        ]));

	set("item_desc",([
	    "bian" : 
"    ※※※※※※※※※※※※※※※※※※※\n"
"    ※※※※　　　　　　　　　　　※※※※\n"
"    ※※※※　　长　　乐　　帮　　※※※※\n"
"    ※※※※　　　　　　　　　　　※※※※\n"
"    ※※※※※※※※※※※※※※※※※※※\n",
            "bei" :
"    长乐，据传出自唐李颀诗：“莫是长安行乐处，空令岁月易蹉跎。”\n"
"    长乐帮原是江湖上不入流的小帮，从第七代帮主时，开始声名鹊起。\n"
"    帮中自帮主、总管以下，分为龙灵堂，狮敏堂，熊威堂，虎猛堂和豹\n"
"    捷堂，其分舵更是遍布各地，好手如云。长乐帮行事亦正亦邪，阴魂\n"
"    不散，黑白两道人物无不避让三分。正如市井小儿歌谣云：长乐无常，\n"
"    无常长乐。\n",
	]));

	set("cost", 1);
        set("objects",([
                __DIR__"npc/cl_qiu" : 1,
            ]));

        set("outdoors", "city");

        setup();
        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "enter" )
                return ::valid_leave(me, dir);

        if( !(ob = present("qiu", environment(me))) )
                return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        if( me->query_temp("bangs/fam") == "长乐帮"
        ||  me->query("fam") == "长乐帮" )
                return ::valid_leave(me, dir);

        if( me->query_temp("changle/enter") ) {
                me->delete_temp("changle/enter");
                return ::valid_leave(me, dir);
        }

        message_vision("$N拦在$n面前，说道：" + RANK_D->query_rude(me) + "怎么连一点江湖规矩都不懂？起码也得孝敬一下老子。\n", ob, me);
        return notify_fail("");
}
