//Cracked by Roath
// /d/hangzhou/biaoju.c  龙门镖局
// by aln  2 / 98

inherit ROOM;

void create()
{
        set("short", "龙门镖局");
        set("long", @LONG
这里是浙江一带最大最有名的镖局“龙门镖局”。总镖头乃江湖上人称
“多臂熊”的都大锦，龙门镖局自他开设二十年来，从来没出过半点岔子。
门口石坛上插着一根两丈多高的旗杆，杆上飘着一面绣着一尾金色鲤鱼的镖
旗。
LONG
        );
/*
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));
*/

        set("exits", ([
                "west" : __DIR__"road20",
                "enter" : __DIR__"xiaoyuan",
        ]));

        set("objects", ([
                __DIR__"npc/du" : 1,
        ]));

        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "enter" )
                return ::valid_leave(me, dir);

        if( !(ob = present("du dajin", environment(me))) )
                return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        if( me == ob )
                return ::valid_leave(me, dir);

        if( !me->query_condition("lmjob") ) {
                message_vision("$N拦在$n面前，喝道：" + RANK_D->query_rude(me) + "里面是镖局重地，不得闯入！\n", ob, me);
                return notify_fail("");
        }

        return ::valid_leave(me, dir);
}

/*
string look_gaoshi()
{
        object place;
        string str, *skills, *teachs;
        int i;

        if( !(place = find_object("/d/hangzhou/xiaoyuan")) )
                place = load_object("/d/hangzhou/xiaoyuan");
  
        if( time() > (int)place->query("time") + 3600 ) {
                place->set("time", time());

                skills = ({});
                for(i = 0; i < sizeof(lmskills); i++) {
                        teachs = lmskills[i];
                        skills += ({teachs[random(sizeof(teachs))]});
                }
                place->set("skills", skills);
        }

        skills = place->query("skills");
        str = "\n俜请武师教授以下武功：\n\n";
        for(i = 0; i < sizeof(skills); i++)
                str += to_chinese(skills[i]) + "。\n";
        str += "\n\n龙门镖局\n";
        return str;
}
*/
