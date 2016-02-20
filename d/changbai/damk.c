//Cracked by Roath
// Room: damk.c

inherit ROOM;

#include <localtime.h>
#include <command.h>

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();

void create()
{
	set("short", "´óÃÅ¿²×Ó");
	set("long", @LONG
ÕâÀïÊÇÑØ½­Ïò¶«µÄ¹ÅµÀ£¬¶àÎª½øÉ½²É²ÎµÄ²Î¿ÍËù×ß£¬Òò´ËÒ²³Æ¡°²ÎÂ·¡±
¡£Ç°ÃæÒ»×ùÐ¡É½½Ø¶ÏÈ¥Â·£¬ÒòÆäÐÐËÆÃÅ¿²£¬ÇÒÎª¶«È¥²É²ÎµÄµÚÒ»µÀÆÁÕÏ£¬¹Ê
±»³ÆÎª´óÃÅ¿²×Ó¡£Î÷ÃæÊÇ¿íÀ«µÄËÉ»¨½­¡£ËÉ»¨½­ÔÚ¶¬´ºÊ±½á±ù¿ÉÍ¨ÐÐ£¬ÏÄÇï  
»¯¶³ÄãÖ»ºÃÕÒ´¬¼Ò°ïÃ¦ÁË¡£
LONG	);

	set("exits", ([ 
              "west" : __DIR__"chuanc",
              "southeast" : __DIR__"ermk",
        ]));

        set("outdoors", "changbai");
        set("cost", 3);

	setup();
}

int valid_leave(object me, string dir)
{
        mixed *local;
        object *ob;
        int i;

        if( dir == "west" ) {
                local = localtime(time()*60);
                if( local[LT_MON] > 3 && local[LT_MON] < 10 )
                        return notify_fail("ËÉ»¨½­»¯¶³ÁË£¬Äãº°(yell)Ìõ´¬¹ý½­°É¡£\n");
                else {
                        ob = all_inventory(environment(me));
                        for(i=0; i<sizeof(ob); i++){
                                if( ob[i]->query("rider") == me )
                                        me->move(__DIR__"bingmian");
                        me->set_temp("new_valid_dest", __DIR__"bingmian");
                        tell_object(me, "Äã¼û½­Ãæ½á¶³£¬±ã×³Æðµ¨×Ó²È±ù¶ø¹ý¡£\n");
                        }                 
                        return 1;
                }
        }

        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_yell", "yell");
}

int do_yell(string arg)
{
        mixed *local;
        string dir;

	local = localtime(time()*60);
        if( !(local[LT_MON] > 3 && local[LT_MON] < 10) ) 
                return 0;       

        if( !arg || arg=="" ) return 0;

        if( (int)this_player()->query("age") < 16 )
                message_vision("$NÊ¹³ö³ÔÄÌµÄÁ¦Æøº°ÁËÒ»Éù£º¡°" + arg + "¡±\n", this_player());
        else if( (int)this_player()->query("neili") > 500 )
                message_vision("$NÎüÁË¿ÚÆø£¬Ò»Éù¡°" + arg + "¡±£¬ÉùÒôÖÐÕýÆ½ºÍµØ¶Ô¶´«"
                "ÁË³öÈ¥¡£\n", this_player());
        else    message_vision("$N¹Ä×ãÖÐÆø£¬³¤Ð¥Ò»Éù£º¡°" + arg + "£¡¡±\n", this_player());

        if( arg == "´¬¼Ò" ) {
                check_trigger();
                return 1;
        } else  message_vision("½­ÃæÉÏÔ¶Ô¶´«À´Ò»Õó»ØÉù£º¡°" + arg +
                "¡«¡«¡«¡±\n", this_player());
        return 1;
}

void check_trigger()
{
        object room;

        if( !query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
                room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
                if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "Ò»Ò¶±âÖÛ»º»ºµØÊ»ÁË¹ýÀ´£¬ô¹¹«½«Ò»¿éÌ¤½Å"
                    "°å´îÉÏµÌ°¶£¬ÒÔ±ã³Ë¿Í\nÉÏÏÂ¡£\n", this_object());
                message("vision", "ô¹¹«½«Ò»¿éÌ¤½Å°å´îÉÏµÌ°¶£¬ÐÎ³ÉÒ»¸öÏòÉÏ"
                    "µÄ½×ÌÝ¡£\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
                } else
                message("vision", "Ö»ÌýµÃ½­ÃæÉÏÒþÒþ´«À´£º¡°±ð¼±Âï£¬"
                "Õâ¶ùÕýÃ¦×ÅÄÅ¡­¡­¡±\n", this_object());
        }  else
                message("vision", "ERROR: boat not found\n", this_object() );
        } else 
                message("vision", "°¶±ßÒ»Ö»¶É´¬ÉÏµÄÀÏô¹¹«ËµµÀ£ºÕýµÈ×ÅÄãÄØ£¬ÉÏÀ´°É¡£\n", this_object() );
}


void on_board()
{
        object room;

        if( !query("exits/enter") ) return;

        message("vision", "ô¹¹«°ÑÌ¤½Å°åÊÕÁËÆðÀ´£¬Öñ¸ÝÒ»µã£¬±âÖÛÏò½­ÐÄÊ»È¥¡£\n", this_object());

        if( room = find_object(__DIR__"duchuan") ) {
                room->delete("exits/out");
                message("vision", "ô¹¹«°ÑÌ¤½Å°åÊÕÆðÀ´£¬ËµÁËÒ»Éù¡°×øÎÈà¶¡±£¬"
                "Öñ¸ÝÒ»µã£¬±âÖÛÏò\n½­ÐÄÊ»È¥¡£\n", room);
        }

        delete("exits/enter");

        remove_call_out("arrive");
        call_out("arrive", 20);
}

void arrive()
{
        object room;

        if( room = find_object(__DIR__"duchuan") ) {
                room->set("exits/out", __DIR__"chuanc");
                message("vision", "ô¹¹«Ëµ¡°µ½À²£¬ÉÏ°¶°É¡±£¬Ëæ¼´°ÑÒ»¿éÌ¤½Å°å"
                "´îÉÏµÌ°¶¡£\n",room );
        }

        remove_call_out("close_passage");
        call_out("close_passage", 20);
}

void close_passage()
{
        object room;

        if( room = find_object(__DIR__"duchuan") ) {
                room->delete("exits/out");
                message("vision","ô¹¹«°ÑÌ¤½Å°åÊÕÆðÀ´£¬°Ñ±âÖÛÊ»Ïò½­ÐÄ¡£\n", room);
                room->delete("yell_trigger"); 
        }
}

void reset()
{
        object room;

        ::reset();

        if( room = find_object(__DIR__"duchuan") )
                room->delete("yell_trigger"); 
}

