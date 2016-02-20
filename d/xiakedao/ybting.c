//Cracked by Roath
// xiakedao/ybting.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "迎宾厅");
        set("long", @LONG
石子路旁是一座小亭，亭边立着一块石碑，碑上题着“迎宾”两
个大字。字迹入石三分，好像是人用手指写出的。
LONG );

      set("exits", ([
		     "south" : __DIR__"xiaolu",
		     "north" : __DIR__"xiaolu2",
      ]));

        set("objects", ([ 
            __DIR__ + "npc/huashan" : 1,
      ]));
        set("outdoors", "xiakedao" );
        set("cost", 0);

//        "/clone/board/xkd_b"->foo();

        setup();
}
void init()
{     object greeter;
        object greeter2;
        string longdesc = "石子路旁是一座小亭，亭边立着一块石碑，碑上题着“迎宾”两
个大字。字迹入石三分，好像是人用手指写出的。";
        object me = this_player();
        if (interactive(me)) 
        {       if ( (!(me->query("xkd/hosted") ) )&& (!(me->query_temp("xkd/guested"))) )
                {       longdesc += "一人在亭内低头想\n着些什麽，看你进来忙迎了过来。\n";
                        this_object()->set("long", longdesc);
                        greeter = present("long dizi", environment(me));
                        if (! (greeter) )
                        {       greeter = new(__DIR__"npc/longx.c"); 
                                greeter->set_temp("xkd/guest", getuid(me));
                                me->set_temp("xkd/guested", 1);
                        }
                        else
                        {       if ((string)greeter->query_temp("xkd/guest") != getuid(me))
                                {       greeter2 = new(__DIR__"npc/longx.c"); 
                                        greeter2->set_temp("xkd/guest", getuid(me));
                                        me->set_temp("xkd/guested", 1);
                                }
                        }
                        greeter->move(environment(me));
                }
        }

}

