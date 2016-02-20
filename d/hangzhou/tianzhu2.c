//Cracked by Roath
// 天竺山路
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "山路");
   set("long", @LONG
走在这条不是很宽的山路上，只见两旁峰峦秀丽，景色怡人。一
条小溪在路边潺潺流过，溪畔有一农家。山村小景，使人有退隐江湖
之意。南上便到了中天竺。北下就是下天竺。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "southup" : __DIR__"tianzhu3", 
                  "northdown" : __DIR__"tianzhu1", 
                ])
       );

	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}