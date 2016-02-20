//Cracked by Roath
// /d/emei/secret_path4.c
// xbc 02/07/1997

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
        set("short", "秘道");
        set("long", @LONG
这是一条长长的秘道，只有几盏长明灯，光线极暗。越往下走，越觉得亮，
前面似乎有阳光透进来，原来到了一个洞口。
LONG
        );
        set("exits", ([
                "up" : __DIR__"secret_path3",
                "down" : __DIR__"cliffpool",
        ]));

        set("no_clean_up", 0);

	set("cost", 3);
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "你点燃了火折，把秘道照亮了一些。\n"
             );
             return 1;
       }
}

int do_zuan(string arg)
{
      object me;
      me = this_player();

      message_vision(
      "$N像没头苍蝇一样在秘道里瞎钻，结果一头撞在墙上。\n", this_player());
      if (random(2)==1) {
         write("你觉得你晕乎乎的，似乎撞傻了。\n");
         if (me->query_skill("literate", 1) )
             me->set_skill("literate", me->query_skill("literate", 1)-1);
      }
      else {
         me->set("qi",10);
         me->unconcious();
      }
      return 1;
}

