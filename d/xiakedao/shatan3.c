//Cracked by Roath
// Copy from  /d/shaolin/hanshui1.c
// Date: Long /8/1/97

inherit ROOM;

//void do_fisttime(object me);

void create()
{
    set("short", "沙滩");
    set("long", @LONG
蓝蓝的大海一望无边。岸边不远处停着几只小船，细细的白沙，
踩在脚下软软的好不舒服。
LONG
    );

       set("exits", ([
       ]));
       set("no_fight", "1");
       set("outdoors", "xiakedao");
       setup();
}

void init()
{      object me = this_player();
       object money, car, ling1, ling2;
      if (interactive(me)) 
       {       if (!(car = present("da che", environment(me))))
               {       car = new(__DIR__"obj/car");
                       car->move(environment(me));
               }
       }
}
