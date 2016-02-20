//Cracked by Roath
// 曲院风荷
// Dong  11/03/1996.
// xbc 06/21/97

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   	set("short", HIG"曲院风荷"NOR);
   	set("long", @LONG
走进亭院，只见临湖一座小榭。柱上有一对联(duilian)。 依榭
观湖，只见荷花满湖，茭荷深处，香远益清。杨万里曾有题咏“毕竟
西湖六月中，风光不与四时同。接天莲叶无穷碧，映日荷花别样红”。
LONG );

   	set("item_desc",  ([
      		"duilian" : 
	    HIG	"	身		眼\n"
	    	"	在		明\n"
            	"	荷		小\n"
            	"	香		阁\n"
	    	"	水		浮\n"
	    	"	影		烟\n"
	    	"	中		翠\n"NOR
   	   ]));

   	set("exits", ([ /* sizeof() == 1 */ 
  		  "out" : __DIR__"quyuan1",
                ]));

	set("cost", 1);
        set("outdoors", "hangzhou");
        set("he_count", 2);
   	setup();
//   	replace_program(ROOM);
}
void init()
{
        add_action("do_pick", "pick");
        add_action("do_pick", "zhai");
}

int do_pick(string arg)
{
        object me = this_player();
        object ob = new("/d/gaibang/obj/heye");

        if ( !arg || arg == "") return 0;

        if ( arg == "he ye" || arg == "荷叶" ){
                if (query("he_count") < 1) {
                        tell_object(me, "还摘？再摘人家还看不看「曲院风荷」了？\n", me);
                        return 1;
                }
                message_vision("$N从湖中摘下一片荷叶来。\n", me);
                ob->move(me);
                add("he_count", -1);
                return 1;
        }
        return 0;
}

